#!/bin/bash

echo "Compiling [PRIMARY] indoor_forest"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_forest ./tiles/indoor_forest ./include/constants/metatile_behaviors.h
