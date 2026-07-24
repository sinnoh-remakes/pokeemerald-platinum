echo "Compiling [PRIMARY] outdoor_route_204"
porytiles compile-primary -Wall -o ./data/tilesets/primary/outdoor_route_204 ./tiles/outdoor_route_204 ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] route_204_north"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/route_204_north ./tiles/route_204_north ./tiles/outdoor_route_204 ./include/constants/metatile_behaviors.h
