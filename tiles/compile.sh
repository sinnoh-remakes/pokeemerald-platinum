#!/bin/bash

# Compile each tileset
echo "Compiling all tilesets..."
porytiles compile-primary -Wall -o ./data/tilesets/primary/outdoor_jubilife ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "[PRIMARY] outdoor_jubilife - compiled successfully"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/twinleaf ./tiles/twinleaf ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "[SECONDARY] twinleaf - compiled successfully"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/route_201 ./tiles/route_201 ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "[SECONDARY] route_201 - compiled successfully"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/lake ./tiles/lake ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "[SECONDARY] lake - compiled successfully"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/gatehouse ./tiles/gatehouse ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "[SECONDARY] gatehouse - compiled successfully"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_twinleaf ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h
echo "[PRIMARY] indoor_twinleaf - compiled successfully"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/twinleaf_player ./tiles/twinleaf_player ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h
echo "[SECONDARY] twinleaf_player - compiled successfully"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/twinleaf_living ./tiles/twinleaf_living ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h
echo "[SECONDARY] twinleaf_living - compiled successfully"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/twinleaf_other ./tiles/twinleaf_other ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h
echo "[SECONDARY] twinleaf_other - compiled successfully"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_twinleaf_2 ./tiles/indoor_twinleaf_2 ./include/constants/metatile_behaviors.h
echo "[PRIMARY] indoor_twinleaf_2 - compiled successfully"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/twinleaf_rival ./tiles/twinleaf_rival ./tiles/indoor_twinleaf_2 ./include/constants/metatile_behaviors.h
echo "[SECONDARY] twinleaf_rival - compiled successfully"
