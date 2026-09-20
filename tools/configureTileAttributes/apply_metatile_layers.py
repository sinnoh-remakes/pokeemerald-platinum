import os
import csv
import struct
import argparse

# Known 4-bit layer enums
LAYER_TYPES = {
    "NORMAL": 0,
    "COVERED": 1,
    "SPLIT": 2,
    "TOP": 3
}


def load_csv(csv_path):
    table = {}
    with open(csv_path, newline="") as f:
        reader = csv.DictReader(f)
        for row in reader:
            tileset = row["tileset"]
            index   = int(row["index"])
            raw     = row["type_or_hex"].strip().upper()

            # Named layer?
            if raw in LAYER_TYPES:
                layer_val = LAYER_TYPES[raw]

            # Hex layer?
            elif raw.startswith("0X"):
                try:
                    layer_val = int(raw, 16) & 0xF
                except ValueError:
                    print(f"[WARN] Bad hex '{raw}' → skipping")
                    continue

            else:
                print(f"[WARN] Unknown layer '{raw}' → skipping")
                continue

            table.setdefault(tileset, {})[index] = layer_val
    return table


def apply_to_tilesets(tsroot, table):
    primary_path   = os.path.join(tsroot, "primary")
    secondary_path = os.path.join(tsroot, "secondary")

    # All tileset directories
    targets = []
    for root in (primary_path, secondary_path):
        if os.path.exists(root):
            _, dirs, _ = next(os.walk(root))
            targets += [os.path.join(root, d) for d in dirs]

    updated = 0

    for tileset_dir in targets:
        tileset_name = os.path.basename(tileset_dir)
        meta_attr_path = os.path.join(tileset_dir, "metatile_attributes.bin")

        if not os.path.exists(meta_attr_path):
            print(f"[SKIP] {tileset_name}: missing metatile_attributes.bin")
            continue

        if tileset_name not in table:
            print(f"[SKIP] {tileset_name}: no rows in CSV")
            continue

        overrides = table[tileset_name]

        # ---- Load binary ----
        with open(meta_attr_path, "rb") as f:
            attr_data = f.read()

        attrs = list(struct.unpack(f"<{len(attr_data)//2}H", attr_data))

        # ---- Patch ----
        for idx, new_layer in overrides.items():
            if idx >= len(attrs):
                print(f"[WARN] {tileset_name}: index {idx} out of range")
                continue

            old = attrs[idx]
            new = (new_layer << 12) | (old & 0x0FFF)
            attrs[idx] = new

        # ---- Store updated ----
        with open(meta_attr_path, "wb") as f:
            f.write(struct.pack(f"<{len(attrs)}H", *attrs))

        print(f"[OK] Updated {tileset_name}")
        updated += 1

    print(f"[DONE] Updated {updated} tilesets")


def main():
    parser = argparse.ArgumentParser(
        description="Apply metatile layer types to tilesets from CSV"
    )
    parser.add_argument("--tsroot", required=True, help="Tilesets root")
    parser.add_argument("--csv",    required=True, help="Layer-spec CSV")
    args = parser.parse_args()

    table = load_csv(args.csv)
    apply_to_tilesets(args.tsroot, table)


if __name__ == "__main__":
    main()
