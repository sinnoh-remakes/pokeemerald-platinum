#!/bin/bash

echo "Compiling [PRIMARY] indoor_twinleaf"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_twinleaf ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] twinleaf_player"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/twinleaf_player ./tiles/twinleaf_player ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] twinleaf_living"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/twinleaf_living ./tiles/twinleaf_living ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] twinleaf_other"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/twinleaf_other ./tiles/twinleaf_other ./tiles/indoor_twinleaf ./include/constants/metatile_behaviors.h

echo "Compiling [PRIMARY] indoor_twinleaf_rival"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_twinleaf_rival ./tiles/indoor_twinleaf_rival ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] twinleaf_rival"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/twinleaf_rival ./tiles/twinleaf_rival ./tiles/indoor_twinleaf_rival ./include/constants/metatile_behaviors.h

echo "Compiling [PRIMARY] indoor_sandgem_lab"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_sandgem_lab ./tiles/indoor_sandgem_lab ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] sandgem_lab"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/sandgem_lab ./tiles/sandgem_lab ./tiles/indoor_sandgem_lab ./include/constants/metatile_behaviors.h
