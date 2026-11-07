#ifndef GUARD_CONSTANTS_EVENT_OBJECTS_H
#define GUARD_CONSTANTS_EVENT_OBJECTS_H

#include "constants/global.h"
#include "constants/map_event_ids.h"

#define PLAYER_AVATAR_GFX_MALE_NORMAL       OBJ_EVENT_GFX_LUCAS_NORMAL
#define PLAYER_AVATAR_GFX_MALE_MACH_BIKE    OBJ_EVENT_GFX_LUCAS_BIKE
#define PLAYER_AVATAR_GFX_MALE_ACRO_BIKE    OBJ_EVENT_GFX_LUCAS_BIKE
#define PLAYER_AVATAR_GFX_MALE_SURFING      OBJ_EVENT_GFX_LUCAS_NORMAL
#define PLAYER_AVATAR_GFX_MALE_UNDERWATER   OBJ_EVENT_GFX_LUCAS_NORMAL
#define PLAYER_AVATAR_GFX_MALE_FIELD_MOVE   OBJ_EVENT_GFX_LUCAS_FIELD_MOVE
#define PLAYER_AVATAR_GFX_MALE_FISHING      OBJ_EVENT_GFX_LUCAS_FISHING
#define PLAYER_AVATAR_GFX_MALE_WATERING     OBJ_EVENT_GFX_LUCAS_WATERING
#define PLAYER_AVATAR_GFX_MALE_VSSEEKER     OBJ_EVENT_GFX_LUCAS_NORMAL
#define PLAYER_AVATAR_GFX_FEMALE_NORMAL     OBJ_EVENT_GFX_DAWN_NORMAL
#define PLAYER_AVATAR_GFX_FEMALE_MACH_BIKE  OBJ_EVENT_GFX_DAWN_BIKE
#define PLAYER_AVATAR_GFX_FEMALE_ACRO_BIKE  OBJ_EVENT_GFX_DAWN_BIKE
#define PLAYER_AVATAR_GFX_FEMALE_SURFING    OBJ_EVENT_GFX_DAWN_NORMAL
#define PLAYER_AVATAR_GFX_FEMALE_UNDERWATER OBJ_EVENT_GFX_DAWN_NORMAL
#define PLAYER_AVATAR_GFX_FEMALE_FIELD_MOVE OBJ_EVENT_GFX_DAWN_FIELD_MOVE
#define PLAYER_AVATAR_GFX_FEMALE_FISHING    OBJ_EVENT_GFX_DAWN_FISHING
#define PLAYER_AVATAR_GFX_FEMALE_WATERING   OBJ_EVENT_GFX_DAWN_WATERING
#define PLAYER_AVATAR_GFX_FEMALE_VSSEEKER   OBJ_EVENT_GFX_DAWN_NORMAL

#define OBJ_EVENT_GFX_BRIEFCASE_PT               376
#define OBJ_EVENT_GFX_BREAKABLE_ROCK_PT          377
#define OBJ_EVENT_GFX_CUTTABLE_TREE_PT           378
#define OBJ_EVENT_GFX_PUSHABLE_BOULDER_PT        379
#define OBJ_EVENT_GFX_BIKE_RACK_PT               380
#define OBJ_EVENT_GFX_BIKE_DISPLAY_PT            381
#define OBJ_EVENT_GFX_WIND_TURBINE_BASE          382
#define OBJ_EVENT_GFX_WIND_TURBINE_BLADES_1      383
#define OBJ_EVENT_GFX_WIND_TURBINE_BLADES_2      384
#define OBJ_EVENT_GFX_BURIED_TRAINER_BROWN_PT    385
#define OBJ_EVENT_GFX_BURIED_TRAINER_GREEN_PT    386
#define OBJ_EVENT_GFX_BURIED_TRAINER_WHITE_PT    387
#define OBJ_EVENT_GFX_BURIED_TRAINER_GRAY_PT     388

