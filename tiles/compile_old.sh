#!/bin/bash

echo "Compiling [PRIMARY] outdoor_route_201"
porytiles compile-primary -Wall -o ./data/tilesets/primary/outdoor_route_201 ./tiles/outdoor_route_201 ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] twinleaf"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/twinleaf ./tiles/twinleaf ./tiles/outdoor_route_201 ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] route_201"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/route_201 ./tiles/route_201 ./tiles/outdoor_route_201 ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] lake"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/lake ./tiles/lake ./tiles/outdoor_route_201 ./include/constants/metatile_behaviors.h

echo "Compiling [PRIMARY] outdoor_sandgem"
porytiles compile-primary -Wall -o ./data/tilesets/primary/outdoor_sandgem ./tiles/outdoor_sandgem ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] sandgem"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/sandgem ./tiles/sandgem ./tiles/outdoor_sandgem ./include/constants/metatile_behaviors.h
echo "Compiling [PRIMARY] outdoor_jubilife"
porytiles compile-primary -Wall -o ./data/tilesets/primary/outdoor_jubilife ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
