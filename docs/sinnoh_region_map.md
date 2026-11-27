# Sinnoh Region Map & Fly Workflow

How to link new maps to the Sinnoh Region Map, register locations before their playable maps exist, and enable Fly destinations as towns are completed.

## Architecture & Region Section ID Capacity

Region Map locations, Fly destinations, and playable map warps are kept separate:
- **Region Map location:** An entry in `src/data/region_map/region_map_sections.json` (plus cells in `src/data/region_map/region_map_layout.h` for overworld areas). Safe to register before the playable map exists.
- **Fly destination:** An entry in `sFlyLocations` and `GetMapsecType()` (`src/region_map.c`) gated by a `FLAG_VISITED_*` flag.
- **Map warp:** A valid target map and `HEAL_LOCATION_*` in `src/data/heal_locations.json` and `sMapHealLocations`.

Per `include/gametypes.h`, `mapsec_u8_t` / `metloc_u8_t` currently use an 8-bit representation. Values `0xFD`–`0xFF` are reserved for `METLOC_SPECIAL_EGG`, `METLOC_IN_GAME_TRADE`, and `METLOC_FATEFUL_ENCOUNTER`.

This is an existing implementation constraint, not an insurmountable save-compatibility restriction. Widening map-section IDs is possible, but it requires coordinated changes:

1. A Pokémon's met location is stored as a byte in `PokemonSubstruct3`, which is part of the `secure` union in `BoxPokemon`. The union reserves space for four equally sized substructures, so increasing the size of `PokemonSubstruct3` can increase the stored data for every boxed or party Pokémon.
2. Map-section IDs are also used by map headers, warp state, Pokenav and TV data, and functions that currently accept `mapsec_u8_t`. Those fields and call sites would need to be audited and widened to prevent truncation.
3. The `0xFD`–`0xFF` met-location sentinel values are part of the current 8-bit representation and would need deliberate handling in a wider format.

Existing saves could be supported with a versioned migration. Since the project is still under development, adopting a new save format or requiring a fresh save could also be considered. Save compatibility is therefore a migration cost, not a technical impossibility.

For this PR, the decision is to retain the current 8-bit representation and keep the change scoped to the existing data model. The 103 Kanto/Sevii-only sections were removed from `region_map_sections.json` to make room for Sinnoh locations; `MAPSEC_POKEMON_LEAGUE` and `MAPSEC_POKEMON_MANSION` were moved to Sinnoh, and FRLG-only C code remains guarded behind `#if IS_FRLG`. Widening the ID format can be reconsidered if the project needs to retain those sections or exceeds the available 8-bit capacity.

*(Note: Do not hand-edit `include/constants/region_map_sections.h` or `src/data/region_map/region_map_entries.h`; both are generated from `region_map_sections.json` during `make`.)*

---

## 1. Linking a New Map to an Existing Location

Most Sinnoh towns, routes, lakes, caves, and landmarks are already registered. In `data/maps/<MapName>/map.json`:

1. Set `"region": "REGION_SINNOH"` (accepted alongside `REGION_HOENN` by `tools/mapjson/mapjson.cpp`).
2. Set `"region_map_section": "MAPSEC_<NAME>"` (for example, `"MAPSEC_HEARTHOME_CITY"`).
3. Run `make -j4`.

No C edits are needed; cursor placement and the player head icon will resolve automatically.

---

## 2. Registering a New Region Map Location (Before or After Mapping)

1. Add an entry to `src/data/region_map/region_map_sections.json` (keep Sinnoh entries grouped before `MAPSEC_LITTLEROOT_TOWN`):
```json
   {
     "id": "MAPSEC_MY_NEW_AREA",
     "name": "MY NEW AREA",
     "x": 10,
     "y": 5,
     "width": 1,
     "height": 1
   }
```
   - Coordinates use the 28x15 map grid (`x`: `0..27`, `y`: `0..14`).
   - Interior/sub-areas (e.g. `MAPSEC_SPEAR_PILLAR`, `MAPSEC_OLD_CHATEAU`) share the parent location's `(x, y)` and do not need cells in `region_map_layout.h`.
2. For overworld areas, assign `MAPSEC_MY_NEW_AREA` to the matching `(y, x)` cell(s) in `src/data/region_map/region_map_layout.h`.
3. For towns/cities not yet flyable, add `case MAPSEC_MY_NEW_AREA:` returning `MAPSECTYPE_CITY_CANTFLY` in `GetMapsecType()` (`src/region_map.c`).
4. Run `make -j4` and verify `MAPSEC_COUNT` in `include/constants/region_map_sections.h` remains `< 253`.

---

## 3. Enabling Fly for a Completed Town or City

Only wire a location for Fly once its outdoor map, Pokémon Center / heal spot, and visited flag exist (never add dummy warps):

1. **Visited flag (`include/constants/flags.h` + `data/maps/<City>/scripts.inc`):**
   - Define `FLAG_VISITED_<CITY>` if missing, and add `setflag FLAG_VISITED_<CITY>` to the city's `MAP_SCRIPT_ON_TRANSITION` script.
2. **Heal location (`src/data/heal_locations.json`):**
   - Add `HEAL_LOCATION_<CITY>` pointing to the target map/respawn coordinates.
3. **Region Map tables (`src/region_map.c`):**
   - Add `[MAPSEC_<CITY>] = {MAP_GROUP(MAP_<CITY>), MAP_NUM(MAP_<CITY>), HEAL_LOCATION_<CITY>},` to `sMapHealLocations`.
   - Update `GetMapsecType()` to check `FlagGet(FLAG_VISITED_<CITY>) ? MAPSECTYPE_CITY_CANFLY : MAPSECTYPE_CITY_CANTFLY`.
   - Add an entry to `sFlyLocations` using `.regionMapType = REGION_MAP_HOENN` (the Sinnoh slot):
```c
     {
         .regionMapType = REGION_MAP_HOENN,
         .mapsec = MAPSEC_<CITY>,
         .flag = FLAG_VISITED_<CITY>,
     },
```
4. **Debug Menu (`src/debug.c`):**
   - Add `FLAG_VISITED_<CITY>` to `sLocationFlags[]` so **Toggle Fly Flags** can unlock it during testing.
5. Run `make -j4` and verify the Fly icon and warp destination in-game.
