#!/bin/bash

echo "Compiling [PRIMARY] indoor_sunyshore"
porytiles compile-primary -Wall -o ./data/tilesets/primary/indoor_sunyshore ./tiles/indoor_sunyshore ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] sunyshore_house"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/sunyshore_house ./tiles/sunyshore_house ./tiles/indoor_sunyshore ./include/constants/metatile_behaviors.h
