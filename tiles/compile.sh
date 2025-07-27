#!/bin/bash

echo "Compiling [secondary] jubilife"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/jubilife ./tiles/jubilife ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] route_203"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/route_203 ./tiles/route_203 ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] route_204"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/route_204 ./tiles/route_204 ./tiles/outdoor_jubilife ./include/constants/metatile_behaviors.h
