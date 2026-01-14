#!/bin/bash

echo "Compiling [PRIMARY] indoor_jubilife"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_jubilife ./tiles/indoor_jubilife ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] jubilife_school"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/jubilife_school ./tiles/jubilife_school ./tiles/indoor_jubilife ./include/constants/metatile_behaviors.h