// NOTE: The maximum amount of object events has been expanded from 255 to 65535.
// Since dynamic graphics ids still require at least 16 free values, the actual limit
// is 65519, but even considering follower Pokémon, this should be more than enough :)
#define NUM_OBJ_EVENT_GFX                        389


// These are dynamic object gfx ids.
// They correspond with the values of the VAR_OBJ_GFX_ID_X vars.
// More info about them in include/constants/vars.h
#define OBJ_EVENT_GFX_VARS   (NUM_OBJ_EVENT_GFX + 1)
#define OBJ_EVENT_GFX_VAR_0  (OBJ_EVENT_GFX_VARS + 0x0)
#define OBJ_EVENT_GFX_VAR_1  (OBJ_EVENT_GFX_VARS + 0x1)
#define OBJ_EVENT_GFX_VAR_2  (OBJ_EVENT_GFX_VARS + 0x2)
#define OBJ_EVENT_GFX_VAR_3  (OBJ_EVENT_GFX_VARS + 0x3)
#define OBJ_EVENT_GFX_VAR_4  (OBJ_EVENT_GFX_VARS + 0x4)
#define OBJ_EVENT_GFX_VAR_5  (OBJ_EVENT_GFX_VARS + 0x5)
#define OBJ_EVENT_GFX_VAR_6  (OBJ_EVENT_GFX_VARS + 0x6)
#define OBJ_EVENT_GFX_VAR_7  (OBJ_EVENT_GFX_VARS + 0x7)
#define OBJ_EVENT_GFX_VAR_8  (OBJ_EVENT_GFX_VARS + 0x8)
#define OBJ_EVENT_GFX_VAR_9  (OBJ_EVENT_GFX_VARS + 0x9)
#define OBJ_EVENT_GFX_VAR_A  (OBJ_EVENT_GFX_VARS + 0xA)
#define OBJ_EVENT_GFX_VAR_B  (OBJ_EVENT_GFX_VARS + 0xB)
#define OBJ_EVENT_GFX_VAR_C  (OBJ_EVENT_GFX_VARS + 0xC)
#define OBJ_EVENT_GFX_VAR_D  (OBJ_EVENT_GFX_VARS + 0xD)
#define OBJ_EVENT_GFX_VAR_E  (OBJ_EVENT_GFX_VARS + 0xE)
#define OBJ_EVENT_GFX_VAR_F  (OBJ_EVENT_GFX_VARS + 0xF)

// Don't use (1u << 15) to avoid conflict with BLEND_IMMUNE_FLAG.
#define OBJ_EVENT_MON               (1u << 14)
#define OBJ_EVENT_MON_SHINY         (1u << 13)
#define OBJ_EVENT_MON_FEMALE        (1u << 12)
#define OBJ_EVENT_MON_SPECIES_MASK  (~(7u << 12))

// Used to call a specific species' follower graphics. Useful for static encounters.
#define OBJ_EVENT_GFX_SPECIES(name)                 (SPECIES_##name + OBJ_EVENT_MON)
#define OBJ_EVENT_GFX_SPECIES_SHINY(name)           (SPECIES_##name + OBJ_EVENT_MON + OBJ_EVENT_MON_SHINY)
#define OBJ_EVENT_GFX_SPECIES_FEMALE(name)          (SPECIES_##name + OBJ_EVENT_MON + OBJ_EVENT_MON_FEMALE)
#define OBJ_EVENT_GFX_SPECIES_SHINY_FEMALE(name)    (SPECIES_##name + OBJ_EVENT_MON + OBJ_EVENT_MON_SHINY + OBJ_EVENT_MON_FEMALE)

#define OW_SPECIES(x) ((x)->graphicsId & OBJ_EVENT_MON_SPECIES_MASK)
#define OW_SHINY(x) ((x)->graphicsId & OBJ_EVENT_MON_SHINY)
#define OW_FEMALE(x) ((x)->graphicsId & OBJ_EVENT_MON_FEMALE)

