#!/bin/bash

echo "Compiling [PRIMARY] cave_coronet"
porytiles compile-primary -Wall -o ./data/tilesets/primary/cave_coronet ./tiles/cave_coronet ./include/constants/metatile_behaviors.h
