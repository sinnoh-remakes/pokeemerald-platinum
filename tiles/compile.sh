#!/bin/bash

echo "Compiling [PRIMARY] cave_coronet_north"
porytiles compile-primary -tiles-primary-override=384 -Wall -o ./data/tilesets/primary/cave_coronet_north ./tiles/cave_coronet_north ./include/constants/metatile_behaviors.h
