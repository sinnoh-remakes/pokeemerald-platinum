#!/bin/bash

echo "Compiling [PRIMARY] outdoor_floaroma"
porytiles compile-primary -Wall -o ./data/tilesets/primary/outdoor_floaroma ./tiles/outdoor_floaroma ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] floaroma"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/floaroma ./tiles/floaroma ./tiles/outdoor_floaroma ./include/constants/metatile_behaviors.h
