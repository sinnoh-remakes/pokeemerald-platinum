#!/bin/bash

echo "Compiling [PRIMARY] indoor_twinleaf"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_twinleaf ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] sandgem_living"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/sandgem_living ./tiles/sandgem_living ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] sandgem_helper"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/sandgem_helper ./tiles/sandgem_helper ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h
