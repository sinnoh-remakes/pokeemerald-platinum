#!/bin/bash

# Compile each tileset
echo "Compiling all tilesets..."
echo "Compiling [PRIMARY] outdoor_jubilife"
porytiles compile-primary -Wall -o ./data/tilesets/primary/outdoor_jubilife ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "Compiling [SECONDARY] twinleaf"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/twinleaf ./tiles/twinleaf ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "Compiling [SECONDARY] route_201"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/route_201 ./tiles/route_201 ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "Compiling [SECONDARY] sandgem"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/sandgem ./tiles/sandgem ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "Compiling [SECONDARY] lake"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/lake ./tiles/lake ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "Compiling [SECONDARY] gatehouse"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/gatehouse ./tiles/gatehouse ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "Compiling [PRIMARY] indoor_twinleaf"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_twinleaf ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h
echo "Compiling [SECONDARY] twinleaf_player"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/twinleaf_player ./tiles/twinleaf_player ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h
echo "Compiling [SECONDARY] twinleaf_living"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/twinleaf_living ./tiles/twinleaf_living ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h
echo "Compiling [SECONDARY] twinleaf_other"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/twinleaf_other ./tiles/twinleaf_other ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h
echo "Compiling [PRIMARY] indoor_twinleaf_2"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_twinleaf_2 ./tiles/indoor_twinleaf_2 ./include/constants/metatile_behaviors.h
echo "Compiling [SECONDARY] twinleaf_rival"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/twinleaf_rival ./tiles/twinleaf_rival ./tiles/indoor_twinleaf_2 ./include/constants/metatile_behaviors.h
