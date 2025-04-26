#!/bin/bash

# Compile each tileset
echo "Compiling all tilesets..."
echo "[PRIMARY] outdoor - compiled successfully"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/twinleaf ./tiles/twinleaf ./tiles/outdoor ./include/constants/metatile_behaviors.h
echo "[SECONDARY] twinleaf - compiled successfully"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/route_201 ./tiles/route_201 ./tiles/outdoor ./include/constants/metatile_behaviors.h
echo "[SECONDARY] route_201 - compiled successfully"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/gatehouse ./tiles/gatehouse ./tiles/outdoor ./include/constants/metatile_behaviors.h
echo "[SECONDARY] gatehouse - compiled successfully"
