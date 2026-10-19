#include "global.h"
#include "save.h"
#include "malloc.h"
#include "gba/macro.h"

struct SaveBlock1_v0
{
    /*0x00*/ struct Coords16 pos;
    /*0x04*/ struct WarpData location;
    /*0x0C*/ struct WarpData continueGameWarp;
    /*0x14*/ struct WarpData dynamicWarp;
    /*0x1C*/ struct WarpData lastHealLocation; // used by white-out and teleport
    /*0x24*/ struct WarpData escapeWarp; // used by Dig and Escape Rope
    /*0x2C*/ u16 savedMusic;
    /*0x2E*/ u8 weather;
    /*0x2F*/ u8 weatherCycleStage;
    /*0x30*/ u8 flashLevel;
    /*0x31*/ //u8 padding1;
    /*0x32*/ u16 mapLayoutId;
    /*0x34*/ u16 mapView[0x100];
    /*0x234*/ u8 playerPartyCount;
    /*0x235*/ //u8 padding2[3];
    /*0x238*/ struct Pokemon playerParty[PARTY_SIZE];
    /*0x490*/ u32 money;
    /*0x494*/ u16 coins;
    /*0x496*/ u16 registeredItem; // registered for use with SELECT button
    /*0x498*/ struct ItemSlot pcItems[PC_ITEMS_COUNT];
    /*0x560 -> 0x848 is bag storage*/
    /*0x560*/ struct Bag bag;
    /*0x848*/ struct Pokeblock pokeblocks[POKEBLOCKS_COUNT];
#if FREE_EXTRA_SEEN_FLAGS_SAVEBLOCK1 == FALSE
    /*0x988*/ u8 filler1[0x34]; // Previously Dex Flags, feel free to remove.
#endif //FREE_EXTRA_SEEN_FLAGS_SAVEBLOCK1
    /*0x9BC*/ u16 berryBlenderRecords[3];
    /*0x9C2*/ u8 unused_9C2[6];
#if FREE_MATCH_CALL == FALSE
    /*0x9C8*/ u16 trainerRematchStepCounter;
    /*0x9CA*/ u8 trainerRematches[MAX_REMATCH_ENTRIES];
#endif //FREE_MATCH_CALL
    /*0xA2E*/ //u8 padding3[2];
    /*0xA30*/ struct ObjectEvent objectEvents[OBJECT_EVENTS_COUNT];
    /*0xC70*/ struct ObjectEventTemplate objectEventTemplates[OBJECT_EVENT_TEMPLATES_COUNT];
    /*0x1270*/ u8 flags[NUM_FLAG_BYTES];
    /*0x139C*/ u16 vars[VARS_COUNT];
    /*0x159C*/ u32 gameStats[NUM_GAME_STATS];
    /*0x169C*/ struct BerryTree berryTrees[BERRY_TREES_COUNT];
    /*0x1A9C*/ struct SecretBase secretBases[SECRET_BASES_COUNT];
    /*0x271C*/ u8 playerRoomDecorations[DECOR_MAX_PLAYERS_HOUSE];
    /*0x2728*/ u8 playerRoomDecorationPositions[DECOR_MAX_PLAYERS_HOUSE];
    /*0x2734*/ u8 decorationDesks[10];
    /*0x273E*/ u8 decorationChairs[10];
    /*0x2748*/ u8 decorationPlants[10];
    /*0x2752*/ u8 decorationOrnaments[30];
    /*0x2770*/ u8 decorationMats[30];
    /*0x278E*/ u8 decorationPosters[10];
    /*0x2798*/ u8 decorationDolls[40];
    /*0x27C0*/ u8 decorationCushions[10];
    /*0x27CC*/ TVShow tvShows[TV_SHOWS_COUNT];
    /*0x27CA*/ //u8 padding4[2];
    /*0x2B50*/ PokeNews pokeNews[POKE_NEWS_COUNT];
    /*0x2B90*/ u16 outbreakPokemonSpecies;
    /*0x2B92*/ u8 outbreakLocationMapNum;
    /*0x2B93*/ u8 outbreakLocationMapGroup;
    /*0x2B94*/ u8 outbreakPokemonLevel;
    /*0x2B95*/ u8 outbreakUnused1;
    /*0x2B96*/ u16 outbreakUnused2;
    /*0x2B98*/ u16 outbreakPokemonMoves[MAX_MON_MOVES];
    /*0x2BA0*/ u8 outbreakUnused3;
    /*0x2BA1*/ u8 outbreakPokemonProbability;
    /*0x2BA2*/ u16 outbreakDaysLeft;
    /*0x2BA4*/ struct GabbyAndTyData gabbyAndTyData;
    /*0x2BB0*/ u16 easyChatProfile[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x2BBC*/ u16 easyChatBattleStart[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x2BC8*/ u16 easyChatBattleWon[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x2BD4*/ u16 easyChatBattleLost[EASY_CHAT_BATTLE_WORDS_COUNT];
    /*0x2BE0*/ struct Mail mail[MAIL_COUNT];
    /*0x2E20*/ u8 unlockedTrendySayings[NUM_TRENDY_SAYING_BYTES]; // Bitfield for unlockable Easy Chat words in EC_GROUP_TRENDY_SAYING
    /*0x2E25*/ //u8 padding5[3];
    /*0x2E28*/ OldMan oldMan;
    /*0x2e64*/ struct DewfordTrend dewfordTrends[SAVED_TRENDS_COUNT];
    /*0x2e90*/ struct ContestWinner contestWinners[NUM_CONTEST_WINNERS]; // see CONTEST_WINNER_*
    /*0x3030*/ struct DayCare daycare;
#if FREE_LINK_BATTLE_RECORDS == FALSE
    /*0x3150*/ struct LinkBattleRecords linkBattleRecords;
#endif //FREE_LINK_BATTLE_RECORDS
    /*0x31A8*/ u8 giftRibbons[GIFT_RIBBONS_COUNT];
    /*0x31B3*/ struct ExternalEventData externalEventData;
    /*0x31C7*/ struct ExternalEventFlags externalEventFlags;
    /*0x31DC*/ struct Roamer roamer[ROAMER_COUNT];
#if FREE_ENIGMA_BERRY == FALSE
    /*0x31F8*/ struct EnigmaBerry enigmaBerry;
#endif //FREE_ENIGMA_BERRY
#if FREE_MYSTERY_GIFT == FALSE
    /*0x322C*/ struct MysteryGiftSave mysteryGift;
#endif //FREE_MYSTERY_GIFT
    /*0x3???*/ u8 dexSeen[NUM_DEX_FLAG_BYTES];
    /*0x3???*/ u8 dexCaught[NUM_DEX_FLAG_BYTES];
#if FREE_TRAINER_HILL == FALSE
    /*0x3???*/ u32 trainerHillTimes[NUM_TRAINER_HILL_MODES];
#endif //FREE_TRAINER_HILL
#if FREE_MYSTERY_EVENT_BUFFERS == FALSE
    /*0x3???*/ struct RamScript ramScript;
#endif //FREE_MYSTERY_EVENT_BUFFERS
    /*0x3???*/ struct RecordMixingGift recordMixingGift;
    /*0x3???*/ LilycoveLady lilycoveLady;
    /*0x3???*/ struct TrainerNameRecord trainerNameRecords[20];
#if FREE_UNION_ROOM_CHAT == FALSE
    /*0x3???*/ u8 registeredTexts[UNION_ROOM_KB_ROW_COUNT][21];
#endif //FREE_UNION_ROOM_CHAT
#if FREE_TRAINER_HILL == FALSE
    /*0x3???*/ struct TrainerHillSave trainerHill;
#endif //FREE_TRAINER_HILL
    /*0x3???*/ struct WaldaPhrase waldaPhrase;
    // sizeof: 0x3???
};

struct SaveBlock2_v0
{
    /*0x00*/ u8 playerName[PLAYER_NAME_LENGTH + 1];
    /*0x08*/ u8 playerGender; // MALE, FEMALE
    /*0x09*/ u8 specialSaveWarpFlags;
    /*0x0A*/ u8 playerTrainerId[TRAINER_ID_LENGTH];
    /*0x0E*/ u16 playTimeHours;
    /*0x10*/ u8 playTimeMinutes;
    /*0x11*/ u8 playTimeSeconds;
    /*0x12*/ u8 playTimeVBlanks;
    /*0x13*/ u8 optionsButtonMode;  // OPTIONS_BUTTON_MODE_[NORMAL/LR/L_EQUALS_A]
    /*0x14*/ u16 optionsTextSpeed:3; // OPTIONS_TEXT_SPEED_[SLOW/MID/FAST]
             u16 optionsWindowFrameType:5; // Specifies one of the 20 decorative borders for text boxes
             u16 optionsSound:1; // OPTIONS_SOUND_[MONO/STEREO]
             u16 optionsBattleStyle:1; // OPTIONS_BATTLE_STYLE_[SHIFT/SET]
             u16 optionsBattleSceneOff:1; // whether battle animations are disabled
             u16 regionMapZoom:1; // whether the map is zoomed in
             //u16 padding1:4;
             //u16 padding2;
    /*0x18*/ struct Pokedex pokedex;
    /*0x90*/ u8 rivalName[PLAYER_NAME_LENGTH + 1];
    /*0x98*/ struct Time localTimeOffset;
    /*0xA0*/ struct Time lastBerryTreeUpdate;
    /*0xA8*/ u32 gcnLinkFlags; // Read by Pokémon Colosseum/XD
    /*0xAC*/ u32 encryptionKey;
    /*0xB0*/ struct PlayersApprentice playerApprentice;
    /*0xDC*/ struct Apprentice apprentices[APPRENTICE_COUNT];
    /*0x1EC*/ struct BerryCrush berryCrush;
#if FREE_POKEMON_JUMP == FALSE
    /*0x1FC*/ struct PokemonJumpRecords pokeJump;
#endif //FREE_POKEMON_JUMP
    /*0x20C*/ struct BerryPickingResults berryPick;
#if FREE_RECORD_MIXING_HALL_RECORDS == FALSE
    /*0x21C*/ struct RankingHall1P hallRecords1P[HALL_FACILITIES_COUNT][FRONTIER_LVL_MODE_COUNT][HALL_RECORDS_COUNT]; // From record mixing.
    /*0x57C*/ struct RankingHall2P hallRecords2P[FRONTIER_LVL_MODE_COUNT][HALL_RECORDS_COUNT]; // From record mixing.
#endif //FREE_RECORD_MIXING_HALL_RECORDS
    /*0x624*/ u16 contestLinkResults[CONTEST_CATEGORIES_COUNT][CONTESTANT_COUNT];
    /*0x64C*/ struct BattleFrontier frontier;
}; // sizeof=0xF2C

struct SaveBlock3_v0
{
#if OW_USE_FAKE_RTC
    struct SiiRtcInfo fakeRTC;
#endif
#if FNPC_ENABLE_NPC_FOLLOWERS
    struct NPCFollower NPCfollower;
#endif
#if OW_SHOW_ITEM_DESCRIPTIONS == OW_ITEM_DESCRIPTIONS_FIRST_TIME
    u8 itemFlags[ITEM_FLAGS_COUNT];
#endif
#if USE_DEXNAV_SEARCH_LEVELS == TRUE
    u8 dexNavSearchLevels[NUM_SPECIES];
#endif
    u8 dexNavChain;
#if APRICORN_TREE_COUNT > 0
    u8 apricornTrees[NUM_APRICORN_TREE_BYTES];
#endif
}; /* max size 1624 bytes */

struct PokemonStorage_v0
{
    /*0x0000*/ u8 currentBox;
    /*0x0001*/ struct BoxPokemon boxes[TOTAL_BOXES_COUNT][IN_BOX_COUNT];
    /*0x8344*/ u8 boxNames[TOTAL_BOXES_COUNT][BOX_NAME_LENGTH + 1];
    /*0x83C2*/ u8 boxWallpapers[TOTAL_BOXES_COUNT];
    /*0x8432*/ struct Pokemon fusions[MAX_FUSION_STORAGE];
};

bool8 UpdateSave_v0_v1(const struct SaveSectorLocation *locations)
{
    const struct SaveBlock2_v0 *sOldSaveBlock2Ptr =
        (struct SaveBlock2_v0 *)(locations[SECTOR_ID_SAVEBLOCK2].data);

    const struct SaveBlock1_v0 *sOldSaveBlock1Ptr =
        (struct SaveBlock1_v0 *)(locations[SECTOR_ID_SAVEBLOCK1_START].data);

    const struct PokemonStorage_v0 *sOldPokemonStoragePtr =
        (struct PokemonStorage_v0 *)(locations[SECTOR_ID_PKMN_STORAGE_START].data);

    u32 i;

    gSaveBlock2Ptr->_saveSentinel = 0xFF;
    gSaveBlock2Ptr->saveVersion = SAVE_VERSION_1;

#define COPY_FIELD(field) \
    gSaveBlock2Ptr->field = sOldSaveBlock2Ptr->field

#define COPY_BLOCK(field) \
    CpuCopy16(&sOldSaveBlock2Ptr->field, &gSaveBlock2Ptr->field, sizeof(gSaveBlock2Ptr->field))

#define COPY_ARRAY(field) \
    for (i = 0; i < min(ARRAY_COUNT(gSaveBlock2Ptr->field), ARRAY_COUNT(sOldSaveBlock2Ptr->field)); i++) \
        gSaveBlock2Ptr->field[i] = sOldSaveBlock2Ptr->field[i]

    // SaveBlock2
    COPY_ARRAY(playerName);
    COPY_FIELD(playerGender);
    COPY_FIELD(specialSaveWarpFlags);
    COPY_ARRAY(playerTrainerId);
    COPY_FIELD(playTimeHours);
    COPY_FIELD(playTimeMinutes);
    COPY_FIELD(playTimeSeconds);
    COPY_FIELD(playTimeVBlanks);
    COPY_FIELD(optionsButtonMode);
    COPY_FIELD(optionsTextSpeed);
    COPY_FIELD(optionsWindowFrameType);
    COPY_FIELD(optionsSound);
    COPY_FIELD(optionsBattleStyle);
    COPY_FIELD(optionsBattleSceneOff);
    COPY_FIELD(regionMapZoom);
    COPY_FIELD(pokedex);
    COPY_ARRAY(rivalName);
    COPY_FIELD(localTimeOffset);
    COPY_FIELD(lastBerryTreeUpdate);
    COPY_FIELD(gcnLinkFlags);
    COPY_FIELD(encryptionKey);
    COPY_FIELD(playerApprentice);
    COPY_BLOCK(apprentices);
    COPY_FIELD(berryCrush);
#if FREE_POKEMON_JUMP == FALSE
    COPY_FIELD(pokeJump);
#endif
    COPY_FIELD(berryPick);
#if FREE_RECORD_MIXING_HALL_RECORDS == FALSE
    COPY_BLOCK(hallRecords1P);
    COPY_BLOCK(hallRecords2P);
#endif
    COPY_BLOCK(contestLinkResults);
    COPY_FIELD(frontier);

#undef COPY_FIELD
#undef COPY_BLOCK
#undef COPY_ARRAY

#define COPY_FIELD(field) \
    gSaveBlock1Ptr->field = sOldSaveBlock1Ptr->field

#define COPY_BLOCK(field) \
    CpuCopy16(&sOldSaveBlock1Ptr->field, &gSaveBlock1Ptr->field, sizeof(gSaveBlock1Ptr->field))

#define COPY_ARRAY(field) \
    for (i = 0; i < min(ARRAY_COUNT(gSaveBlock1Ptr->field), ARRAY_COUNT(sOldSaveBlock1Ptr->field)); i++) \
        gSaveBlock1Ptr->field[i] = sOldSaveBlock1Ptr->field[i]

    // SaveBlock1
    COPY_FIELD(pos);
    COPY_FIELD(location);
    COPY_FIELD(continueGameWarp);
    COPY_FIELD(dynamicWarp);
    COPY_FIELD(lastHealLocation);
    COPY_FIELD(escapeWarp);

    /*
    Don't copy:
    weather
    weatherCycleStage
    flashLevel
    savedMusic
    mapLayoutId
    mapView
    objectEvents
    objectEventTemplates
    These contain state associated with the old map.
    */

    COPY_FIELD(playerPartyCount);
    COPY_ARRAY(playerParty);
    COPY_FIELD(money);
    COPY_FIELD(coins);
    COPY_FIELD(registeredItem);
    COPY_BLOCK(pcItems);
    COPY_FIELD(bag);
    COPY_BLOCK(pokeblocks);

#if FREE_EXTRA_SEEN_FLAGS_SAVEBLOCK1 == FALSE
    COPY_BLOCK(filler1);
#endif

    COPY_BLOCK(berryBlenderRecords);
    COPY_BLOCK(unused_9C2);

#if FREE_MATCH_CALL == FALSE
    COPY_FIELD(trainerRematchStepCounter);
    COPY_BLOCK(trainerRematches);
#endif

    COPY_BLOCK(flags);
    COPY_BLOCK(vars);
    COPY_BLOCK(gameStats);
    COPY_BLOCK(berryTrees);
    COPY_BLOCK(secretBases);
    COPY_BLOCK(playerRoomDecorations);
    COPY_BLOCK(playerRoomDecorationPositions);
    COPY_BLOCK(decorationDesks);
    COPY_BLOCK(decorationChairs);
    COPY_BLOCK(decorationPlants);
    COPY_BLOCK(decorationOrnaments);
    COPY_BLOCK(decorationMats);
    COPY_BLOCK(decorationPosters);
    COPY_BLOCK(decorationDolls);
    COPY_BLOCK(decorationCushions);
    COPY_BLOCK(tvShows);
    COPY_BLOCK(pokeNews);

    COPY_FIELD(outbreakPokemonSpecies);
    COPY_FIELD(outbreakLocationMapNum);
    COPY_FIELD(outbreakLocationMapGroup);
    COPY_FIELD(outbreakPokemonLevel);
    COPY_FIELD(outbreakUnused1);
    COPY_FIELD(outbreakUnused2);
    COPY_BLOCK(outbreakPokemonMoves);
    COPY_FIELD(outbreakUnused3);
    COPY_FIELD(outbreakPokemonProbability);
    COPY_FIELD(outbreakDaysLeft);

    COPY_FIELD(gabbyAndTyData);
    COPY_BLOCK(easyChatProfile);
    COPY_BLOCK(easyChatBattleStart);
    COPY_BLOCK(easyChatBattleWon);
    COPY_BLOCK(easyChatBattleLost);
    COPY_BLOCK(mail);
    COPY_BLOCK(unlockedTrendySayings);
    COPY_FIELD(oldMan);
    COPY_BLOCK(dewfordTrends);
    COPY_BLOCK(contestWinners);
    COPY_FIELD(daycare);

#if FREE_LINK_BATTLE_RECORDS == FALSE
    COPY_FIELD(linkBattleRecords);
#endif

    COPY_BLOCK(giftRibbons);
    COPY_FIELD(externalEventData);
    COPY_FIELD(externalEventFlags);
    COPY_BLOCK(roamer);

#if FREE_ENIGMA_BERRY == FALSE
    COPY_FIELD(enigmaBerry);
#endif

#if FREE_MYSTERY_GIFT == FALSE
    COPY_FIELD(mysteryGift);
#endif

    COPY_BLOCK(dexSeen);
    COPY_BLOCK(dexCaught);

#if FREE_TRAINER_HILL == FALSE
    COPY_BLOCK(trainerHillTimes);
#endif

#if FREE_MYSTERY_EVENT_BUFFERS == FALSE
    COPY_FIELD(ramScript);
#endif

    COPY_FIELD(recordMixingGift);
    COPY_FIELD(lilycoveLady);
    COPY_BLOCK(trainerNameRecords);

#if FREE_UNION_ROOM_CHAT == FALSE
    COPY_BLOCK(registeredTexts);
#endif

#if FREE_TRAINER_HILL == FALSE
    COPY_FIELD(trainerHill);
#endif

    COPY_FIELD(waldaPhrase);

#undef COPY_FIELD
#undef COPY_BLOCK
#undef COPY_ARRAY

    /*
    The pokemon structure hasn't changed at all this version, so
    we can just assign across the old box storage to the new.
    */ 
    CpuCopy16(sOldPokemonStoragePtr, gPokemonStoragePtr, sizeof(*gPokemonStoragePtr));

    /*
    The most common kind of change that might happen between major versions are 
    map changes. The save file usually saves the area around the player and 
    event objects currently on the map, so that when the player resumes play, 
    everything will be exactly where it was when they saved. But if the map has
    changed at all, this means there could be incongruity between the saved
    version of the map and the new version in the updated ROM. So to make it so
    that the map reloads properly, we use the "Continue Game Warp" usually used
    when the player clears the game to place the player at a known position and
    with a newly loaded map and event objects. Here, we're using the last location
    that the player healed, so the player will appear in the same spot they would
    as if they blacked out.
    */
    SetContinueGameWarpStatus();
    gSaveBlock1Ptr->continueGameWarp = gSaveBlock1Ptr->lastHealLocation;

    return TRUE;
}