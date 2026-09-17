import os
import struct
import argparse
import csv

# Triple-layer constants
TILES_PER_LAYER = 4
LAYERS = 3
TILES_PER_METATILE = TILES_PER_LAYER * LAYERS  # 12 tiles per metatile

# Known 4-bit layer enums
METATILE_LAYER_TYPE_NORMAL  = 0
METATILE_LAYER_TYPE_COVERED = 1
METATILE_LAYER_TYPE_SPLIT   = 2
METATILE_LAYER_TYPE_TOP     = 3

LAYER_TYPE_NAMES_4BIT = {
    METATILE_LAYER_TYPE_NORMAL:  "NORMAL",
    METATILE_LAYER_TYPE_COVERED: "COVERED",
    METATILE_LAYER_TYPE_SPLIT:   "SPLIT",
    METATILE_LAYER_TYPE_TOP:     "TOP",
}

parser = argparse.ArgumentParser(description="Export metatile layer types to CSV")
parser.add_argument("--tsroot", required=True, help="Path to tilesets root (contains primary/ and secondary/)")
parser.add_argument("--out", default="metatile_layers.csv", help="Output CSV file")
args = parser.parse_args()

primary_path = os.path.join(args.tsroot, "primary")
secondary_path = os.path.join(args.tsroot, "secondary")
tileset_dirs = []

for root in (primary_path, secondary_path):
    if os.path.exists(root):
        _, dirs, _ = next(os.walk(root))
        tileset_dirs += [os.path.join(root, d) for d in dirs]

rows = []

for tileset_dir in tileset_dirs:
    tileset_name = os.path.basename(tileset_dir)
    metatiles_path = os.path.join(tileset_dir, "metatiles.bin")
    attributes_path = os.path.join(tileset_dir, "metatile_attributes.bin")

    if not os.path.exists(metatiles_path) or not os.path.exists(attributes_path):
        print(f"[SKIP] {tileset_name}: missing files")
        continue

    # Read tile data
    with open(metatiles_path, "rb") as f:
        tiles_data = f.read()

    # Read attributes
    with open(attributes_path, "rb") as f:
        attr_data = f.read()
    attributes = list(struct.unpack(f"<{len(attr_data)//2}H", attr_data))

    # Count metatiles
    num_metatiles = len(tiles_data) // (TILES_PER_METATILE * 2)
    if len(attributes) != num_metatiles:
        print(f"[ERROR] {tileset_name}: mismatch metatiles={num_metatiles} attrs={len(attributes)}")
        continue

    for idx in range(num_metatiles):
        attr = attributes[idx]

        # Extract 4-bit layer type
        layer4 = (attr >> 12) & 0xF

        # If one of the known 0-3 values, map to name; otherwise hex
        if layer4 in LAYER_TYPE_NAMES_4BIT:
            type_str = LAYER_TYPE_NAMES_4BIT[layer4]
        else:
            type_str = f"0x{layer4:X}"

        rows.append([
            tileset_name,
            idx,
            type_str
        ])

    print(f"[OK] Exported {num_metatiles} from {tileset_name}")

# Write CSV
with open(args.out, "w", newline="") as f:
    writer = csv.writer(f)
    writer.writerow(["tileset", "index", "type_or_hex"])
    writer.writerows(rows)

print(f"[DONE] Wrote {len(rows)} entries -> {args.out}")
