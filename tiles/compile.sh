#!/bin/bash

echo "Compiling [PRIMARY] outdoor_route_206"
porytiles compile-primary -Wall -o ./data/tilesets/primary/outdoor_route_206 ./tiles/outdoor_route_206 ./include/constants/metatile_behaviors.h
# echo "Compiling [secondary] route_206_south_1"
# porytiles compile-secondary -Wall -o ./data/tilesets/secondary/route_206_south_1 ./tiles/route_206_south_1 ./tiles/outdoor_route_206 ./include/constants/metatile_behaviors.h
# echo "Compiling [secondary] route_206_south_2"
# porytiles compile-secondary -Wall -o ./data/tilesets/secondary/route_206_south_2 ./tiles/route_206_south_2 ./tiles/outdoor_route_206 ./include/constants/metatile_behaviors.h
