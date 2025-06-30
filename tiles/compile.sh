#!/bin/bash

echo "Compiling [PRIMARY] outdoor_jubilife"
porytiles compile-primary -Wall -o ./data/tilesets/primary/outdoor_jubilife ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] jubilife"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/jubilife ./tiles/jubilife ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
