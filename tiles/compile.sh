#!/bin/bash

echo "Compiling [PRIMARY] indoor_jubilife"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_jubilife ./tiles/indoor_jubilife ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] jubilife_tower"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/jubilife_tower ./tiles/jubilife_tower ./tiles/indoor_jubilife ./include/constants/metatile_behaviors.h
