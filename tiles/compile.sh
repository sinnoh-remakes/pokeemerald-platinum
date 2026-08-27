#!/bin/bash

echo "Compiling [PRIMARY] outdoor_eterna"
porytiles compile-primary -Wall -o ./data/tilesets/primary/outdoor_eterna ./tiles/outdoor_eterna ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] route_205_north"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/route_205_north ./tiles/route_205_north ./tiles/outdoor_eterna ./include/constants/metatile_behaviors.h

echo "Compiling [PRIMARY] indoor_jubilife"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_jubilife ./tiles/indoor_jubilife ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] jubilife_gts"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/jubilife_gts ./tiles/jubilife_gts ./tiles/indoor_jubilife ./include/constants/metatile_behaviors.h
