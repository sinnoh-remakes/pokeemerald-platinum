#!/bin/bash

echo "Compiling [secondary] route_211_west"
porytiles compile-secondary -tiles-primary-override=384 -Wall -o ./data/tilesets/secondary/route_211_west ./tiles/route_211_west ./tiles/outdoor_eterna ./include/constants/metatile_behaviors.h
