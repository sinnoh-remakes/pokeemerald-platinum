#!/bin/bash

echo "Compiling [PRIMARY] indoor_windworks"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_windworks ./tiles/indoor_windworks ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] valley_windworks_indoor"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/valley_windworks_indoor ./tiles/valley_windworks_indoor ./tiles/indoor_windworks ./include/constants/metatile_behaviors.h
