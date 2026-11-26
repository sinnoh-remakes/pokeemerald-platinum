# Sinnoh Region Map & Fly Workflow

How to link new maps to the Sinnoh Region Map, register locations before their playable maps exist, and enable Fly destinations as towns are completed.

## Architecture & Why Kanto Sections Were Excluded (8-bit `u8` Limit)

Region Map locations, Fly destinations, and playable map warps are kept separate:
- **Region Map location:** An entry in `src/data/region_map/region_map_sections.json` (plus cells in `src/data/region_map/region_map_layout.h` for overworld areas). Safe to register before the playable map exists.
- **Fly destination:** An entry in `sFlyLocations` and `GetMapsecType()` (`src/region_map.c`) gated by a `FLAG_VISITED_*` flag.
- **Map warp:** A valid target map and `HEAL_LOCATION_*` in `src/data/heal_locations.json` and `sMapHealLocations`.

Per `include/gametypes.h`, `mapsec_u8_t` / `metloc_u8_t` is canonically **8-bit** (`0`–`252`, with `0xFD`–`0xFF` reserved for `METLOC_SPECIAL_EGG`, `METLOC_IN_GAME_TRADE`, and `METLOC_FATEFUL_ENCOUNTER`).

Widening `mapsec_u8_t` to `u16` was intentionally avoided:
1. Met locations are stored inside `BoxPokemon` and save-block structs, which are packed to fit GBA Flash save limits—changing `u8` to `u16` breaks save-struct layout and existing `.sav` compatibility.
2. Any call site still expecting `metloc_u8_t` or `mapsec_u8_t` would silently truncate IDs `>= 253` (`id % 256`), corrupting caught-location names.
3. The `0xFD`–`0xFF` sentinel checks are hardcoded for 8-bit values across egg, trade, and summary-screen logic.

Instead, we dropped the 103 Kanto/Sevii-only sections from `region_map_sections.json` (moving `MAPSEC_POKEMON_LEAGUE` and `MAPSEC_POKEMON_MANSION` to Sinnoh and guarding FRLG-only C code behind `#if IS_FRLG`). That keeps the total `MAPSEC_COUNT` well under `253` while leaving ~55 free 8-bit slots for new Sinnoh locations.

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
