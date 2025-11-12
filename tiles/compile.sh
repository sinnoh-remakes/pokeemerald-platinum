#!/bin/bash

echo "Compiling [PRIMARY] indoor_center"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_center ./tiles/indoor_center ./include/constants/metatile_behaviors.h
# echo "Compiling [secondary] common_center"
# porytiles compile-secondary -Wall -o ./data/tilesets/secondary/common_center ./tiles/common_center ./tiles/indoor_center ./include/constants/metatile_behaviors.h
