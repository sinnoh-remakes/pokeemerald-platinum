#!/bin/bash

echo "Compiling [PRIMARY] indoor_twinleaf"
porytiles compile-primary -tiles-primary-override=384 -Wall -o ./data/tilesets/primary/indoor_twinleaf ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] eterna_indoor"
porytiles compile-secondary -tiles-primary-override=384 -Wall -o ./data/tilesets/secondary/eterna_indoor ./tiles/eterna_indoor ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h
