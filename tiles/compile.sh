#!/bin/bash

echo "Compiling [PRIMARY] indoor_windworks"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_windworks ./tiles/indoor_windworks ./include/constants/metatile_behaviors.h
