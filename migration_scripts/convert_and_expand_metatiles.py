import os
import io
import argparse
import struct
import json
import re

# Some context for how and why this script works:
#
## Low-level programs, especially at the embedded and ROM design levels, try to be as efficient as possible.
## A common method is to minimize wasted space down to the Bit (Bits obviously being the famous 1s and 0s);
## a challenge presented by the necessary standard of grouping data into a minimum unit of Bytes (8 bits).
## The GameBoy Advance, in particular, can work with 32-Bit (4-Byte) variables at largest,
## so each variable can technically represent up to 256 unique values (1 Byte, 1 Char, etc.),
## 65,536 values (2 Bytes, 1 Half-Word, etc.), or 4,294,967,296 values (4 Bytes, 1 Word, etc.).
## **FUN FACT** 4 Bits (half a Byte) is called a "Nibble"!
#
## But let's say you know a specific variable only needs 10 values (0-9, or 0b1001 in binary), and therefore only 4 Bits.
## The other 4 Bits of the 8-Bit Byte will go completely unused as long as 17+ unique values aren't needed.
## Then, let's say you have *another* variable that you know needs at most 16 unique possible values,
## or instead a variable that you know needs 12 Bits for up to 4096 possible values (2^12).
## Either of those variables would *also* be wasting an additional 4 Bits,
## which is already an entire 1-Byte variable's worth of data wasted across two variables.
#
## To avoid this waste, programmers made a way to use a single 8-, 16-, or 32-Bit variable to store multiple smaller ones.
## The tools used to achieve this are generally referred to as "Bitfields" and "Bit Manipulation",
## which also offers a peek into how computers and electronic calculators work at the lowest level.
#
## This script is a combination of the procedures and included scripts from these two links:
## https://github.com/pret/pokeemerald/wiki/Triple-layer-metatiles
## https://github.com/pret/pokeemerald/wiki/Expanding-The-Metatile-Count
## It uses Bit Manipulation to translate the Data Formats (how Bitfields are used) of pret's pokeemerald decomp
## into a Format that is even more data-efficient, [NOT YET additionally updating relevant C code in the project as best possible.]
## However, **PLEASE NOTE** that it does not make any changes to your Porymap, AdvanceMap, or other tools.
## To ensure your mapping tools continue to work for you, please follow the instructions in those links.
#
## This Format Conversion includes:
## 1. Converting existing Tilesets from the Double Layer Metatile Format to the Triple Layer Metatile Format.
##   - This involves converting each 8-Half-Word Chunk of a Tileset's "metatiles.bin" into a 12-Half-Word Chunk.
##     - Each Chunk of "metatiles.bin" represents the set of 8 (or 12) Tiles that make up a respective Metatile.
##       - Each Half-Word contains both a Tile ID and a Palette ID, which together define the color of each of the 64 pixels of a given Tile.
##       - Each Metatile contains 4 Tiles per Layer, so each added Third Layer will contain 4 transparent Tiles by default.
##         - This is because, functionally, the Third Layer of each Metatile already exists as a transparent Layer.
##         - Which tiles belong to which Metatile Layer is defined by the "Layer Type" value in each 1-Half-Word Chunk of "metatile_attributes.bin".
## 2. Increasing the maximum number of possible Metatiles per Tileset, from the default 1024, to 2048 or 4096.
##   - This involves using a free Collision Bit and/or sacrificial Elevation Bit as Metatile ID Bits instead.
##     - Each Half-Word Chunk of a Layout's "map.bin" or "border.bin" represents a gridspace in a map.
##       - 10 (by default, maximum 12) Metatile ID Bits define the appearance of a gridspace.
##       - 4 (by default, minimum 3) Elevation Bits define the Elevation applied to any Object in a gridspace (such as the Player).
##       - 2 (by default, minimum 1) Collision Bits define if Objects can move into the gridspace (by normal means).


# Some context-specific Bit Manipulation definitions for understanding this code:
#
## Bit "Mask": a constant binary value where 1s represent the relevant Bits of a variable, and 0s for all others.
##          This value gets "Bitwise AND"ed (X & Y) with a variable to set all irrelevant Bits to 0.
#
## Bit "Shift": a constant integer value of the number of irrelevant lower Bits of a variable.
##           This value is the amount a variable is "Bit-Shifted" (X >> Y) for the resulting value to be the desired value.
#
## "Upper" and "Lower" Bits: like with decimal numbers, the rightmost digits of a binary number are "least significant",
##                            and the leftmost are "most significant". "Upper" and "Lower" refer to significance ranking.


## As our first example, every 16 Bits (aka every 2-Byte "Half-Word") of each Tileset's "metatile_attributes.bin"
## stores the "Layer Type" value of a Metatile in its upper 4 Bits, and the "Layer Attribute" in its lower 12 Bits.
LAYER_TYPE_MASK      = 0xF000   # 0b11110000`00000000 - the 4 upper Bits of a 16-Bit value
LAYER_TYPE_SHIFT     = 12       # the number of lower Bits irrelevant to the Layer Type value
META_ATTRIBUTE_MASK  = 0x0FFF   # 0b00001111`11111111 - the 12 lower Bits

LAYER_TYPE_MASK_FRLG      = 0x60000000 # Bits 29-30
LAYER_TYPE_SHIFT_FRLG     = 29
META_ATTRIBUTE_MASK_FRLG  = 0x000001ff # Bits 0-8

