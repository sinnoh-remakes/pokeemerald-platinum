#!/bin/bash

echo "Compiling [PRIMARY] outdoor_oreburgh"
porytiles compile-primary -Wall -o ./data/tilesets/primary/outdoor_oreburgh ./tiles/outdoor_oreburgh ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] route_207"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/route_207 ./tiles/route_207 ./tiles/outdoor_oreburgh ./include/constants/metatile_behaviors.h
