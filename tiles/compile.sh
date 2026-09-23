#!/bin/bash

echo "Compiling [secondary] jubilife_tower"
porytiles compile-secondary -tiles-primary-override=384 -Wall -o ./data/tilesets/secondary/jubilife_tower ./tiles/jubilife_tower ./tiles/indoor_jubilife ./include/constants/metatile_behaviors.h
