#!/bin/bash

echo "Compiling [PRIMARY] gym_oreburgh"
porytiles compile-primary -Wall -o ./data/tilesets/primary/gym_oreburgh ./tiles/gym_oreburgh ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] oreburgh_gym"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/oreburgh_gym ./tiles/oreburgh_gym ./tiles/gym_oreburgh ./include/constants/metatile_behaviors.h
