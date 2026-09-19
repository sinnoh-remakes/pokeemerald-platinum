#!/bin/bash

echo "Compiling [PRIMARY] cave_coronet_south"
porytiles compile-primary -tiles-primary-override=384 -Wall -o ./data/tilesets/primary/cave_coronet_south ./tiles/cave_coronet_south ./include/constants/metatile_behaviors.h
echo "Compiling [secondary] ravaged_path"
porytiles compile-secondary -tiles-primary-override=384 -Wall -o ./data/tilesets/secondary/ravaged_path ./tiles/ravaged_path ./tiles/cave_coronet_south ./include/constants/metatile_behaviors.h
