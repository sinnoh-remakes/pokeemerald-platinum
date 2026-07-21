#!/bin/bash

echo "Compiling [PRIMARY] outdoor_route_205"
porytiles compile-primary -Wall -o ./data/tilesets/primary/outdoor_route_205 ./tiles/outdoor_route_205 ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] route_205_south"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/route_205_south ./tiles/route_205_south ./tiles/outdoor_route_205 ./include/constants/metatile_behaviors.h
