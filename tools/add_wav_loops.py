#!/usr/bin/env python3
"""
Restore loop points to DPPt WAV sample files that lost them during .aif -> .wav migration.

The original .aif files had MARK + INST chunks encoding loop start/end points at the
original sample rate. When converted to .wav (resampled to 22050 Hz), the loop info
was stripped. This script reads loop info from the original .aif files in git history,
scales the sample coordinates to match the WAV's sample rate, and injects proper
'smpl' chunks so that wav2agb generates looped GBA samples.

Usage:
    python3 tools/add_wav_loops.py

Run from the project root. Requires git history to contain the original .aif files
(commit 44ae989223 - the first DPPt music release).
"""

import struct
import subprocess
import glob
import os
import sys

AIF_COMMIT = "44ae989223"
WAV_DIR = "sound/direct_sound_samples"


def read_aiff_info(aif_data):
    """Parse an AIFF file.
    Returns dict with keys: sample_rate, num_frames, loop_mode,
    loop_start (sample index), loop_end (sample index, inclusive).
    Returns None if not a valid AIFF."""
    if aif_data[:4] != b'FORM' or aif_data[8:12] != b'AIFF':
        return None

    marks = {}
    result = {
        'sample_rate': None,
        'num_frames': None,
        'loop_mode': 0,
        'loop_start': None,
        'loop_end': None,
    }

    pos = 12
    while pos < len(aif_data) - 8:
        chunk_id = aif_data[pos:pos+4]
        chunk_size = struct.unpack('>I', aif_data[pos+4:pos+8])[0]
        chunk_data = aif_data[pos+8:pos+8+chunk_size]

        if chunk_id == b'COMM':
            result['num_frames'] = struct.unpack('>I', chunk_data[2:6])[0]
            # 80-bit extended float at bytes 8-17
            exponent = (struct.unpack('>H', chunk_data[8:10])[0] & 0x7FFF) - 16383 - 63
            mantissa = struct.unpack('>Q', chunk_data[10:18])[0]
            result['sample_rate'] = mantissa * (2.0 ** exponent)

        elif chunk_id == b'MARK':
            num = struct.unpack('>H', chunk_data[0:2])[0]
            p = 2
            for _ in range(num):
                mid = struct.unpack('>H', chunk_data[p:p+2])[0]
                mpos = struct.unpack('>I', chunk_data[p+2:p+6])[0]
                p += 6
                nlen = chunk_data[p]
                p += 1 + nlen + (1 if (1 + nlen) % 2 == 1 else 0)
                marks[mid] = mpos

        elif chunk_id == b'INST':
            loop_mode = struct.unpack('>H', chunk_data[8:10])[0]
            ls_marker = struct.unpack('>H', chunk_data[10:12])[0]
            le_marker = struct.unpack('>H', chunk_data[12:14])[0]
            result['loop_mode'] = loop_mode
            result['_ls_marker'] = ls_marker
            result['_le_marker'] = le_marker

        pos += 8 + chunk_size + (chunk_size % 2)

    # Resolve markers
    ls_m = result.pop('_ls_marker', None)
    le_m = result.pop('_le_marker', None)
    if result['loop_mode'] > 0 and ls_m in marks and le_m in marks:
        result['loop_start'] = marks[ls_m]
        result['loop_end'] = marks[le_m]

    return result


