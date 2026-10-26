#!/bin/bash

echo "Compiling [PRIMARY] indoor_galactic_eterna"
porytiles compile-primary -tiles-primary-override=384 -Wall -o ./data/tilesets/primary/indoor_galactic_eterna ./tiles/indoor_galactic_eterna ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] galactic_eterna_indoor"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/galactic_eterna_indoor ./tiles/galactic_eterna_indoor ./tiles/indoor_galactic_eterna ./include/constants/metatile_behaviors.h
