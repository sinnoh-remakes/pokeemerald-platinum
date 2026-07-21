#!/bin/bash

echo "Compiling [secondary] route_205_south"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/route_205_south ./tiles/route_205_south ./tiles/outdoor_route_205 ./include/constants/metatile_behaviors.h
