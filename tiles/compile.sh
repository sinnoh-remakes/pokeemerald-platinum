#!/bin/bash

echo "Compiling [PRIMARY] gym_eterna"
porytiles compile-primary -tiles-primary-override=384 -Wall -o ./data/tilesets/primary/gym_eterna ./tiles/gym_eterna ./include/constants/metatile_behaviors.h
# echo "Compiling [secondary] eterna_gym"
# porytiles compile-secondary -tiles-primary-override=384 -Wall -o ./data/tilesets/secondary/eterna_gym ./tiles/eterna_gym ./tiles/gym_eterna ./include/constants/metatile_behaviors.h