def read_wav_info(wav_data):
    """Parse basic WAV info: sample_rate, num_samples, has_smpl_chunk."""
    if wav_data[:4] != b'RIFF' or wav_data[8:12] != b'WAVE':
        return None

    result = {'sample_rate': None, 'num_samples': None, 'has_smpl': False}
    pos = 12
    while pos < len(wav_data) - 8:
        chunk_id = wav_data[pos:pos+4]
        chunk_size = struct.unpack('<I', wav_data[pos+4:pos+8])[0]
        if chunk_id == b'fmt ':
            channels = struct.unpack('<H', wav_data[pos+8+2:pos+8+4])[0]
            result['sample_rate'] = struct.unpack('<I', wav_data[pos+8+4:pos+8+8])[0]
            bits_per_sample = struct.unpack('<H', wav_data[pos+8+14:pos+8+16])[0]
            result['bytes_per_sample'] = (bits_per_sample // 8) * channels
        elif chunk_id == b'data':
            bps = result.get('bytes_per_sample', 2)
            result['num_samples'] = chunk_size // bps
        elif chunk_id == b'smpl':
            result['has_smpl'] = True
        pos += 8 + chunk_size + (chunk_size % 2)

    return result


def make_smpl_chunk(loop_start, loop_end_inclusive, midi_note=60):
    """Build a RIFF 'smpl' chunk with one forward loop.

    wav2agb reads: loopEnd = smpl[36+12] + 1 (exclusive).
    So store loop_end_inclusive directly; wav2agb adds 1.
    """
    body = bytearray(60)
    struct.pack_into('<I', body, 12, midi_note)     # MIDI unity note
    struct.pack_into('<I', body, 16, 0)             # pitch fraction
    struct.pack_into('<I', body, 28, 1)             # num loops = 1
    struct.pack_into('<I', body, 32, 0)             # sampler data size
    struct.pack_into('<I', body, 36, 1)             # cue point ID
    struct.pack_into('<I', body, 40, 0)             # loop type = 0 (forward)
    struct.pack_into('<I', body, 44, loop_start)
    struct.pack_into('<I', body, 48, loop_end_inclusive)
    struct.pack_into('<I', body, 52, 0)             # fraction
    struct.pack_into('<I', body, 56, 0)             # play count (0 = infinite)
    return b'smpl' + struct.pack('<I', len(body)) + bytes(body)


def inject_smpl_chunk(wav_path, loop_start, loop_end_inclusive):
    """Inject a smpl chunk into a WAV file before the 'data' chunk."""
    with open(wav_path, 'rb') as f:
        wav_data = bytearray(f.read())

    smpl_chunk = make_smpl_chunk(loop_start, loop_end_inclusive)

    # Find 'data' chunk to insert before it
    insert_pos = len(wav_data)
    pos = 12
    while pos < len(wav_data) - 8:
        chunk_id = wav_data[pos:pos+4]
        chunk_size = struct.unpack('<I', wav_data[pos+4:pos+8])[0]
        if chunk_id == b'data':
            insert_pos = pos
            break
        pos += 8 + chunk_size + (chunk_size % 2)

    new_data = bytearray()
    new_data += wav_data[:insert_pos]
    new_data += smpl_chunk
    new_data += wav_data[insert_pos:]

    # Update RIFF size
    struct.pack_into('<I', new_data, 4, len(new_data) - 8)

    with open(wav_path, 'wb') as f:
        f.write(new_data)


def main():
    wav_files = sorted(glob.glob(os.path.join(WAV_DIR, 'dp_*.wav')))
    if not wav_files:
        print(f"No dp_*.wav files found in {WAV_DIR}")
        sys.exit(1)

    print(f"Processing {len(wav_files)} DPPt WAV files...")
    fixed = 0
    skipped_has_smpl = 0
    skipped_no_loop = 0
    errors = 0

    for wav_path in wav_files:
        base = os.path.basename(wav_path).replace('.wav', '')
        aif_name = f"{base}.aif"

        # Read WAV info
        with open(wav_path, 'rb') as f:
            wav_bytes = f.read()
        wav_info = read_wav_info(wav_bytes)
        if not wav_info:
            print(f"  ERROR: {wav_path} is not a valid WAV file")
            errors += 1
            continue

        if wav_info['has_smpl']:
            skipped_has_smpl += 1
            continue

        # Fetch original .aif from git
        result = subprocess.run(
            ['git', 'show', f'{AIF_COMMIT}:{WAV_DIR}/{aif_name}'],
            capture_output=True
        )
        if result.returncode != 0:
            print(f"  WARN: {aif_name} not found in git commit {AIF_COMMIT}")
            errors += 1
            continue

        aif_info = read_aiff_info(result.stdout)
        if not aif_info or aif_info['loop_mode'] == 0 or aif_info['loop_start'] is None:
            skipped_no_loop += 1
            continue

        # Scale loop coordinates from AIF sample rate to WAV sample rate
        aif_sr = aif_info['sample_rate']
        wav_sr = wav_info['sample_rate']
        wav_samples = wav_info['num_samples']

        scale = wav_sr / aif_sr
        loop_start_wav = round(aif_info['loop_start'] * scale)
        loop_end_wav = round(aif_info['loop_end'] * scale)

        # Clamp to valid range
        loop_start_wav = max(0, min(loop_start_wav, wav_samples - 1))
        loop_end_wav = max(loop_start_wav + 1, min(loop_end_wav, wav_samples))

        # wav2agb reads smpl[36+12] + 1 as exclusive end, so store (loop_end - 1)
        loop_end_stored = loop_end_wav - 1

        inject_smpl_chunk(wav_path, loop_start_wav, loop_end_stored)
        print(f"  FIXED: {base}.wav  "
              f"loop={loop_start_wav}..{loop_end_wav} "
              f"(aif: {aif_info['loop_start']}..{aif_info['loop_end']} "
              f"@ {aif_sr:.0f}Hz -> wav @ {wav_sr}Hz)")
        fixed += 1

    print()
    print(f"Done: {fixed} fixed, {skipped_has_smpl} already had smpl, "
          f"{skipped_no_loop} no loop needed, {errors} errors")


if __name__ == '__main__':
    main()
