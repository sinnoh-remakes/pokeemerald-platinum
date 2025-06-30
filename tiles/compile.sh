#!/bin/bash

echo "Compiling [secondary] twinleaf"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/twinleaf ./tiles/twinleaf ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] sandgem"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/sandgem ./tiles/sandgem ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] jubilife"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/jubilife ./tiles/jubilife ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