// Whether Object Event is an OW Pokémon
#define IS_OW_MON_OBJ(obj) ((obj)->graphicsId & OBJ_EVENT_MON)

#define SHADOW_SIZE_S       0
#define SHADOW_SIZE_M       1
#define SHADOW_SIZE_L       2
#define SHADOW_SIZE_NONE    3   // Originally SHADOW_SIZE_XL, which went unused due to shadowSize in ObjectEventGraphicsInfo being only 2 bits.

#define SHADOW_SIZE_XL_BATTLE_ONLY  SHADOW_SIZE_NONE    // Battle-only definition for XL shadow size.

#define F_INANIMATE                        (1 << 6)
#define F_DISABLE_REFLECTION_PALETTE_LOAD  (1 << 7)

#define TRACKS_NONE       0
#define TRACKS_FOOT       1
#define TRACKS_BIKE_TIRE  2
#define TRACKS_SLITHER    3
#define TRACKS_SPOT       4
#define TRACKS_BUG        5

#define LIGHT_TYPE_BALL             0
#define LIGHT_TYPE_PKMN_CENTER_SIGN 1
#define LIGHT_TYPE_POKE_MART_SIGN   2

#define FIRST_DECORATION_SPRITE_GFX OBJ_EVENT_GFX_PICHU_DOLL

#define OBJ_KIND_NORMAL 0
#define OBJ_KIND_CLONE  255 // Exclusive to FRLG


// Each object event template gets an ID that can be used to refer to it in scripts and elsewhere.
// This is referred to as the "local id" (and it's really just 1 + its index in the templates array).
// There are a few special IDs reserved for objects that don't have templates in the map data -- one for the player
// in regular offline play, five for linked players while playing Berry Blender, and one for an invisible object that
// can be spawned for the camera to track instead of the player. Additionally, the value 0 is reserved as an "empty" indicator.
#define LOCALID_NONE                              0
#define LOCALID_CAMERA                          127
#define LOCALID_BERRY_BLENDER_PLAYER_END        240 // This will use 5 (MAX_RFU_PLAYERS) IDs ending at 240, i.e. 236-240
#define LOCALID_OW_ENCOUNTER_END                252 // This will use 4 (OWE_SPAWNS_MAX) IDs ending at 252, i.e. 249-252
#define LOCALID_FOLLOWING_POKEMON               254
#define LOCALID_PLAYER                          255
#define OBJ_EVENT_ID_FOLLOWER                   0xFE
#define OBJ_EVENT_ID_NPC_FOLLOWER               0xFD

#define IS_LOCALID_GENERATED_OWE(localId)       (localId <= LOCALID_OW_ENCOUNTER_END \
                                                 && localId > (LOCALID_OW_ENCOUNTER_END - OWE_SPAWNS_MAX))

// Aliases for old names. "object event id" normally refers to an index into gObjectEvents, which these are not.
// Used for link player OWs in CreateLinkPlayerSprite
#define OBJ_EVENT_ID_CAMERA LOCALID_CAMERA
#define OBJ_EVENT_ID_PLAYER LOCALID_PLAYER
#define OBJ_EVENT_ID_DYNAMIC_BASE 0xF0

