#!/bin/bash
#
# Compiles the Sinnoh overworld tilesets from their Porytiles sources.
#
# Sources live next to the compiled output:
#   data/tilesets/{primary,secondary}/<name>/porytiles_src/
#
# Porytiles 2.x manages almost every tileset (see porytiles/tilesets/). For
# those, output goes to <name>/porytiles_bin/, animation code is generated
# into include/porytiles_generated/, and per-tileset settings (primary
# pairing, tile limits, ...) live in
# porytiles/tilesets/<gTileset_Name>/config.yaml. Porytiles names each folder
# after the tileset's struct, e.g. gTileset_Route206 -> route206/.
#
# Five families still use porytiles-legacy because Porytiles 2.0.0 cannot
# compile one of their secondaries: secondaries with more than 105 unique
# colours crash its palette packer, and it does not support locked palettes
# for secondaries yet. A primary and every secondary compiled against it
# must use the same compiler (legacy compile-secondary re-packs the primary
# itself), so each of these families moves to Porytiles 2.x as a whole.
#
# Usage: ./compile_tiles.sh   (run from anywhere; paths are repo-relative)

cd "$(dirname "$0")" || exit 1

BEHAVIORS=./include/constants/metatile_behaviors.h
PRIMARY=./data/tilesets/primary
SECONDARY=./data/tilesets/secondary
FAILED=()

# porytiles 2.x: compile managed tilesets by struct name (primaries first).
compile() {
    for tileset in "$@"; do
        echo "Compiling $tileset"
        porytiles compile-tileset "$tileset" || FAILED+=("$tileset")
    done
}

# porytiles-legacy: <name> [extra flags...]
legacy_primary() {
    local name=$1; shift
    echo "Compiling [PRIMARY] $name (legacy)"
    porytiles-legacy compile-primary "$@" -Wall -o "$PRIMARY/$name" \
        "$PRIMARY/$name/porytiles_src" "$BEHAVIORS" || FAILED+=("$name")
}

# porytiles-legacy: <name> <primary name> [extra flags...]
legacy_secondary() {
    local name=$1 primary=$2; shift 2
    echo "Compiling [secondary] $name (legacy, primary: $primary)"
    porytiles-legacy compile-secondary "$@" -Wall -o "$SECONDARY/$name" \
        "$SECONDARY/$name/porytiles_src" "$PRIMARY/$primary/porytiles_src" "$BEHAVIORS" || FAILED+=("$name")
}

########################################################################
# Porytiles 2.x
########################################################################

compile gTileset_IndoorCenter gTileset_CommonCenter1F gTileset_CommonCenter2F
compile gTileset_IndoorMart gTileset_CommonMart
compile gTileset_OutdoorJubilife gTileset_Twinleaf gTileset_Route201 gTileset_Lake gTileset_Sandgem \
    gTileset_Jubilife gTileset_Route203 gTileset_Route204South
compile gTileset_IndoorTwinleaf gTileset_TwinleafPlayer gTileset_TwinleafLiving gTileset_TwinleafHouse \
    gTileset_SandgemLiving gTileset_SandgemHelper gTileset_EternaIndoor gTileset_Gatehouse
compile gTileset_IndoorTwinleafRival gTileset_TwinleafRival
compile gTileset_IndoorSandgemLab gTileset_SandgemLab
compile gTileset_IndoorJubilife gTileset_JubilifeTower gTileset_JubilifeSchool
compile gTileset_GymOreburgh gTileset_OreburghGym
compile gTileset_CaveOreburgh gTileset_OreburghMine
compile gTileset_CaveCoronetSouth gTileset_RavagedPath
compile gTileset_CaveCoronetNorth
compile gTileset_OutdoorRoute204 gTileset_Route204North
compile gTileset_IndoorSunyshore gTileset_SunyshoreHouse
compile gTileset_IndoorWindworks gTileset_ValleyWindworksIndoor
compile gTileset_IndoorForest
compile gTileset_IndoorCycleShop gTileset_CycleShop
compile gTileset_IndoorGalacticEterna gTileset_GalacticEternaIndoor
compile gTileset_IndoorGalacticSpace gTileset_GalacticSpaceIndoor
compile gTileset_GymEterna gTileset_EternaGym

########################################################################
# porytiles-legacy (blocked on Porytiles 2.0.0; see top of file)
########################################################################

# Blocked by eterna_north (128 colours) and eterna_south (120).
# gTileset_OutdoorEterna and its secondaries use NUM_TILES_IN_PRIMARY_ETERNA (384).
legacy_primary outdoor_eterna -tiles-primary-override=384
legacy_secondary eterna_north outdoor_eterna -tiles-primary-override=384
legacy_secondary eterna_south outdoor_eterna -tiles-primary-override=384
legacy_secondary route_205_north outdoor_eterna -tiles-primary-override=384
legacy_secondary route_211_west outdoor_eterna -tiles-primary-override=384

# Blocked by floaroma (113 colours).
legacy_primary outdoor_floaroma
legacy_secondary floaroma outdoor_floaroma

# Blocked by oreburgh_north (107 colours) and route_207 (125).
legacy_primary outdoor_oreburgh
legacy_secondary oreburgh_north outdoor_oreburgh
legacy_secondary oreburgh_south outdoor_oreburgh
legacy_secondary route_207 outdoor_oreburgh

# Blocked by route_205_south_2 (106 colours).
legacy_primary outdoor_route_205
legacy_secondary route_205_south_1 outdoor_route_205
legacy_secondary route_205_south_2 outdoor_route_205
legacy_secondary valley_windworks outdoor_route_205
legacy_secondary floaroma_meadow outdoor_route_205

# Blocked by route_206 (130 colours).
legacy_primary outdoor_route_206
legacy_secondary route_206 outdoor_route_206

if [ ${#FAILED[@]} -ne 0 ]; then
    echo
    echo "Failed to compile: ${FAILED[*]}"
    exit 1
fi
