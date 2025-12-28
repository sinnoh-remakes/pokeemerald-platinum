#!/bin/bash

echo "Compiling [PRIMARY] outdoor_jubilife"
porytiles compile-primary -Wall -o ./data/tilesets/primary/outdoor_jubilife ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] twinleaf"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/twinleaf ./tiles/twinleaf ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] route_201"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/route_201 ./tiles/route_201 ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] lake"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/lake ./tiles/lake ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] sandgem"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/sandgem ./tiles/sandgem ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] jubilife"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/jubilife ./tiles/jubilife ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] route_203"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/route_203 ./tiles/route_203 ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] route_204"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/route_204 ./tiles/route_204 ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h

echo "Compiling [PRIMARY] outdoor_oreburgh"
porytiles compile-primary -Wall -o ./data/tilesets/primary/outdoor_oreburgh ./tiles/outdoor_oreburgh ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] oreburgh_north"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/oreburgh_north ./tiles/oreburgh_north ./tiles/outdoor_oreburgh ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] oreburgh_south"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/oreburgh_south ./tiles/oreburgh_south ./tiles/outdoor_oreburgh ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] route_207"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/route_207 ./tiles/route_207 ./tiles/outdoor_oreburgh ./include/constants/metatile_behaviors.h

echo "Compiling [PRIMARY] indoor_twinleaf"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_twinleaf ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] twinleaf_player"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/twinleaf_player ./tiles/twinleaf_player ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] twinleaf_living"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/twinleaf_living ./tiles/twinleaf_living ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] twinleaf_house"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/twinleaf_house ./tiles/twinleaf_house ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] sandgem_living"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/sandgem_living ./tiles/sandgem_living ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] sandgem_helper"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/sandgem_helper ./tiles/sandgem_helper ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h

echo "Compiling [PRIMARY] indoor_twinleaf_rival"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_twinleaf_rival ./tiles/indoor_twinleaf_rival ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] twinleaf_rival"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/twinleaf_rival ./tiles/twinleaf_rival ./tiles/indoor_twinleaf_rival ./include/constants/metatile_behaviors.h

echo "Compiling [PRIMARY] indoor_sandgem_lab"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_sandgem_lab ./tiles/indoor_sandgem_lab ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] sandgem_lab"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/sandgem_lab ./tiles/sandgem_lab ./tiles/indoor_sandgem_lab ./include/constants/metatile_behaviors.h

echo "Compiling [PRIMARY] indoor_center"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_center ./tiles/indoor_center ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] common_center"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/common_center ./tiles/common_center ./tiles/indoor_center ./include/constants/metatile_behaviors.h
echo "Compiling [PRIMARY] indoor_mart"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_mart ./tiles/indoor_mart ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] common_mart"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/common_mart ./tiles/common_mart ./tiles/indoor_mart ./include/constants/metatile_behaviors.h

echo "Compiling [PRIMARY] cave_coronet"
porytiles compile-primary -Wall -o ./data/tilesets/primary/cave_coronet ./tiles/cave_coronet ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] ravaged_path"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/ravaged_path ./tiles/ravaged_path ./tiles/cave_coronet ./include/constants/metatile_behaviors.h
