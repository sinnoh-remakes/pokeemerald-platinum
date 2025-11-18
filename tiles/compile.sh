#!/bin/bash

echo "Compiling [PRIMARY] indoor_mart"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_mart ./tiles/indoor_mart ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] common_mart"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/common_mart ./tiles/common_mart ./tiles/indoor_mart ./include/constants/metatile_behaviors.h
