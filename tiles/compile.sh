#!/bin/bash

echo "Compiling [PRIMARY] indoor_mart"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_mart ./tiles/indoor_mart ./include/constants/metatile_behaviors.h
# echo "Compiling [secondary] mart_main"
# porytiles compile-secondary -Wall -o ./data/tilesets/secondary/mart_main ./tiles/mart_main ./tiles/indoor_mart ./include/constants/metatile_behaviors.h
