import os
import struct
import argparse

# Triple-layer constants
TILES_PER_LAYER = 4
LAYERS = 3
TILES_PER_METATILE = TILES_PER_LAYER * LAYERS  # 12 tiles per metatile

# Layer type enums
METATILE_LAYER_TYPE_NORMAL  = 0  # bottom + middle + top
METATILE_LAYER_TYPE_COVERED = 1  # bottom + middle
METATILE_LAYER_TYPE_SPLIT   = 2  # bottom + top
METATILE_LAYER_TYPE_TOP     = 3  # (some combination where everything shifts down)

"""
Shift-Down Layer Resolution Table
---------------------------------
Always try to shift tiles downward if there is space beneath them.
BOTTOM  MIDDLE  TOP     → Result layer_type
-------------------------------------------
no      no      yes     → TOP       (top → middle → bottom)
no      yes     no      → TOP       (middle → bottom)
yes     no      no      → COVERED   (only bottom exists)
no      yes     yes     → TOP       (middle + top shift down)
yes     no      yes     → SPLIT     (top shifts to middle)
yes     yes     no      → COVERED   (bottom + middle)
yes     yes     yes     → NORMAL    (all present)
no      no      no      → COVERED   (fallback; do NOT set NORMAL)
-------------------------------------------
"""

parser = argparse.ArgumentParser(description="Fix metatileLayerType for triple-layer metatiles")
parser.add_argument("--tsroot", required=True, help="Path to tilesets root")
args = parser.parse_args()

primary_path = os.path.join(args.tsroot, 'primary')
secondary_path = os.path.join(args.tsroot, 'secondary')
tileset_dirs = []

for root in [primary_path, secondary_path]:
    if os.path.exists(root):
        _, dirs, _ = next(os.walk(root))
        tileset_dirs += [os.path.join(root, d) for d in dirs]

for tileset_dir in tileset_dirs:
    tileset_name = os.path.basename(tileset_dir)
    metatiles_path = os.path.join(tileset_dir, 'metatiles.bin')
    metatile_attributes_path = os.path.join(tileset_dir, 'metatile_attributes.bin')

    if not os.path.exists(metatiles_path) or not os.path.exists(metatile_attributes_path):
        print(f"[SKIP] {tileset_name}: missing files")
        continue

    # Read tiles
    with open(metatiles_path, 'rb') as f:
        tiles_data = f.read()
    tiles = struct.unpack(f"<{len(tiles_data)//2}H", tiles_data)

    # Read attributes
    with open(metatile_attributes_path, 'rb') as f:
        attr_data = f.read()
    attributes = list(struct.unpack(f"<{len(attr_data)//2}H", attr_data))

    # Total metatiles
    num_metatiles = len(tiles_data) // (TILES_PER_METATILE * 2)
    if len(attributes) != num_metatiles:
        print(f"[ERROR] {tileset_name}: number of metatiles ({num_metatiles}) "
              f"does not match number of attributes ({len(attributes)})")
        continue

    new_attributes = []
    for i in range(num_metatiles):
        base = i * TILES_PER_METATILE

        bottom = tiles[base : base+4]
        middle = tiles[base+4 : base+8]
        top    = tiles[base+8 : base+12]

        has_bottom = any(t != 0 for t in bottom)
        has_middle = any(t != 0 for t in middle)
        has_top    = any(t != 0 for t in top)

        # Determine layer type via shift-down rules
        if has_bottom and has_middle and has_top:
            layer_type = METATILE_LAYER_TYPE_NORMAL

        elif has_bottom and has_middle and not has_top:
            layer_type = METATILE_LAYER_TYPE_COVERED

        elif has_bottom and not has_middle and has_top:
            layer_type = METATILE_LAYER_TYPE_SPLIT

        elif not has_bottom and has_middle and has_top:
            layer_type = METATILE_LAYER_TYPE_TOP

        elif not has_bottom and has_middle and not has_top:
            layer_type = METATILE_LAYER_TYPE_TOP

        elif not has_bottom and not has_middle and has_top:
            layer_type = METATILE_LAYER_TYPE_TOP

        elif has_bottom and not has_middle and not has_top:
            layer_type = METATILE_LAYER_TYPE_COVERED

        else:
            # all empty → fallback (do NOT set NORMAL)
            layer_type = METATILE_LAYER_TYPE_COVERED

        # Preserve lower 12 bits, set top 4 bits
        new_attr = (layer_type << 12) | (attributes[i] & 0x0FFF)
        new_attributes.append(new_attr)

    # Write updated attributes back
    with open(metatile_attributes_path, 'wb') as f:
        f.write(struct.pack(f"<{len(new_attributes)}H", *new_attributes))

    print(f"[OK] Updated metatileLayerType for {tileset_name}")
