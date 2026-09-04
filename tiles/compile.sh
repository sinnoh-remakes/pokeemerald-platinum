#!/bin/bash

echo "Compiling [PRIMARY] outdoor_eterna"
porytiles compile-primary -Wall -o ./data/tilesets/primary/outdoor_eterna ./tiles/outdoor_eterna ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] eterna"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/eterna ./tiles/eterna ./tiles/outdoor_eterna ./include/constants/metatile_behaviors.h