// Moved from src/event_object_movement.c so that they're accesible from other files.
#define OBJ_EVENT_PAL_TAG_BRENDAN                 0x1100
#define OBJ_EVENT_PAL_TAG_BRENDAN_REFLECTION      0x1101
#define OBJ_EVENT_PAL_TAG_BRIDGE_REFLECTION       0x1102
#define OBJ_EVENT_PAL_TAG_NPC_1                   0x1103
#define OBJ_EVENT_PAL_TAG_NPC_2                   0x1104
#define OBJ_EVENT_PAL_TAG_NPC_3                   0x1105
#define OBJ_EVENT_PAL_TAG_NPC_4                   0x1106
#define OBJ_EVENT_PAL_TAG_NPC_1_REFLECTION        0x1107
#define OBJ_EVENT_PAL_TAG_NPC_2_REFLECTION        0x1108
#define OBJ_EVENT_PAL_TAG_NPC_3_REFLECTION        0x1109
#define OBJ_EVENT_PAL_TAG_NPC_4_REFLECTION        0x110A
#define OBJ_EVENT_PAL_TAG_QUINTY_PLUMP            0x110B
#define OBJ_EVENT_PAL_TAG_QUINTY_PLUMP_REFLECTION 0x110C
#define OBJ_EVENT_PAL_TAG_TRUCK                   0x110D
#define OBJ_EVENT_PAL_TAG_VIGOROTH                0x110E
#define OBJ_EVENT_PAL_TAG_ZIGZAGOON               0x110F
#define OBJ_EVENT_PAL_TAG_MAY                     0x1110
#define OBJ_EVENT_PAL_TAG_MAY_REFLECTION          0x1111
#define OBJ_EVENT_PAL_TAG_MOVING_BOX              0x1112
#define OBJ_EVENT_PAL_TAG_CABLE_CAR               0x1113
#define OBJ_EVENT_PAL_TAG_SSTIDAL                 0x1114
#define OBJ_EVENT_PAL_TAG_PLAYER_UNDERWATER       0x1115
#define OBJ_EVENT_PAL_TAG_KYOGRE                  0x1116
#define OBJ_EVENT_PAL_TAG_KYOGRE_REFLECTION       0x1117
#define OBJ_EVENT_PAL_TAG_GROUDON                 0x1118
#define OBJ_EVENT_PAL_TAG_GROUDON_REFLECTION      0x1119
#define OBJ_EVENT_PAL_TAG_UNUSED                  0x111A
#define OBJ_EVENT_PAL_TAG_SUBMARINE_SHADOW        0x111B
#define OBJ_EVENT_PAL_TAG_POOCHYENA               0x111C
#define OBJ_EVENT_PAL_TAG_RED_LEAF                0x111D
#define OBJ_EVENT_PAL_TAG_DEOXYS                  0x111E
#define OBJ_EVENT_PAL_TAG_BIRTH_ISLAND_STONE      0x111F
#define OBJ_EVENT_PAL_TAG_HO_OH                   0x1120
#define OBJ_EVENT_PAL_TAG_LUGIA                   0x1121
#define OBJ_EVENT_PAL_TAG_RS_BRENDAN              0x1122
#define OBJ_EVENT_PAL_TAG_RS_MAY                  0x1123
#define OBJ_EVENT_PAL_TAG_DYNAMIC                 0x1124
#define OBJ_EVENT_PAL_TAG_PLAYER_RED              0x1125
#define OBJ_EVENT_PAL_TAG_PLAYER_RED_REFLECTION   0x1126
#define OBJ_EVENT_PAL_TAG_PLAYER_GREEN            0x1127
#define OBJ_EVENT_PAL_TAG_PLAYER_GREEN_REFLECTION 0x1128
#define OBJ_EVENT_PAL_TAG_NPC_BLUE                0x1129
#define OBJ_EVENT_PAL_TAG_NPC_PINK                0x112A
#define OBJ_EVENT_PAL_TAG_NPC_GREEN               0x112B
#define OBJ_EVENT_PAL_TAG_NPC_WHITE               0x112C
#define OBJ_EVENT_PAL_TAG_NPC_BLUE_REFLECTION     0x112D
#define OBJ_EVENT_PAL_TAG_NPC_PINK_REFLECTION     0x112E
#define OBJ_EVENT_PAL_TAG_NPC_GREEN_REFLECTION    0x112F
#define OBJ_EVENT_PAL_TAG_NPC_WHITE_REFLECTION    0x1130
#define OBJ_EVENT_PAL_TAG_METEORITE               0x1131
#define OBJ_EVENT_PAL_TAG_SEAGALLOP               0x1132
#define OBJ_EVENT_PAL_TAG_SS_ANNE                 0x1133

