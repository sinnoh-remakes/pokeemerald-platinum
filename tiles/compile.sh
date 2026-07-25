#!/bin/bash

echo "Compiling [PRIMARY] outdoor_route_205"
porytiles compile-primary -Wall -o ./data/tilesets/primary/outdoor_route_205 ./tiles/outdoor_route_205 ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] route_205_south_1"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/route_205_south_1 ./tiles/route_205_south_1 ./tiles/outdoor_route_205 ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] route_205_south_2"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/route_205_south_2 ./tiles/route_205_south_2 ./tiles/outdoor_route_205 ./include/constants/metatile_behaviors.h
