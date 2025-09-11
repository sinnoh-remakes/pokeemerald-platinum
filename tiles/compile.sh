#!/bin/bash

echo "Compiling [PRIMARY] outdoor_oreburgh"
porytiles compile-primary -Wall -o ./data/tilesets/primary/outdoor_oreburgh ./tiles/outdoor_oreburgh ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] oreburgh"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/oreburgh ./tiles/oreburgh ./tiles/outdoor_oreburgh ./include/constants/metatile_behaviors.h
