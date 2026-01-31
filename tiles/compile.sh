#!/bin/bash

echo "Compiling [PRIMARY] indoor_center"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_center ./tiles/indoor_center ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] common_center_2f"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/common_center_2f ./tiles/common_center_2f ./tiles/indoor_center ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] common_center_3f"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/common_center_3f ./tiles/common_center_3f ./tiles/indoor_center ./include/constants/metatile_behaviors.h
