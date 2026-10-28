#!/bin/bash

echo "Compiling [PRIMARY] indoor_galactic_space"
porytiles compile-primary -tiles-primary-override=384 -Wall -o ./data/tilesets/primary/indoor_galactic_space ./tiles/indoor_galactic_space ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] galactic_space_indoor"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/galactic_space_indoor ./tiles/galactic_space_indoor ./tiles/indoor_galactic_space ./include/constants/metatile_behaviors.h
