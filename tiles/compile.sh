#!/bin/bash

echo "Compiling [PRIMARY] outdoor_oreburgh"
porytiles compile-primary -Wall -o ./data/tilesets/primary/outdoor_oreburgh ./tiles/outdoor_oreburgh ./include/constants/metatile_behaviors.h
# echo "Compiling [secondary] oreburgh_north"
# porytiles compile-secondary -Wall -o ./data/tilesets/secondary/oreburgh_north ./tiles/oreburgh_north ./tiles/outdoor_oreburgh ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] oreburgh_south"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/oreburgh_south ./tiles/oreburgh_south ./tiles/outdoor_oreburgh ./include/constants/metatile_behaviors.h
