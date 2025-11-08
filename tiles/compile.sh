#!/bin/bash

echo "Compiling [secondary] ravaged_path"
porytiles compile-secondary -Wall -o ./data/tilesets/secondary/ravaged_path ./tiles/ravaged_path ./tiles/cave_coronet ./include/constants/metatile_behaviors.h