#if OW_FOLLOWERS_POKEBALLS
// Vanilla
#define OBJ_EVENT_PAL_TAG_BALL_MASTER             0x1150
#define OBJ_EVENT_PAL_TAG_BALL_ULTRA              0x1151
#define OBJ_EVENT_PAL_TAG_BALL_GREAT              0x1152
#define OBJ_EVENT_PAL_TAG_BALL_SAFARI             0x1153
#define OBJ_EVENT_PAL_TAG_BALL_NET                0x1154
#define OBJ_EVENT_PAL_TAG_BALL_DIVE               0x1155
#define OBJ_EVENT_PAL_TAG_BALL_NEST               0x1156
#define OBJ_EVENT_PAL_TAG_BALL_REPEAT             0x1157
#define OBJ_EVENT_PAL_TAG_BALL_TIMER              0x1158
#define OBJ_EVENT_PAL_TAG_BALL_LUXURY             0x1159
#define OBJ_EVENT_PAL_TAG_BALL_PREMIER            0x115A
// Gen IV/Sinnoh
#define OBJ_EVENT_PAL_TAG_BALL_DUSK               0x115B
#define OBJ_EVENT_PAL_TAG_BALL_HEAL               0x115C
#define OBJ_EVENT_PAL_TAG_BALL_QUICK              0x115D
#define OBJ_EVENT_PAL_TAG_BALL_CHERISH            0x115E
#define OBJ_EVENT_PAL_TAG_BALL_PARK               0x115F
// Gen II/Johto Apricorns
#define OBJ_EVENT_PAL_TAG_BALL_FAST               0x1160
#define OBJ_EVENT_PAL_TAG_BALL_LEVEL              0x1161
#define OBJ_EVENT_PAL_TAG_BALL_LURE               0x1162
#define OBJ_EVENT_PAL_TAG_BALL_HEAVY              0x1163
#define OBJ_EVENT_PAL_TAG_BALL_LOVE               0x1164
#define OBJ_EVENT_PAL_TAG_BALL_FRIEND             0x1165
#define OBJ_EVENT_PAL_TAG_BALL_MOON               0x1166
#define OBJ_EVENT_PAL_TAG_BALL_SPORT              0x1167
// Gen V
#define OBJ_EVENT_PAL_TAG_BALL_DREAM              0x1168
// Gen VII
#define OBJ_EVENT_PAL_TAG_BALL_BEAST              0x1169
// Gen VIII
#define OBJ_EVENT_PAL_TAG_BALL_STRANGE            0x116A
#endif //OW_FOLLOWERS_POKEBALLS

