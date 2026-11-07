#!/bin/bash

echo "Compiling [PRIMARY] outdoor_route_206"
porytiles compile-primary -Wall -o ./data/tilesets/primary/outdoor_route_206 ./tiles/outdoor_route_206 ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] route_206"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/route_206 ./tiles/route_206 ./tiles/outdoor_route_206 ./include/constants/metatile_behaviors.h