## Let's say we read a Metatile Attribute value of 0b*1010*1010`10101010,
## where (using *s for visual clarity) *1010* are the 4 Layer Type Bits.
## We can manually identify these bits and maybe even hand-calculate their decimal value of 10.
## However, for the computer to do this, it needs to apply the Bit Mask and Bit Shift.
#
## Bitwise AND-ing LAYER_TYPE_MASK with the value will output 0b*1010*0000`00000000 (decimal 40,960),
## and Right-Shifting *that* value by LAYER_TYPE_SHIFT will output 0b1010 (decimal 10).
## In this specific (python) example, because there are no values "above" the upper 4 Bits (aka no digits that are more significant),
## applying the Mask is actually unnecessary (but still a good habit) as the Right-Shift removes the 12 lower Bits.


def convert_tilesets_to_triple(tileset_dirs, keep_layer_types = False):
    '''
    Adds a Third Layer of Tiles to each Metatile in the "metatiles.bin" file of each Tileset in the project,
    ordering the Layers of each Metatile as defined by its Layer Type value,
    found in the "metatiles.bin"'s respective "metatile_attributes.bin".
    '''

    for tileset_dir in tileset_dirs:
        tileset_name = os.path.basename(tileset_dir)
        metatiles_path = os.path.join(tileset_dir, 'metatiles.bin')
        metatile_attributes_path = os.path.join(tileset_dir, 'metatile_attributes.bin')
        size_ratio = os.path.getsize(metatiles_path) / os.path.getsize(metatile_attributes_path)
        if not os.path.exists(metatiles_path):
            print(f"[SKIP] {tileset_name} skipped because metatiles.bin was not found.")
            continue
        if not os.path.exists(metatile_attributes_path):
            print(f"[SKIP] {tileset_name} skipped because metatile_attributes.bin was not found.")
            continue
        if size_ratio != 8 and size_ratio != 4:
            if size_ratio != 12 and size_ratio != 6:
                print(f"[SKIP] {tileset_name} skipped because metatiles.bin is not eight times the size of metatile_attributes.bin (bad data?)\nmetatiles.bin size is {os.path.getsize(metatiles_path)}, metatile_attributes.bin size is {os.path.getsize(metatile_attributes_path)}")
            else:
                print(f"[SKIP] {tileset_name} skipped because metatiles.bin is twelve times the size of metatile_attributes.bin (already converted?)")
            continue

        if size_ratio == 8:
            # build up separate lists of Layer Type and Meta Attribute values from metatile_attributes.bin
            layer_types = []
            meta_attributes = []
            with open(metatile_attributes_path, 'rb') as fileobj:
                for chunk in iter(lambda: fileobj.read(2), ''): # each chunk in metatile_attributes.bin is 2 Bytes
                    if chunk == b'': # a null Byte means EOF (End Of File)
                        break
                    metatile_attribute = struct.unpack('<H', chunk)[0] # read 1 Half-Word into 1 array item
                    meta_attributes.append(metatile_attribute & META_ATTRIBUTE_MASK) # retrieves the Meta Attribute
                    layer_types.append((metatile_attribute & LAYER_TYPE_MASK) >> LAYER_TYPE_SHIFT) # retrieves the Layer Type
            
            # build up a list of the new 24-Byte (12-Half-Word) Metatile Data values
            i = 0
            new_metatile_data = []
            with open(metatiles_path, 'rb') as fileobj:
                for chunk in iter(lambda: fileobj.read(16), ''): # each chunk in metatiles.bin is 16 Bytes
                    if chunk == b'': # a null Byte means EOF (End Of File)
                        break
                    metatile_data = struct.unpack('<HHHHHHHH', chunk) # read 8 Half-Words into 8 array items
                    if layer_types[i] == 0:   # Layer Type NORMAL - Bottom Layer empty
                        new_metatile_data += [0]*4
                        new_metatile_data += metatile_data
                        if keep_layer_types:
                            meta_attributes[i] |= (3 << LAYER_TYPE_SHIFT) # Triple-Layer Type TOP - Bottom Layer empty
                    elif layer_types[i] == 1: # Layer Type COVERED - Top Layer empty
                        new_metatile_data += metatile_data
                        new_metatile_data += [0]*4
                        if keep_layer_types:
                            meta_attributes[i] |= (1 << LAYER_TYPE_SHIFT) # Triple-Layer Type COVERED - Top Layer empty
                    elif layer_types[i] == 2: # Layer Type Split - Middle Layer empty
                        new_metatile_data += metatile_data[:4] # first 4 Half-Words
                        new_metatile_data += [0]*4
                        new_metatile_data += metatile_data[4:] # last 4 Half-Words
                        if keep_layer_types:
                            meta_attributes[i] |= (2 << LAYER_TYPE_SHIFT) # Triple-Layer Type SPLIT - Midle Layer empty
                    else: # if no valid Layer Type found, all 3 Layers are now empty
                        new_metatile_data += [0]*12
                    i += 1

            metatile_buffer = struct.pack(f'<{len(new_metatile_data)}H', *new_metatile_data)
            metatile_attribute_buffer = struct.pack(f'<{len(meta_attributes)}H', *meta_attributes)
        elif size_ratio == 4: # FRLG tilesets
            # build up separate lists of Layer Type and Meta Attribute values from metatile_attributes.bin
            layer_types = []
            meta_attributes = []
            with open(metatile_attributes_path, 'rb') as fileobj:
                for chunk in iter(lambda: fileobj.read(4), ''): # each chunk in metatile_attributes.bin is 4 Bytes
                    if chunk == b'': # a null Byte means EOF (End Of File)
                        break
                    metatile_attribute = struct.unpack('<I', chunk)[0] # read 1 Word into 1 array item
                    meta_attributes.append(metatile_attribute & META_ATTRIBUTE_MASK_FRLG) # retrieves the Meta Attribute
                    layer_types.append((metatile_attribute & LAYER_TYPE_MASK_FRLG) >> LAYER_TYPE_SHIFT_FRLG) # retrieves the Layer Type
            
            # build up a list of the new 24-Byte (12-Half-Word) Metatile Data values
            i = 0
            new_metatile_data = []
            with open(metatiles_path, 'rb') as fileobj:
                for chunk in iter(lambda: fileobj.read(16), ''): # each chunk in metatiles.bin is 16 Bytes
                    if chunk == b'': # a null Byte means EOF (End Of File)
                        break
                    metatile_data = struct.unpack('<HHHHHHHH', chunk) # read 8 Half-Words into 8 array items
                    if layer_types[i] == 0:   # Layer Type NORMAL - Bottom Layer empty
                        new_metatile_data += [0]*4
                        new_metatile_data += metatile_data
                        if keep_layer_types:
                            meta_attributes[i] |= (3 << LAYER_TYPE_SHIFT_FRLG) # Triple-Layer Type TOP - Bottom Layer empty
                    elif layer_types[i] == 1: # Layer Type COVERED - Top Layer empty
                        new_metatile_data += metatile_data
                        new_metatile_data += [0]*4
                        if keep_layer_types:
                            meta_attributes[i] |= (1 << LAYER_TYPE_SHIFT_FRLG) # Triple-Layer Type COVERED - Top Layer empty
                    elif layer_types[i] == 2: # Layer Type Split - Middle Layer empty
                        new_metatile_data += metatile_data[:4] # first 4 Half-Words
                        new_metatile_data += [0]*4
                        new_metatile_data += metatile_data[4:] # last 4 Half-Words
                        if keep_layer_types:
                            meta_attributes[i] |= (2 << LAYER_TYPE_SHIFT_FRLG) # Triple-Layer Type SPLIT - Midle Layer empty
                    else: # if no valid Layer Type found, all 3 Layers are now empty
                        new_metatile_data += [0]*12
                    i += 1

            metatile_buffer = struct.pack(f'<{len(new_metatile_data)}H', *new_metatile_data)
            metatile_attribute_buffer = struct.pack(f'<{len(meta_attributes)}I', *meta_attributes)

        with open(metatiles_path, 'wb') as fileobj:
            fileobj.write(metatile_buffer)
        
        with open(metatile_attributes_path, 'wb') as fileobj:
            fileobj.write(metatile_attribute_buffer)
        
        print(f'[OK] Converted {tileset_name}')