#define OBJ_EVENT_PAL_TAG_LUCAS                   0x116B
#define OBJ_EVENT_PAL_TAG_LUCAS_REFLECTION        0x116C
#define OBJ_EVENT_PAL_TAG_DAWN                    0x116D
#define OBJ_EVENT_PAL_TAG_DAWN_REFLECTION         0x116E
#define OBJ_EVENT_PAL_TAG_AARON_PT                0x116F
#define OBJ_EVENT_PAL_TAG_ACE_TRAINER_COLD_F_PT   0x1170
#define OBJ_EVENT_PAL_TAG_ACE_TRAINER_COLD_M_PT   0x1171
#define OBJ_EVENT_PAL_TAG_ACE_TRAINER_F_PT        0x1172
#define OBJ_EVENT_PAL_TAG_ACE_TRAINER_M_PT        0x1173
#define OBJ_EVENT_PAL_TAG_ARGENTA_PT              0x1174
#define OBJ_EVENT_PAL_TAG_AROMA_LADY_PT           0x1175
#define OBJ_EVENT_PAL_TAG_ARTIST_PT               0x1176
#define OBJ_EVENT_PAL_TAG_BABY_PT                 0x1177
#define OBJ_EVENT_PAL_TAG_BARRY_PT                0x1178
#define OBJ_EVENT_PAL_TAG_BATTLE_GIRL_PT          0x1179
#define OBJ_EVENT_PAL_TAG_BEAUTY_PT               0x117A
#define OBJ_EVENT_PAL_TAG_BERTHA_PT               0x117B
#define OBJ_EVENT_PAL_TAG_BLACK_BELT_PT           0x117C
#define OBJ_EVENT_PAL_TAG_BREEDER_PT              0x117D
#define OBJ_EVENT_PAL_TAG_BUCK_PT                 0x117E
#define OBJ_EVENT_PAL_TAG_BUG_CATCHER_PT          0x117F
#define OBJ_EVENT_PAL_TAG_BYRON_PT                0x1180
#define OBJ_EVENT_PAL_TAG_CAMERAMAN_PT            0x1181
#define OBJ_EVENT_PAL_TAG_CAMPER_PT               0x1182
#define OBJ_EVENT_PAL_TAG_CANDICE_PT              0x1183
#define OBJ_EVENT_PAL_TAG_CASHIER_F_PT            0x1184
#define OBJ_EVENT_PAL_TAG_CASHIER_M_PT            0x1185
#define OBJ_EVENT_PAL_TAG_CHARON_PT               0x1186
#define OBJ_EVENT_PAL_TAG_CHERYL_PT               0x1187
#define OBJ_EVENT_PAL_TAG_CLOWN_PT                0x1188
#define OBJ_EVENT_PAL_TAG_COLLECTOR_PT            0x1189
#define OBJ_EVENT_PAL_TAG_COWGIRL_PT              0x118A
#define OBJ_EVENT_PAL_TAG_CRASHER_WAKE_PT         0x118B
#define OBJ_EVENT_PAL_TAG_CYCLIST_F_PT            0x118C
#define OBJ_EVENT_PAL_TAG_CYCLIST_M_PT            0x118D
#define OBJ_EVENT_PAL_TAG_CYNTHIA_PT              0x118E
#define OBJ_EVENT_PAL_TAG_CYRUS_PT                0x118F
#define OBJ_EVENT_PAL_TAG_DAHLIA_PT               0x1190
#define OBJ_EVENT_PAL_TAG_DARACH_PT               0x1191
#define OBJ_EVENT_PAL_TAG_EXPERT_PT               0x1192
#define OBJ_EVENT_PAL_TAG_FANTINA_PT              0x1193
#define OBJ_EVENT_PAL_TAG_FISHERMAN_PT            0x1194
#define OBJ_EVENT_PAL_TAG_FLINT_PT                0x1195
#define OBJ_EVENT_PAL_TAG_FRONTIER_BOOTH_PT       0x1196
#define OBJ_EVENT_PAL_TAG_FRONTIER_MULTI_PT       0x1197
#define OBJ_EVENT_PAL_TAG_FRONTIER_SINGLES_PT     0x1198
#define OBJ_EVENT_PAL_TAG_GALACTIC_GRUNT_F_PT     0x1199
#define OBJ_EVENT_PAL_TAG_GALACTIC_GRUNT_M_PT     0x119A
#define OBJ_EVENT_PAL_TAG_GARDENIA_PT             0x119B
#define OBJ_EVENT_PAL_TAG_GENTLEMAN_PT            0x119C
#define OBJ_EVENT_PAL_TAG_GUITARIST_PT            0x119D
#define OBJ_EVENT_PAL_TAG_GYM_GUY_PT              0x119E
#define OBJ_EVENT_PAL_TAG_HIKER_PT                0x119F
#define OBJ_EVENT_PAL_TAG_IDOL_PT                 0x11A0
#define OBJ_EVENT_PAL_TAG_JASMINE_PT              0x11A1
#define OBJ_EVENT_PAL_TAG_JOGGER_PT               0x11A2
#define OBJ_EVENT_PAL_TAG_JOHANNA_PT              0x11A3
#define OBJ_EVENT_PAL_TAG_JUPITER_PT              0x11A4
#define OBJ_EVENT_PAL_TAG_LADY_PT                 0x11A5
#define OBJ_EVENT_PAL_TAG_LASS_PT                 0x11A6
#define OBJ_EVENT_PAL_TAG_LOOKER_PT               0x11A7
#define OBJ_EVENT_PAL_TAG_LUCIAN_PT               0x11A8
#define OBJ_EVENT_PAL_TAG_MAID_PT                 0x11A9
#define OBJ_EVENT_PAL_TAG_MAN_PT                  0x11AA
#define OBJ_EVENT_PAL_TAG_MAN_SNOW_PT             0x11AB
#define OBJ_EVENT_PAL_TAG_MARLEY_PT               0x11AC
#define OBJ_EVENT_PAL_TAG_MARS_PT                 0x11AD
#define OBJ_EVENT_PAL_TAG_MAYLENE_PT              0x11AE
#define OBJ_EVENT_PAL_TAG_MIRA_PT                 0x11AF
#define OBJ_EVENT_PAL_TAG_NDS_KID_PT              0x11B0
#define OBJ_EVENT_PAL_TAG_NINJA_BOY_PT            0x11B1
#define OBJ_EVENT_PAL_TAG_NURSE_JOY_PT            0x11B2
#define OBJ_EVENT_PAL_TAG_OAK_PT                  0x11B3
#define OBJ_EVENT_PAL_TAG_OLD_MAN_PT              0x11B4
#define OBJ_EVENT_PAL_TAG_OLD_WOMAN_PT            0x11B5
#define OBJ_EVENT_PAL_TAG_PALMER_PT               0x11B6
#define OBJ_EVENT_PAL_TAG_PARASOL_LADY_PT         0x11B7
#define OBJ_EVENT_PAL_TAG_PICNICKER_PT            0x11B8
#define OBJ_EVENT_PAL_TAG_PLAZA_ATTENDANT_F_PT    0x11B9
#define OBJ_EVENT_PAL_TAG_PLAZA_ATTENDANT_M_PT    0x11BA
#define OBJ_EVENT_PAL_TAG_POKEFAN_F_PT            0x11BB
#define OBJ_EVENT_PAL_TAG_POKEFAN_M_PT            0x11BC
#define OBJ_EVENT_PAL_TAG_POLICEMAN_PT            0x11BD
#define OBJ_EVENT_PAL_TAG_PSYCHIC_PT              0x11BE
#define OBJ_EVENT_PAL_TAG_RANCHER_PT              0x11BF
#define OBJ_EVENT_PAL_TAG_RECEPTIONIST_PT         0x11C0
#define OBJ_EVENT_PAL_TAG_REPORTER_PT             0x11C1
#define OBJ_EVENT_PAL_TAG_RICH_BOY_PT             0x11C2
#define OBJ_EVENT_PAL_TAG_RILEY_PT                0x11C3
#define OBJ_EVENT_PAL_TAG_ROARK_PT                0x11C4
#define OBJ_EVENT_PAL_TAG_ROUGHNECK_PT            0x11C5
#define OBJ_EVENT_PAL_TAG_ROWAN_PT                0x11C6
#define OBJ_EVENT_PAL_TAG_RUIN_MANIAC_PT          0x11C7
#define OBJ_EVENT_PAL_TAG_SAILOR_PT               0x11C8
#define OBJ_EVENT_PAL_TAG_SATURN_PT               0x11C9
#define OBJ_EVENT_PAL_TAG_SCHOOL_KID_F_PT         0x11CA
#define OBJ_EVENT_PAL_TAG_SCHOOL_KID_M_PT         0x11CB
#define OBJ_EVENT_PAL_TAG_SCIENTIST_F_PT          0x11CC
#define OBJ_EVENT_PAL_TAG_SCIENTIST_M_PT          0x11CD
#define OBJ_EVENT_PAL_TAG_SKIER_F_PT              0x11CE
#define OBJ_EVENT_PAL_TAG_SKIER_M_PT              0x11CF
#define OBJ_EVENT_PAL_TAG_SOCIALITE_PT            0x11D0
#define OBJ_EVENT_PAL_TAG_SWIMMER_F_PT            0x11D1
#define OBJ_EVENT_PAL_TAG_SWIMMER_M_PT            0x11D2
#define OBJ_EVENT_PAL_TAG_TEALA_PT                0x11D3
#define OBJ_EVENT_PAL_TAG_THORNTON_PT             0x11D4
#define OBJ_EVENT_PAL_TAG_TUBER_F_PT              0x11D5
#define OBJ_EVENT_PAL_TAG_TUBER_M_PT              0x11D6
#define OBJ_EVENT_PAL_TAG_TWINS_PT                0x11D7
#define OBJ_EVENT_PAL_TAG_VETERAN_PT              0x11D8
#define OBJ_EVENT_PAL_TAG_VOLKNER_PT              0x11D9
#define OBJ_EVENT_PAL_TAG_WAITER_PT               0x11DA
#define OBJ_EVENT_PAL_TAG_WAITRESS_PT             0x11DB
#define OBJ_EVENT_PAL_TAG_WOMAN_PT                0x11DC
#define OBJ_EVENT_PAL_TAG_WOMAN_SNOW_PT           0x11DD
#define OBJ_EVENT_PAL_TAG_WORKER_PT               0x11DE
#define OBJ_EVENT_PAL_TAG_YOUNGSTER_PT            0x11DF

