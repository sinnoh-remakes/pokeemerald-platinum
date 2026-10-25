#!/bin/bash

echo "Compiling [PRIMARY] indoor_cycle_shop"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_cycle_shop ./tiles/indoor_cycle_shop ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] cycle_shop"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/cycle_shop ./tiles/cycle_shop ./tiles/indoor_cycle_shop ./include/constants/metatile_behaviors.h