def read_map_bin(file_path):
    with open(file_path, "rb") as f:
        data = f.read()
        return list(struct.unpack("<" + "H" * (len(data) // 2), data))

def write_map_bin(file_path, new_data):
    with open(file_path, "wb") as f:
        f.write(struct.pack("<" + "H" * len(new_data), *new_data))

def process_map_data(old_data, offset):
    new_data = []
    
    for value in old_data:
        metatile_id = value & old_metatile_id_mask
        collision = (value & old_collision_mask) >> old_num_metatile_id_bits
        elevation = (value & old_elevation_mask) >> (old_num_metatile_id_bits + old_num_collision_bits)
        
        # if elevation is the old maximum value, set it to the new maximum instead
        if elevation == (old_elevation_mask >> (old_num_metatile_id_bits + old_num_collision_bits)):
            elevation = new_elevation_mask

        # if a metatile's ID is greater than the size of the primary tileset, it is in the secondary tileset and needs to be shifted accordingly
        if metatile_id >= offset:
            metatile_id = metatile_id + ((new_metatile_count // 2) - offset) # the secondary tileset now begins at half of the total metatile count

        # re-combine the sub-values into the new format
        new_value = metatile_id | ((collision & new_collision_mask) << new_num_metatile_id_bits) | ((elevation & new_elevation_mask) << (new_num_metatile_id_bits + new_num_collision_bits))
        new_data.append(new_value)
    return new_data

def process_border_data(old_data, offset):
    new_data = []
    for value in old_data:
        metatile_id = value & old_metatile_id_mask

        if metatile_id >= offset:
            metatile_id = metatile_id + ((new_metatile_count // 2) - offset) # the secondary tileset now begins at half of the total metatile count

        new_data.append(metatile_id)
    return new_data

def str_to_bool(value):
    if value.lower() in ('true', '1', 't', 'y', 'yes'):
        return True
    elif value.lower() in ('false', '0', 'f', 'n', 'no'):
        return False
    else:
        raise argparse.ArgumentTypeError(f"Boolean value expected, got {value}")

if __name__ == "__main__":

    parser = argparse.ArgumentParser(description='Use arguments to either Convert pokeemerald Metatiles to use the Triple Layer system, Expand the number of available Metatiles, or both.',
                                     epilog='Must be run from the project\'s root folder or specify it with -r or --root.')
    parser.add_argument('-r', '--root', default='',
                        help='Path to the root directory of your pokeemerald project, e.g. /path/to/pokeemerald')
    parser.add_argument('-t', '--tsroot', default='data/tilesets',
                        help='Path to the tilesets directory in your pokeemerald project, e.g. /path/to/pokeemerald/data/tilesets')
    parser.add_argument('-m', '--loroot', default='data/layouts',
                        help='Path to the layouts directory in your pokeemerald project, e.g. /path/to/pokeemerald/data/layouts')
    parser.add_argument('-l', '--layers', default='2', choices=['2','3'],
                        help='Whether or not to attempt to Convert from Double to Triple Layer Metatiles. Cannot be used to Convert from Triple back to Double.')
    parser.add_argument('-c', '--colbits', default=True, type=str_to_bool, choices=[True,False],
                        help='Whether or not to attempt to Expand the number of available Metatiles by recycling an unused Collisions bit.')
    parser.add_argument('-e', '--elvbits', default=False, type=str_to_bool, choices=[True,False],
                        help='Whether or not to attempt to Expand the number of available Metatiles by repurposing an Elevations bit, halving available elevation values.')
    parser.add_argument('-k', '--keeptypes', default=False, type=str_to_bool, choices=[True,False],
                        help='Whether or not, when converting to Triple Layer Metatiles, to also convert Layer Types rather than defaulting to NORMAL.')

    args = parser.parse_args()

    args.layers = int(args.layers, 10)

    # Validate the CWD or given Root
    if not args.root == '':
        if not os.path.exists(args.root):
            print(f"[ERR] Given root directory does not exist: {args.root}")
            print(f"[SKIP] Attempting to use current working directory instead: {os.getcwd()}")
        else:
            print(f"[INFO] Setting current working directory to given root directory: {args.root}")
            os.chdir(args.root)
    else:
        print(f"[INFO] Defaulting to current working directory: {os.getcwd()}")

    # Validate the default/given tilesets directory root
    if not os.path.exists(args.tsroot):
        print(f"Given tilesets root directory does not exist: {args.tsroot}")
        exit(1)

    primary_path = os.path.join(args.tsroot, 'primary')
    if not os.path.exists(primary_path):
        print(f"[ERR] Given tilesets root directory does not contain a primary folder, aborting.")
        exit(1)
    
    secondary_path = os.path.join(args.tsroot, 'secondary')
    if not os.path.exists(secondary_path):
        print(f"[ERR] Given tilesets root directory does not contain a secondary folder, aborting.")
        exit(1)

    # Validate the default/given layouts directory root
    if not os.path.exists(args.loroot):
        print(f"Given layouts root directory does not exist: {args.loroot}")
        exit(1)

    layouts_path = os.path.join(args.loroot, 'layouts.json')
    if not os.path.exists(layouts_path):
        print(f"[ERR] Given layouts root directory does not contain a layouts.json, aborting.")
        exit(1)

    # Validate user requests for conversion
    if not (args.layers == 3 or args.colbits or args.elvbits):
        print(f"[ERR] This will not result in any changes to your project, aborting.")
        exit(1)

    # Prepare and Validate all known source files
    fieldmap_path          = 'include/fieldmap.h'           # may change the define "NUM_TILES_PER_METATILE" from 8 to 12
        # may also change the defines "NUM_METATILES_IN_PRIMARY", "NUM_METATILES_TOTAL", and add "MAX_ELEVATION_LEVEL"
    
    global_fieldmap_path   = 'include/global.fieldmap.h'    # may add "METATILE_LAYER_TYPE_DOOR = 0xFF" to the METATILE_LAYER_TYPE enum
        # may also read and write the values of "MAPGRID_METATILE_ID_MASK", "MAPGRID_COLLISION_MASK", "MAPGRID_ELEVATION_MASK", "MAPGRID_COLLISION_SHIFT", and "MAPGRID_ELEVATION_SHIFT"

    field_camera_path      = 'src/field_camera.c'           # may make a number of changes:
        # - DrawMetatile new definition (including METATILE_LAYER_TYPE_DOOR as 0xFF)
        # - DrawDoorMetatile will now call DrawMetatile with METATILE_LAYER_TYPE_DOOR instead of METATILE_LAYER_TYPE_COVERED

    shop_path              = 'src/shop.c'                   # may make a number of changes:
        # - BuyMenuDrawMapBg will replace a call to MapGridGetMetatileLayerTypeAt with the constant METATILE_LAYER_TYPE_NORMAL
        # - A new function IsMetatileLayerEmpty will be inserted before BuyMenuDrawMapMetatile
        # - BuyMenuDrawMapMetatile new definition (including calls to IsMetatileLayerEmpty)

    metatile_labels_path   = 'include/constants/metatile_labels.h' # all values greater than a determined value (end of primary tileset) must be increased

    # event_object_movement_path = 'src/event_object_movement.c' # a handful of statics require updating

    porymap_project_json_path   = 'porymap.project.json' # must add "collision_sheet_path": "collisions.png" to file if elevation bits decreased

    # these two files are used to confidently retrieve a tileset filepath from the tileset variable names in layouts.json
    tilesets_headers_path  = 'src/data/tilesets/headers.h'
    metatiles_path         = 'src/data/tilesets/metatiles.h'

    if args.layers == 3:
        print(f"[INFO] Attempting to convert from double layer metatile format to triple layer")
        tileset_dirs = []

        _, dirs, _ = next(os.walk(primary_path))
        tileset_dirs += map(lambda d: os.path.join(primary_path, d), dirs)
        _, dirs, _ = next(os.walk(secondary_path))
        tileset_dirs += map(lambda d: os.path.join(secondary_path, d), dirs)

        convert_tilesets_to_triple(tileset_dirs, args.keeptypes)

        with open(fieldmap_path, 'r+') as fieldmap_file:
            fieldmap = fieldmap_file.read()

            ## Not Applicable for target HnS version
            # find = r"#define\s*MAX_ELEVATION_LEVEL\s*[0-9]+"
            # if re.search(find, fieldmap) is None:
            #     replace = r"#define MAX_ELEVATION_LEVEL 15\n\g<1>12"
            # else:
            #     replace = r"\g<1>12"

            find = r"(#define\s*NUM_TILES_PER_METATILE\s*)([0-9]+)"
            replace = r"\g<1>12"
            new_fieldmap = re.sub(find, replace, fieldmap)
            fieldmap_file.seek(0)
            fieldmap_file.write(new_fieldmap)
            fieldmap_file.truncate()

        with open(global_fieldmap_path, 'r+') as global_fieldmap_file:
            global_fieldmap = global_fieldmap_file.read()
            find = r"(enum[\s\n]*{(?:([\s\n]*)METATILE_LAYER_TYPE_(?!DOOR|TOP).*)+)([\s\n]*})"
            replace = r"\1\2METATILE_LAYER_TYPE_TOP,\n\tMETATILE_LAYER_TYPE_DOOR = 0xFF,\3"
            new_global_fieldmap = re.sub(find, replace, global_fieldmap)
            global_fieldmap_file.seek(0)
            global_fieldmap_file.write(new_global_fieldmap)
            global_fieldmap_file.truncate()

        with open(field_camera_path, 'r+') as field_camera_file:
            field_camera = field_camera_file.read()

            find = r"void\s*DrawDoorMetatileAt\(.*[\s\n]*\{[\S\s\n]*sFieldCameraOffset\.copyBGToVRAM\s*=\s*TRUE;[^}]*}[^}]*}"
            replace = r"""void DrawDoorMetatileAt(int x, int y, u16 *tiles)
{
    int offset = MapPosToBgTilemapOffset(&sFieldCameraOffset, x, y);

    if (offset >= 0)
    {
        DrawMetatile(METATILE_LAYER_TYPE_DOOR, tiles, offset);
        sFieldCameraOffset.copyBGToVRAM = TRUE;
    }
}"""
            new_field_camera = re.sub(find, replace, field_camera)

            find = r"static\s*void\s*DrawMetatile\(.*[\s\n]*\{[\S\s\n]*ScheduleBgCopyTilemapToVram\(3\);[^}]}"
            replace = r"""static void DrawMetatile(s32 metatileLayerType, const u16 *tiles, u16 offset)
{
    if (metatileLayerType == METATILE_LAYER_TYPE_DOOR)
    {
        // When drawing a door metatile, use TOP behavior
        // Draw metatile's bottom layer to the bottom background layer.
        gOverworldTilemapBuffer_Bg3[offset] = tiles[0];
        gOverworldTilemapBuffer_Bg3[offset + 1] = tiles[1];
        gOverworldTilemapBuffer_Bg3[offset + 0x20] = tiles[2];
        gOverworldTilemapBuffer_Bg3[offset + 0x21] = tiles[3];

        // Draw transparent tiles to the middle background layer.
        gOverworldTilemapBuffer_Bg2[offset] = 0;
        gOverworldTilemapBuffer_Bg2[offset + 1] = 0;
        gOverworldTilemapBuffer_Bg2[offset + 0x20] = 0;
        gOverworldTilemapBuffer_Bg2[offset + 0x21] = 0;

        // Draw metatile's middle layer to the top background layer.
        gOverworldTilemapBuffer_Bg1[offset] = tiles[4];
        gOverworldTilemapBuffer_Bg1[offset + 1] = tiles[5];
        gOverworldTilemapBuffer_Bg1[offset + 0x20] = tiles[6];
        gOverworldTilemapBuffer_Bg1[offset + 0x21] = tiles[7];
    }
    else
    {
        // Draw metatile's bottom layer to the bottom background layer.
        gOverworldTilemapBuffer_Bg3[offset] = tiles[0];
        gOverworldTilemapBuffer_Bg3[offset + 1] = tiles[1];
        gOverworldTilemapBuffer_Bg3[offset + 0x20] = tiles[2];
        gOverworldTilemapBuffer_Bg3[offset + 0x21] = tiles[3];

        // Draw metatile's middle layer to the middle background layer.
        gOverworldTilemapBuffer_Bg2[offset] = tiles[4];
        gOverworldTilemapBuffer_Bg2[offset + 1] = tiles[5];
        gOverworldTilemapBuffer_Bg2[offset + 0x20] = tiles[6];
        gOverworldTilemapBuffer_Bg2[offset + 0x21] = tiles[7];

        // Draw metatile's top layer to the top background layer, which covers object event sprites.
        gOverworldTilemapBuffer_Bg1[offset] = tiles[8];
        gOverworldTilemapBuffer_Bg1[offset + 1] = tiles[9];
        gOverworldTilemapBuffer_Bg1[offset + 0x20] = tiles[10];
        gOverworldTilemapBuffer_Bg1[offset + 0x21] = tiles[11];
    }
    
    ScheduleBgCopyTilemapToVram(1);
    ScheduleBgCopyTilemapToVram(2);
    ScheduleBgCopyTilemapToVram(3);
}"""
            new_field_camera = re.sub(find, replace, new_field_camera)
            field_camera_file.seek(0)
            field_camera_file.write(new_field_camera)
            field_camera_file.truncate()

        with open(shop_path, 'r+') as shop_file:
            shop = shop_file.read()

            find = r"(metatileLayerType\s*=\s*)MapGridGetMetatileLayerTypeAt\(.*;"
            replace = r"\1METATILE_LAYER_TYPE_NORMAL;"
            new_shop = re.sub(find, replace, shop)

            find = r"(?<!;)(\n\s*)(?=static\s*void\s*BuyMenuDrawMapMetatile\()"
            replace = r"""\n\nstatic bool8 IsMetatileLayerEmpty(const u16 *src)
{
    for (u32 i = 0; i < 4; ++i)
    {
        if ((src[i] & MAPGRID_METATILE_ID_MASK) != 0)
            return FALSE;
    }
    return TRUE;
}\1"""
            new_shop = re.sub(find, replace, new_shop)

            find = r"static\s*void\s*BuyMenuDrawMapMetatile\(.*[\s\n]*\{[\S\s\n]*BuyMenuDrawMapMetatileLayer.*;[^}]*}[^}]*}"
            replace = r"""static void BuyMenuDrawMapMetatile(s16 x, s16 y, const u16 *src, u8 metatileLayerType)
{
    u16 offset1 = x * 2;
    u16 offset2 = y * 64;

    if (metatileLayerType == METATILE_LAYER_TYPE_NORMAL)
    {
        BuyMenuDrawMapMetatileLayer(sShopData->tilemapBuffers[2], offset1, offset2, src + 0);
        BuyMenuDrawMapMetatileLayer(sShopData->tilemapBuffers[3], offset1, offset2, src + 4);
        BuyMenuDrawMapMetatileLayer(sShopData->tilemapBuffers[1], offset1, offset2, src + 8);
    }
    else
    {
        if (IsMetatileLayerEmpty(src + 0))
        {
            BuyMenuDrawMapMetatileLayer(sShopData->tilemapBuffers[2], offset1, offset2, src + 4);
            BuyMenuDrawMapMetatileLayer(sShopData->tilemapBuffers[3], offset1, offset2, src + 8);
        }
        else if (IsMetatileLayerEmpty(src + 4))
        {
            BuyMenuDrawMapMetatileLayer(sShopData->tilemapBuffers[2], offset1, offset2, src + 0);
            BuyMenuDrawMapMetatileLayer(sShopData->tilemapBuffers[3], offset1, offset2, src + 8);
        }
        else if (IsMetatileLayerEmpty(src + 8))
        {
            BuyMenuDrawMapMetatileLayer(sShopData->tilemapBuffers[2], offset1, offset2, src + 0);
            BuyMenuDrawMapMetatileLayer(sShopData->tilemapBuffers[3], offset1, offset2, src + 4);
        }
    }
}"""
            new_shop = re.sub(find, replace, new_shop)

            shop_file.seek(0)
            shop_file.write(new_shop)
            shop_file.truncate()
        
    else:
        print(f"[SKIP] Not converting to triple layer metatile format.")

    if args.colbits or args.elvbits:
        global old_metatile_id_mask, old_collision_mask, old_elevation_mask, old_num_metatile_id_bits, old_num_collision_bits, old_num_elevation_bits
        global new_metatile_id_mask, new_collision_mask, new_elevation_mask, new_num_metatile_id_bits, new_num_collision_bits, new_num_elevation_bits
        global num_tiles_per_metatile

        with open(fieldmap_path) as fieldmap_file:
            fieldmap = fieldmap_file.read()
            regex = r"#define\s*NUM_TILES_PER_METATILE\s*([0-9]+)"
            num_tiles_per_metatile = int(re.search(regex, fieldmap)[1], 10) # assumes NUM_TILES_PER_METATILE will be decimal
            regex = r"#define\s*NUM_METATILES_IN_PRIMARY\s*([0-9]+)"
            old_num_metatiles_in_primary = int(re.search(regex, fieldmap)[1], 10) # assumes NUM_METATILES_IN_PRIMARY will be decimal
            # regex = r"#define\s*NUM_METATILES_IN_PRIMARY_EMERALD\s*([0-9]+)"
            # old_num_metatiles_in_primary_emerald = int(re.search(regex, fieldmap)[1], 10) # assumes NUM_METATILES_IN_PRIMARY_EMERALD will be decimal

        print(f"[TEST] Number of Metatiles in Primary prior to conversion: {old_num_metatiles_in_primary}")
        # print(f"[TEST] Number of Metatiles in Primary in Emerald prior to conversion: {old_num_metatiles_in_primary_emerald}")

        with open(global_fieldmap_path) as global_fieldmap_file:
            global_fieldmap = global_fieldmap_file.read()
            
            regex = r"#define\s*MAPGRID_METATILE_ID_MASK\s*(0x[0-9A-Fa-f]+)"
            old_metatile_id_mask = int(re.search(regex, global_fieldmap)[1], 16) # assumes MAPGRID_METATILE_ID_MASK will be hexadecimal

            regex = r"#define\s*MAPGRID_COLLISION_MASK\s*(0x[0-9A-Fa-f]+)"
            old_collision_mask = int(re.search(regex, global_fieldmap)[1], 16) # assumes MAPGRID_COLLISION_MASK will be hexadecimal

            regex = r"#define\s*MAPGRID_ELEVATION_MASK\s*(0x[0-9A-Fa-f]+)"
            old_elevation_mask = int(re.search(regex, global_fieldmap)[1], 16) # assumes MAPGRID_ELEVATION_MASK will be hexadecimal

            regex = r"#define\s*MAPGRID_COLLISION_SHIFT\s*([0-9]+)"
            old_num_metatile_id_bits = int(re.search(regex, global_fieldmap)[1], 10) # assumes MAPGRID_COLLISION_SHIFT will be decimal

            regex = r"#define\s*MAPGRID_ELEVATION_SHIFT\s*([0-9]+)"
            old_num_collision_bits = int(re.search(regex, global_fieldmap)[1], 10) - old_num_metatile_id_bits  # assumes MAPGRID_ELEVATION_SHIFT will be decimal

            old_num_elevation_bits = 16 - (old_num_metatile_id_bits + old_num_collision_bits)

        # determine the post-expansion state
        new_num_collision_bits   = old_num_collision_bits - args.colbits
        new_num_elevation_bits   = old_num_elevation_bits - args.elvbits

        if new_num_collision_bits < 1:
            print(f"[SKIP] Already at minimum 1 collision bit, cannot reduce to zero. Proceeding...")
            args.colbits = 0
            new_num_collision_bits = old_num_collision_bits

        if new_num_elevation_bits < 3:
            print(f"[SKIP] Already at minimum 3 elevation bits, cannot reduce further. Proceeding...")
            args.elvbits = 0
            new_num_elevation_bits = old_num_elevation_bits

        # Validate if metatile format is actually being changed
        if not (args.colbits or args.elvbits):
            print(f"[ERR] Neither collision or elevation bits are being reduced, aborting.")
            exit(1)

        new_num_metatile_id_bits = old_num_metatile_id_bits + args.colbits + args.elvbits

        # post-expansion masks
        new_metatile_id_mask = old_metatile_id_mask | (old_metatile_id_mask << (args.colbits + args.elvbits))
        new_collision_mask   = old_collision_mask >> (old_num_metatile_id_bits + args.colbits)
        new_elevation_mask   = old_elevation_mask >> (old_num_metatile_id_bits + old_num_collision_bits + args.elvbits)

        # the maximum number of metatiles per tileset pre-and-post-expansion
        old_metatile_count = 2 ** old_num_metatile_id_bits
        new_metatile_count = 2 ** new_num_metatile_id_bits

        if args.colbits:
            print(f"[INFO] Decreasing number of Collision Bits from {old_num_collision_bits} to {new_num_collision_bits}")

        if args.elvbits:
            print(f"[INFO] Decreasing number of Elevation Bits from {old_num_elevation_bits} to {new_num_elevation_bits}")

        print(f"[INFO] Increasing number of Metatile ID Bits from {old_num_metatile_id_bits} to {new_num_metatile_id_bits}")
        print(f"[INFO] Increasing maximum possible number of Metatiles per Tileset from {old_metatile_count} to {new_metatile_count}")

        with open(fieldmap_path, 'r+') as fieldmap_file:
            fieldmap = fieldmap_file.read()

            find = r"(#define\s*NUM_METATILES_IN_PRIMARY\s*)([0-9]+)"
            replace = r"\g<1>" + f"{int(new_metatile_count / 2)}"
            new_fieldmap = re.sub(find, replace, fieldmap)

            # find = r"(#define\s*NUM_METATILES_IN_PRIMARY_EMERALD\s*)([0-9]+)"
            # replace = r"\g<1>" + f"{int(new_metatile_count / 2)}"
            # new_fieldmap = re.sub(find, replace, new_fieldmap)

            find = r"(#define\s*NUM_METATILES_TOTAL\s*)([0-9]+)"
            replace = r"\g<1>" + f"{new_metatile_count}"
            new_fieldmap = re.sub(find, replace, new_fieldmap)
            
            fieldmap_file.seek(0)
            fieldmap_file.write(new_fieldmap)
            fieldmap_file.truncate()

        with open(global_fieldmap_path, 'r+') as global_fieldmap_file:
            global_fieldmap = global_fieldmap_file.read()

            find = r"(#define\s*MAPGRID_METATILE_ID_MASK\s*)(0x[0-9A-Fa-f]+).*"
            replace = r"\g<1>" + f"0x{new_metatile_id_mask:04X} // Bits 0-{new_num_metatile_id_bits - 1}"
            new_global_fieldmap = re.sub(find, replace, global_fieldmap)

            find = r"(#define\s*MAPGRID_COLLISION_MASK\s*)(0x[0-9A-Fa-f]+).*"
            replace = r"\g<1>" + f"0x{(new_collision_mask << new_num_metatile_id_bits):04X} // Bit{f"s {new_num_metatile_id_bits}-{new_num_metatile_id_bits + new_num_collision_bits - 1}" if new_num_collision_bits > 1 else f"  {new_num_metatile_id_bits}"}"
            new_global_fieldmap = re.sub(find, replace, new_global_fieldmap)

            find = r"(#define\s*MAPGRID_ELEVATION_MASK\s*)(0x[0-9A-Fa-f]+).*"
            replace = r"\g<1>" + f"0x{(new_elevation_mask << (new_num_metatile_id_bits + new_num_collision_bits)):04X} // Bits {new_num_metatile_id_bits + new_num_collision_bits}-15"
            new_global_fieldmap = re.sub(find, replace, new_global_fieldmap)

            find = r"(#define\s*MAPGRID_COLLISION_SHIFT\s*)([0-9]+).*"
            replace = r"\g<1>" + f"{new_num_metatile_id_bits}"
            new_global_fieldmap = re.sub(find, replace, new_global_fieldmap)

            find = r"(#define\s*MAPGRID_ELEVATION_SHIFT\s*)([0-9]+).*"
            replace = r"\g<1>" + f"{new_num_metatile_id_bits + new_num_collision_bits}"
            new_global_fieldmap = re.sub(find, replace, new_global_fieldmap)

            find = r"(ELEVATION_MULTI_LEVEL\s*=\s*)([0-9]+)(.*)"
            replace = r"\g<1>" + f"{(2 ** new_num_elevation_bits) - 1}" + r"\g<3>"
            new_global_fieldmap = re.sub(find, replace, new_global_fieldmap)
            
            global_fieldmap_file.seek(0)
            global_fieldmap_file.write(new_global_fieldmap)
            global_fieldmap_file.truncate()

        with open(metatile_labels_path) as metatile_labels_file:
            new_lines = []
            for line in metatile_labels_file:
                find = r"(#define\s*METATILE_([^_]*)_.*)(0x[0-9A-Fa-f]+)"
                hit = re.search(find, line)
                if hit is None:
                    new_lines += line
                else:
                    num = int(hit[3], 16)

                    # emerald_metatiles = [
                    #     "BattleArena",
                    #     "BattleDome",
                    #     "BattleFrontier",
                    #     "BattleFrontierOutsideEast",
                    #     "BattleFrontierOutsideWest",
                    #     "BattlePalace",
                    #     "BattlePike",
                    #     "BattlePyramid",
                    #     "BattleTent",
                    #     "BikeShop",
                    #     "BrendansMaysHouse",
                    #     "Cave",
                    #     "Contest",
                    #     "Dewford",
                    #     "EliteFour",
                    #     "EverGrande",
                    #     "Facility",
                    #     "Fallarbor",
                    #     "Fortree",
                    #     "GenericBuilding",
                    #     "InsideOfTruck",
                    #     "InsideShip",
                    #     "Lavaridge",
                    #     "Lilycove",
                    #     "LilycoveMuseum",
                    #     "Mauville",
                    #     "MauvilleGym",
                    #     "MeteorFalls",
                    #     "MossdeepGameCorner",
                    #     "MossdeepGym",
                    #     "Pacifidlog",
                    #     "Petalburg",
                    #     "PetalburgGym",
                    #     "PokemonCenter",
                    #     "Rustboro",
                    #     "SecretBase",
                    #     "Shop",
                    #     "Slateport",
                    #     "Sootopolis",
                    #     "TrainerHill",
                    #     "TrickHousePuzzle",
                    #     "Underwater",
                    #     "RSCave",
                    #     "RSMossdeepGym"
                    # ]

                    # if num > old_num_metatiles_in_primary_emerald and hit[2] in emerald_metatiles:
                    #     num = num + (int(new_metatile_count / 2) - old_num_metatiles_in_primary_emerald)
                    #     new_lines += hit[1] + f"0x{num:03X}\n"
                    # el

                    if num > old_num_metatiles_in_primary:
                        num = num + (int(new_metatile_count / 2) - old_num_metatiles_in_primary)
                        new_lines += hit[1] + f"0x{num:03X}\n"
                    else:
                        new_lines += line

        with open(metatile_labels_path, 'w') as metatile_labels_file:
            for new_line in new_lines:
                metatile_labels_file.write(new_line)

#         if args.elvbits:
#             with open(event_object_movement_path, 'r+') as event_object_movement_file:
#                 event_object_movement = event_object_movement_file.read()

#                 find = r"static\s*const\s*u8\s*sElevationToSubpriority[^;]*;"
#                 replace = r"""static const u8 sElevationToSubpriority[] = {
#     115, 115, 83, 115, 83, 115, 83, 115
# };"""
#                 new_event_object_movement = re.sub(find, replace, event_object_movement)

#                 find = r"static\s*const\s*u8\s*sElevationToPriority[^;]*;"
#                 replace = r"""static const u8 sElevationToPriority[] = {
#     2, 2, 2, 2, 1, 2, 1, 2
# };"""
#                 new_event_object_movement = re.sub(find, replace, new_event_object_movement)

#                 find = r"static\s*const\s*u8\s*sElevationToSubspriteTableNum[^;]*;"
#                 replace = r"""static const u8 sElevationToSubspriteTableNum[] = {
#     1, 1, 1, 1, 2, 1, 2, 1
# };"""
#                 new_event_object_movement = re.sub(find, replace, new_event_object_movement)
                            
#                 event_object_movement_file.seek(0)
#                 event_object_movement_file.write(new_event_object_movement)
#                 event_object_movement_file.truncate()

        #     with open(porymap_project_json_path, 'r+') as porymap_project_json_file:
        #         porymap_project_json = json.load(porymap_project_json_file)
        #         porymap_project_json['collision_sheet_path'] = "collisions.png"
        #         json.dump(porymap_project_json, porymap_project_json_file, indent=4)
        
        with open(layouts_path) as layouts_file, \
            open(tilesets_headers_path) as tileset_headers_file, \
            open(metatiles_path) as metatiles_file:

            layouts = json.load(layouts_file)
            tileset_headers = tileset_headers_file.read()
            metatiles = metatiles_file.read()

            # iterate through all layouts in the project, updating the metatile format of every map.bin and border.bin file.
            # additionally, build a dictionary of the tileset variable names those layouts use, and the size of the respective tileset
            tileset_sizes = {}
            for layout in layouts['layouts']:
                primary_tileset_variable_name = layout['primary_tileset']
                map_path = layout['blockdata_filepath']
                border_path = layout['border_filepath']

                # have not encountered this tileset yet
                if primary_tileset_variable_name not in tileset_sizes.keys():
                    regex = primary_tileset_variable_name + r"(?:[^}]|\n)*\.metatiles = (.*),"
                    metatiles_variable = re.search(regex, tileset_headers)[1]

                    regex = metatiles_variable + r"\[\] = INCBIN_U16\(\"(.*)\"\)\;"
                    tileset_file = re.search(regex, metatiles)[1]

                    # len(data) is in Bytes, so the tileset size (number of metatiles) is that length divided by the number of Bytes per metatile
                    # Bytes per metatile = 2 bytes per tile * 4 tiles per layer * <2 or 3> layers per metatile
                    with open(tileset_file, "rb") as f:
                        data = f.read()
                        tileset_sizes[primary_tileset_variable_name] = (len(data) // (2 * num_tiles_per_metatile))

                # update the map.bin file
                # print(f"Processing {map_path}...")
                old_data = read_map_bin(map_path)
                new_data = process_map_data(old_data, old_num_metatiles_in_primary) # tileset_sizes[primary_tileset_variable_name])
                write_map_bin(map_path, new_data)
                
                # update the border.bin file
                # print(f"Processing {border_path}...")
                old_data = read_map_bin(border_path)
                new_data = process_border_data(old_data, old_num_metatiles_in_primary) # tileset_sizes[primary_tileset_variable_name])
                write_map_bin(border_path, new_data)

            print("Found the following Primary Tilesets and their number of metatiles:")
            print(tileset_sizes)
    else:
        print(f"[SKIP] Not expanding number of maximum possible Metatiles per Tileset.")
