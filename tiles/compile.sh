#!/bin/bash

echo "Compiling [PRIMARY] outdoor_eterna"
porytiles compile-primary -Wall -o ./data/tilesets/primary/outdoor_eterna ./tiles/outdoor_eterna ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] eterna_north"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/eterna_north ./tiles/eterna_north ./tiles/outdoor_eterna ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] eterna_south"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/eterna_south ./tiles/eterna_south ./tiles/outdoor_eterna ./include/constants/metatile_behaviors.h
