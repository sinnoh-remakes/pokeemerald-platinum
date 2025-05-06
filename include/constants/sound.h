#ifndef GUARD_CONSTANTS_SOUND_H
#define GUARD_CONSTANTS_SOUND_H

#define FANFARE_LEVEL_UP                 0
#define FANFARE_HEAL                     1
#define FANFARE_OBTAIN_BADGE             2
#define FANFARE_OBTAIN_ITEM              3
#define FANFARE_EVOLVED                  4
#define FANFARE_OBTAIN_TMHM              5
#define FANFARE_EVOLUTION_INTRO          6
#define FANFARE_MOVE_DELETED             7
#define FANFARE_OBTAIN_BERRY             8
#define FANFARE_AWAKEN_LEGEND            9
#define FANFARE_SLOTS_JACKPOT            10
#define FANFARE_SLOTS_WIN                11
#define FANFARE_TOO_BAD                  12
#define FANFARE_RG_JIGGLYPUFF            13
#define FANFARE_RG_DEX_RATING            14
#define FANFARE_RG_OBTAIN_KEY_ITEM       15
#define FANFARE_RG_CAUGHT_INTRO          16
#define FANFARE_RG_PHOTO                 17
#define FANFARE_RG_POKE_FLUTE            18
#define FANFARE_OBTAIN_B_POINTS          19
#define FANFARE_REGISTER_MATCH_CALL      20
#define FANFARE_OBTAIN_SYMBOL            21
#define FANFARE_DP_TV_END                22
#define FANFARE_DP_OBTAIN_ITEM           23
#define FANFARE_DP_HEAL                  24
#define FANFARE_DP_OBTAIN_KEY_ITEM       25
#define FANFARE_DP_OBTAIN_TMHM           26
#define FANFARE_DP_OBTAIN_BADGE          27
#define FANFARE_DP_LEVEL_UP              28
#define FANFARE_DP_OBTAIN_BERRY          29
#define FANFARE_DP_PARTNER               30
#define FANFARE_DP_EVOLVED               31
#define FANFARE_DP_POKETCH               32
#define FANFARE_DP_MOVE_DELETED          33
#define FANFARE_DP_ACCESSORY             34
#define FANFARE_PL_TV_END                35
#define FANFARE_PL_CLEAR_MINIGAME        36
#define FANFARE_PL_OBTAIN_ARCADE_POINTS  37
#define FANFARE_PL_OBTAIN_CASTLE_POINTS  38
#define FANFARE_PL_OBTAIN_B_POINTS       39

#define CRY_MODE_NORMAL        0 // Default
#define CRY_MODE_DOUBLES       1 // Shortened cry for double battles
#define CRY_MODE_ENCOUNTER     2 // Used when starting a static encounter, or when a Pokémon is "aggressive"
#define CRY_MODE_HIGH_PITCH    3 // Highest pitch mode, used exclusively by the move Howl
#define CRY_MODE_ECHO_START    4 // For 1st half of cry used by the move Hyper Voice. Played in reverse
#define CRY_MODE_FAINT         5 // Used when a Pokémon faints
#define CRY_MODE_ECHO_END      6 // For 2nd half of cry used by the move Hyper Voice
#define CRY_MODE_ROAR_1        7 // For 1st cry used by the move Roar
#define CRY_MODE_ROAR_2        8 // For 2nd cry used by the move Roar
#define CRY_MODE_GROWL_1       9 // For 1st cry used by the move Growl. Played in reverse
#define CRY_MODE_GROWL_2      10 // For 2nd cry used by the move Growl
#define CRY_MODE_WEAK         11 // Used when a Pokémon is unhealthy
#define CRY_MODE_WEAK_DOUBLES 12 // Equivalent to CRY_MODE_DOUBLES for CRY_MODE_WEAK

// Given to SoundTask_PlayDoubleCry to determine which cry mode to use. Values are arbitrary
#define DOUBLE_CRY_ROAR  2
#define DOUBLE_CRY_GROWL 255

#define CRY_PRIORITY_NORMAL 10
#define CRY_PRIORITY_AMBIENT 1

// Cry volume was changed from 125 in R/S to 120 for FRLG/Em, but was (accidentally?) not updated outside of sound.c
#define CRY_VOLUME    120
#define CRY_VOLUME_RS 125

#endif // GUARD_CONSTANTS_SOUND_H