#define OBJ_EVENT_PAL_TAG_BRIEFCASE_PT            0x11E0
#define OBJ_EVENT_PAL_TAG_BREAKABLE_ROCK_PT       0x11E1
#define OBJ_EVENT_PAL_TAG_CUTTABLE_TREE_PT        0x11E2
#define OBJ_EVENT_PAL_TAG_PUSHABLE_BOULDER_PT     0x11E3
#define OBJ_EVENT_PAL_TAG_BIKE_RACK_PT            0x11E4
#define OBJ_EVENT_PAL_TAG_BIKE_DISPLAY_PT         0x11E5
#define OBJ_EVENT_PAL_TAG_WIND_TURBINE            0x11E6
#define OBJ_EVENT_PAL_TAG_BURIED_TRAINER_BROWN_PT 0x11E7
#define OBJ_EVENT_PAL_TAG_BURIED_TRAINER_GREEN_PT 0x11E8
#define OBJ_EVENT_PAL_TAG_BURIED_TRAINER_WHITE_PT 0x11E9
#define OBJ_EVENT_PAL_TAG_BURIED_TRAINER_GRAY_PT  0x11EA

// Used as a placeholder follower graphic
#define OBJ_EVENT_PAL_TAG_SUBSTITUTE              0x7611
#define OBJ_EVENT_PAL_TAG_LIGHT                   0x8001
#define OBJ_EVENT_PAL_TAG_LIGHT_2                 0x8002
#define OBJ_EVENT_PAL_TAG_EMOTES                  0x8003
#define OBJ_EVENT_PAL_TAG_NEON_LIGHT              0x8004
// Not a real OW palette tag; used for the white flash applied to followers
#define OBJ_EVENT_PAL_TAG_WHITE                   (OBJ_EVENT_PAL_TAG_NONE - 1)
#define OBJ_EVENT_PAL_TAG_NONE                    0x11FF

// This + localId is used as the tileTag
// for compressed graphicsInfos
// '(C)ompressed (E)vent'
#define COMP_OW_TILE_TAG_BASE 0xCE00

#endif  // GUARD_CONSTANTS_EVENT_OBJECTS_H
