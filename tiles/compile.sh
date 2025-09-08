#!/bin/bash

echo "Compiling [secondary] jubilife"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/jubilife ./tiles/jubilife ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "Compiling [PRIMARY] cave_coronet"
porytiles compile-primary -Wall -o ./data/tilesets/primary/cave_coronet ./tiles/cave_coronet ./include/constants/metatile_behaviors.h
