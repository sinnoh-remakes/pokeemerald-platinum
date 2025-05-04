// Normally, INCBIN_COMP acts like INCBIN_U32, but appends `.lz` to the file, compressing it;
// If not compressing overworld gfx, make this an alias to INCBIN_32, so gfx will *not* be compressed
#if !(OW_GFX_COMPRESS)
#define INCBIN_COMP INCBIN_U32
#endif

const u32 gMonFrontPic_CircledQuestionMark[] = INCBIN_U32("graphics/pokemon/question_mark/circled/anim_front.4bpp.lz");
const u32 gMonBackPic_CircledQuestionMark[] = INCBIN_U32("graphics/pokemon/question_mark/circled/back.4bpp.lz");
const u32 gMonPalette_CircledQuestionMark[] = INCBIN_U32("graphics/pokemon/question_mark/circled/normal.gbapal.lz");
const u32 gMonShinyPalette_CircledQuestionMark[] = INCBIN_U32("graphics/pokemon/question_mark/circled/shiny.gbapal.lz");
const u8 gMonIcon_QuestionMark[] = INCBIN_U8("graphics/pokemon/question_mark/icon.4bpp");
#if P_FOOTPRINTS
#if !P_GBA_STYLE_SPECIES_FOOTPRINTS
    const u8 gMonFootprint_QuestionMark[] = INCBIN_U8("graphics/pokemon/question_mark/footprint.1bpp");
#else
    const u8 gMonFootprint_QuestionMark[] = INCBIN_U8("graphics/pokemon/question_mark/footprint_gba.1bpp");
#endif //P_GBA_STYLE_SPECIES_FOOTPRINTS
#endif //P_FOOTPRINTS
const u32 gObjectEventPic_Substitute[] = INCBIN_COMP("graphics/pokemon/question_mark/overworld.4bpp");

#if P_FAMILY_BULBASAUR
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Bulbasaur[] = INCBIN_U32("graphics/pokemon/bulbasaur/anim_front.4bpp.lz");
    const u32 gMonPalette_Bulbasaur[] = INCBIN_U32("graphics/pokemon/bulbasaur/normal.gbapal.lz");
    const u32 gMonBackPic_Bulbasaur[] = INCBIN_U32("graphics/pokemon/bulbasaur/back.4bpp.lz");
    const u32 gMonShinyPalette_Bulbasaur[] = INCBIN_U32("graphics/pokemon/bulbasaur/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Bulbasaur[] = INCBIN_U32("graphics/pokemon/bulbasaur/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Bulbasaur[] = INCBIN_U32("graphics/pokemon/bulbasaur/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Bulbasaur[] = INCBIN_U32("graphics/pokemon/bulbasaur/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Bulbasaur[] = INCBIN_U32("graphics/pokemon/bulbasaur/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Bulbasaur[] = INCBIN_U8("graphics/pokemon/bulbasaur/icon.4bpp");
#else
    const u8 gMonIcon_Bulbasaur[] = INCBIN_U8("graphics/pokemon/bulbasaur/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Bulbasaur[] = INCBIN_U8("graphics/pokemon/bulbasaur/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Bulbasaur[] = INCBIN_COMP("graphics/pokemon/bulbasaur/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Bulbasaur[] = INCBIN_U32("graphics/pokemon/bulbasaur/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Bulbasaur[] = INCBIN_U32("graphics/pokemon/bulbasaur/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Ivysaur[] = INCBIN_U32("graphics/pokemon/ivysaur/anim_front.4bpp.lz");
    const u32 gMonPalette_Ivysaur[] = INCBIN_U32("graphics/pokemon/ivysaur/normal.gbapal.lz");
    const u32 gMonBackPic_Ivysaur[] = INCBIN_U32("graphics/pokemon/ivysaur/back.4bpp.lz");
    const u32 gMonShinyPalette_Ivysaur[] = INCBIN_U32("graphics/pokemon/ivysaur/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Ivysaur[] = INCBIN_U32("graphics/pokemon/ivysaur/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Ivysaur[] = INCBIN_U32("graphics/pokemon/ivysaur/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Ivysaur[] = INCBIN_U32("graphics/pokemon/ivysaur/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Ivysaur[] = INCBIN_U32("graphics/pokemon/ivysaur/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Ivysaur[] = INCBIN_U8("graphics/pokemon/ivysaur/icon.4bpp");
#else
    const u8 gMonIcon_Ivysaur[] = INCBIN_U8("graphics/pokemon/ivysaur/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Ivysaur[] = INCBIN_U8("graphics/pokemon/ivysaur/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Ivysaur[] = INCBIN_COMP("graphics/pokemon/ivysaur/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Ivysaur[] = INCBIN_U32("graphics/pokemon/ivysaur/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Ivysaur[] = INCBIN_U32("graphics/pokemon/ivysaur/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Venusaur[] = INCBIN_U32("graphics/pokemon/venusaur/anim_front.4bpp.lz");
    const u32 gMonPalette_Venusaur[] = INCBIN_U32("graphics/pokemon/venusaur/normal.gbapal.lz");
    const u32 gMonBackPic_Venusaur[] = INCBIN_U32("graphics/pokemon/venusaur/back.4bpp.lz");
    const u32 gMonShinyPalette_Venusaur[] = INCBIN_U32("graphics/pokemon/venusaur/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Venusaur[] = INCBIN_U32("graphics/pokemon/venusaur/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Venusaur[] = INCBIN_U32("graphics/pokemon/venusaur/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Venusaur[] = INCBIN_U32("graphics/pokemon/venusaur/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Venusaur[] = INCBIN_U32("graphics/pokemon/venusaur/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Venusaur[] = INCBIN_U8("graphics/pokemon/venusaur/icon.4bpp");
#else
    const u8 gMonIcon_Venusaur[] = INCBIN_U8("graphics/pokemon/venusaur/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Venusaur[] = INCBIN_U8("graphics/pokemon/venusaur/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Venusaur[] = INCBIN_COMP("graphics/pokemon/venusaur/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Venusaur[] = INCBIN_U32("graphics/pokemon/venusaur/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Venusaur[] = INCBIN_U32("graphics/pokemon/venusaur/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_VenusaurF[] = INCBIN_U32("graphics/pokemon/venusaur/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_VenusaurF[] = INCBIN_U32("graphics/pokemon/venusaur/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_VenusaurF[] = INCBIN_COMP("graphics/pokemon/venusaur/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_BULBASAUR

#if P_FAMILY_CHARMANDER
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Charmander[] = INCBIN_U32("graphics/pokemon/charmander/anim_front.4bpp.lz");
    const u32 gMonPalette_Charmander[] = INCBIN_U32("graphics/pokemon/charmander/normal.gbapal.lz");
    const u32 gMonBackPic_Charmander[] = INCBIN_U32("graphics/pokemon/charmander/back.4bpp.lz");
    const u32 gMonShinyPalette_Charmander[] = INCBIN_U32("graphics/pokemon/charmander/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Charmander[] = INCBIN_U32("graphics/pokemon/charmander/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Charmander[] = INCBIN_U32("graphics/pokemon/charmander/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Charmander[] = INCBIN_U32("graphics/pokemon/charmander/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Charmander[] = INCBIN_U32("graphics/pokemon/charmander/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Charmander[] = INCBIN_U8("graphics/pokemon/charmander/icon.4bpp");
#else
    const u8 gMonIcon_Charmander[] = INCBIN_U8("graphics/pokemon/charmander/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Charmander[] = INCBIN_U8("graphics/pokemon/charmander/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Charmander[] = INCBIN_COMP("graphics/pokemon/charmander/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Charmander[] = INCBIN_U32("graphics/pokemon/charmander/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Charmander[] = INCBIN_U32("graphics/pokemon/charmander/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Charmeleon[] = INCBIN_U32("graphics/pokemon/charmeleon/anim_front.4bpp.lz");
    const u32 gMonPalette_Charmeleon[] = INCBIN_U32("graphics/pokemon/charmeleon/normal.gbapal.lz");
    const u32 gMonBackPic_Charmeleon[] = INCBIN_U32("graphics/pokemon/charmeleon/back.4bpp.lz");
    const u32 gMonShinyPalette_Charmeleon[] = INCBIN_U32("graphics/pokemon/charmeleon/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Charmeleon[] = INCBIN_U32("graphics/pokemon/charmeleon/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Charmeleon[] = INCBIN_U32("graphics/pokemon/charmeleon/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Charmeleon[] = INCBIN_U32("graphics/pokemon/charmeleon/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Charmeleon[] = INCBIN_U32("graphics/pokemon/charmeleon/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Charmeleon[] = INCBIN_U8("graphics/pokemon/charmeleon/icon.4bpp");
#else
    const u8 gMonIcon_Charmeleon[] = INCBIN_U8("graphics/pokemon/charmeleon/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Charmeleon[] = INCBIN_U8("graphics/pokemon/charmeleon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Charmeleon[] = INCBIN_COMP("graphics/pokemon/charmeleon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Charmeleon[] = INCBIN_U32("graphics/pokemon/charmeleon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Charmeleon[] = INCBIN_U32("graphics/pokemon/charmeleon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Charizard[] = INCBIN_U32("graphics/pokemon/charizard/anim_front.4bpp.lz");
    const u32 gMonPalette_Charizard[] = INCBIN_U32("graphics/pokemon/charizard/normal.gbapal.lz");
    const u32 gMonBackPic_Charizard[] = INCBIN_U32("graphics/pokemon/charizard/back.4bpp.lz");
    const u32 gMonShinyPalette_Charizard[] = INCBIN_U32("graphics/pokemon/charizard/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Charizard[] = INCBIN_U32("graphics/pokemon/charizard/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Charizard[] = INCBIN_U32("graphics/pokemon/charizard/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Charizard[] = INCBIN_U32("graphics/pokemon/charizard/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Charizard[] = INCBIN_U32("graphics/pokemon/charizard/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Charizard[] = INCBIN_U8("graphics/pokemon/charizard/icon.4bpp");
#else
    const u8 gMonIcon_Charizard[] = INCBIN_U8("graphics/pokemon/charizard/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Charizard[] = INCBIN_U8("graphics/pokemon/charizard/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Charizard[] = INCBIN_COMP("graphics/pokemon/charizard/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Charizard[] = INCBIN_U32("graphics/pokemon/charizard/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Charizard[] = INCBIN_U32("graphics/pokemon/charizard/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_CHARMANDER

#if P_FAMILY_SQUIRTLE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Squirtle[] = INCBIN_U32("graphics/pokemon/squirtle/anim_front.4bpp.lz");
    const u32 gMonPalette_Squirtle[] = INCBIN_U32("graphics/pokemon/squirtle/normal.gbapal.lz");
    const u32 gMonBackPic_Squirtle[] = INCBIN_U32("graphics/pokemon/squirtle/back.4bpp.lz");
    const u32 gMonShinyPalette_Squirtle[] = INCBIN_U32("graphics/pokemon/squirtle/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Squirtle[] = INCBIN_U32("graphics/pokemon/squirtle/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Squirtle[] = INCBIN_U32("graphics/pokemon/squirtle/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Squirtle[] = INCBIN_U32("graphics/pokemon/squirtle/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Squirtle[] = INCBIN_U32("graphics/pokemon/squirtle/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Squirtle[] = INCBIN_U8("graphics/pokemon/squirtle/icon.4bpp");
#else
    const u8 gMonIcon_Squirtle[] = INCBIN_U8("graphics/pokemon/squirtle/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Squirtle[] = INCBIN_U8("graphics/pokemon/squirtle/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Squirtle[] = INCBIN_COMP("graphics/pokemon/squirtle/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Squirtle[] = INCBIN_U32("graphics/pokemon/squirtle/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Squirtle[] = INCBIN_U32("graphics/pokemon/squirtle/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Wartortle[] = INCBIN_U32("graphics/pokemon/wartortle/anim_front.4bpp.lz");
    const u32 gMonPalette_Wartortle[] = INCBIN_U32("graphics/pokemon/wartortle/normal.gbapal.lz");
    const u32 gMonBackPic_Wartortle[] = INCBIN_U32("graphics/pokemon/wartortle/back.4bpp.lz");
    const u32 gMonShinyPalette_Wartortle[] = INCBIN_U32("graphics/pokemon/wartortle/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Wartortle[] = INCBIN_U32("graphics/pokemon/wartortle/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Wartortle[] = INCBIN_U32("graphics/pokemon/wartortle/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Wartortle[] = INCBIN_U32("graphics/pokemon/wartortle/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Wartortle[] = INCBIN_U32("graphics/pokemon/wartortle/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Wartortle[] = INCBIN_U8("graphics/pokemon/wartortle/icon.4bpp");
#else
    const u8 gMonIcon_Wartortle[] = INCBIN_U8("graphics/pokemon/wartortle/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Wartortle[] = INCBIN_U8("graphics/pokemon/wartortle/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Wartortle[] = INCBIN_COMP("graphics/pokemon/wartortle/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Wartortle[] = INCBIN_U32("graphics/pokemon/wartortle/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Wartortle[] = INCBIN_U32("graphics/pokemon/wartortle/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Blastoise[] = INCBIN_U32("graphics/pokemon/blastoise/anim_front.4bpp.lz");
    const u32 gMonPalette_Blastoise[] = INCBIN_U32("graphics/pokemon/blastoise/normal.gbapal.lz");
    const u32 gMonBackPic_Blastoise[] = INCBIN_U32("graphics/pokemon/blastoise/back.4bpp.lz");
    const u32 gMonShinyPalette_Blastoise[] = INCBIN_U32("graphics/pokemon/blastoise/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Blastoise[] = INCBIN_U32("graphics/pokemon/blastoise/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Blastoise[] = INCBIN_U32("graphics/pokemon/blastoise/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Blastoise[] = INCBIN_U32("graphics/pokemon/blastoise/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Blastoise[] = INCBIN_U32("graphics/pokemon/blastoise/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Blastoise[] = INCBIN_U8("graphics/pokemon/blastoise/icon.4bpp");
#else
    const u8 gMonIcon_Blastoise[] = INCBIN_U8("graphics/pokemon/blastoise/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Blastoise[] = INCBIN_U8("graphics/pokemon/blastoise/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Blastoise[] = INCBIN_COMP("graphics/pokemon/blastoise/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Blastoise[] = INCBIN_U32("graphics/pokemon/blastoise/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Blastoise[] = INCBIN_U32("graphics/pokemon/blastoise/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SQUIRTLE

#if P_FAMILY_CATERPIE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Caterpie[] = INCBIN_U32("graphics/pokemon/caterpie/anim_front.4bpp.lz");
    const u32 gMonPalette_Caterpie[] = INCBIN_U32("graphics/pokemon/caterpie/normal.gbapal.lz");
    const u32 gMonBackPic_Caterpie[] = INCBIN_U32("graphics/pokemon/caterpie/back.4bpp.lz");
    const u32 gMonShinyPalette_Caterpie[] = INCBIN_U32("graphics/pokemon/caterpie/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Caterpie[] = INCBIN_U32("graphics/pokemon/caterpie/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Caterpie[] = INCBIN_U32("graphics/pokemon/caterpie/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Caterpie[] = INCBIN_U32("graphics/pokemon/caterpie/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Caterpie[] = INCBIN_U32("graphics/pokemon/caterpie/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Caterpie[] = INCBIN_U8("graphics/pokemon/caterpie/icon.4bpp");
#else
    const u8 gMonIcon_Caterpie[] = INCBIN_U8("graphics/pokemon/caterpie/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Caterpie[] = INCBIN_U8("graphics/pokemon/caterpie/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Caterpie[] = INCBIN_COMP("graphics/pokemon/caterpie/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Caterpie[] = INCBIN_U32("graphics/pokemon/caterpie/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Caterpie[] = INCBIN_U32("graphics/pokemon/caterpie/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Metapod[] = INCBIN_U32("graphics/pokemon/metapod/anim_front.4bpp.lz");
    const u32 gMonPalette_Metapod[] = INCBIN_U32("graphics/pokemon/metapod/normal.gbapal.lz");
    const u32 gMonBackPic_Metapod[] = INCBIN_U32("graphics/pokemon/metapod/back.4bpp.lz");
    const u32 gMonShinyPalette_Metapod[] = INCBIN_U32("graphics/pokemon/metapod/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Metapod[] = INCBIN_U32("graphics/pokemon/metapod/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Metapod[] = INCBIN_U32("graphics/pokemon/metapod/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Metapod[] = INCBIN_U32("graphics/pokemon/metapod/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Metapod[] = INCBIN_U32("graphics/pokemon/metapod/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
    const u8 gMonIcon_Metapod[] = INCBIN_U8( "graphics/pokemon/metapod/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Metapod[] = INCBIN_U8("graphics/pokemon/metapod/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Metapod[] = INCBIN_COMP("graphics/pokemon/metapod/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Metapod[] = INCBIN_U32("graphics/pokemon/metapod/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Metapod[] = INCBIN_U32("graphics/pokemon/metapod/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Butterfree[] = INCBIN_U32("graphics/pokemon/butterfree/anim_front.4bpp.lz");
    const u32 gMonPalette_Butterfree[] = INCBIN_U32("graphics/pokemon/butterfree/normal.gbapal.lz");
    const u32 gMonBackPic_Butterfree[] = INCBIN_U32("graphics/pokemon/butterfree/back.4bpp.lz");
    const u32 gMonShinyPalette_Butterfree[] = INCBIN_U32("graphics/pokemon/butterfree/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Butterfree[] = INCBIN_U32("graphics/pokemon/butterfree/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Butterfree[] = INCBIN_U32("graphics/pokemon/butterfree/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Butterfree[] = INCBIN_U32("graphics/pokemon/butterfree/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Butterfree[] = INCBIN_U32("graphics/pokemon/butterfree/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Butterfree[] = INCBIN_U8("graphics/pokemon/butterfree/icon.4bpp");
#else
    const u8 gMonIcon_Butterfree[] = INCBIN_U8("graphics/pokemon/butterfree/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Butterfree[] = INCBIN_U8("graphics/pokemon/butterfree/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Butterfree[] = INCBIN_COMP("graphics/pokemon/butterfree/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Butterfree[] = INCBIN_U32("graphics/pokemon/butterfree/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Butterfree[] = INCBIN_U32("graphics/pokemon/butterfree/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_ButterfreeF[] = INCBIN_U32("graphics/pokemon/butterfree/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_ButterfreeF[] = INCBIN_U32("graphics/pokemon/butterfree/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_ButterfreeF[] = INCBIN_COMP("graphics/pokemon/butterfree/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_CATERPIE

#if P_FAMILY_WEEDLE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Weedle[] = INCBIN_U32("graphics/pokemon/weedle/anim_front.4bpp.lz");
    const u32 gMonPalette_Weedle[] = INCBIN_U32("graphics/pokemon/weedle/normal.gbapal.lz");
    const u32 gMonBackPic_Weedle[] = INCBIN_U32("graphics/pokemon/weedle/back.4bpp.lz");
    const u32 gMonShinyPalette_Weedle[] = INCBIN_U32("graphics/pokemon/weedle/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Weedle[] = INCBIN_U32("graphics/pokemon/weedle/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Weedle[] = INCBIN_U32("graphics/pokemon/weedle/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Weedle[] = INCBIN_U32("graphics/pokemon/weedle/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Weedle[] = INCBIN_U32("graphics/pokemon/weedle/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Weedle[] = INCBIN_U8("graphics/pokemon/weedle/icon.4bpp");
#else
    const u8 gMonIcon_Weedle[] = INCBIN_U8("graphics/pokemon/weedle/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Weedle[] = INCBIN_U8("graphics/pokemon/weedle/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Weedle[] = INCBIN_COMP("graphics/pokemon/weedle/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Weedle[] = INCBIN_U32("graphics/pokemon/weedle/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Weedle[] = INCBIN_U32("graphics/pokemon/weedle/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Kakuna[] = INCBIN_U32("graphics/pokemon/kakuna/anim_front.4bpp.lz");
    const u32 gMonPalette_Kakuna[] = INCBIN_U32("graphics/pokemon/kakuna/normal.gbapal.lz");
    const u32 gMonBackPic_Kakuna[] = INCBIN_U32("graphics/pokemon/kakuna/back.4bpp.lz");
    const u32 gMonShinyPalette_Kakuna[] = INCBIN_U32("graphics/pokemon/kakuna/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Kakuna[] = INCBIN_U32("graphics/pokemon/kakuna/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Kakuna[] = INCBIN_U32("graphics/pokemon/kakuna/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Kakuna[] = INCBIN_U32("graphics/pokemon/kakuna/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Kakuna[] = INCBIN_U32("graphics/pokemon/kakuna/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Kakuna[] = INCBIN_U8("graphics/pokemon/kakuna/icon.4bpp");
#else
    const u8 gMonIcon_Kakuna[] = INCBIN_U8("graphics/pokemon/kakuna/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Kakuna[] = INCBIN_U8("graphics/pokemon/kakuna/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Kakuna[] = INCBIN_COMP("graphics/pokemon/kakuna/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Kakuna[] = INCBIN_U32("graphics/pokemon/kakuna/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Kakuna[] = INCBIN_U32("graphics/pokemon/kakuna/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Beedrill[] = INCBIN_U32("graphics/pokemon/beedrill/anim_front.4bpp.lz");
    const u32 gMonPalette_Beedrill[] = INCBIN_U32("graphics/pokemon/beedrill/normal.gbapal.lz");
    const u32 gMonBackPic_Beedrill[] = INCBIN_U32("graphics/pokemon/beedrill/back.4bpp.lz");
    const u32 gMonShinyPalette_Beedrill[] = INCBIN_U32("graphics/pokemon/beedrill/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Beedrill[] = INCBIN_U32("graphics/pokemon/beedrill/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Beedrill[] = INCBIN_U32("graphics/pokemon/beedrill/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Beedrill[] = INCBIN_U32("graphics/pokemon/beedrill/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Beedrill[] = INCBIN_U32("graphics/pokemon/beedrill/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Beedrill[] = INCBIN_U8("graphics/pokemon/beedrill/icon.4bpp");
#else
    const u8 gMonIcon_Beedrill[] = INCBIN_U8("graphics/pokemon/beedrill/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Beedrill[] = INCBIN_U8("graphics/pokemon/beedrill/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Beedrill[] = INCBIN_COMP("graphics/pokemon/beedrill/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Beedrill[] = INCBIN_U32("graphics/pokemon/beedrill/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Beedrill[] = INCBIN_U32("graphics/pokemon/beedrill/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_WEEDLE

#if P_FAMILY_PIDGEY
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Pidgey[] = INCBIN_U32("graphics/pokemon/pidgey/anim_front.4bpp.lz");
    const u32 gMonPalette_Pidgey[] = INCBIN_U32("graphics/pokemon/pidgey/normal.gbapal.lz");
    const u32 gMonBackPic_Pidgey[] = INCBIN_U32("graphics/pokemon/pidgey/back.4bpp.lz");
    const u32 gMonShinyPalette_Pidgey[] = INCBIN_U32("graphics/pokemon/pidgey/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Pidgey[] = INCBIN_U32("graphics/pokemon/pidgey/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Pidgey[] = INCBIN_U32("graphics/pokemon/pidgey/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Pidgey[] = INCBIN_U32("graphics/pokemon/pidgey/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Pidgey[] = INCBIN_U32("graphics/pokemon/pidgey/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Pidgey[] = INCBIN_U8("graphics/pokemon/pidgey/icon.4bpp");
#else
    const u8 gMonIcon_Pidgey[] = INCBIN_U8("graphics/pokemon/pidgey/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Pidgey[] = INCBIN_U8("graphics/pokemon/pidgey/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Pidgey[] = INCBIN_COMP("graphics/pokemon/pidgey/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Pidgey[] = INCBIN_U32("graphics/pokemon/pidgey/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Pidgey[] = INCBIN_U32("graphics/pokemon/pidgey/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Pidgeotto[] = INCBIN_U32("graphics/pokemon/pidgeotto/anim_front.4bpp.lz");
    const u32 gMonPalette_Pidgeotto[] = INCBIN_U32("graphics/pokemon/pidgeotto/normal.gbapal.lz");
    const u32 gMonBackPic_Pidgeotto[] = INCBIN_U32("graphics/pokemon/pidgeotto/back.4bpp.lz");
    const u32 gMonShinyPalette_Pidgeotto[] = INCBIN_U32("graphics/pokemon/pidgeotto/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Pidgeotto[] = INCBIN_U32("graphics/pokemon/pidgeotto/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Pidgeotto[] = INCBIN_U32("graphics/pokemon/pidgeotto/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Pidgeotto[] = INCBIN_U32("graphics/pokemon/pidgeotto/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Pidgeotto[] = INCBIN_U32("graphics/pokemon/pidgeotto/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Pidgeotto[] = INCBIN_U8("graphics/pokemon/pidgeotto/icon.4bpp");
#else
    const u8 gMonIcon_Pidgeotto[] = INCBIN_U8("graphics/pokemon/pidgeotto/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Pidgeotto[] = INCBIN_U8("graphics/pokemon/pidgeotto/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Pidgeotto[] = INCBIN_COMP("graphics/pokemon/pidgeotto/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Pidgeotto[] = INCBIN_U32("graphics/pokemon/pidgeotto/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Pidgeotto[] = INCBIN_U32("graphics/pokemon/pidgeotto/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Pidgeot[] = INCBIN_U32("graphics/pokemon/pidgeot/anim_front.4bpp.lz");
    const u32 gMonPalette_Pidgeot[] = INCBIN_U32("graphics/pokemon/pidgeot/normal.gbapal.lz");
    const u32 gMonBackPic_Pidgeot[] = INCBIN_U32("graphics/pokemon/pidgeot/back.4bpp.lz");
    const u32 gMonShinyPalette_Pidgeot[] = INCBIN_U32("graphics/pokemon/pidgeot/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Pidgeot[] = INCBIN_U32("graphics/pokemon/pidgeot/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Pidgeot[] = INCBIN_U32("graphics/pokemon/pidgeot/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Pidgeot[] = INCBIN_U32("graphics/pokemon/pidgeot/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Pidgeot[] = INCBIN_U32("graphics/pokemon/pidgeot/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Pidgeot[] = INCBIN_U8("graphics/pokemon/pidgeot/icon.4bpp");
#else
    const u8 gMonIcon_Pidgeot[] = INCBIN_U8("graphics/pokemon/pidgeot/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Pidgeot[] = INCBIN_U8("graphics/pokemon/pidgeot/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Pidgeot[] = INCBIN_COMP("graphics/pokemon/pidgeot/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Pidgeot[] = INCBIN_U32("graphics/pokemon/pidgeot/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Pidgeot[] = INCBIN_U32("graphics/pokemon/pidgeot/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_PIDGEY

#if P_FAMILY_RATTATA
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Rattata[] = INCBIN_U32("graphics/pokemon/rattata/anim_front.4bpp.lz");
    const u32 gMonPalette_Rattata[] = INCBIN_U32("graphics/pokemon/rattata/normal.gbapal.lz");
    const u32 gMonBackPic_Rattata[] = INCBIN_U32("graphics/pokemon/rattata/back.4bpp.lz");
    const u32 gMonShinyPalette_Rattata[] = INCBIN_U32("graphics/pokemon/rattata/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Rattata[] = INCBIN_U32("graphics/pokemon/rattata/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Rattata[] = INCBIN_U32("graphics/pokemon/rattata/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Rattata[] = INCBIN_U32("graphics/pokemon/rattata/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Rattata[] = INCBIN_U32("graphics/pokemon/rattata/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Rattata[] = INCBIN_U8("graphics/pokemon/rattata/icon.4bpp");
#else
    const u8 gMonIcon_Rattata[] = INCBIN_U8("graphics/pokemon/rattata/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Rattata[] = INCBIN_U8("graphics/pokemon/rattata/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Rattata[] = INCBIN_COMP("graphics/pokemon/rattata/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Rattata[] = INCBIN_U32("graphics/pokemon/rattata/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Rattata[] = INCBIN_U32("graphics/pokemon/rattata/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_RattataF[] = INCBIN_U32("graphics/pokemon/rattata/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_RattataF[] = INCBIN_U32("graphics/pokemon/rattata/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_RattataF[] = INCBIN_COMP("graphics/pokemon/rattata/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Raticate[] = INCBIN_U32("graphics/pokemon/raticate/anim_front.4bpp.lz");
    const u32 gMonPalette_Raticate[] = INCBIN_U32("graphics/pokemon/raticate/normal.gbapal.lz");
    const u32 gMonBackPic_Raticate[] = INCBIN_U32("graphics/pokemon/raticate/back.4bpp.lz");
    const u32 gMonShinyPalette_Raticate[] = INCBIN_U32("graphics/pokemon/raticate/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Raticate[] = INCBIN_U32("graphics/pokemon/raticate/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Raticate[] = INCBIN_U32("graphics/pokemon/raticate/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Raticate[] = INCBIN_U32("graphics/pokemon/raticate/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Raticate[] = INCBIN_U32("graphics/pokemon/raticate/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Raticate[] = INCBIN_U8("graphics/pokemon/raticate/icon.4bpp");
#else
    const u8 gMonIcon_Raticate[] = INCBIN_U8("graphics/pokemon/raticate/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Raticate[] = INCBIN_U8("graphics/pokemon/raticate/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Raticate[] = INCBIN_COMP("graphics/pokemon/raticate/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Raticate[] = INCBIN_U32("graphics/pokemon/raticate/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Raticate[] = INCBIN_U32("graphics/pokemon/raticate/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_RaticateF[] = INCBIN_U32("graphics/pokemon/raticate/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_RaticateF[] = INCBIN_U32("graphics/pokemon/raticate/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_RaticateF[] = INCBIN_COMP("graphics/pokemon/raticate/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_RATTATA

#if P_FAMILY_SPEAROW
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Spearow[] = INCBIN_U32("graphics/pokemon/spearow/anim_front.4bpp.lz");
    const u32 gMonPalette_Spearow[] = INCBIN_U32("graphics/pokemon/spearow/normal.gbapal.lz");
    const u32 gMonBackPic_Spearow[] = INCBIN_U32("graphics/pokemon/spearow/back.4bpp.lz");
    const u32 gMonShinyPalette_Spearow[] = INCBIN_U32("graphics/pokemon/spearow/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Spearow[] = INCBIN_U32("graphics/pokemon/spearow/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Spearow[] = INCBIN_U32("graphics/pokemon/spearow/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Spearow[] = INCBIN_U32("graphics/pokemon/spearow/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Spearow[] = INCBIN_U32("graphics/pokemon/spearow/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Spearow[] = INCBIN_U8("graphics/pokemon/spearow/icon.4bpp");
#else
    const u8 gMonIcon_Spearow[] = INCBIN_U8("graphics/pokemon/spearow/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Spearow[] = INCBIN_U8("graphics/pokemon/spearow/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Spearow[] = INCBIN_COMP("graphics/pokemon/spearow/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Spearow[] = INCBIN_U32("graphics/pokemon/spearow/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Spearow[] = INCBIN_U32("graphics/pokemon/spearow/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Fearow[] = INCBIN_U32("graphics/pokemon/fearow/anim_front.4bpp.lz");
    const u32 gMonPalette_Fearow[] = INCBIN_U32("graphics/pokemon/fearow/normal.gbapal.lz");
    const u32 gMonBackPic_Fearow[] = INCBIN_U32("graphics/pokemon/fearow/back.4bpp.lz");
    const u32 gMonShinyPalette_Fearow[] = INCBIN_U32("graphics/pokemon/fearow/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Fearow[] = INCBIN_U32("graphics/pokemon/fearow/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Fearow[] = INCBIN_U32("graphics/pokemon/fearow/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Fearow[] = INCBIN_U32("graphics/pokemon/fearow/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Fearow[] = INCBIN_U32("graphics/pokemon/fearow/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Fearow[] = INCBIN_U8("graphics/pokemon/fearow/icon.4bpp");
#else
    const u8 gMonIcon_Fearow[] = INCBIN_U8("graphics/pokemon/fearow/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Fearow[] = INCBIN_U8("graphics/pokemon/fearow/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Fearow[] = INCBIN_COMP("graphics/pokemon/fearow/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Fearow[] = INCBIN_U32("graphics/pokemon/fearow/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Fearow[] = INCBIN_U32("graphics/pokemon/fearow/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SPEAROW

#if P_FAMILY_EKANS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Ekans[] = INCBIN_U32("graphics/pokemon/ekans/anim_front.4bpp.lz");
    const u32 gMonPalette_Ekans[] = INCBIN_U32("graphics/pokemon/ekans/normal.gbapal.lz");
    const u32 gMonBackPic_Ekans[] = INCBIN_U32("graphics/pokemon/ekans/back.4bpp.lz");
    const u32 gMonShinyPalette_Ekans[] = INCBIN_U32("graphics/pokemon/ekans/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Ekans[] = INCBIN_U32("graphics/pokemon/ekans/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Ekans[] = INCBIN_U32("graphics/pokemon/ekans/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Ekans[] = INCBIN_U32("graphics/pokemon/ekans/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Ekans[] = INCBIN_U32("graphics/pokemon/ekans/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Ekans[] = INCBIN_U8("graphics/pokemon/ekans/icon.4bpp");
#else
    const u8 gMonIcon_Ekans[] = INCBIN_U8("graphics/pokemon/ekans/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Ekans[] = INCBIN_U8("graphics/pokemon/ekans/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Ekans[] = INCBIN_COMP("graphics/pokemon/ekans/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Ekans[] = INCBIN_U32("graphics/pokemon/ekans/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Ekans[] = INCBIN_U32("graphics/pokemon/ekans/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Arbok[] = INCBIN_U32("graphics/pokemon/arbok/anim_front.4bpp.lz");
    const u32 gMonPalette_Arbok[] = INCBIN_U32("graphics/pokemon/arbok/normal.gbapal.lz");
    const u32 gMonBackPic_Arbok[] = INCBIN_U32("graphics/pokemon/arbok/back.4bpp.lz");
    const u32 gMonShinyPalette_Arbok[] = INCBIN_U32("graphics/pokemon/arbok/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Arbok[] = INCBIN_U32("graphics/pokemon/arbok/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Arbok[] = INCBIN_U32("graphics/pokemon/arbok/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Arbok[] = INCBIN_U32("graphics/pokemon/arbok/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Arbok[] = INCBIN_U32("graphics/pokemon/arbok/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Arbok[] = INCBIN_U8("graphics/pokemon/arbok/icon.4bpp");
#else
    const u8 gMonIcon_Arbok[] = INCBIN_U8("graphics/pokemon/arbok/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Arbok[] = INCBIN_U8("graphics/pokemon/arbok/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Arbok[] = INCBIN_COMP("graphics/pokemon/arbok/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Arbok[] = INCBIN_U32("graphics/pokemon/arbok/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Arbok[] = INCBIN_U32("graphics/pokemon/arbok/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_EKANS

#if P_FAMILY_PIKACHU
#if P_GEN_2_CROSS_EVOS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Pichu[] = INCBIN_U32("graphics/pokemon/pichu/anim_front.4bpp.lz");
    const u32 gMonPalette_Pichu[] = INCBIN_U32("graphics/pokemon/pichu/normal.gbapal.lz");
    const u32 gMonBackPic_Pichu[] = INCBIN_U32("graphics/pokemon/pichu/back.4bpp.lz");
    const u32 gMonShinyPalette_Pichu[] = INCBIN_U32("graphics/pokemon/pichu/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Pichu[] = INCBIN_U32("graphics/pokemon/pichu/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Pichu[] = INCBIN_U32("graphics/pokemon/pichu/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Pichu[] = INCBIN_U32("graphics/pokemon/pichu/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Pichu[] = INCBIN_U32("graphics/pokemon/pichu/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Pichu[] = INCBIN_U8("graphics/pokemon/pichu/icon.4bpp");
#else
    const u8 gMonIcon_Pichu[] = INCBIN_U8("graphics/pokemon/pichu/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Pichu[] = INCBIN_U8("graphics/pokemon/pichu/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Pichu[] = INCBIN_COMP("graphics/pokemon/pichu/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Pichu[] = INCBIN_U32("graphics/pokemon/pichu/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Pichu[] = INCBIN_U32("graphics/pokemon/pichu/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_PichuSpikyEared[] = INCBIN_U32("graphics/pokemon/pichu/spiky_eared/anim_front.4bpp.lz");
    const u32 gMonPalette_PichuSpikyEared[] = INCBIN_U32("graphics/pokemon/pichu/spiky_eared/normal.gbapal.lz");
    const u32 gMonBackPic_PichuSpikyEared[] = INCBIN_U32("graphics/pokemon/pichu/spiky_eared/back.4bpp.lz");
    const u32 gMonShinyPalette_PichuSpikyEared[] = INCBIN_U32("graphics/pokemon/pichu/spiky_eared/shiny.gbapal.lz");
    const u8 gMonIcon_PichuSpikyEared[] = INCBIN_U8("graphics/pokemon/pichu/spiky_eared/icon.4bpp");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_PichuSpikyEared[] = INCBIN_COMP("graphics/pokemon/pichu/spiky_eared/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_PichuSpikyEared[] = INCBIN_U32("graphics/pokemon/pichu/spiky_eared/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_PichuSpikyEared[] = INCBIN_U32("graphics/pokemon/pichu/spiky_eared/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_2_CROSS_EVOS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Pikachu[] = INCBIN_U32("graphics/pokemon/pikachu/anim_front.4bpp.lz");
    const u32 gMonPalette_Pikachu[] = INCBIN_U32("graphics/pokemon/pikachu/normal.gbapal.lz");
    const u32 gMonBackPic_Pikachu[] = INCBIN_U32("graphics/pokemon/pikachu/back.4bpp.lz");
    const u32 gMonShinyPalette_Pikachu[] = INCBIN_U32("graphics/pokemon/pikachu/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Pikachu[] = INCBIN_U32("graphics/pokemon/pikachu/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Pikachu[] = INCBIN_U32("graphics/pokemon/pikachu/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Pikachu[] = INCBIN_U32("graphics/pokemon/pikachu/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Pikachu[] = INCBIN_U32("graphics/pokemon/pikachu/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Pikachu[] = INCBIN_U8("graphics/pokemon/pikachu/icon.4bpp");
#else
    const u8 gMonIcon_Pikachu[] = INCBIN_U8("graphics/pokemon/pikachu/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Pikachu[] = INCBIN_U8("graphics/pokemon/pikachu/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Pikachu[] = INCBIN_COMP("graphics/pokemon/pikachu/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Pikachu[] = INCBIN_U32("graphics/pokemon/pikachu/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Pikachu[] = INCBIN_U32("graphics/pokemon/pikachu/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_PikachuF[] = INCBIN_U32("graphics/pokemon/pikachu/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_PikachuF[] = INCBIN_U32("graphics/pokemon/pikachu/backf.4bpp.lz");
#if P_CUSTOM_GENDER_DIFF_ICONS
    const u8 gMonIcon_PikachuF[] = INCBIN_U8("graphics/pokemon/pikachu/iconf.4bpp");
#endif
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_PikachuF[] = INCBIN_COMP("graphics/pokemon/pikachu/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
    const u8 gMonIcon_PikachuStarter[] = INCBIN_U8("graphics/pokemon/pikachu/starter/icon.4bpp");
#if P_GENDER_DIFFERENCES && P_CUSTOM_GENDER_DIFF_ICONS
    const u8 gMonIcon_PikachuStarterF[] = INCBIN_U8("graphics/pokemon/pikachu/starter/iconf.4bpp");
#endif //P_GENDER_DIFFERENCES && P_CUSTOM_GENDER_DIFF_ICONS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Raichu[] = INCBIN_U32("graphics/pokemon/raichu/anim_front.4bpp.lz");
    const u32 gMonPalette_Raichu[] = INCBIN_U32("graphics/pokemon/raichu/normal.gbapal.lz");
    const u32 gMonBackPic_Raichu[] = INCBIN_U32("graphics/pokemon/raichu/back.4bpp.lz");
    const u32 gMonShinyPalette_Raichu[] = INCBIN_U32("graphics/pokemon/raichu/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Raichu[] = INCBIN_U32("graphics/pokemon/raichu/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Raichu[] = INCBIN_U32("graphics/pokemon/raichu/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Raichu[] = INCBIN_U32("graphics/pokemon/raichu/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Raichu[] = INCBIN_U32("graphics/pokemon/raichu/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Raichu[] = INCBIN_U8("graphics/pokemon/raichu/icon.4bpp");
#else
    const u8 gMonIcon_Raichu[] = INCBIN_U8("graphics/pokemon/raichu/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Raichu[] = INCBIN_U8("graphics/pokemon/raichu/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Raichu[] = INCBIN_COMP("graphics/pokemon/raichu/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Raichu[] = INCBIN_U32("graphics/pokemon/raichu/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Raichu[] = INCBIN_U32("graphics/pokemon/raichu/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_RaichuF[] = INCBIN_U32("graphics/pokemon/raichu/anim_frontf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_RaichuF[] = INCBIN_COMP("graphics/pokemon/raichu/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_PIKACHU

#if P_FAMILY_SANDSHREW
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Sandshrew[] = INCBIN_U32("graphics/pokemon/sandshrew/anim_front.4bpp.lz");
    const u32 gMonPalette_Sandshrew[] = INCBIN_U32("graphics/pokemon/sandshrew/normal.gbapal.lz");
    const u32 gMonBackPic_Sandshrew[] = INCBIN_U32("graphics/pokemon/sandshrew/back.4bpp.lz");
    const u32 gMonShinyPalette_Sandshrew[] = INCBIN_U32("graphics/pokemon/sandshrew/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Sandshrew[] = INCBIN_U32("graphics/pokemon/sandshrew/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Sandshrew[] = INCBIN_U32("graphics/pokemon/sandshrew/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Sandshrew[] = INCBIN_U32("graphics/pokemon/sandshrew/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Sandshrew[] = INCBIN_U32("graphics/pokemon/sandshrew/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Sandshrew[] = INCBIN_U8("graphics/pokemon/sandshrew/icon.4bpp");
#else
    const u8 gMonIcon_Sandshrew[] = INCBIN_U8("graphics/pokemon/sandshrew/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Sandshrew[] = INCBIN_U8("graphics/pokemon/sandshrew/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Sandshrew[] = INCBIN_COMP("graphics/pokemon/sandshrew/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Sandshrew[] = INCBIN_U32("graphics/pokemon/sandshrew/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Sandshrew[] = INCBIN_U32("graphics/pokemon/sandshrew/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Sandslash[] = INCBIN_U32("graphics/pokemon/sandslash/anim_front.4bpp.lz");
    const u32 gMonPalette_Sandslash[] = INCBIN_U32("graphics/pokemon/sandslash/normal.gbapal.lz");
    const u32 gMonBackPic_Sandslash[] = INCBIN_U32("graphics/pokemon/sandslash/back.4bpp.lz");
    const u32 gMonShinyPalette_Sandslash[] = INCBIN_U32("graphics/pokemon/sandslash/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Sandslash[] = INCBIN_U32("graphics/pokemon/sandslash/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Sandslash[] = INCBIN_U32("graphics/pokemon/sandslash/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Sandslash[] = INCBIN_U32("graphics/pokemon/sandslash/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Sandslash[] = INCBIN_U32("graphics/pokemon/sandslash/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Sandslash[] = INCBIN_U8("graphics/pokemon/sandslash/icon.4bpp");
#else
    const u8 gMonIcon_Sandslash[] = INCBIN_U8("graphics/pokemon/sandslash/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Sandslash[] = INCBIN_U8("graphics/pokemon/sandslash/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Sandslash[] = INCBIN_COMP("graphics/pokemon/sandslash/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Sandslash[] = INCBIN_U32("graphics/pokemon/sandslash/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Sandslash[] = INCBIN_U32("graphics/pokemon/sandslash/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SANDSHREW

#if P_FAMILY_NIDORAN
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_NidoranF[] = INCBIN_U32("graphics/pokemon/nidoran_f/anim_front.4bpp.lz");
    const u32 gMonPalette_NidoranF[] = INCBIN_U32("graphics/pokemon/nidoran_f/normal.gbapal.lz");
    const u32 gMonBackPic_NidoranF[] = INCBIN_U32("graphics/pokemon/nidoran_f/back.4bpp.lz");
    const u32 gMonShinyPalette_NidoranF[] = INCBIN_U32("graphics/pokemon/nidoran_f/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_NidoranF[] = INCBIN_U32("graphics/pokemon/nidoran_f/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_NidoranF[] = INCBIN_U32("graphics/pokemon/nidoran_f/normal_gba.gbapal.lz");
    const u32 gMonBackPic_NidoranF[] = INCBIN_U32("graphics/pokemon/nidoran_f/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_NidoranF[] = INCBIN_U32("graphics/pokemon/nidoran_f/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_NidoranF[] = INCBIN_U8("graphics/pokemon/nidoran_f/icon.4bpp");
#else
    const u8 gMonIcon_NidoranF[] = INCBIN_U8("graphics/pokemon/nidoran_f/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_NidoranF[] = INCBIN_U8("graphics/pokemon/nidoran_f/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_NidoranF[] = INCBIN_COMP("graphics/pokemon/nidoran_f/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_NidoranF[] = INCBIN_U32("graphics/pokemon/nidoran_f/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_NidoranF[] = INCBIN_U32("graphics/pokemon/nidoran_f/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Nidorina[] = INCBIN_U32("graphics/pokemon/nidorina/anim_front.4bpp.lz");
    const u32 gMonPalette_Nidorina[] = INCBIN_U32("graphics/pokemon/nidorina/normal.gbapal.lz");
    const u32 gMonBackPic_Nidorina[] = INCBIN_U32("graphics/pokemon/nidorina/back.4bpp.lz");
    const u32 gMonShinyPalette_Nidorina[] = INCBIN_U32("graphics/pokemon/nidorina/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Nidorina[] = INCBIN_U32("graphics/pokemon/nidorina/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Nidorina[] = INCBIN_U32("graphics/pokemon/nidorina/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Nidorina[] = INCBIN_U32("graphics/pokemon/nidorina/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Nidorina[] = INCBIN_U32("graphics/pokemon/nidorina/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Nidorina[] = INCBIN_U8("graphics/pokemon/nidorina/icon.4bpp");
#else
    const u8 gMonIcon_Nidorina[] = INCBIN_U8("graphics/pokemon/nidorina/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Nidorina[] = INCBIN_U8("graphics/pokemon/nidorina/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Nidorina[] = INCBIN_COMP("graphics/pokemon/nidorina/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Nidorina[] = INCBIN_U32("graphics/pokemon/nidorina/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Nidorina[] = INCBIN_U32("graphics/pokemon/nidorina/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Nidoqueen[] = INCBIN_U32("graphics/pokemon/nidoqueen/anim_front.4bpp.lz");
    const u32 gMonPalette_Nidoqueen[] = INCBIN_U32("graphics/pokemon/nidoqueen/normal.gbapal.lz");
    const u32 gMonBackPic_Nidoqueen[] = INCBIN_U32("graphics/pokemon/nidoqueen/back.4bpp.lz");
    const u32 gMonShinyPalette_Nidoqueen[] = INCBIN_U32("graphics/pokemon/nidoqueen/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Nidoqueen[] = INCBIN_U32("graphics/pokemon/nidoqueen/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Nidoqueen[] = INCBIN_U32("graphics/pokemon/nidoqueen/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Nidoqueen[] = INCBIN_U32("graphics/pokemon/nidoqueen/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Nidoqueen[] = INCBIN_U32("graphics/pokemon/nidoqueen/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Nidoqueen[] = INCBIN_U8("graphics/pokemon/nidoqueen/icon.4bpp");
#else
    const u8 gMonIcon_Nidoqueen[] = INCBIN_U8("graphics/pokemon/nidoqueen/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Nidoqueen[] = INCBIN_U8("graphics/pokemon/nidoqueen/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Nidoqueen[] = INCBIN_COMP("graphics/pokemon/nidoqueen/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Nidoqueen[] = INCBIN_U32("graphics/pokemon/nidoqueen/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Nidoqueen[] = INCBIN_U32("graphics/pokemon/nidoqueen/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_NidoranM[] = INCBIN_U32("graphics/pokemon/nidoran_m/anim_front.4bpp.lz");
    const u32 gMonPalette_NidoranM[] = INCBIN_U32("graphics/pokemon/nidoran_m/normal.gbapal.lz");
    const u32 gMonBackPic_NidoranM[] = INCBIN_U32("graphics/pokemon/nidoran_m/back.4bpp.lz");
    const u32 gMonShinyPalette_NidoranM[] = INCBIN_U32("graphics/pokemon/nidoran_m/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_NidoranM[] = INCBIN_U32("graphics/pokemon/nidoran_m/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_NidoranM[] = INCBIN_U32("graphics/pokemon/nidoran_m/normal_gba.gbapal.lz");
    const u32 gMonBackPic_NidoranM[] = INCBIN_U32("graphics/pokemon/nidoran_m/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_NidoranM[] = INCBIN_U32("graphics/pokemon/nidoran_m/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_NidoranM[] = INCBIN_U8("graphics/pokemon/nidoran_m/icon.4bpp");
#else
    const u8 gMonIcon_NidoranM[] = INCBIN_U8("graphics/pokemon/nidoran_m/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_NidoranM[] = INCBIN_U8("graphics/pokemon/nidoran_m/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_NidoranM[] = INCBIN_COMP("graphics/pokemon/nidoran_m/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_NidoranM[] = INCBIN_U32("graphics/pokemon/nidoran_m/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_NidoranM[] = INCBIN_U32("graphics/pokemon/nidoran_m/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Nidorino[] = INCBIN_U32("graphics/pokemon/nidorino/anim_front.4bpp.lz");
    const u32 gMonPalette_Nidorino[] = INCBIN_U32("graphics/pokemon/nidorino/normal.gbapal.lz");
    const u32 gMonBackPic_Nidorino[] = INCBIN_U32("graphics/pokemon/nidorino/back.4bpp.lz");
    const u32 gMonShinyPalette_Nidorino[] = INCBIN_U32("graphics/pokemon/nidorino/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Nidorino[] = INCBIN_U32("graphics/pokemon/nidorino/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Nidorino[] = INCBIN_U32("graphics/pokemon/nidorino/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Nidorino[] = INCBIN_U32("graphics/pokemon/nidorino/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Nidorino[] = INCBIN_U32("graphics/pokemon/nidorino/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Nidorino[] = INCBIN_U8("graphics/pokemon/nidorino/icon.4bpp");
#else
    const u8 gMonIcon_Nidorino[] = INCBIN_U8("graphics/pokemon/nidorino/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Nidorino[] = INCBIN_U8("graphics/pokemon/nidorino/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Nidorino[] = INCBIN_COMP("graphics/pokemon/nidorino/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Nidorino[] = INCBIN_U32("graphics/pokemon/nidorino/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Nidorino[] = INCBIN_U32("graphics/pokemon/nidorino/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Nidoking[] = INCBIN_U32("graphics/pokemon/nidoking/anim_front.4bpp.lz");
    const u32 gMonPalette_Nidoking[] = INCBIN_U32("graphics/pokemon/nidoking/normal.gbapal.lz");
    const u32 gMonBackPic_Nidoking[] = INCBIN_U32("graphics/pokemon/nidoking/back.4bpp.lz");
    const u32 gMonShinyPalette_Nidoking[] = INCBIN_U32("graphics/pokemon/nidoking/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Nidoking[] = INCBIN_U32("graphics/pokemon/nidoking/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Nidoking[] = INCBIN_U32("graphics/pokemon/nidoking/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Nidoking[] = INCBIN_U32("graphics/pokemon/nidoking/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Nidoking[] = INCBIN_U32("graphics/pokemon/nidoking/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Nidoking[] = INCBIN_U8("graphics/pokemon/nidoking/icon.4bpp");
#else
    const u8 gMonIcon_Nidoking[] = INCBIN_U8("graphics/pokemon/nidoking/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Nidoking[] = INCBIN_U8("graphics/pokemon/nidoking/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Nidoking[] = INCBIN_COMP("graphics/pokemon/nidoking/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Nidoking[] = INCBIN_U32("graphics/pokemon/nidoking/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Nidoking[] = INCBIN_U32("graphics/pokemon/nidoking/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_NIDORAN

#if P_FAMILY_CLEFAIRY
#if P_GEN_2_CROSS_EVOS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Cleffa[] = INCBIN_U32("graphics/pokemon/cleffa/anim_front.4bpp.lz");
    const u32 gMonPalette_Cleffa[] = INCBIN_U32("graphics/pokemon/cleffa/normal.gbapal.lz");
    const u32 gMonBackPic_Cleffa[] = INCBIN_U32("graphics/pokemon/cleffa/back.4bpp.lz");
    const u32 gMonShinyPalette_Cleffa[] = INCBIN_U32("graphics/pokemon/cleffa/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Cleffa[] = INCBIN_U32("graphics/pokemon/cleffa/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Cleffa[] = INCBIN_U32("graphics/pokemon/cleffa/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Cleffa[] = INCBIN_U32("graphics/pokemon/cleffa/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Cleffa[] = INCBIN_U32("graphics/pokemon/cleffa/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Cleffa[] = INCBIN_U8("graphics/pokemon/cleffa/icon.4bpp");
#else
    const u8 gMonIcon_Cleffa[] = INCBIN_U8("graphics/pokemon/cleffa/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Cleffa[] = INCBIN_U8("graphics/pokemon/cleffa/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Cleffa[] = INCBIN_COMP("graphics/pokemon/cleffa/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Cleffa[] = INCBIN_U32("graphics/pokemon/cleffa/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Cleffa[] = INCBIN_U32("graphics/pokemon/cleffa/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_2_CROSS_EVOS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Clefairy[] = INCBIN_U32("graphics/pokemon/clefairy/anim_front.4bpp.lz");
    const u32 gMonPalette_Clefairy[] = INCBIN_U32("graphics/pokemon/clefairy/normal.gbapal.lz");
    const u32 gMonBackPic_Clefairy[] = INCBIN_U32("graphics/pokemon/clefairy/back.4bpp.lz");
    const u32 gMonShinyPalette_Clefairy[] = INCBIN_U32("graphics/pokemon/clefairy/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Clefairy[] = INCBIN_U32("graphics/pokemon/clefairy/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Clefairy[] = INCBIN_U32("graphics/pokemon/clefairy/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Clefairy[] = INCBIN_U32("graphics/pokemon/clefairy/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Clefairy[] = INCBIN_U32("graphics/pokemon/clefairy/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Clefairy[] = INCBIN_U8("graphics/pokemon/clefairy/icon.4bpp");
#else
    const u8 gMonIcon_Clefairy[] = INCBIN_U8("graphics/pokemon/clefairy/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Clefairy[] = INCBIN_U8("graphics/pokemon/clefairy/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Clefairy[] = INCBIN_COMP("graphics/pokemon/clefairy/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Clefairy[] = INCBIN_U32("graphics/pokemon/clefairy/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Clefairy[] = INCBIN_U32("graphics/pokemon/clefairy/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Clefable[] = INCBIN_U32("graphics/pokemon/clefable/anim_front.4bpp.lz");
    const u32 gMonPalette_Clefable[] = INCBIN_U32("graphics/pokemon/clefable/normal.gbapal.lz");
    const u32 gMonBackPic_Clefable[] = INCBIN_U32("graphics/pokemon/clefable/back.4bpp.lz");
    const u32 gMonShinyPalette_Clefable[] = INCBIN_U32("graphics/pokemon/clefable/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Clefable[] = INCBIN_U32("graphics/pokemon/clefable/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Clefable[] = INCBIN_U32("graphics/pokemon/clefable/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Clefable[] = INCBIN_U32("graphics/pokemon/clefable/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Clefable[] = INCBIN_U32("graphics/pokemon/clefable/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Clefable[] = INCBIN_U8("graphics/pokemon/clefable/icon.4bpp");
#else
    const u8 gMonIcon_Clefable[] = INCBIN_U8("graphics/pokemon/clefable/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Clefable[] = INCBIN_U8("graphics/pokemon/clefable/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Clefable[] = INCBIN_COMP("graphics/pokemon/clefable/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Clefable[] = INCBIN_U32("graphics/pokemon/clefable/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Clefable[] = INCBIN_U32("graphics/pokemon/clefable/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_CLEFAIRY

#if P_FAMILY_VULPIX
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Vulpix[] = INCBIN_U32("graphics/pokemon/vulpix/anim_front.4bpp.lz");
    const u32 gMonPalette_Vulpix[] = INCBIN_U32("graphics/pokemon/vulpix/normal.gbapal.lz");
    const u32 gMonBackPic_Vulpix[] = INCBIN_U32("graphics/pokemon/vulpix/back.4bpp.lz");
    const u32 gMonShinyPalette_Vulpix[] = INCBIN_U32("graphics/pokemon/vulpix/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Vulpix[] = INCBIN_U32("graphics/pokemon/vulpix/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Vulpix[] = INCBIN_U32("graphics/pokemon/vulpix/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Vulpix[] = INCBIN_U32("graphics/pokemon/vulpix/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Vulpix[] = INCBIN_U32("graphics/pokemon/vulpix/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Vulpix[] = INCBIN_U8("graphics/pokemon/vulpix/icon.4bpp");
#else
    const u8 gMonIcon_Vulpix[] = INCBIN_U8("graphics/pokemon/vulpix/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Vulpix[] = INCBIN_U8("graphics/pokemon/vulpix/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Vulpix[] = INCBIN_COMP("graphics/pokemon/vulpix/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Vulpix[] = INCBIN_U32("graphics/pokemon/vulpix/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Vulpix[] = INCBIN_U32("graphics/pokemon/vulpix/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Ninetales[] = INCBIN_U32("graphics/pokemon/ninetales/anim_front.4bpp.lz");
    const u32 gMonPalette_Ninetales[] = INCBIN_U32("graphics/pokemon/ninetales/normal.gbapal.lz");
    const u32 gMonBackPic_Ninetales[] = INCBIN_U32("graphics/pokemon/ninetales/back.4bpp.lz");
    const u32 gMonShinyPalette_Ninetales[] = INCBIN_U32("graphics/pokemon/ninetales/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Ninetales[] = INCBIN_U32("graphics/pokemon/ninetales/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Ninetales[] = INCBIN_U32("graphics/pokemon/ninetales/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Ninetales[] = INCBIN_U32("graphics/pokemon/ninetales/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Ninetales[] = INCBIN_U32("graphics/pokemon/ninetales/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Ninetales[] = INCBIN_U8("graphics/pokemon/ninetales/icon.4bpp");
#else
    const u8 gMonIcon_Ninetales[] = INCBIN_U8("graphics/pokemon/ninetales/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Ninetales[] = INCBIN_U8("graphics/pokemon/ninetales/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Ninetales[] = INCBIN_COMP("graphics/pokemon/ninetales/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Ninetales[] = INCBIN_U32("graphics/pokemon/ninetales/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Ninetales[] = INCBIN_U32("graphics/pokemon/ninetales/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_VULPIX

#if P_FAMILY_JIGGLYPUFF
#if P_GEN_2_CROSS_EVOS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Igglybuff[] = INCBIN_U32("graphics/pokemon/igglybuff/anim_front.4bpp.lz");
    const u32 gMonPalette_Igglybuff[] = INCBIN_U32("graphics/pokemon/igglybuff/normal.gbapal.lz");
    const u32 gMonBackPic_Igglybuff[] = INCBIN_U32("graphics/pokemon/igglybuff/back.4bpp.lz");
    const u32 gMonShinyPalette_Igglybuff[] = INCBIN_U32("graphics/pokemon/igglybuff/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Igglybuff[] = INCBIN_U32("graphics/pokemon/igglybuff/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Igglybuff[] = INCBIN_U32("graphics/pokemon/igglybuff/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Igglybuff[] = INCBIN_U32("graphics/pokemon/igglybuff/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Igglybuff[] = INCBIN_U32("graphics/pokemon/igglybuff/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Igglybuff[] = INCBIN_U8("graphics/pokemon/igglybuff/icon.4bpp");
#else
    const u8 gMonIcon_Igglybuff[] = INCBIN_U8("graphics/pokemon/igglybuff/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Igglybuff[] = INCBIN_U8("graphics/pokemon/igglybuff/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Igglybuff[] = INCBIN_COMP("graphics/pokemon/igglybuff/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Igglybuff[] = INCBIN_U32("graphics/pokemon/igglybuff/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Igglybuff[] = INCBIN_U32("graphics/pokemon/igglybuff/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_2_CROSS_EVOS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Jigglypuff[] = INCBIN_U32("graphics/pokemon/jigglypuff/anim_front.4bpp.lz");
    const u32 gMonPalette_Jigglypuff[] = INCBIN_U32("graphics/pokemon/jigglypuff/normal.gbapal.lz");
    const u32 gMonBackPic_Jigglypuff[] = INCBIN_U32("graphics/pokemon/jigglypuff/back.4bpp.lz");
    const u32 gMonShinyPalette_Jigglypuff[] = INCBIN_U32("graphics/pokemon/jigglypuff/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Jigglypuff[] = INCBIN_U32("graphics/pokemon/jigglypuff/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Jigglypuff[] = INCBIN_U32("graphics/pokemon/jigglypuff/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Jigglypuff[] = INCBIN_U32("graphics/pokemon/jigglypuff/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Jigglypuff[] = INCBIN_U32("graphics/pokemon/jigglypuff/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Jigglypuff[] = INCBIN_U8("graphics/pokemon/jigglypuff/icon.4bpp");
#else
    const u8 gMonIcon_Jigglypuff[] = INCBIN_U8("graphics/pokemon/jigglypuff/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Jigglypuff[] = INCBIN_U8("graphics/pokemon/jigglypuff/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Jigglypuff[] = INCBIN_COMP("graphics/pokemon/jigglypuff/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Jigglypuff[] = INCBIN_U32("graphics/pokemon/jigglypuff/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Jigglypuff[] = INCBIN_U32("graphics/pokemon/jigglypuff/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Wigglytuff[] = INCBIN_U32("graphics/pokemon/wigglytuff/anim_front.4bpp.lz");
    const u32 gMonPalette_Wigglytuff[] = INCBIN_U32("graphics/pokemon/wigglytuff/normal.gbapal.lz");
    const u32 gMonBackPic_Wigglytuff[] = INCBIN_U32("graphics/pokemon/wigglytuff/back.4bpp.lz");
    const u32 gMonShinyPalette_Wigglytuff[] = INCBIN_U32("graphics/pokemon/wigglytuff/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Wigglytuff[] = INCBIN_U32("graphics/pokemon/wigglytuff/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Wigglytuff[] = INCBIN_U32("graphics/pokemon/wigglytuff/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Wigglytuff[] = INCBIN_U32("graphics/pokemon/wigglytuff/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Wigglytuff[] = INCBIN_U32("graphics/pokemon/wigglytuff/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Wigglytuff[] = INCBIN_U8("graphics/pokemon/wigglytuff/icon.4bpp");
#else
    const u8 gMonIcon_Wigglytuff[] = INCBIN_U8("graphics/pokemon/wigglytuff/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Wigglytuff[] = INCBIN_U8("graphics/pokemon/wigglytuff/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Wigglytuff[] = INCBIN_COMP("graphics/pokemon/wigglytuff/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Wigglytuff[] = INCBIN_U32("graphics/pokemon/wigglytuff/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Wigglytuff[] = INCBIN_U32("graphics/pokemon/wigglytuff/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_JIGGLYPUFF

#if P_FAMILY_ZUBAT
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Zubat[] = INCBIN_U32("graphics/pokemon/zubat/anim_front.4bpp.lz");
    const u32 gMonPalette_Zubat[] = INCBIN_U32("graphics/pokemon/zubat/normal.gbapal.lz");
    const u32 gMonBackPic_Zubat[] = INCBIN_U32("graphics/pokemon/zubat/back.4bpp.lz");
    const u32 gMonShinyPalette_Zubat[] = INCBIN_U32("graphics/pokemon/zubat/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Zubat[] = INCBIN_U32("graphics/pokemon/zubat/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Zubat[] = INCBIN_U32("graphics/pokemon/zubat/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Zubat[] = INCBIN_U32("graphics/pokemon/zubat/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Zubat[] = INCBIN_U32("graphics/pokemon/zubat/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Zubat[] = INCBIN_U8("graphics/pokemon/zubat/icon.4bpp");
#else
    const u8 gMonIcon_Zubat[] = INCBIN_U8("graphics/pokemon/zubat/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Zubat[] = INCBIN_U8("graphics/pokemon/zubat/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Zubat[] = INCBIN_COMP("graphics/pokemon/zubat/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Zubat[] = INCBIN_U32("graphics/pokemon/zubat/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Zubat[] = INCBIN_U32("graphics/pokemon/zubat/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_ZubatF[] = INCBIN_U32("graphics/pokemon/zubat/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_ZubatF[] = INCBIN_U32("graphics/pokemon/zubat/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_ZubatF[] = INCBIN_COMP("graphics/pokemon/zubat/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Golbat[] = INCBIN_U32("graphics/pokemon/golbat/anim_front.4bpp.lz");
    const u32 gMonPalette_Golbat[] = INCBIN_U32("graphics/pokemon/golbat/normal.gbapal.lz");
    const u32 gMonBackPic_Golbat[] = INCBIN_U32("graphics/pokemon/golbat/back.4bpp.lz");
    const u32 gMonShinyPalette_Golbat[] = INCBIN_U32("graphics/pokemon/golbat/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Golbat[] = INCBIN_U32("graphics/pokemon/golbat/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Golbat[] = INCBIN_U32("graphics/pokemon/golbat/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Golbat[] = INCBIN_U32("graphics/pokemon/golbat/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Golbat[] = INCBIN_U32("graphics/pokemon/golbat/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Golbat[] = INCBIN_U8("graphics/pokemon/golbat/icon.4bpp");
#else
    const u8 gMonIcon_Golbat[] = INCBIN_U8("graphics/pokemon/golbat/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Golbat[] = INCBIN_U8("graphics/pokemon/golbat/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Golbat[] = INCBIN_COMP("graphics/pokemon/golbat/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Golbat[] = INCBIN_U32("graphics/pokemon/golbat/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Golbat[] = INCBIN_U32("graphics/pokemon/golbat/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_GolbatF[] = INCBIN_U32("graphics/pokemon/golbat/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_GolbatF[] = INCBIN_U32("graphics/pokemon/golbat/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_GolbatF[] = INCBIN_COMP("graphics/pokemon/golbat/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if P_GEN_2_CROSS_EVOS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Crobat[] = INCBIN_U32("graphics/pokemon/crobat/anim_front.4bpp.lz");
    const u32 gMonPalette_Crobat[] = INCBIN_U32("graphics/pokemon/crobat/normal.gbapal.lz");
    const u32 gMonBackPic_Crobat[] = INCBIN_U32("graphics/pokemon/crobat/back.4bpp.lz");
    const u32 gMonShinyPalette_Crobat[] = INCBIN_U32("graphics/pokemon/crobat/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Crobat[] = INCBIN_U32("graphics/pokemon/crobat/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Crobat[] = INCBIN_U32("graphics/pokemon/crobat/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Crobat[] = INCBIN_U32("graphics/pokemon/crobat/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Crobat[] = INCBIN_U32("graphics/pokemon/crobat/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Crobat[] = INCBIN_U8("graphics/pokemon/crobat/icon.4bpp");
#else
    const u8 gMonIcon_Crobat[] = INCBIN_U8("graphics/pokemon/crobat/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Crobat[] = INCBIN_U8("graphics/pokemon/crobat/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Crobat[] = INCBIN_COMP("graphics/pokemon/crobat/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Crobat[] = INCBIN_U32("graphics/pokemon/crobat/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Crobat[] = INCBIN_U32("graphics/pokemon/crobat/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_2_CROSS_EVOS
#endif //P_FAMILY_ZUBAT

#if P_FAMILY_ODDISH
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Oddish[] = INCBIN_U32("graphics/pokemon/oddish/anim_front.4bpp.lz");
    const u32 gMonPalette_Oddish[] = INCBIN_U32("graphics/pokemon/oddish/normal.gbapal.lz");
    const u32 gMonBackPic_Oddish[] = INCBIN_U32("graphics/pokemon/oddish/back.4bpp.lz");
    const u32 gMonShinyPalette_Oddish[] = INCBIN_U32("graphics/pokemon/oddish/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Oddish[] = INCBIN_U32("graphics/pokemon/oddish/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Oddish[] = INCBIN_U32("graphics/pokemon/oddish/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Oddish[] = INCBIN_U32("graphics/pokemon/oddish/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Oddish[] = INCBIN_U32("graphics/pokemon/oddish/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Oddish[] = INCBIN_U8("graphics/pokemon/oddish/icon.4bpp");
#else
    const u8 gMonIcon_Oddish[] = INCBIN_U8("graphics/pokemon/oddish/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Oddish[] = INCBIN_U8("graphics/pokemon/oddish/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Oddish[] = INCBIN_COMP("graphics/pokemon/oddish/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Oddish[] = INCBIN_U32("graphics/pokemon/oddish/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Oddish[] = INCBIN_U32("graphics/pokemon/oddish/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Gloom[] = INCBIN_U32("graphics/pokemon/gloom/anim_front.4bpp.lz");
    const u32 gMonPalette_Gloom[] = INCBIN_U32("graphics/pokemon/gloom/normal.gbapal.lz");
    const u32 gMonBackPic_Gloom[] = INCBIN_U32("graphics/pokemon/gloom/back.4bpp.lz");
    const u32 gMonShinyPalette_Gloom[] = INCBIN_U32("graphics/pokemon/gloom/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Gloom[] = INCBIN_U32("graphics/pokemon/gloom/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Gloom[] = INCBIN_U32("graphics/pokemon/gloom/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Gloom[] = INCBIN_U32("graphics/pokemon/gloom/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Gloom[] = INCBIN_U32("graphics/pokemon/gloom/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Gloom[] = INCBIN_U8("graphics/pokemon/gloom/icon.4bpp");
#else
    const u8 gMonIcon_Gloom[] = INCBIN_U8("graphics/pokemon/gloom/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Gloom[] = INCBIN_U8("graphics/pokemon/gloom/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Gloom[] = INCBIN_COMP("graphics/pokemon/gloom/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Gloom[] = INCBIN_U32("graphics/pokemon/gloom/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Gloom[] = INCBIN_U32("graphics/pokemon/gloom/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_GloomF[] = INCBIN_U32("graphics/pokemon/gloom/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_GloomF[] = INCBIN_U32("graphics/pokemon/gloom/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_GloomF[] = INCBIN_COMP("graphics/pokemon/gloom/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Vileplume[] = INCBIN_U32("graphics/pokemon/vileplume/anim_front.4bpp.lz");
    const u32 gMonPalette_Vileplume[] = INCBIN_U32("graphics/pokemon/vileplume/normal.gbapal.lz");
    const u32 gMonBackPic_Vileplume[] = INCBIN_U32("graphics/pokemon/vileplume/back.4bpp.lz");
    const u32 gMonShinyPalette_Vileplume[] = INCBIN_U32("graphics/pokemon/vileplume/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Vileplume[] = INCBIN_U32("graphics/pokemon/vileplume/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Vileplume[] = INCBIN_U32("graphics/pokemon/vileplume/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Vileplume[] = INCBIN_U32("graphics/pokemon/vileplume/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Vileplume[] = INCBIN_U32("graphics/pokemon/vileplume/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Vileplume[] = INCBIN_U8("graphics/pokemon/vileplume/icon.4bpp");
#else
    const u8 gMonIcon_Vileplume[] = INCBIN_U8("graphics/pokemon/vileplume/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Vileplume[] = INCBIN_U8("graphics/pokemon/vileplume/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Vileplume[] = INCBIN_COMP("graphics/pokemon/vileplume/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Vileplume[] = INCBIN_U32("graphics/pokemon/vileplume/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Vileplume[] = INCBIN_U32("graphics/pokemon/vileplume/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_VileplumeF[] = INCBIN_U32("graphics/pokemon/vileplume/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_VileplumeF[] = INCBIN_U32("graphics/pokemon/vileplume/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_VileplumeF[] = INCBIN_COMP("graphics/pokemon/vileplume/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if P_GEN_2_CROSS_EVOS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Bellossom[] = INCBIN_U32("graphics/pokemon/bellossom/anim_front.4bpp.lz");
    const u32 gMonPalette_Bellossom[] = INCBIN_U32("graphics/pokemon/bellossom/normal.gbapal.lz");
    const u32 gMonBackPic_Bellossom[] = INCBIN_U32("graphics/pokemon/bellossom/back.4bpp.lz");
    const u32 gMonShinyPalette_Bellossom[] = INCBIN_U32("graphics/pokemon/bellossom/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Bellossom[] = INCBIN_U32("graphics/pokemon/bellossom/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Bellossom[] = INCBIN_U32("graphics/pokemon/bellossom/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Bellossom[] = INCBIN_U32("graphics/pokemon/bellossom/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Bellossom[] = INCBIN_U32("graphics/pokemon/bellossom/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Bellossom[] = INCBIN_U8("graphics/pokemon/bellossom/icon.4bpp");
#else
    const u8 gMonIcon_Bellossom[] = INCBIN_U8("graphics/pokemon/bellossom/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Bellossom[] = INCBIN_U8("graphics/pokemon/bellossom/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Bellossom[] = INCBIN_COMP("graphics/pokemon/bellossom/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Bellossom[] = INCBIN_U32("graphics/pokemon/bellossom/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Bellossom[] = INCBIN_U32("graphics/pokemon/bellossom/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_2_CROSS_EVOS
#endif //P_FAMILY_ODDISH

#if P_FAMILY_PARAS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Paras[] = INCBIN_U32("graphics/pokemon/paras/anim_front.4bpp.lz");
    const u32 gMonPalette_Paras[] = INCBIN_U32("graphics/pokemon/paras/normal.gbapal.lz");
    const u32 gMonBackPic_Paras[] = INCBIN_U32("graphics/pokemon/paras/back.4bpp.lz");
    const u32 gMonShinyPalette_Paras[] = INCBIN_U32("graphics/pokemon/paras/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Paras[] = INCBIN_U32("graphics/pokemon/paras/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Paras[] = INCBIN_U32("graphics/pokemon/paras/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Paras[] = INCBIN_U32("graphics/pokemon/paras/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Paras[] = INCBIN_U32("graphics/pokemon/paras/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Paras[] = INCBIN_U8("graphics/pokemon/paras/icon.4bpp");
#else
    const u8 gMonIcon_Paras[] = INCBIN_U8("graphics/pokemon/paras/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Paras[] = INCBIN_U8("graphics/pokemon/paras/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Paras[] = INCBIN_COMP("graphics/pokemon/paras/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Paras[] = INCBIN_U32("graphics/pokemon/paras/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Paras[] = INCBIN_U32("graphics/pokemon/paras/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Parasect[] = INCBIN_U32("graphics/pokemon/parasect/anim_front.4bpp.lz");
    const u32 gMonPalette_Parasect[] = INCBIN_U32("graphics/pokemon/parasect/normal.gbapal.lz");
    const u32 gMonBackPic_Parasect[] = INCBIN_U32("graphics/pokemon/parasect/back.4bpp.lz");
    const u32 gMonShinyPalette_Parasect[] = INCBIN_U32("graphics/pokemon/parasect/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Parasect[] = INCBIN_U32("graphics/pokemon/parasect/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Parasect[] = INCBIN_U32("graphics/pokemon/parasect/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Parasect[] = INCBIN_U32("graphics/pokemon/parasect/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Parasect[] = INCBIN_U32("graphics/pokemon/parasect/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Parasect[] = INCBIN_U8("graphics/pokemon/parasect/icon.4bpp");
#else
    const u8 gMonIcon_Parasect[] = INCBIN_U8("graphics/pokemon/parasect/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Parasect[] = INCBIN_U8("graphics/pokemon/parasect/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Parasect[] = INCBIN_COMP("graphics/pokemon/parasect/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Parasect[] = INCBIN_U32("graphics/pokemon/parasect/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Parasect[] = INCBIN_U32("graphics/pokemon/parasect/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_PARAS

#if P_FAMILY_VENONAT
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Venonat[] = INCBIN_U32("graphics/pokemon/venonat/anim_front.4bpp.lz");
    const u32 gMonPalette_Venonat[] = INCBIN_U32("graphics/pokemon/venonat/normal.gbapal.lz");
    const u32 gMonBackPic_Venonat[] = INCBIN_U32("graphics/pokemon/venonat/back.4bpp.lz");
    const u32 gMonShinyPalette_Venonat[] = INCBIN_U32("graphics/pokemon/venonat/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Venonat[] = INCBIN_U32("graphics/pokemon/venonat/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Venonat[] = INCBIN_U32("graphics/pokemon/venonat/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Venonat[] = INCBIN_U32("graphics/pokemon/venonat/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Venonat[] = INCBIN_U32("graphics/pokemon/venonat/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Venonat[] = INCBIN_U8("graphics/pokemon/venonat/icon.4bpp");
#else
    const u8 gMonIcon_Venonat[] = INCBIN_U8("graphics/pokemon/venonat/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Venonat[] = INCBIN_U8("graphics/pokemon/venonat/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Venonat[] = INCBIN_COMP("graphics/pokemon/venonat/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Venonat[] = INCBIN_U32("graphics/pokemon/venonat/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Venonat[] = INCBIN_U32("graphics/pokemon/venonat/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Venomoth[] = INCBIN_U32("graphics/pokemon/venomoth/anim_front.4bpp.lz");
    const u32 gMonPalette_Venomoth[] = INCBIN_U32("graphics/pokemon/venomoth/normal.gbapal.lz");
    const u32 gMonBackPic_Venomoth[] = INCBIN_U32("graphics/pokemon/venomoth/back.4bpp.lz");
    const u32 gMonShinyPalette_Venomoth[] = INCBIN_U32("graphics/pokemon/venomoth/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Venomoth[] = INCBIN_U32("graphics/pokemon/venomoth/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Venomoth[] = INCBIN_U32("graphics/pokemon/venomoth/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Venomoth[] = INCBIN_U32("graphics/pokemon/venomoth/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Venomoth[] = INCBIN_U32("graphics/pokemon/venomoth/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Venomoth[] = INCBIN_U8("graphics/pokemon/venomoth/icon.4bpp");
#else
    const u8 gMonIcon_Venomoth[] = INCBIN_U8("graphics/pokemon/venomoth/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Venomoth[] = INCBIN_U8("graphics/pokemon/venomoth/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Venomoth[] = INCBIN_COMP("graphics/pokemon/venomoth/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Venomoth[] = INCBIN_U32("graphics/pokemon/venomoth/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Venomoth[] = INCBIN_U32("graphics/pokemon/venomoth/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_VENONAT

#if P_FAMILY_DIGLETT
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Diglett[] = INCBIN_U32("graphics/pokemon/diglett/anim_front.4bpp.lz");
    const u32 gMonPalette_Diglett[] = INCBIN_U32("graphics/pokemon/diglett/normal.gbapal.lz");
    const u32 gMonBackPic_Diglett[] = INCBIN_U32("graphics/pokemon/diglett/back.4bpp.lz");
    const u32 gMonShinyPalette_Diglett[] = INCBIN_U32("graphics/pokemon/diglett/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Diglett[] = INCBIN_U32("graphics/pokemon/diglett/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Diglett[] = INCBIN_U32("graphics/pokemon/diglett/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Diglett[] = INCBIN_U32("graphics/pokemon/diglett/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Diglett[] = INCBIN_U32("graphics/pokemon/diglett/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Diglett[] = INCBIN_U8("graphics/pokemon/diglett/icon.4bpp");
#else
    const u8 gMonIcon_Diglett[] = INCBIN_U8("graphics/pokemon/diglett/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Diglett[] = INCBIN_U8("graphics/pokemon/diglett/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Diglett[] = INCBIN_COMP("graphics/pokemon/diglett/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Diglett[] = INCBIN_U32("graphics/pokemon/diglett/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Diglett[] = INCBIN_U32("graphics/pokemon/diglett/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Dugtrio[] = INCBIN_U32("graphics/pokemon/dugtrio/anim_front.4bpp.lz");
    const u32 gMonPalette_Dugtrio[] = INCBIN_U32("graphics/pokemon/dugtrio/normal.gbapal.lz");
    const u32 gMonBackPic_Dugtrio[] = INCBIN_U32("graphics/pokemon/dugtrio/back.4bpp.lz");
    const u32 gMonShinyPalette_Dugtrio[] = INCBIN_U32("graphics/pokemon/dugtrio/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Dugtrio[] = INCBIN_U32("graphics/pokemon/dugtrio/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Dugtrio[] = INCBIN_U32("graphics/pokemon/dugtrio/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Dugtrio[] = INCBIN_U32("graphics/pokemon/dugtrio/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Dugtrio[] = INCBIN_U32("graphics/pokemon/dugtrio/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Dugtrio[] = INCBIN_U8("graphics/pokemon/dugtrio/icon.4bpp");
#else
    const u8 gMonIcon_Dugtrio[] = INCBIN_U8("graphics/pokemon/dugtrio/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Dugtrio[] = INCBIN_U8("graphics/pokemon/dugtrio/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Dugtrio[] = INCBIN_COMP("graphics/pokemon/dugtrio/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Dugtrio[] = INCBIN_U32("graphics/pokemon/dugtrio/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Dugtrio[] = INCBIN_U32("graphics/pokemon/dugtrio/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_DIGLETT

#if P_FAMILY_MEOWTH
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Meowth[] = INCBIN_U32("graphics/pokemon/meowth/anim_front.4bpp.lz");
    const u32 gMonPalette_Meowth[] = INCBIN_U32("graphics/pokemon/meowth/normal.gbapal.lz");
    const u32 gMonBackPic_Meowth[] = INCBIN_U32("graphics/pokemon/meowth/back.4bpp.lz");
    const u32 gMonShinyPalette_Meowth[] = INCBIN_U32("graphics/pokemon/meowth/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Meowth[] = INCBIN_U32("graphics/pokemon/meowth/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Meowth[] = INCBIN_U32("graphics/pokemon/meowth/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Meowth[] = INCBIN_U32("graphics/pokemon/meowth/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Meowth[] = INCBIN_U32("graphics/pokemon/meowth/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Meowth[] = INCBIN_U8("graphics/pokemon/meowth/icon.4bpp");
#else
    const u8 gMonIcon_Meowth[] = INCBIN_U8("graphics/pokemon/meowth/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Meowth[] = INCBIN_U8("graphics/pokemon/meowth/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Meowth[] = INCBIN_COMP("graphics/pokemon/meowth/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Meowth[] = INCBIN_U32("graphics/pokemon/meowth/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Meowth[] = INCBIN_U32("graphics/pokemon/meowth/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Persian[] = INCBIN_U32("graphics/pokemon/persian/anim_front.4bpp.lz");
    const u32 gMonPalette_Persian[] = INCBIN_U32("graphics/pokemon/persian/normal.gbapal.lz");
    const u32 gMonBackPic_Persian[] = INCBIN_U32("graphics/pokemon/persian/back.4bpp.lz");
    const u32 gMonShinyPalette_Persian[] = INCBIN_U32("graphics/pokemon/persian/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Persian[] = INCBIN_U32("graphics/pokemon/persian/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Persian[] = INCBIN_U32("graphics/pokemon/persian/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Persian[] = INCBIN_U32("graphics/pokemon/persian/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Persian[] = INCBIN_U32("graphics/pokemon/persian/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Persian[] = INCBIN_U8("graphics/pokemon/persian/icon.4bpp");
#else
    const u8 gMonIcon_Persian[] = INCBIN_U8("graphics/pokemon/persian/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Persian[] = INCBIN_U8("graphics/pokemon/persian/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Persian[] = INCBIN_COMP("graphics/pokemon/persian/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Persian[] = INCBIN_U32("graphics/pokemon/persian/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Persian[] = INCBIN_U32("graphics/pokemon/persian/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_MEOWTH

#if P_FAMILY_PSYDUCK
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Psyduck[] = INCBIN_U32("graphics/pokemon/psyduck/anim_front.4bpp.lz");
    const u32 gMonPalette_Psyduck[] = INCBIN_U32("graphics/pokemon/psyduck/normal.gbapal.lz");
    const u32 gMonBackPic_Psyduck[] = INCBIN_U32("graphics/pokemon/psyduck/back.4bpp.lz");
    const u32 gMonShinyPalette_Psyduck[] = INCBIN_U32("graphics/pokemon/psyduck/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Psyduck[] = INCBIN_U32("graphics/pokemon/psyduck/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Psyduck[] = INCBIN_U32("graphics/pokemon/psyduck/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Psyduck[] = INCBIN_U32("graphics/pokemon/psyduck/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Psyduck[] = INCBIN_U32("graphics/pokemon/psyduck/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Psyduck[] = INCBIN_U8("graphics/pokemon/psyduck/icon.4bpp");
#else
    const u8 gMonIcon_Psyduck[] = INCBIN_U8("graphics/pokemon/psyduck/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Psyduck[] = INCBIN_U8("graphics/pokemon/psyduck/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Psyduck[] = INCBIN_COMP("graphics/pokemon/psyduck/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Psyduck[] = INCBIN_U32("graphics/pokemon/psyduck/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Psyduck[] = INCBIN_U32("graphics/pokemon/psyduck/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Golduck[] = INCBIN_U32("graphics/pokemon/golduck/anim_front.4bpp.lz");
    const u32 gMonPalette_Golduck[] = INCBIN_U32("graphics/pokemon/golduck/normal.gbapal.lz");
    const u32 gMonBackPic_Golduck[] = INCBIN_U32("graphics/pokemon/golduck/back.4bpp.lz");
    const u32 gMonShinyPalette_Golduck[] = INCBIN_U32("graphics/pokemon/golduck/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Golduck[] = INCBIN_U32("graphics/pokemon/golduck/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Golduck[] = INCBIN_U32("graphics/pokemon/golduck/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Golduck[] = INCBIN_U32("graphics/pokemon/golduck/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Golduck[] = INCBIN_U32("graphics/pokemon/golduck/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Golduck[] = INCBIN_U8("graphics/pokemon/golduck/icon.4bpp");
#else
    const u8 gMonIcon_Golduck[] = INCBIN_U8("graphics/pokemon/golduck/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Golduck[] = INCBIN_U8("graphics/pokemon/golduck/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Golduck[] = INCBIN_COMP("graphics/pokemon/golduck/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Golduck[] = INCBIN_U32("graphics/pokemon/golduck/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Golduck[] = INCBIN_U32("graphics/pokemon/golduck/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_PSYDUCK

#if P_FAMILY_MANKEY
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Mankey[] = INCBIN_U32("graphics/pokemon/mankey/anim_front.4bpp.lz");
    const u32 gMonPalette_Mankey[] = INCBIN_U32("graphics/pokemon/mankey/normal.gbapal.lz");
    const u32 gMonBackPic_Mankey[] = INCBIN_U32("graphics/pokemon/mankey/back.4bpp.lz");
    const u32 gMonShinyPalette_Mankey[] = INCBIN_U32("graphics/pokemon/mankey/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Mankey[] = INCBIN_U32("graphics/pokemon/mankey/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Mankey[] = INCBIN_U32("graphics/pokemon/mankey/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Mankey[] = INCBIN_U32("graphics/pokemon/mankey/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Mankey[] = INCBIN_U32("graphics/pokemon/mankey/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Mankey[] = INCBIN_U8("graphics/pokemon/mankey/icon.4bpp");
#else
    const u8 gMonIcon_Mankey[] = INCBIN_U8("graphics/pokemon/mankey/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Mankey[] = INCBIN_U8("graphics/pokemon/mankey/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Mankey[] = INCBIN_COMP("graphics/pokemon/mankey/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Mankey[] = INCBIN_U32("graphics/pokemon/mankey/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Mankey[] = INCBIN_U32("graphics/pokemon/mankey/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Primeape[] = INCBIN_U32("graphics/pokemon/primeape/anim_front.4bpp.lz");
    const u32 gMonPalette_Primeape[] = INCBIN_U32("graphics/pokemon/primeape/normal.gbapal.lz");
    const u32 gMonBackPic_Primeape[] = INCBIN_U32("graphics/pokemon/primeape/back.4bpp.lz");
    const u32 gMonShinyPalette_Primeape[] = INCBIN_U32("graphics/pokemon/primeape/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Primeape[] = INCBIN_U32("graphics/pokemon/primeape/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Primeape[] = INCBIN_U32("graphics/pokemon/primeape/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Primeape[] = INCBIN_U32("graphics/pokemon/primeape/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Primeape[] = INCBIN_U32("graphics/pokemon/primeape/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Primeape[] = INCBIN_U8("graphics/pokemon/primeape/icon.4bpp");
#else
    const u8 gMonIcon_Primeape[] = INCBIN_U8("graphics/pokemon/primeape/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Primeape[] = INCBIN_U8("graphics/pokemon/primeape/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Primeape[] = INCBIN_COMP("graphics/pokemon/primeape/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Primeape[] = INCBIN_U32("graphics/pokemon/primeape/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Primeape[] = INCBIN_U32("graphics/pokemon/primeape/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_MANKEY

#if P_FAMILY_GROWLITHE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Growlithe[] = INCBIN_U32("graphics/pokemon/growlithe/anim_front.4bpp.lz");
    const u32 gMonPalette_Growlithe[] = INCBIN_U32("graphics/pokemon/growlithe/normal.gbapal.lz");
    const u32 gMonBackPic_Growlithe[] = INCBIN_U32("graphics/pokemon/growlithe/back.4bpp.lz");
    const u32 gMonShinyPalette_Growlithe[] = INCBIN_U32("graphics/pokemon/growlithe/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Growlithe[] = INCBIN_U32("graphics/pokemon/growlithe/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Growlithe[] = INCBIN_U32("graphics/pokemon/growlithe/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Growlithe[] = INCBIN_U32("graphics/pokemon/growlithe/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Growlithe[] = INCBIN_U32("graphics/pokemon/growlithe/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Growlithe[] = INCBIN_U8("graphics/pokemon/growlithe/icon.4bpp");
#else
    const u8 gMonIcon_Growlithe[] = INCBIN_U8("graphics/pokemon/growlithe/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Growlithe[] = INCBIN_U8("graphics/pokemon/growlithe/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Growlithe[] = INCBIN_COMP("graphics/pokemon/growlithe/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Growlithe[] = INCBIN_U32("graphics/pokemon/growlithe/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Growlithe[] = INCBIN_U32("graphics/pokemon/growlithe/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Arcanine[] = INCBIN_U32("graphics/pokemon/arcanine/anim_front.4bpp.lz");
    const u32 gMonPalette_Arcanine[] = INCBIN_U32("graphics/pokemon/arcanine/normal.gbapal.lz");
    const u32 gMonBackPic_Arcanine[] = INCBIN_U32("graphics/pokemon/arcanine/back.4bpp.lz");
    const u32 gMonShinyPalette_Arcanine[] = INCBIN_U32("graphics/pokemon/arcanine/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Arcanine[] = INCBIN_U32("graphics/pokemon/arcanine/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Arcanine[] = INCBIN_U32("graphics/pokemon/arcanine/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Arcanine[] = INCBIN_U32("graphics/pokemon/arcanine/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Arcanine[] = INCBIN_U32("graphics/pokemon/arcanine/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Arcanine[] = INCBIN_U8("graphics/pokemon/arcanine/icon.4bpp");
#else
    const u8 gMonIcon_Arcanine[] = INCBIN_U8("graphics/pokemon/arcanine/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Arcanine[] = INCBIN_U8("graphics/pokemon/arcanine/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Arcanine[] = INCBIN_COMP("graphics/pokemon/arcanine/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Arcanine[] = INCBIN_U32("graphics/pokemon/arcanine/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Arcanine[] = INCBIN_U32("graphics/pokemon/arcanine/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_GROWLITHE

#if P_FAMILY_POLIWAG
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Poliwag[] = INCBIN_U32("graphics/pokemon/poliwag/anim_front.4bpp.lz");
    const u32 gMonPalette_Poliwag[] = INCBIN_U32("graphics/pokemon/poliwag/normal.gbapal.lz");
    const u32 gMonBackPic_Poliwag[] = INCBIN_U32("graphics/pokemon/poliwag/back.4bpp.lz");
    const u32 gMonShinyPalette_Poliwag[] = INCBIN_U32("graphics/pokemon/poliwag/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Poliwag[] = INCBIN_U32("graphics/pokemon/poliwag/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Poliwag[] = INCBIN_U32("graphics/pokemon/poliwag/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Poliwag[] = INCBIN_U32("graphics/pokemon/poliwag/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Poliwag[] = INCBIN_U32("graphics/pokemon/poliwag/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Poliwag[] = INCBIN_U8("graphics/pokemon/poliwag/icon.4bpp");
#else
    const u8 gMonIcon_Poliwag[] = INCBIN_U8("graphics/pokemon/poliwag/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Poliwag[] = INCBIN_U8("graphics/pokemon/poliwag/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Poliwag[] = INCBIN_COMP("graphics/pokemon/poliwag/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Poliwag[] = INCBIN_U32("graphics/pokemon/poliwag/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Poliwag[] = INCBIN_U32("graphics/pokemon/poliwag/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Poliwhirl[] = INCBIN_U32("graphics/pokemon/poliwhirl/anim_front.4bpp.lz");
    const u32 gMonPalette_Poliwhirl[] = INCBIN_U32("graphics/pokemon/poliwhirl/normal.gbapal.lz");
    const u32 gMonBackPic_Poliwhirl[] = INCBIN_U32("graphics/pokemon/poliwhirl/back.4bpp.lz");
    const u32 gMonShinyPalette_Poliwhirl[] = INCBIN_U32("graphics/pokemon/poliwhirl/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Poliwhirl[] = INCBIN_U32("graphics/pokemon/poliwhirl/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Poliwhirl[] = INCBIN_U32("graphics/pokemon/poliwhirl/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Poliwhirl[] = INCBIN_U32("graphics/pokemon/poliwhirl/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Poliwhirl[] = INCBIN_U32("graphics/pokemon/poliwhirl/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Poliwhirl[] = INCBIN_U8("graphics/pokemon/poliwhirl/icon.4bpp");
#else
    const u8 gMonIcon_Poliwhirl[] = INCBIN_U8("graphics/pokemon/poliwhirl/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Poliwhirl[] = INCBIN_U8("graphics/pokemon/poliwhirl/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Poliwhirl[] = INCBIN_COMP("graphics/pokemon/poliwhirl/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Poliwhirl[] = INCBIN_U32("graphics/pokemon/poliwhirl/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Poliwhirl[] = INCBIN_U32("graphics/pokemon/poliwhirl/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Poliwrath[] = INCBIN_U32("graphics/pokemon/poliwrath/anim_front.4bpp.lz");
    const u32 gMonPalette_Poliwrath[] = INCBIN_U32("graphics/pokemon/poliwrath/normal.gbapal.lz");
    const u32 gMonBackPic_Poliwrath[] = INCBIN_U32("graphics/pokemon/poliwrath/back.4bpp.lz");
    const u32 gMonShinyPalette_Poliwrath[] = INCBIN_U32("graphics/pokemon/poliwrath/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Poliwrath[] = INCBIN_U32("graphics/pokemon/poliwrath/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Poliwrath[] = INCBIN_U32("graphics/pokemon/poliwrath/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Poliwrath[] = INCBIN_U32("graphics/pokemon/poliwrath/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Poliwrath[] = INCBIN_U32("graphics/pokemon/poliwrath/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Poliwrath[] = INCBIN_U8("graphics/pokemon/poliwrath/icon.4bpp");
#else
    const u8 gMonIcon_Poliwrath[] = INCBIN_U8("graphics/pokemon/poliwrath/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Poliwrath[] = INCBIN_U8("graphics/pokemon/poliwrath/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Poliwrath[] = INCBIN_COMP("graphics/pokemon/poliwrath/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Poliwrath[] = INCBIN_U32("graphics/pokemon/poliwrath/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Poliwrath[] = INCBIN_U32("graphics/pokemon/poliwrath/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GEN_2_CROSS_EVOS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Politoed[] = INCBIN_U32("graphics/pokemon/politoed/anim_front.4bpp.lz");
    const u32 gMonPalette_Politoed[] = INCBIN_U32("graphics/pokemon/politoed/normal.gbapal.lz");
    const u32 gMonBackPic_Politoed[] = INCBIN_U32("graphics/pokemon/politoed/back.4bpp.lz");
    const u32 gMonShinyPalette_Politoed[] = INCBIN_U32("graphics/pokemon/politoed/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Politoed[] = INCBIN_U32("graphics/pokemon/politoed/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Politoed[] = INCBIN_U32("graphics/pokemon/politoed/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Politoed[] = INCBIN_U32("graphics/pokemon/politoed/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Politoed[] = INCBIN_U32("graphics/pokemon/politoed/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Politoed[] = INCBIN_U8("graphics/pokemon/politoed/icon.4bpp");
#else
    const u8 gMonIcon_Politoed[] = INCBIN_U8("graphics/pokemon/politoed/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Politoed[] = INCBIN_U8("graphics/pokemon/politoed/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Politoed[] = INCBIN_COMP("graphics/pokemon/politoed/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Politoed[] = INCBIN_U32("graphics/pokemon/politoed/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Politoed[] = INCBIN_U32("graphics/pokemon/politoed/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_PolitoedF[] = INCBIN_U32("graphics/pokemon/politoed/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_PolitoedF[] = INCBIN_U32("graphics/pokemon/politoed/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_PolitoedF[] = INCBIN_COMP("graphics/pokemon/politoed/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_GEN_2_CROSS_EVOS
#endif //P_FAMILY_POLIWAG

#if P_FAMILY_ABRA
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Abra[] = INCBIN_U32("graphics/pokemon/abra/anim_front.4bpp.lz");
    const u32 gMonPalette_Abra[] = INCBIN_U32("graphics/pokemon/abra/normal.gbapal.lz");
    const u32 gMonBackPic_Abra[] = INCBIN_U32("graphics/pokemon/abra/back.4bpp.lz");
    const u32 gMonShinyPalette_Abra[] = INCBIN_U32("graphics/pokemon/abra/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Abra[] = INCBIN_U32("graphics/pokemon/abra/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Abra[] = INCBIN_U32("graphics/pokemon/abra/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Abra[] = INCBIN_U32("graphics/pokemon/abra/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Abra[] = INCBIN_U32("graphics/pokemon/abra/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Abra[] = INCBIN_U8("graphics/pokemon/abra/icon.4bpp");
#else
    const u8 gMonIcon_Abra[] = INCBIN_U8("graphics/pokemon/abra/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Abra[] = INCBIN_U8("graphics/pokemon/abra/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Abra[] = INCBIN_COMP("graphics/pokemon/abra/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Abra[] = INCBIN_U32("graphics/pokemon/abra/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Abra[] = INCBIN_U32("graphics/pokemon/abra/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Kadabra[] = INCBIN_U32("graphics/pokemon/kadabra/anim_front.4bpp.lz");
    const u32 gMonPalette_Kadabra[] = INCBIN_U32("graphics/pokemon/kadabra/normal.gbapal.lz");
    const u32 gMonBackPic_Kadabra[] = INCBIN_U32("graphics/pokemon/kadabra/back.4bpp.lz");
    const u32 gMonShinyPalette_Kadabra[] = INCBIN_U32("graphics/pokemon/kadabra/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Kadabra[] = INCBIN_U32("graphics/pokemon/kadabra/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Kadabra[] = INCBIN_U32("graphics/pokemon/kadabra/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Kadabra[] = INCBIN_U32("graphics/pokemon/kadabra/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Kadabra[] = INCBIN_U32("graphics/pokemon/kadabra/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Kadabra[] = INCBIN_U8("graphics/pokemon/kadabra/icon.4bpp");
#else
    const u8 gMonIcon_Kadabra[] = INCBIN_U8("graphics/pokemon/kadabra/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Kadabra[] = INCBIN_U8("graphics/pokemon/kadabra/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Kadabra[] = INCBIN_COMP("graphics/pokemon/kadabra/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Kadabra[] = INCBIN_U32("graphics/pokemon/kadabra/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Kadabra[] = INCBIN_U32("graphics/pokemon/kadabra/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_KadabraF[] = INCBIN_U32("graphics/pokemon/kadabra/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_KadabraF[] = INCBIN_U32("graphics/pokemon/kadabra/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_KadabraF[] = INCBIN_COMP("graphics/pokemon/kadabra/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Alakazam[] = INCBIN_U32("graphics/pokemon/alakazam/anim_front.4bpp.lz");
    const u32 gMonPalette_Alakazam[] = INCBIN_U32("graphics/pokemon/alakazam/normal.gbapal.lz");
    const u32 gMonBackPic_Alakazam[] = INCBIN_U32("graphics/pokemon/alakazam/back.4bpp.lz");
    const u32 gMonShinyPalette_Alakazam[] = INCBIN_U32("graphics/pokemon/alakazam/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Alakazam[] = INCBIN_U32("graphics/pokemon/alakazam/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Alakazam[] = INCBIN_U32("graphics/pokemon/alakazam/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Alakazam[] = INCBIN_U32("graphics/pokemon/alakazam/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Alakazam[] = INCBIN_U32("graphics/pokemon/alakazam/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Alakazam[] = INCBIN_U8("graphics/pokemon/alakazam/icon.4bpp");
#else
    const u8 gMonIcon_Alakazam[] = INCBIN_U8("graphics/pokemon/alakazam/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Alakazam[] = INCBIN_U8("graphics/pokemon/alakazam/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Alakazam[] = INCBIN_COMP("graphics/pokemon/alakazam/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Alakazam[] = INCBIN_U32("graphics/pokemon/alakazam/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Alakazam[] = INCBIN_U32("graphics/pokemon/alakazam/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_AlakazamF[] = INCBIN_U32("graphics/pokemon/alakazam/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_AlakazamF[] = INCBIN_U32("graphics/pokemon/alakazam/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_AlakazamF[] = INCBIN_COMP("graphics/pokemon/alakazam/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_ABRA

#if P_FAMILY_MACHOP
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Machop[] = INCBIN_U32("graphics/pokemon/machop/anim_front.4bpp.lz");
    const u32 gMonPalette_Machop[] = INCBIN_U32("graphics/pokemon/machop/normal.gbapal.lz");
    const u32 gMonBackPic_Machop[] = INCBIN_U32("graphics/pokemon/machop/back.4bpp.lz");
    const u32 gMonShinyPalette_Machop[] = INCBIN_U32("graphics/pokemon/machop/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Machop[] = INCBIN_U32("graphics/pokemon/machop/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Machop[] = INCBIN_U32("graphics/pokemon/machop/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Machop[] = INCBIN_U32("graphics/pokemon/machop/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Machop[] = INCBIN_U32("graphics/pokemon/machop/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Machop[] = INCBIN_U8("graphics/pokemon/machop/icon.4bpp");
#else
    const u8 gMonIcon_Machop[] = INCBIN_U8("graphics/pokemon/machop/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Machop[] = INCBIN_U8("graphics/pokemon/machop/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Machop[] = INCBIN_COMP("graphics/pokemon/machop/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Machop[] = INCBIN_U32("graphics/pokemon/machop/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Machop[] = INCBIN_U32("graphics/pokemon/machop/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Machoke[] = INCBIN_U32("graphics/pokemon/machoke/anim_front.4bpp.lz");
    const u32 gMonPalette_Machoke[] = INCBIN_U32("graphics/pokemon/machoke/normal.gbapal.lz");
    const u32 gMonBackPic_Machoke[] = INCBIN_U32("graphics/pokemon/machoke/back.4bpp.lz");
    const u32 gMonShinyPalette_Machoke[] = INCBIN_U32("graphics/pokemon/machoke/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Machoke[] = INCBIN_U32("graphics/pokemon/machoke/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Machoke[] = INCBIN_U32("graphics/pokemon/machoke/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Machoke[] = INCBIN_U32("graphics/pokemon/machoke/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Machoke[] = INCBIN_U32("graphics/pokemon/machoke/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Machoke[] = INCBIN_U8("graphics/pokemon/machoke/icon.4bpp");
#else
    const u8 gMonIcon_Machoke[] = INCBIN_U8("graphics/pokemon/machoke/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Machoke[] = INCBIN_U8("graphics/pokemon/machoke/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Machoke[] = INCBIN_COMP("graphics/pokemon/machoke/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Machoke[] = INCBIN_U32("graphics/pokemon/machoke/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Machoke[] = INCBIN_U32("graphics/pokemon/machoke/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Machamp[] = INCBIN_U32("graphics/pokemon/machamp/anim_front.4bpp.lz");
    const u32 gMonPalette_Machamp[] = INCBIN_U32("graphics/pokemon/machamp/normal.gbapal.lz");
    const u32 gMonBackPic_Machamp[] = INCBIN_U32("graphics/pokemon/machamp/back.4bpp.lz");
    const u32 gMonShinyPalette_Machamp[] = INCBIN_U32("graphics/pokemon/machamp/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Machamp[] = INCBIN_U32("graphics/pokemon/machamp/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Machamp[] = INCBIN_U32("graphics/pokemon/machamp/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Machamp[] = INCBIN_U32("graphics/pokemon/machamp/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Machamp[] = INCBIN_U32("graphics/pokemon/machamp/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Machamp[] = INCBIN_U8("graphics/pokemon/machamp/icon.4bpp");
#else
    const u8 gMonIcon_Machamp[] = INCBIN_U8("graphics/pokemon/machamp/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Machamp[] = INCBIN_U8("graphics/pokemon/machamp/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Machamp[] = INCBIN_COMP("graphics/pokemon/machamp/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Machamp[] = INCBIN_U32("graphics/pokemon/machamp/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Machamp[] = INCBIN_U32("graphics/pokemon/machamp/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_MACHOP

#if P_FAMILY_BELLSPROUT
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Bellsprout[] = INCBIN_U32("graphics/pokemon/bellsprout/anim_front.4bpp.lz");
    const u32 gMonPalette_Bellsprout[] = INCBIN_U32("graphics/pokemon/bellsprout/normal.gbapal.lz");
    const u32 gMonBackPic_Bellsprout[] = INCBIN_U32("graphics/pokemon/bellsprout/back.4bpp.lz");
    const u32 gMonShinyPalette_Bellsprout[] = INCBIN_U32("graphics/pokemon/bellsprout/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Bellsprout[] = INCBIN_U32("graphics/pokemon/bellsprout/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Bellsprout[] = INCBIN_U32("graphics/pokemon/bellsprout/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Bellsprout[] = INCBIN_U32("graphics/pokemon/bellsprout/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Bellsprout[] = INCBIN_U32("graphics/pokemon/bellsprout/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Bellsprout[] = INCBIN_U8("graphics/pokemon/bellsprout/icon.4bpp");
#else
    const u8 gMonIcon_Bellsprout[] = INCBIN_U8("graphics/pokemon/bellsprout/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Bellsprout[] = INCBIN_U8("graphics/pokemon/bellsprout/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Bellsprout[] = INCBIN_COMP("graphics/pokemon/bellsprout/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Bellsprout[] = INCBIN_U32("graphics/pokemon/bellsprout/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Bellsprout[] = INCBIN_U32("graphics/pokemon/bellsprout/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Weepinbell[] = INCBIN_U32("graphics/pokemon/weepinbell/anim_front.4bpp.lz");
    const u32 gMonPalette_Weepinbell[] = INCBIN_U32("graphics/pokemon/weepinbell/normal.gbapal.lz");
    const u32 gMonBackPic_Weepinbell[] = INCBIN_U32("graphics/pokemon/weepinbell/back.4bpp.lz");
    const u32 gMonShinyPalette_Weepinbell[] = INCBIN_U32("graphics/pokemon/weepinbell/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Weepinbell[] = INCBIN_U32("graphics/pokemon/weepinbell/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Weepinbell[] = INCBIN_U32("graphics/pokemon/weepinbell/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Weepinbell[] = INCBIN_U32("graphics/pokemon/weepinbell/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Weepinbell[] = INCBIN_U32("graphics/pokemon/weepinbell/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Weepinbell[] = INCBIN_U8("graphics/pokemon/weepinbell/icon.4bpp");
#else
    const u8 gMonIcon_Weepinbell[] = INCBIN_U8("graphics/pokemon/weepinbell/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Weepinbell[] = INCBIN_U8("graphics/pokemon/weepinbell/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Weepinbell[] = INCBIN_COMP("graphics/pokemon/weepinbell/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Weepinbell[] = INCBIN_U32("graphics/pokemon/weepinbell/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Weepinbell[] = INCBIN_U32("graphics/pokemon/weepinbell/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Victreebel[] = INCBIN_U32("graphics/pokemon/victreebel/anim_front.4bpp.lz");
    const u32 gMonPalette_Victreebel[] = INCBIN_U32("graphics/pokemon/victreebel/normal.gbapal.lz");
    const u32 gMonBackPic_Victreebel[] = INCBIN_U32("graphics/pokemon/victreebel/back.4bpp.lz");
    const u32 gMonShinyPalette_Victreebel[] = INCBIN_U32("graphics/pokemon/victreebel/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Victreebel[] = INCBIN_U32("graphics/pokemon/victreebel/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Victreebel[] = INCBIN_U32("graphics/pokemon/victreebel/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Victreebel[] = INCBIN_U32("graphics/pokemon/victreebel/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Victreebel[] = INCBIN_U32("graphics/pokemon/victreebel/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Victreebel[] = INCBIN_U8("graphics/pokemon/victreebel/icon.4bpp");
#else
    const u8 gMonIcon_Victreebel[] = INCBIN_U8("graphics/pokemon/victreebel/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Victreebel[] = INCBIN_U8("graphics/pokemon/victreebel/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Victreebel[] = INCBIN_COMP("graphics/pokemon/victreebel/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Victreebel[] = INCBIN_U32("graphics/pokemon/victreebel/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Victreebel[] = INCBIN_U32("graphics/pokemon/victreebel/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_BELLSPROUT

#if P_FAMILY_TENTACOOL
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Tentacool[] = INCBIN_U32("graphics/pokemon/tentacool/anim_front.4bpp.lz");
    const u32 gMonPalette_Tentacool[] = INCBIN_U32("graphics/pokemon/tentacool/normal.gbapal.lz");
    const u32 gMonBackPic_Tentacool[] = INCBIN_U32("graphics/pokemon/tentacool/back.4bpp.lz");
    const u32 gMonShinyPalette_Tentacool[] = INCBIN_U32("graphics/pokemon/tentacool/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Tentacool[] = INCBIN_U32("graphics/pokemon/tentacool/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Tentacool[] = INCBIN_U32("graphics/pokemon/tentacool/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Tentacool[] = INCBIN_U32("graphics/pokemon/tentacool/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Tentacool[] = INCBIN_U32("graphics/pokemon/tentacool/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Tentacool[] = INCBIN_U8("graphics/pokemon/tentacool/icon.4bpp");
#else
    const u8 gMonIcon_Tentacool[] = INCBIN_U8("graphics/pokemon/tentacool/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Tentacool[] = INCBIN_U8("graphics/pokemon/tentacool/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Tentacool[] = INCBIN_COMP("graphics/pokemon/tentacool/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Tentacool[] = INCBIN_U32("graphics/pokemon/tentacool/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Tentacool[] = INCBIN_U32("graphics/pokemon/tentacool/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Tentacruel[] = INCBIN_U32("graphics/pokemon/tentacruel/anim_front.4bpp.lz");
    const u32 gMonPalette_Tentacruel[] = INCBIN_U32("graphics/pokemon/tentacruel/normal.gbapal.lz");
    const u32 gMonBackPic_Tentacruel[] = INCBIN_U32("graphics/pokemon/tentacruel/back.4bpp.lz");
    const u32 gMonShinyPalette_Tentacruel[] = INCBIN_U32("graphics/pokemon/tentacruel/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Tentacruel[] = INCBIN_U32("graphics/pokemon/tentacruel/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Tentacruel[] = INCBIN_U32("graphics/pokemon/tentacruel/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Tentacruel[] = INCBIN_U32("graphics/pokemon/tentacruel/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Tentacruel[] = INCBIN_U32("graphics/pokemon/tentacruel/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Tentacruel[] = INCBIN_U8("graphics/pokemon/tentacruel/icon.4bpp");
#else
    const u8 gMonIcon_Tentacruel[] = INCBIN_U8("graphics/pokemon/tentacruel/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Tentacruel[] = INCBIN_U8("graphics/pokemon/tentacruel/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Tentacruel[] = INCBIN_COMP("graphics/pokemon/tentacruel/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Tentacruel[] = INCBIN_U32("graphics/pokemon/tentacruel/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Tentacruel[] = INCBIN_U32("graphics/pokemon/tentacruel/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_TENTACOOL

#if P_FAMILY_GEODUDE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Geodude[] = INCBIN_U32("graphics/pokemon/geodude/anim_front.4bpp.lz");
    const u32 gMonPalette_Geodude[] = INCBIN_U32("graphics/pokemon/geodude/normal.gbapal.lz");
    const u32 gMonBackPic_Geodude[] = INCBIN_U32("graphics/pokemon/geodude/back.4bpp.lz");
    const u32 gMonShinyPalette_Geodude[] = INCBIN_U32("graphics/pokemon/geodude/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Geodude[] = INCBIN_U32("graphics/pokemon/geodude/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Geodude[] = INCBIN_U32("graphics/pokemon/geodude/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Geodude[] = INCBIN_U32("graphics/pokemon/geodude/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Geodude[] = INCBIN_U32("graphics/pokemon/geodude/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Geodude[] = INCBIN_U8("graphics/pokemon/geodude/icon.4bpp");
#else
    const u8 gMonIcon_Geodude[] = INCBIN_U8("graphics/pokemon/geodude/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Geodude[] = INCBIN_U8("graphics/pokemon/geodude/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Geodude[] = INCBIN_COMP("graphics/pokemon/geodude/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Geodude[] = INCBIN_U32("graphics/pokemon/geodude/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Geodude[] = INCBIN_U32("graphics/pokemon/geodude/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Graveler[] = INCBIN_U32("graphics/pokemon/graveler/anim_front.4bpp.lz");
    const u32 gMonPalette_Graveler[] = INCBIN_U32("graphics/pokemon/graveler/normal.gbapal.lz");
    const u32 gMonBackPic_Graveler[] = INCBIN_U32("graphics/pokemon/graveler/back.4bpp.lz");
    const u32 gMonShinyPalette_Graveler[] = INCBIN_U32("graphics/pokemon/graveler/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Graveler[] = INCBIN_U32("graphics/pokemon/graveler/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Graveler[] = INCBIN_U32("graphics/pokemon/graveler/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Graveler[] = INCBIN_U32("graphics/pokemon/graveler/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Graveler[] = INCBIN_U32("graphics/pokemon/graveler/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Graveler[] = INCBIN_U8("graphics/pokemon/graveler/icon.4bpp");
#else
    const u8 gMonIcon_Graveler[] = INCBIN_U8("graphics/pokemon/graveler/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Graveler[] = INCBIN_U8("graphics/pokemon/graveler/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Graveler[] = INCBIN_COMP("graphics/pokemon/graveler/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Graveler[] = INCBIN_U32("graphics/pokemon/graveler/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Graveler[] = INCBIN_U32("graphics/pokemon/graveler/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Golem[] = INCBIN_U32("graphics/pokemon/golem/anim_front.4bpp.lz");
    const u32 gMonPalette_Golem[] = INCBIN_U32("graphics/pokemon/golem/normal.gbapal.lz");
    const u32 gMonBackPic_Golem[] = INCBIN_U32("graphics/pokemon/golem/back.4bpp.lz");
    const u32 gMonShinyPalette_Golem[] = INCBIN_U32("graphics/pokemon/golem/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Golem[] = INCBIN_U32("graphics/pokemon/golem/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Golem[] = INCBIN_U32("graphics/pokemon/golem/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Golem[] = INCBIN_U32("graphics/pokemon/golem/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Golem[] = INCBIN_U32("graphics/pokemon/golem/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Golem[] = INCBIN_U8("graphics/pokemon/golem/icon.4bpp");
#else
    const u8 gMonIcon_Golem[] = INCBIN_U8("graphics/pokemon/golem/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
#if !P_GBA_STYLE_SPECIES_FOOTPRINTS
    const u8 gMonFootprint_Golem[] = INCBIN_U8("graphics/pokemon/golem/footprint.1bpp");
#else
    const u8 gMonFootprint_Golem[] = INCBIN_U8("graphics/pokemon/golem/footprint_gba.1bpp");
#endif //P_GBA_STYLE_SPECIES_FOOTPRINTS
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Golem[] = INCBIN_COMP("graphics/pokemon/golem/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Golem[] = INCBIN_U32("graphics/pokemon/golem/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Golem[] = INCBIN_U32("graphics/pokemon/golem/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_GEODUDE

#if P_FAMILY_PONYTA
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Ponyta[] = INCBIN_U32("graphics/pokemon/ponyta/anim_front.4bpp.lz");
    const u32 gMonPalette_Ponyta[] = INCBIN_U32("graphics/pokemon/ponyta/normal.gbapal.lz");
    const u32 gMonBackPic_Ponyta[] = INCBIN_U32("graphics/pokemon/ponyta/back.4bpp.lz");
    const u32 gMonShinyPalette_Ponyta[] = INCBIN_U32("graphics/pokemon/ponyta/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Ponyta[] = INCBIN_U32("graphics/pokemon/ponyta/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Ponyta[] = INCBIN_U32("graphics/pokemon/ponyta/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Ponyta[] = INCBIN_U32("graphics/pokemon/ponyta/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Ponyta[] = INCBIN_U32("graphics/pokemon/ponyta/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Ponyta[] = INCBIN_U8("graphics/pokemon/ponyta/icon.4bpp");
#else
    const u8 gMonIcon_Ponyta[] = INCBIN_U8("graphics/pokemon/ponyta/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Ponyta[] = INCBIN_U8("graphics/pokemon/ponyta/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Ponyta[] = INCBIN_COMP("graphics/pokemon/ponyta/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Ponyta[] = INCBIN_U32("graphics/pokemon/ponyta/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Ponyta[] = INCBIN_U32("graphics/pokemon/ponyta/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Rapidash[] = INCBIN_U32("graphics/pokemon/rapidash/anim_front.4bpp.lz");
    const u32 gMonPalette_Rapidash[] = INCBIN_U32("graphics/pokemon/rapidash/normal.gbapal.lz");
    const u32 gMonBackPic_Rapidash[] = INCBIN_U32("graphics/pokemon/rapidash/back.4bpp.lz");
    const u32 gMonShinyPalette_Rapidash[] = INCBIN_U32("graphics/pokemon/rapidash/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Rapidash[] = INCBIN_U32("graphics/pokemon/rapidash/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Rapidash[] = INCBIN_U32("graphics/pokemon/rapidash/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Rapidash[] = INCBIN_U32("graphics/pokemon/rapidash/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Rapidash[] = INCBIN_U32("graphics/pokemon/rapidash/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Rapidash[] = INCBIN_U8("graphics/pokemon/rapidash/icon.4bpp");
#else
    const u8 gMonIcon_Rapidash[] = INCBIN_U8("graphics/pokemon/rapidash/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Rapidash[] = INCBIN_U8("graphics/pokemon/rapidash/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Rapidash[] = INCBIN_COMP("graphics/pokemon/rapidash/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Rapidash[] = INCBIN_U32("graphics/pokemon/rapidash/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Rapidash[] = INCBIN_U32("graphics/pokemon/rapidash/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_PONYTA

#if P_FAMILY_SLOWPOKE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Slowpoke[] = INCBIN_U32("graphics/pokemon/slowpoke/anim_front.4bpp.lz");
    const u32 gMonPalette_Slowpoke[] = INCBIN_U32("graphics/pokemon/slowpoke/normal.gbapal.lz");
    const u32 gMonBackPic_Slowpoke[] = INCBIN_U32("graphics/pokemon/slowpoke/back.4bpp.lz");
    const u32 gMonShinyPalette_Slowpoke[] = INCBIN_U32("graphics/pokemon/slowpoke/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Slowpoke[] = INCBIN_U32("graphics/pokemon/slowpoke/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Slowpoke[] = INCBIN_U32("graphics/pokemon/slowpoke/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Slowpoke[] = INCBIN_U32("graphics/pokemon/slowpoke/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Slowpoke[] = INCBIN_U32("graphics/pokemon/slowpoke/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Slowpoke[] = INCBIN_U8("graphics/pokemon/slowpoke/icon.4bpp");
#else
    const u8 gMonIcon_Slowpoke[] = INCBIN_U8("graphics/pokemon/slowpoke/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Slowpoke[] = INCBIN_U8("graphics/pokemon/slowpoke/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Slowpoke[] = INCBIN_COMP("graphics/pokemon/slowpoke/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Slowpoke[] = INCBIN_U32("graphics/pokemon/slowpoke/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Slowpoke[] = INCBIN_U32("graphics/pokemon/slowpoke/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Slowbro[] = INCBIN_U32("graphics/pokemon/slowbro/anim_front.4bpp.lz");
    const u32 gMonPalette_Slowbro[] = INCBIN_U32("graphics/pokemon/slowbro/normal.gbapal.lz");
    const u32 gMonBackPic_Slowbro[] = INCBIN_U32("graphics/pokemon/slowbro/back.4bpp.lz");
    const u32 gMonShinyPalette_Slowbro[] = INCBIN_U32("graphics/pokemon/slowbro/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Slowbro[] = INCBIN_U32("graphics/pokemon/slowbro/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Slowbro[] = INCBIN_U32("graphics/pokemon/slowbro/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Slowbro[] = INCBIN_U32("graphics/pokemon/slowbro/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Slowbro[] = INCBIN_U32("graphics/pokemon/slowbro/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Slowbro[] = INCBIN_U8("graphics/pokemon/slowbro/icon.4bpp");
#else
    const u8 gMonIcon_Slowbro[] = INCBIN_U8("graphics/pokemon/slowbro/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Slowbro[] = INCBIN_U8("graphics/pokemon/slowbro/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Slowbro[] = INCBIN_COMP("graphics/pokemon/slowbro/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Slowbro[] = INCBIN_U32("graphics/pokemon/slowbro/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Slowbro[] = INCBIN_U32("graphics/pokemon/slowbro/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GEN_2_CROSS_EVOS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Slowking[] = INCBIN_U32("graphics/pokemon/slowking/anim_front.4bpp.lz");
    const u32 gMonPalette_Slowking[] = INCBIN_U32("graphics/pokemon/slowking/normal.gbapal.lz");
    const u32 gMonBackPic_Slowking[] = INCBIN_U32("graphics/pokemon/slowking/back.4bpp.lz");
    const u32 gMonShinyPalette_Slowking[] = INCBIN_U32("graphics/pokemon/slowking/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Slowking[] = INCBIN_U32("graphics/pokemon/slowking/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Slowking[] = INCBIN_U32("graphics/pokemon/slowking/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Slowking[] = INCBIN_U32("graphics/pokemon/slowking/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Slowking[] = INCBIN_U32("graphics/pokemon/slowking/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Slowking[] = INCBIN_U8("graphics/pokemon/slowking/icon.4bpp");
#else
    const u8 gMonIcon_Slowking[] = INCBIN_U8("graphics/pokemon/slowking/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Slowking[] = INCBIN_U8("graphics/pokemon/slowking/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Slowking[] = INCBIN_COMP("graphics/pokemon/slowking/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Slowking[] = INCBIN_U32("graphics/pokemon/slowking/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Slowking[] = INCBIN_U32("graphics/pokemon/slowking/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_2_CROSS_EVOS
#endif //P_FAMILY_SLOWPOKE

#if P_FAMILY_MAGNEMITE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Magnemite[] = INCBIN_U32("graphics/pokemon/magnemite/anim_front.4bpp.lz");
    const u32 gMonPalette_Magnemite[] = INCBIN_U32("graphics/pokemon/magnemite/normal.gbapal.lz");
    const u32 gMonBackPic_Magnemite[] = INCBIN_U32("graphics/pokemon/magnemite/back.4bpp.lz");
    const u32 gMonShinyPalette_Magnemite[] = INCBIN_U32("graphics/pokemon/magnemite/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Magnemite[] = INCBIN_U32("graphics/pokemon/magnemite/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Magnemite[] = INCBIN_U32("graphics/pokemon/magnemite/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Magnemite[] = INCBIN_U32("graphics/pokemon/magnemite/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Magnemite[] = INCBIN_U32("graphics/pokemon/magnemite/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Magnemite[] = INCBIN_U8("graphics/pokemon/magnemite/icon.4bpp");
#else
    const u8 gMonIcon_Magnemite[] = INCBIN_U8("graphics/pokemon/magnemite/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Magnemite[] = INCBIN_U8("graphics/pokemon/magnemite/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Magnemite[] = INCBIN_COMP("graphics/pokemon/magnemite/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Magnemite[] = INCBIN_U32("graphics/pokemon/magnemite/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Magnemite[] = INCBIN_U32("graphics/pokemon/magnemite/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Magneton[] = INCBIN_U32("graphics/pokemon/magneton/anim_front.4bpp.lz");
    const u32 gMonPalette_Magneton[] = INCBIN_U32("graphics/pokemon/magneton/normal.gbapal.lz");
    const u32 gMonBackPic_Magneton[] = INCBIN_U32("graphics/pokemon/magneton/back.4bpp.lz");
    const u32 gMonShinyPalette_Magneton[] = INCBIN_U32("graphics/pokemon/magneton/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Magneton[] = INCBIN_U32("graphics/pokemon/magneton/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Magneton[] = INCBIN_U32("graphics/pokemon/magneton/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Magneton[] = INCBIN_U32("graphics/pokemon/magneton/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Magneton[] = INCBIN_U32("graphics/pokemon/magneton/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Magneton[] = INCBIN_U8("graphics/pokemon/magneton/icon.4bpp");
#else
    const u8 gMonIcon_Magneton[] = INCBIN_U8("graphics/pokemon/magneton/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Magneton[] = INCBIN_U8("graphics/pokemon/magneton/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Magneton[] = INCBIN_COMP("graphics/pokemon/magneton/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Magneton[] = INCBIN_U32("graphics/pokemon/magneton/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Magneton[] = INCBIN_U32("graphics/pokemon/magneton/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Magnezone[] = INCBIN_U32("graphics/pokemon/magnezone/anim_front.4bpp.lz");
    const u32 gMonPalette_Magnezone[] = INCBIN_U32("graphics/pokemon/magnezone/normal.gbapal.lz");
    const u32 gMonBackPic_Magnezone[] = INCBIN_U32("graphics/pokemon/magnezone/back.4bpp.lz");
    const u32 gMonShinyPalette_Magnezone[] = INCBIN_U32("graphics/pokemon/magnezone/shiny.gbapal.lz");
    const u8 gMonIcon_Magnezone[] = INCBIN_U8("graphics/pokemon/magnezone/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Magnezone[] = INCBIN_U8("graphics/pokemon/magnezone/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Magnezone[] = INCBIN_COMP("graphics/pokemon/magnezone/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Magnezone[] = INCBIN_U32("graphics/pokemon/magnezone/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Magnezone[] = INCBIN_U32("graphics/pokemon/magnezone/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_MAGNEMITE

#if P_FAMILY_FARFETCHD
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Farfetchd[] = INCBIN_U32("graphics/pokemon/farfetchd/anim_front.4bpp.lz");
    const u32 gMonPalette_Farfetchd[] = INCBIN_U32("graphics/pokemon/farfetchd/normal.gbapal.lz");
    const u32 gMonBackPic_Farfetchd[] = INCBIN_U32("graphics/pokemon/farfetchd/back.4bpp.lz");
    const u32 gMonShinyPalette_Farfetchd[] = INCBIN_U32("graphics/pokemon/farfetchd/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Farfetchd[] = INCBIN_U32("graphics/pokemon/farfetchd/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Farfetchd[] = INCBIN_U32("graphics/pokemon/farfetchd/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Farfetchd[] = INCBIN_U32("graphics/pokemon/farfetchd/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Farfetchd[] = INCBIN_U32("graphics/pokemon/farfetchd/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Farfetchd[] = INCBIN_U8("graphics/pokemon/farfetchd/icon.4bpp");
#else
    const u8 gMonIcon_Farfetchd[] = INCBIN_U8("graphics/pokemon/farfetchd/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Farfetchd[] = INCBIN_U8("graphics/pokemon/farfetchd/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Farfetchd[] = INCBIN_COMP("graphics/pokemon/farfetchd/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Farfetchd[] = INCBIN_U32("graphics/pokemon/farfetchd/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Farfetchd[] = INCBIN_U32("graphics/pokemon/farfetchd/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_FARFETCHD

#if P_FAMILY_DODUO
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Doduo[] = INCBIN_U32("graphics/pokemon/doduo/anim_front.4bpp.lz");
    const u32 gMonPalette_Doduo[] = INCBIN_U32("graphics/pokemon/doduo/normal.gbapal.lz");
    const u32 gMonBackPic_Doduo[] = INCBIN_U32("graphics/pokemon/doduo/back.4bpp.lz");
    const u32 gMonShinyPalette_Doduo[] = INCBIN_U32("graphics/pokemon/doduo/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Doduo[] = INCBIN_U32("graphics/pokemon/doduo/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Doduo[] = INCBIN_U32("graphics/pokemon/doduo/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Doduo[] = INCBIN_U32("graphics/pokemon/doduo/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Doduo[] = INCBIN_U32("graphics/pokemon/doduo/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Doduo[] = INCBIN_U8("graphics/pokemon/doduo/icon.4bpp");
#else
    const u8 gMonIcon_Doduo[] = INCBIN_U8("graphics/pokemon/doduo/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Doduo[] = INCBIN_U8("graphics/pokemon/doduo/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Doduo[] = INCBIN_COMP("graphics/pokemon/doduo/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Doduo[] = INCBIN_U32("graphics/pokemon/doduo/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Doduo[] = INCBIN_U32("graphics/pokemon/doduo/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_DoduoF[] = INCBIN_U32("graphics/pokemon/doduo/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_DoduoF[] = INCBIN_U32("graphics/pokemon/doduo/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_DoduoF[] = INCBIN_COMP("graphics/pokemon/doduo/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Dodrio[] = INCBIN_U32("graphics/pokemon/dodrio/anim_front.4bpp.lz");
    const u32 gMonPalette_Dodrio[] = INCBIN_U32("graphics/pokemon/dodrio/normal.gbapal.lz");
    const u32 gMonBackPic_Dodrio[] = INCBIN_U32("graphics/pokemon/dodrio/back.4bpp.lz");
    const u32 gMonShinyPalette_Dodrio[] = INCBIN_U32("graphics/pokemon/dodrio/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Dodrio[] = INCBIN_U32("graphics/pokemon/dodrio/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Dodrio[] = INCBIN_U32("graphics/pokemon/dodrio/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Dodrio[] = INCBIN_U32("graphics/pokemon/dodrio/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Dodrio[] = INCBIN_U32("graphics/pokemon/dodrio/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Dodrio[] = INCBIN_U8("graphics/pokemon/dodrio/icon.4bpp");
#else
    const u8 gMonIcon_Dodrio[] = INCBIN_U8("graphics/pokemon/dodrio/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Dodrio[] = INCBIN_U8("graphics/pokemon/dodrio/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Dodrio[] = INCBIN_COMP("graphics/pokemon/dodrio/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Dodrio[] = INCBIN_U32("graphics/pokemon/dodrio/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Dodrio[] = INCBIN_U32("graphics/pokemon/dodrio/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_DodrioF[] = INCBIN_U32("graphics/pokemon/dodrio/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_DodrioF[] = INCBIN_U32("graphics/pokemon/dodrio/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_DodrioF[] = INCBIN_COMP("graphics/pokemon/dodrio/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_DODUO

#if P_FAMILY_SEEL
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Seel[] = INCBIN_U32("graphics/pokemon/seel/anim_front.4bpp.lz");
    const u32 gMonPalette_Seel[] = INCBIN_U32("graphics/pokemon/seel/normal.gbapal.lz");
    const u32 gMonBackPic_Seel[] = INCBIN_U32("graphics/pokemon/seel/back.4bpp.lz");
    const u32 gMonShinyPalette_Seel[] = INCBIN_U32("graphics/pokemon/seel/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Seel[] = INCBIN_U32("graphics/pokemon/seel/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Seel[] = INCBIN_U32("graphics/pokemon/seel/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Seel[] = INCBIN_U32("graphics/pokemon/seel/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Seel[] = INCBIN_U32("graphics/pokemon/seel/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Seel[] = INCBIN_U8("graphics/pokemon/seel/icon.4bpp");
#else
    const u8 gMonIcon_Seel[] = INCBIN_U8("graphics/pokemon/seel/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Seel[] = INCBIN_U8("graphics/pokemon/seel/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Seel[] = INCBIN_COMP("graphics/pokemon/seel/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Seel[] = INCBIN_U32("graphics/pokemon/seel/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Seel[] = INCBIN_U32("graphics/pokemon/seel/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Dewgong[] = INCBIN_U32("graphics/pokemon/dewgong/anim_front.4bpp.lz");
    const u32 gMonPalette_Dewgong[] = INCBIN_U32("graphics/pokemon/dewgong/normal.gbapal.lz");
    const u32 gMonBackPic_Dewgong[] = INCBIN_U32("graphics/pokemon/dewgong/back.4bpp.lz");
    const u32 gMonShinyPalette_Dewgong[] = INCBIN_U32("graphics/pokemon/dewgong/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Dewgong[] = INCBIN_U32("graphics/pokemon/dewgong/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Dewgong[] = INCBIN_U32("graphics/pokemon/dewgong/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Dewgong[] = INCBIN_U32("graphics/pokemon/dewgong/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Dewgong[] = INCBIN_U32("graphics/pokemon/dewgong/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Dewgong[] = INCBIN_U8("graphics/pokemon/dewgong/icon.4bpp");
#else
    const u8 gMonIcon_Dewgong[] = INCBIN_U8("graphics/pokemon/dewgong/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Dewgong[] = INCBIN_U8("graphics/pokemon/dewgong/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Dewgong[] = INCBIN_COMP("graphics/pokemon/dewgong/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Dewgong[] = INCBIN_U32("graphics/pokemon/dewgong/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Dewgong[] = INCBIN_U32("graphics/pokemon/dewgong/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SEEL

#if P_FAMILY_GRIMER
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Grimer[] = INCBIN_U32("graphics/pokemon/grimer/anim_front.4bpp.lz");
    const u32 gMonPalette_Grimer[] = INCBIN_U32("graphics/pokemon/grimer/normal.gbapal.lz");
    const u32 gMonBackPic_Grimer[] = INCBIN_U32("graphics/pokemon/grimer/back.4bpp.lz");
    const u32 gMonShinyPalette_Grimer[] = INCBIN_U32("graphics/pokemon/grimer/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Grimer[] = INCBIN_U32("graphics/pokemon/grimer/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Grimer[] = INCBIN_U32("graphics/pokemon/grimer/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Grimer[] = INCBIN_U32("graphics/pokemon/grimer/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Grimer[] = INCBIN_U32("graphics/pokemon/grimer/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Grimer[] = INCBIN_U8("graphics/pokemon/grimer/icon.4bpp");
#else
    const u8 gMonIcon_Grimer[] = INCBIN_U8("graphics/pokemon/grimer/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Grimer[] = INCBIN_U8("graphics/pokemon/grimer/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Grimer[] = INCBIN_COMP("graphics/pokemon/grimer/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Grimer[] = INCBIN_U32("graphics/pokemon/grimer/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Grimer[] = INCBIN_U32("graphics/pokemon/grimer/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Muk[] = INCBIN_U32("graphics/pokemon/muk/anim_front.4bpp.lz");
    const u32 gMonPalette_Muk[] = INCBIN_U32("graphics/pokemon/muk/normal.gbapal.lz");
    const u32 gMonBackPic_Muk[] = INCBIN_U32("graphics/pokemon/muk/back.4bpp.lz");
    const u32 gMonShinyPalette_Muk[] = INCBIN_U32("graphics/pokemon/muk/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Muk[] = INCBIN_U32("graphics/pokemon/muk/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Muk[] = INCBIN_U32("graphics/pokemon/muk/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Muk[] = INCBIN_U32("graphics/pokemon/muk/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Muk[] = INCBIN_U32("graphics/pokemon/muk/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Muk[] = INCBIN_U8("graphics/pokemon/muk/icon.4bpp");
#else
    const u8 gMonIcon_Muk[] = INCBIN_U8("graphics/pokemon/muk/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Muk[] = INCBIN_U8("graphics/pokemon/muk/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Muk[] = INCBIN_COMP("graphics/pokemon/muk/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Muk[] = INCBIN_U32("graphics/pokemon/muk/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Muk[] = INCBIN_U32("graphics/pokemon/muk/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_GRIMER

#if P_FAMILY_SHELLDER
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Shellder[] = INCBIN_U32("graphics/pokemon/shellder/anim_front.4bpp.lz");
    const u32 gMonPalette_Shellder[] = INCBIN_U32("graphics/pokemon/shellder/normal.gbapal.lz");
    const u32 gMonBackPic_Shellder[] = INCBIN_U32("graphics/pokemon/shellder/back.4bpp.lz");
    const u32 gMonShinyPalette_Shellder[] = INCBIN_U32("graphics/pokemon/shellder/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Shellder[] = INCBIN_U32("graphics/pokemon/shellder/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Shellder[] = INCBIN_U32("graphics/pokemon/shellder/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Shellder[] = INCBIN_U32("graphics/pokemon/shellder/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Shellder[] = INCBIN_U32("graphics/pokemon/shellder/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Shellder[] = INCBIN_U8("graphics/pokemon/shellder/icon.4bpp");
#else
    const u8 gMonIcon_Shellder[] = INCBIN_U8("graphics/pokemon/shellder/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Shellder[] = INCBIN_U8("graphics/pokemon/shellder/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Shellder[] = INCBIN_COMP("graphics/pokemon/shellder/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Shellder[] = INCBIN_U32("graphics/pokemon/shellder/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Shellder[] = INCBIN_U32("graphics/pokemon/shellder/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Cloyster[] = INCBIN_U32("graphics/pokemon/cloyster/anim_front.4bpp.lz");
    const u32 gMonPalette_Cloyster[] = INCBIN_U32("graphics/pokemon/cloyster/normal.gbapal.lz");
    const u32 gMonBackPic_Cloyster[] = INCBIN_U32("graphics/pokemon/cloyster/back.4bpp.lz");
    const u32 gMonShinyPalette_Cloyster[] = INCBIN_U32("graphics/pokemon/cloyster/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Cloyster[] = INCBIN_U32("graphics/pokemon/cloyster/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Cloyster[] = INCBIN_U32("graphics/pokemon/cloyster/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Cloyster[] = INCBIN_U32("graphics/pokemon/cloyster/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Cloyster[] = INCBIN_U32("graphics/pokemon/cloyster/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Cloyster[] = INCBIN_U8("graphics/pokemon/cloyster/icon.4bpp");
#else
    const u8 gMonIcon_Cloyster[] = INCBIN_U8("graphics/pokemon/cloyster/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Cloyster[] = INCBIN_U8("graphics/pokemon/cloyster/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Cloyster[] = INCBIN_COMP("graphics/pokemon/cloyster/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Cloyster[] = INCBIN_U32("graphics/pokemon/cloyster/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Cloyster[] = INCBIN_U32("graphics/pokemon/cloyster/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SHELLDER

#if P_FAMILY_GASTLY
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Gastly[] = INCBIN_U32("graphics/pokemon/gastly/anim_front.4bpp.lz");
    const u32 gMonPalette_Gastly[] = INCBIN_U32("graphics/pokemon/gastly/normal.gbapal.lz");
    const u32 gMonBackPic_Gastly[] = INCBIN_U32("graphics/pokemon/gastly/back.4bpp.lz");
    const u32 gMonShinyPalette_Gastly[] = INCBIN_U32("graphics/pokemon/gastly/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Gastly[] = INCBIN_U32("graphics/pokemon/gastly/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Gastly[] = INCBIN_U32("graphics/pokemon/gastly/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Gastly[] = INCBIN_U32("graphics/pokemon/gastly/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Gastly[] = INCBIN_U32("graphics/pokemon/gastly/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Gastly[] = INCBIN_U8("graphics/pokemon/gastly/icon.4bpp");
#else
    const u8 gMonIcon_Gastly[] = INCBIN_U8("graphics/pokemon/gastly/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Gastly[] = INCBIN_U8("graphics/pokemon/gastly/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Gastly[] = INCBIN_COMP("graphics/pokemon/gastly/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Gastly[] = INCBIN_U32("graphics/pokemon/gastly/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Gastly[] = INCBIN_U32("graphics/pokemon/gastly/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Haunter[] = INCBIN_U32("graphics/pokemon/haunter/anim_front.4bpp.lz");
    const u32 gMonPalette_Haunter[] = INCBIN_U32("graphics/pokemon/haunter/normal.gbapal.lz");
    const u32 gMonBackPic_Haunter[] = INCBIN_U32("graphics/pokemon/haunter/back.4bpp.lz");
    const u32 gMonShinyPalette_Haunter[] = INCBIN_U32("graphics/pokemon/haunter/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Haunter[] = INCBIN_U32("graphics/pokemon/haunter/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Haunter[] = INCBIN_U32("graphics/pokemon/haunter/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Haunter[] = INCBIN_U32("graphics/pokemon/haunter/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Haunter[] = INCBIN_U32("graphics/pokemon/haunter/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Haunter[] = INCBIN_U8("graphics/pokemon/haunter/icon.4bpp");
#else
    const u8 gMonIcon_Haunter[] = INCBIN_U8("graphics/pokemon/haunter/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Haunter[] = INCBIN_U8("graphics/pokemon/haunter/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Haunter[] = INCBIN_COMP("graphics/pokemon/haunter/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Haunter[] = INCBIN_U32("graphics/pokemon/haunter/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Haunter[] = INCBIN_U32("graphics/pokemon/haunter/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Gengar[] = INCBIN_U32("graphics/pokemon/gengar/anim_front.4bpp.lz");
    const u32 gMonPalette_Gengar[] = INCBIN_U32("graphics/pokemon/gengar/normal.gbapal.lz");
    const u32 gMonBackPic_Gengar[] = INCBIN_U32("graphics/pokemon/gengar/back.4bpp.lz");
    const u32 gMonShinyPalette_Gengar[] = INCBIN_U32("graphics/pokemon/gengar/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Gengar[] = INCBIN_U32("graphics/pokemon/gengar/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Gengar[] = INCBIN_U32("graphics/pokemon/gengar/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Gengar[] = INCBIN_U32("graphics/pokemon/gengar/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Gengar[] = INCBIN_U32("graphics/pokemon/gengar/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Gengar[] = INCBIN_U8("graphics/pokemon/gengar/icon.4bpp");
#else
    const u8 gMonIcon_Gengar[] = INCBIN_U8("graphics/pokemon/gengar/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Gengar[] = INCBIN_U8("graphics/pokemon/gengar/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Gengar[] = INCBIN_COMP("graphics/pokemon/gengar/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Gengar[] = INCBIN_U32("graphics/pokemon/gengar/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Gengar[] = INCBIN_U32("graphics/pokemon/gengar/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_GASTLY

#if P_FAMILY_ONIX
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Onix[] = INCBIN_U32("graphics/pokemon/onix/anim_front.4bpp.lz");
    const u32 gMonPalette_Onix[] = INCBIN_U32("graphics/pokemon/onix/normal.gbapal.lz");
    const u32 gMonBackPic_Onix[] = INCBIN_U32("graphics/pokemon/onix/back.4bpp.lz");
    const u32 gMonShinyPalette_Onix[] = INCBIN_U32("graphics/pokemon/onix/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Onix[] = INCBIN_U32("graphics/pokemon/onix/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Onix[] = INCBIN_U32("graphics/pokemon/onix/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Onix[] = INCBIN_U32("graphics/pokemon/onix/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Onix[] = INCBIN_U32("graphics/pokemon/onix/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Onix[] = INCBIN_U8("graphics/pokemon/onix/icon.4bpp");
#else
    const u8 gMonIcon_Onix[] = INCBIN_U8("graphics/pokemon/onix/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Onix[] = INCBIN_U8("graphics/pokemon/onix/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Onix[] = INCBIN_COMP("graphics/pokemon/onix/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Onix[] = INCBIN_U32("graphics/pokemon/onix/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Onix[] = INCBIN_U32("graphics/pokemon/onix/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GEN_2_CROSS_EVOS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Steelix[] = INCBIN_U32("graphics/pokemon/steelix/anim_front.4bpp.lz");
    const u32 gMonPalette_Steelix[] = INCBIN_U32("graphics/pokemon/steelix/normal.gbapal.lz");
    const u32 gMonBackPic_Steelix[] = INCBIN_U32("graphics/pokemon/steelix/back.4bpp.lz");
    const u32 gMonShinyPalette_Steelix[] = INCBIN_U32("graphics/pokemon/steelix/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Steelix[] = INCBIN_U32("graphics/pokemon/steelix/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Steelix[] = INCBIN_U32("graphics/pokemon/steelix/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Steelix[] = INCBIN_U32("graphics/pokemon/steelix/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Steelix[] = INCBIN_U32("graphics/pokemon/steelix/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Steelix[] = INCBIN_U8("graphics/pokemon/steelix/icon.4bpp");
#else
    const u8 gMonIcon_Steelix[] = INCBIN_U8("graphics/pokemon/steelix/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Steelix[] = INCBIN_U8("graphics/pokemon/steelix/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Steelix[] = INCBIN_COMP("graphics/pokemon/steelix/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Steelix[] = INCBIN_U32("graphics/pokemon/steelix/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Steelix[] = INCBIN_U32("graphics/pokemon/steelix/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_SteelixF[] = INCBIN_U32("graphics/pokemon/steelix/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_SteelixF[] = INCBIN_U32("graphics/pokemon/steelix/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_SteelixF[] = INCBIN_COMP("graphics/pokemon/steelix/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_GEN_2_CROSS_EVOS
#endif //P_FAMILY_ONIX

#if P_FAMILY_DROWZEE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Drowzee[] = INCBIN_U32("graphics/pokemon/drowzee/anim_front.4bpp.lz");
    const u32 gMonPalette_Drowzee[] = INCBIN_U32("graphics/pokemon/drowzee/normal.gbapal.lz");
    const u32 gMonBackPic_Drowzee[] = INCBIN_U32("graphics/pokemon/drowzee/back.4bpp.lz");
    const u32 gMonShinyPalette_Drowzee[] = INCBIN_U32("graphics/pokemon/drowzee/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Drowzee[] = INCBIN_U32("graphics/pokemon/drowzee/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Drowzee[] = INCBIN_U32("graphics/pokemon/drowzee/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Drowzee[] = INCBIN_U32("graphics/pokemon/drowzee/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Drowzee[] = INCBIN_U32("graphics/pokemon/drowzee/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Drowzee[] = INCBIN_U8("graphics/pokemon/drowzee/icon.4bpp");
#else
    const u8 gMonIcon_Drowzee[] = INCBIN_U8("graphics/pokemon/drowzee/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Drowzee[] = INCBIN_U8("graphics/pokemon/drowzee/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Drowzee[] = INCBIN_COMP("graphics/pokemon/drowzee/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Drowzee[] = INCBIN_U32("graphics/pokemon/drowzee/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Drowzee[] = INCBIN_U32("graphics/pokemon/drowzee/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Hypno[] = INCBIN_U32("graphics/pokemon/hypno/anim_front.4bpp.lz");
    const u32 gMonPalette_Hypno[] = INCBIN_U32("graphics/pokemon/hypno/normal.gbapal.lz");
    const u32 gMonBackPic_Hypno[] = INCBIN_U32("graphics/pokemon/hypno/back.4bpp.lz");
    const u32 gMonShinyPalette_Hypno[] = INCBIN_U32("graphics/pokemon/hypno/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Hypno[] = INCBIN_U32("graphics/pokemon/hypno/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Hypno[] = INCBIN_U32("graphics/pokemon/hypno/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Hypno[] = INCBIN_U32("graphics/pokemon/hypno/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Hypno[] = INCBIN_U32("graphics/pokemon/hypno/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Hypno[] = INCBIN_U8("graphics/pokemon/hypno/icon.4bpp");
#else
    const u8 gMonIcon_Hypno[] = INCBIN_U8("graphics/pokemon/hypno/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Hypno[] = INCBIN_U8("graphics/pokemon/hypno/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Hypno[] = INCBIN_COMP("graphics/pokemon/hypno/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Hypno[] = INCBIN_U32("graphics/pokemon/hypno/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Hypno[] = INCBIN_U32("graphics/pokemon/hypno/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_HypnoF[] = INCBIN_U32("graphics/pokemon/hypno/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_HypnoF[] = INCBIN_U32("graphics/pokemon/hypno/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_HypnoF[] = INCBIN_COMP("graphics/pokemon/hypno/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_DROWZEE

#if P_FAMILY_KRABBY
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Krabby[] = INCBIN_U32("graphics/pokemon/krabby/anim_front.4bpp.lz");
    const u32 gMonPalette_Krabby[] = INCBIN_U32("graphics/pokemon/krabby/normal.gbapal.lz");
    const u32 gMonBackPic_Krabby[] = INCBIN_U32("graphics/pokemon/krabby/back.4bpp.lz");
    const u32 gMonShinyPalette_Krabby[] = INCBIN_U32("graphics/pokemon/krabby/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Krabby[] = INCBIN_U32("graphics/pokemon/krabby/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Krabby[] = INCBIN_U32("graphics/pokemon/krabby/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Krabby[] = INCBIN_U32("graphics/pokemon/krabby/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Krabby[] = INCBIN_U32("graphics/pokemon/krabby/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Krabby[] = INCBIN_U8("graphics/pokemon/krabby/icon.4bpp");
#else
    const u8 gMonIcon_Krabby[] = INCBIN_U8("graphics/pokemon/krabby/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Krabby[] = INCBIN_U8("graphics/pokemon/krabby/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Krabby[] = INCBIN_COMP("graphics/pokemon/krabby/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Krabby[] = INCBIN_U32("graphics/pokemon/krabby/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Krabby[] = INCBIN_U32("graphics/pokemon/krabby/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Kingler[] = INCBIN_U32("graphics/pokemon/kingler/anim_front.4bpp.lz");
    const u32 gMonPalette_Kingler[] = INCBIN_U32("graphics/pokemon/kingler/normal.gbapal.lz");
    const u32 gMonBackPic_Kingler[] = INCBIN_U32("graphics/pokemon/kingler/back.4bpp.lz");
    const u32 gMonShinyPalette_Kingler[] = INCBIN_U32("graphics/pokemon/kingler/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Kingler[] = INCBIN_U32("graphics/pokemon/kingler/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Kingler[] = INCBIN_U32("graphics/pokemon/kingler/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Kingler[] = INCBIN_U32("graphics/pokemon/kingler/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Kingler[] = INCBIN_U32("graphics/pokemon/kingler/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Kingler[] = INCBIN_U8("graphics/pokemon/kingler/icon.4bpp");
#else
    const u8 gMonIcon_Kingler[] = INCBIN_U8("graphics/pokemon/kingler/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Kingler[] = INCBIN_U8("graphics/pokemon/kingler/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Kingler[] = INCBIN_COMP("graphics/pokemon/kingler/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Kingler[] = INCBIN_U32("graphics/pokemon/kingler/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Kingler[] = INCBIN_U32("graphics/pokemon/kingler/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_KRABBY

#if P_FAMILY_VOLTORB
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Voltorb[] = INCBIN_U32("graphics/pokemon/voltorb/anim_front.4bpp.lz");
    const u32 gMonPalette_Voltorb[] = INCBIN_U32("graphics/pokemon/voltorb/normal.gbapal.lz");
    const u32 gMonBackPic_Voltorb[] = INCBIN_U32("graphics/pokemon/voltorb/back.4bpp.lz");
    const u32 gMonShinyPalette_Voltorb[] = INCBIN_U32("graphics/pokemon/voltorb/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Voltorb[] = INCBIN_U32("graphics/pokemon/voltorb/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Voltorb[] = INCBIN_U32("graphics/pokemon/voltorb/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Voltorb[] = INCBIN_U32("graphics/pokemon/voltorb/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Voltorb[] = INCBIN_U32("graphics/pokemon/voltorb/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Voltorb[] = INCBIN_U8("graphics/pokemon/voltorb/icon.4bpp");
#else
    const u8 gMonIcon_Voltorb[] = INCBIN_U8("graphics/pokemon/voltorb/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Voltorb[] = INCBIN_U8("graphics/pokemon/voltorb/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Voltorb[] = INCBIN_COMP("graphics/pokemon/voltorb/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Voltorb[] = INCBIN_U32("graphics/pokemon/voltorb/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Voltorb[] = INCBIN_U32("graphics/pokemon/voltorb/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Electrode[] = INCBIN_U32("graphics/pokemon/electrode/anim_front.4bpp.lz");
    const u32 gMonPalette_Electrode[] = INCBIN_U32("graphics/pokemon/electrode/normal.gbapal.lz");
    const u32 gMonBackPic_Electrode[] = INCBIN_U32("graphics/pokemon/electrode/back.4bpp.lz");
    const u32 gMonShinyPalette_Electrode[] = INCBIN_U32("graphics/pokemon/electrode/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Electrode[] = INCBIN_U32("graphics/pokemon/electrode/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Electrode[] = INCBIN_U32("graphics/pokemon/electrode/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Electrode[] = INCBIN_U32("graphics/pokemon/electrode/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Electrode[] = INCBIN_U32("graphics/pokemon/electrode/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Electrode[] = INCBIN_U8("graphics/pokemon/electrode/icon.4bpp");
#else
    const u8 gMonIcon_Electrode[] = INCBIN_U8("graphics/pokemon/electrode/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Electrode[] = INCBIN_U8("graphics/pokemon/electrode/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Electrode[] = INCBIN_COMP("graphics/pokemon/electrode/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Electrode[] = INCBIN_U32("graphics/pokemon/electrode/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Electrode[] = INCBIN_U32("graphics/pokemon/electrode/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_VOLTORB

#if P_FAMILY_EXEGGCUTE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Exeggcute[] = INCBIN_U32("graphics/pokemon/exeggcute/anim_front.4bpp.lz");
    const u32 gMonPalette_Exeggcute[] = INCBIN_U32("graphics/pokemon/exeggcute/normal.gbapal.lz");
    const u32 gMonBackPic_Exeggcute[] = INCBIN_U32("graphics/pokemon/exeggcute/back.4bpp.lz");
    const u32 gMonShinyPalette_Exeggcute[] = INCBIN_U32("graphics/pokemon/exeggcute/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Exeggcute[] = INCBIN_U32("graphics/pokemon/exeggcute/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Exeggcute[] = INCBIN_U32("graphics/pokemon/exeggcute/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Exeggcute[] = INCBIN_U32("graphics/pokemon/exeggcute/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Exeggcute[] = INCBIN_U32("graphics/pokemon/exeggcute/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Exeggcute[] = INCBIN_U8("graphics/pokemon/exeggcute/icon.4bpp");
#else
    const u8 gMonIcon_Exeggcute[] = INCBIN_U8("graphics/pokemon/exeggcute/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Exeggcute[] = INCBIN_U8("graphics/pokemon/exeggcute/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Exeggcute[] = INCBIN_COMP("graphics/pokemon/exeggcute/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Exeggcute[] = INCBIN_U32("graphics/pokemon/exeggcute/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Exeggcute[] = INCBIN_U32("graphics/pokemon/exeggcute/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Exeggutor[] = INCBIN_U32("graphics/pokemon/exeggutor/anim_front.4bpp.lz");
    const u32 gMonPalette_Exeggutor[] = INCBIN_U32("graphics/pokemon/exeggutor/normal.gbapal.lz");
    const u32 gMonBackPic_Exeggutor[] = INCBIN_U32("graphics/pokemon/exeggutor/back.4bpp.lz");
    const u32 gMonShinyPalette_Exeggutor[] = INCBIN_U32("graphics/pokemon/exeggutor/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Exeggutor[] = INCBIN_U32("graphics/pokemon/exeggutor/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Exeggutor[] = INCBIN_U32("graphics/pokemon/exeggutor/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Exeggutor[] = INCBIN_U32("graphics/pokemon/exeggutor/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Exeggutor[] = INCBIN_U32("graphics/pokemon/exeggutor/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Exeggutor[] = INCBIN_U8("graphics/pokemon/exeggutor/icon.4bpp");
#else
    const u8 gMonIcon_Exeggutor[] = INCBIN_U8("graphics/pokemon/exeggutor/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Exeggutor[] = INCBIN_U8("graphics/pokemon/exeggutor/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Exeggutor[] = INCBIN_COMP("graphics/pokemon/exeggutor/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Exeggutor[] = INCBIN_U32("graphics/pokemon/exeggutor/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Exeggutor[] = INCBIN_U32("graphics/pokemon/exeggutor/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_EXEGGCUTE

#if P_FAMILY_CUBONE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Cubone[] = INCBIN_U32("graphics/pokemon/cubone/anim_front.4bpp.lz");
    const u32 gMonPalette_Cubone[] = INCBIN_U32("graphics/pokemon/cubone/normal.gbapal.lz");
    const u32 gMonBackPic_Cubone[] = INCBIN_U32("graphics/pokemon/cubone/back.4bpp.lz");
    const u32 gMonShinyPalette_Cubone[] = INCBIN_U32("graphics/pokemon/cubone/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Cubone[] = INCBIN_U32("graphics/pokemon/cubone/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Cubone[] = INCBIN_U32("graphics/pokemon/cubone/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Cubone[] = INCBIN_U32("graphics/pokemon/cubone/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Cubone[] = INCBIN_U32("graphics/pokemon/cubone/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Cubone[] = INCBIN_U8("graphics/pokemon/cubone/icon.4bpp");
#else
    const u8 gMonIcon_Cubone[] = INCBIN_U8("graphics/pokemon/cubone/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Cubone[] = INCBIN_U8("graphics/pokemon/cubone/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Cubone[] = INCBIN_COMP("graphics/pokemon/cubone/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Cubone[] = INCBIN_U32("graphics/pokemon/cubone/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Cubone[] = INCBIN_U32("graphics/pokemon/cubone/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Marowak[] = INCBIN_U32("graphics/pokemon/marowak/anim_front.4bpp.lz");
    const u32 gMonPalette_Marowak[] = INCBIN_U32("graphics/pokemon/marowak/normal.gbapal.lz");
    const u32 gMonBackPic_Marowak[] = INCBIN_U32("graphics/pokemon/marowak/back.4bpp.lz");
    const u32 gMonShinyPalette_Marowak[] = INCBIN_U32("graphics/pokemon/marowak/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Marowak[] = INCBIN_U32("graphics/pokemon/marowak/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Marowak[] = INCBIN_U32("graphics/pokemon/marowak/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Marowak[] = INCBIN_U32("graphics/pokemon/marowak/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Marowak[] = INCBIN_U32("graphics/pokemon/marowak/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Marowak[] = INCBIN_U8("graphics/pokemon/marowak/icon.4bpp");
#else
    const u8 gMonIcon_Marowak[] = INCBIN_U8("graphics/pokemon/marowak/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Marowak[] = INCBIN_U8("graphics/pokemon/marowak/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Marowak[] = INCBIN_COMP("graphics/pokemon/marowak/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Marowak[] = INCBIN_U32("graphics/pokemon/marowak/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Marowak[] = INCBIN_U32("graphics/pokemon/marowak/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_CUBONE

#if P_FAMILY_HITMONS
#if P_GEN_2_CROSS_EVOS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Tyrogue[] = INCBIN_U32("graphics/pokemon/tyrogue/anim_front.4bpp.lz");
    const u32 gMonPalette_Tyrogue[] = INCBIN_U32("graphics/pokemon/tyrogue/normal.gbapal.lz");
    const u32 gMonBackPic_Tyrogue[] = INCBIN_U32("graphics/pokemon/tyrogue/back.4bpp.lz");
    const u32 gMonShinyPalette_Tyrogue[] = INCBIN_U32("graphics/pokemon/tyrogue/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Tyrogue[] = INCBIN_U32("graphics/pokemon/tyrogue/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Tyrogue[] = INCBIN_U32("graphics/pokemon/tyrogue/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Tyrogue[] = INCBIN_U32("graphics/pokemon/tyrogue/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Tyrogue[] = INCBIN_U32("graphics/pokemon/tyrogue/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Tyrogue[] = INCBIN_U8("graphics/pokemon/tyrogue/icon.4bpp");
#else
    const u8 gMonIcon_Tyrogue[] = INCBIN_U8("graphics/pokemon/tyrogue/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Tyrogue[] = INCBIN_U8("graphics/pokemon/tyrogue/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Tyrogue[] = INCBIN_COMP("graphics/pokemon/tyrogue/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Tyrogue[] = INCBIN_U32("graphics/pokemon/tyrogue/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Tyrogue[] = INCBIN_U32("graphics/pokemon/tyrogue/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_2_CROSS_EVOS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Hitmonlee[] = INCBIN_U32("graphics/pokemon/hitmonlee/anim_front.4bpp.lz");
    const u32 gMonPalette_Hitmonlee[] = INCBIN_U32("graphics/pokemon/hitmonlee/normal.gbapal.lz");
    const u32 gMonBackPic_Hitmonlee[] = INCBIN_U32("graphics/pokemon/hitmonlee/back.4bpp.lz");
    const u32 gMonShinyPalette_Hitmonlee[] = INCBIN_U32("graphics/pokemon/hitmonlee/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Hitmonlee[] = INCBIN_U32("graphics/pokemon/hitmonlee/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Hitmonlee[] = INCBIN_U32("graphics/pokemon/hitmonlee/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Hitmonlee[] = INCBIN_U32("graphics/pokemon/hitmonlee/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Hitmonlee[] = INCBIN_U32("graphics/pokemon/hitmonlee/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Hitmonlee[] = INCBIN_U8("graphics/pokemon/hitmonlee/icon.4bpp");
#else
    const u8 gMonIcon_Hitmonlee[] = INCBIN_U8("graphics/pokemon/hitmonlee/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Hitmonlee[] = INCBIN_U8("graphics/pokemon/hitmonlee/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Hitmonlee[] = INCBIN_COMP("graphics/pokemon/hitmonlee/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Hitmonlee[] = INCBIN_U32("graphics/pokemon/hitmonlee/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Hitmonlee[] = INCBIN_U32("graphics/pokemon/hitmonlee/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Hitmonchan[] = INCBIN_U32("graphics/pokemon/hitmonchan/anim_front.4bpp.lz");
    const u32 gMonPalette_Hitmonchan[] = INCBIN_U32("graphics/pokemon/hitmonchan/normal.gbapal.lz");
    const u32 gMonBackPic_Hitmonchan[] = INCBIN_U32("graphics/pokemon/hitmonchan/back.4bpp.lz");
    const u32 gMonShinyPalette_Hitmonchan[] = INCBIN_U32("graphics/pokemon/hitmonchan/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Hitmonchan[] = INCBIN_U32("graphics/pokemon/hitmonchan/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Hitmonchan[] = INCBIN_U32("graphics/pokemon/hitmonchan/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Hitmonchan[] = INCBIN_U32("graphics/pokemon/hitmonchan/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Hitmonchan[] = INCBIN_U32("graphics/pokemon/hitmonchan/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Hitmonchan[] = INCBIN_U8("graphics/pokemon/hitmonchan/icon.4bpp");
#else
    const u8 gMonIcon_Hitmonchan[] = INCBIN_U8("graphics/pokemon/hitmonchan/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Hitmonchan[] = INCBIN_U8("graphics/pokemon/hitmonchan/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Hitmonchan[] = INCBIN_COMP("graphics/pokemon/hitmonchan/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Hitmonchan[] = INCBIN_U32("graphics/pokemon/hitmonchan/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Hitmonchan[] = INCBIN_U32("graphics/pokemon/hitmonchan/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GEN_2_CROSS_EVOS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Hitmontop[] = INCBIN_U32("graphics/pokemon/hitmontop/anim_front.4bpp.lz");
    const u32 gMonPalette_Hitmontop[] = INCBIN_U32("graphics/pokemon/hitmontop/normal.gbapal.lz");
    const u32 gMonBackPic_Hitmontop[] = INCBIN_U32("graphics/pokemon/hitmontop/back.4bpp.lz");
    const u32 gMonShinyPalette_Hitmontop[] = INCBIN_U32("graphics/pokemon/hitmontop/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Hitmontop[] = INCBIN_U32("graphics/pokemon/hitmontop/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Hitmontop[] = INCBIN_U32("graphics/pokemon/hitmontop/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Hitmontop[] = INCBIN_U32("graphics/pokemon/hitmontop/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Hitmontop[] = INCBIN_U32("graphics/pokemon/hitmontop/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Hitmontop[] = INCBIN_U8("graphics/pokemon/hitmontop/icon.4bpp");
#else
    const u8 gMonIcon_Hitmontop[] = INCBIN_U8("graphics/pokemon/hitmontop/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Hitmontop[] = INCBIN_U8("graphics/pokemon/hitmontop/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Hitmontop[] = INCBIN_COMP("graphics/pokemon/hitmontop/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Hitmontop[] = INCBIN_U32("graphics/pokemon/hitmontop/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Hitmontop[] = INCBIN_U32("graphics/pokemon/hitmontop/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_2_CROSS_EVOS
#endif //P_FAMILY_HITMONS

#if P_FAMILY_LICKITUNG
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Lickitung[] = INCBIN_U32("graphics/pokemon/lickitung/anim_front.4bpp.lz");
    const u32 gMonPalette_Lickitung[] = INCBIN_U32("graphics/pokemon/lickitung/normal.gbapal.lz");
    const u32 gMonBackPic_Lickitung[] = INCBIN_U32("graphics/pokemon/lickitung/back.4bpp.lz");
    const u32 gMonShinyPalette_Lickitung[] = INCBIN_U32("graphics/pokemon/lickitung/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Lickitung[] = INCBIN_U32("graphics/pokemon/lickitung/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Lickitung[] = INCBIN_U32("graphics/pokemon/lickitung/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Lickitung[] = INCBIN_U32("graphics/pokemon/lickitung/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Lickitung[] = INCBIN_U32("graphics/pokemon/lickitung/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Lickitung[] = INCBIN_U8("graphics/pokemon/lickitung/icon.4bpp");
#else
    const u8 gMonIcon_Lickitung[] = INCBIN_U8("graphics/pokemon/lickitung/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Lickitung[] = INCBIN_U8("graphics/pokemon/lickitung/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Lickitung[] = INCBIN_COMP("graphics/pokemon/lickitung/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Lickitung[] = INCBIN_U32("graphics/pokemon/lickitung/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Lickitung[] = INCBIN_U32("graphics/pokemon/lickitung/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Lickilicky[] = INCBIN_U32("graphics/pokemon/lickilicky/anim_front.4bpp.lz");
    const u32 gMonPalette_Lickilicky[] = INCBIN_U32("graphics/pokemon/lickilicky/normal.gbapal.lz");
    const u32 gMonBackPic_Lickilicky[] = INCBIN_U32("graphics/pokemon/lickilicky/back.4bpp.lz");
    const u32 gMonShinyPalette_Lickilicky[] = INCBIN_U32("graphics/pokemon/lickilicky/shiny.gbapal.lz");
    const u8 gMonIcon_Lickilicky[] = INCBIN_U8("graphics/pokemon/lickilicky/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Lickilicky[] = INCBIN_U8("graphics/pokemon/lickilicky/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Lickilicky[] = INCBIN_COMP("graphics/pokemon/lickilicky/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Lickilicky[] = INCBIN_U32("graphics/pokemon/lickilicky/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Lickilicky[] = INCBIN_U32("graphics/pokemon/lickilicky/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_LICKITUNG

#if P_FAMILY_KOFFING
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Koffing[] = INCBIN_U32("graphics/pokemon/koffing/anim_front.4bpp.lz");
    const u32 gMonPalette_Koffing[] = INCBIN_U32("graphics/pokemon/koffing/normal.gbapal.lz");
    const u32 gMonBackPic_Koffing[] = INCBIN_U32("graphics/pokemon/koffing/back.4bpp.lz");
    const u32 gMonShinyPalette_Koffing[] = INCBIN_U32("graphics/pokemon/koffing/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Koffing[] = INCBIN_U32("graphics/pokemon/koffing/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Koffing[] = INCBIN_U32("graphics/pokemon/koffing/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Koffing[] = INCBIN_U32("graphics/pokemon/koffing/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Koffing[] = INCBIN_U32("graphics/pokemon/koffing/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Koffing[] = INCBIN_U8("graphics/pokemon/koffing/icon.4bpp");
#else
    const u8 gMonIcon_Koffing[] = INCBIN_U8("graphics/pokemon/koffing/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Koffing[] = INCBIN_U8("graphics/pokemon/koffing/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Koffing[] = INCBIN_COMP("graphics/pokemon/koffing/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Koffing[] = INCBIN_U32("graphics/pokemon/koffing/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Koffing[] = INCBIN_U32("graphics/pokemon/koffing/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Weezing[] = INCBIN_U32("graphics/pokemon/weezing/anim_front.4bpp.lz");
    const u32 gMonPalette_Weezing[] = INCBIN_U32("graphics/pokemon/weezing/normal.gbapal.lz");
    const u32 gMonBackPic_Weezing[] = INCBIN_U32("graphics/pokemon/weezing/back.4bpp.lz");
    const u32 gMonShinyPalette_Weezing[] = INCBIN_U32("graphics/pokemon/weezing/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Weezing[] = INCBIN_U32("graphics/pokemon/weezing/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Weezing[] = INCBIN_U32("graphics/pokemon/weezing/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Weezing[] = INCBIN_U32("graphics/pokemon/weezing/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Weezing[] = INCBIN_U32("graphics/pokemon/weezing/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Weezing[] = INCBIN_U8("graphics/pokemon/weezing/icon.4bpp");
#else
    const u8 gMonIcon_Weezing[] = INCBIN_U8("graphics/pokemon/weezing/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Weezing[] = INCBIN_U8("graphics/pokemon/weezing/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Weezing[] = INCBIN_COMP("graphics/pokemon/weezing/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Weezing[] = INCBIN_U32("graphics/pokemon/weezing/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Weezing[] = INCBIN_U32("graphics/pokemon/weezing/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_KOFFING

#if P_FAMILY_RHYHORN
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Rhyhorn[] = INCBIN_U32("graphics/pokemon/rhyhorn/anim_front.4bpp.lz");
    const u32 gMonPalette_Rhyhorn[] = INCBIN_U32("graphics/pokemon/rhyhorn/normal.gbapal.lz");
    const u32 gMonBackPic_Rhyhorn[] = INCBIN_U32("graphics/pokemon/rhyhorn/back.4bpp.lz");
    const u32 gMonShinyPalette_Rhyhorn[] = INCBIN_U32("graphics/pokemon/rhyhorn/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Rhyhorn[] = INCBIN_U32("graphics/pokemon/rhyhorn/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Rhyhorn[] = INCBIN_U32("graphics/pokemon/rhyhorn/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Rhyhorn[] = INCBIN_U32("graphics/pokemon/rhyhorn/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Rhyhorn[] = INCBIN_U32("graphics/pokemon/rhyhorn/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Rhyhorn[] = INCBIN_U8("graphics/pokemon/rhyhorn/icon.4bpp");
#else
    const u8 gMonIcon_Rhyhorn[] = INCBIN_U8("graphics/pokemon/rhyhorn/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Rhyhorn[] = INCBIN_U8("graphics/pokemon/rhyhorn/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Rhyhorn[] = INCBIN_COMP("graphics/pokemon/rhyhorn/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Rhyhorn[] = INCBIN_U32("graphics/pokemon/rhyhorn/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Rhyhorn[] = INCBIN_U32("graphics/pokemon/rhyhorn/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_RhyhornF[] = INCBIN_U32("graphics/pokemon/rhyhorn/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_RhyhornF[] = INCBIN_U32("graphics/pokemon/rhyhorn/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_RhyhornF[] = INCBIN_COMP("graphics/pokemon/rhyhorn/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Rhydon[] = INCBIN_U32("graphics/pokemon/rhydon/anim_front.4bpp.lz");
    const u32 gMonPalette_Rhydon[] = INCBIN_U32("graphics/pokemon/rhydon/normal.gbapal.lz");
    const u32 gMonBackPic_Rhydon[] = INCBIN_U32("graphics/pokemon/rhydon/back.4bpp.lz");
    const u32 gMonShinyPalette_Rhydon[] = INCBIN_U32("graphics/pokemon/rhydon/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Rhydon[] = INCBIN_U32("graphics/pokemon/rhydon/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Rhydon[] = INCBIN_U32("graphics/pokemon/rhydon/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Rhydon[] = INCBIN_U32("graphics/pokemon/rhydon/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Rhydon[] = INCBIN_U32("graphics/pokemon/rhydon/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Rhydon[] = INCBIN_U8("graphics/pokemon/rhydon/icon.4bpp");
#else
    const u8 gMonIcon_Rhydon[] = INCBIN_U8("graphics/pokemon/rhydon/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Rhydon[] = INCBIN_U8("graphics/pokemon/rhydon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Rhydon[] = INCBIN_COMP("graphics/pokemon/rhydon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Rhydon[] = INCBIN_U32("graphics/pokemon/rhydon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Rhydon[] = INCBIN_U32("graphics/pokemon/rhydon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_RhydonF[] = INCBIN_U32("graphics/pokemon/rhydon/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_RhydonF[] = INCBIN_U32("graphics/pokemon/rhydon/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_RhydonF[] = INCBIN_COMP("graphics/pokemon/rhydon/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Rhyperior[] = INCBIN_U32("graphics/pokemon/rhyperior/anim_front.4bpp.lz");
    const u32 gMonPalette_Rhyperior[] = INCBIN_U32("graphics/pokemon/rhyperior/normal.gbapal.lz");
    const u32 gMonBackPic_Rhyperior[] = INCBIN_U32("graphics/pokemon/rhyperior/back.4bpp.lz");
    const u32 gMonShinyPalette_Rhyperior[] = INCBIN_U32("graphics/pokemon/rhyperior/shiny.gbapal.lz");
    const u8 gMonIcon_Rhyperior[] = INCBIN_U8("graphics/pokemon/rhyperior/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Rhyperior[] = INCBIN_U8("graphics/pokemon/rhyperior/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Rhyperior[] = INCBIN_COMP("graphics/pokemon/rhyperior/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Rhyperior[] = INCBIN_U32("graphics/pokemon/rhyperior/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Rhyperior[] = INCBIN_U32("graphics/pokemon/rhyperior/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_RhyperiorF[] = INCBIN_U32("graphics/pokemon/rhyperior/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_RhyperiorF[] = INCBIN_U32("graphics/pokemon/rhyperior/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_RhyperiorF[] = INCBIN_COMP("graphics/pokemon/rhyperior/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_RHYHORN

#if P_FAMILY_CHANSEY
#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Happiny[] = INCBIN_U32("graphics/pokemon/happiny/anim_front.4bpp.lz");
    const u32 gMonPalette_Happiny[] = INCBIN_U32("graphics/pokemon/happiny/normal.gbapal.lz");
    const u32 gMonBackPic_Happiny[] = INCBIN_U32("graphics/pokemon/happiny/back.4bpp.lz");
    const u32 gMonShinyPalette_Happiny[] = INCBIN_U32("graphics/pokemon/happiny/shiny.gbapal.lz");
    const u8 gMonIcon_Happiny[] = INCBIN_U8("graphics/pokemon/happiny/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Happiny[] = INCBIN_U8("graphics/pokemon/happiny/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Happiny[] = INCBIN_COMP("graphics/pokemon/happiny/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Happiny[] = INCBIN_U32("graphics/pokemon/happiny/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Happiny[] = INCBIN_U32("graphics/pokemon/happiny/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_4_CROSS_EVOS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Chansey[] = INCBIN_U32("graphics/pokemon/chansey/anim_front.4bpp.lz");
    const u32 gMonPalette_Chansey[] = INCBIN_U32("graphics/pokemon/chansey/normal.gbapal.lz");
    const u32 gMonBackPic_Chansey[] = INCBIN_U32("graphics/pokemon/chansey/back.4bpp.lz");
    const u32 gMonShinyPalette_Chansey[] = INCBIN_U32("graphics/pokemon/chansey/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Chansey[] = INCBIN_U32("graphics/pokemon/chansey/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Chansey[] = INCBIN_U32("graphics/pokemon/chansey/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Chansey[] = INCBIN_U32("graphics/pokemon/chansey/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Chansey[] = INCBIN_U32("graphics/pokemon/chansey/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Chansey[] = INCBIN_U8("graphics/pokemon/chansey/icon.4bpp");
#else
    const u8 gMonIcon_Chansey[] = INCBIN_U8("graphics/pokemon/chansey/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Chansey[] = INCBIN_U8("graphics/pokemon/chansey/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Chansey[] = INCBIN_COMP("graphics/pokemon/chansey/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Chansey[] = INCBIN_U32("graphics/pokemon/chansey/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Chansey[] = INCBIN_U32("graphics/pokemon/chansey/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GEN_2_CROSS_EVOS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Blissey[] = INCBIN_U32("graphics/pokemon/blissey/anim_front.4bpp.lz");
    const u32 gMonPalette_Blissey[] = INCBIN_U32("graphics/pokemon/blissey/normal.gbapal.lz");
    const u32 gMonBackPic_Blissey[] = INCBIN_U32("graphics/pokemon/blissey/back.4bpp.lz");
    const u32 gMonShinyPalette_Blissey[] = INCBIN_U32("graphics/pokemon/blissey/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Blissey[] = INCBIN_U32("graphics/pokemon/blissey/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Blissey[] = INCBIN_U32("graphics/pokemon/blissey/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Blissey[] = INCBIN_U32("graphics/pokemon/blissey/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Blissey[] = INCBIN_U32("graphics/pokemon/blissey/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Blissey[] = INCBIN_U8("graphics/pokemon/blissey/icon.4bpp");
#else
    const u8 gMonIcon_Blissey[] = INCBIN_U8("graphics/pokemon/blissey/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Blissey[] = INCBIN_U8("graphics/pokemon/blissey/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Blissey[] = INCBIN_COMP("graphics/pokemon/blissey/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Blissey[] = INCBIN_U32("graphics/pokemon/blissey/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Blissey[] = INCBIN_U32("graphics/pokemon/blissey/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_2_CROSS_EVOS
#endif //P_FAMILY_CHANSEY

#if P_FAMILY_TANGELA
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Tangela[] = INCBIN_U32("graphics/pokemon/tangela/anim_front.4bpp.lz");
    const u32 gMonPalette_Tangela[] = INCBIN_U32("graphics/pokemon/tangela/normal.gbapal.lz");
    const u32 gMonBackPic_Tangela[] = INCBIN_U32("graphics/pokemon/tangela/back.4bpp.lz");
    const u32 gMonShinyPalette_Tangela[] = INCBIN_U32("graphics/pokemon/tangela/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Tangela[] = INCBIN_U32("graphics/pokemon/tangela/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Tangela[] = INCBIN_U32("graphics/pokemon/tangela/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Tangela[] = INCBIN_U32("graphics/pokemon/tangela/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Tangela[] = INCBIN_U32("graphics/pokemon/tangela/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Tangela[] = INCBIN_U8("graphics/pokemon/tangela/icon.4bpp");
#else
    const u8 gMonIcon_Tangela[] = INCBIN_U8("graphics/pokemon/tangela/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Tangela[] = INCBIN_U8("graphics/pokemon/tangela/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Tangela[] = INCBIN_COMP("graphics/pokemon/tangela/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Tangela[] = INCBIN_U32("graphics/pokemon/tangela/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Tangela[] = INCBIN_U32("graphics/pokemon/tangela/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Tangrowth[] = INCBIN_U32("graphics/pokemon/tangrowth/anim_front.4bpp.lz");
    const u32 gMonPalette_Tangrowth[] = INCBIN_U32("graphics/pokemon/tangrowth/normal.gbapal.lz");
    const u32 gMonBackPic_Tangrowth[] = INCBIN_U32("graphics/pokemon/tangrowth/back.4bpp.lz");
    const u32 gMonShinyPalette_Tangrowth[] = INCBIN_U32("graphics/pokemon/tangrowth/shiny.gbapal.lz");
    const u8 gMonIcon_Tangrowth[] = INCBIN_U8("graphics/pokemon/tangrowth/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Tangrowth[] = INCBIN_U8("graphics/pokemon/tangrowth/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Tangrowth[] = INCBIN_COMP("graphics/pokemon/tangrowth/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Tangrowth[] = INCBIN_U32("graphics/pokemon/tangrowth/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Tangrowth[] = INCBIN_U32("graphics/pokemon/tangrowth/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_TangrowthF[] = INCBIN_U32("graphics/pokemon/tangrowth/anim_frontf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_TangrowthF[] = INCBIN_COMP("graphics/pokemon/tangrowth/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_TANGELA

#if P_FAMILY_KANGASKHAN
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Kangaskhan[] = INCBIN_U32("graphics/pokemon/kangaskhan/anim_front.4bpp.lz");
    const u32 gMonPalette_Kangaskhan[] = INCBIN_U32("graphics/pokemon/kangaskhan/normal.gbapal.lz");
    const u32 gMonBackPic_Kangaskhan[] = INCBIN_U32("graphics/pokemon/kangaskhan/back.4bpp.lz");
    const u32 gMonShinyPalette_Kangaskhan[] = INCBIN_U32("graphics/pokemon/kangaskhan/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Kangaskhan[] = INCBIN_U32("graphics/pokemon/kangaskhan/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Kangaskhan[] = INCBIN_U32("graphics/pokemon/kangaskhan/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Kangaskhan[] = INCBIN_U32("graphics/pokemon/kangaskhan/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Kangaskhan[] = INCBIN_U32("graphics/pokemon/kangaskhan/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Kangaskhan[] = INCBIN_U8("graphics/pokemon/kangaskhan/icon.4bpp");
#else
    const u8 gMonIcon_Kangaskhan[] = INCBIN_U8("graphics/pokemon/kangaskhan/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Kangaskhan[] = INCBIN_U8("graphics/pokemon/kangaskhan/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Kangaskhan[] = INCBIN_COMP("graphics/pokemon/kangaskhan/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Kangaskhan[] = INCBIN_U32("graphics/pokemon/kangaskhan/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Kangaskhan[] = INCBIN_U32("graphics/pokemon/kangaskhan/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_KANGASKHAN

#if P_FAMILY_HORSEA
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Horsea[] = INCBIN_U32("graphics/pokemon/horsea/anim_front.4bpp.lz");
    const u32 gMonPalette_Horsea[] = INCBIN_U32("graphics/pokemon/horsea/normal.gbapal.lz");
    const u32 gMonBackPic_Horsea[] = INCBIN_U32("graphics/pokemon/horsea/back.4bpp.lz");
    const u32 gMonShinyPalette_Horsea[] = INCBIN_U32("graphics/pokemon/horsea/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Horsea[] = INCBIN_U32("graphics/pokemon/horsea/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Horsea[] = INCBIN_U32("graphics/pokemon/horsea/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Horsea[] = INCBIN_U32("graphics/pokemon/horsea/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Horsea[] = INCBIN_U32("graphics/pokemon/horsea/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Horsea[] = INCBIN_U8("graphics/pokemon/horsea/icon.4bpp");
#else
    const u8 gMonIcon_Horsea[] = INCBIN_U8("graphics/pokemon/horsea/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Horsea[] = INCBIN_U8("graphics/pokemon/horsea/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Horsea[] = INCBIN_COMP("graphics/pokemon/horsea/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Horsea[] = INCBIN_U32("graphics/pokemon/horsea/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Horsea[] = INCBIN_U32("graphics/pokemon/horsea/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Seadra[] = INCBIN_U32("graphics/pokemon/seadra/anim_front.4bpp.lz");
    const u32 gMonPalette_Seadra[] = INCBIN_U32("graphics/pokemon/seadra/normal.gbapal.lz");
    const u32 gMonBackPic_Seadra[] = INCBIN_U32("graphics/pokemon/seadra/back.4bpp.lz");
    const u32 gMonShinyPalette_Seadra[] = INCBIN_U32("graphics/pokemon/seadra/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Seadra[] = INCBIN_U32("graphics/pokemon/seadra/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Seadra[] = INCBIN_U32("graphics/pokemon/seadra/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Seadra[] = INCBIN_U32("graphics/pokemon/seadra/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Seadra[] = INCBIN_U32("graphics/pokemon/seadra/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Seadra[] = INCBIN_U8("graphics/pokemon/seadra/icon.4bpp");
#else
    const u8 gMonIcon_Seadra[] = INCBIN_U8("graphics/pokemon/seadra/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Seadra[] = INCBIN_U8("graphics/pokemon/seadra/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Seadra[] = INCBIN_COMP("graphics/pokemon/seadra/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Seadra[] = INCBIN_U32("graphics/pokemon/seadra/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Seadra[] = INCBIN_U32("graphics/pokemon/seadra/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GEN_2_CROSS_EVOS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Kingdra[] = INCBIN_U32("graphics/pokemon/kingdra/anim_front.4bpp.lz");
    const u32 gMonPalette_Kingdra[] = INCBIN_U32("graphics/pokemon/kingdra/normal.gbapal.lz");
    const u32 gMonBackPic_Kingdra[] = INCBIN_U32("graphics/pokemon/kingdra/back.4bpp.lz");
    const u32 gMonShinyPalette_Kingdra[] = INCBIN_U32("graphics/pokemon/kingdra/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Kingdra[] = INCBIN_U32("graphics/pokemon/kingdra/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Kingdra[] = INCBIN_U32("graphics/pokemon/kingdra/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Kingdra[] = INCBIN_U32("graphics/pokemon/kingdra/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Kingdra[] = INCBIN_U32("graphics/pokemon/kingdra/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Kingdra[] = INCBIN_U8("graphics/pokemon/kingdra/icon.4bpp");
#else
    const u8 gMonIcon_Kingdra[] = INCBIN_U8("graphics/pokemon/kingdra/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Kingdra[] = INCBIN_U8("graphics/pokemon/kingdra/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Kingdra[] = INCBIN_COMP("graphics/pokemon/kingdra/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Kingdra[] = INCBIN_U32("graphics/pokemon/kingdra/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Kingdra[] = INCBIN_U32("graphics/pokemon/kingdra/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_2_CROSS_EVOS
#endif //P_FAMILY_HORSEA

#if P_FAMILY_GOLDEEN
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Goldeen[] = INCBIN_U32("graphics/pokemon/goldeen/anim_front.4bpp.lz");
    const u32 gMonPalette_Goldeen[] = INCBIN_U32("graphics/pokemon/goldeen/normal.gbapal.lz");
    const u32 gMonBackPic_Goldeen[] = INCBIN_U32("graphics/pokemon/goldeen/back.4bpp.lz");
    const u32 gMonShinyPalette_Goldeen[] = INCBIN_U32("graphics/pokemon/goldeen/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Goldeen[] = INCBIN_U32("graphics/pokemon/goldeen/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Goldeen[] = INCBIN_U32("graphics/pokemon/goldeen/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Goldeen[] = INCBIN_U32("graphics/pokemon/goldeen/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Goldeen[] = INCBIN_U32("graphics/pokemon/goldeen/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Goldeen[] = INCBIN_U8("graphics/pokemon/goldeen/icon.4bpp");
#else
    const u8 gMonIcon_Goldeen[] = INCBIN_U8("graphics/pokemon/goldeen/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Goldeen[] = INCBIN_U8("graphics/pokemon/goldeen/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Goldeen[] = INCBIN_COMP("graphics/pokemon/goldeen/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Goldeen[] = INCBIN_U32("graphics/pokemon/goldeen/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Goldeen[] = INCBIN_U32("graphics/pokemon/goldeen/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_GoldeenF[] = INCBIN_U32("graphics/pokemon/goldeen/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_GoldeenF[] = INCBIN_U32("graphics/pokemon/goldeen/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_GoldeenF[] = INCBIN_COMP("graphics/pokemon/goldeen/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Seaking[] = INCBIN_U32("graphics/pokemon/seaking/anim_front.4bpp.lz");
    const u32 gMonPalette_Seaking[] = INCBIN_U32("graphics/pokemon/seaking/normal.gbapal.lz");
    const u32 gMonBackPic_Seaking[] = INCBIN_U32("graphics/pokemon/seaking/back.4bpp.lz");
    const u32 gMonShinyPalette_Seaking[] = INCBIN_U32("graphics/pokemon/seaking/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Seaking[] = INCBIN_U32("graphics/pokemon/seaking/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Seaking[] = INCBIN_U32("graphics/pokemon/seaking/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Seaking[] = INCBIN_U32("graphics/pokemon/seaking/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Seaking[] = INCBIN_U32("graphics/pokemon/seaking/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Seaking[] = INCBIN_U8("graphics/pokemon/seaking/icon.4bpp");
#else
    const u8 gMonIcon_Seaking[] = INCBIN_U8("graphics/pokemon/seaking/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Seaking[] = INCBIN_U8("graphics/pokemon/seaking/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Seaking[] = INCBIN_COMP("graphics/pokemon/seaking/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Seaking[] = INCBIN_U32("graphics/pokemon/seaking/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Seaking[] = INCBIN_U32("graphics/pokemon/seaking/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_SeakingF[] = INCBIN_U32("graphics/pokemon/seaking/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_SeakingF[] = INCBIN_U32("graphics/pokemon/seaking/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_SeakingF[] = INCBIN_COMP("graphics/pokemon/seaking/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_GOLDEEN

#if P_FAMILY_STARYU
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Staryu[] = INCBIN_U32("graphics/pokemon/staryu/anim_front.4bpp.lz");
    const u32 gMonPalette_Staryu[] = INCBIN_U32("graphics/pokemon/staryu/normal.gbapal.lz");
    const u32 gMonBackPic_Staryu[] = INCBIN_U32("graphics/pokemon/staryu/back.4bpp.lz");
    const u32 gMonShinyPalette_Staryu[] = INCBIN_U32("graphics/pokemon/staryu/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Staryu[] = INCBIN_U32("graphics/pokemon/staryu/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Staryu[] = INCBIN_U32("graphics/pokemon/staryu/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Staryu[] = INCBIN_U32("graphics/pokemon/staryu/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Staryu[] = INCBIN_U32("graphics/pokemon/staryu/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Staryu[] = INCBIN_U8("graphics/pokemon/staryu/icon.4bpp");
#else
    const u8 gMonIcon_Staryu[] = INCBIN_U8("graphics/pokemon/staryu/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Staryu[] = INCBIN_U8("graphics/pokemon/staryu/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Staryu[] = INCBIN_COMP("graphics/pokemon/staryu/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Staryu[] = INCBIN_U32("graphics/pokemon/staryu/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Staryu[] = INCBIN_U32("graphics/pokemon/staryu/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Starmie[] = INCBIN_U32("graphics/pokemon/starmie/anim_front.4bpp.lz");
    const u32 gMonPalette_Starmie[] = INCBIN_U32("graphics/pokemon/starmie/normal.gbapal.lz");
    const u32 gMonBackPic_Starmie[] = INCBIN_U32("graphics/pokemon/starmie/back.4bpp.lz");
    const u32 gMonShinyPalette_Starmie[] = INCBIN_U32("graphics/pokemon/starmie/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Starmie[] = INCBIN_U32("graphics/pokemon/starmie/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Starmie[] = INCBIN_U32("graphics/pokemon/starmie/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Starmie[] = INCBIN_U32("graphics/pokemon/starmie/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Starmie[] = INCBIN_U32("graphics/pokemon/starmie/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Starmie[] = INCBIN_U8("graphics/pokemon/starmie/icon.4bpp");
#else
    const u8 gMonIcon_Starmie[] = INCBIN_U8("graphics/pokemon/starmie/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Starmie[] = INCBIN_U8("graphics/pokemon/starmie/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Starmie[] = INCBIN_COMP("graphics/pokemon/starmie/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Starmie[] = INCBIN_U32("graphics/pokemon/starmie/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Starmie[] = INCBIN_U32("graphics/pokemon/starmie/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_STARYU

#if P_FAMILY_MR_MIME
#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_MimeJr[] = INCBIN_U32("graphics/pokemon/mime_jr/anim_front.4bpp.lz");
    const u32 gMonPalette_MimeJr[] = INCBIN_U32("graphics/pokemon/mime_jr/normal.gbapal.lz");
    const u32 gMonBackPic_MimeJr[] = INCBIN_U32("graphics/pokemon/mime_jr/back.4bpp.lz");
    const u32 gMonShinyPalette_MimeJr[] = INCBIN_U32("graphics/pokemon/mime_jr/shiny.gbapal.lz");
    const u8 gMonIcon_MimeJr[] = INCBIN_U8("graphics/pokemon/mime_jr/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_MimeJr[] = INCBIN_U8("graphics/pokemon/mime_jr/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_MimeJr[] = INCBIN_COMP("graphics/pokemon/mime_jr/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_MimeJr[] = INCBIN_U32("graphics/pokemon/mime_jr/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_MimeJr[] = INCBIN_U32("graphics/pokemon/mime_jr/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_4_CROSS_EVOS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_MrMime[] = INCBIN_U32("graphics/pokemon/mr_mime/anim_front.4bpp.lz");
    const u32 gMonPalette_MrMime[] = INCBIN_U32("graphics/pokemon/mr_mime/normal.gbapal.lz");
    const u32 gMonBackPic_MrMime[] = INCBIN_U32("graphics/pokemon/mr_mime/back.4bpp.lz");
    const u32 gMonShinyPalette_MrMime[] = INCBIN_U32("graphics/pokemon/mr_mime/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_MrMime[] = INCBIN_U32("graphics/pokemon/mr_mime/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_MrMime[] = INCBIN_U32("graphics/pokemon/mr_mime/normal_gba.gbapal.lz");
    const u32 gMonBackPic_MrMime[] = INCBIN_U32("graphics/pokemon/mr_mime/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_MrMime[] = INCBIN_U32("graphics/pokemon/mr_mime/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_MrMime[] = INCBIN_U8("graphics/pokemon/mr_mime/icon.4bpp");
#else
    const u8 gMonIcon_MrMime[] = INCBIN_U8("graphics/pokemon/mr_mime/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_MrMime[] = INCBIN_U8("graphics/pokemon/mr_mime/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_MrMime[] = INCBIN_COMP("graphics/pokemon/mr_mime/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_MrMime[] = INCBIN_U32("graphics/pokemon/mr_mime/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_MrMime[] = INCBIN_U32("graphics/pokemon/mr_mime/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_MR_MIME

#if P_FAMILY_SCYTHER
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Scyther[] = INCBIN_U32("graphics/pokemon/scyther/anim_front.4bpp.lz");
    const u32 gMonPalette_Scyther[] = INCBIN_U32("graphics/pokemon/scyther/normal.gbapal.lz");
    const u32 gMonBackPic_Scyther[] = INCBIN_U32("graphics/pokemon/scyther/back.4bpp.lz");
    const u32 gMonShinyPalette_Scyther[] = INCBIN_U32("graphics/pokemon/scyther/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Scyther[] = INCBIN_U32("graphics/pokemon/scyther/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Scyther[] = INCBIN_U32("graphics/pokemon/scyther/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Scyther[] = INCBIN_U32("graphics/pokemon/scyther/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Scyther[] = INCBIN_U32("graphics/pokemon/scyther/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Scyther[] = INCBIN_U8("graphics/pokemon/scyther/icon.4bpp");
#else
    const u8 gMonIcon_Scyther[] = INCBIN_U8("graphics/pokemon/scyther/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Scyther[] = INCBIN_U8("graphics/pokemon/scyther/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Scyther[] = INCBIN_COMP("graphics/pokemon/scyther/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Scyther[] = INCBIN_U32("graphics/pokemon/scyther/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Scyther[] = INCBIN_U32("graphics/pokemon/scyther/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_ScytherF[] = INCBIN_U32("graphics/pokemon/scyther/anim_frontf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_ScytherF[] = INCBIN_COMP("graphics/pokemon/scyther/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if P_GEN_2_CROSS_EVOS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Scizor[] = INCBIN_U32("graphics/pokemon/scizor/anim_front.4bpp.lz");
    const u32 gMonPalette_Scizor[] = INCBIN_U32("graphics/pokemon/scizor/normal.gbapal.lz");
    const u32 gMonBackPic_Scizor[] = INCBIN_U32("graphics/pokemon/scizor/back.4bpp.lz");
    const u32 gMonShinyPalette_Scizor[] = INCBIN_U32("graphics/pokemon/scizor/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Scizor[] = INCBIN_U32("graphics/pokemon/scizor/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Scizor[] = INCBIN_U32("graphics/pokemon/scizor/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Scizor[] = INCBIN_U32("graphics/pokemon/scizor/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Scizor[] = INCBIN_U32("graphics/pokemon/scizor/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Scizor[] = INCBIN_U8("graphics/pokemon/scizor/icon.4bpp");
#else
    const u8 gMonIcon_Scizor[] = INCBIN_U8("graphics/pokemon/scizor/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Scizor[] = INCBIN_U8("graphics/pokemon/scizor/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Scizor[] = INCBIN_COMP("graphics/pokemon/scizor/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Scizor[] = INCBIN_U32("graphics/pokemon/scizor/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Scizor[] = INCBIN_U32("graphics/pokemon/scizor/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_ScizorF[] = INCBIN_U32("graphics/pokemon/scizor/anim_frontf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_ScizorF[] = INCBIN_COMP("graphics/pokemon/scizor/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_GEN_2_CROSS_EVOS
#endif //P_FAMILY_SCYTHER

#if P_FAMILY_JYNX
#if P_GEN_2_CROSS_EVOS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Smoochum[] = INCBIN_U32("graphics/pokemon/smoochum/anim_front.4bpp.lz");
    const u32 gMonPalette_Smoochum[] = INCBIN_U32("graphics/pokemon/smoochum/normal.gbapal.lz");
    const u32 gMonBackPic_Smoochum[] = INCBIN_U32("graphics/pokemon/smoochum/back.4bpp.lz");
    const u32 gMonShinyPalette_Smoochum[] = INCBIN_U32("graphics/pokemon/smoochum/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Smoochum[] = INCBIN_U32("graphics/pokemon/smoochum/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Smoochum[] = INCBIN_U32("graphics/pokemon/smoochum/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Smoochum[] = INCBIN_U32("graphics/pokemon/smoochum/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Smoochum[] = INCBIN_U32("graphics/pokemon/smoochum/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Smoochum[] = INCBIN_U8("graphics/pokemon/smoochum/icon.4bpp");
#else
    const u8 gMonIcon_Smoochum[] = INCBIN_U8("graphics/pokemon/smoochum/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Smoochum[] = INCBIN_U8("graphics/pokemon/smoochum/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Smoochum[] = INCBIN_COMP("graphics/pokemon/smoochum/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Smoochum[] = INCBIN_U32("graphics/pokemon/smoochum/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Smoochum[] = INCBIN_U32("graphics/pokemon/smoochum/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_2_CROSS_EVOS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Jynx[] = INCBIN_U32("graphics/pokemon/jynx/anim_front.4bpp.lz");
    const u32 gMonPalette_Jynx[] = INCBIN_U32("graphics/pokemon/jynx/normal.gbapal.lz");
    const u32 gMonBackPic_Jynx[] = INCBIN_U32("graphics/pokemon/jynx/back.4bpp.lz");
    const u32 gMonShinyPalette_Jynx[] = INCBIN_U32("graphics/pokemon/jynx/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Jynx[] = INCBIN_U32("graphics/pokemon/jynx/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Jynx[] = INCBIN_U32("graphics/pokemon/jynx/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Jynx[] = INCBIN_U32("graphics/pokemon/jynx/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Jynx[] = INCBIN_U32("graphics/pokemon/jynx/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Jynx[] = INCBIN_U8("graphics/pokemon/jynx/icon.4bpp");
#else
    const u8 gMonIcon_Jynx[] = INCBIN_U8("graphics/pokemon/jynx/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Jynx[] = INCBIN_U8("graphics/pokemon/jynx/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Jynx[] = INCBIN_COMP("graphics/pokemon/jynx/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Jynx[] = INCBIN_U32("graphics/pokemon/jynx/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Jynx[] = INCBIN_U32("graphics/pokemon/jynx/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_JYNX

#if P_FAMILY_ELECTABUZZ
#if P_GEN_2_CROSS_EVOS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Elekid[] = INCBIN_U32("graphics/pokemon/elekid/anim_front.4bpp.lz");
    const u32 gMonPalette_Elekid[] = INCBIN_U32("graphics/pokemon/elekid/normal.gbapal.lz");
    const u32 gMonBackPic_Elekid[] = INCBIN_U32("graphics/pokemon/elekid/back.4bpp.lz");
    const u32 gMonShinyPalette_Elekid[] = INCBIN_U32("graphics/pokemon/elekid/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Elekid[] = INCBIN_U32("graphics/pokemon/elekid/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Elekid[] = INCBIN_U32("graphics/pokemon/elekid/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Elekid[] = INCBIN_U32("graphics/pokemon/elekid/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Elekid[] = INCBIN_U32("graphics/pokemon/elekid/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Elekid[] = INCBIN_U8("graphics/pokemon/elekid/icon.4bpp");
#else
    const u8 gMonIcon_Elekid[] = INCBIN_U8("graphics/pokemon/elekid/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Elekid[] = INCBIN_U8("graphics/pokemon/elekid/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Elekid[] = INCBIN_COMP("graphics/pokemon/elekid/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Elekid[] = INCBIN_U32("graphics/pokemon/elekid/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Elekid[] = INCBIN_U32("graphics/pokemon/elekid/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_2_CROSS_EVOS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Electabuzz[] = INCBIN_U32("graphics/pokemon/electabuzz/anim_front.4bpp.lz");
    const u32 gMonPalette_Electabuzz[] = INCBIN_U32("graphics/pokemon/electabuzz/normal.gbapal.lz");
    const u32 gMonBackPic_Electabuzz[] = INCBIN_U32("graphics/pokemon/electabuzz/back.4bpp.lz");
    const u32 gMonShinyPalette_Electabuzz[] = INCBIN_U32("graphics/pokemon/electabuzz/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Electabuzz[] = INCBIN_U32("graphics/pokemon/electabuzz/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Electabuzz[] = INCBIN_U32("graphics/pokemon/electabuzz/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Electabuzz[] = INCBIN_U32("graphics/pokemon/electabuzz/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Electabuzz[] = INCBIN_U32("graphics/pokemon/electabuzz/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Electabuzz[] = INCBIN_U8("graphics/pokemon/electabuzz/icon.4bpp");
#else
    const u8 gMonIcon_Electabuzz[] = INCBIN_U8("graphics/pokemon/electabuzz/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Electabuzz[] = INCBIN_U8("graphics/pokemon/electabuzz/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Electabuzz[] = INCBIN_COMP("graphics/pokemon/electabuzz/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Electabuzz[] = INCBIN_U32("graphics/pokemon/electabuzz/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Electabuzz[] = INCBIN_U32("graphics/pokemon/electabuzz/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Electivire[] = INCBIN_U32("graphics/pokemon/electivire/anim_front.4bpp.lz");
    const u32 gMonPalette_Electivire[] = INCBIN_U32("graphics/pokemon/electivire/normal.gbapal.lz");
    const u32 gMonBackPic_Electivire[] = INCBIN_U32("graphics/pokemon/electivire/back.4bpp.lz");
    const u32 gMonShinyPalette_Electivire[] = INCBIN_U32("graphics/pokemon/electivire/shiny.gbapal.lz");
    const u8 gMonIcon_Electivire[] = INCBIN_U8("graphics/pokemon/electivire/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Electivire[] = INCBIN_U8("graphics/pokemon/electivire/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Electivire[] = INCBIN_COMP("graphics/pokemon/electivire/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Electivire[] = INCBIN_U32("graphics/pokemon/electivire/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Electivire[] = INCBIN_U32("graphics/pokemon/electivire/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_ELECTABUZZ

#if P_FAMILY_MAGMAR
#if P_GEN_2_CROSS_EVOS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Magby[] = INCBIN_U32("graphics/pokemon/magby/anim_front.4bpp.lz");
    const u32 gMonPalette_Magby[] = INCBIN_U32("graphics/pokemon/magby/normal.gbapal.lz");
    const u32 gMonBackPic_Magby[] = INCBIN_U32("graphics/pokemon/magby/back.4bpp.lz");
    const u32 gMonShinyPalette_Magby[] = INCBIN_U32("graphics/pokemon/magby/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Magby[] = INCBIN_U32("graphics/pokemon/magby/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Magby[] = INCBIN_U32("graphics/pokemon/magby/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Magby[] = INCBIN_U32("graphics/pokemon/magby/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Magby[] = INCBIN_U32("graphics/pokemon/magby/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Magby[] = INCBIN_U8("graphics/pokemon/magby/icon.4bpp");
#else
    const u8 gMonIcon_Magby[] = INCBIN_U8("graphics/pokemon/magby/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Magby[] = INCBIN_U8("graphics/pokemon/magby/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Magby[] = INCBIN_COMP("graphics/pokemon/magby/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Magby[] = INCBIN_U32("graphics/pokemon/magby/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Magby[] = INCBIN_U32("graphics/pokemon/magby/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_2_CROSS_EVOS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Magmar[] = INCBIN_U32("graphics/pokemon/magmar/anim_front.4bpp.lz");
    const u32 gMonPalette_Magmar[] = INCBIN_U32("graphics/pokemon/magmar/normal.gbapal.lz");
    const u32 gMonBackPic_Magmar[] = INCBIN_U32("graphics/pokemon/magmar/back.4bpp.lz");
    const u32 gMonShinyPalette_Magmar[] = INCBIN_U32("graphics/pokemon/magmar/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Magmar[] = INCBIN_U32("graphics/pokemon/magmar/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Magmar[] = INCBIN_U32("graphics/pokemon/magmar/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Magmar[] = INCBIN_U32("graphics/pokemon/magmar/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Magmar[] = INCBIN_U32("graphics/pokemon/magmar/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Magmar[] = INCBIN_U8("graphics/pokemon/magmar/icon.4bpp");
#else
    const u8 gMonIcon_Magmar[] = INCBIN_U8("graphics/pokemon/magmar/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Magmar[] = INCBIN_U8("graphics/pokemon/magmar/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Magmar[] = INCBIN_COMP("graphics/pokemon/magmar/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Magmar[] = INCBIN_U32("graphics/pokemon/magmar/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Magmar[] = INCBIN_U32("graphics/pokemon/magmar/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Magmortar[] = INCBIN_U32("graphics/pokemon/magmortar/anim_front.4bpp.lz");
    const u32 gMonPalette_Magmortar[] = INCBIN_U32("graphics/pokemon/magmortar/normal.gbapal.lz");
    const u32 gMonBackPic_Magmortar[] = INCBIN_U32("graphics/pokemon/magmortar/back.4bpp.lz");
    const u32 gMonShinyPalette_Magmortar[] = INCBIN_U32("graphics/pokemon/magmortar/shiny.gbapal.lz");
    const u8 gMonIcon_Magmortar[] = INCBIN_U8("graphics/pokemon/magmortar/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Magmortar[] = INCBIN_U8("graphics/pokemon/magmortar/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Magmortar[] = INCBIN_COMP("graphics/pokemon/magmortar/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Magmortar[] = INCBIN_U32("graphics/pokemon/magmortar/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Magmortar[] = INCBIN_U32("graphics/pokemon/magmortar/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_MAGMAR

#if P_FAMILY_PINSIR
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Pinsir[] = INCBIN_U32("graphics/pokemon/pinsir/anim_front.4bpp.lz");
    const u32 gMonPalette_Pinsir[] = INCBIN_U32("graphics/pokemon/pinsir/normal.gbapal.lz");
    const u32 gMonBackPic_Pinsir[] = INCBIN_U32("graphics/pokemon/pinsir/back.4bpp.lz");
    const u32 gMonShinyPalette_Pinsir[] = INCBIN_U32("graphics/pokemon/pinsir/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Pinsir[] = INCBIN_U32("graphics/pokemon/pinsir/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Pinsir[] = INCBIN_U32("graphics/pokemon/pinsir/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Pinsir[] = INCBIN_U32("graphics/pokemon/pinsir/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Pinsir[] = INCBIN_U32("graphics/pokemon/pinsir/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Pinsir[] = INCBIN_U8("graphics/pokemon/pinsir/icon.4bpp");
#else
    const u8 gMonIcon_Pinsir[] = INCBIN_U8("graphics/pokemon/pinsir/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Pinsir[] = INCBIN_U8("graphics/pokemon/pinsir/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Pinsir[] = INCBIN_COMP("graphics/pokemon/pinsir/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Pinsir[] = INCBIN_U32("graphics/pokemon/pinsir/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Pinsir[] = INCBIN_U32("graphics/pokemon/pinsir/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_PINSIR

#if P_FAMILY_TAUROS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Tauros[] = INCBIN_U32("graphics/pokemon/tauros/anim_front.4bpp.lz");
    const u32 gMonPalette_Tauros[] = INCBIN_U32("graphics/pokemon/tauros/normal.gbapal.lz");
    const u32 gMonBackPic_Tauros[] = INCBIN_U32("graphics/pokemon/tauros/back.4bpp.lz");
    const u32 gMonShinyPalette_Tauros[] = INCBIN_U32("graphics/pokemon/tauros/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Tauros[] = INCBIN_U32("graphics/pokemon/tauros/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Tauros[] = INCBIN_U32("graphics/pokemon/tauros/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Tauros[] = INCBIN_U32("graphics/pokemon/tauros/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Tauros[] = INCBIN_U32("graphics/pokemon/tauros/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Tauros[] = INCBIN_U8("graphics/pokemon/tauros/icon.4bpp");
#else
    const u8 gMonIcon_Tauros[] = INCBIN_U8("graphics/pokemon/tauros/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Tauros[] = INCBIN_U8("graphics/pokemon/tauros/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Tauros[] = INCBIN_COMP("graphics/pokemon/tauros/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Tauros[] = INCBIN_U32("graphics/pokemon/tauros/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Tauros[] = INCBIN_U32("graphics/pokemon/tauros/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_TAUROS

#if P_FAMILY_MAGIKARP
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Magikarp[] = INCBIN_U32("graphics/pokemon/magikarp/anim_front.4bpp.lz");
    const u32 gMonPalette_Magikarp[] = INCBIN_U32("graphics/pokemon/magikarp/normal.gbapal.lz");
    const u32 gMonBackPic_Magikarp[] = INCBIN_U32("graphics/pokemon/magikarp/back.4bpp.lz");
    const u32 gMonShinyPalette_Magikarp[] = INCBIN_U32("graphics/pokemon/magikarp/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Magikarp[] = INCBIN_U32("graphics/pokemon/magikarp/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Magikarp[] = INCBIN_U32("graphics/pokemon/magikarp/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Magikarp[] = INCBIN_U32("graphics/pokemon/magikarp/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Magikarp[] = INCBIN_U32("graphics/pokemon/magikarp/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Magikarp[] = INCBIN_U8("graphics/pokemon/magikarp/icon.4bpp");
#else
    const u8 gMonIcon_Magikarp[] = INCBIN_U8("graphics/pokemon/magikarp/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Magikarp[] = INCBIN_U8("graphics/pokemon/magikarp/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Magikarp[] = INCBIN_COMP("graphics/pokemon/magikarp/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Magikarp[] = INCBIN_U32("graphics/pokemon/magikarp/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Magikarp[] = INCBIN_U32("graphics/pokemon/magikarp/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_MagikarpF[] = INCBIN_U32("graphics/pokemon/magikarp/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_MagikarpF[] = INCBIN_U32("graphics/pokemon/magikarp/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_MagikarpF[] = INCBIN_COMP("graphics/pokemon/magikarp/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Gyarados[] = INCBIN_U32("graphics/pokemon/gyarados/anim_front.4bpp.lz");
    const u32 gMonPalette_Gyarados[] = INCBIN_U32("graphics/pokemon/gyarados/normal.gbapal.lz");
    const u32 gMonBackPic_Gyarados[] = INCBIN_U32("graphics/pokemon/gyarados/back.4bpp.lz");
    const u32 gMonShinyPalette_Gyarados[] = INCBIN_U32("graphics/pokemon/gyarados/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Gyarados[] = INCBIN_U32("graphics/pokemon/gyarados/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Gyarados[] = INCBIN_U32("graphics/pokemon/gyarados/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Gyarados[] = INCBIN_U32("graphics/pokemon/gyarados/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Gyarados[] = INCBIN_U32("graphics/pokemon/gyarados/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Gyarados[] = INCBIN_U8("graphics/pokemon/gyarados/icon.4bpp");
#else
    const u8 gMonIcon_Gyarados[] = INCBIN_U8("graphics/pokemon/gyarados/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Gyarados[] = INCBIN_U8("graphics/pokemon/gyarados/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Gyarados[] = INCBIN_COMP("graphics/pokemon/gyarados/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Gyarados[] = INCBIN_U32("graphics/pokemon/gyarados/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Gyarados[] = INCBIN_U32("graphics/pokemon/gyarados/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_GyaradosF[] = INCBIN_U32("graphics/pokemon/gyarados/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_GyaradosF[] = INCBIN_U32("graphics/pokemon/gyarados/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_GyaradosF[] = INCBIN_COMP("graphics/pokemon/gyarados/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_MAGIKARP

#if P_FAMILY_LAPRAS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Lapras[] = INCBIN_U32("graphics/pokemon/lapras/anim_front.4bpp.lz");
    const u32 gMonPalette_Lapras[] = INCBIN_U32("graphics/pokemon/lapras/normal.gbapal.lz");
    const u32 gMonBackPic_Lapras[] = INCBIN_U32("graphics/pokemon/lapras/back.4bpp.lz");
    const u32 gMonShinyPalette_Lapras[] = INCBIN_U32("graphics/pokemon/lapras/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Lapras[] = INCBIN_U32("graphics/pokemon/lapras/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Lapras[] = INCBIN_U32("graphics/pokemon/lapras/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Lapras[] = INCBIN_U32("graphics/pokemon/lapras/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Lapras[] = INCBIN_U32("graphics/pokemon/lapras/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Lapras[] = INCBIN_U8("graphics/pokemon/lapras/icon.4bpp");
#else
    const u8 gMonIcon_Lapras[] = INCBIN_U8("graphics/pokemon/lapras/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Lapras[] = INCBIN_U8("graphics/pokemon/lapras/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Lapras[] = INCBIN_COMP("graphics/pokemon/lapras/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Lapras[] = INCBIN_U32("graphics/pokemon/lapras/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Lapras[] = INCBIN_U32("graphics/pokemon/lapras/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_LAPRAS

#if P_FAMILY_DITTO
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Ditto[] = INCBIN_U32("graphics/pokemon/ditto/anim_front.4bpp.lz");
    const u32 gMonPalette_Ditto[] = INCBIN_U32("graphics/pokemon/ditto/normal.gbapal.lz");
    const u32 gMonBackPic_Ditto[] = INCBIN_U32("graphics/pokemon/ditto/back.4bpp.lz");
    const u32 gMonShinyPalette_Ditto[] = INCBIN_U32("graphics/pokemon/ditto/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Ditto[] = INCBIN_U32("graphics/pokemon/ditto/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Ditto[] = INCBIN_U32("graphics/pokemon/ditto/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Ditto[] = INCBIN_U32("graphics/pokemon/ditto/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Ditto[] = INCBIN_U32("graphics/pokemon/ditto/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Ditto[] = INCBIN_U8("graphics/pokemon/ditto/icon.4bpp");
#else
    const u8 gMonIcon_Ditto[] = INCBIN_U8("graphics/pokemon/ditto/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Ditto[] = INCBIN_U8("graphics/pokemon/ditto/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Ditto[] = INCBIN_COMP("graphics/pokemon/ditto/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Ditto[] = INCBIN_U32("graphics/pokemon/ditto/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Ditto[] = INCBIN_U32("graphics/pokemon/ditto/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_DITTO

#if P_FAMILY_EEVEE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Eevee[] = INCBIN_U32("graphics/pokemon/eevee/anim_front.4bpp.lz");
    const u32 gMonPalette_Eevee[] = INCBIN_U32("graphics/pokemon/eevee/normal.gbapal.lz");
    const u32 gMonBackPic_Eevee[] = INCBIN_U32("graphics/pokemon/eevee/back.4bpp.lz");
    const u32 gMonShinyPalette_Eevee[] = INCBIN_U32("graphics/pokemon/eevee/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Eevee[] = INCBIN_U32("graphics/pokemon/eevee/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Eevee[] = INCBIN_U32("graphics/pokemon/eevee/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Eevee[] = INCBIN_U32("graphics/pokemon/eevee/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Eevee[] = INCBIN_U32("graphics/pokemon/eevee/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Eevee[] = INCBIN_U8("graphics/pokemon/eevee/icon.4bpp");
#else
    const u8 gMonIcon_Eevee[] = INCBIN_U8("graphics/pokemon/eevee/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Eevee[] = INCBIN_U8("graphics/pokemon/eevee/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Eevee[] = INCBIN_COMP("graphics/pokemon/eevee/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Eevee[] = INCBIN_U32("graphics/pokemon/eevee/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Eevee[] = INCBIN_U32("graphics/pokemon/eevee/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_EeveeF[] = INCBIN_U32("graphics/pokemon/eevee/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_EeveeF[] = INCBIN_U32("graphics/pokemon/eevee/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_EeveeF[] = INCBIN_COMP("graphics/pokemon/eevee/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
    const u8 gMonIcon_EeveePartner[] = INCBIN_U8("graphics/pokemon/eevee/partner/icon.4bpp");
#if P_GENDER_DIFFERENCES && P_CUSTOM_GENDER_DIFF_ICONS
    const u8 gMonIcon_EeveePartnerF[] = INCBIN_U8("graphics/pokemon/eevee/partner/iconf.4bpp");
#endif //P_GENDER_DIFFERENCES && P_CUSTOM_GENDER_DIFF_ICONS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Vaporeon[] = INCBIN_U32("graphics/pokemon/vaporeon/anim_front.4bpp.lz");
    const u32 gMonPalette_Vaporeon[] = INCBIN_U32("graphics/pokemon/vaporeon/normal.gbapal.lz");
    const u32 gMonBackPic_Vaporeon[] = INCBIN_U32("graphics/pokemon/vaporeon/back.4bpp.lz");
    const u32 gMonShinyPalette_Vaporeon[] = INCBIN_U32("graphics/pokemon/vaporeon/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Vaporeon[] = INCBIN_U32("graphics/pokemon/vaporeon/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Vaporeon[] = INCBIN_U32("graphics/pokemon/vaporeon/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Vaporeon[] = INCBIN_U32("graphics/pokemon/vaporeon/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Vaporeon[] = INCBIN_U32("graphics/pokemon/vaporeon/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Vaporeon[] = INCBIN_U8("graphics/pokemon/vaporeon/icon.4bpp");
#else
    const u8 gMonIcon_Vaporeon[] = INCBIN_U8("graphics/pokemon/vaporeon/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Vaporeon[] = INCBIN_U8("graphics/pokemon/vaporeon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Vaporeon[] = INCBIN_COMP("graphics/pokemon/vaporeon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Vaporeon[] = INCBIN_U32("graphics/pokemon/vaporeon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Vaporeon[] = INCBIN_U32("graphics/pokemon/vaporeon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Jolteon[] = INCBIN_U32("graphics/pokemon/jolteon/anim_front.4bpp.lz");
    const u32 gMonPalette_Jolteon[] = INCBIN_U32("graphics/pokemon/jolteon/normal.gbapal.lz");
    const u32 gMonBackPic_Jolteon[] = INCBIN_U32("graphics/pokemon/jolteon/back.4bpp.lz");
    const u32 gMonShinyPalette_Jolteon[] = INCBIN_U32("graphics/pokemon/jolteon/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Jolteon[] = INCBIN_U32("graphics/pokemon/jolteon/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Jolteon[] = INCBIN_U32("graphics/pokemon/jolteon/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Jolteon[] = INCBIN_U32("graphics/pokemon/jolteon/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Jolteon[] = INCBIN_U32("graphics/pokemon/jolteon/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Jolteon[] = INCBIN_U8("graphics/pokemon/jolteon/icon.4bpp");
#else
    const u8 gMonIcon_Jolteon[] = INCBIN_U8("graphics/pokemon/jolteon/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Jolteon[] = INCBIN_U8("graphics/pokemon/jolteon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Jolteon[] = INCBIN_COMP("graphics/pokemon/jolteon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Jolteon[] = INCBIN_U32("graphics/pokemon/jolteon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Jolteon[] = INCBIN_U32("graphics/pokemon/jolteon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Flareon[] = INCBIN_U32("graphics/pokemon/flareon/anim_front.4bpp.lz");
    const u32 gMonPalette_Flareon[] = INCBIN_U32("graphics/pokemon/flareon/normal.gbapal.lz");
    const u32 gMonBackPic_Flareon[] = INCBIN_U32("graphics/pokemon/flareon/back.4bpp.lz");
    const u32 gMonShinyPalette_Flareon[] = INCBIN_U32("graphics/pokemon/flareon/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Flareon[] = INCBIN_U32("graphics/pokemon/flareon/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Flareon[] = INCBIN_U32("graphics/pokemon/flareon/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Flareon[] = INCBIN_U32("graphics/pokemon/flareon/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Flareon[] = INCBIN_U32("graphics/pokemon/flareon/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Flareon[] = INCBIN_U8("graphics/pokemon/flareon/icon.4bpp");
#else
    const u8 gMonIcon_Flareon[] = INCBIN_U8("graphics/pokemon/flareon/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Flareon[] = INCBIN_U8("graphics/pokemon/flareon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Flareon[] = INCBIN_COMP("graphics/pokemon/flareon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Flareon[] = INCBIN_U32("graphics/pokemon/flareon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Flareon[] = INCBIN_U32("graphics/pokemon/flareon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GEN_2_CROSS_EVOS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Espeon[] = INCBIN_U32("graphics/pokemon/espeon/anim_front.4bpp.lz");
    const u32 gMonPalette_Espeon[] = INCBIN_U32("graphics/pokemon/espeon/normal.gbapal.lz");
    const u32 gMonBackPic_Espeon[] = INCBIN_U32("graphics/pokemon/espeon/back.4bpp.lz");
    const u32 gMonShinyPalette_Espeon[] = INCBIN_U32("graphics/pokemon/espeon/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Espeon[] = INCBIN_U32("graphics/pokemon/espeon/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Espeon[] = INCBIN_U32("graphics/pokemon/espeon/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Espeon[] = INCBIN_U32("graphics/pokemon/espeon/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Espeon[] = INCBIN_U32("graphics/pokemon/espeon/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Espeon[] = INCBIN_U8("graphics/pokemon/espeon/icon.4bpp");
#else
    const u8 gMonIcon_Espeon[] = INCBIN_U8("graphics/pokemon/espeon/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Espeon[] = INCBIN_U8("graphics/pokemon/espeon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Espeon[] = INCBIN_COMP("graphics/pokemon/espeon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Espeon[] = INCBIN_U32("graphics/pokemon/espeon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Espeon[] = INCBIN_U32("graphics/pokemon/espeon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Umbreon[] = INCBIN_U32("graphics/pokemon/umbreon/anim_front.4bpp.lz");
    const u32 gMonPalette_Umbreon[] = INCBIN_U32("graphics/pokemon/umbreon/normal.gbapal.lz");
    const u32 gMonBackPic_Umbreon[] = INCBIN_U32("graphics/pokemon/umbreon/back.4bpp.lz");
    const u32 gMonShinyPalette_Umbreon[] = INCBIN_U32("graphics/pokemon/umbreon/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Umbreon[] = INCBIN_U32("graphics/pokemon/umbreon/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Umbreon[] = INCBIN_U32("graphics/pokemon/umbreon/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Umbreon[] = INCBIN_U32("graphics/pokemon/umbreon/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Umbreon[] = INCBIN_U32("graphics/pokemon/umbreon/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Umbreon[] = INCBIN_U8("graphics/pokemon/umbreon/icon.4bpp");
#else
    const u8 gMonIcon_Umbreon[] = INCBIN_U8("graphics/pokemon/umbreon/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Umbreon[] = INCBIN_U8("graphics/pokemon/umbreon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Umbreon[] = INCBIN_COMP("graphics/pokemon/umbreon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Umbreon[] = INCBIN_U32("graphics/pokemon/umbreon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Umbreon[] = INCBIN_U32("graphics/pokemon/umbreon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_2_CROSS_EVOS

#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Leafeon[] = INCBIN_U32("graphics/pokemon/leafeon/anim_front.4bpp.lz");
    const u32 gMonPalette_Leafeon[] = INCBIN_U32("graphics/pokemon/leafeon/normal.gbapal.lz");
    const u32 gMonBackPic_Leafeon[] = INCBIN_U32("graphics/pokemon/leafeon/back.4bpp.lz");
    const u32 gMonShinyPalette_Leafeon[] = INCBIN_U32("graphics/pokemon/leafeon/shiny.gbapal.lz");
    const u8 gMonIcon_Leafeon[] = INCBIN_U8("graphics/pokemon/leafeon/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Leafeon[] = INCBIN_U8("graphics/pokemon/leafeon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Leafeon[] = INCBIN_COMP("graphics/pokemon/leafeon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Leafeon[] = INCBIN_U32("graphics/pokemon/leafeon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Leafeon[] = INCBIN_U32("graphics/pokemon/leafeon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_Glaceon[] = INCBIN_U32("graphics/pokemon/glaceon/anim_front.4bpp.lz");
    const u32 gMonPalette_Glaceon[] = INCBIN_U32("graphics/pokemon/glaceon/normal.gbapal.lz");
    const u32 gMonBackPic_Glaceon[] = INCBIN_U32("graphics/pokemon/glaceon/back.4bpp.lz");
    const u32 gMonShinyPalette_Glaceon[] = INCBIN_U32("graphics/pokemon/glaceon/shiny.gbapal.lz");
    const u8 gMonIcon_Glaceon[] = INCBIN_U8("graphics/pokemon/glaceon/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Glaceon[] = INCBIN_U8("graphics/pokemon/glaceon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Glaceon[] = INCBIN_COMP("graphics/pokemon/glaceon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Glaceon[] = INCBIN_U32("graphics/pokemon/glaceon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Glaceon[] = INCBIN_U32("graphics/pokemon/glaceon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_EEVEE

#if P_FAMILY_PORYGON
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Porygon[] = INCBIN_U32("graphics/pokemon/porygon/anim_front.4bpp.lz");
    const u32 gMonPalette_Porygon[] = INCBIN_U32("graphics/pokemon/porygon/normal.gbapal.lz");
    const u32 gMonBackPic_Porygon[] = INCBIN_U32("graphics/pokemon/porygon/back.4bpp.lz");
    const u32 gMonShinyPalette_Porygon[] = INCBIN_U32("graphics/pokemon/porygon/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Porygon[] = INCBIN_U32("graphics/pokemon/porygon/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Porygon[] = INCBIN_U32("graphics/pokemon/porygon/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Porygon[] = INCBIN_U32("graphics/pokemon/porygon/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Porygon[] = INCBIN_U32("graphics/pokemon/porygon/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Porygon[] = INCBIN_U8("graphics/pokemon/porygon/icon.4bpp");
#else
    const u8 gMonIcon_Porygon[] = INCBIN_U8("graphics/pokemon/porygon/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Porygon[] = INCBIN_U8("graphics/pokemon/porygon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Porygon[] = INCBIN_COMP("graphics/pokemon/porygon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Porygon[] = INCBIN_U32("graphics/pokemon/porygon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Porygon[] = INCBIN_U32("graphics/pokemon/porygon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GEN_2_CROSS_EVOS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Porygon2[] = INCBIN_U32("graphics/pokemon/porygon2/anim_front.4bpp.lz");
    const u32 gMonPalette_Porygon2[] = INCBIN_U32("graphics/pokemon/porygon2/normal.gbapal.lz");
    const u32 gMonBackPic_Porygon2[] = INCBIN_U32("graphics/pokemon/porygon2/back.4bpp.lz");
    const u32 gMonShinyPalette_Porygon2[] = INCBIN_U32("graphics/pokemon/porygon2/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Porygon2[] = INCBIN_U32("graphics/pokemon/porygon2/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Porygon2[] = INCBIN_U32("graphics/pokemon/porygon2/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Porygon2[] = INCBIN_U32("graphics/pokemon/porygon2/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Porygon2[] = INCBIN_U32("graphics/pokemon/porygon2/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Porygon2[] = INCBIN_U8("graphics/pokemon/porygon2/icon.4bpp");
#else
    const u8 gMonIcon_Porygon2[] = INCBIN_U8("graphics/pokemon/porygon2/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Porygon2[] = INCBIN_U8("graphics/pokemon/porygon2/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Porygon2[] = INCBIN_COMP("graphics/pokemon/porygon2/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Porygon2[] = INCBIN_U32("graphics/pokemon/porygon2/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Porygon2[] = INCBIN_U32("graphics/pokemon/porygon2/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_PorygonZ[] = INCBIN_U32("graphics/pokemon/porygon_z/anim_front.4bpp.lz");
    const u32 gMonPalette_PorygonZ[] = INCBIN_U32("graphics/pokemon/porygon_z/normal.gbapal.lz");
    const u32 gMonBackPic_PorygonZ[] = INCBIN_U32("graphics/pokemon/porygon_z/back.4bpp.lz");
    const u32 gMonShinyPalette_PorygonZ[] = INCBIN_U32("graphics/pokemon/porygon_z/shiny.gbapal.lz");
    const u8 gMonIcon_PorygonZ[] = INCBIN_U8("graphics/pokemon/porygon_z/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_PorygonZ[] = INCBIN_U8("graphics/pokemon/porygon_z/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_PorygonZ[] = INCBIN_COMP("graphics/pokemon/porygon_z/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_PorygonZ[] = INCBIN_U32("graphics/pokemon/porygon_z/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_PorygonZ[] = INCBIN_U32("graphics/pokemon/porygon_z/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_4_CROSS_EVOS
#endif //P_GEN_2_CROSS_EVOS
#endif //P_FAMILY_PORYGON

#if P_FAMILY_OMANYTE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Omanyte[] = INCBIN_U32("graphics/pokemon/omanyte/anim_front.4bpp.lz");
    const u32 gMonPalette_Omanyte[] = INCBIN_U32("graphics/pokemon/omanyte/normal.gbapal.lz");
    const u32 gMonBackPic_Omanyte[] = INCBIN_U32("graphics/pokemon/omanyte/back.4bpp.lz");
    const u32 gMonShinyPalette_Omanyte[] = INCBIN_U32("graphics/pokemon/omanyte/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Omanyte[] = INCBIN_U32("graphics/pokemon/omanyte/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Omanyte[] = INCBIN_U32("graphics/pokemon/omanyte/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Omanyte[] = INCBIN_U32("graphics/pokemon/omanyte/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Omanyte[] = INCBIN_U32("graphics/pokemon/omanyte/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Omanyte[] = INCBIN_U8("graphics/pokemon/omanyte/icon.4bpp");
#else
    const u8 gMonIcon_Omanyte[] = INCBIN_U8("graphics/pokemon/omanyte/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Omanyte[] = INCBIN_U8("graphics/pokemon/omanyte/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Omanyte[] = INCBIN_COMP("graphics/pokemon/omanyte/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Omanyte[] = INCBIN_U32("graphics/pokemon/omanyte/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Omanyte[] = INCBIN_U32("graphics/pokemon/omanyte/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Omastar[] = INCBIN_U32("graphics/pokemon/omastar/anim_front.4bpp.lz");
    const u32 gMonPalette_Omastar[] = INCBIN_U32("graphics/pokemon/omastar/normal.gbapal.lz");
    const u32 gMonBackPic_Omastar[] = INCBIN_U32("graphics/pokemon/omastar/back.4bpp.lz");
    const u32 gMonShinyPalette_Omastar[] = INCBIN_U32("graphics/pokemon/omastar/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Omastar[] = INCBIN_U32("graphics/pokemon/omastar/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Omastar[] = INCBIN_U32("graphics/pokemon/omastar/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Omastar[] = INCBIN_U32("graphics/pokemon/omastar/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Omastar[] = INCBIN_U32("graphics/pokemon/omastar/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Omastar[] = INCBIN_U8("graphics/pokemon/omastar/icon.4bpp");
#else
    const u8 gMonIcon_Omastar[] = INCBIN_U8("graphics/pokemon/omastar/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Omastar[] = INCBIN_U8("graphics/pokemon/omastar/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Omastar[] = INCBIN_COMP("graphics/pokemon/omastar/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Omastar[] = INCBIN_U32("graphics/pokemon/omastar/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Omastar[] = INCBIN_U32("graphics/pokemon/omastar/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_OMANYTE

#if P_FAMILY_KABUTO
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Kabuto[] = INCBIN_U32("graphics/pokemon/kabuto/anim_front.4bpp.lz");
    const u32 gMonPalette_Kabuto[] = INCBIN_U32("graphics/pokemon/kabuto/normal.gbapal.lz");
    const u32 gMonBackPic_Kabuto[] = INCBIN_U32("graphics/pokemon/kabuto/back.4bpp.lz");
    const u32 gMonShinyPalette_Kabuto[] = INCBIN_U32("graphics/pokemon/kabuto/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Kabuto[] = INCBIN_U32("graphics/pokemon/kabuto/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Kabuto[] = INCBIN_U32("graphics/pokemon/kabuto/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Kabuto[] = INCBIN_U32("graphics/pokemon/kabuto/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Kabuto[] = INCBIN_U32("graphics/pokemon/kabuto/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Kabuto[] = INCBIN_U8("graphics/pokemon/kabuto/icon.4bpp");
#else
    const u8 gMonIcon_Kabuto[] = INCBIN_U8("graphics/pokemon/kabuto/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Kabuto[] = INCBIN_U8("graphics/pokemon/kabuto/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Kabuto[] = INCBIN_COMP("graphics/pokemon/kabuto/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Kabuto[] = INCBIN_U32("graphics/pokemon/kabuto/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Kabuto[] = INCBIN_U32("graphics/pokemon/kabuto/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Kabutops[] = INCBIN_U32("graphics/pokemon/kabutops/anim_front.4bpp.lz");
    const u32 gMonPalette_Kabutops[] = INCBIN_U32("graphics/pokemon/kabutops/normal.gbapal.lz");
    const u32 gMonBackPic_Kabutops[] = INCBIN_U32("graphics/pokemon/kabutops/back.4bpp.lz");
    const u32 gMonShinyPalette_Kabutops[] = INCBIN_U32("graphics/pokemon/kabutops/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Kabutops[] = INCBIN_U32("graphics/pokemon/kabutops/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Kabutops[] = INCBIN_U32("graphics/pokemon/kabutops/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Kabutops[] = INCBIN_U32("graphics/pokemon/kabutops/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Kabutops[] = INCBIN_U32("graphics/pokemon/kabutops/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Kabutops[] = INCBIN_U8("graphics/pokemon/kabutops/icon.4bpp");
#else
    const u8 gMonIcon_Kabutops[] = INCBIN_U8("graphics/pokemon/kabutops/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Kabutops[] = INCBIN_U8("graphics/pokemon/kabutops/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Kabutops[] = INCBIN_COMP("graphics/pokemon/kabutops/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Kabutops[] = INCBIN_U32("graphics/pokemon/kabutops/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Kabutops[] = INCBIN_U32("graphics/pokemon/kabutops/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_KABUTO

#if P_FAMILY_AERODACTYL
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Aerodactyl[] = INCBIN_U32("graphics/pokemon/aerodactyl/anim_front.4bpp.lz");
    const u32 gMonPalette_Aerodactyl[] = INCBIN_U32("graphics/pokemon/aerodactyl/normal.gbapal.lz");
    const u32 gMonBackPic_Aerodactyl[] = INCBIN_U32("graphics/pokemon/aerodactyl/back.4bpp.lz");
    const u32 gMonShinyPalette_Aerodactyl[] = INCBIN_U32("graphics/pokemon/aerodactyl/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Aerodactyl[] = INCBIN_U32("graphics/pokemon/aerodactyl/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Aerodactyl[] = INCBIN_U32("graphics/pokemon/aerodactyl/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Aerodactyl[] = INCBIN_U32("graphics/pokemon/aerodactyl/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Aerodactyl[] = INCBIN_U32("graphics/pokemon/aerodactyl/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Aerodactyl[] = INCBIN_U8("graphics/pokemon/aerodactyl/icon.4bpp");
#else
    const u8 gMonIcon_Aerodactyl[] = INCBIN_U8("graphics/pokemon/aerodactyl/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Aerodactyl[] = INCBIN_U8("graphics/pokemon/aerodactyl/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Aerodactyl[] = INCBIN_COMP("graphics/pokemon/aerodactyl/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Aerodactyl[] = INCBIN_U32("graphics/pokemon/aerodactyl/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Aerodactyl[] = INCBIN_U32("graphics/pokemon/aerodactyl/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_AERODACTYL

#if P_FAMILY_SNORLAX
#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Munchlax[] = INCBIN_U32("graphics/pokemon/munchlax/anim_front.4bpp.lz");
    const u32 gMonPalette_Munchlax[] = INCBIN_U32("graphics/pokemon/munchlax/normal.gbapal.lz");
    const u32 gMonBackPic_Munchlax[] = INCBIN_U32("graphics/pokemon/munchlax/back.4bpp.lz");
    const u32 gMonShinyPalette_Munchlax[] = INCBIN_U32("graphics/pokemon/munchlax/shiny.gbapal.lz");
    const u8 gMonIcon_Munchlax[] = INCBIN_U8("graphics/pokemon/munchlax/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Munchlax[] = INCBIN_U8("graphics/pokemon/munchlax/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Munchlax[] = INCBIN_COMP("graphics/pokemon/munchlax/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Munchlax[] = INCBIN_U32("graphics/pokemon/munchlax/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Munchlax[] = INCBIN_U32("graphics/pokemon/munchlax/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_4_CROSS_EVOS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Snorlax[] = INCBIN_U32("graphics/pokemon/snorlax/anim_front.4bpp.lz");
    const u32 gMonPalette_Snorlax[] = INCBIN_U32("graphics/pokemon/snorlax/normal.gbapal.lz");
    const u32 gMonBackPic_Snorlax[] = INCBIN_U32("graphics/pokemon/snorlax/back.4bpp.lz");
    const u32 gMonShinyPalette_Snorlax[] = INCBIN_U32("graphics/pokemon/snorlax/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Snorlax[] = INCBIN_U32("graphics/pokemon/snorlax/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Snorlax[] = INCBIN_U32("graphics/pokemon/snorlax/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Snorlax[] = INCBIN_U32("graphics/pokemon/snorlax/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Snorlax[] = INCBIN_U32("graphics/pokemon/snorlax/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Snorlax[] = INCBIN_U8("graphics/pokemon/snorlax/icon.4bpp");
#else
    const u8 gMonIcon_Snorlax[] = INCBIN_U8("graphics/pokemon/snorlax/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Snorlax[] = INCBIN_U8("graphics/pokemon/snorlax/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Snorlax[] = INCBIN_COMP("graphics/pokemon/snorlax/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Snorlax[] = INCBIN_U32("graphics/pokemon/snorlax/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Snorlax[] = INCBIN_U32("graphics/pokemon/snorlax/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SNORLAX

#if P_FAMILY_ARTICUNO
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Articuno[] = INCBIN_U32("graphics/pokemon/articuno/anim_front.4bpp.lz");
    const u32 gMonPalette_Articuno[] = INCBIN_U32("graphics/pokemon/articuno/normal.gbapal.lz");
    const u32 gMonBackPic_Articuno[] = INCBIN_U32("graphics/pokemon/articuno/back.4bpp.lz");
    const u32 gMonShinyPalette_Articuno[] = INCBIN_U32("graphics/pokemon/articuno/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Articuno[] = INCBIN_U32("graphics/pokemon/articuno/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Articuno[] = INCBIN_U32("graphics/pokemon/articuno/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Articuno[] = INCBIN_U32("graphics/pokemon/articuno/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Articuno[] = INCBIN_U32("graphics/pokemon/articuno/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Articuno[] = INCBIN_U8("graphics/pokemon/articuno/icon.4bpp");
#else
    const u8 gMonIcon_Articuno[] = INCBIN_U8("graphics/pokemon/articuno/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Articuno[] = INCBIN_U8("graphics/pokemon/articuno/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Articuno[] = INCBIN_COMP("graphics/pokemon/articuno/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Articuno[] = INCBIN_U32("graphics/pokemon/articuno/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Articuno[] = INCBIN_U32("graphics/pokemon/articuno/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_ARTICUNO

#if P_FAMILY_ZAPDOS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Zapdos[] = INCBIN_U32("graphics/pokemon/zapdos/anim_front.4bpp.lz");
    const u32 gMonPalette_Zapdos[] = INCBIN_U32("graphics/pokemon/zapdos/normal.gbapal.lz");
    const u32 gMonBackPic_Zapdos[] = INCBIN_U32("graphics/pokemon/zapdos/back.4bpp.lz");
    const u32 gMonShinyPalette_Zapdos[] = INCBIN_U32("graphics/pokemon/zapdos/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Zapdos[] = INCBIN_U32("graphics/pokemon/zapdos/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Zapdos[] = INCBIN_U32("graphics/pokemon/zapdos/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Zapdos[] = INCBIN_U32("graphics/pokemon/zapdos/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Zapdos[] = INCBIN_U32("graphics/pokemon/zapdos/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Zapdos[] = INCBIN_U8("graphics/pokemon/zapdos/icon.4bpp");
#else
    const u8 gMonIcon_Zapdos[] = INCBIN_U8("graphics/pokemon/zapdos/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Zapdos[] = INCBIN_U8("graphics/pokemon/zapdos/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Zapdos[] = INCBIN_COMP("graphics/pokemon/zapdos/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Zapdos[] = INCBIN_U32("graphics/pokemon/zapdos/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Zapdos[] = INCBIN_U32("graphics/pokemon/zapdos/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_ZAPDOS

#if P_FAMILY_MOLTRES
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Moltres[] = INCBIN_U32("graphics/pokemon/moltres/anim_front.4bpp.lz");
    const u32 gMonPalette_Moltres[] = INCBIN_U32("graphics/pokemon/moltres/normal.gbapal.lz");
    const u32 gMonBackPic_Moltres[] = INCBIN_U32("graphics/pokemon/moltres/back.4bpp.lz");
    const u32 gMonShinyPalette_Moltres[] = INCBIN_U32("graphics/pokemon/moltres/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Moltres[] = INCBIN_U32("graphics/pokemon/moltres/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Moltres[] = INCBIN_U32("graphics/pokemon/moltres/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Moltres[] = INCBIN_U32("graphics/pokemon/moltres/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Moltres[] = INCBIN_U32("graphics/pokemon/moltres/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Moltres[] = INCBIN_U8("graphics/pokemon/moltres/icon.4bpp");
#else
    const u8 gMonIcon_Moltres[] = INCBIN_U8("graphics/pokemon/moltres/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Moltres[] = INCBIN_U8("graphics/pokemon/moltres/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Moltres[] = INCBIN_COMP("graphics/pokemon/moltres/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Moltres[] = INCBIN_U32("graphics/pokemon/moltres/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Moltres[] = INCBIN_U32("graphics/pokemon/moltres/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_MOLTRES

#if P_FAMILY_DRATINI
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Dratini[] = INCBIN_U32("graphics/pokemon/dratini/anim_front.4bpp.lz");
    const u32 gMonPalette_Dratini[] = INCBIN_U32("graphics/pokemon/dratini/normal.gbapal.lz");
    const u32 gMonBackPic_Dratini[] = INCBIN_U32("graphics/pokemon/dratini/back.4bpp.lz");
    const u32 gMonShinyPalette_Dratini[] = INCBIN_U32("graphics/pokemon/dratini/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Dratini[] = INCBIN_U32("graphics/pokemon/dratini/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Dratini[] = INCBIN_U32("graphics/pokemon/dratini/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Dratini[] = INCBIN_U32("graphics/pokemon/dratini/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Dratini[] = INCBIN_U32("graphics/pokemon/dratini/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Dratini[] = INCBIN_U8("graphics/pokemon/dratini/icon.4bpp");
#else
    const u8 gMonIcon_Dratini[] = INCBIN_U8("graphics/pokemon/dratini/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Dratini[] = INCBIN_U8("graphics/pokemon/dratini/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Dratini[] = INCBIN_COMP("graphics/pokemon/dratini/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Dratini[] = INCBIN_U32("graphics/pokemon/dratini/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Dratini[] = INCBIN_U32("graphics/pokemon/dratini/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Dragonair[] = INCBIN_U32("graphics/pokemon/dragonair/anim_front.4bpp.lz");
    const u32 gMonPalette_Dragonair[] = INCBIN_U32("graphics/pokemon/dragonair/normal.gbapal.lz");
    const u32 gMonBackPic_Dragonair[] = INCBIN_U32("graphics/pokemon/dragonair/back.4bpp.lz");
    const u32 gMonShinyPalette_Dragonair[] = INCBIN_U32("graphics/pokemon/dragonair/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Dragonair[] = INCBIN_U32("graphics/pokemon/dragonair/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Dragonair[] = INCBIN_U32("graphics/pokemon/dragonair/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Dragonair[] = INCBIN_U32("graphics/pokemon/dragonair/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Dragonair[] = INCBIN_U32("graphics/pokemon/dragonair/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Dragonair[] = INCBIN_U8("graphics/pokemon/dragonair/icon.4bpp");
#else
    const u8 gMonIcon_Dragonair[] = INCBIN_U8("graphics/pokemon/dragonair/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Dragonair[] = INCBIN_U8("graphics/pokemon/dragonair/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Dragonair[] = INCBIN_COMP("graphics/pokemon/dragonair/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Dragonair[] = INCBIN_U32("graphics/pokemon/dragonair/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Dragonair[] = INCBIN_U32("graphics/pokemon/dragonair/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Dragonite[] = INCBIN_U32("graphics/pokemon/dragonite/anim_front.4bpp.lz");
    const u32 gMonPalette_Dragonite[] = INCBIN_U32("graphics/pokemon/dragonite/normal.gbapal.lz");
    const u32 gMonBackPic_Dragonite[] = INCBIN_U32("graphics/pokemon/dragonite/back.4bpp.lz");
    const u32 gMonShinyPalette_Dragonite[] = INCBIN_U32("graphics/pokemon/dragonite/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Dragonite[] = INCBIN_U32("graphics/pokemon/dragonite/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Dragonite[] = INCBIN_U32("graphics/pokemon/dragonite/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Dragonite[] = INCBIN_U32("graphics/pokemon/dragonite/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Dragonite[] = INCBIN_U32("graphics/pokemon/dragonite/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Dragonite[] = INCBIN_U8("graphics/pokemon/dragonite/icon.4bpp");
#else
    const u8 gMonIcon_Dragonite[] = INCBIN_U8("graphics/pokemon/dragonite/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Dragonite[] = INCBIN_U8("graphics/pokemon/dragonite/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Dragonite[] = INCBIN_COMP("graphics/pokemon/dragonite/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Dragonite[] = INCBIN_U32("graphics/pokemon/dragonite/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Dragonite[] = INCBIN_U32("graphics/pokemon/dragonite/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_DRATINI

#if P_FAMILY_MEWTWO
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Mewtwo[] = INCBIN_U32("graphics/pokemon/mewtwo/anim_front.4bpp.lz");
    const u32 gMonPalette_Mewtwo[] = INCBIN_U32("graphics/pokemon/mewtwo/normal.gbapal.lz");
    const u32 gMonBackPic_Mewtwo[] = INCBIN_U32("graphics/pokemon/mewtwo/back.4bpp.lz");
    const u32 gMonShinyPalette_Mewtwo[] = INCBIN_U32("graphics/pokemon/mewtwo/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Mewtwo[] = INCBIN_U32("graphics/pokemon/mewtwo/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Mewtwo[] = INCBIN_U32("graphics/pokemon/mewtwo/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Mewtwo[] = INCBIN_U32("graphics/pokemon/mewtwo/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Mewtwo[] = INCBIN_U32("graphics/pokemon/mewtwo/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Mewtwo[] = INCBIN_U8("graphics/pokemon/mewtwo/icon.4bpp");
#else
    const u8 gMonIcon_Mewtwo[] = INCBIN_U8("graphics/pokemon/mewtwo/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Mewtwo[] = INCBIN_U8("graphics/pokemon/mewtwo/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Mewtwo[] = INCBIN_COMP("graphics/pokemon/mewtwo/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Mewtwo[] = INCBIN_U32("graphics/pokemon/mewtwo/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Mewtwo[] = INCBIN_U32("graphics/pokemon/mewtwo/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_MEWTWO

#if P_FAMILY_MEW
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Mew[] = INCBIN_U32("graphics/pokemon/mew/anim_front.4bpp.lz");
    const u32 gMonPalette_Mew[] = INCBIN_U32("graphics/pokemon/mew/normal.gbapal.lz");
    const u32 gMonBackPic_Mew[] = INCBIN_U32("graphics/pokemon/mew/back.4bpp.lz");
    const u32 gMonShinyPalette_Mew[] = INCBIN_U32("graphics/pokemon/mew/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Mew[] = INCBIN_U32("graphics/pokemon/mew/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Mew[] = INCBIN_U32("graphics/pokemon/mew/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Mew[] = INCBIN_U32("graphics/pokemon/mew/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Mew[] = INCBIN_U32("graphics/pokemon/mew/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Mew[] = INCBIN_U8("graphics/pokemon/mew/icon.4bpp");
#else
    const u8 gMonIcon_Mew[] = INCBIN_U8("graphics/pokemon/mew/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Mew[] = INCBIN_U8("graphics/pokemon/mew/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Mew[] = INCBIN_COMP("graphics/pokemon/mew/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Mew[] = INCBIN_U32("graphics/pokemon/mew/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Mew[] = INCBIN_U32("graphics/pokemon/mew/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_MEW

#if P_FAMILY_CHIKORITA
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Chikorita[] = INCBIN_U32("graphics/pokemon/chikorita/anim_front.4bpp.lz");
    const u32 gMonPalette_Chikorita[] = INCBIN_U32("graphics/pokemon/chikorita/normal.gbapal.lz");
    const u32 gMonBackPic_Chikorita[] = INCBIN_U32("graphics/pokemon/chikorita/back.4bpp.lz");
    const u32 gMonShinyPalette_Chikorita[] = INCBIN_U32("graphics/pokemon/chikorita/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Chikorita[] = INCBIN_U32("graphics/pokemon/chikorita/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Chikorita[] = INCBIN_U32("graphics/pokemon/chikorita/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Chikorita[] = INCBIN_U32("graphics/pokemon/chikorita/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Chikorita[] = INCBIN_U32("graphics/pokemon/chikorita/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Chikorita[] = INCBIN_U8("graphics/pokemon/chikorita/icon.4bpp");
#else
    const u8 gMonIcon_Chikorita[] = INCBIN_U8("graphics/pokemon/chikorita/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Chikorita[] = INCBIN_U8("graphics/pokemon/chikorita/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Chikorita[] = INCBIN_COMP("graphics/pokemon/chikorita/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Chikorita[] = INCBIN_U32("graphics/pokemon/chikorita/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Chikorita[] = INCBIN_U32("graphics/pokemon/chikorita/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Bayleef[] = INCBIN_U32("graphics/pokemon/bayleef/anim_front.4bpp.lz");
    const u32 gMonPalette_Bayleef[] = INCBIN_U32("graphics/pokemon/bayleef/normal.gbapal.lz");
    const u32 gMonBackPic_Bayleef[] = INCBIN_U32("graphics/pokemon/bayleef/back.4bpp.lz");
    const u32 gMonShinyPalette_Bayleef[] = INCBIN_U32("graphics/pokemon/bayleef/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Bayleef[] = INCBIN_U32("graphics/pokemon/bayleef/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Bayleef[] = INCBIN_U32("graphics/pokemon/bayleef/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Bayleef[] = INCBIN_U32("graphics/pokemon/bayleef/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Bayleef[] = INCBIN_U32("graphics/pokemon/bayleef/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Bayleef[] = INCBIN_U8("graphics/pokemon/bayleef/icon.4bpp");
#else
    const u8 gMonIcon_Bayleef[] = INCBIN_U8("graphics/pokemon/bayleef/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Bayleef[] = INCBIN_U8("graphics/pokemon/bayleef/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Bayleef[] = INCBIN_COMP("graphics/pokemon/bayleef/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Bayleef[] = INCBIN_U32("graphics/pokemon/bayleef/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Bayleef[] = INCBIN_U32("graphics/pokemon/bayleef/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Meganium[] = INCBIN_U32("graphics/pokemon/meganium/anim_front.4bpp.lz");
    const u32 gMonPalette_Meganium[] = INCBIN_U32("graphics/pokemon/meganium/normal.gbapal.lz");
    const u32 gMonBackPic_Meganium[] = INCBIN_U32("graphics/pokemon/meganium/back.4bpp.lz");
    const u32 gMonShinyPalette_Meganium[] = INCBIN_U32("graphics/pokemon/meganium/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Meganium[] = INCBIN_U32("graphics/pokemon/meganium/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Meganium[] = INCBIN_U32("graphics/pokemon/meganium/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Meganium[] = INCBIN_U32("graphics/pokemon/meganium/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Meganium[] = INCBIN_U32("graphics/pokemon/meganium/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Meganium[] = INCBIN_U8("graphics/pokemon/meganium/icon.4bpp");
#else
    const u8 gMonIcon_Meganium[] = INCBIN_U8("graphics/pokemon/meganium/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Meganium[] = INCBIN_U8("graphics/pokemon/meganium/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Meganium[] = INCBIN_COMP("graphics/pokemon/meganium/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Meganium[] = INCBIN_U32("graphics/pokemon/meganium/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Meganium[] = INCBIN_U32("graphics/pokemon/meganium/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_MeganiumF[] = INCBIN_U32("graphics/pokemon/meganium/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_MeganiumF[] = INCBIN_U32("graphics/pokemon/meganium/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_MeganiumF[] = INCBIN_COMP("graphics/pokemon/meganium/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_CHIKORITA

#if P_FAMILY_CYNDAQUIL
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Cyndaquil[] = INCBIN_U32("graphics/pokemon/cyndaquil/anim_front.4bpp.lz");
    const u32 gMonPalette_Cyndaquil[] = INCBIN_U32("graphics/pokemon/cyndaquil/normal.gbapal.lz");
    const u32 gMonBackPic_Cyndaquil[] = INCBIN_U32("graphics/pokemon/cyndaquil/back.4bpp.lz");
    const u32 gMonShinyPalette_Cyndaquil[] = INCBIN_U32("graphics/pokemon/cyndaquil/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Cyndaquil[] = INCBIN_U32("graphics/pokemon/cyndaquil/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Cyndaquil[] = INCBIN_U32("graphics/pokemon/cyndaquil/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Cyndaquil[] = INCBIN_U32("graphics/pokemon/cyndaquil/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Cyndaquil[] = INCBIN_U32("graphics/pokemon/cyndaquil/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Cyndaquil[] = INCBIN_U8("graphics/pokemon/cyndaquil/icon.4bpp");
#else
    const u8 gMonIcon_Cyndaquil[] = INCBIN_U8("graphics/pokemon/cyndaquil/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Cyndaquil[] = INCBIN_U8("graphics/pokemon/cyndaquil/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Cyndaquil[] = INCBIN_COMP("graphics/pokemon/cyndaquil/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Cyndaquil[] = INCBIN_U32("graphics/pokemon/cyndaquil/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Cyndaquil[] = INCBIN_U32("graphics/pokemon/cyndaquil/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Quilava[] = INCBIN_U32("graphics/pokemon/quilava/anim_front.4bpp.lz");
    const u32 gMonPalette_Quilava[] = INCBIN_U32("graphics/pokemon/quilava/normal.gbapal.lz");
    const u32 gMonBackPic_Quilava[] = INCBIN_U32("graphics/pokemon/quilava/back.4bpp.lz");
    const u32 gMonShinyPalette_Quilava[] = INCBIN_U32("graphics/pokemon/quilava/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Quilava[] = INCBIN_U32("graphics/pokemon/quilava/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Quilava[] = INCBIN_U32("graphics/pokemon/quilava/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Quilava[] = INCBIN_U32("graphics/pokemon/quilava/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Quilava[] = INCBIN_U32("graphics/pokemon/quilava/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Quilava[] = INCBIN_U8("graphics/pokemon/quilava/icon.4bpp");
#else
    const u8 gMonIcon_Quilava[] = INCBIN_U8("graphics/pokemon/quilava/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Quilava[] = INCBIN_U8("graphics/pokemon/quilava/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Quilava[] = INCBIN_COMP("graphics/pokemon/quilava/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Quilava[] = INCBIN_U32("graphics/pokemon/quilava/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Quilava[] = INCBIN_U32("graphics/pokemon/quilava/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Typhlosion[] = INCBIN_U32("graphics/pokemon/typhlosion/anim_front.4bpp.lz");
    const u32 gMonPalette_Typhlosion[] = INCBIN_U32("graphics/pokemon/typhlosion/normal.gbapal.lz");
    const u32 gMonBackPic_Typhlosion[] = INCBIN_U32("graphics/pokemon/typhlosion/back.4bpp.lz");
    const u32 gMonShinyPalette_Typhlosion[] = INCBIN_U32("graphics/pokemon/typhlosion/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Typhlosion[] = INCBIN_U32("graphics/pokemon/typhlosion/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Typhlosion[] = INCBIN_U32("graphics/pokemon/typhlosion/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Typhlosion[] = INCBIN_U32("graphics/pokemon/typhlosion/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Typhlosion[] = INCBIN_U32("graphics/pokemon/typhlosion/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Typhlosion[] = INCBIN_U8("graphics/pokemon/typhlosion/icon.4bpp");
#else
    const u8 gMonIcon_Typhlosion[] = INCBIN_U8("graphics/pokemon/typhlosion/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Typhlosion[] = INCBIN_U8("graphics/pokemon/typhlosion/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Typhlosion[] = INCBIN_COMP("graphics/pokemon/typhlosion/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Typhlosion[] = INCBIN_U32("graphics/pokemon/typhlosion/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Typhlosion[] = INCBIN_U32("graphics/pokemon/typhlosion/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_CYNDAQUIL

#if P_FAMILY_TOTODILE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Totodile[] = INCBIN_U32("graphics/pokemon/totodile/anim_front.4bpp.lz");
    const u32 gMonPalette_Totodile[] = INCBIN_U32("graphics/pokemon/totodile/normal.gbapal.lz");
    const u32 gMonBackPic_Totodile[] = INCBIN_U32("graphics/pokemon/totodile/back.4bpp.lz");
    const u32 gMonShinyPalette_Totodile[] = INCBIN_U32("graphics/pokemon/totodile/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Totodile[] = INCBIN_U32("graphics/pokemon/totodile/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Totodile[] = INCBIN_U32("graphics/pokemon/totodile/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Totodile[] = INCBIN_U32("graphics/pokemon/totodile/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Totodile[] = INCBIN_U32("graphics/pokemon/totodile/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Totodile[] = INCBIN_U8("graphics/pokemon/totodile/icon.4bpp");
#else
    const u8 gMonIcon_Totodile[] = INCBIN_U8("graphics/pokemon/totodile/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Totodile[] = INCBIN_U8("graphics/pokemon/totodile/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Totodile[] = INCBIN_COMP("graphics/pokemon/totodile/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Totodile[] = INCBIN_U32("graphics/pokemon/totodile/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Totodile[] = INCBIN_U32("graphics/pokemon/totodile/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Croconaw[] = INCBIN_U32("graphics/pokemon/croconaw/anim_front.4bpp.lz");
    const u32 gMonPalette_Croconaw[] = INCBIN_U32("graphics/pokemon/croconaw/normal.gbapal.lz");
    const u32 gMonBackPic_Croconaw[] = INCBIN_U32("graphics/pokemon/croconaw/back.4bpp.lz");
    const u32 gMonShinyPalette_Croconaw[] = INCBIN_U32("graphics/pokemon/croconaw/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Croconaw[] = INCBIN_U32("graphics/pokemon/croconaw/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Croconaw[] = INCBIN_U32("graphics/pokemon/croconaw/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Croconaw[] = INCBIN_U32("graphics/pokemon/croconaw/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Croconaw[] = INCBIN_U32("graphics/pokemon/croconaw/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Croconaw[] = INCBIN_U8("graphics/pokemon/croconaw/icon.4bpp");
#else
    const u8 gMonIcon_Croconaw[] = INCBIN_U8("graphics/pokemon/croconaw/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Croconaw[] = INCBIN_U8("graphics/pokemon/croconaw/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Croconaw[] = INCBIN_COMP("graphics/pokemon/croconaw/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Croconaw[] = INCBIN_U32("graphics/pokemon/croconaw/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Croconaw[] = INCBIN_U32("graphics/pokemon/croconaw/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Feraligatr[] = INCBIN_U32("graphics/pokemon/feraligatr/anim_front.4bpp.lz");
    const u32 gMonPalette_Feraligatr[] = INCBIN_U32("graphics/pokemon/feraligatr/normal.gbapal.lz");
    const u32 gMonBackPic_Feraligatr[] = INCBIN_U32("graphics/pokemon/feraligatr/back.4bpp.lz");
    const u32 gMonShinyPalette_Feraligatr[] = INCBIN_U32("graphics/pokemon/feraligatr/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Feraligatr[] = INCBIN_U32("graphics/pokemon/feraligatr/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Feraligatr[] = INCBIN_U32("graphics/pokemon/feraligatr/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Feraligatr[] = INCBIN_U32("graphics/pokemon/feraligatr/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Feraligatr[] = INCBIN_U32("graphics/pokemon/feraligatr/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Feraligatr[] = INCBIN_U8("graphics/pokemon/feraligatr/icon.4bpp");
#else
    const u8 gMonIcon_Feraligatr[] = INCBIN_U8("graphics/pokemon/feraligatr/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Feraligatr[] = INCBIN_U8("graphics/pokemon/feraligatr/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Feraligatr[] = INCBIN_COMP("graphics/pokemon/feraligatr/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Feraligatr[] = INCBIN_U32("graphics/pokemon/feraligatr/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Feraligatr[] = INCBIN_U32("graphics/pokemon/feraligatr/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_TOTODILE

#if P_FAMILY_SENTRET
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Sentret[] = INCBIN_U32("graphics/pokemon/sentret/anim_front.4bpp.lz");
    const u32 gMonPalette_Sentret[] = INCBIN_U32("graphics/pokemon/sentret/normal.gbapal.lz");
    const u32 gMonBackPic_Sentret[] = INCBIN_U32("graphics/pokemon/sentret/back.4bpp.lz");
    const u32 gMonShinyPalette_Sentret[] = INCBIN_U32("graphics/pokemon/sentret/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Sentret[] = INCBIN_U32("graphics/pokemon/sentret/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Sentret[] = INCBIN_U32("graphics/pokemon/sentret/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Sentret[] = INCBIN_U32("graphics/pokemon/sentret/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Sentret[] = INCBIN_U32("graphics/pokemon/sentret/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Sentret[] = INCBIN_U8("graphics/pokemon/sentret/icon.4bpp");
#else
    const u8 gMonIcon_Sentret[] = INCBIN_U8("graphics/pokemon/sentret/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Sentret[] = INCBIN_U8("graphics/pokemon/sentret/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Sentret[] = INCBIN_COMP("graphics/pokemon/sentret/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Sentret[] = INCBIN_U32("graphics/pokemon/sentret/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Sentret[] = INCBIN_U32("graphics/pokemon/sentret/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Furret[] = INCBIN_U32("graphics/pokemon/furret/anim_front.4bpp.lz");
    const u32 gMonPalette_Furret[] = INCBIN_U32("graphics/pokemon/furret/normal.gbapal.lz");
    const u32 gMonBackPic_Furret[] = INCBIN_U32("graphics/pokemon/furret/back.4bpp.lz");
    const u32 gMonShinyPalette_Furret[] = INCBIN_U32("graphics/pokemon/furret/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Furret[] = INCBIN_U32("graphics/pokemon/furret/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Furret[] = INCBIN_U32("graphics/pokemon/furret/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Furret[] = INCBIN_U32("graphics/pokemon/furret/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Furret[] = INCBIN_U32("graphics/pokemon/furret/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Furret[] = INCBIN_U8("graphics/pokemon/furret/icon.4bpp");
#else
    const u8 gMonIcon_Furret[] = INCBIN_U8("graphics/pokemon/furret/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Furret[] = INCBIN_U8("graphics/pokemon/furret/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Furret[] = INCBIN_COMP("graphics/pokemon/furret/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Furret[] = INCBIN_U32("graphics/pokemon/furret/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Furret[] = INCBIN_U32("graphics/pokemon/furret/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SENTRET

#if P_FAMILY_HOOTHOOT
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Hoothoot[] = INCBIN_U32("graphics/pokemon/hoothoot/anim_front.4bpp.lz");
    const u32 gMonPalette_Hoothoot[] = INCBIN_U32("graphics/pokemon/hoothoot/normal.gbapal.lz");
    const u32 gMonBackPic_Hoothoot[] = INCBIN_U32("graphics/pokemon/hoothoot/back.4bpp.lz");
    const u32 gMonShinyPalette_Hoothoot[] = INCBIN_U32("graphics/pokemon/hoothoot/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Hoothoot[] = INCBIN_U32("graphics/pokemon/hoothoot/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Hoothoot[] = INCBIN_U32("graphics/pokemon/hoothoot/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Hoothoot[] = INCBIN_U32("graphics/pokemon/hoothoot/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Hoothoot[] = INCBIN_U32("graphics/pokemon/hoothoot/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Hoothoot[] = INCBIN_U8("graphics/pokemon/hoothoot/icon.4bpp");
#else
    const u8 gMonIcon_Hoothoot[] = INCBIN_U8("graphics/pokemon/hoothoot/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Hoothoot[] = INCBIN_U8("graphics/pokemon/hoothoot/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Hoothoot[] = INCBIN_COMP("graphics/pokemon/hoothoot/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Hoothoot[] = INCBIN_U32("graphics/pokemon/hoothoot/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Hoothoot[] = INCBIN_U32("graphics/pokemon/hoothoot/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Noctowl[] = INCBIN_U32("graphics/pokemon/noctowl/anim_front.4bpp.lz");
    const u32 gMonPalette_Noctowl[] = INCBIN_U32("graphics/pokemon/noctowl/normal.gbapal.lz");
    const u32 gMonBackPic_Noctowl[] = INCBIN_U32("graphics/pokemon/noctowl/back.4bpp.lz");
    const u32 gMonShinyPalette_Noctowl[] = INCBIN_U32("graphics/pokemon/noctowl/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Noctowl[] = INCBIN_U32("graphics/pokemon/noctowl/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Noctowl[] = INCBIN_U32("graphics/pokemon/noctowl/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Noctowl[] = INCBIN_U32("graphics/pokemon/noctowl/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Noctowl[] = INCBIN_U32("graphics/pokemon/noctowl/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Noctowl[] = INCBIN_U8("graphics/pokemon/noctowl/icon.4bpp");
#else
    const u8 gMonIcon_Noctowl[] = INCBIN_U8("graphics/pokemon/noctowl/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Noctowl[] = INCBIN_U8("graphics/pokemon/noctowl/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Noctowl[] = INCBIN_COMP("graphics/pokemon/noctowl/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Noctowl[] = INCBIN_U32("graphics/pokemon/noctowl/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Noctowl[] = INCBIN_U32("graphics/pokemon/noctowl/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_HOOTHOOT

#if P_FAMILY_LEDYBA
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Ledyba[] = INCBIN_U32("graphics/pokemon/ledyba/anim_front.4bpp.lz");
    const u32 gMonPalette_Ledyba[] = INCBIN_U32("graphics/pokemon/ledyba/normal.gbapal.lz");
    const u32 gMonBackPic_Ledyba[] = INCBIN_U32("graphics/pokemon/ledyba/back.4bpp.lz");
    const u32 gMonShinyPalette_Ledyba[] = INCBIN_U32("graphics/pokemon/ledyba/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Ledyba[] = INCBIN_U32("graphics/pokemon/ledyba/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Ledyba[] = INCBIN_U32("graphics/pokemon/ledyba/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Ledyba[] = INCBIN_U32("graphics/pokemon/ledyba/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Ledyba[] = INCBIN_U32("graphics/pokemon/ledyba/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Ledyba[] = INCBIN_U8("graphics/pokemon/ledyba/icon.4bpp");
#else
    const u8 gMonIcon_Ledyba[] = INCBIN_U8("graphics/pokemon/ledyba/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Ledyba[] = INCBIN_U8("graphics/pokemon/ledyba/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Ledyba[] = INCBIN_COMP("graphics/pokemon/ledyba/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Ledyba[] = INCBIN_U32("graphics/pokemon/ledyba/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Ledyba[] = INCBIN_U32("graphics/pokemon/ledyba/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_LedybaF[] = INCBIN_U32("graphics/pokemon/ledyba/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_LedybaF[] = INCBIN_U32("graphics/pokemon/ledyba/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_LedybaF[] = INCBIN_COMP("graphics/pokemon/ledyba/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Ledian[] = INCBIN_U32("graphics/pokemon/ledian/anim_front.4bpp.lz");
    const u32 gMonPalette_Ledian[] = INCBIN_U32("graphics/pokemon/ledian/normal.gbapal.lz");
    const u32 gMonBackPic_Ledian[] = INCBIN_U32("graphics/pokemon/ledian/back.4bpp.lz");
    const u32 gMonShinyPalette_Ledian[] = INCBIN_U32("graphics/pokemon/ledian/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Ledian[] = INCBIN_U32("graphics/pokemon/ledian/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Ledian[] = INCBIN_U32("graphics/pokemon/ledian/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Ledian[] = INCBIN_U32("graphics/pokemon/ledian/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Ledian[] = INCBIN_U32("graphics/pokemon/ledian/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Ledian[] = INCBIN_U8("graphics/pokemon/ledian/icon.4bpp");
#else
    const u8 gMonIcon_Ledian[] = INCBIN_U8("graphics/pokemon/ledian/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Ledian[] = INCBIN_U8("graphics/pokemon/ledian/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Ledian[] = INCBIN_COMP("graphics/pokemon/ledian/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Ledian[] = INCBIN_U32("graphics/pokemon/ledian/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Ledian[] = INCBIN_U32("graphics/pokemon/ledian/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_LedianF[] = INCBIN_U32("graphics/pokemon/ledian/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_LedianF[] = INCBIN_U32("graphics/pokemon/ledian/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_LedianF[] = INCBIN_COMP("graphics/pokemon/ledian/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_LEDYBA

#if P_FAMILY_SPINARAK
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Spinarak[] = INCBIN_U32("graphics/pokemon/spinarak/anim_front.4bpp.lz");
    const u32 gMonPalette_Spinarak[] = INCBIN_U32("graphics/pokemon/spinarak/normal.gbapal.lz");
    const u32 gMonBackPic_Spinarak[] = INCBIN_U32("graphics/pokemon/spinarak/back.4bpp.lz");
    const u32 gMonShinyPalette_Spinarak[] = INCBIN_U32("graphics/pokemon/spinarak/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Spinarak[] = INCBIN_U32("graphics/pokemon/spinarak/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Spinarak[] = INCBIN_U32("graphics/pokemon/spinarak/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Spinarak[] = INCBIN_U32("graphics/pokemon/spinarak/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Spinarak[] = INCBIN_U32("graphics/pokemon/spinarak/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Spinarak[] = INCBIN_U8("graphics/pokemon/spinarak/icon.4bpp");
#else
    const u8 gMonIcon_Spinarak[] = INCBIN_U8("graphics/pokemon/spinarak/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Spinarak[] = INCBIN_U8("graphics/pokemon/spinarak/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Spinarak[] = INCBIN_COMP("graphics/pokemon/spinarak/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Spinarak[] = INCBIN_U32("graphics/pokemon/spinarak/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Spinarak[] = INCBIN_U32("graphics/pokemon/spinarak/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Ariados[] = INCBIN_U32("graphics/pokemon/ariados/anim_front.4bpp.lz");
    const u32 gMonPalette_Ariados[] = INCBIN_U32("graphics/pokemon/ariados/normal.gbapal.lz");
    const u32 gMonBackPic_Ariados[] = INCBIN_U32("graphics/pokemon/ariados/back.4bpp.lz");
    const u32 gMonShinyPalette_Ariados[] = INCBIN_U32("graphics/pokemon/ariados/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Ariados[] = INCBIN_U32("graphics/pokemon/ariados/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Ariados[] = INCBIN_U32("graphics/pokemon/ariados/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Ariados[] = INCBIN_U32("graphics/pokemon/ariados/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Ariados[] = INCBIN_U32("graphics/pokemon/ariados/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Ariados[] = INCBIN_U8("graphics/pokemon/ariados/icon.4bpp");
#else
    const u8 gMonIcon_Ariados[] = INCBIN_U8("graphics/pokemon/ariados/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Ariados[] = INCBIN_U8("graphics/pokemon/ariados/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Ariados[] = INCBIN_COMP("graphics/pokemon/ariados/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Ariados[] = INCBIN_U32("graphics/pokemon/ariados/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Ariados[] = INCBIN_U32("graphics/pokemon/ariados/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SPINARAK

#if P_FAMILY_CHINCHOU
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Chinchou[] = INCBIN_U32("graphics/pokemon/chinchou/anim_front.4bpp.lz");
    const u32 gMonPalette_Chinchou[] = INCBIN_U32("graphics/pokemon/chinchou/normal.gbapal.lz");
    const u32 gMonBackPic_Chinchou[] = INCBIN_U32("graphics/pokemon/chinchou/back.4bpp.lz");
    const u32 gMonShinyPalette_Chinchou[] = INCBIN_U32("graphics/pokemon/chinchou/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Chinchou[] = INCBIN_U32("graphics/pokemon/chinchou/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Chinchou[] = INCBIN_U32("graphics/pokemon/chinchou/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Chinchou[] = INCBIN_U32("graphics/pokemon/chinchou/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Chinchou[] = INCBIN_U32("graphics/pokemon/chinchou/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Chinchou[] = INCBIN_U8("graphics/pokemon/chinchou/icon.4bpp");
#else
    const u8 gMonIcon_Chinchou[] = INCBIN_U8("graphics/pokemon/chinchou/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Chinchou[] = INCBIN_U8("graphics/pokemon/chinchou/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Chinchou[] = INCBIN_COMP("graphics/pokemon/chinchou/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Chinchou[] = INCBIN_U32("graphics/pokemon/chinchou/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Chinchou[] = INCBIN_U32("graphics/pokemon/chinchou/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Lanturn[] = INCBIN_U32("graphics/pokemon/lanturn/anim_front.4bpp.lz");
    const u32 gMonPalette_Lanturn[] = INCBIN_U32("graphics/pokemon/lanturn/normal.gbapal.lz");
    const u32 gMonBackPic_Lanturn[] = INCBIN_U32("graphics/pokemon/lanturn/back.4bpp.lz");
    const u32 gMonShinyPalette_Lanturn[] = INCBIN_U32("graphics/pokemon/lanturn/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Lanturn[] = INCBIN_U32("graphics/pokemon/lanturn/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Lanturn[] = INCBIN_U32("graphics/pokemon/lanturn/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Lanturn[] = INCBIN_U32("graphics/pokemon/lanturn/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Lanturn[] = INCBIN_U32("graphics/pokemon/lanturn/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Lanturn[] = INCBIN_U8("graphics/pokemon/lanturn/icon.4bpp");
#else
    const u8 gMonIcon_Lanturn[] = INCBIN_U8("graphics/pokemon/lanturn/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Lanturn[] = INCBIN_U8("graphics/pokemon/lanturn/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Lanturn[] = INCBIN_COMP("graphics/pokemon/lanturn/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Lanturn[] = INCBIN_U32("graphics/pokemon/lanturn/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Lanturn[] = INCBIN_U32("graphics/pokemon/lanturn/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_CHINCHOU

#if P_FAMILY_TOGEPI
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Togepi[] = INCBIN_U32("graphics/pokemon/togepi/anim_front.4bpp.lz");
    const u32 gMonPalette_Togepi[] = INCBIN_U32("graphics/pokemon/togepi/normal.gbapal.lz");
    const u32 gMonBackPic_Togepi[] = INCBIN_U32("graphics/pokemon/togepi/back.4bpp.lz");
    const u32 gMonShinyPalette_Togepi[] = INCBIN_U32("graphics/pokemon/togepi/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Togepi[] = INCBIN_U32("graphics/pokemon/togepi/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Togepi[] = INCBIN_U32("graphics/pokemon/togepi/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Togepi[] = INCBIN_U32("graphics/pokemon/togepi/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Togepi[] = INCBIN_U32("graphics/pokemon/togepi/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Togepi[] = INCBIN_U8("graphics/pokemon/togepi/icon.4bpp");
#else
    const u8 gMonIcon_Togepi[] = INCBIN_U8("graphics/pokemon/togepi/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Togepi[] = INCBIN_U8("graphics/pokemon/togepi/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Togepi[] = INCBIN_COMP("graphics/pokemon/togepi/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Togepi[] = INCBIN_U32("graphics/pokemon/togepi/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Togepi[] = INCBIN_U32("graphics/pokemon/togepi/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Togetic[] = INCBIN_U32("graphics/pokemon/togetic/anim_front.4bpp.lz");
    const u32 gMonPalette_Togetic[] = INCBIN_U32("graphics/pokemon/togetic/normal.gbapal.lz");
    const u32 gMonBackPic_Togetic[] = INCBIN_U32("graphics/pokemon/togetic/back.4bpp.lz");
    const u32 gMonShinyPalette_Togetic[] = INCBIN_U32("graphics/pokemon/togetic/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Togetic[] = INCBIN_U32("graphics/pokemon/togetic/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Togetic[] = INCBIN_U32("graphics/pokemon/togetic/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Togetic[] = INCBIN_U32("graphics/pokemon/togetic/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Togetic[] = INCBIN_U32("graphics/pokemon/togetic/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Togetic[] = INCBIN_U8("graphics/pokemon/togetic/icon.4bpp");
#else
    const u8 gMonIcon_Togetic[] = INCBIN_U8("graphics/pokemon/togetic/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Togetic[] = INCBIN_U8("graphics/pokemon/togetic/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Togetic[] = INCBIN_COMP("graphics/pokemon/togetic/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Togetic[] = INCBIN_U32("graphics/pokemon/togetic/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Togetic[] = INCBIN_U32("graphics/pokemon/togetic/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Togekiss[] = INCBIN_U32("graphics/pokemon/togekiss/anim_front.4bpp.lz");
    const u32 gMonPalette_Togekiss[] = INCBIN_U32("graphics/pokemon/togekiss/normal.gbapal.lz");
    const u32 gMonBackPic_Togekiss[] = INCBIN_U32("graphics/pokemon/togekiss/back.4bpp.lz");
    const u32 gMonShinyPalette_Togekiss[] = INCBIN_U32("graphics/pokemon/togekiss/shiny.gbapal.lz");
    const u8 gMonIcon_Togekiss[] = INCBIN_U8("graphics/pokemon/togekiss/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Togekiss[] = INCBIN_U8("graphics/pokemon/togekiss/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Togekiss[] = INCBIN_COMP("graphics/pokemon/togekiss/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Togekiss[] = INCBIN_U32("graphics/pokemon/togekiss/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Togekiss[] = INCBIN_U32("graphics/pokemon/togekiss/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_TOGEPI

#if P_FAMILY_NATU
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Natu[] = INCBIN_U32("graphics/pokemon/natu/anim_front.4bpp.lz");
    const u32 gMonPalette_Natu[] = INCBIN_U32("graphics/pokemon/natu/normal.gbapal.lz");
    const u32 gMonBackPic_Natu[] = INCBIN_U32("graphics/pokemon/natu/back.4bpp.lz");
    const u32 gMonShinyPalette_Natu[] = INCBIN_U32("graphics/pokemon/natu/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Natu[] = INCBIN_U32("graphics/pokemon/natu/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Natu[] = INCBIN_U32("graphics/pokemon/natu/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Natu[] = INCBIN_U32("graphics/pokemon/natu/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Natu[] = INCBIN_U32("graphics/pokemon/natu/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Natu[] = INCBIN_U8("graphics/pokemon/natu/icon.4bpp");
#else
    const u8 gMonIcon_Natu[] = INCBIN_U8("graphics/pokemon/natu/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Natu[] = INCBIN_U8("graphics/pokemon/natu/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Natu[] = INCBIN_COMP("graphics/pokemon/natu/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Natu[] = INCBIN_U32("graphics/pokemon/natu/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Natu[] = INCBIN_U32("graphics/pokemon/natu/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Xatu[] = INCBIN_U32("graphics/pokemon/xatu/anim_front.4bpp.lz");
    const u32 gMonPalette_Xatu[] = INCBIN_U32("graphics/pokemon/xatu/normal.gbapal.lz");
    const u32 gMonBackPic_Xatu[] = INCBIN_U32("graphics/pokemon/xatu/back.4bpp.lz");
    const u32 gMonShinyPalette_Xatu[] = INCBIN_U32("graphics/pokemon/xatu/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Xatu[] = INCBIN_U32("graphics/pokemon/xatu/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Xatu[] = INCBIN_U32("graphics/pokemon/xatu/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Xatu[] = INCBIN_U32("graphics/pokemon/xatu/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Xatu[] = INCBIN_U32("graphics/pokemon/xatu/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Xatu[] = INCBIN_U8("graphics/pokemon/xatu/icon.4bpp");
#else
    const u8 gMonIcon_Xatu[] = INCBIN_U8("graphics/pokemon/xatu/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Xatu[] = INCBIN_U8("graphics/pokemon/xatu/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Xatu[] = INCBIN_COMP("graphics/pokemon/xatu/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Xatu[] = INCBIN_U32("graphics/pokemon/xatu/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Xatu[] = INCBIN_U32("graphics/pokemon/xatu/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_XatuF[] = INCBIN_U32("graphics/pokemon/xatu/anim_frontf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_XatuF[] = INCBIN_COMP("graphics/pokemon/xatu/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_NATU

#if P_FAMILY_MAREEP
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Mareep[] = INCBIN_U32("graphics/pokemon/mareep/anim_front.4bpp.lz");
    const u32 gMonPalette_Mareep[] = INCBIN_U32("graphics/pokemon/mareep/normal.gbapal.lz");
    const u32 gMonBackPic_Mareep[] = INCBIN_U32("graphics/pokemon/mareep/back.4bpp.lz");
    const u32 gMonShinyPalette_Mareep[] = INCBIN_U32("graphics/pokemon/mareep/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Mareep[] = INCBIN_U32("graphics/pokemon/mareep/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Mareep[] = INCBIN_U32("graphics/pokemon/mareep/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Mareep[] = INCBIN_U32("graphics/pokemon/mareep/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Mareep[] = INCBIN_U32("graphics/pokemon/mareep/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Mareep[] = INCBIN_U8("graphics/pokemon/mareep/icon.4bpp");
#else
    const u8 gMonIcon_Mareep[] = INCBIN_U8("graphics/pokemon/mareep/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Mareep[] = INCBIN_U8("graphics/pokemon/mareep/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Mareep[] = INCBIN_COMP("graphics/pokemon/mareep/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Mareep[] = INCBIN_U32("graphics/pokemon/mareep/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Mareep[] = INCBIN_U32("graphics/pokemon/mareep/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Flaaffy[] = INCBIN_U32("graphics/pokemon/flaaffy/anim_front.4bpp.lz");
    const u32 gMonPalette_Flaaffy[] = INCBIN_U32("graphics/pokemon/flaaffy/normal.gbapal.lz");
    const u32 gMonBackPic_Flaaffy[] = INCBIN_U32("graphics/pokemon/flaaffy/back.4bpp.lz");
    const u32 gMonShinyPalette_Flaaffy[] = INCBIN_U32("graphics/pokemon/flaaffy/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Flaaffy[] = INCBIN_U32("graphics/pokemon/flaaffy/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Flaaffy[] = INCBIN_U32("graphics/pokemon/flaaffy/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Flaaffy[] = INCBIN_U32("graphics/pokemon/flaaffy/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Flaaffy[] = INCBIN_U32("graphics/pokemon/flaaffy/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Flaaffy[] = INCBIN_U8("graphics/pokemon/flaaffy/icon.4bpp");
#else
    const u8 gMonIcon_Flaaffy[] = INCBIN_U8("graphics/pokemon/flaaffy/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Flaaffy[] = INCBIN_U8("graphics/pokemon/flaaffy/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Flaaffy[] = INCBIN_COMP("graphics/pokemon/flaaffy/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Flaaffy[] = INCBIN_U32("graphics/pokemon/flaaffy/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Flaaffy[] = INCBIN_U32("graphics/pokemon/flaaffy/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Ampharos[] = INCBIN_U32("graphics/pokemon/ampharos/anim_front.4bpp.lz");
    const u32 gMonPalette_Ampharos[] = INCBIN_U32("graphics/pokemon/ampharos/normal.gbapal.lz");
    const u32 gMonBackPic_Ampharos[] = INCBIN_U32("graphics/pokemon/ampharos/back.4bpp.lz");
    const u32 gMonShinyPalette_Ampharos[] = INCBIN_U32("graphics/pokemon/ampharos/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Ampharos[] = INCBIN_U32("graphics/pokemon/ampharos/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Ampharos[] = INCBIN_U32("graphics/pokemon/ampharos/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Ampharos[] = INCBIN_U32("graphics/pokemon/ampharos/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Ampharos[] = INCBIN_U32("graphics/pokemon/ampharos/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Ampharos[] = INCBIN_U8("graphics/pokemon/ampharos/icon.4bpp");
#else
    const u8 gMonIcon_Ampharos[] = INCBIN_U8("graphics/pokemon/ampharos/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Ampharos[] = INCBIN_U8("graphics/pokemon/ampharos/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Ampharos[] = INCBIN_COMP("graphics/pokemon/ampharos/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Ampharos[] = INCBIN_U32("graphics/pokemon/ampharos/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Ampharos[] = INCBIN_U32("graphics/pokemon/ampharos/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_MAREEP

#if P_FAMILY_MARILL
#if P_GEN_3_CROSS_EVOS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Azurill[] = INCBIN_U32("graphics/pokemon/azurill/anim_front.4bpp.lz");
    const u32 gMonPalette_Azurill[] = INCBIN_U32("graphics/pokemon/azurill/normal.gbapal.lz");
    const u32 gMonBackPic_Azurill[] = INCBIN_U32("graphics/pokemon/azurill/back.4bpp.lz");
    const u32 gMonShinyPalette_Azurill[] = INCBIN_U32("graphics/pokemon/azurill/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Azurill[] = INCBIN_U32("graphics/pokemon/azurill/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Azurill[] = INCBIN_U32("graphics/pokemon/azurill/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Azurill[] = INCBIN_U32("graphics/pokemon/azurill/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Azurill[] = INCBIN_U32("graphics/pokemon/azurill/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Azurill[] = INCBIN_U8("graphics/pokemon/azurill/icon.4bpp");
#else
    const u8 gMonIcon_Azurill[] = INCBIN_U8("graphics/pokemon/azurill/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Azurill[] = INCBIN_U8("graphics/pokemon/azurill/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Azurill[] = INCBIN_COMP("graphics/pokemon/azurill/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Azurill[] = INCBIN_U32("graphics/pokemon/azurill/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Azurill[] = INCBIN_U32("graphics/pokemon/azurill/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_3_CROSS_EVOS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Marill[] = INCBIN_U32("graphics/pokemon/marill/anim_front.4bpp.lz");
    const u32 gMonPalette_Marill[] = INCBIN_U32("graphics/pokemon/marill/normal.gbapal.lz");
    const u32 gMonBackPic_Marill[] = INCBIN_U32("graphics/pokemon/marill/back.4bpp.lz");
    const u32 gMonShinyPalette_Marill[] = INCBIN_U32("graphics/pokemon/marill/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Marill[] = INCBIN_U32("graphics/pokemon/marill/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Marill[] = INCBIN_U32("graphics/pokemon/marill/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Marill[] = INCBIN_U32("graphics/pokemon/marill/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Marill[] = INCBIN_U32("graphics/pokemon/marill/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Marill[] = INCBIN_U8("graphics/pokemon/marill/icon.4bpp");
#else
    const u8 gMonIcon_Marill[] = INCBIN_U8("graphics/pokemon/marill/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Marill[] = INCBIN_U8("graphics/pokemon/marill/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Marill[] = INCBIN_COMP("graphics/pokemon/marill/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Marill[] = INCBIN_U32("graphics/pokemon/marill/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Marill[] = INCBIN_U32("graphics/pokemon/marill/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Azumarill[] = INCBIN_U32("graphics/pokemon/azumarill/anim_front.4bpp.lz");
    const u32 gMonPalette_Azumarill[] = INCBIN_U32("graphics/pokemon/azumarill/normal.gbapal.lz");
    const u32 gMonBackPic_Azumarill[] = INCBIN_U32("graphics/pokemon/azumarill/back.4bpp.lz");
    const u32 gMonShinyPalette_Azumarill[] = INCBIN_U32("graphics/pokemon/azumarill/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Azumarill[] = INCBIN_U32("graphics/pokemon/azumarill/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Azumarill[] = INCBIN_U32("graphics/pokemon/azumarill/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Azumarill[] = INCBIN_U32("graphics/pokemon/azumarill/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Azumarill[] = INCBIN_U32("graphics/pokemon/azumarill/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Azumarill[] = INCBIN_U8("graphics/pokemon/azumarill/icon.4bpp");
#else
    const u8 gMonIcon_Azumarill[] = INCBIN_U8("graphics/pokemon/azumarill/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Azumarill[] = INCBIN_U8("graphics/pokemon/azumarill/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Azumarill[] = INCBIN_COMP("graphics/pokemon/azumarill/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Azumarill[] = INCBIN_U32("graphics/pokemon/azumarill/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Azumarill[] = INCBIN_U32("graphics/pokemon/azumarill/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_MARILL

#if P_FAMILY_SUDOWOODO
#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Bonsly[] = INCBIN_U32("graphics/pokemon/bonsly/anim_front.4bpp.lz");
    const u32 gMonPalette_Bonsly[] = INCBIN_U32("graphics/pokemon/bonsly/normal.gbapal.lz");
    const u32 gMonBackPic_Bonsly[] = INCBIN_U32("graphics/pokemon/bonsly/back.4bpp.lz");
    const u32 gMonShinyPalette_Bonsly[] = INCBIN_U32("graphics/pokemon/bonsly/shiny.gbapal.lz");
    const u8 gMonIcon_Bonsly[] = INCBIN_U8("graphics/pokemon/bonsly/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Bonsly[] = INCBIN_U8("graphics/pokemon/bonsly/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Bonsly[] = INCBIN_COMP("graphics/pokemon/bonsly/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Bonsly[] = INCBIN_U32("graphics/pokemon/bonsly/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Bonsly[] = INCBIN_U32("graphics/pokemon/bonsly/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_4_CROSS_EVOS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Sudowoodo[] = INCBIN_U32("graphics/pokemon/sudowoodo/anim_front.4bpp.lz");
    const u32 gMonPalette_Sudowoodo[] = INCBIN_U32("graphics/pokemon/sudowoodo/normal.gbapal.lz");
    const u32 gMonBackPic_Sudowoodo[] = INCBIN_U32("graphics/pokemon/sudowoodo/back.4bpp.lz");
    const u32 gMonShinyPalette_Sudowoodo[] = INCBIN_U32("graphics/pokemon/sudowoodo/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Sudowoodo[] = INCBIN_U32("graphics/pokemon/sudowoodo/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Sudowoodo[] = INCBIN_U32("graphics/pokemon/sudowoodo/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Sudowoodo[] = INCBIN_U32("graphics/pokemon/sudowoodo/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Sudowoodo[] = INCBIN_U32("graphics/pokemon/sudowoodo/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Sudowoodo[] = INCBIN_U8("graphics/pokemon/sudowoodo/icon.4bpp");
#else
    const u8 gMonIcon_Sudowoodo[] = INCBIN_U8("graphics/pokemon/sudowoodo/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Sudowoodo[] = INCBIN_U8("graphics/pokemon/sudowoodo/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Sudowoodo[] = INCBIN_COMP("graphics/pokemon/sudowoodo/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Sudowoodo[] = INCBIN_U32("graphics/pokemon/sudowoodo/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Sudowoodo[] = INCBIN_U32("graphics/pokemon/sudowoodo/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_SudowoodoF[] = INCBIN_U32("graphics/pokemon/sudowoodo/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_SudowoodoF[] = INCBIN_U32("graphics/pokemon/sudowoodo/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_SudowoodoF[] = INCBIN_COMP("graphics/pokemon/sudowoodo/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_SUDOWOODO

#if P_FAMILY_HOPPIP
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Hoppip[] = INCBIN_U32("graphics/pokemon/hoppip/anim_front.4bpp.lz");
    const u32 gMonPalette_Hoppip[] = INCBIN_U32("graphics/pokemon/hoppip/normal.gbapal.lz");
    const u32 gMonBackPic_Hoppip[] = INCBIN_U32("graphics/pokemon/hoppip/back.4bpp.lz");
    const u32 gMonShinyPalette_Hoppip[] = INCBIN_U32("graphics/pokemon/hoppip/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Hoppip[] = INCBIN_U32("graphics/pokemon/hoppip/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Hoppip[] = INCBIN_U32("graphics/pokemon/hoppip/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Hoppip[] = INCBIN_U32("graphics/pokemon/hoppip/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Hoppip[] = INCBIN_U32("graphics/pokemon/hoppip/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Hoppip[] = INCBIN_U8("graphics/pokemon/hoppip/icon.4bpp");
#else
    const u8 gMonIcon_Hoppip[] = INCBIN_U8("graphics/pokemon/hoppip/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Hoppip[] = INCBIN_U8("graphics/pokemon/hoppip/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Hoppip[] = INCBIN_COMP("graphics/pokemon/hoppip/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Hoppip[] = INCBIN_U32("graphics/pokemon/hoppip/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Hoppip[] = INCBIN_U32("graphics/pokemon/hoppip/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Skiploom[] = INCBIN_U32("graphics/pokemon/skiploom/anim_front.4bpp.lz");
    const u32 gMonPalette_Skiploom[] = INCBIN_U32("graphics/pokemon/skiploom/normal.gbapal.lz");
    const u32 gMonBackPic_Skiploom[] = INCBIN_U32("graphics/pokemon/skiploom/back.4bpp.lz");
    const u32 gMonShinyPalette_Skiploom[] = INCBIN_U32("graphics/pokemon/skiploom/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Skiploom[] = INCBIN_U32("graphics/pokemon/skiploom/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Skiploom[] = INCBIN_U32("graphics/pokemon/skiploom/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Skiploom[] = INCBIN_U32("graphics/pokemon/skiploom/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Skiploom[] = INCBIN_U32("graphics/pokemon/skiploom/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Skiploom[] = INCBIN_U8("graphics/pokemon/skiploom/icon.4bpp");
#else
    const u8 gMonIcon_Skiploom[] = INCBIN_U8("graphics/pokemon/skiploom/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Skiploom[] = INCBIN_U8("graphics/pokemon/skiploom/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Skiploom[] = INCBIN_COMP("graphics/pokemon/skiploom/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Skiploom[] = INCBIN_U32("graphics/pokemon/skiploom/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Skiploom[] = INCBIN_U32("graphics/pokemon/skiploom/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Jumpluff[] = INCBIN_U32("graphics/pokemon/jumpluff/anim_front.4bpp.lz");
    const u32 gMonPalette_Jumpluff[] = INCBIN_U32("graphics/pokemon/jumpluff/normal.gbapal.lz");
    const u32 gMonBackPic_Jumpluff[] = INCBIN_U32("graphics/pokemon/jumpluff/back.4bpp.lz");
    const u32 gMonShinyPalette_Jumpluff[] = INCBIN_U32("graphics/pokemon/jumpluff/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Jumpluff[] = INCBIN_U32("graphics/pokemon/jumpluff/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Jumpluff[] = INCBIN_U32("graphics/pokemon/jumpluff/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Jumpluff[] = INCBIN_U32("graphics/pokemon/jumpluff/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Jumpluff[] = INCBIN_U32("graphics/pokemon/jumpluff/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Jumpluff[] = INCBIN_U8("graphics/pokemon/jumpluff/icon.4bpp");
#else
    const u8 gMonIcon_Jumpluff[] = INCBIN_U8("graphics/pokemon/jumpluff/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Jumpluff[] = INCBIN_U8("graphics/pokemon/jumpluff/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Jumpluff[] = INCBIN_COMP("graphics/pokemon/jumpluff/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Jumpluff[] = INCBIN_U32("graphics/pokemon/jumpluff/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Jumpluff[] = INCBIN_U32("graphics/pokemon/jumpluff/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_HOPPIP

#if P_FAMILY_AIPOM
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Aipom[] = INCBIN_U32("graphics/pokemon/aipom/anim_front.4bpp.lz");
    const u32 gMonPalette_Aipom[] = INCBIN_U32("graphics/pokemon/aipom/normal.gbapal.lz");
    const u32 gMonBackPic_Aipom[] = INCBIN_U32("graphics/pokemon/aipom/back.4bpp.lz");
    const u32 gMonShinyPalette_Aipom[] = INCBIN_U32("graphics/pokemon/aipom/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Aipom[] = INCBIN_U32("graphics/pokemon/aipom/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Aipom[] = INCBIN_U32("graphics/pokemon/aipom/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Aipom[] = INCBIN_U32("graphics/pokemon/aipom/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Aipom[] = INCBIN_U32("graphics/pokemon/aipom/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Aipom[] = INCBIN_U8("graphics/pokemon/aipom/icon.4bpp");
#else
    const u8 gMonIcon_Aipom[] = INCBIN_U8("graphics/pokemon/aipom/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Aipom[] = INCBIN_U8("graphics/pokemon/aipom/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Aipom[] = INCBIN_COMP("graphics/pokemon/aipom/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Aipom[] = INCBIN_U32("graphics/pokemon/aipom/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Aipom[] = INCBIN_U32("graphics/pokemon/aipom/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_AipomF[] = INCBIN_U32("graphics/pokemon/aipom/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_AipomF[] = INCBIN_U32("graphics/pokemon/aipom/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_AipomF[] = INCBIN_COMP("graphics/pokemon/aipom/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Ambipom[] = INCBIN_U32("graphics/pokemon/ambipom/anim_front.4bpp.lz");
    const u32 gMonPalette_Ambipom[] = INCBIN_U32("graphics/pokemon/ambipom/normal.gbapal.lz");
    const u32 gMonBackPic_Ambipom[] = INCBIN_U32("graphics/pokemon/ambipom/back.4bpp.lz");
    const u32 gMonShinyPalette_Ambipom[] = INCBIN_U32("graphics/pokemon/ambipom/shiny.gbapal.lz");
    const u8 gMonIcon_Ambipom[] = INCBIN_U8("graphics/pokemon/ambipom/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Ambipom[] = INCBIN_U8("graphics/pokemon/ambipom/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Ambipom[] = INCBIN_COMP("graphics/pokemon/ambipom/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Ambipom[] = INCBIN_U32("graphics/pokemon/ambipom/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Ambipom[] = INCBIN_U32("graphics/pokemon/ambipom/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_AmbipomF[] = INCBIN_U32("graphics/pokemon/ambipom/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_AmbipomF[] = INCBIN_U32("graphics/pokemon/ambipom/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_AmbipomF[] = INCBIN_COMP("graphics/pokemon/ambipom/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_AIPOM

#if P_FAMILY_SUNKERN
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Sunkern[] = INCBIN_U32("graphics/pokemon/sunkern/anim_front.4bpp.lz");
    const u32 gMonPalette_Sunkern[] = INCBIN_U32("graphics/pokemon/sunkern/normal.gbapal.lz");
    const u32 gMonBackPic_Sunkern[] = INCBIN_U32("graphics/pokemon/sunkern/back.4bpp.lz");
    const u32 gMonShinyPalette_Sunkern[] = INCBIN_U32("graphics/pokemon/sunkern/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Sunkern[] = INCBIN_U32("graphics/pokemon/sunkern/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Sunkern[] = INCBIN_U32("graphics/pokemon/sunkern/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Sunkern[] = INCBIN_U32("graphics/pokemon/sunkern/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Sunkern[] = INCBIN_U32("graphics/pokemon/sunkern/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Sunkern[] = INCBIN_U8("graphics/pokemon/sunkern/icon.4bpp");
#else
    const u8 gMonIcon_Sunkern[] = INCBIN_U8("graphics/pokemon/sunkern/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Sunkern[] = INCBIN_U8("graphics/pokemon/sunkern/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Sunkern[] = INCBIN_COMP("graphics/pokemon/sunkern/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Sunkern[] = INCBIN_U32("graphics/pokemon/sunkern/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Sunkern[] = INCBIN_U32("graphics/pokemon/sunkern/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Sunflora[] = INCBIN_U32("graphics/pokemon/sunflora/anim_front.4bpp.lz");
    const u32 gMonPalette_Sunflora[] = INCBIN_U32("graphics/pokemon/sunflora/normal.gbapal.lz");
    const u32 gMonBackPic_Sunflora[] = INCBIN_U32("graphics/pokemon/sunflora/back.4bpp.lz");
    const u32 gMonShinyPalette_Sunflora[] = INCBIN_U32("graphics/pokemon/sunflora/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Sunflora[] = INCBIN_U32("graphics/pokemon/sunflora/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Sunflora[] = INCBIN_U32("graphics/pokemon/sunflora/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Sunflora[] = INCBIN_U32("graphics/pokemon/sunflora/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Sunflora[] = INCBIN_U32("graphics/pokemon/sunflora/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Sunflora[] = INCBIN_U8("graphics/pokemon/sunflora/icon.4bpp");
#else
    const u8 gMonIcon_Sunflora[] = INCBIN_U8("graphics/pokemon/sunflora/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Sunflora[] = INCBIN_U8("graphics/pokemon/sunflora/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Sunflora[] = INCBIN_COMP("graphics/pokemon/sunflora/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Sunflora[] = INCBIN_U32("graphics/pokemon/sunflora/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Sunflora[] = INCBIN_U32("graphics/pokemon/sunflora/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SUNKERN

#if P_FAMILY_YANMA
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Yanma[] = INCBIN_U32("graphics/pokemon/yanma/anim_front.4bpp.lz");
    const u32 gMonPalette_Yanma[] = INCBIN_U32("graphics/pokemon/yanma/normal.gbapal.lz");
    const u32 gMonBackPic_Yanma[] = INCBIN_U32("graphics/pokemon/yanma/back.4bpp.lz");
    const u32 gMonShinyPalette_Yanma[] = INCBIN_U32("graphics/pokemon/yanma/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Yanma[] = INCBIN_U32("graphics/pokemon/yanma/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Yanma[] = INCBIN_U32("graphics/pokemon/yanma/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Yanma[] = INCBIN_U32("graphics/pokemon/yanma/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Yanma[] = INCBIN_U32("graphics/pokemon/yanma/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Yanma[] = INCBIN_U8("graphics/pokemon/yanma/icon.4bpp");
#else
    const u8 gMonIcon_Yanma[] = INCBIN_U8("graphics/pokemon/yanma/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Yanma[] = INCBIN_U8("graphics/pokemon/yanma/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Yanma[] = INCBIN_COMP("graphics/pokemon/yanma/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Yanma[] = INCBIN_U32("graphics/pokemon/yanma/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Yanma[] = INCBIN_U32("graphics/pokemon/yanma/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Yanmega[] = INCBIN_U32("graphics/pokemon/yanmega/anim_front.4bpp.lz");
    const u32 gMonPalette_Yanmega[] = INCBIN_U32("graphics/pokemon/yanmega/normal.gbapal.lz");
    const u32 gMonBackPic_Yanmega[] = INCBIN_U32("graphics/pokemon/yanmega/back.4bpp.lz");
    const u32 gMonShinyPalette_Yanmega[] = INCBIN_U32("graphics/pokemon/yanmega/shiny.gbapal.lz");
    const u8 gMonIcon_Yanmega[] = INCBIN_U8("graphics/pokemon/yanmega/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Yanmega[] = INCBIN_U8("graphics/pokemon/yanmega/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Yanmega[] = INCBIN_COMP("graphics/pokemon/yanmega/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Yanmega[] = INCBIN_U32("graphics/pokemon/yanmega/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Yanmega[] = INCBIN_U32("graphics/pokemon/yanmega/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_YANMA

#if P_FAMILY_WOOPER
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Wooper[] = INCBIN_U32("graphics/pokemon/wooper/anim_front.4bpp.lz");
    const u32 gMonPalette_Wooper[] = INCBIN_U32("graphics/pokemon/wooper/normal.gbapal.lz");
    const u32 gMonBackPic_Wooper[] = INCBIN_U32("graphics/pokemon/wooper/back.4bpp.lz");
    const u32 gMonShinyPalette_Wooper[] = INCBIN_U32("graphics/pokemon/wooper/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Wooper[] = INCBIN_U32("graphics/pokemon/wooper/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Wooper[] = INCBIN_U32("graphics/pokemon/wooper/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Wooper[] = INCBIN_U32("graphics/pokemon/wooper/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Wooper[] = INCBIN_U32("graphics/pokemon/wooper/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Wooper[] = INCBIN_U8("graphics/pokemon/wooper/icon.4bpp");
#else
    const u8 gMonIcon_Wooper[] = INCBIN_U8("graphics/pokemon/wooper/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Wooper[] = INCBIN_U8("graphics/pokemon/wooper/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Wooper[] = INCBIN_COMP("graphics/pokemon/wooper/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Wooper[] = INCBIN_U32("graphics/pokemon/wooper/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Wooper[] = INCBIN_U32("graphics/pokemon/wooper/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_WooperF[] = INCBIN_U32("graphics/pokemon/wooper/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_WooperF[] = INCBIN_U32("graphics/pokemon/wooper/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_WooperF[] = INCBIN_COMP("graphics/pokemon/wooper/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Quagsire[] = INCBIN_U32("graphics/pokemon/quagsire/anim_front.4bpp.lz");
    const u32 gMonPalette_Quagsire[] = INCBIN_U32("graphics/pokemon/quagsire/normal.gbapal.lz");
    const u32 gMonBackPic_Quagsire[] = INCBIN_U32("graphics/pokemon/quagsire/back.4bpp.lz");
    const u32 gMonShinyPalette_Quagsire[] = INCBIN_U32("graphics/pokemon/quagsire/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Quagsire[] = INCBIN_U32("graphics/pokemon/quagsire/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Quagsire[] = INCBIN_U32("graphics/pokemon/quagsire/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Quagsire[] = INCBIN_U32("graphics/pokemon/quagsire/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Quagsire[] = INCBIN_U32("graphics/pokemon/quagsire/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Quagsire[] = INCBIN_U8("graphics/pokemon/quagsire/icon.4bpp");
#else
    const u8 gMonIcon_Quagsire[] = INCBIN_U8("graphics/pokemon/quagsire/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Quagsire[] = INCBIN_U8("graphics/pokemon/quagsire/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Quagsire[] = INCBIN_COMP("graphics/pokemon/quagsire/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Quagsire[] = INCBIN_U32("graphics/pokemon/quagsire/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Quagsire[] = INCBIN_U32("graphics/pokemon/quagsire/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_QuagsireF[] = INCBIN_U32("graphics/pokemon/quagsire/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_QuagsireF[] = INCBIN_U32("graphics/pokemon/quagsire/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_QuagsireF[] = INCBIN_COMP("graphics/pokemon/quagsire/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_WOOPER

#if P_FAMILY_MURKROW
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Murkrow[] = INCBIN_U32("graphics/pokemon/murkrow/anim_front.4bpp.lz");
    const u32 gMonPalette_Murkrow[] = INCBIN_U32("graphics/pokemon/murkrow/normal.gbapal.lz");
    const u32 gMonBackPic_Murkrow[] = INCBIN_U32("graphics/pokemon/murkrow/back.4bpp.lz");
    const u32 gMonShinyPalette_Murkrow[] = INCBIN_U32("graphics/pokemon/murkrow/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Murkrow[] = INCBIN_U32("graphics/pokemon/murkrow/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Murkrow[] = INCBIN_U32("graphics/pokemon/murkrow/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Murkrow[] = INCBIN_U32("graphics/pokemon/murkrow/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Murkrow[] = INCBIN_U32("graphics/pokemon/murkrow/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Murkrow[] = INCBIN_U8("graphics/pokemon/murkrow/icon.4bpp");
#else
    const u8 gMonIcon_Murkrow[] = INCBIN_U8("graphics/pokemon/murkrow/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Murkrow[] = INCBIN_U8("graphics/pokemon/murkrow/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Murkrow[] = INCBIN_COMP("graphics/pokemon/murkrow/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Murkrow[] = INCBIN_U32("graphics/pokemon/murkrow/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Murkrow[] = INCBIN_U32("graphics/pokemon/murkrow/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_MurkrowF[] = INCBIN_U32("graphics/pokemon/murkrow/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_MurkrowF[] = INCBIN_U32("graphics/pokemon/murkrow/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_MurkrowF[] = INCBIN_COMP("graphics/pokemon/murkrow/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Honchkrow[] = INCBIN_U32("graphics/pokemon/honchkrow/anim_front.4bpp.lz");
    const u32 gMonPalette_Honchkrow[] = INCBIN_U32("graphics/pokemon/honchkrow/normal.gbapal.lz");
    const u32 gMonBackPic_Honchkrow[] = INCBIN_U32("graphics/pokemon/honchkrow/back.4bpp.lz");
    const u32 gMonShinyPalette_Honchkrow[] = INCBIN_U32("graphics/pokemon/honchkrow/shiny.gbapal.lz");
    const u8 gMonIcon_Honchkrow[] = INCBIN_U8("graphics/pokemon/honchkrow/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Honchkrow[] = INCBIN_U8("graphics/pokemon/honchkrow/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Honchkrow[] = INCBIN_COMP("graphics/pokemon/honchkrow/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Honchkrow[] = INCBIN_U32("graphics/pokemon/honchkrow/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Honchkrow[] = INCBIN_U32("graphics/pokemon/honchkrow/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_MURKROW

#if P_FAMILY_MISDREAVUS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Misdreavus[] = INCBIN_U32("graphics/pokemon/misdreavus/anim_front.4bpp.lz");
    const u32 gMonPalette_Misdreavus[] = INCBIN_U32("graphics/pokemon/misdreavus/normal.gbapal.lz");
    const u32 gMonBackPic_Misdreavus[] = INCBIN_U32("graphics/pokemon/misdreavus/back.4bpp.lz");
    const u32 gMonShinyPalette_Misdreavus[] = INCBIN_U32("graphics/pokemon/misdreavus/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Misdreavus[] = INCBIN_U32("graphics/pokemon/misdreavus/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Misdreavus[] = INCBIN_U32("graphics/pokemon/misdreavus/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Misdreavus[] = INCBIN_U32("graphics/pokemon/misdreavus/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Misdreavus[] = INCBIN_U32("graphics/pokemon/misdreavus/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Misdreavus[] = INCBIN_U8("graphics/pokemon/misdreavus/icon.4bpp");
#else
    const u8 gMonIcon_Misdreavus[] = INCBIN_U8("graphics/pokemon/misdreavus/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Misdreavus[] = INCBIN_U8("graphics/pokemon/misdreavus/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Misdreavus[] = INCBIN_COMP("graphics/pokemon/misdreavus/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Misdreavus[] = INCBIN_U32("graphics/pokemon/misdreavus/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Misdreavus[] = INCBIN_U32("graphics/pokemon/misdreavus/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Mismagius[] = INCBIN_U32("graphics/pokemon/mismagius/anim_front.4bpp.lz");
    const u32 gMonPalette_Mismagius[] = INCBIN_U32("graphics/pokemon/mismagius/normal.gbapal.lz");
    const u32 gMonBackPic_Mismagius[] = INCBIN_U32("graphics/pokemon/mismagius/back.4bpp.lz");
    const u32 gMonShinyPalette_Mismagius[] = INCBIN_U32("graphics/pokemon/mismagius/shiny.gbapal.lz");
    const u8 gMonIcon_Mismagius[] = INCBIN_U8("graphics/pokemon/mismagius/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Mismagius[] = INCBIN_U8("graphics/pokemon/mismagius/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Mismagius[] = INCBIN_COMP("graphics/pokemon/mismagius/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Mismagius[] = INCBIN_U32("graphics/pokemon/mismagius/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Mismagius[] = INCBIN_U32("graphics/pokemon/mismagius/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_MISDREAVUS

#if P_FAMILY_UNOWN
    const u32 gMonPalette_Unown[] = INCBIN_U32("graphics/pokemon/unown/normal.gbapal.lz");
    const u32 gMonShinyPalette_Unown[] = INCBIN_U32("graphics/pokemon/unown/shiny.gbapal.lz");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Unown[] = INCBIN_U8("graphics/pokemon/unown/footprint.1bpp");
#endif //P_FOOTPRINTS

    const u32 gMonFrontPic_UnownA[] = INCBIN_U32("graphics/pokemon/unown/front.4bpp.lz");
    const u32 gMonBackPic_UnownA[] = INCBIN_U32("graphics/pokemon/unown/back.4bpp.lz");
    const u8 gMonIcon_UnownA[] = INCBIN_U8("graphics/pokemon/unown/icon.4bpp");

    const u32 gMonFrontPic_UnownB[] = INCBIN_U32("graphics/pokemon/unown/b/front.4bpp.lz");
    const u32 gMonBackPic_UnownB[] = INCBIN_U32("graphics/pokemon/unown/b/back.4bpp.lz");
    const u8 gMonIcon_UnownB[] = INCBIN_U8("graphics/pokemon/unown/b/icon.4bpp");

    const u32 gMonFrontPic_UnownC[] = INCBIN_U32("graphics/pokemon/unown/c/front.4bpp.lz");
    const u32 gMonBackPic_UnownC[] = INCBIN_U32("graphics/pokemon/unown/c/back.4bpp.lz");
    const u8 gMonIcon_UnownC[] = INCBIN_U8("graphics/pokemon/unown/c/icon.4bpp");

    const u32 gMonFrontPic_UnownD[] = INCBIN_U32("graphics/pokemon/unown/d/front.4bpp.lz");
    const u32 gMonBackPic_UnownD[] = INCBIN_U32("graphics/pokemon/unown/d/back.4bpp.lz");
    const u8 gMonIcon_UnownD[] = INCBIN_U8("graphics/pokemon/unown/d/icon.4bpp");

    const u32 gMonFrontPic_UnownE[] = INCBIN_U32("graphics/pokemon/unown/e/front.4bpp.lz");
    const u32 gMonBackPic_UnownE[] = INCBIN_U32("graphics/pokemon/unown/e/back.4bpp.lz");
    const u8 gMonIcon_UnownE[] = INCBIN_U8("graphics/pokemon/unown/e/icon.4bpp");

    const u32 gMonFrontPic_UnownF[] = INCBIN_U32("graphics/pokemon/unown/f/front.4bpp.lz");
    const u32 gMonBackPic_UnownF[] = INCBIN_U32("graphics/pokemon/unown/f/back.4bpp.lz");
    const u8 gMonIcon_UnownF[] = INCBIN_U8("graphics/pokemon/unown/f/icon.4bpp");

    const u32 gMonFrontPic_UnownG[] = INCBIN_U32("graphics/pokemon/unown/g/front.4bpp.lz");
    const u32 gMonBackPic_UnownG[] = INCBIN_U32("graphics/pokemon/unown/g/back.4bpp.lz");
    const u8 gMonIcon_UnownG[] = INCBIN_U8("graphics/pokemon/unown/g/icon.4bpp");

    const u32 gMonFrontPic_UnownH[] = INCBIN_U32("graphics/pokemon/unown/h/front.4bpp.lz");
    const u32 gMonBackPic_UnownH[] = INCBIN_U32("graphics/pokemon/unown/h/back.4bpp.lz");
    const u8 gMonIcon_UnownH[] = INCBIN_U8("graphics/pokemon/unown/h/icon.4bpp");

    const u32 gMonFrontPic_UnownI[] = INCBIN_U32("graphics/pokemon/unown/i/front.4bpp.lz");
    const u32 gMonBackPic_UnownI[] = INCBIN_U32("graphics/pokemon/unown/i/back.4bpp.lz");
    const u8 gMonIcon_UnownI[] = INCBIN_U8("graphics/pokemon/unown/i/icon.4bpp");

    const u32 gMonFrontPic_UnownJ[] = INCBIN_U32("graphics/pokemon/unown/j/front.4bpp.lz");
    const u32 gMonBackPic_UnownJ[] = INCBIN_U32("graphics/pokemon/unown/j/back.4bpp.lz");
    const u8 gMonIcon_UnownJ[] = INCBIN_U8("graphics/pokemon/unown/j/icon.4bpp");

    const u32 gMonFrontPic_UnownK[] = INCBIN_U32("graphics/pokemon/unown/k/front.4bpp.lz");
    const u32 gMonBackPic_UnownK[] = INCBIN_U32("graphics/pokemon/unown/k/back.4bpp.lz");
    const u8 gMonIcon_UnownK[] = INCBIN_U8("graphics/pokemon/unown/k/icon.4bpp");

    const u32 gMonFrontPic_UnownL[] = INCBIN_U32("graphics/pokemon/unown/l/front.4bpp.lz");
    const u32 gMonBackPic_UnownL[] = INCBIN_U32("graphics/pokemon/unown/l/back.4bpp.lz");
    const u8 gMonIcon_UnownL[] = INCBIN_U8("graphics/pokemon/unown/l/icon.4bpp");

    const u32 gMonFrontPic_UnownM[] = INCBIN_U32("graphics/pokemon/unown/m/front.4bpp.lz");
    const u32 gMonBackPic_UnownM[] = INCBIN_U32("graphics/pokemon/unown/m/back.4bpp.lz");
    const u8 gMonIcon_UnownM[] = INCBIN_U8("graphics/pokemon/unown/m/icon.4bpp");

    const u32 gMonFrontPic_UnownN[] = INCBIN_U32("graphics/pokemon/unown/n/front.4bpp.lz");
    const u32 gMonBackPic_UnownN[] = INCBIN_U32("graphics/pokemon/unown/n/back.4bpp.lz");
    const u8 gMonIcon_UnownN[] = INCBIN_U8("graphics/pokemon/unown/n/icon.4bpp");

    const u32 gMonFrontPic_UnownO[] = INCBIN_U32("graphics/pokemon/unown/o/front.4bpp.lz");
    const u32 gMonBackPic_UnownO[] = INCBIN_U32("graphics/pokemon/unown/o/back.4bpp.lz");
    const u8 gMonIcon_UnownO[] = INCBIN_U8("graphics/pokemon/unown/o/icon.4bpp");

    const u32 gMonFrontPic_UnownP[] = INCBIN_U32("graphics/pokemon/unown/p/front.4bpp.lz");
    const u32 gMonBackPic_UnownP[] = INCBIN_U32("graphics/pokemon/unown/p/back.4bpp.lz");
    const u8 gMonIcon_UnownP[] = INCBIN_U8("graphics/pokemon/unown/p/icon.4bpp");

    const u32 gMonFrontPic_UnownQ[] = INCBIN_U32("graphics/pokemon/unown/q/front.4bpp.lz");
    const u32 gMonBackPic_UnownQ[] = INCBIN_U32("graphics/pokemon/unown/q/back.4bpp.lz");
    const u8 gMonIcon_UnownQ[] = INCBIN_U8("graphics/pokemon/unown/q/icon.4bpp");

    const u32 gMonFrontPic_UnownR[] = INCBIN_U32("graphics/pokemon/unown/r/front.4bpp.lz");
    const u32 gMonBackPic_UnownR[] = INCBIN_U32("graphics/pokemon/unown/r/back.4bpp.lz");
    const u8 gMonIcon_UnownR[] = INCBIN_U8("graphics/pokemon/unown/r/icon.4bpp");

    const u32 gMonFrontPic_UnownS[] = INCBIN_U32("graphics/pokemon/unown/s/front.4bpp.lz");
    const u32 gMonBackPic_UnownS[] = INCBIN_U32("graphics/pokemon/unown/s/back.4bpp.lz");
    const u8 gMonIcon_UnownS[] = INCBIN_U8("graphics/pokemon/unown/s/icon.4bpp");

    const u32 gMonFrontPic_UnownT[] = INCBIN_U32("graphics/pokemon/unown/t/front.4bpp.lz");
    const u32 gMonBackPic_UnownT[] = INCBIN_U32("graphics/pokemon/unown/t/back.4bpp.lz");
    const u8 gMonIcon_UnownT[] = INCBIN_U8("graphics/pokemon/unown/t/icon.4bpp");

    const u32 gMonFrontPic_UnownU[] = INCBIN_U32("graphics/pokemon/unown/u/front.4bpp.lz");
    const u32 gMonBackPic_UnownU[] = INCBIN_U32("graphics/pokemon/unown/u/back.4bpp.lz");
    const u8 gMonIcon_UnownU[] = INCBIN_U8("graphics/pokemon/unown/u/icon.4bpp");

    const u32 gMonFrontPic_UnownV[] = INCBIN_U32("graphics/pokemon/unown/v/front.4bpp.lz");
    const u32 gMonBackPic_UnownV[] = INCBIN_U32("graphics/pokemon/unown/v/back.4bpp.lz");
    const u8 gMonIcon_UnownV[] = INCBIN_U8("graphics/pokemon/unown/v/icon.4bpp");

    const u32 gMonFrontPic_UnownW[] = INCBIN_U32("graphics/pokemon/unown/w/front.4bpp.lz");
    const u32 gMonBackPic_UnownW[] = INCBIN_U32("graphics/pokemon/unown/w/back.4bpp.lz");
    const u8 gMonIcon_UnownW[] = INCBIN_U8("graphics/pokemon/unown/w/icon.4bpp");

    const u32 gMonFrontPic_UnownX[] = INCBIN_U32("graphics/pokemon/unown/x/front.4bpp.lz");
    const u32 gMonBackPic_UnownX[] = INCBIN_U32("graphics/pokemon/unown/x/back.4bpp.lz");
    const u8 gMonIcon_UnownX[] = INCBIN_U8("graphics/pokemon/unown/x/icon.4bpp");

    const u32 gMonFrontPic_UnownY[] = INCBIN_U32("graphics/pokemon/unown/y/front.4bpp.lz");
    const u32 gMonBackPic_UnownY[] = INCBIN_U32("graphics/pokemon/unown/y/back.4bpp.lz");
    const u8 gMonIcon_UnownY[] = INCBIN_U8("graphics/pokemon/unown/y/icon.4bpp");

    const u32 gMonFrontPic_UnownZ[] = INCBIN_U32("graphics/pokemon/unown/z/front.4bpp.lz");
    const u32 gMonBackPic_UnownZ[] = INCBIN_U32("graphics/pokemon/unown/z/back.4bpp.lz");
    const u8 gMonIcon_UnownZ[] = INCBIN_U8("graphics/pokemon/unown/z/icon.4bpp");

    const u32 gMonFrontPic_UnownExclamation[] = INCBIN_U32("graphics/pokemon/unown/exclamation/front.4bpp.lz");
    const u32 gMonBackPic_UnownExclamation[] = INCBIN_U32("graphics/pokemon/unown/exclamation/back.4bpp.lz");
    const u8 gMonIcon_UnownExclamation[] = INCBIN_U8("graphics/pokemon/unown/exclamation/icon.4bpp");

    const u32 gMonFrontPic_UnownQuestion[] = INCBIN_U32("graphics/pokemon/unown/question/front.4bpp.lz");
    const u32 gMonBackPic_UnownQuestion[] = INCBIN_U32("graphics/pokemon/unown/question/back.4bpp.lz");
    const u8 gMonIcon_UnownQuestion[] = INCBIN_U8("graphics/pokemon/unown/question/icon.4bpp");

#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_UnownA[] = INCBIN_COMP("graphics/pokemon/unown/overworld.4bpp");
    const u32 gObjectEventPic_UnownB[] = INCBIN_COMP("graphics/pokemon/unown/b/overworld.4bpp");
    const u32 gObjectEventPic_UnownC[] = INCBIN_COMP("graphics/pokemon/unown/c/overworld.4bpp");
    const u32 gObjectEventPic_UnownD[] = INCBIN_COMP("graphics/pokemon/unown/d/overworld.4bpp");
    const u32 gObjectEventPic_UnownE[] = INCBIN_COMP("graphics/pokemon/unown/e/overworld.4bpp");
    const u32 gObjectEventPic_UnownF[] = INCBIN_COMP("graphics/pokemon/unown/f/overworld.4bpp");
    const u32 gObjectEventPic_UnownG[] = INCBIN_COMP("graphics/pokemon/unown/g/overworld.4bpp");
    const u32 gObjectEventPic_UnownH[] = INCBIN_COMP("graphics/pokemon/unown/h/overworld.4bpp");
    const u32 gObjectEventPic_UnownI[] = INCBIN_COMP("graphics/pokemon/unown/i/overworld.4bpp");
    const u32 gObjectEventPic_UnownJ[] = INCBIN_COMP("graphics/pokemon/unown/j/overworld.4bpp");
    const u32 gObjectEventPic_UnownK[] = INCBIN_COMP("graphics/pokemon/unown/k/overworld.4bpp");
    const u32 gObjectEventPic_UnownL[] = INCBIN_COMP("graphics/pokemon/unown/l/overworld.4bpp");
    const u32 gObjectEventPic_UnownM[] = INCBIN_COMP("graphics/pokemon/unown/m/overworld.4bpp");
    const u32 gObjectEventPic_UnownN[] = INCBIN_COMP("graphics/pokemon/unown/n/overworld.4bpp");
    const u32 gObjectEventPic_UnownO[] = INCBIN_COMP("graphics/pokemon/unown/o/overworld.4bpp");
    const u32 gObjectEventPic_UnownP[] = INCBIN_COMP("graphics/pokemon/unown/p/overworld.4bpp");
    const u32 gObjectEventPic_UnownQ[] = INCBIN_COMP("graphics/pokemon/unown/q/overworld.4bpp");
    const u32 gObjectEventPic_UnownR[] = INCBIN_COMP("graphics/pokemon/unown/r/overworld.4bpp");
    const u32 gObjectEventPic_UnownS[] = INCBIN_COMP("graphics/pokemon/unown/s/overworld.4bpp");
    const u32 gObjectEventPic_UnownT[] = INCBIN_COMP("graphics/pokemon/unown/t/overworld.4bpp");
    const u32 gObjectEventPic_UnownU[] = INCBIN_COMP("graphics/pokemon/unown/u/overworld.4bpp");
    const u32 gObjectEventPic_UnownV[] = INCBIN_COMP("graphics/pokemon/unown/v/overworld.4bpp");
    const u32 gObjectEventPic_UnownW[] = INCBIN_COMP("graphics/pokemon/unown/w/overworld.4bpp");
    const u32 gObjectEventPic_UnownX[] = INCBIN_COMP("graphics/pokemon/unown/x/overworld.4bpp");
    const u32 gObjectEventPic_UnownY[] = INCBIN_COMP("graphics/pokemon/unown/y/overworld.4bpp");
    const u32 gObjectEventPic_UnownZ[] = INCBIN_COMP("graphics/pokemon/unown/z/overworld.4bpp");
    const u32 gObjectEventPic_UnownExclamation[] = INCBIN_COMP("graphics/pokemon/unown/exclamation/overworld.4bpp");
    const u32 gObjectEventPic_UnownQuestion[] = INCBIN_COMP("graphics/pokemon/unown/question/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Unown[] = INCBIN_U32("graphics/pokemon/unown/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Unown[] = INCBIN_U32("graphics/pokemon/unown/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_UNOWN

#if P_FAMILY_WOBBUFFET
#if P_GEN_3_CROSS_EVOS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Wynaut[] = INCBIN_U32("graphics/pokemon/wynaut/anim_front.4bpp.lz");
    const u32 gMonPalette_Wynaut[] = INCBIN_U32("graphics/pokemon/wynaut/normal.gbapal.lz");
    const u32 gMonBackPic_Wynaut[] = INCBIN_U32("graphics/pokemon/wynaut/back.4bpp.lz");
    const u32 gMonShinyPalette_Wynaut[] = INCBIN_U32("graphics/pokemon/wynaut/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Wynaut[] = INCBIN_U32("graphics/pokemon/wynaut/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Wynaut[] = INCBIN_U32("graphics/pokemon/wynaut/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Wynaut[] = INCBIN_U32("graphics/pokemon/wynaut/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Wynaut[] = INCBIN_U32("graphics/pokemon/wynaut/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Wynaut[] = INCBIN_U8("graphics/pokemon/wynaut/icon.4bpp");
#else
    const u8 gMonIcon_Wynaut[] = INCBIN_U8("graphics/pokemon/wynaut/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Wynaut[] = INCBIN_U8("graphics/pokemon/wynaut/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Wynaut[] = INCBIN_COMP("graphics/pokemon/wynaut/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Wynaut[] = INCBIN_U32("graphics/pokemon/wynaut/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Wynaut[] = INCBIN_U32("graphics/pokemon/wynaut/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_3_CROSS_EVOS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Wobbuffet[] = INCBIN_U32("graphics/pokemon/wobbuffet/anim_front.4bpp.lz");
    const u32 gMonPalette_Wobbuffet[] = INCBIN_U32("graphics/pokemon/wobbuffet/normal.gbapal.lz");
    const u32 gMonBackPic_Wobbuffet[] = INCBIN_U32("graphics/pokemon/wobbuffet/back.4bpp.lz");
    const u32 gMonShinyPalette_Wobbuffet[] = INCBIN_U32("graphics/pokemon/wobbuffet/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Wobbuffet[] = INCBIN_U32("graphics/pokemon/wobbuffet/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Wobbuffet[] = INCBIN_U32("graphics/pokemon/wobbuffet/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Wobbuffet[] = INCBIN_U32("graphics/pokemon/wobbuffet/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Wobbuffet[] = INCBIN_U32("graphics/pokemon/wobbuffet/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Wobbuffet[] = INCBIN_U8("graphics/pokemon/wobbuffet/icon.4bpp");
#else
    const u8 gMonIcon_Wobbuffet[] = INCBIN_U8("graphics/pokemon/wobbuffet/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Wobbuffet[] = INCBIN_U8("graphics/pokemon/wobbuffet/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Wobbuffet[] = INCBIN_COMP("graphics/pokemon/wobbuffet/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Wobbuffet[] = INCBIN_U32("graphics/pokemon/wobbuffet/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Wobbuffet[] = INCBIN_U32("graphics/pokemon/wobbuffet/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_WobbuffetF[] = INCBIN_U32("graphics/pokemon/wobbuffet/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_WobbuffetF[] = INCBIN_U32("graphics/pokemon/wobbuffet/backf.4bpp.lz");
#if P_CUSTOM_GENDER_DIFF_ICONS
    const u8 gMonIcon_WobbuffetF[] = INCBIN_U8("graphics/pokemon/wobbuffet/iconf.4bpp");
#endif
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_WobbuffetF[] = INCBIN_COMP("graphics/pokemon/wobbuffet/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_WOBBUFFET

#if P_FAMILY_GIRAFARIG
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Girafarig[] = INCBIN_U32("graphics/pokemon/girafarig/anim_front.4bpp.lz");
    const u32 gMonPalette_Girafarig[] = INCBIN_U32("graphics/pokemon/girafarig/normal.gbapal.lz");
    const u32 gMonBackPic_Girafarig[] = INCBIN_U32("graphics/pokemon/girafarig/back.4bpp.lz");
    const u32 gMonShinyPalette_Girafarig[] = INCBIN_U32("graphics/pokemon/girafarig/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Girafarig[] = INCBIN_U32("graphics/pokemon/girafarig/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Girafarig[] = INCBIN_U32("graphics/pokemon/girafarig/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Girafarig[] = INCBIN_U32("graphics/pokemon/girafarig/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Girafarig[] = INCBIN_U32("graphics/pokemon/girafarig/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Girafarig[] = INCBIN_U8("graphics/pokemon/girafarig/icon.4bpp");
#else
    const u8 gMonIcon_Girafarig[] = INCBIN_U8("graphics/pokemon/girafarig/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Girafarig[] = INCBIN_U8("graphics/pokemon/girafarig/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Girafarig[] = INCBIN_COMP("graphics/pokemon/girafarig/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Girafarig[] = INCBIN_U32("graphics/pokemon/girafarig/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Girafarig[] = INCBIN_U32("graphics/pokemon/girafarig/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_GirafarigF[] = INCBIN_U32("graphics/pokemon/girafarig/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_GirafarigF[] = INCBIN_U32("graphics/pokemon/girafarig/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_GirafarigF[] = INCBIN_COMP("graphics/pokemon/girafarig/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_GIRAFARIG

#if P_FAMILY_PINECO
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Pineco[] = INCBIN_U32("graphics/pokemon/pineco/anim_front.4bpp.lz");
    const u32 gMonPalette_Pineco[] = INCBIN_U32("graphics/pokemon/pineco/normal.gbapal.lz");
    const u32 gMonBackPic_Pineco[] = INCBIN_U32("graphics/pokemon/pineco/back.4bpp.lz");
    const u32 gMonShinyPalette_Pineco[] = INCBIN_U32("graphics/pokemon/pineco/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Pineco[] = INCBIN_U32("graphics/pokemon/pineco/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Pineco[] = INCBIN_U32("graphics/pokemon/pineco/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Pineco[] = INCBIN_U32("graphics/pokemon/pineco/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Pineco[] = INCBIN_U32("graphics/pokemon/pineco/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Pineco[] = INCBIN_U8("graphics/pokemon/pineco/icon.4bpp");
#else
    const u8 gMonIcon_Pineco[] = INCBIN_U8("graphics/pokemon/pineco/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Pineco[] = INCBIN_U8("graphics/pokemon/pineco/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Pineco[] = INCBIN_COMP("graphics/pokemon/pineco/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Pineco[] = INCBIN_U32("graphics/pokemon/pineco/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Pineco[] = INCBIN_U32("graphics/pokemon/pineco/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Forretress[] = INCBIN_U32("graphics/pokemon/forretress/anim_front.4bpp.lz");
    const u32 gMonPalette_Forretress[] = INCBIN_U32("graphics/pokemon/forretress/normal.gbapal.lz");
    const u32 gMonBackPic_Forretress[] = INCBIN_U32("graphics/pokemon/forretress/back.4bpp.lz");
    const u32 gMonShinyPalette_Forretress[] = INCBIN_U32("graphics/pokemon/forretress/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Forretress[] = INCBIN_U32("graphics/pokemon/forretress/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Forretress[] = INCBIN_U32("graphics/pokemon/forretress/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Forretress[] = INCBIN_U32("graphics/pokemon/forretress/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Forretress[] = INCBIN_U32("graphics/pokemon/forretress/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Forretress[] = INCBIN_U8("graphics/pokemon/forretress/icon.4bpp");
#else
    const u8 gMonIcon_Forretress[] = INCBIN_U8("graphics/pokemon/forretress/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Forretress[] = INCBIN_U8("graphics/pokemon/forretress/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Forretress[] = INCBIN_COMP("graphics/pokemon/forretress/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Forretress[] = INCBIN_U32("graphics/pokemon/forretress/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Forretress[] = INCBIN_U32("graphics/pokemon/forretress/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_PINECO

#if P_FAMILY_DUNSPARCE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Dunsparce[] = INCBIN_U32("graphics/pokemon/dunsparce/anim_front.4bpp.lz");
    const u32 gMonPalette_Dunsparce[] = INCBIN_U32("graphics/pokemon/dunsparce/normal.gbapal.lz");
    const u32 gMonBackPic_Dunsparce[] = INCBIN_U32("graphics/pokemon/dunsparce/back.4bpp.lz");
    const u32 gMonShinyPalette_Dunsparce[] = INCBIN_U32("graphics/pokemon/dunsparce/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Dunsparce[] = INCBIN_U32("graphics/pokemon/dunsparce/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Dunsparce[] = INCBIN_U32("graphics/pokemon/dunsparce/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Dunsparce[] = INCBIN_U32("graphics/pokemon/dunsparce/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Dunsparce[] = INCBIN_U32("graphics/pokemon/dunsparce/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Dunsparce[] = INCBIN_U8("graphics/pokemon/dunsparce/icon.4bpp");
#else
    const u8 gMonIcon_Dunsparce[] = INCBIN_U8("graphics/pokemon/dunsparce/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Dunsparce[] = INCBIN_U8("graphics/pokemon/dunsparce/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Dunsparce[] = INCBIN_COMP("graphics/pokemon/dunsparce/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Dunsparce[] = INCBIN_U32("graphics/pokemon/dunsparce/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Dunsparce[] = INCBIN_U32("graphics/pokemon/dunsparce/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_DUNSPARCE

#if P_FAMILY_GLIGAR
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Gligar[] = INCBIN_U32("graphics/pokemon/gligar/anim_front.4bpp.lz");
    const u32 gMonPalette_Gligar[] = INCBIN_U32("graphics/pokemon/gligar/normal.gbapal.lz");
    const u32 gMonBackPic_Gligar[] = INCBIN_U32("graphics/pokemon/gligar/back.4bpp.lz");
    const u32 gMonShinyPalette_Gligar[] = INCBIN_U32("graphics/pokemon/gligar/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Gligar[] = INCBIN_U32("graphics/pokemon/gligar/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Gligar[] = INCBIN_U32("graphics/pokemon/gligar/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Gligar[] = INCBIN_U32("graphics/pokemon/gligar/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Gligar[] = INCBIN_U32("graphics/pokemon/gligar/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Gligar[] = INCBIN_U8("graphics/pokemon/gligar/icon.4bpp");
#else
    const u8 gMonIcon_Gligar[] = INCBIN_U8("graphics/pokemon/gligar/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Gligar[] = INCBIN_U8("graphics/pokemon/gligar/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Gligar[] = INCBIN_COMP("graphics/pokemon/gligar/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Gligar[] = INCBIN_U32("graphics/pokemon/gligar/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Gligar[] = INCBIN_U32("graphics/pokemon/gligar/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_GligarF[] = INCBIN_U32("graphics/pokemon/gligar/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_GligarF[] = INCBIN_U32("graphics/pokemon/gligar/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_GligarF[] = INCBIN_COMP("graphics/pokemon/gligar/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Gliscor[] = INCBIN_U32("graphics/pokemon/gliscor/anim_front.4bpp.lz");
    const u32 gMonPalette_Gliscor[] = INCBIN_U32("graphics/pokemon/gliscor/normal.gbapal.lz");
    const u32 gMonBackPic_Gliscor[] = INCBIN_U32("graphics/pokemon/gliscor/back.4bpp.lz");
    const u32 gMonShinyPalette_Gliscor[] = INCBIN_U32("graphics/pokemon/gliscor/shiny.gbapal.lz");
    const u8 gMonIcon_Gliscor[] = INCBIN_U8("graphics/pokemon/gliscor/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Gliscor[] = INCBIN_U8("graphics/pokemon/gliscor/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Gliscor[] = INCBIN_COMP("graphics/pokemon/gliscor/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Gliscor[] = INCBIN_U32("graphics/pokemon/gliscor/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Gliscor[] = INCBIN_U32("graphics/pokemon/gliscor/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_GLIGAR

#if P_FAMILY_SNUBBULL
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Snubbull[] = INCBIN_U32("graphics/pokemon/snubbull/anim_front.4bpp.lz");
    const u32 gMonPalette_Snubbull[] = INCBIN_U32("graphics/pokemon/snubbull/normal.gbapal.lz");
    const u32 gMonBackPic_Snubbull[] = INCBIN_U32("graphics/pokemon/snubbull/back.4bpp.lz");
    const u32 gMonShinyPalette_Snubbull[] = INCBIN_U32("graphics/pokemon/snubbull/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Snubbull[] = INCBIN_U32("graphics/pokemon/snubbull/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Snubbull[] = INCBIN_U32("graphics/pokemon/snubbull/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Snubbull[] = INCBIN_U32("graphics/pokemon/snubbull/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Snubbull[] = INCBIN_U32("graphics/pokemon/snubbull/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Snubbull[] = INCBIN_U8("graphics/pokemon/snubbull/icon.4bpp");
#else
    const u8 gMonIcon_Snubbull[] = INCBIN_U8("graphics/pokemon/snubbull/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Snubbull[] = INCBIN_U8("graphics/pokemon/snubbull/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Snubbull[] = INCBIN_COMP("graphics/pokemon/snubbull/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Snubbull[] = INCBIN_U32("graphics/pokemon/snubbull/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Snubbull[] = INCBIN_U32("graphics/pokemon/snubbull/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Granbull[] = INCBIN_U32("graphics/pokemon/granbull/anim_front.4bpp.lz");
    const u32 gMonPalette_Granbull[] = INCBIN_U32("graphics/pokemon/granbull/normal.gbapal.lz");
    const u32 gMonBackPic_Granbull[] = INCBIN_U32("graphics/pokemon/granbull/back.4bpp.lz");
    const u32 gMonShinyPalette_Granbull[] = INCBIN_U32("graphics/pokemon/granbull/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Granbull[] = INCBIN_U32("graphics/pokemon/granbull/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Granbull[] = INCBIN_U32("graphics/pokemon/granbull/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Granbull[] = INCBIN_U32("graphics/pokemon/granbull/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Granbull[] = INCBIN_U32("graphics/pokemon/granbull/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Granbull[] = INCBIN_U8("graphics/pokemon/granbull/icon.4bpp");
#else
    const u8 gMonIcon_Granbull[] = INCBIN_U8("graphics/pokemon/granbull/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Granbull[] = INCBIN_U8("graphics/pokemon/granbull/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Granbull[] = INCBIN_COMP("graphics/pokemon/granbull/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Granbull[] = INCBIN_U32("graphics/pokemon/granbull/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Granbull[] = INCBIN_U32("graphics/pokemon/granbull/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SNUBBULL

#if P_FAMILY_QWILFISH
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Qwilfish[] = INCBIN_U32("graphics/pokemon/qwilfish/anim_front.4bpp.lz");
    const u32 gMonPalette_Qwilfish[] = INCBIN_U32("graphics/pokemon/qwilfish/normal.gbapal.lz");
    const u32 gMonBackPic_Qwilfish[] = INCBIN_U32("graphics/pokemon/qwilfish/back.4bpp.lz");
    const u32 gMonShinyPalette_Qwilfish[] = INCBIN_U32("graphics/pokemon/qwilfish/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Qwilfish[] = INCBIN_U32("graphics/pokemon/qwilfish/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Qwilfish[] = INCBIN_U32("graphics/pokemon/qwilfish/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Qwilfish[] = INCBIN_U32("graphics/pokemon/qwilfish/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Qwilfish[] = INCBIN_U32("graphics/pokemon/qwilfish/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Qwilfish[] = INCBIN_U8("graphics/pokemon/qwilfish/icon.4bpp");
#else
    const u8 gMonIcon_Qwilfish[] = INCBIN_U8("graphics/pokemon/qwilfish/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Qwilfish[] = INCBIN_U8("graphics/pokemon/qwilfish/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Qwilfish[] = INCBIN_COMP("graphics/pokemon/qwilfish/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Qwilfish[] = INCBIN_U32("graphics/pokemon/qwilfish/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Qwilfish[] = INCBIN_U32("graphics/pokemon/qwilfish/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_QWILFISH

#if P_FAMILY_SHUCKLE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Shuckle[] = INCBIN_U32("graphics/pokemon/shuckle/anim_front.4bpp.lz");
    const u32 gMonPalette_Shuckle[] = INCBIN_U32("graphics/pokemon/shuckle/normal.gbapal.lz");
    const u32 gMonBackPic_Shuckle[] = INCBIN_U32("graphics/pokemon/shuckle/back.4bpp.lz");
    const u32 gMonShinyPalette_Shuckle[] = INCBIN_U32("graphics/pokemon/shuckle/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Shuckle[] = INCBIN_U32("graphics/pokemon/shuckle/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Shuckle[] = INCBIN_U32("graphics/pokemon/shuckle/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Shuckle[] = INCBIN_U32("graphics/pokemon/shuckle/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Shuckle[] = INCBIN_U32("graphics/pokemon/shuckle/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Shuckle[] = INCBIN_U8("graphics/pokemon/shuckle/icon.4bpp");
#else
    const u8 gMonIcon_Shuckle[] = INCBIN_U8("graphics/pokemon/shuckle/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Shuckle[] = INCBIN_U8("graphics/pokemon/shuckle/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Shuckle[] = INCBIN_COMP("graphics/pokemon/shuckle/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Shuckle[] = INCBIN_U32("graphics/pokemon/shuckle/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Shuckle[] = INCBIN_U32("graphics/pokemon/shuckle/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SHUCKLE

#if P_FAMILY_HERACROSS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Heracross[] = INCBIN_U32("graphics/pokemon/heracross/anim_front.4bpp.lz");
    const u32 gMonPalette_Heracross[] = INCBIN_U32("graphics/pokemon/heracross/normal.gbapal.lz");
    const u32 gMonBackPic_Heracross[] = INCBIN_U32("graphics/pokemon/heracross/back.4bpp.lz");
    const u32 gMonShinyPalette_Heracross[] = INCBIN_U32("graphics/pokemon/heracross/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Heracross[] = INCBIN_U32("graphics/pokemon/heracross/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Heracross[] = INCBIN_U32("graphics/pokemon/heracross/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Heracross[] = INCBIN_U32("graphics/pokemon/heracross/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Heracross[] = INCBIN_U32("graphics/pokemon/heracross/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Heracross[] = INCBIN_U8("graphics/pokemon/heracross/icon.4bpp");
#else
    const u8 gMonIcon_Heracross[] = INCBIN_U8("graphics/pokemon/heracross/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Heracross[] = INCBIN_U8("graphics/pokemon/heracross/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Heracross[] = INCBIN_COMP("graphics/pokemon/heracross/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Heracross[] = INCBIN_U32("graphics/pokemon/heracross/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Heracross[] = INCBIN_U32("graphics/pokemon/heracross/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_HeracrossF[] = INCBIN_U32("graphics/pokemon/heracross/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_HeracrossF[] = INCBIN_U32("graphics/pokemon/heracross/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_HeracrossF[] = INCBIN_COMP("graphics/pokemon/heracross/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_HERACROSS

#if P_FAMILY_SNEASEL
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Sneasel[] = INCBIN_U32("graphics/pokemon/sneasel/anim_front.4bpp.lz");
    const u32 gMonPalette_Sneasel[] = INCBIN_U32("graphics/pokemon/sneasel/normal.gbapal.lz");
    const u32 gMonBackPic_Sneasel[] = INCBIN_U32("graphics/pokemon/sneasel/back.4bpp.lz");
    const u32 gMonShinyPalette_Sneasel[] = INCBIN_U32("graphics/pokemon/sneasel/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Sneasel[] = INCBIN_U32("graphics/pokemon/sneasel/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Sneasel[] = INCBIN_U32("graphics/pokemon/sneasel/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Sneasel[] = INCBIN_U32("graphics/pokemon/sneasel/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Sneasel[] = INCBIN_U32("graphics/pokemon/sneasel/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Sneasel[] = INCBIN_U8("graphics/pokemon/sneasel/icon.4bpp");
#else
    const u8 gMonIcon_Sneasel[] = INCBIN_U8("graphics/pokemon/sneasel/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Sneasel[] = INCBIN_U8("graphics/pokemon/sneasel/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Sneasel[] = INCBIN_COMP("graphics/pokemon/sneasel/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Sneasel[] = INCBIN_U32("graphics/pokemon/sneasel/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Sneasel[] = INCBIN_U32("graphics/pokemon/sneasel/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_SneaselF[] = INCBIN_U32("graphics/pokemon/sneasel/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_SneaselF[] = INCBIN_U32("graphics/pokemon/sneasel/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_SneaselF[] = INCBIN_COMP("graphics/pokemon/sneasel/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Weavile[] = INCBIN_U32("graphics/pokemon/weavile/anim_front.4bpp.lz");
    const u32 gMonPalette_Weavile[] = INCBIN_U32("graphics/pokemon/weavile/normal.gbapal.lz");
    const u32 gMonBackPic_Weavile[] = INCBIN_U32("graphics/pokemon/weavile/back.4bpp.lz");
    const u32 gMonShinyPalette_Weavile[] = INCBIN_U32("graphics/pokemon/weavile/shiny.gbapal.lz");
    const u8 gMonIcon_Weavile[] = INCBIN_U8("graphics/pokemon/weavile/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Weavile[] = INCBIN_U8("graphics/pokemon/weavile/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Weavile[] = INCBIN_COMP("graphics/pokemon/weavile/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Weavile[] = INCBIN_U32("graphics/pokemon/weavile/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Weavile[] = INCBIN_U32("graphics/pokemon/weavile/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_WeavileF[] = INCBIN_U32("graphics/pokemon/weavile/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_WeavileF[] = INCBIN_U32("graphics/pokemon/weavile/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_WeavileF[] = INCBIN_COMP("graphics/pokemon/weavile/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_SNEASEL

#if P_FAMILY_TEDDIURSA
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Teddiursa[] = INCBIN_U32("graphics/pokemon/teddiursa/anim_front.4bpp.lz");
    const u32 gMonPalette_Teddiursa[] = INCBIN_U32("graphics/pokemon/teddiursa/normal.gbapal.lz");
    const u32 gMonBackPic_Teddiursa[] = INCBIN_U32("graphics/pokemon/teddiursa/back.4bpp.lz");
    const u32 gMonShinyPalette_Teddiursa[] = INCBIN_U32("graphics/pokemon/teddiursa/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Teddiursa[] = INCBIN_U32("graphics/pokemon/teddiursa/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Teddiursa[] = INCBIN_U32("graphics/pokemon/teddiursa/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Teddiursa[] = INCBIN_U32("graphics/pokemon/teddiursa/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Teddiursa[] = INCBIN_U32("graphics/pokemon/teddiursa/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Teddiursa[] = INCBIN_U8("graphics/pokemon/teddiursa/icon.4bpp");
#else
    const u8 gMonIcon_Teddiursa[] = INCBIN_U8("graphics/pokemon/teddiursa/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Teddiursa[] = INCBIN_U8("graphics/pokemon/teddiursa/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Teddiursa[] = INCBIN_COMP("graphics/pokemon/teddiursa/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Teddiursa[] = INCBIN_U32("graphics/pokemon/teddiursa/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Teddiursa[] = INCBIN_U32("graphics/pokemon/teddiursa/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Ursaring[] = INCBIN_U32("graphics/pokemon/ursaring/anim_front.4bpp.lz");
    const u32 gMonPalette_Ursaring[] = INCBIN_U32("graphics/pokemon/ursaring/normal.gbapal.lz");
    const u32 gMonBackPic_Ursaring[] = INCBIN_U32("graphics/pokemon/ursaring/back.4bpp.lz");
    const u32 gMonShinyPalette_Ursaring[] = INCBIN_U32("graphics/pokemon/ursaring/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Ursaring[] = INCBIN_U32("graphics/pokemon/ursaring/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Ursaring[] = INCBIN_U32("graphics/pokemon/ursaring/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Ursaring[] = INCBIN_U32("graphics/pokemon/ursaring/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Ursaring[] = INCBIN_U32("graphics/pokemon/ursaring/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Ursaring[] = INCBIN_U8("graphics/pokemon/ursaring/icon.4bpp");
#else
    const u8 gMonIcon_Ursaring[] = INCBIN_U8("graphics/pokemon/ursaring/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Ursaring[] = INCBIN_U8("graphics/pokemon/ursaring/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Ursaring[] = INCBIN_COMP("graphics/pokemon/ursaring/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Ursaring[] = INCBIN_U32("graphics/pokemon/ursaring/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Ursaring[] = INCBIN_U32("graphics/pokemon/ursaring/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_UrsaringF[] = INCBIN_U32("graphics/pokemon/ursaring/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_UrsaringF[] = INCBIN_U32("graphics/pokemon/ursaring/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_UrsaringF[] = INCBIN_COMP("graphics/pokemon/ursaring/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_TEDDIURSA

#if P_FAMILY_SLUGMA
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Slugma[] = INCBIN_U32("graphics/pokemon/slugma/anim_front.4bpp.lz");
    const u32 gMonPalette_Slugma[] = INCBIN_U32("graphics/pokemon/slugma/normal.gbapal.lz");
    const u32 gMonBackPic_Slugma[] = INCBIN_U32("graphics/pokemon/slugma/back.4bpp.lz");
    const u32 gMonShinyPalette_Slugma[] = INCBIN_U32("graphics/pokemon/slugma/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Slugma[] = INCBIN_U32("graphics/pokemon/slugma/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Slugma[] = INCBIN_U32("graphics/pokemon/slugma/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Slugma[] = INCBIN_U32("graphics/pokemon/slugma/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Slugma[] = INCBIN_U32("graphics/pokemon/slugma/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Slugma[] = INCBIN_U8("graphics/pokemon/slugma/icon.4bpp");
#else
    const u8 gMonIcon_Slugma[] = INCBIN_U8("graphics/pokemon/slugma/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Slugma[] = INCBIN_U8("graphics/pokemon/slugma/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Slugma[] = INCBIN_COMP("graphics/pokemon/slugma/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Slugma[] = INCBIN_U32("graphics/pokemon/slugma/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Slugma[] = INCBIN_U32("graphics/pokemon/slugma/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Magcargo[] = INCBIN_U32("graphics/pokemon/magcargo/anim_front.4bpp.lz");
    const u32 gMonPalette_Magcargo[] = INCBIN_U32("graphics/pokemon/magcargo/normal.gbapal.lz");
    const u32 gMonBackPic_Magcargo[] = INCBIN_U32("graphics/pokemon/magcargo/back.4bpp.lz");
    const u32 gMonShinyPalette_Magcargo[] = INCBIN_U32("graphics/pokemon/magcargo/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Magcargo[] = INCBIN_U32("graphics/pokemon/magcargo/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Magcargo[] = INCBIN_U32("graphics/pokemon/magcargo/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Magcargo[] = INCBIN_U32("graphics/pokemon/magcargo/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Magcargo[] = INCBIN_U32("graphics/pokemon/magcargo/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Magcargo[] = INCBIN_U8("graphics/pokemon/magcargo/icon.4bpp");
#else
    const u8 gMonIcon_Magcargo[] = INCBIN_U8("graphics/pokemon/magcargo/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Magcargo[] = INCBIN_U8("graphics/pokemon/magcargo/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Magcargo[] = INCBIN_COMP("graphics/pokemon/magcargo/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Magcargo[] = INCBIN_U32("graphics/pokemon/magcargo/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Magcargo[] = INCBIN_U32("graphics/pokemon/magcargo/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SLUGMA

#if P_FAMILY_SWINUB
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Swinub[] = INCBIN_U32("graphics/pokemon/swinub/anim_front.4bpp.lz");
    const u32 gMonPalette_Swinub[] = INCBIN_U32("graphics/pokemon/swinub/normal.gbapal.lz");
    const u32 gMonBackPic_Swinub[] = INCBIN_U32("graphics/pokemon/swinub/back.4bpp.lz");
    const u32 gMonShinyPalette_Swinub[] = INCBIN_U32("graphics/pokemon/swinub/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Swinub[] = INCBIN_U32("graphics/pokemon/swinub/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Swinub[] = INCBIN_U32("graphics/pokemon/swinub/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Swinub[] = INCBIN_U32("graphics/pokemon/swinub/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Swinub[] = INCBIN_U32("graphics/pokemon/swinub/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Swinub[] = INCBIN_U8("graphics/pokemon/swinub/icon.4bpp");
#else
    const u8 gMonIcon_Swinub[] = INCBIN_U8("graphics/pokemon/swinub/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Swinub[] = INCBIN_U8("graphics/pokemon/swinub/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Swinub[] = INCBIN_COMP("graphics/pokemon/swinub/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Swinub[] = INCBIN_U32("graphics/pokemon/swinub/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Swinub[] = INCBIN_U32("graphics/pokemon/swinub/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Piloswine[] = INCBIN_U32("graphics/pokemon/piloswine/anim_front.4bpp.lz");
    const u32 gMonPalette_Piloswine[] = INCBIN_U32("graphics/pokemon/piloswine/normal.gbapal.lz");
    const u32 gMonBackPic_Piloswine[] = INCBIN_U32("graphics/pokemon/piloswine/back.4bpp.lz");
    const u32 gMonShinyPalette_Piloswine[] = INCBIN_U32("graphics/pokemon/piloswine/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Piloswine[] = INCBIN_U32("graphics/pokemon/piloswine/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Piloswine[] = INCBIN_U32("graphics/pokemon/piloswine/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Piloswine[] = INCBIN_U32("graphics/pokemon/piloswine/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Piloswine[] = INCBIN_U32("graphics/pokemon/piloswine/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Piloswine[] = INCBIN_U8("graphics/pokemon/piloswine/icon.4bpp");
#else
    const u8 gMonIcon_Piloswine[] = INCBIN_U8("graphics/pokemon/piloswine/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Piloswine[] = INCBIN_U8("graphics/pokemon/piloswine/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Piloswine[] = INCBIN_COMP("graphics/pokemon/piloswine/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Piloswine[] = INCBIN_U32("graphics/pokemon/piloswine/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Piloswine[] = INCBIN_U32("graphics/pokemon/piloswine/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_PiloswineF[] = INCBIN_U32("graphics/pokemon/piloswine/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_PiloswineF[] = INCBIN_U32("graphics/pokemon/piloswine/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_PiloswineF[] = INCBIN_COMP("graphics/pokemon/piloswine/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Mamoswine[] = INCBIN_U32("graphics/pokemon/mamoswine/anim_front.4bpp.lz");
    const u32 gMonPalette_Mamoswine[] = INCBIN_U32("graphics/pokemon/mamoswine/normal.gbapal.lz");
    const u32 gMonBackPic_Mamoswine[] = INCBIN_U32("graphics/pokemon/mamoswine/back.4bpp.lz");
    const u32 gMonShinyPalette_Mamoswine[] = INCBIN_U32("graphics/pokemon/mamoswine/shiny.gbapal.lz");
    const u8 gMonIcon_Mamoswine[] = INCBIN_U8("graphics/pokemon/mamoswine/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Mamoswine[] = INCBIN_U8("graphics/pokemon/mamoswine/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Mamoswine[] = INCBIN_COMP("graphics/pokemon/mamoswine/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Mamoswine[] = INCBIN_U32("graphics/pokemon/mamoswine/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Mamoswine[] = INCBIN_U32("graphics/pokemon/mamoswine/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_MamoswineF[] = INCBIN_U32("graphics/pokemon/mamoswine/anim_frontf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_MamoswineF[] = INCBIN_COMP("graphics/pokemon/mamoswine/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_SWINUB

#if P_FAMILY_CORSOLA
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Corsola[] = INCBIN_U32("graphics/pokemon/corsola/anim_front.4bpp.lz");
    const u32 gMonPalette_Corsola[] = INCBIN_U32("graphics/pokemon/corsola/normal.gbapal.lz");
    const u32 gMonBackPic_Corsola[] = INCBIN_U32("graphics/pokemon/corsola/back.4bpp.lz");
    const u32 gMonShinyPalette_Corsola[] = INCBIN_U32("graphics/pokemon/corsola/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Corsola[] = INCBIN_U32("graphics/pokemon/corsola/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Corsola[] = INCBIN_U32("graphics/pokemon/corsola/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Corsola[] = INCBIN_U32("graphics/pokemon/corsola/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Corsola[] = INCBIN_U32("graphics/pokemon/corsola/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Corsola[] = INCBIN_U8("graphics/pokemon/corsola/icon.4bpp");
#else
    const u8 gMonIcon_Corsola[] = INCBIN_U8("graphics/pokemon/corsola/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Corsola[] = INCBIN_U8("graphics/pokemon/corsola/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Corsola[] = INCBIN_COMP("graphics/pokemon/corsola/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Corsola[] = INCBIN_U32("graphics/pokemon/corsola/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Corsola[] = INCBIN_U32("graphics/pokemon/corsola/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_CORSOLA

#if P_FAMILY_REMORAID
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Remoraid[] = INCBIN_U32("graphics/pokemon/remoraid/anim_front.4bpp.lz");
    const u32 gMonPalette_Remoraid[] = INCBIN_U32("graphics/pokemon/remoraid/normal.gbapal.lz");
    const u32 gMonBackPic_Remoraid[] = INCBIN_U32("graphics/pokemon/remoraid/back.4bpp.lz");
    const u32 gMonShinyPalette_Remoraid[] = INCBIN_U32("graphics/pokemon/remoraid/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Remoraid[] = INCBIN_U32("graphics/pokemon/remoraid/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Remoraid[] = INCBIN_U32("graphics/pokemon/remoraid/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Remoraid[] = INCBIN_U32("graphics/pokemon/remoraid/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Remoraid[] = INCBIN_U32("graphics/pokemon/remoraid/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Remoraid[] = INCBIN_U8("graphics/pokemon/remoraid/icon.4bpp");
#else
    const u8 gMonIcon_Remoraid[] = INCBIN_U8("graphics/pokemon/remoraid/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Remoraid[] = INCBIN_U8("graphics/pokemon/remoraid/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Remoraid[] = INCBIN_COMP("graphics/pokemon/remoraid/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Remoraid[] = INCBIN_U32("graphics/pokemon/remoraid/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Remoraid[] = INCBIN_U32("graphics/pokemon/remoraid/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Octillery[] = INCBIN_U32("graphics/pokemon/octillery/anim_front.4bpp.lz");
    const u32 gMonPalette_Octillery[] = INCBIN_U32("graphics/pokemon/octillery/normal.gbapal.lz");
    const u32 gMonBackPic_Octillery[] = INCBIN_U32("graphics/pokemon/octillery/back.4bpp.lz");
    const u32 gMonShinyPalette_Octillery[] = INCBIN_U32("graphics/pokemon/octillery/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Octillery[] = INCBIN_U32("graphics/pokemon/octillery/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Octillery[] = INCBIN_U32("graphics/pokemon/octillery/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Octillery[] = INCBIN_U32("graphics/pokemon/octillery/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Octillery[] = INCBIN_U32("graphics/pokemon/octillery/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Octillery[] = INCBIN_U8("graphics/pokemon/octillery/icon.4bpp");
#else
    const u8 gMonIcon_Octillery[] = INCBIN_U8("graphics/pokemon/octillery/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Octillery[] = INCBIN_U8("graphics/pokemon/octillery/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Octillery[] = INCBIN_COMP("graphics/pokemon/octillery/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Octillery[] = INCBIN_U32("graphics/pokemon/octillery/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Octillery[] = INCBIN_U32("graphics/pokemon/octillery/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_OctilleryF[] = INCBIN_U32("graphics/pokemon/octillery/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_OctilleryF[] = INCBIN_U32("graphics/pokemon/octillery/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_OctilleryF[] = INCBIN_COMP("graphics/pokemon/octillery/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_REMORAID

#if P_FAMILY_DELIBIRD
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Delibird[] = INCBIN_U32("graphics/pokemon/delibird/anim_front.4bpp.lz");
    const u32 gMonPalette_Delibird[] = INCBIN_U32("graphics/pokemon/delibird/normal.gbapal.lz");
    const u32 gMonBackPic_Delibird[] = INCBIN_U32("graphics/pokemon/delibird/back.4bpp.lz");
    const u32 gMonShinyPalette_Delibird[] = INCBIN_U32("graphics/pokemon/delibird/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Delibird[] = INCBIN_U32("graphics/pokemon/delibird/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Delibird[] = INCBIN_U32("graphics/pokemon/delibird/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Delibird[] = INCBIN_U32("graphics/pokemon/delibird/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Delibird[] = INCBIN_U32("graphics/pokemon/delibird/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Delibird[] = INCBIN_U8("graphics/pokemon/delibird/icon.4bpp");
#else
    const u8 gMonIcon_Delibird[] = INCBIN_U8("graphics/pokemon/delibird/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Delibird[] = INCBIN_U8("graphics/pokemon/delibird/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Delibird[] = INCBIN_COMP("graphics/pokemon/delibird/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Delibird[] = INCBIN_U32("graphics/pokemon/delibird/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Delibird[] = INCBIN_U32("graphics/pokemon/delibird/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_DELIBIRD

#if P_FAMILY_MANTINE
#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Mantyke[] = INCBIN_U32("graphics/pokemon/mantyke/anim_front.4bpp.lz");
    const u32 gMonPalette_Mantyke[] = INCBIN_U32("graphics/pokemon/mantyke/normal.gbapal.lz");
    const u32 gMonBackPic_Mantyke[] = INCBIN_U32("graphics/pokemon/mantyke/back.4bpp.lz");
    const u32 gMonShinyPalette_Mantyke[] = INCBIN_U32("graphics/pokemon/mantyke/shiny.gbapal.lz");
    const u8 gMonIcon_Mantyke[] = INCBIN_U8("graphics/pokemon/mantyke/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Mantyke[] = INCBIN_U8("graphics/pokemon/mantyke/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Mantyke[] = INCBIN_COMP("graphics/pokemon/mantyke/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Mantyke[] = INCBIN_U32("graphics/pokemon/mantyke/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Mantyke[] = INCBIN_U32("graphics/pokemon/mantyke/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_4_CROSS_EVOS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Mantine[] = INCBIN_U32("graphics/pokemon/mantine/anim_front.4bpp.lz");
    const u32 gMonPalette_Mantine[] = INCBIN_U32("graphics/pokemon/mantine/normal.gbapal.lz");
    const u32 gMonBackPic_Mantine[] = INCBIN_U32("graphics/pokemon/mantine/back.4bpp.lz");
    const u32 gMonShinyPalette_Mantine[] = INCBIN_U32("graphics/pokemon/mantine/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Mantine[] = INCBIN_U32("graphics/pokemon/mantine/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Mantine[] = INCBIN_U32("graphics/pokemon/mantine/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Mantine[] = INCBIN_U32("graphics/pokemon/mantine/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Mantine[] = INCBIN_U32("graphics/pokemon/mantine/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Mantine[] = INCBIN_U8("graphics/pokemon/mantine/icon.4bpp");
#else
    const u8 gMonIcon_Mantine[] = INCBIN_U8("graphics/pokemon/mantine/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Mantine[] = INCBIN_U8("graphics/pokemon/mantine/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Mantine[] = INCBIN_COMP("graphics/pokemon/mantine/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Mantine[] = INCBIN_U32("graphics/pokemon/mantine/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Mantine[] = INCBIN_U32("graphics/pokemon/mantine/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_MANTINE

#if P_FAMILY_SKARMORY
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Skarmory[] = INCBIN_U32("graphics/pokemon/skarmory/anim_front.4bpp.lz");
    const u32 gMonPalette_Skarmory[] = INCBIN_U32("graphics/pokemon/skarmory/normal.gbapal.lz");
    const u32 gMonBackPic_Skarmory[] = INCBIN_U32("graphics/pokemon/skarmory/back.4bpp.lz");
    const u32 gMonShinyPalette_Skarmory[] = INCBIN_U32("graphics/pokemon/skarmory/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Skarmory[] = INCBIN_U32("graphics/pokemon/skarmory/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Skarmory[] = INCBIN_U32("graphics/pokemon/skarmory/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Skarmory[] = INCBIN_U32("graphics/pokemon/skarmory/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Skarmory[] = INCBIN_U32("graphics/pokemon/skarmory/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Skarmory[] = INCBIN_U8("graphics/pokemon/skarmory/icon.4bpp");
#else
    const u8 gMonIcon_Skarmory[] = INCBIN_U8("graphics/pokemon/skarmory/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Skarmory[] = INCBIN_U8("graphics/pokemon/skarmory/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Skarmory[] = INCBIN_COMP("graphics/pokemon/skarmory/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Skarmory[] = INCBIN_U32("graphics/pokemon/skarmory/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Skarmory[] = INCBIN_U32("graphics/pokemon/skarmory/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SKARMORY

#if P_FAMILY_HOUNDOUR
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Houndour[] = INCBIN_U32("graphics/pokemon/houndour/anim_front.4bpp.lz");
    const u32 gMonPalette_Houndour[] = INCBIN_U32("graphics/pokemon/houndour/normal.gbapal.lz");
    const u32 gMonBackPic_Houndour[] = INCBIN_U32("graphics/pokemon/houndour/back.4bpp.lz");
    const u32 gMonShinyPalette_Houndour[] = INCBIN_U32("graphics/pokemon/houndour/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Houndour[] = INCBIN_U32("graphics/pokemon/houndour/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Houndour[] = INCBIN_U32("graphics/pokemon/houndour/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Houndour[] = INCBIN_U32("graphics/pokemon/houndour/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Houndour[] = INCBIN_U32("graphics/pokemon/houndour/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Houndour[] = INCBIN_U8("graphics/pokemon/houndour/icon.4bpp");
#else
    const u8 gMonIcon_Houndour[] = INCBIN_U8("graphics/pokemon/houndour/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Houndour[] = INCBIN_U8("graphics/pokemon/houndour/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Houndour[] = INCBIN_COMP("graphics/pokemon/houndour/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Houndour[] = INCBIN_U32("graphics/pokemon/houndour/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Houndour[] = INCBIN_U32("graphics/pokemon/houndour/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Houndoom[] = INCBIN_U32("graphics/pokemon/houndoom/anim_front.4bpp.lz");
    const u32 gMonPalette_Houndoom[] = INCBIN_U32("graphics/pokemon/houndoom/normal.gbapal.lz");
    const u32 gMonBackPic_Houndoom[] = INCBIN_U32("graphics/pokemon/houndoom/back.4bpp.lz");
    const u32 gMonShinyPalette_Houndoom[] = INCBIN_U32("graphics/pokemon/houndoom/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Houndoom[] = INCBIN_U32("graphics/pokemon/houndoom/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Houndoom[] = INCBIN_U32("graphics/pokemon/houndoom/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Houndoom[] = INCBIN_U32("graphics/pokemon/houndoom/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Houndoom[] = INCBIN_U32("graphics/pokemon/houndoom/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Houndoom[] = INCBIN_U8("graphics/pokemon/houndoom/icon.4bpp");
#else
    const u8 gMonIcon_Houndoom[] = INCBIN_U8("graphics/pokemon/houndoom/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Houndoom[] = INCBIN_U8("graphics/pokemon/houndoom/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Houndoom[] = INCBIN_COMP("graphics/pokemon/houndoom/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Houndoom[] = INCBIN_U32("graphics/pokemon/houndoom/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Houndoom[] = INCBIN_U32("graphics/pokemon/houndoom/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_HoundoomF[] = INCBIN_U32("graphics/pokemon/houndoom/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_HoundoomF[] = INCBIN_U32("graphics/pokemon/houndoom/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_HoundoomF[] = INCBIN_COMP("graphics/pokemon/houndoom/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_HOUNDOUR

#if P_FAMILY_PHANPY
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Phanpy[] = INCBIN_U32("graphics/pokemon/phanpy/anim_front.4bpp.lz");
    const u32 gMonPalette_Phanpy[] = INCBIN_U32("graphics/pokemon/phanpy/normal.gbapal.lz");
    const u32 gMonBackPic_Phanpy[] = INCBIN_U32("graphics/pokemon/phanpy/back.4bpp.lz");
    const u32 gMonShinyPalette_Phanpy[] = INCBIN_U32("graphics/pokemon/phanpy/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Phanpy[] = INCBIN_U32("graphics/pokemon/phanpy/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Phanpy[] = INCBIN_U32("graphics/pokemon/phanpy/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Phanpy[] = INCBIN_U32("graphics/pokemon/phanpy/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Phanpy[] = INCBIN_U32("graphics/pokemon/phanpy/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Phanpy[] = INCBIN_U8("graphics/pokemon/phanpy/icon.4bpp");
#else
    const u8 gMonIcon_Phanpy[] = INCBIN_U8("graphics/pokemon/phanpy/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Phanpy[] = INCBIN_U8("graphics/pokemon/phanpy/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Phanpy[] = INCBIN_COMP("graphics/pokemon/phanpy/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Phanpy[] = INCBIN_U32("graphics/pokemon/phanpy/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Phanpy[] = INCBIN_U32("graphics/pokemon/phanpy/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Donphan[] = INCBIN_U32("graphics/pokemon/donphan/anim_front.4bpp.lz");
    const u32 gMonPalette_Donphan[] = INCBIN_U32("graphics/pokemon/donphan/normal.gbapal.lz");
    const u32 gMonBackPic_Donphan[] = INCBIN_U32("graphics/pokemon/donphan/back.4bpp.lz");
    const u32 gMonShinyPalette_Donphan[] = INCBIN_U32("graphics/pokemon/donphan/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Donphan[] = INCBIN_U32("graphics/pokemon/donphan/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Donphan[] = INCBIN_U32("graphics/pokemon/donphan/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Donphan[] = INCBIN_U32("graphics/pokemon/donphan/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Donphan[] = INCBIN_U32("graphics/pokemon/donphan/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Donphan[] = INCBIN_U8("graphics/pokemon/donphan/icon.4bpp");
#else
    const u8 gMonIcon_Donphan[] = INCBIN_U8("graphics/pokemon/donphan/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Donphan[] = INCBIN_U8("graphics/pokemon/donphan/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Donphan[] = INCBIN_COMP("graphics/pokemon/donphan/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Donphan[] = INCBIN_U32("graphics/pokemon/donphan/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Donphan[] = INCBIN_U32("graphics/pokemon/donphan/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_DonphanF[] = INCBIN_U32("graphics/pokemon/donphan/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_DonphanF[] = INCBIN_U32("graphics/pokemon/donphan/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_DonphanF[] = INCBIN_COMP("graphics/pokemon/donphan/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_PHANPY

#if P_FAMILY_STANTLER
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Stantler[] = INCBIN_U32("graphics/pokemon/stantler/anim_front.4bpp.lz");
    const u32 gMonPalette_Stantler[] = INCBIN_U32("graphics/pokemon/stantler/normal.gbapal.lz");
    const u32 gMonBackPic_Stantler[] = INCBIN_U32("graphics/pokemon/stantler/back.4bpp.lz");
    const u32 gMonShinyPalette_Stantler[] = INCBIN_U32("graphics/pokemon/stantler/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Stantler[] = INCBIN_U32("graphics/pokemon/stantler/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Stantler[] = INCBIN_U32("graphics/pokemon/stantler/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Stantler[] = INCBIN_U32("graphics/pokemon/stantler/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Stantler[] = INCBIN_U32("graphics/pokemon/stantler/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Stantler[] = INCBIN_U8("graphics/pokemon/stantler/icon.4bpp");
#else
    const u8 gMonIcon_Stantler[] = INCBIN_U8("graphics/pokemon/stantler/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Stantler[] = INCBIN_U8("graphics/pokemon/stantler/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Stantler[] = INCBIN_COMP("graphics/pokemon/stantler/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Stantler[] = INCBIN_U32("graphics/pokemon/stantler/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Stantler[] = INCBIN_U32("graphics/pokemon/stantler/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_STANTLER

#if P_FAMILY_SMEARGLE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Smeargle[] = INCBIN_U32("graphics/pokemon/smeargle/anim_front.4bpp.lz");
    const u32 gMonPalette_Smeargle[] = INCBIN_U32("graphics/pokemon/smeargle/normal.gbapal.lz");
    const u32 gMonBackPic_Smeargle[] = INCBIN_U32("graphics/pokemon/smeargle/back.4bpp.lz");
    const u32 gMonShinyPalette_Smeargle[] = INCBIN_U32("graphics/pokemon/smeargle/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Smeargle[] = INCBIN_U32("graphics/pokemon/smeargle/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Smeargle[] = INCBIN_U32("graphics/pokemon/smeargle/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Smeargle[] = INCBIN_U32("graphics/pokemon/smeargle/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Smeargle[] = INCBIN_U32("graphics/pokemon/smeargle/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Smeargle[] = INCBIN_U8("graphics/pokemon/smeargle/icon.4bpp");
#else
    const u8 gMonIcon_Smeargle[] = INCBIN_U8("graphics/pokemon/smeargle/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Smeargle[] = INCBIN_U8("graphics/pokemon/smeargle/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Smeargle[] = INCBIN_COMP("graphics/pokemon/smeargle/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Smeargle[] = INCBIN_U32("graphics/pokemon/smeargle/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Smeargle[] = INCBIN_U32("graphics/pokemon/smeargle/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SMEARGLE

#if P_FAMILY_MILTANK
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Miltank[] = INCBIN_U32("graphics/pokemon/miltank/anim_front.4bpp.lz");
    const u32 gMonPalette_Miltank[] = INCBIN_U32("graphics/pokemon/miltank/normal.gbapal.lz");
    const u32 gMonBackPic_Miltank[] = INCBIN_U32("graphics/pokemon/miltank/back.4bpp.lz");
    const u32 gMonShinyPalette_Miltank[] = INCBIN_U32("graphics/pokemon/miltank/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Miltank[] = INCBIN_U32("graphics/pokemon/miltank/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Miltank[] = INCBIN_U32("graphics/pokemon/miltank/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Miltank[] = INCBIN_U32("graphics/pokemon/miltank/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Miltank[] = INCBIN_U32("graphics/pokemon/miltank/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Miltank[] = INCBIN_U8("graphics/pokemon/miltank/icon.4bpp");
#else
    const u8 gMonIcon_Miltank[] = INCBIN_U8("graphics/pokemon/miltank/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Miltank[] = INCBIN_U8("graphics/pokemon/miltank/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Miltank[] = INCBIN_COMP("graphics/pokemon/miltank/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Miltank[] = INCBIN_U32("graphics/pokemon/miltank/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Miltank[] = INCBIN_U32("graphics/pokemon/miltank/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_MILTANK

#if P_FAMILY_RAIKOU
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Raikou[] = INCBIN_U32("graphics/pokemon/raikou/anim_front.4bpp.lz");
    const u32 gMonPalette_Raikou[] = INCBIN_U32("graphics/pokemon/raikou/normal.gbapal.lz");
    const u32 gMonBackPic_Raikou[] = INCBIN_U32("graphics/pokemon/raikou/back.4bpp.lz");
    const u32 gMonShinyPalette_Raikou[] = INCBIN_U32("graphics/pokemon/raikou/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Raikou[] = INCBIN_U32("graphics/pokemon/raikou/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Raikou[] = INCBIN_U32("graphics/pokemon/raikou/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Raikou[] = INCBIN_U32("graphics/pokemon/raikou/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Raikou[] = INCBIN_U32("graphics/pokemon/raikou/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Raikou[] = INCBIN_U8("graphics/pokemon/raikou/icon.4bpp");
#else
    const u8 gMonIcon_Raikou[] = INCBIN_U8("graphics/pokemon/raikou/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Raikou[] = INCBIN_U8("graphics/pokemon/raikou/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Raikou[] = INCBIN_COMP("graphics/pokemon/raikou/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Raikou[] = INCBIN_U32("graphics/pokemon/raikou/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Raikou[] = INCBIN_U32("graphics/pokemon/raikou/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_RAIKOU

#if P_FAMILY_ENTEI
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Entei[] = INCBIN_U32("graphics/pokemon/entei/anim_front.4bpp.lz");
    const u32 gMonPalette_Entei[] = INCBIN_U32("graphics/pokemon/entei/normal.gbapal.lz");
    const u32 gMonBackPic_Entei[] = INCBIN_U32("graphics/pokemon/entei/back.4bpp.lz");
    const u32 gMonShinyPalette_Entei[] = INCBIN_U32("graphics/pokemon/entei/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Entei[] = INCBIN_U32("graphics/pokemon/entei/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Entei[] = INCBIN_U32("graphics/pokemon/entei/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Entei[] = INCBIN_U32("graphics/pokemon/entei/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Entei[] = INCBIN_U32("graphics/pokemon/entei/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Entei[] = INCBIN_U8("graphics/pokemon/entei/icon.4bpp");
#else
    const u8 gMonIcon_Entei[] = INCBIN_U8("graphics/pokemon/entei/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Entei[] = INCBIN_U8("graphics/pokemon/entei/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Entei[] = INCBIN_COMP("graphics/pokemon/entei/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Entei[] = INCBIN_U32("graphics/pokemon/entei/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Entei[] = INCBIN_U32("graphics/pokemon/entei/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_ENTEI

#if P_FAMILY_SUICUNE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Suicune[] = INCBIN_U32("graphics/pokemon/suicune/anim_front.4bpp.lz");
    const u32 gMonPalette_Suicune[] = INCBIN_U32("graphics/pokemon/suicune/normal.gbapal.lz");
    const u32 gMonBackPic_Suicune[] = INCBIN_U32("graphics/pokemon/suicune/back.4bpp.lz");
    const u32 gMonShinyPalette_Suicune[] = INCBIN_U32("graphics/pokemon/suicune/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Suicune[] = INCBIN_U32("graphics/pokemon/suicune/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Suicune[] = INCBIN_U32("graphics/pokemon/suicune/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Suicune[] = INCBIN_U32("graphics/pokemon/suicune/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Suicune[] = INCBIN_U32("graphics/pokemon/suicune/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Suicune[] = INCBIN_U8("graphics/pokemon/suicune/icon.4bpp");
#else
    const u8 gMonIcon_Suicune[] = INCBIN_U8("graphics/pokemon/suicune/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Suicune[] = INCBIN_U8("graphics/pokemon/suicune/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Suicune[] = INCBIN_COMP("graphics/pokemon/suicune/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Suicune[] = INCBIN_U32("graphics/pokemon/suicune/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Suicune[] = INCBIN_U32("graphics/pokemon/suicune/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SUICUNE

#if P_FAMILY_LARVITAR
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Larvitar[] = INCBIN_U32("graphics/pokemon/larvitar/anim_front.4bpp.lz");
    const u32 gMonPalette_Larvitar[] = INCBIN_U32("graphics/pokemon/larvitar/normal.gbapal.lz");
    const u32 gMonBackPic_Larvitar[] = INCBIN_U32("graphics/pokemon/larvitar/back.4bpp.lz");
    const u32 gMonShinyPalette_Larvitar[] = INCBIN_U32("graphics/pokemon/larvitar/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Larvitar[] = INCBIN_U32("graphics/pokemon/larvitar/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Larvitar[] = INCBIN_U32("graphics/pokemon/larvitar/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Larvitar[] = INCBIN_U32("graphics/pokemon/larvitar/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Larvitar[] = INCBIN_U32("graphics/pokemon/larvitar/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Larvitar[] = INCBIN_U8("graphics/pokemon/larvitar/icon.4bpp");
#else
    const u8 gMonIcon_Larvitar[] = INCBIN_U8("graphics/pokemon/larvitar/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Larvitar[] = INCBIN_U8("graphics/pokemon/larvitar/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Larvitar[] = INCBIN_COMP("graphics/pokemon/larvitar/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Larvitar[] = INCBIN_U32("graphics/pokemon/larvitar/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Larvitar[] = INCBIN_U32("graphics/pokemon/larvitar/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Pupitar[] = INCBIN_U32("graphics/pokemon/pupitar/anim_front.4bpp.lz");
    const u32 gMonPalette_Pupitar[] = INCBIN_U32("graphics/pokemon/pupitar/normal.gbapal.lz");
    const u32 gMonBackPic_Pupitar[] = INCBIN_U32("graphics/pokemon/pupitar/back.4bpp.lz");
    const u32 gMonShinyPalette_Pupitar[] = INCBIN_U32("graphics/pokemon/pupitar/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Pupitar[] = INCBIN_U32("graphics/pokemon/pupitar/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Pupitar[] = INCBIN_U32("graphics/pokemon/pupitar/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Pupitar[] = INCBIN_U32("graphics/pokemon/pupitar/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Pupitar[] = INCBIN_U32("graphics/pokemon/pupitar/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Pupitar[] = INCBIN_U8("graphics/pokemon/pupitar/icon.4bpp");
#else
    const u8 gMonIcon_Pupitar[] = INCBIN_U8("graphics/pokemon/pupitar/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Pupitar[] = INCBIN_U8("graphics/pokemon/pupitar/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Pupitar[] = INCBIN_COMP("graphics/pokemon/pupitar/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Pupitar[] = INCBIN_U32("graphics/pokemon/pupitar/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Pupitar[] = INCBIN_U32("graphics/pokemon/pupitar/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Tyranitar[] = INCBIN_U32("graphics/pokemon/tyranitar/anim_front.4bpp.lz");
    const u32 gMonPalette_Tyranitar[] = INCBIN_U32("graphics/pokemon/tyranitar/normal.gbapal.lz");
    const u32 gMonBackPic_Tyranitar[] = INCBIN_U32("graphics/pokemon/tyranitar/back.4bpp.lz");
    const u32 gMonShinyPalette_Tyranitar[] = INCBIN_U32("graphics/pokemon/tyranitar/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Tyranitar[] = INCBIN_U32("graphics/pokemon/tyranitar/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Tyranitar[] = INCBIN_U32("graphics/pokemon/tyranitar/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Tyranitar[] = INCBIN_U32("graphics/pokemon/tyranitar/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Tyranitar[] = INCBIN_U32("graphics/pokemon/tyranitar/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Tyranitar[] = INCBIN_U8("graphics/pokemon/tyranitar/icon.4bpp");
#else
    const u8 gMonIcon_Tyranitar[] = INCBIN_U8("graphics/pokemon/tyranitar/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Tyranitar[] = INCBIN_U8("graphics/pokemon/tyranitar/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Tyranitar[] = INCBIN_COMP("graphics/pokemon/tyranitar/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Tyranitar[] = INCBIN_U32("graphics/pokemon/tyranitar/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Tyranitar[] = INCBIN_U32("graphics/pokemon/tyranitar/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_LARVITAR

#if P_FAMILY_LUGIA
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Lugia[] = INCBIN_U32("graphics/pokemon/lugia/anim_front.4bpp.lz");
    const u32 gMonPalette_Lugia[] = INCBIN_U32("graphics/pokemon/lugia/normal.gbapal.lz");
    const u32 gMonBackPic_Lugia[] = INCBIN_U32("graphics/pokemon/lugia/back.4bpp.lz");
    const u32 gMonShinyPalette_Lugia[] = INCBIN_U32("graphics/pokemon/lugia/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Lugia[] = INCBIN_U32("graphics/pokemon/lugia/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Lugia[] = INCBIN_U32("graphics/pokemon/lugia/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Lugia[] = INCBIN_U32("graphics/pokemon/lugia/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Lugia[] = INCBIN_U32("graphics/pokemon/lugia/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Lugia[] = INCBIN_U8("graphics/pokemon/lugia/icon.4bpp");
#else
    const u8 gMonIcon_Lugia[] = INCBIN_U8("graphics/pokemon/lugia/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Lugia[] = INCBIN_U8("graphics/pokemon/lugia/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Lugia[] = INCBIN_COMP("graphics/pokemon/lugia/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Lugia[] = INCBIN_U32("graphics/pokemon/lugia/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Lugia[] = INCBIN_U32("graphics/pokemon/lugia/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_LUGIA

#if P_FAMILY_HO_OH
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_HoOh[] = INCBIN_U32("graphics/pokemon/ho_oh/anim_front.4bpp.lz");
    const u32 gMonPalette_HoOh[] = INCBIN_U32("graphics/pokemon/ho_oh/normal.gbapal.lz");
    const u32 gMonBackPic_HoOh[] = INCBIN_U32("graphics/pokemon/ho_oh/back.4bpp.lz");
    const u32 gMonShinyPalette_HoOh[] = INCBIN_U32("graphics/pokemon/ho_oh/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_HoOh[] = INCBIN_U32("graphics/pokemon/ho_oh/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_HoOh[] = INCBIN_U32("graphics/pokemon/ho_oh/normal_gba.gbapal.lz");
    const u32 gMonBackPic_HoOh[] = INCBIN_U32("graphics/pokemon/ho_oh/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_HoOh[] = INCBIN_U32("graphics/pokemon/ho_oh/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_HoOh[] = INCBIN_U8("graphics/pokemon/ho_oh/icon.4bpp");
#else
    const u8 gMonIcon_HoOh[] = INCBIN_U8("graphics/pokemon/ho_oh/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_HoOh[] = INCBIN_U8("graphics/pokemon/ho_oh/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_HoOh[] = INCBIN_COMP("graphics/pokemon/ho_oh/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_HoOh[] = INCBIN_U32("graphics/pokemon/ho_oh/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_HoOh[] = INCBIN_U32("graphics/pokemon/ho_oh/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_HO_OH

#if P_FAMILY_CELEBI
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Celebi[] = INCBIN_U32("graphics/pokemon/celebi/anim_front.4bpp.lz");
    const u32 gMonPalette_Celebi[] = INCBIN_U32("graphics/pokemon/celebi/normal.gbapal.lz");
    const u32 gMonBackPic_Celebi[] = INCBIN_U32("graphics/pokemon/celebi/back.4bpp.lz");
    const u32 gMonShinyPalette_Celebi[] = INCBIN_U32("graphics/pokemon/celebi/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Celebi[] = INCBIN_U32("graphics/pokemon/celebi/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Celebi[] = INCBIN_U32("graphics/pokemon/celebi/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Celebi[] = INCBIN_U32("graphics/pokemon/celebi/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Celebi[] = INCBIN_U32("graphics/pokemon/celebi/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Celebi[] = INCBIN_U8("graphics/pokemon/celebi/icon.4bpp");
#else
    const u8 gMonIcon_Celebi[] = INCBIN_U8("graphics/pokemon/celebi/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Celebi[] = INCBIN_U8("graphics/pokemon/celebi/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Celebi[] = INCBIN_COMP("graphics/pokemon/celebi/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Celebi[] = INCBIN_U32("graphics/pokemon/celebi/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Celebi[] = INCBIN_U32("graphics/pokemon/celebi/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_CELEBI

#if P_FAMILY_TREECKO
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Treecko[] = INCBIN_U32("graphics/pokemon/treecko/anim_front.4bpp.lz");
    const u32 gMonPalette_Treecko[] = INCBIN_U32("graphics/pokemon/treecko/normal.gbapal.lz");
    const u32 gMonBackPic_Treecko[] = INCBIN_U32("graphics/pokemon/treecko/back.4bpp.lz");
    const u32 gMonShinyPalette_Treecko[] = INCBIN_U32("graphics/pokemon/treecko/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Treecko[] = INCBIN_U32("graphics/pokemon/treecko/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Treecko[] = INCBIN_U32("graphics/pokemon/treecko/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Treecko[] = INCBIN_U32("graphics/pokemon/treecko/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Treecko[] = INCBIN_U32("graphics/pokemon/treecko/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Treecko[] = INCBIN_U8("graphics/pokemon/treecko/icon.4bpp");
#else
    const u8 gMonIcon_Treecko[] = INCBIN_U8("graphics/pokemon/treecko/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Treecko[] = INCBIN_U8("graphics/pokemon/treecko/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Treecko[] = INCBIN_COMP("graphics/pokemon/treecko/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Treecko[] = INCBIN_U32("graphics/pokemon/treecko/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Treecko[] = INCBIN_U32("graphics/pokemon/treecko/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Grovyle[] = INCBIN_U32("graphics/pokemon/grovyle/anim_front.4bpp.lz");
    const u32 gMonPalette_Grovyle[] = INCBIN_U32("graphics/pokemon/grovyle/normal.gbapal.lz");
    const u32 gMonBackPic_Grovyle[] = INCBIN_U32("graphics/pokemon/grovyle/back.4bpp.lz");
    const u32 gMonShinyPalette_Grovyle[] = INCBIN_U32("graphics/pokemon/grovyle/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Grovyle[] = INCBIN_U32("graphics/pokemon/grovyle/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Grovyle[] = INCBIN_U32("graphics/pokemon/grovyle/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Grovyle[] = INCBIN_U32("graphics/pokemon/grovyle/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Grovyle[] = INCBIN_U32("graphics/pokemon/grovyle/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Grovyle[] = INCBIN_U8("graphics/pokemon/grovyle/icon.4bpp");
#else
    const u8 gMonIcon_Grovyle[] = INCBIN_U8("graphics/pokemon/grovyle/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Grovyle[] = INCBIN_U8("graphics/pokemon/grovyle/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Grovyle[] = INCBIN_COMP("graphics/pokemon/grovyle/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Grovyle[] = INCBIN_U32("graphics/pokemon/grovyle/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Grovyle[] = INCBIN_U32("graphics/pokemon/grovyle/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Sceptile[] = INCBIN_U32("graphics/pokemon/sceptile/anim_front.4bpp.lz");
    const u32 gMonPalette_Sceptile[] = INCBIN_U32("graphics/pokemon/sceptile/normal.gbapal.lz");
    const u32 gMonBackPic_Sceptile[] = INCBIN_U32("graphics/pokemon/sceptile/back.4bpp.lz");
    const u32 gMonShinyPalette_Sceptile[] = INCBIN_U32("graphics/pokemon/sceptile/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Sceptile[] = INCBIN_U32("graphics/pokemon/sceptile/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Sceptile[] = INCBIN_U32("graphics/pokemon/sceptile/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Sceptile[] = INCBIN_U32("graphics/pokemon/sceptile/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Sceptile[] = INCBIN_U32("graphics/pokemon/sceptile/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Sceptile[] = INCBIN_U8("graphics/pokemon/sceptile/icon.4bpp");
#else
    const u8 gMonIcon_Sceptile[] = INCBIN_U8("graphics/pokemon/sceptile/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Sceptile[] = INCBIN_U8("graphics/pokemon/sceptile/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Sceptile[] = INCBIN_COMP("graphics/pokemon/sceptile/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Sceptile[] = INCBIN_U32("graphics/pokemon/sceptile/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Sceptile[] = INCBIN_U32("graphics/pokemon/sceptile/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_TREECKO

#if P_FAMILY_TORCHIC
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Torchic[] = INCBIN_U32("graphics/pokemon/torchic/anim_front.4bpp.lz");
    const u32 gMonPalette_Torchic[] = INCBIN_U32("graphics/pokemon/torchic/normal.gbapal.lz");
    const u32 gMonBackPic_Torchic[] = INCBIN_U32("graphics/pokemon/torchic/back.4bpp.lz");
    const u32 gMonShinyPalette_Torchic[] = INCBIN_U32("graphics/pokemon/torchic/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Torchic[] = INCBIN_U32("graphics/pokemon/torchic/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Torchic[] = INCBIN_U32("graphics/pokemon/torchic/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Torchic[] = INCBIN_U32("graphics/pokemon/torchic/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Torchic[] = INCBIN_U32("graphics/pokemon/torchic/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Torchic[] = INCBIN_U8("graphics/pokemon/torchic/icon.4bpp");
#else
    const u8 gMonIcon_Torchic[] = INCBIN_U8("graphics/pokemon/torchic/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Torchic[] = INCBIN_U8("graphics/pokemon/torchic/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Torchic[] = INCBIN_COMP("graphics/pokemon/torchic/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Torchic[] = INCBIN_U32("graphics/pokemon/torchic/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Torchic[] = INCBIN_U32("graphics/pokemon/torchic/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonBackPic_TorchicF[] = INCBIN_U32("graphics/pokemon/torchic/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_TorchicF[] = INCBIN_COMP("graphics/pokemon/torchic/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Combusken[] = INCBIN_U32("graphics/pokemon/combusken/anim_front.4bpp.lz");
    const u32 gMonPalette_Combusken[] = INCBIN_U32("graphics/pokemon/combusken/normal.gbapal.lz");
    const u32 gMonBackPic_Combusken[] = INCBIN_U32("graphics/pokemon/combusken/back.4bpp.lz");
    const u32 gMonShinyPalette_Combusken[] = INCBIN_U32("graphics/pokemon/combusken/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Combusken[] = INCBIN_U32("graphics/pokemon/combusken/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Combusken[] = INCBIN_U32("graphics/pokemon/combusken/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Combusken[] = INCBIN_U32("graphics/pokemon/combusken/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Combusken[] = INCBIN_U32("graphics/pokemon/combusken/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Combusken[] = INCBIN_U8("graphics/pokemon/combusken/icon.4bpp");
#else
    const u8 gMonIcon_Combusken[] = INCBIN_U8("graphics/pokemon/combusken/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Combusken[] = INCBIN_U8("graphics/pokemon/combusken/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Combusken[] = INCBIN_COMP("graphics/pokemon/combusken/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Combusken[] = INCBIN_U32("graphics/pokemon/combusken/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Combusken[] = INCBIN_U32("graphics/pokemon/combusken/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_CombuskenF[] = INCBIN_U32("graphics/pokemon/combusken/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_CombuskenF[] = INCBIN_U32("graphics/pokemon/combusken/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_CombuskenF[] = INCBIN_COMP("graphics/pokemon/combusken/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Blaziken[] = INCBIN_U32("graphics/pokemon/blaziken/anim_front.4bpp.lz");
    const u32 gMonPalette_Blaziken[] = INCBIN_U32("graphics/pokemon/blaziken/normal.gbapal.lz");
    const u32 gMonBackPic_Blaziken[] = INCBIN_U32("graphics/pokemon/blaziken/back.4bpp.lz");
    const u32 gMonShinyPalette_Blaziken[] = INCBIN_U32("graphics/pokemon/blaziken/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Blaziken[] = INCBIN_U32("graphics/pokemon/blaziken/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Blaziken[] = INCBIN_U32("graphics/pokemon/blaziken/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Blaziken[] = INCBIN_U32("graphics/pokemon/blaziken/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Blaziken[] = INCBIN_U32("graphics/pokemon/blaziken/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Blaziken[] = INCBIN_U8("graphics/pokemon/blaziken/icon.4bpp");
#else
    const u8 gMonIcon_Blaziken[] = INCBIN_U8("graphics/pokemon/blaziken/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Blaziken[] = INCBIN_U8("graphics/pokemon/blaziken/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Blaziken[] = INCBIN_COMP("graphics/pokemon/blaziken/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Blaziken[] = INCBIN_U32("graphics/pokemon/blaziken/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Blaziken[] = INCBIN_U32("graphics/pokemon/blaziken/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_BlazikenF[] = INCBIN_U32("graphics/pokemon/blaziken/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_BlazikenF[] = INCBIN_U32("graphics/pokemon/blaziken/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_BlazikenF[] = INCBIN_COMP("graphics/pokemon/blaziken/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_TORCHIC

#if P_FAMILY_MUDKIP
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Mudkip[] = INCBIN_U32("graphics/pokemon/mudkip/anim_front.4bpp.lz");
    const u32 gMonPalette_Mudkip[] = INCBIN_U32("graphics/pokemon/mudkip/normal.gbapal.lz");
    const u32 gMonBackPic_Mudkip[] = INCBIN_U32("graphics/pokemon/mudkip/back.4bpp.lz");
    const u32 gMonShinyPalette_Mudkip[] = INCBIN_U32("graphics/pokemon/mudkip/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Mudkip[] = INCBIN_U32("graphics/pokemon/mudkip/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Mudkip[] = INCBIN_U32("graphics/pokemon/mudkip/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Mudkip[] = INCBIN_U32("graphics/pokemon/mudkip/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Mudkip[] = INCBIN_U32("graphics/pokemon/mudkip/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Mudkip[] = INCBIN_U8("graphics/pokemon/mudkip/icon.4bpp");
#else
    const u8 gMonIcon_Mudkip[] = INCBIN_U8("graphics/pokemon/mudkip/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Mudkip[] = INCBIN_U8("graphics/pokemon/mudkip/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Mudkip[] = INCBIN_COMP("graphics/pokemon/mudkip/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Mudkip[] = INCBIN_U32("graphics/pokemon/mudkip/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Mudkip[] = INCBIN_U32("graphics/pokemon/mudkip/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Marshtomp[] = INCBIN_U32("graphics/pokemon/marshtomp/anim_front.4bpp.lz");
    const u32 gMonPalette_Marshtomp[] = INCBIN_U32("graphics/pokemon/marshtomp/normal.gbapal.lz");
    const u32 gMonBackPic_Marshtomp[] = INCBIN_U32("graphics/pokemon/marshtomp/back.4bpp.lz");
    const u32 gMonShinyPalette_Marshtomp[] = INCBIN_U32("graphics/pokemon/marshtomp/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Marshtomp[] = INCBIN_U32("graphics/pokemon/marshtomp/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Marshtomp[] = INCBIN_U32("graphics/pokemon/marshtomp/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Marshtomp[] = INCBIN_U32("graphics/pokemon/marshtomp/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Marshtomp[] = INCBIN_U32("graphics/pokemon/marshtomp/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Marshtomp[] = INCBIN_U8("graphics/pokemon/marshtomp/icon.4bpp");
#else
    const u8 gMonIcon_Marshtomp[] = INCBIN_U8("graphics/pokemon/marshtomp/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Marshtomp[] = INCBIN_U8("graphics/pokemon/marshtomp/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Marshtomp[] = INCBIN_COMP("graphics/pokemon/marshtomp/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Marshtomp[] = INCBIN_U32("graphics/pokemon/marshtomp/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Marshtomp[] = INCBIN_U32("graphics/pokemon/marshtomp/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Swampert[] = INCBIN_U32("graphics/pokemon/swampert/anim_front.4bpp.lz");
    const u32 gMonPalette_Swampert[] = INCBIN_U32("graphics/pokemon/swampert/normal.gbapal.lz");
    const u32 gMonBackPic_Swampert[] = INCBIN_U32("graphics/pokemon/swampert/back.4bpp.lz");
    const u32 gMonShinyPalette_Swampert[] = INCBIN_U32("graphics/pokemon/swampert/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Swampert[] = INCBIN_U32("graphics/pokemon/swampert/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Swampert[] = INCBIN_U32("graphics/pokemon/swampert/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Swampert[] = INCBIN_U32("graphics/pokemon/swampert/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Swampert[] = INCBIN_U32("graphics/pokemon/swampert/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Swampert[] = INCBIN_U8("graphics/pokemon/swampert/icon.4bpp");
#else
    const u8 gMonIcon_Swampert[] = INCBIN_U8("graphics/pokemon/swampert/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Swampert[] = INCBIN_U8("graphics/pokemon/swampert/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Swampert[] = INCBIN_COMP("graphics/pokemon/swampert/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Swampert[] = INCBIN_U32("graphics/pokemon/swampert/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Swampert[] = INCBIN_U32("graphics/pokemon/swampert/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_MUDKIP

#if P_FAMILY_POOCHYENA
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Poochyena[] = INCBIN_U32("graphics/pokemon/poochyena/anim_front.4bpp.lz");
    const u32 gMonPalette_Poochyena[] = INCBIN_U32("graphics/pokemon/poochyena/normal.gbapal.lz");
    const u32 gMonBackPic_Poochyena[] = INCBIN_U32("graphics/pokemon/poochyena/back.4bpp.lz");
    const u32 gMonShinyPalette_Poochyena[] = INCBIN_U32("graphics/pokemon/poochyena/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Poochyena[] = INCBIN_U32("graphics/pokemon/poochyena/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Poochyena[] = INCBIN_U32("graphics/pokemon/poochyena/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Poochyena[] = INCBIN_U32("graphics/pokemon/poochyena/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Poochyena[] = INCBIN_U32("graphics/pokemon/poochyena/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Poochyena[] = INCBIN_U8("graphics/pokemon/poochyena/icon.4bpp");
#else
    const u8 gMonIcon_Poochyena[] = INCBIN_U8("graphics/pokemon/poochyena/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Poochyena[] = INCBIN_U8("graphics/pokemon/poochyena/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Poochyena[] = INCBIN_COMP("graphics/pokemon/poochyena/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Poochyena[] = INCBIN_U32("graphics/pokemon/poochyena/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Poochyena[] = INCBIN_U32("graphics/pokemon/poochyena/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Mightyena[] = INCBIN_U32("graphics/pokemon/mightyena/anim_front.4bpp.lz");
    const u32 gMonPalette_Mightyena[] = INCBIN_U32("graphics/pokemon/mightyena/normal.gbapal.lz");
    const u32 gMonBackPic_Mightyena[] = INCBIN_U32("graphics/pokemon/mightyena/back.4bpp.lz");
    const u32 gMonShinyPalette_Mightyena[] = INCBIN_U32("graphics/pokemon/mightyena/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Mightyena[] = INCBIN_U32("graphics/pokemon/mightyena/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Mightyena[] = INCBIN_U32("graphics/pokemon/mightyena/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Mightyena[] = INCBIN_U32("graphics/pokemon/mightyena/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Mightyena[] = INCBIN_U32("graphics/pokemon/mightyena/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Mightyena[] = INCBIN_U8("graphics/pokemon/mightyena/icon.4bpp");
#else
    const u8 gMonIcon_Mightyena[] = INCBIN_U8("graphics/pokemon/mightyena/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Mightyena[] = INCBIN_U8("graphics/pokemon/mightyena/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Mightyena[] = INCBIN_COMP("graphics/pokemon/mightyena/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Mightyena[] = INCBIN_U32("graphics/pokemon/mightyena/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Mightyena[] = INCBIN_U32("graphics/pokemon/mightyena/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_POOCHYENA

#if P_FAMILY_ZIGZAGOON
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Zigzagoon[] = INCBIN_U32("graphics/pokemon/zigzagoon/anim_front.4bpp.lz");
    const u32 gMonPalette_Zigzagoon[] = INCBIN_U32("graphics/pokemon/zigzagoon/normal.gbapal.lz");
    const u32 gMonBackPic_Zigzagoon[] = INCBIN_U32("graphics/pokemon/zigzagoon/back.4bpp.lz");
    const u32 gMonShinyPalette_Zigzagoon[] = INCBIN_U32("graphics/pokemon/zigzagoon/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Zigzagoon[] = INCBIN_U32("graphics/pokemon/zigzagoon/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Zigzagoon[] = INCBIN_U32("graphics/pokemon/zigzagoon/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Zigzagoon[] = INCBIN_U32("graphics/pokemon/zigzagoon/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Zigzagoon[] = INCBIN_U32("graphics/pokemon/zigzagoon/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Zigzagoon[] = INCBIN_U8("graphics/pokemon/zigzagoon/icon.4bpp");
#else
    const u8 gMonIcon_Zigzagoon[] = INCBIN_U8("graphics/pokemon/zigzagoon/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Zigzagoon[] = INCBIN_U8("graphics/pokemon/zigzagoon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Zigzagoon[] = INCBIN_COMP("graphics/pokemon/zigzagoon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Zigzagoon[] = INCBIN_U32("graphics/pokemon/zigzagoon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Zigzagoon[] = INCBIN_U32("graphics/pokemon/zigzagoon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Linoone[] = INCBIN_U32("graphics/pokemon/linoone/anim_front.4bpp.lz");
    const u32 gMonPalette_Linoone[] = INCBIN_U32("graphics/pokemon/linoone/normal.gbapal.lz");
    const u32 gMonBackPic_Linoone[] = INCBIN_U32("graphics/pokemon/linoone/back.4bpp.lz");
    const u32 gMonShinyPalette_Linoone[] = INCBIN_U32("graphics/pokemon/linoone/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Linoone[] = INCBIN_U32("graphics/pokemon/linoone/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Linoone[] = INCBIN_U32("graphics/pokemon/linoone/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Linoone[] = INCBIN_U32("graphics/pokemon/linoone/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Linoone[] = INCBIN_U32("graphics/pokemon/linoone/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Linoone[] = INCBIN_U8("graphics/pokemon/linoone/icon.4bpp");
#else
    const u8 gMonIcon_Linoone[] = INCBIN_U8("graphics/pokemon/linoone/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Linoone[] = INCBIN_U8("graphics/pokemon/linoone/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Linoone[] = INCBIN_COMP("graphics/pokemon/linoone/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Linoone[] = INCBIN_U32("graphics/pokemon/linoone/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Linoone[] = INCBIN_U32("graphics/pokemon/linoone/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_ZIGZAGOON

#if P_FAMILY_WURMPLE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Wurmple[] = INCBIN_U32("graphics/pokemon/wurmple/anim_front.4bpp.lz");
    const u32 gMonPalette_Wurmple[] = INCBIN_U32("graphics/pokemon/wurmple/normal.gbapal.lz");
    const u32 gMonBackPic_Wurmple[] = INCBIN_U32("graphics/pokemon/wurmple/back.4bpp.lz");
    const u32 gMonShinyPalette_Wurmple[] = INCBIN_U32("graphics/pokemon/wurmple/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Wurmple[] = INCBIN_U32("graphics/pokemon/wurmple/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Wurmple[] = INCBIN_U32("graphics/pokemon/wurmple/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Wurmple[] = INCBIN_U32("graphics/pokemon/wurmple/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Wurmple[] = INCBIN_U32("graphics/pokemon/wurmple/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Wurmple[] = INCBIN_U8("graphics/pokemon/wurmple/icon.4bpp");
#else
    const u8 gMonIcon_Wurmple[] = INCBIN_U8("graphics/pokemon/wurmple/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Wurmple[] = INCBIN_U8("graphics/pokemon/wurmple/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Wurmple[] = INCBIN_COMP("graphics/pokemon/wurmple/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Wurmple[] = INCBIN_U32("graphics/pokemon/wurmple/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Wurmple[] = INCBIN_U32("graphics/pokemon/wurmple/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Silcoon[] = INCBIN_U32("graphics/pokemon/silcoon/anim_front.4bpp.lz");
    const u32 gMonPalette_Silcoon[] = INCBIN_U32("graphics/pokemon/silcoon/normal.gbapal.lz");
    const u32 gMonBackPic_Silcoon[] = INCBIN_U32("graphics/pokemon/silcoon/back.4bpp.lz");
    const u32 gMonShinyPalette_Silcoon[] = INCBIN_U32("graphics/pokemon/silcoon/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Silcoon[] = INCBIN_U32("graphics/pokemon/silcoon/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Silcoon[] = INCBIN_U32("graphics/pokemon/silcoon/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Silcoon[] = INCBIN_U32("graphics/pokemon/silcoon/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Silcoon[] = INCBIN_U32("graphics/pokemon/silcoon/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Silcoon[] = INCBIN_U8("graphics/pokemon/silcoon/icon.4bpp");
#else
    const u8 gMonIcon_Silcoon[] = INCBIN_U8("graphics/pokemon/silcoon/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Silcoon[] = INCBIN_U8("graphics/pokemon/silcoon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Silcoon[] = INCBIN_COMP("graphics/pokemon/silcoon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Silcoon[] = INCBIN_U32("graphics/pokemon/silcoon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Silcoon[] = INCBIN_U32("graphics/pokemon/silcoon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Beautifly[] = INCBIN_U32("graphics/pokemon/beautifly/anim_front.4bpp.lz");
    const u32 gMonPalette_Beautifly[] = INCBIN_U32("graphics/pokemon/beautifly/normal.gbapal.lz");
    const u32 gMonBackPic_Beautifly[] = INCBIN_U32("graphics/pokemon/beautifly/back.4bpp.lz");
    const u32 gMonShinyPalette_Beautifly[] = INCBIN_U32("graphics/pokemon/beautifly/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Beautifly[] = INCBIN_U32("graphics/pokemon/beautifly/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Beautifly[] = INCBIN_U32("graphics/pokemon/beautifly/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Beautifly[] = INCBIN_U32("graphics/pokemon/beautifly/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Beautifly[] = INCBIN_U32("graphics/pokemon/beautifly/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Beautifly[] = INCBIN_U8("graphics/pokemon/beautifly/icon.4bpp");
#else
    const u8 gMonIcon_Beautifly[] = INCBIN_U8("graphics/pokemon/beautifly/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Beautifly[] = INCBIN_U8("graphics/pokemon/beautifly/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Beautifly[] = INCBIN_COMP("graphics/pokemon/beautifly/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Beautifly[] = INCBIN_U32("graphics/pokemon/beautifly/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Beautifly[] = INCBIN_U32("graphics/pokemon/beautifly/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_BeautiflyF[] = INCBIN_U32("graphics/pokemon/beautifly/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_BeautiflyF[] = INCBIN_U32("graphics/pokemon/beautifly/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_BeautiflyF[] = INCBIN_COMP("graphics/pokemon/beautifly/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Cascoon[] = INCBIN_U32("graphics/pokemon/cascoon/anim_front.4bpp.lz");
    const u32 gMonPalette_Cascoon[] = INCBIN_U32("graphics/pokemon/cascoon/normal.gbapal.lz");
    const u32 gMonBackPic_Cascoon[] = INCBIN_U32("graphics/pokemon/cascoon/back.4bpp.lz");
    const u32 gMonShinyPalette_Cascoon[] = INCBIN_U32("graphics/pokemon/cascoon/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Cascoon[] = INCBIN_U32("graphics/pokemon/cascoon/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Cascoon[] = INCBIN_U32("graphics/pokemon/cascoon/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Cascoon[] = INCBIN_U32("graphics/pokemon/cascoon/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Cascoon[] = INCBIN_U32("graphics/pokemon/cascoon/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Cascoon[] = INCBIN_U8("graphics/pokemon/cascoon/icon.4bpp");
#else
    const u8 gMonIcon_Cascoon[] = INCBIN_U8("graphics/pokemon/cascoon/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Cascoon[] = INCBIN_U8("graphics/pokemon/cascoon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Cascoon[] = INCBIN_COMP("graphics/pokemon/cascoon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Cascoon[] = INCBIN_U32("graphics/pokemon/cascoon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Cascoon[] = INCBIN_U32("graphics/pokemon/cascoon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Dustox[] = INCBIN_U32("graphics/pokemon/dustox/anim_front.4bpp.lz");
    const u32 gMonPalette_Dustox[] = INCBIN_U32("graphics/pokemon/dustox/normal.gbapal.lz");
    const u32 gMonBackPic_Dustox[] = INCBIN_U32("graphics/pokemon/dustox/back.4bpp.lz");
    const u32 gMonShinyPalette_Dustox[] = INCBIN_U32("graphics/pokemon/dustox/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Dustox[] = INCBIN_U32("graphics/pokemon/dustox/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Dustox[] = INCBIN_U32("graphics/pokemon/dustox/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Dustox[] = INCBIN_U32("graphics/pokemon/dustox/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Dustox[] = INCBIN_U32("graphics/pokemon/dustox/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Dustox[] = INCBIN_U8("graphics/pokemon/dustox/icon.4bpp");
#else
    const u8 gMonIcon_Dustox[] = INCBIN_U8("graphics/pokemon/dustox/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Dustox[] = INCBIN_U8("graphics/pokemon/dustox/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Dustox[] = INCBIN_COMP("graphics/pokemon/dustox/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Dustox[] = INCBIN_U32("graphics/pokemon/dustox/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Dustox[] = INCBIN_U32("graphics/pokemon/dustox/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_DustoxF[] = INCBIN_U32("graphics/pokemon/dustox/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_DustoxF[] = INCBIN_U32("graphics/pokemon/dustox/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_DustoxF[] = INCBIN_COMP("graphics/pokemon/dustox/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_WURMPLE

#if P_FAMILY_LOTAD
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Lotad[] = INCBIN_U32("graphics/pokemon/lotad/anim_front.4bpp.lz");
    const u32 gMonPalette_Lotad[] = INCBIN_U32("graphics/pokemon/lotad/normal.gbapal.lz");
    const u32 gMonBackPic_Lotad[] = INCBIN_U32("graphics/pokemon/lotad/back.4bpp.lz");
    const u32 gMonShinyPalette_Lotad[] = INCBIN_U32("graphics/pokemon/lotad/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Lotad[] = INCBIN_U32("graphics/pokemon/lotad/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Lotad[] = INCBIN_U32("graphics/pokemon/lotad/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Lotad[] = INCBIN_U32("graphics/pokemon/lotad/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Lotad[] = INCBIN_U32("graphics/pokemon/lotad/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Lotad[] = INCBIN_U8("graphics/pokemon/lotad/icon.4bpp");
#else
    const u8 gMonIcon_Lotad[] = INCBIN_U8("graphics/pokemon/lotad/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Lotad[] = INCBIN_U8("graphics/pokemon/lotad/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Lotad[] = INCBIN_COMP("graphics/pokemon/lotad/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Lotad[] = INCBIN_U32("graphics/pokemon/lotad/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Lotad[] = INCBIN_U32("graphics/pokemon/lotad/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Lombre[] = INCBIN_U32("graphics/pokemon/lombre/anim_front.4bpp.lz");
    const u32 gMonPalette_Lombre[] = INCBIN_U32("graphics/pokemon/lombre/normal.gbapal.lz");
    const u32 gMonBackPic_Lombre[] = INCBIN_U32("graphics/pokemon/lombre/back.4bpp.lz");
    const u32 gMonShinyPalette_Lombre[] = INCBIN_U32("graphics/pokemon/lombre/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Lombre[] = INCBIN_U32("graphics/pokemon/lombre/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Lombre[] = INCBIN_U32("graphics/pokemon/lombre/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Lombre[] = INCBIN_U32("graphics/pokemon/lombre/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Lombre[] = INCBIN_U32("graphics/pokemon/lombre/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Lombre[] = INCBIN_U8("graphics/pokemon/lombre/icon.4bpp");
#else
    const u8 gMonIcon_Lombre[] = INCBIN_U8("graphics/pokemon/lombre/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Lombre[] = INCBIN_U8("graphics/pokemon/lombre/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Lombre[] = INCBIN_COMP("graphics/pokemon/lombre/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Lombre[] = INCBIN_U32("graphics/pokemon/lombre/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Lombre[] = INCBIN_U32("graphics/pokemon/lombre/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Ludicolo[] = INCBIN_U32("graphics/pokemon/ludicolo/anim_front.4bpp.lz");
    const u32 gMonPalette_Ludicolo[] = INCBIN_U32("graphics/pokemon/ludicolo/normal.gbapal.lz");
    const u32 gMonBackPic_Ludicolo[] = INCBIN_U32("graphics/pokemon/ludicolo/back.4bpp.lz");
    const u32 gMonShinyPalette_Ludicolo[] = INCBIN_U32("graphics/pokemon/ludicolo/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Ludicolo[] = INCBIN_U32("graphics/pokemon/ludicolo/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Ludicolo[] = INCBIN_U32("graphics/pokemon/ludicolo/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Ludicolo[] = INCBIN_U32("graphics/pokemon/ludicolo/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Ludicolo[] = INCBIN_U32("graphics/pokemon/ludicolo/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Ludicolo[] = INCBIN_U8("graphics/pokemon/ludicolo/icon.4bpp");
#else
    const u8 gMonIcon_Ludicolo[] = INCBIN_U8("graphics/pokemon/ludicolo/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
#if !P_GBA_STYLE_SPECIES_FOOTPRINTS
    const u8 gMonFootprint_Ludicolo[] = INCBIN_U8("graphics/pokemon/ludicolo/footprint.1bpp");
#else
    const u8 gMonFootprint_Ludicolo[] = INCBIN_U8("graphics/pokemon/ludicolo/footprint_gba.1bpp");
#endif //P_GBA_STYLE_SPECIES_FOOTPRINTS
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Ludicolo[] = INCBIN_COMP("graphics/pokemon/ludicolo/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Ludicolo[] = INCBIN_U32("graphics/pokemon/ludicolo/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Ludicolo[] = INCBIN_U32("graphics/pokemon/ludicolo/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_LudicoloF[] = INCBIN_U32("graphics/pokemon/ludicolo/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_LudicoloF[] = INCBIN_U32("graphics/pokemon/ludicolo/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_LudicoloF[] = INCBIN_COMP("graphics/pokemon/ludicolo/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_LOTAD

#if P_FAMILY_SEEDOT
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Seedot[] = INCBIN_U32("graphics/pokemon/seedot/anim_front.4bpp.lz");
    const u32 gMonPalette_Seedot[] = INCBIN_U32("graphics/pokemon/seedot/normal.gbapal.lz");
    const u32 gMonBackPic_Seedot[] = INCBIN_U32("graphics/pokemon/seedot/back.4bpp.lz");
    const u32 gMonShinyPalette_Seedot[] = INCBIN_U32("graphics/pokemon/seedot/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Seedot[] = INCBIN_U32("graphics/pokemon/seedot/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Seedot[] = INCBIN_U32("graphics/pokemon/seedot/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Seedot[] = INCBIN_U32("graphics/pokemon/seedot/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Seedot[] = INCBIN_U32("graphics/pokemon/seedot/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Seedot[] = INCBIN_U8("graphics/pokemon/seedot/icon.4bpp");
#else
    const u8 gMonIcon_Seedot[] = INCBIN_U8("graphics/pokemon/seedot/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Seedot[] = INCBIN_U8("graphics/pokemon/seedot/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Seedot[] = INCBIN_COMP("graphics/pokemon/seedot/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Seedot[] = INCBIN_U32("graphics/pokemon/seedot/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Seedot[] = INCBIN_U32("graphics/pokemon/seedot/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Nuzleaf[] = INCBIN_U32("graphics/pokemon/nuzleaf/anim_front.4bpp.lz");
    const u32 gMonPalette_Nuzleaf[] = INCBIN_U32("graphics/pokemon/nuzleaf/normal.gbapal.lz");
    const u32 gMonBackPic_Nuzleaf[] = INCBIN_U32("graphics/pokemon/nuzleaf/back.4bpp.lz");
    const u32 gMonShinyPalette_Nuzleaf[] = INCBIN_U32("graphics/pokemon/nuzleaf/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Nuzleaf[] = INCBIN_U32("graphics/pokemon/nuzleaf/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Nuzleaf[] = INCBIN_U32("graphics/pokemon/nuzleaf/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Nuzleaf[] = INCBIN_U32("graphics/pokemon/nuzleaf/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Nuzleaf[] = INCBIN_U32("graphics/pokemon/nuzleaf/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Nuzleaf[] = INCBIN_U8("graphics/pokemon/nuzleaf/icon.4bpp");
#else
    const u8 gMonIcon_Nuzleaf[] = INCBIN_U8("graphics/pokemon/nuzleaf/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Nuzleaf[] = INCBIN_U8("graphics/pokemon/nuzleaf/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Nuzleaf[] = INCBIN_COMP("graphics/pokemon/nuzleaf/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Nuzleaf[] = INCBIN_U32("graphics/pokemon/nuzleaf/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Nuzleaf[] = INCBIN_U32("graphics/pokemon/nuzleaf/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_NuzleafF[] = INCBIN_U32("graphics/pokemon/nuzleaf/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_NuzleafF[] = INCBIN_U32("graphics/pokemon/nuzleaf/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_NuzleafF[] = INCBIN_COMP("graphics/pokemon/nuzleaf/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Shiftry[] = INCBIN_U32("graphics/pokemon/shiftry/anim_front.4bpp.lz");
    const u32 gMonPalette_Shiftry[] = INCBIN_U32("graphics/pokemon/shiftry/normal.gbapal.lz");
    const u32 gMonBackPic_Shiftry[] = INCBIN_U32("graphics/pokemon/shiftry/back.4bpp.lz");
    const u32 gMonShinyPalette_Shiftry[] = INCBIN_U32("graphics/pokemon/shiftry/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Shiftry[] = INCBIN_U32("graphics/pokemon/shiftry/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Shiftry[] = INCBIN_U32("graphics/pokemon/shiftry/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Shiftry[] = INCBIN_U32("graphics/pokemon/shiftry/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Shiftry[] = INCBIN_U32("graphics/pokemon/shiftry/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Shiftry[] = INCBIN_U8("graphics/pokemon/shiftry/icon.4bpp");
#else
    const u8 gMonIcon_Shiftry[] = INCBIN_U8("graphics/pokemon/shiftry/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Shiftry[] = INCBIN_U8("graphics/pokemon/shiftry/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Shiftry[] = INCBIN_COMP("graphics/pokemon/shiftry/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Shiftry[] = INCBIN_U32("graphics/pokemon/shiftry/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Shiftry[] = INCBIN_U32("graphics/pokemon/shiftry/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_ShiftryF[] = INCBIN_U32("graphics/pokemon/shiftry/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_ShiftryF[] = INCBIN_U32("graphics/pokemon/shiftry/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_ShiftryF[] = INCBIN_COMP("graphics/pokemon/shiftry/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_SEEDOT

#if P_FAMILY_TAILLOW
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Taillow[] = INCBIN_U32("graphics/pokemon/taillow/anim_front.4bpp.lz");
    const u32 gMonPalette_Taillow[] = INCBIN_U32("graphics/pokemon/taillow/normal.gbapal.lz");
    const u32 gMonBackPic_Taillow[] = INCBIN_U32("graphics/pokemon/taillow/back.4bpp.lz");
    const u32 gMonShinyPalette_Taillow[] = INCBIN_U32("graphics/pokemon/taillow/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Taillow[] = INCBIN_U32("graphics/pokemon/taillow/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Taillow[] = INCBIN_U32("graphics/pokemon/taillow/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Taillow[] = INCBIN_U32("graphics/pokemon/taillow/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Taillow[] = INCBIN_U32("graphics/pokemon/taillow/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Taillow[] = INCBIN_U8("graphics/pokemon/taillow/icon.4bpp");
#else
    const u8 gMonIcon_Taillow[] = INCBIN_U8("graphics/pokemon/taillow/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Taillow[] = INCBIN_U8("graphics/pokemon/taillow/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Taillow[] = INCBIN_COMP("graphics/pokemon/taillow/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Taillow[] = INCBIN_U32("graphics/pokemon/taillow/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Taillow[] = INCBIN_U32("graphics/pokemon/taillow/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Swellow[] = INCBIN_U32("graphics/pokemon/swellow/anim_front.4bpp.lz");
    const u32 gMonPalette_Swellow[] = INCBIN_U32("graphics/pokemon/swellow/normal.gbapal.lz");
    const u32 gMonBackPic_Swellow[] = INCBIN_U32("graphics/pokemon/swellow/back.4bpp.lz");
    const u32 gMonShinyPalette_Swellow[] = INCBIN_U32("graphics/pokemon/swellow/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Swellow[] = INCBIN_U32("graphics/pokemon/swellow/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Swellow[] = INCBIN_U32("graphics/pokemon/swellow/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Swellow[] = INCBIN_U32("graphics/pokemon/swellow/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Swellow[] = INCBIN_U32("graphics/pokemon/swellow/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Swellow[] = INCBIN_U8("graphics/pokemon/swellow/icon.4bpp");
#else
    const u8 gMonIcon_Swellow[] = INCBIN_U8("graphics/pokemon/swellow/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Swellow[] = INCBIN_U8("graphics/pokemon/swellow/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Swellow[] = INCBIN_COMP("graphics/pokemon/swellow/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Swellow[] = INCBIN_U32("graphics/pokemon/swellow/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Swellow[] = INCBIN_U32("graphics/pokemon/swellow/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_TAILLOW

#if P_FAMILY_WINGULL
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Wingull[] = INCBIN_U32("graphics/pokemon/wingull/anim_front.4bpp.lz");
    const u32 gMonPalette_Wingull[] = INCBIN_U32("graphics/pokemon/wingull/normal.gbapal.lz");
    const u32 gMonBackPic_Wingull[] = INCBIN_U32("graphics/pokemon/wingull/back.4bpp.lz");
    const u32 gMonShinyPalette_Wingull[] = INCBIN_U32("graphics/pokemon/wingull/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Wingull[] = INCBIN_U32("graphics/pokemon/wingull/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Wingull[] = INCBIN_U32("graphics/pokemon/wingull/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Wingull[] = INCBIN_U32("graphics/pokemon/wingull/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Wingull[] = INCBIN_U32("graphics/pokemon/wingull/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Wingull[] = INCBIN_U8("graphics/pokemon/wingull/icon.4bpp");
#else
    const u8 gMonIcon_Wingull[] = INCBIN_U8("graphics/pokemon/wingull/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Wingull[] = INCBIN_U8("graphics/pokemon/wingull/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Wingull[] = INCBIN_COMP("graphics/pokemon/wingull/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Wingull[] = INCBIN_U32("graphics/pokemon/wingull/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Wingull[] = INCBIN_U32("graphics/pokemon/wingull/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Pelipper[] = INCBIN_U32("graphics/pokemon/pelipper/anim_front.4bpp.lz");
    const u32 gMonPalette_Pelipper[] = INCBIN_U32("graphics/pokemon/pelipper/normal.gbapal.lz");
    const u32 gMonBackPic_Pelipper[] = INCBIN_U32("graphics/pokemon/pelipper/back.4bpp.lz");
    const u32 gMonShinyPalette_Pelipper[] = INCBIN_U32("graphics/pokemon/pelipper/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Pelipper[] = INCBIN_U32("graphics/pokemon/pelipper/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Pelipper[] = INCBIN_U32("graphics/pokemon/pelipper/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Pelipper[] = INCBIN_U32("graphics/pokemon/pelipper/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Pelipper[] = INCBIN_U32("graphics/pokemon/pelipper/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Pelipper[] = INCBIN_U8("graphics/pokemon/pelipper/icon.4bpp");
#else
    const u8 gMonIcon_Pelipper[] = INCBIN_U8("graphics/pokemon/pelipper/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Pelipper[] = INCBIN_U8("graphics/pokemon/pelipper/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Pelipper[] = INCBIN_COMP("graphics/pokemon/pelipper/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Pelipper[] = INCBIN_U32("graphics/pokemon/pelipper/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Pelipper[] = INCBIN_U32("graphics/pokemon/pelipper/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_WINGULL

#if P_FAMILY_RALTS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Ralts[] = INCBIN_U32("graphics/pokemon/ralts/anim_front.4bpp.lz");
    const u32 gMonPalette_Ralts[] = INCBIN_U32("graphics/pokemon/ralts/normal.gbapal.lz");
    const u32 gMonBackPic_Ralts[] = INCBIN_U32("graphics/pokemon/ralts/back.4bpp.lz");
    const u32 gMonShinyPalette_Ralts[] = INCBIN_U32("graphics/pokemon/ralts/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Ralts[] = INCBIN_U32("graphics/pokemon/ralts/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Ralts[] = INCBIN_U32("graphics/pokemon/ralts/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Ralts[] = INCBIN_U32("graphics/pokemon/ralts/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Ralts[] = INCBIN_U32("graphics/pokemon/ralts/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Ralts[] = INCBIN_U8("graphics/pokemon/ralts/icon.4bpp");
#else
    const u8 gMonIcon_Ralts[] = INCBIN_U8("graphics/pokemon/ralts/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Ralts[] = INCBIN_U8("graphics/pokemon/ralts/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Ralts[] = INCBIN_COMP("graphics/pokemon/ralts/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Ralts[] = INCBIN_U32("graphics/pokemon/ralts/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Ralts[] = INCBIN_U32("graphics/pokemon/ralts/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Kirlia[] = INCBIN_U32("graphics/pokemon/kirlia/anim_front.4bpp.lz");
    const u32 gMonPalette_Kirlia[] = INCBIN_U32("graphics/pokemon/kirlia/normal.gbapal.lz");
    const u32 gMonBackPic_Kirlia[] = INCBIN_U32("graphics/pokemon/kirlia/back.4bpp.lz");
    const u32 gMonShinyPalette_Kirlia[] = INCBIN_U32("graphics/pokemon/kirlia/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Kirlia[] = INCBIN_U32("graphics/pokemon/kirlia/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Kirlia[] = INCBIN_U32("graphics/pokemon/kirlia/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Kirlia[] = INCBIN_U32("graphics/pokemon/kirlia/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Kirlia[] = INCBIN_U32("graphics/pokemon/kirlia/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Kirlia[] = INCBIN_U8("graphics/pokemon/kirlia/icon.4bpp");
#else
    const u8 gMonIcon_Kirlia[] = INCBIN_U8("graphics/pokemon/kirlia/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Kirlia[] = INCBIN_U8("graphics/pokemon/kirlia/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Kirlia[] = INCBIN_COMP("graphics/pokemon/kirlia/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Kirlia[] = INCBIN_U32("graphics/pokemon/kirlia/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Kirlia[] = INCBIN_U32("graphics/pokemon/kirlia/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Gardevoir[] = INCBIN_U32("graphics/pokemon/gardevoir/anim_front.4bpp.lz");
    const u32 gMonPalette_Gardevoir[] = INCBIN_U32("graphics/pokemon/gardevoir/normal.gbapal.lz");
    const u32 gMonBackPic_Gardevoir[] = INCBIN_U32("graphics/pokemon/gardevoir/back.4bpp.lz");
    const u32 gMonShinyPalette_Gardevoir[] = INCBIN_U32("graphics/pokemon/gardevoir/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Gardevoir[] = INCBIN_U32("graphics/pokemon/gardevoir/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Gardevoir[] = INCBIN_U32("graphics/pokemon/gardevoir/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Gardevoir[] = INCBIN_U32("graphics/pokemon/gardevoir/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Gardevoir[] = INCBIN_U32("graphics/pokemon/gardevoir/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Gardevoir[] = INCBIN_U8("graphics/pokemon/gardevoir/icon.4bpp");
#else
    const u8 gMonIcon_Gardevoir[] = INCBIN_U8("graphics/pokemon/gardevoir/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Gardevoir[] = INCBIN_U8("graphics/pokemon/gardevoir/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Gardevoir[] = INCBIN_COMP("graphics/pokemon/gardevoir/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Gardevoir[] = INCBIN_U32("graphics/pokemon/gardevoir/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Gardevoir[] = INCBIN_U32("graphics/pokemon/gardevoir/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Gallade[] = INCBIN_U32("graphics/pokemon/gallade/anim_front.4bpp.lz");
    const u32 gMonPalette_Gallade[] = INCBIN_U32("graphics/pokemon/gallade/normal.gbapal.lz");
    const u32 gMonBackPic_Gallade[] = INCBIN_U32("graphics/pokemon/gallade/back.4bpp.lz");
    const u32 gMonShinyPalette_Gallade[] = INCBIN_U32("graphics/pokemon/gallade/shiny.gbapal.lz");
    const u8 gMonIcon_Gallade[] = INCBIN_U8("graphics/pokemon/gallade/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Gallade[] = INCBIN_U8("graphics/pokemon/gallade/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Gallade[] = INCBIN_COMP("graphics/pokemon/gallade/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Gallade[] = INCBIN_U32("graphics/pokemon/gallade/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Gallade[] = INCBIN_U32("graphics/pokemon/gallade/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_RALTS

#if P_FAMILY_SURSKIT
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Surskit[] = INCBIN_U32("graphics/pokemon/surskit/anim_front.4bpp.lz");
    const u32 gMonPalette_Surskit[] = INCBIN_U32("graphics/pokemon/surskit/normal.gbapal.lz");
    const u32 gMonBackPic_Surskit[] = INCBIN_U32("graphics/pokemon/surskit/back.4bpp.lz");
    const u32 gMonShinyPalette_Surskit[] = INCBIN_U32("graphics/pokemon/surskit/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Surskit[] = INCBIN_U32("graphics/pokemon/surskit/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Surskit[] = INCBIN_U32("graphics/pokemon/surskit/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Surskit[] = INCBIN_U32("graphics/pokemon/surskit/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Surskit[] = INCBIN_U32("graphics/pokemon/surskit/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Surskit[] = INCBIN_U8("graphics/pokemon/surskit/icon.4bpp");
#else
    const u8 gMonIcon_Surskit[] = INCBIN_U8("graphics/pokemon/surskit/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Surskit[] = INCBIN_U8("graphics/pokemon/surskit/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Surskit[] = INCBIN_COMP("graphics/pokemon/surskit/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Surskit[] = INCBIN_U32("graphics/pokemon/surskit/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Surskit[] = INCBIN_U32("graphics/pokemon/surskit/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Masquerain[] = INCBIN_U32("graphics/pokemon/masquerain/anim_front.4bpp.lz");
    const u32 gMonPalette_Masquerain[] = INCBIN_U32("graphics/pokemon/masquerain/normal.gbapal.lz");
    const u32 gMonBackPic_Masquerain[] = INCBIN_U32("graphics/pokemon/masquerain/back.4bpp.lz");
    const u32 gMonShinyPalette_Masquerain[] = INCBIN_U32("graphics/pokemon/masquerain/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Masquerain[] = INCBIN_U32("graphics/pokemon/masquerain/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Masquerain[] = INCBIN_U32("graphics/pokemon/masquerain/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Masquerain[] = INCBIN_U32("graphics/pokemon/masquerain/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Masquerain[] = INCBIN_U32("graphics/pokemon/masquerain/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Masquerain[] = INCBIN_U8("graphics/pokemon/masquerain/icon.4bpp");
#else
    const u8 gMonIcon_Masquerain[] = INCBIN_U8("graphics/pokemon/masquerain/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Masquerain[] = INCBIN_U8("graphics/pokemon/masquerain/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Masquerain[] = INCBIN_COMP("graphics/pokemon/masquerain/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Masquerain[] = INCBIN_U32("graphics/pokemon/masquerain/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Masquerain[] = INCBIN_U32("graphics/pokemon/masquerain/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SURSKIT

#if P_FAMILY_SHROOMISH
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Shroomish[] = INCBIN_U32("graphics/pokemon/shroomish/anim_front.4bpp.lz");
    const u32 gMonPalette_Shroomish[] = INCBIN_U32("graphics/pokemon/shroomish/normal.gbapal.lz");
    const u32 gMonBackPic_Shroomish[] = INCBIN_U32("graphics/pokemon/shroomish/back.4bpp.lz");
    const u32 gMonShinyPalette_Shroomish[] = INCBIN_U32("graphics/pokemon/shroomish/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Shroomish[] = INCBIN_U32("graphics/pokemon/shroomish/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Shroomish[] = INCBIN_U32("graphics/pokemon/shroomish/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Shroomish[] = INCBIN_U32("graphics/pokemon/shroomish/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Shroomish[] = INCBIN_U32("graphics/pokemon/shroomish/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Shroomish[] = INCBIN_U8("graphics/pokemon/shroomish/icon.4bpp");
#else
    const u8 gMonIcon_Shroomish[] = INCBIN_U8("graphics/pokemon/shroomish/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
#if !P_GBA_STYLE_SPECIES_FOOTPRINTS
    const u8 gMonFootprint_Shroomish[] = INCBIN_U8("graphics/pokemon/shroomish/footprint.1bpp");
#else
    const u8 gMonFootprint_Shroomish[] = INCBIN_U8("graphics/pokemon/shroomish/footprint_gba.1bpp");
#endif //P_GBA_STYLE_SPECIES_FOOTPRINTS
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Shroomish[] = INCBIN_COMP("graphics/pokemon/shroomish/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Shroomish[] = INCBIN_U32("graphics/pokemon/shroomish/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Shroomish[] = INCBIN_U32("graphics/pokemon/shroomish/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Breloom[] = INCBIN_U32("graphics/pokemon/breloom/anim_front.4bpp.lz");
    const u32 gMonPalette_Breloom[] = INCBIN_U32("graphics/pokemon/breloom/normal.gbapal.lz");
    const u32 gMonBackPic_Breloom[] = INCBIN_U32("graphics/pokemon/breloom/back.4bpp.lz");
    const u32 gMonShinyPalette_Breloom[] = INCBIN_U32("graphics/pokemon/breloom/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Breloom[] = INCBIN_U32("graphics/pokemon/breloom/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Breloom[] = INCBIN_U32("graphics/pokemon/breloom/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Breloom[] = INCBIN_U32("graphics/pokemon/breloom/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Breloom[] = INCBIN_U32("graphics/pokemon/breloom/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Breloom[] = INCBIN_U8("graphics/pokemon/breloom/icon.4bpp");
#else
    const u8 gMonIcon_Breloom[] = INCBIN_U8("graphics/pokemon/breloom/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Breloom[] = INCBIN_U8("graphics/pokemon/breloom/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Breloom[] = INCBIN_COMP("graphics/pokemon/breloom/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Breloom[] = INCBIN_U32("graphics/pokemon/breloom/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Breloom[] = INCBIN_U32("graphics/pokemon/breloom/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SHROOMISH

#if P_FAMILY_SLAKOTH
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Slakoth[] = INCBIN_U32("graphics/pokemon/slakoth/anim_front.4bpp.lz");
    const u32 gMonPalette_Slakoth[] = INCBIN_U32("graphics/pokemon/slakoth/normal.gbapal.lz");
    const u32 gMonBackPic_Slakoth[] = INCBIN_U32("graphics/pokemon/slakoth/back.4bpp.lz");
    const u32 gMonShinyPalette_Slakoth[] = INCBIN_U32("graphics/pokemon/slakoth/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Slakoth[] = INCBIN_U32("graphics/pokemon/slakoth/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Slakoth[] = INCBIN_U32("graphics/pokemon/slakoth/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Slakoth[] = INCBIN_U32("graphics/pokemon/slakoth/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Slakoth[] = INCBIN_U32("graphics/pokemon/slakoth/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Slakoth[] = INCBIN_U8("graphics/pokemon/slakoth/icon.4bpp");
#else
    const u8 gMonIcon_Slakoth[] = INCBIN_U8("graphics/pokemon/slakoth/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Slakoth[] = INCBIN_U8("graphics/pokemon/slakoth/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Slakoth[] = INCBIN_COMP("graphics/pokemon/slakoth/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Slakoth[] = INCBIN_U32("graphics/pokemon/slakoth/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Slakoth[] = INCBIN_U32("graphics/pokemon/slakoth/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Vigoroth[] = INCBIN_U32("graphics/pokemon/vigoroth/anim_front.4bpp.lz");
    const u32 gMonPalette_Vigoroth[] = INCBIN_U32("graphics/pokemon/vigoroth/normal.gbapal.lz");
    const u32 gMonBackPic_Vigoroth[] = INCBIN_U32("graphics/pokemon/vigoroth/back.4bpp.lz");
    const u32 gMonShinyPalette_Vigoroth[] = INCBIN_U32("graphics/pokemon/vigoroth/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Vigoroth[] = INCBIN_U32("graphics/pokemon/vigoroth/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Vigoroth[] = INCBIN_U32("graphics/pokemon/vigoroth/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Vigoroth[] = INCBIN_U32("graphics/pokemon/vigoroth/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Vigoroth[] = INCBIN_U32("graphics/pokemon/vigoroth/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Vigoroth[] = INCBIN_U8("graphics/pokemon/vigoroth/icon.4bpp");
#else
    const u8 gMonIcon_Vigoroth[] = INCBIN_U8("graphics/pokemon/vigoroth/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Vigoroth[] = INCBIN_U8("graphics/pokemon/vigoroth/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Vigoroth[] = INCBIN_COMP("graphics/pokemon/vigoroth/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Vigoroth[] = INCBIN_U32("graphics/pokemon/vigoroth/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Vigoroth[] = INCBIN_U32("graphics/pokemon/vigoroth/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Slaking[] = INCBIN_U32("graphics/pokemon/slaking/anim_front.4bpp.lz");
    const u32 gMonPalette_Slaking[] = INCBIN_U32("graphics/pokemon/slaking/normal.gbapal.lz");
    const u32 gMonBackPic_Slaking[] = INCBIN_U32("graphics/pokemon/slaking/back.4bpp.lz");
    const u32 gMonShinyPalette_Slaking[] = INCBIN_U32("graphics/pokemon/slaking/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Slaking[] = INCBIN_U32("graphics/pokemon/slaking/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Slaking[] = INCBIN_U32("graphics/pokemon/slaking/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Slaking[] = INCBIN_U32("graphics/pokemon/slaking/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Slaking[] = INCBIN_U32("graphics/pokemon/slaking/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Slaking[] = INCBIN_U8("graphics/pokemon/slaking/icon.4bpp");
#else
    const u8 gMonIcon_Slaking[] = INCBIN_U8("graphics/pokemon/slaking/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Slaking[] = INCBIN_U8("graphics/pokemon/slaking/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Slaking[] = INCBIN_COMP("graphics/pokemon/slaking/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Slaking[] = INCBIN_U32("graphics/pokemon/slaking/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Slaking[] = INCBIN_U32("graphics/pokemon/slaking/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SLAKOTH

#if P_FAMILY_NINCADA
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Nincada[] = INCBIN_U32("graphics/pokemon/nincada/anim_front.4bpp.lz");
    const u32 gMonPalette_Nincada[] = INCBIN_U32("graphics/pokemon/nincada/normal.gbapal.lz");
    const u32 gMonBackPic_Nincada[] = INCBIN_U32("graphics/pokemon/nincada/back.4bpp.lz");
    const u32 gMonShinyPalette_Nincada[] = INCBIN_U32("graphics/pokemon/nincada/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Nincada[] = INCBIN_U32("graphics/pokemon/nincada/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Nincada[] = INCBIN_U32("graphics/pokemon/nincada/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Nincada[] = INCBIN_U32("graphics/pokemon/nincada/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Nincada[] = INCBIN_U32("graphics/pokemon/nincada/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Nincada[] = INCBIN_U8("graphics/pokemon/nincada/icon.4bpp");
#else
    const u8 gMonIcon_Nincada[] = INCBIN_U8("graphics/pokemon/nincada/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Nincada[] = INCBIN_U8("graphics/pokemon/nincada/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Nincada[] = INCBIN_COMP("graphics/pokemon/nincada/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Nincada[] = INCBIN_U32("graphics/pokemon/nincada/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Nincada[] = INCBIN_U32("graphics/pokemon/nincada/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Ninjask[] = INCBIN_U32("graphics/pokemon/ninjask/anim_front.4bpp.lz");
    const u32 gMonPalette_Ninjask[] = INCBIN_U32("graphics/pokemon/ninjask/normal.gbapal.lz");
    const u32 gMonBackPic_Ninjask[] = INCBIN_U32("graphics/pokemon/ninjask/back.4bpp.lz");
    const u32 gMonShinyPalette_Ninjask[] = INCBIN_U32("graphics/pokemon/ninjask/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Ninjask[] = INCBIN_U32("graphics/pokemon/ninjask/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Ninjask[] = INCBIN_U32("graphics/pokemon/ninjask/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Ninjask[] = INCBIN_U32("graphics/pokemon/ninjask/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Ninjask[] = INCBIN_U32("graphics/pokemon/ninjask/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Ninjask[] = INCBIN_U8("graphics/pokemon/ninjask/icon.4bpp");
#else
    const u8 gMonIcon_Ninjask[] = INCBIN_U8("graphics/pokemon/ninjask/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Ninjask[] = INCBIN_U8("graphics/pokemon/ninjask/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Ninjask[] = INCBIN_COMP("graphics/pokemon/ninjask/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Ninjask[] = INCBIN_U32("graphics/pokemon/ninjask/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Ninjask[] = INCBIN_U32("graphics/pokemon/ninjask/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Shedinja[] = INCBIN_U32("graphics/pokemon/shedinja/anim_front.4bpp.lz");
    const u32 gMonPalette_Shedinja[] = INCBIN_U32("graphics/pokemon/shedinja/normal.gbapal.lz");
    const u32 gMonBackPic_Shedinja[] = INCBIN_U32("graphics/pokemon/shedinja/back.4bpp.lz");
    const u32 gMonShinyPalette_Shedinja[] = INCBIN_U32("graphics/pokemon/shedinja/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Shedinja[] = INCBIN_U32("graphics/pokemon/shedinja/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Shedinja[] = INCBIN_U32("graphics/pokemon/shedinja/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Shedinja[] = INCBIN_U32("graphics/pokemon/shedinja/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Shedinja[] = INCBIN_U32("graphics/pokemon/shedinja/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Shedinja[] = INCBIN_U8("graphics/pokemon/shedinja/icon.4bpp");
#else
    const u8 gMonIcon_Shedinja[] = INCBIN_U8("graphics/pokemon/shedinja/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Shedinja[] = INCBIN_U8("graphics/pokemon/shedinja/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Shedinja[] = INCBIN_COMP("graphics/pokemon/shedinja/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Shedinja[] = INCBIN_U32("graphics/pokemon/shedinja/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Shedinja[] = INCBIN_U32("graphics/pokemon/shedinja/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_NINCADA

#if P_FAMILY_WHISMUR
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Whismur[] = INCBIN_U32("graphics/pokemon/whismur/anim_front.4bpp.lz");
    const u32 gMonPalette_Whismur[] = INCBIN_U32("graphics/pokemon/whismur/normal.gbapal.lz");
    const u32 gMonBackPic_Whismur[] = INCBIN_U32("graphics/pokemon/whismur/back.4bpp.lz");
    const u32 gMonShinyPalette_Whismur[] = INCBIN_U32("graphics/pokemon/whismur/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Whismur[] = INCBIN_U32("graphics/pokemon/whismur/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Whismur[] = INCBIN_U32("graphics/pokemon/whismur/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Whismur[] = INCBIN_U32("graphics/pokemon/whismur/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Whismur[] = INCBIN_U32("graphics/pokemon/whismur/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Whismur[] = INCBIN_U8("graphics/pokemon/whismur/icon.4bpp");
#else
    const u8 gMonIcon_Whismur[] = INCBIN_U8("graphics/pokemon/whismur/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Whismur[] = INCBIN_U8("graphics/pokemon/whismur/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Whismur[] = INCBIN_COMP("graphics/pokemon/whismur/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Whismur[] = INCBIN_U32("graphics/pokemon/whismur/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Whismur[] = INCBIN_U32("graphics/pokemon/whismur/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Loudred[] = INCBIN_U32("graphics/pokemon/loudred/anim_front.4bpp.lz");
    const u32 gMonPalette_Loudred[] = INCBIN_U32("graphics/pokemon/loudred/normal.gbapal.lz");
    const u32 gMonBackPic_Loudred[] = INCBIN_U32("graphics/pokemon/loudred/back.4bpp.lz");
    const u32 gMonShinyPalette_Loudred[] = INCBIN_U32("graphics/pokemon/loudred/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Loudred[] = INCBIN_U32("graphics/pokemon/loudred/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Loudred[] = INCBIN_U32("graphics/pokemon/loudred/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Loudred[] = INCBIN_U32("graphics/pokemon/loudred/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Loudred[] = INCBIN_U32("graphics/pokemon/loudred/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Loudred[] = INCBIN_U8("graphics/pokemon/loudred/icon.4bpp");
#else
    const u8 gMonIcon_Loudred[] = INCBIN_U8("graphics/pokemon/loudred/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Loudred[] = INCBIN_U8("graphics/pokemon/loudred/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Loudred[] = INCBIN_COMP("graphics/pokemon/loudred/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Loudred[] = INCBIN_U32("graphics/pokemon/loudred/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Loudred[] = INCBIN_U32("graphics/pokemon/loudred/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Exploud[] = INCBIN_U32("graphics/pokemon/exploud/anim_front.4bpp.lz");
    const u32 gMonPalette_Exploud[] = INCBIN_U32("graphics/pokemon/exploud/normal.gbapal.lz");
    const u32 gMonBackPic_Exploud[] = INCBIN_U32("graphics/pokemon/exploud/back.4bpp.lz");
    const u32 gMonShinyPalette_Exploud[] = INCBIN_U32("graphics/pokemon/exploud/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Exploud[] = INCBIN_U32("graphics/pokemon/exploud/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Exploud[] = INCBIN_U32("graphics/pokemon/exploud/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Exploud[] = INCBIN_U32("graphics/pokemon/exploud/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Exploud[] = INCBIN_U32("graphics/pokemon/exploud/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Exploud[] = INCBIN_U8("graphics/pokemon/exploud/icon.4bpp");
#else
    const u8 gMonIcon_Exploud[] = INCBIN_U8("graphics/pokemon/exploud/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Exploud[] = INCBIN_U8("graphics/pokemon/exploud/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Exploud[] = INCBIN_COMP("graphics/pokemon/exploud/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Exploud[] = INCBIN_U32("graphics/pokemon/exploud/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Exploud[] = INCBIN_U32("graphics/pokemon/exploud/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_WHISMUR

#if P_FAMILY_MAKUHITA
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Makuhita[] = INCBIN_U32("graphics/pokemon/makuhita/anim_front.4bpp.lz");
    const u32 gMonPalette_Makuhita[] = INCBIN_U32("graphics/pokemon/makuhita/normal.gbapal.lz");
    const u32 gMonBackPic_Makuhita[] = INCBIN_U32("graphics/pokemon/makuhita/back.4bpp.lz");
    const u32 gMonShinyPalette_Makuhita[] = INCBIN_U32("graphics/pokemon/makuhita/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Makuhita[] = INCBIN_U32("graphics/pokemon/makuhita/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Makuhita[] = INCBIN_U32("graphics/pokemon/makuhita/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Makuhita[] = INCBIN_U32("graphics/pokemon/makuhita/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Makuhita[] = INCBIN_U32("graphics/pokemon/makuhita/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Makuhita[] = INCBIN_U8("graphics/pokemon/makuhita/icon.4bpp");
#else
    const u8 gMonIcon_Makuhita[] = INCBIN_U8("graphics/pokemon/makuhita/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Makuhita[] = INCBIN_U8("graphics/pokemon/makuhita/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Makuhita[] = INCBIN_COMP("graphics/pokemon/makuhita/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Makuhita[] = INCBIN_U32("graphics/pokemon/makuhita/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Makuhita[] = INCBIN_U32("graphics/pokemon/makuhita/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Hariyama[] = INCBIN_U32("graphics/pokemon/hariyama/anim_front.4bpp.lz");
    const u32 gMonPalette_Hariyama[] = INCBIN_U32("graphics/pokemon/hariyama/normal.gbapal.lz");
    const u32 gMonBackPic_Hariyama[] = INCBIN_U32("graphics/pokemon/hariyama/back.4bpp.lz");
    const u32 gMonShinyPalette_Hariyama[] = INCBIN_U32("graphics/pokemon/hariyama/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Hariyama[] = INCBIN_U32("graphics/pokemon/hariyama/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Hariyama[] = INCBIN_U32("graphics/pokemon/hariyama/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Hariyama[] = INCBIN_U32("graphics/pokemon/hariyama/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Hariyama[] = INCBIN_U32("graphics/pokemon/hariyama/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Hariyama[] = INCBIN_U8("graphics/pokemon/hariyama/icon.4bpp");
#else
    const u8 gMonIcon_Hariyama[] = INCBIN_U8("graphics/pokemon/hariyama/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Hariyama[] = INCBIN_U8("graphics/pokemon/hariyama/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Hariyama[] = INCBIN_COMP("graphics/pokemon/hariyama/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Hariyama[] = INCBIN_U32("graphics/pokemon/hariyama/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Hariyama[] = INCBIN_U32("graphics/pokemon/hariyama/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_MAKUHITA

#if P_FAMILY_NOSEPASS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Nosepass[] = INCBIN_U32("graphics/pokemon/nosepass/anim_front.4bpp.lz");
    const u32 gMonPalette_Nosepass[] = INCBIN_U32("graphics/pokemon/nosepass/normal.gbapal.lz");
    const u32 gMonBackPic_Nosepass[] = INCBIN_U32("graphics/pokemon/nosepass/back.4bpp.lz");
    const u32 gMonShinyPalette_Nosepass[] = INCBIN_U32("graphics/pokemon/nosepass/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Nosepass[] = INCBIN_U32("graphics/pokemon/nosepass/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Nosepass[] = INCBIN_U32("graphics/pokemon/nosepass/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Nosepass[] = INCBIN_U32("graphics/pokemon/nosepass/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Nosepass[] = INCBIN_U32("graphics/pokemon/nosepass/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Nosepass[] = INCBIN_U8("graphics/pokemon/nosepass/icon.4bpp");
#else
    const u8 gMonIcon_Nosepass[] = INCBIN_U8("graphics/pokemon/nosepass/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Nosepass[] = INCBIN_U8("graphics/pokemon/nosepass/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Nosepass[] = INCBIN_COMP("graphics/pokemon/nosepass/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Nosepass[] = INCBIN_U32("graphics/pokemon/nosepass/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Nosepass[] = INCBIN_U32("graphics/pokemon/nosepass/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Probopass[] = INCBIN_U32("graphics/pokemon/probopass/anim_front.4bpp.lz");
    const u32 gMonPalette_Probopass[] = INCBIN_U32("graphics/pokemon/probopass/normal.gbapal.lz");
    const u32 gMonBackPic_Probopass[] = INCBIN_U32("graphics/pokemon/probopass/back.4bpp.lz");
    const u32 gMonShinyPalette_Probopass[] = INCBIN_U32("graphics/pokemon/probopass/shiny.gbapal.lz");
    const u8 gMonIcon_Probopass[] = INCBIN_U8("graphics/pokemon/probopass/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Probopass[] = INCBIN_U8("graphics/pokemon/probopass/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Probopass[] = INCBIN_COMP("graphics/pokemon/probopass/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Probopass[] = INCBIN_U32("graphics/pokemon/probopass/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Probopass[] = INCBIN_U32("graphics/pokemon/probopass/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_NOSEPASS

#if P_FAMILY_SKITTY
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Skitty[] = INCBIN_U32("graphics/pokemon/skitty/anim_front.4bpp.lz");
    const u32 gMonPalette_Skitty[] = INCBIN_U32("graphics/pokemon/skitty/normal.gbapal.lz");
    const u32 gMonBackPic_Skitty[] = INCBIN_U32("graphics/pokemon/skitty/back.4bpp.lz");
    const u32 gMonShinyPalette_Skitty[] = INCBIN_U32("graphics/pokemon/skitty/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Skitty[] = INCBIN_U32("graphics/pokemon/skitty/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Skitty[] = INCBIN_U32("graphics/pokemon/skitty/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Skitty[] = INCBIN_U32("graphics/pokemon/skitty/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Skitty[] = INCBIN_U32("graphics/pokemon/skitty/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Skitty[] = INCBIN_U8("graphics/pokemon/skitty/icon.4bpp");
#else
    const u8 gMonIcon_Skitty[] = INCBIN_U8("graphics/pokemon/skitty/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Skitty[] = INCBIN_U8("graphics/pokemon/skitty/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Skitty[] = INCBIN_COMP("graphics/pokemon/skitty/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Skitty[] = INCBIN_U32("graphics/pokemon/skitty/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Skitty[] = INCBIN_U32("graphics/pokemon/skitty/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Delcatty[] = INCBIN_U32("graphics/pokemon/delcatty/anim_front.4bpp.lz");
    const u32 gMonPalette_Delcatty[] = INCBIN_U32("graphics/pokemon/delcatty/normal.gbapal.lz");
    const u32 gMonBackPic_Delcatty[] = INCBIN_U32("graphics/pokemon/delcatty/back.4bpp.lz");
    const u32 gMonShinyPalette_Delcatty[] = INCBIN_U32("graphics/pokemon/delcatty/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Delcatty[] = INCBIN_U32("graphics/pokemon/delcatty/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Delcatty[] = INCBIN_U32("graphics/pokemon/delcatty/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Delcatty[] = INCBIN_U32("graphics/pokemon/delcatty/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Delcatty[] = INCBIN_U32("graphics/pokemon/delcatty/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Delcatty[] = INCBIN_U8("graphics/pokemon/delcatty/icon.4bpp");
#else
    const u8 gMonIcon_Delcatty[] = INCBIN_U8("graphics/pokemon/delcatty/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Delcatty[] = INCBIN_U8("graphics/pokemon/delcatty/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Delcatty[] = INCBIN_COMP("graphics/pokemon/delcatty/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Delcatty[] = INCBIN_U32("graphics/pokemon/delcatty/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Delcatty[] = INCBIN_U32("graphics/pokemon/delcatty/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SKITTY

#if P_FAMILY_SABLEYE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Sableye[] = INCBIN_U32("graphics/pokemon/sableye/anim_front.4bpp.lz");
    const u32 gMonPalette_Sableye[] = INCBIN_U32("graphics/pokemon/sableye/normal.gbapal.lz");
    const u32 gMonBackPic_Sableye[] = INCBIN_U32("graphics/pokemon/sableye/back.4bpp.lz");
    const u32 gMonShinyPalette_Sableye[] = INCBIN_U32("graphics/pokemon/sableye/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Sableye[] = INCBIN_U32("graphics/pokemon/sableye/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Sableye[] = INCBIN_U32("graphics/pokemon/sableye/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Sableye[] = INCBIN_U32("graphics/pokemon/sableye/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Sableye[] = INCBIN_U32("graphics/pokemon/sableye/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Sableye[] = INCBIN_U8("graphics/pokemon/sableye/icon.4bpp");
#else
    const u8 gMonIcon_Sableye[] = INCBIN_U8("graphics/pokemon/sableye/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Sableye[] = INCBIN_U8("graphics/pokemon/sableye/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Sableye[] = INCBIN_COMP("graphics/pokemon/sableye/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Sableye[] = INCBIN_U32("graphics/pokemon/sableye/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Sableye[] = INCBIN_U32("graphics/pokemon/sableye/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SABLEYE

#if P_FAMILY_MAWILE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Mawile[] = INCBIN_U32("graphics/pokemon/mawile/anim_front.4bpp.lz");
    const u32 gMonPalette_Mawile[] = INCBIN_U32("graphics/pokemon/mawile/normal.gbapal.lz");
    const u32 gMonBackPic_Mawile[] = INCBIN_U32("graphics/pokemon/mawile/back.4bpp.lz");
    const u32 gMonShinyPalette_Mawile[] = INCBIN_U32("graphics/pokemon/mawile/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Mawile[] = INCBIN_U32("graphics/pokemon/mawile/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Mawile[] = INCBIN_U32("graphics/pokemon/mawile/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Mawile[] = INCBIN_U32("graphics/pokemon/mawile/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Mawile[] = INCBIN_U32("graphics/pokemon/mawile/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Mawile[] = INCBIN_U8("graphics/pokemon/mawile/icon.4bpp");
#else
    const u8 gMonIcon_Mawile[] = INCBIN_U8("graphics/pokemon/mawile/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
#if !P_GBA_STYLE_SPECIES_FOOTPRINTS
    const u8 gMonFootprint_Mawile[] = INCBIN_U8("graphics/pokemon/mawile/footprint.1bpp");
#else
    const u8 gMonFootprint_Mawile[] = INCBIN_U8("graphics/pokemon/mawile/footprint_gba.1bpp");
#endif //P_GBA_STYLE_SPECIES_FOOTPRINTS
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Mawile[] = INCBIN_COMP("graphics/pokemon/mawile/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Mawile[] = INCBIN_U32("graphics/pokemon/mawile/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Mawile[] = INCBIN_U32("graphics/pokemon/mawile/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_MAWILE

#if P_FAMILY_ARON
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Aron[] = INCBIN_U32("graphics/pokemon/aron/anim_front.4bpp.lz");
    const u32 gMonPalette_Aron[] = INCBIN_U32("graphics/pokemon/aron/normal.gbapal.lz");
    const u32 gMonBackPic_Aron[] = INCBIN_U32("graphics/pokemon/aron/back.4bpp.lz");
    const u32 gMonShinyPalette_Aron[] = INCBIN_U32("graphics/pokemon/aron/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Aron[] = INCBIN_U32("graphics/pokemon/aron/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Aron[] = INCBIN_U32("graphics/pokemon/aron/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Aron[] = INCBIN_U32("graphics/pokemon/aron/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Aron[] = INCBIN_U32("graphics/pokemon/aron/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Aron[] = INCBIN_U8("graphics/pokemon/aron/icon.4bpp");
#else
    const u8 gMonIcon_Aron[] = INCBIN_U8("graphics/pokemon/aron/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Aron[] = INCBIN_U8("graphics/pokemon/aron/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Aron[] = INCBIN_COMP("graphics/pokemon/aron/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Aron[] = INCBIN_U32("graphics/pokemon/aron/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Aron[] = INCBIN_U32("graphics/pokemon/aron/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Lairon[] = INCBIN_U32("graphics/pokemon/lairon/anim_front.4bpp.lz");
    const u32 gMonPalette_Lairon[] = INCBIN_U32("graphics/pokemon/lairon/normal.gbapal.lz");
    const u32 gMonBackPic_Lairon[] = INCBIN_U32("graphics/pokemon/lairon/back.4bpp.lz");
    const u32 gMonShinyPalette_Lairon[] = INCBIN_U32("graphics/pokemon/lairon/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Lairon[] = INCBIN_U32("graphics/pokemon/lairon/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Lairon[] = INCBIN_U32("graphics/pokemon/lairon/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Lairon[] = INCBIN_U32("graphics/pokemon/lairon/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Lairon[] = INCBIN_U32("graphics/pokemon/lairon/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Lairon[] = INCBIN_U8("graphics/pokemon/lairon/icon.4bpp");
#else
    const u8 gMonIcon_Lairon[] = INCBIN_U8("graphics/pokemon/lairon/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Lairon[] = INCBIN_U8("graphics/pokemon/lairon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Lairon[] = INCBIN_COMP("graphics/pokemon/lairon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Lairon[] = INCBIN_U32("graphics/pokemon/lairon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Lairon[] = INCBIN_U32("graphics/pokemon/lairon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Aggron[] = INCBIN_U32("graphics/pokemon/aggron/anim_front.4bpp.lz");
    const u32 gMonPalette_Aggron[] = INCBIN_U32("graphics/pokemon/aggron/normal.gbapal.lz");
    const u32 gMonBackPic_Aggron[] = INCBIN_U32("graphics/pokemon/aggron/back.4bpp.lz");
    const u32 gMonShinyPalette_Aggron[] = INCBIN_U32("graphics/pokemon/aggron/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Aggron[] = INCBIN_U32("graphics/pokemon/aggron/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Aggron[] = INCBIN_U32("graphics/pokemon/aggron/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Aggron[] = INCBIN_U32("graphics/pokemon/aggron/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Aggron[] = INCBIN_U32("graphics/pokemon/aggron/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Aggron[] = INCBIN_U8("graphics/pokemon/aggron/icon.4bpp");
#else
    const u8 gMonIcon_Aggron[] = INCBIN_U8("graphics/pokemon/aggron/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Aggron[] = INCBIN_U8("graphics/pokemon/aggron/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Aggron[] = INCBIN_COMP("graphics/pokemon/aggron/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Aggron[] = INCBIN_U32("graphics/pokemon/aggron/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Aggron[] = INCBIN_U32("graphics/pokemon/aggron/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_ARON

#if P_FAMILY_MEDITITE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Meditite[] = INCBIN_U32("graphics/pokemon/meditite/anim_front.4bpp.lz");
    const u32 gMonPalette_Meditite[] = INCBIN_U32("graphics/pokemon/meditite/normal.gbapal.lz");
    const u32 gMonBackPic_Meditite[] = INCBIN_U32("graphics/pokemon/meditite/back.4bpp.lz");
    const u32 gMonShinyPalette_Meditite[] = INCBIN_U32("graphics/pokemon/meditite/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Meditite[] = INCBIN_U32("graphics/pokemon/meditite/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Meditite[] = INCBIN_U32("graphics/pokemon/meditite/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Meditite[] = INCBIN_U32("graphics/pokemon/meditite/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Meditite[] = INCBIN_U32("graphics/pokemon/meditite/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Meditite[] = INCBIN_U8("graphics/pokemon/meditite/icon.4bpp");
#else
    const u8 gMonIcon_Meditite[] = INCBIN_U8("graphics/pokemon/meditite/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Meditite[] = INCBIN_U8("graphics/pokemon/meditite/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Meditite[] = INCBIN_COMP("graphics/pokemon/meditite/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Meditite[] = INCBIN_U32("graphics/pokemon/meditite/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Meditite[] = INCBIN_U32("graphics/pokemon/meditite/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_MedititeF[] = INCBIN_U32("graphics/pokemon/meditite/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_MedititeF[] = INCBIN_U32("graphics/pokemon/meditite/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_MedititeF[] = INCBIN_COMP("graphics/pokemon/meditite/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Medicham[] = INCBIN_U32("graphics/pokemon/medicham/anim_front.4bpp.lz");
    const u32 gMonPalette_Medicham[] = INCBIN_U32("graphics/pokemon/medicham/normal.gbapal.lz");
    const u32 gMonBackPic_Medicham[] = INCBIN_U32("graphics/pokemon/medicham/back.4bpp.lz");
    const u32 gMonShinyPalette_Medicham[] = INCBIN_U32("graphics/pokemon/medicham/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Medicham[] = INCBIN_U32("graphics/pokemon/medicham/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Medicham[] = INCBIN_U32("graphics/pokemon/medicham/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Medicham[] = INCBIN_U32("graphics/pokemon/medicham/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Medicham[] = INCBIN_U32("graphics/pokemon/medicham/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Medicham[] = INCBIN_U8("graphics/pokemon/medicham/icon.4bpp");
#else
    const u8 gMonIcon_Medicham[] = INCBIN_U8("graphics/pokemon/medicham/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Medicham[] = INCBIN_U8("graphics/pokemon/medicham/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Medicham[] = INCBIN_COMP("graphics/pokemon/medicham/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Medicham[] = INCBIN_U32("graphics/pokemon/medicham/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Medicham[] = INCBIN_U32("graphics/pokemon/medicham/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_MedichamF[] = INCBIN_U32("graphics/pokemon/medicham/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_MedichamF[] = INCBIN_U32("graphics/pokemon/medicham/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_MedichamF[] = INCBIN_COMP("graphics/pokemon/medicham/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_MEDITITE

#if P_FAMILY_ELECTRIKE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Electrike[] = INCBIN_U32("graphics/pokemon/electrike/anim_front.4bpp.lz");
    const u32 gMonPalette_Electrike[] = INCBIN_U32("graphics/pokemon/electrike/normal.gbapal.lz");
    const u32 gMonBackPic_Electrike[] = INCBIN_U32("graphics/pokemon/electrike/back.4bpp.lz");
    const u32 gMonShinyPalette_Electrike[] = INCBIN_U32("graphics/pokemon/electrike/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Electrike[] = INCBIN_U32("graphics/pokemon/electrike/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Electrike[] = INCBIN_U32("graphics/pokemon/electrike/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Electrike[] = INCBIN_U32("graphics/pokemon/electrike/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Electrike[] = INCBIN_U32("graphics/pokemon/electrike/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Electrike[] = INCBIN_U8("graphics/pokemon/electrike/icon.4bpp");
#else
    const u8 gMonIcon_Electrike[] = INCBIN_U8("graphics/pokemon/electrike/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Electrike[] = INCBIN_U8("graphics/pokemon/electrike/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Electrike[] = INCBIN_COMP("graphics/pokemon/electrike/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Electrike[] = INCBIN_U32("graphics/pokemon/electrike/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Electrike[] = INCBIN_U32("graphics/pokemon/electrike/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Manectric[] = INCBIN_U32("graphics/pokemon/manectric/anim_front.4bpp.lz");
    const u32 gMonPalette_Manectric[] = INCBIN_U32("graphics/pokemon/manectric/normal.gbapal.lz");
    const u32 gMonBackPic_Manectric[] = INCBIN_U32("graphics/pokemon/manectric/back.4bpp.lz");
    const u32 gMonShinyPalette_Manectric[] = INCBIN_U32("graphics/pokemon/manectric/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Manectric[] = INCBIN_U32("graphics/pokemon/manectric/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Manectric[] = INCBIN_U32("graphics/pokemon/manectric/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Manectric[] = INCBIN_U32("graphics/pokemon/manectric/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Manectric[] = INCBIN_U32("graphics/pokemon/manectric/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Manectric[] = INCBIN_U8("graphics/pokemon/manectric/icon.4bpp");
#else
    const u8 gMonIcon_Manectric[] = INCBIN_U8("graphics/pokemon/manectric/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Manectric[] = INCBIN_U8("graphics/pokemon/manectric/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Manectric[] = INCBIN_COMP("graphics/pokemon/manectric/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Manectric[] = INCBIN_U32("graphics/pokemon/manectric/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Manectric[] = INCBIN_U32("graphics/pokemon/manectric/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_ELECTRIKE

#if P_FAMILY_PLUSLE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Plusle[] = INCBIN_U32("graphics/pokemon/plusle/anim_front.4bpp.lz");
    const u32 gMonPalette_Plusle[] = INCBIN_U32("graphics/pokemon/plusle/normal.gbapal.lz");
    const u32 gMonBackPic_Plusle[] = INCBIN_U32("graphics/pokemon/plusle/back.4bpp.lz");
    const u32 gMonShinyPalette_Plusle[] = INCBIN_U32("graphics/pokemon/plusle/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Plusle[] = INCBIN_U32("graphics/pokemon/plusle/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Plusle[] = INCBIN_U32("graphics/pokemon/plusle/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Plusle[] = INCBIN_U32("graphics/pokemon/plusle/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Plusle[] = INCBIN_U32("graphics/pokemon/plusle/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Plusle[] = INCBIN_U8("graphics/pokemon/plusle/icon.4bpp");
#else
    const u8 gMonIcon_Plusle[] = INCBIN_U8("graphics/pokemon/plusle/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Plusle[] = INCBIN_U8("graphics/pokemon/plusle/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Plusle[] = INCBIN_COMP("graphics/pokemon/plusle/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Plusle[] = INCBIN_U32("graphics/pokemon/plusle/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Plusle[] = INCBIN_U32("graphics/pokemon/plusle/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_PLUSLE

#if P_FAMILY_MINUN
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Minun[] = INCBIN_U32("graphics/pokemon/minun/anim_front.4bpp.lz");
    const u32 gMonPalette_Minun[] = INCBIN_U32("graphics/pokemon/minun/normal.gbapal.lz");
    const u32 gMonBackPic_Minun[] = INCBIN_U32("graphics/pokemon/minun/back.4bpp.lz");
    const u32 gMonShinyPalette_Minun[] = INCBIN_U32("graphics/pokemon/minun/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Minun[] = INCBIN_U32("graphics/pokemon/minun/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Minun[] = INCBIN_U32("graphics/pokemon/minun/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Minun[] = INCBIN_U32("graphics/pokemon/minun/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Minun[] = INCBIN_U32("graphics/pokemon/minun/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Minun[] = INCBIN_U8("graphics/pokemon/minun/icon.4bpp");
#else
    const u8 gMonIcon_Minun[] = INCBIN_U8("graphics/pokemon/minun/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Minun[] = INCBIN_U8("graphics/pokemon/minun/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Minun[] = INCBIN_COMP("graphics/pokemon/minun/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Minun[] = INCBIN_U32("graphics/pokemon/minun/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Minun[] = INCBIN_U32("graphics/pokemon/minun/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_MINUN

#if P_FAMILY_VOLBEAT_ILLUMISE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Volbeat[] = INCBIN_U32("graphics/pokemon/volbeat/anim_front.4bpp.lz");
    const u32 gMonPalette_Volbeat[] = INCBIN_U32("graphics/pokemon/volbeat/normal.gbapal.lz");
    const u32 gMonBackPic_Volbeat[] = INCBIN_U32("graphics/pokemon/volbeat/back.4bpp.lz");
    const u32 gMonShinyPalette_Volbeat[] = INCBIN_U32("graphics/pokemon/volbeat/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Volbeat[] = INCBIN_U32("graphics/pokemon/volbeat/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Volbeat[] = INCBIN_U32("graphics/pokemon/volbeat/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Volbeat[] = INCBIN_U32("graphics/pokemon/volbeat/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Volbeat[] = INCBIN_U32("graphics/pokemon/volbeat/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Volbeat[] = INCBIN_U8("graphics/pokemon/volbeat/icon.4bpp");
#else
    const u8 gMonIcon_Volbeat[] = INCBIN_U8("graphics/pokemon/volbeat/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Volbeat[] = INCBIN_U8("graphics/pokemon/volbeat/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Volbeat[] = INCBIN_COMP("graphics/pokemon/volbeat/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Volbeat[] = INCBIN_U32("graphics/pokemon/volbeat/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Volbeat[] = INCBIN_U32("graphics/pokemon/volbeat/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Illumise[] = INCBIN_U32("graphics/pokemon/illumise/anim_front.4bpp.lz");
    const u32 gMonPalette_Illumise[] = INCBIN_U32("graphics/pokemon/illumise/normal.gbapal.lz");
    const u32 gMonBackPic_Illumise[] = INCBIN_U32("graphics/pokemon/illumise/back.4bpp.lz");
    const u32 gMonShinyPalette_Illumise[] = INCBIN_U32("graphics/pokemon/illumise/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Illumise[] = INCBIN_U32("graphics/pokemon/illumise/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Illumise[] = INCBIN_U32("graphics/pokemon/illumise/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Illumise[] = INCBIN_U32("graphics/pokemon/illumise/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Illumise[] = INCBIN_U32("graphics/pokemon/illumise/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Illumise[] = INCBIN_U8("graphics/pokemon/illumise/icon.4bpp");
#else
    const u8 gMonIcon_Illumise[] = INCBIN_U8("graphics/pokemon/illumise/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Illumise[] = INCBIN_U8("graphics/pokemon/illumise/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Illumise[] = INCBIN_COMP("graphics/pokemon/illumise/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Illumise[] = INCBIN_U32("graphics/pokemon/illumise/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Illumise[] = INCBIN_U32("graphics/pokemon/illumise/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_VOLBEAT_ILLUMISE

#if P_FAMILY_ROSELIA
#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Budew[] = INCBIN_U32("graphics/pokemon/budew/anim_front.4bpp.lz");
    const u32 gMonPalette_Budew[] = INCBIN_U32("graphics/pokemon/budew/normal.gbapal.lz");
    const u32 gMonBackPic_Budew[] = INCBIN_U32("graphics/pokemon/budew/back.4bpp.lz");
    const u32 gMonShinyPalette_Budew[] = INCBIN_U32("graphics/pokemon/budew/shiny.gbapal.lz");
    const u8 gMonIcon_Budew[] = INCBIN_U8("graphics/pokemon/budew/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Budew[] = INCBIN_U8("graphics/pokemon/budew/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Budew[] = INCBIN_COMP("graphics/pokemon/budew/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Budew[] = INCBIN_U32("graphics/pokemon/budew/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Budew[] = INCBIN_U32("graphics/pokemon/budew/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_4_CROSS_EVOS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Roselia[] = INCBIN_U32("graphics/pokemon/roselia/anim_front.4bpp.lz");
    const u32 gMonPalette_Roselia[] = INCBIN_U32("graphics/pokemon/roselia/normal.gbapal.lz");
    const u32 gMonBackPic_Roselia[] = INCBIN_U32("graphics/pokemon/roselia/back.4bpp.lz");
    const u32 gMonShinyPalette_Roselia[] = INCBIN_U32("graphics/pokemon/roselia/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Roselia[] = INCBIN_U32("graphics/pokemon/roselia/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Roselia[] = INCBIN_U32("graphics/pokemon/roselia/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Roselia[] = INCBIN_U32("graphics/pokemon/roselia/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Roselia[] = INCBIN_U32("graphics/pokemon/roselia/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Roselia[] = INCBIN_U8("graphics/pokemon/roselia/icon.4bpp");
#else
    const u8 gMonIcon_Roselia[] = INCBIN_U8("graphics/pokemon/roselia/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Roselia[] = INCBIN_U8("graphics/pokemon/roselia/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Roselia[] = INCBIN_COMP("graphics/pokemon/roselia/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Roselia[] = INCBIN_U32("graphics/pokemon/roselia/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Roselia[] = INCBIN_U32("graphics/pokemon/roselia/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_RoseliaF[] = INCBIN_U32("graphics/pokemon/roselia/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_RoseliaF[] = INCBIN_U32("graphics/pokemon/roselia/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_RoseliaF[] = INCBIN_COMP("graphics/pokemon/roselia/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Roserade[] = INCBIN_U32("graphics/pokemon/roserade/anim_front.4bpp.lz");
    const u32 gMonPalette_Roserade[] = INCBIN_U32("graphics/pokemon/roserade/normal.gbapal.lz");
    const u32 gMonBackPic_Roserade[] = INCBIN_U32("graphics/pokemon/roserade/back.4bpp.lz");
    const u32 gMonShinyPalette_Roserade[] = INCBIN_U32("graphics/pokemon/roserade/shiny.gbapal.lz");
    const u8 gMonIcon_Roserade[] = INCBIN_U8("graphics/pokemon/roserade/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Roserade[] = INCBIN_U8("graphics/pokemon/roserade/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Roserade[] = INCBIN_COMP("graphics/pokemon/roserade/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Roserade[] = INCBIN_U32("graphics/pokemon/roserade/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Roserade[] = INCBIN_U32("graphics/pokemon/roserade/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_RoseradeF[] = INCBIN_U32("graphics/pokemon/roserade/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_RoseradeF[] = INCBIN_U32("graphics/pokemon/roserade/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_RoseradeF[] = INCBIN_COMP("graphics/pokemon/roserade/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_ROSELIA

#if P_FAMILY_GULPIN
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Gulpin[] = INCBIN_U32("graphics/pokemon/gulpin/anim_front.4bpp.lz");
    const u32 gMonPalette_Gulpin[] = INCBIN_U32("graphics/pokemon/gulpin/normal.gbapal.lz");
    const u32 gMonBackPic_Gulpin[] = INCBIN_U32("graphics/pokemon/gulpin/back.4bpp.lz");
    const u32 gMonShinyPalette_Gulpin[] = INCBIN_U32("graphics/pokemon/gulpin/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Gulpin[] = INCBIN_U32("graphics/pokemon/gulpin/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Gulpin[] = INCBIN_U32("graphics/pokemon/gulpin/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Gulpin[] = INCBIN_U32("graphics/pokemon/gulpin/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Gulpin[] = INCBIN_U32("graphics/pokemon/gulpin/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Gulpin[] = INCBIN_U8("graphics/pokemon/gulpin/icon.4bpp");
#else
    const u8 gMonIcon_Gulpin[] = INCBIN_U8("graphics/pokemon/gulpin/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Gulpin[] = INCBIN_U8("graphics/pokemon/gulpin/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Gulpin[] = INCBIN_COMP("graphics/pokemon/gulpin/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Gulpin[] = INCBIN_U32("graphics/pokemon/gulpin/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Gulpin[] = INCBIN_U32("graphics/pokemon/gulpin/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_GulpinF[] = INCBIN_U32("graphics/pokemon/gulpin/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_GulpinF[] = INCBIN_U32("graphics/pokemon/gulpin/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_GulpinF[] = INCBIN_COMP("graphics/pokemon/gulpin/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Swalot[] = INCBIN_U32("graphics/pokemon/swalot/anim_front.4bpp.lz");
    const u32 gMonPalette_Swalot[] = INCBIN_U32("graphics/pokemon/swalot/normal.gbapal.lz");
    const u32 gMonBackPic_Swalot[] = INCBIN_U32("graphics/pokemon/swalot/back.4bpp.lz");
    const u32 gMonShinyPalette_Swalot[] = INCBIN_U32("graphics/pokemon/swalot/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Swalot[] = INCBIN_U32("graphics/pokemon/swalot/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Swalot[] = INCBIN_U32("graphics/pokemon/swalot/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Swalot[] = INCBIN_U32("graphics/pokemon/swalot/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Swalot[] = INCBIN_U32("graphics/pokemon/swalot/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Swalot[] = INCBIN_U8("graphics/pokemon/swalot/icon.4bpp");
#else
    const u8 gMonIcon_Swalot[] = INCBIN_U8("graphics/pokemon/swalot/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Swalot[] = INCBIN_U8("graphics/pokemon/swalot/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Swalot[] = INCBIN_COMP("graphics/pokemon/swalot/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Swalot[] = INCBIN_U32("graphics/pokemon/swalot/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Swalot[] = INCBIN_U32("graphics/pokemon/swalot/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_SwalotF[] = INCBIN_U32("graphics/pokemon/swalot/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_SwalotF[] = INCBIN_U32("graphics/pokemon/swalot/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_SwalotF[] = INCBIN_COMP("graphics/pokemon/swalot/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_GULPIN

#if P_FAMILY_CARVANHA
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Carvanha[] = INCBIN_U32("graphics/pokemon/carvanha/anim_front.4bpp.lz");
    const u32 gMonPalette_Carvanha[] = INCBIN_U32("graphics/pokemon/carvanha/normal.gbapal.lz");
    const u32 gMonBackPic_Carvanha[] = INCBIN_U32("graphics/pokemon/carvanha/back.4bpp.lz");
    const u32 gMonShinyPalette_Carvanha[] = INCBIN_U32("graphics/pokemon/carvanha/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Carvanha[] = INCBIN_U32("graphics/pokemon/carvanha/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Carvanha[] = INCBIN_U32("graphics/pokemon/carvanha/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Carvanha[] = INCBIN_U32("graphics/pokemon/carvanha/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Carvanha[] = INCBIN_U32("graphics/pokemon/carvanha/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Carvanha[] = INCBIN_U8("graphics/pokemon/carvanha/icon.4bpp");
#else
    const u8 gMonIcon_Carvanha[] = INCBIN_U8("graphics/pokemon/carvanha/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Carvanha[] = INCBIN_U8("graphics/pokemon/carvanha/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Carvanha[] = INCBIN_COMP("graphics/pokemon/carvanha/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Carvanha[] = INCBIN_U32("graphics/pokemon/carvanha/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Carvanha[] = INCBIN_U32("graphics/pokemon/carvanha/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Sharpedo[] = INCBIN_U32("graphics/pokemon/sharpedo/anim_front.4bpp.lz");
    const u32 gMonPalette_Sharpedo[] = INCBIN_U32("graphics/pokemon/sharpedo/normal.gbapal.lz");
    const u32 gMonBackPic_Sharpedo[] = INCBIN_U32("graphics/pokemon/sharpedo/back.4bpp.lz");
    const u32 gMonShinyPalette_Sharpedo[] = INCBIN_U32("graphics/pokemon/sharpedo/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Sharpedo[] = INCBIN_U32("graphics/pokemon/sharpedo/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Sharpedo[] = INCBIN_U32("graphics/pokemon/sharpedo/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Sharpedo[] = INCBIN_U32("graphics/pokemon/sharpedo/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Sharpedo[] = INCBIN_U32("graphics/pokemon/sharpedo/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Sharpedo[] = INCBIN_U8("graphics/pokemon/sharpedo/icon.4bpp");
#else
    const u8 gMonIcon_Sharpedo[] = INCBIN_U8("graphics/pokemon/sharpedo/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Sharpedo[] = INCBIN_U8("graphics/pokemon/sharpedo/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Sharpedo[] = INCBIN_COMP("graphics/pokemon/sharpedo/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Sharpedo[] = INCBIN_U32("graphics/pokemon/sharpedo/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Sharpedo[] = INCBIN_U32("graphics/pokemon/sharpedo/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_CARVANHA

#if P_FAMILY_WAILMER
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Wailmer[] = INCBIN_U32("graphics/pokemon/wailmer/anim_front.4bpp.lz");
    const u32 gMonPalette_Wailmer[] = INCBIN_U32("graphics/pokemon/wailmer/normal.gbapal.lz");
    const u32 gMonBackPic_Wailmer[] = INCBIN_U32("graphics/pokemon/wailmer/back.4bpp.lz");
    const u32 gMonShinyPalette_Wailmer[] = INCBIN_U32("graphics/pokemon/wailmer/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Wailmer[] = INCBIN_U32("graphics/pokemon/wailmer/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Wailmer[] = INCBIN_U32("graphics/pokemon/wailmer/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Wailmer[] = INCBIN_U32("graphics/pokemon/wailmer/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Wailmer[] = INCBIN_U32("graphics/pokemon/wailmer/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Wailmer[] = INCBIN_U8("graphics/pokemon/wailmer/icon.4bpp");
#else
    const u8 gMonIcon_Wailmer[] = INCBIN_U8("graphics/pokemon/wailmer/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Wailmer[] = INCBIN_U8("graphics/pokemon/wailmer/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Wailmer[] = INCBIN_COMP("graphics/pokemon/wailmer/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Wailmer[] = INCBIN_U32("graphics/pokemon/wailmer/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Wailmer[] = INCBIN_U32("graphics/pokemon/wailmer/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Wailord[] = INCBIN_U32("graphics/pokemon/wailord/anim_front.4bpp.lz");
    const u32 gMonPalette_Wailord[] = INCBIN_U32("graphics/pokemon/wailord/normal.gbapal.lz");
    const u32 gMonBackPic_Wailord[] = INCBIN_U32("graphics/pokemon/wailord/back.4bpp.lz");
    const u32 gMonShinyPalette_Wailord[] = INCBIN_U32("graphics/pokemon/wailord/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Wailord[] = INCBIN_U32("graphics/pokemon/wailord/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Wailord[] = INCBIN_U32("graphics/pokemon/wailord/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Wailord[] = INCBIN_U32("graphics/pokemon/wailord/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Wailord[] = INCBIN_U32("graphics/pokemon/wailord/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Wailord[] = INCBIN_U8("graphics/pokemon/wailord/icon.4bpp");
#else
    const u8 gMonIcon_Wailord[] = INCBIN_U8("graphics/pokemon/wailord/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Wailord[] = INCBIN_U8("graphics/pokemon/wailord/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Wailord[] = INCBIN_COMP("graphics/pokemon/wailord/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Wailord[] = INCBIN_U32("graphics/pokemon/wailord/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Wailord[] = INCBIN_U32("graphics/pokemon/wailord/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_WAILMER

#if P_FAMILY_NUMEL
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Numel[] = INCBIN_U32("graphics/pokemon/numel/anim_front.4bpp.lz");
    const u32 gMonPalette_Numel[] = INCBIN_U32("graphics/pokemon/numel/normal.gbapal.lz");
    const u32 gMonBackPic_Numel[] = INCBIN_U32("graphics/pokemon/numel/back.4bpp.lz");
    const u32 gMonShinyPalette_Numel[] = INCBIN_U32("graphics/pokemon/numel/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Numel[] = INCBIN_U32("graphics/pokemon/numel/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Numel[] = INCBIN_U32("graphics/pokemon/numel/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Numel[] = INCBIN_U32("graphics/pokemon/numel/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Numel[] = INCBIN_U32("graphics/pokemon/numel/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Numel[] = INCBIN_U8("graphics/pokemon/numel/icon.4bpp");
#else
    const u8 gMonIcon_Numel[] = INCBIN_U8("graphics/pokemon/numel/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Numel[] = INCBIN_U8("graphics/pokemon/numel/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Numel[] = INCBIN_COMP("graphics/pokemon/numel/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Numel[] = INCBIN_U32("graphics/pokemon/numel/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Numel[] = INCBIN_U32("graphics/pokemon/numel/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_NumelF[] = INCBIN_U32("graphics/pokemon/numel/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_NumelF[] = INCBIN_U32("graphics/pokemon/numel/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_NumelF[] = INCBIN_COMP("graphics/pokemon/numel/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Camerupt[] = INCBIN_U32("graphics/pokemon/camerupt/anim_front.4bpp.lz");
    const u32 gMonPalette_Camerupt[] = INCBIN_U32("graphics/pokemon/camerupt/normal.gbapal.lz");
    const u32 gMonBackPic_Camerupt[] = INCBIN_U32("graphics/pokemon/camerupt/back.4bpp.lz");
    const u32 gMonShinyPalette_Camerupt[] = INCBIN_U32("graphics/pokemon/camerupt/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Camerupt[] = INCBIN_U32("graphics/pokemon/camerupt/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Camerupt[] = INCBIN_U32("graphics/pokemon/camerupt/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Camerupt[] = INCBIN_U32("graphics/pokemon/camerupt/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Camerupt[] = INCBIN_U32("graphics/pokemon/camerupt/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Camerupt[] = INCBIN_U8("graphics/pokemon/camerupt/icon.4bpp");
#else
    const u8 gMonIcon_Camerupt[] = INCBIN_U8("graphics/pokemon/camerupt/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Camerupt[] = INCBIN_U8("graphics/pokemon/camerupt/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Camerupt[] = INCBIN_COMP("graphics/pokemon/camerupt/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Camerupt[] = INCBIN_U32("graphics/pokemon/camerupt/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Camerupt[] = INCBIN_U32("graphics/pokemon/camerupt/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_CameruptF[] = INCBIN_U32("graphics/pokemon/camerupt/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_CameruptF[] = INCBIN_U32("graphics/pokemon/camerupt/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_CameruptF[] = INCBIN_COMP("graphics/pokemon/camerupt/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_NUMEL

#if P_FAMILY_TORKOAL
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Torkoal[] = INCBIN_U32("graphics/pokemon/torkoal/anim_front.4bpp.lz");
    const u32 gMonPalette_Torkoal[] = INCBIN_U32("graphics/pokemon/torkoal/normal.gbapal.lz");
    const u32 gMonBackPic_Torkoal[] = INCBIN_U32("graphics/pokemon/torkoal/back.4bpp.lz");
    const u32 gMonShinyPalette_Torkoal[] = INCBIN_U32("graphics/pokemon/torkoal/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Torkoal[] = INCBIN_U32("graphics/pokemon/torkoal/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Torkoal[] = INCBIN_U32("graphics/pokemon/torkoal/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Torkoal[] = INCBIN_U32("graphics/pokemon/torkoal/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Torkoal[] = INCBIN_U32("graphics/pokemon/torkoal/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Torkoal[] = INCBIN_U8("graphics/pokemon/torkoal/icon.4bpp");
#else
    const u8 gMonIcon_Torkoal[] = INCBIN_U8("graphics/pokemon/torkoal/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Torkoal[] = INCBIN_U8("graphics/pokemon/torkoal/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Torkoal[] = INCBIN_COMP("graphics/pokemon/torkoal/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Torkoal[] = INCBIN_U32("graphics/pokemon/torkoal/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Torkoal[] = INCBIN_U32("graphics/pokemon/torkoal/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_TORKOAL

#if P_FAMILY_SPOINK
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Spoink[] = INCBIN_U32("graphics/pokemon/spoink/anim_front.4bpp.lz");
    const u32 gMonPalette_Spoink[] = INCBIN_U32("graphics/pokemon/spoink/normal.gbapal.lz");
    const u32 gMonBackPic_Spoink[] = INCBIN_U32("graphics/pokemon/spoink/back.4bpp.lz");
    const u32 gMonShinyPalette_Spoink[] = INCBIN_U32("graphics/pokemon/spoink/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Spoink[] = INCBIN_U32("graphics/pokemon/spoink/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Spoink[] = INCBIN_U32("graphics/pokemon/spoink/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Spoink[] = INCBIN_U32("graphics/pokemon/spoink/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Spoink[] = INCBIN_U32("graphics/pokemon/spoink/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Spoink[] = INCBIN_U8("graphics/pokemon/spoink/icon.4bpp");
#else
    const u8 gMonIcon_Spoink[] = INCBIN_U8("graphics/pokemon/spoink/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Spoink[] = INCBIN_U8("graphics/pokemon/spoink/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Spoink[] = INCBIN_COMP("graphics/pokemon/spoink/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Spoink[] = INCBIN_U32("graphics/pokemon/spoink/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Spoink[] = INCBIN_U32("graphics/pokemon/spoink/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Grumpig[] = INCBIN_U32("graphics/pokemon/grumpig/anim_front.4bpp.lz");
    const u32 gMonPalette_Grumpig[] = INCBIN_U32("graphics/pokemon/grumpig/normal.gbapal.lz");
    const u32 gMonBackPic_Grumpig[] = INCBIN_U32("graphics/pokemon/grumpig/back.4bpp.lz");
    const u32 gMonShinyPalette_Grumpig[] = INCBIN_U32("graphics/pokemon/grumpig/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Grumpig[] = INCBIN_U32("graphics/pokemon/grumpig/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Grumpig[] = INCBIN_U32("graphics/pokemon/grumpig/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Grumpig[] = INCBIN_U32("graphics/pokemon/grumpig/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Grumpig[] = INCBIN_U32("graphics/pokemon/grumpig/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Grumpig[] = INCBIN_U8("graphics/pokemon/grumpig/icon.4bpp");
#else
    const u8 gMonIcon_Grumpig[] = INCBIN_U8("graphics/pokemon/grumpig/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Grumpig[] = INCBIN_U8("graphics/pokemon/grumpig/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Grumpig[] = INCBIN_COMP("graphics/pokemon/grumpig/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Grumpig[] = INCBIN_U32("graphics/pokemon/grumpig/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Grumpig[] = INCBIN_U32("graphics/pokemon/grumpig/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SPOINK

#if P_FAMILY_SPINDA
    const u32 gMonFrontPic_Spinda[] = INCBIN_U32("graphics/pokemon/spinda/anim_front.4bpp.lz");
    const u32 gMonPalette_Spinda[] = INCBIN_U32("graphics/pokemon/spinda/normal.gbapal.lz");
    const u32 gMonBackPic_Spinda[] = INCBIN_U32("graphics/pokemon/spinda/back.4bpp.lz");
    const u32 gMonShinyPalette_Spinda[] = INCBIN_U32("graphics/pokemon/spinda/shiny.gbapal.lz");
    const u8 gMonIcon_Spinda[] = INCBIN_U8("graphics/pokemon/spinda/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Spinda[] = INCBIN_U8("graphics/pokemon/spinda/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Spinda[] = INCBIN_COMP("graphics/pokemon/spinda/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Spinda[] = INCBIN_U32("graphics/pokemon/spinda/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Spinda[] = INCBIN_U32("graphics/pokemon/spinda/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SPINDA

#if P_FAMILY_TRAPINCH
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Trapinch[] = INCBIN_U32("graphics/pokemon/trapinch/anim_front.4bpp.lz");
    const u32 gMonPalette_Trapinch[] = INCBIN_U32("graphics/pokemon/trapinch/normal.gbapal.lz");
    const u32 gMonBackPic_Trapinch[] = INCBIN_U32("graphics/pokemon/trapinch/back.4bpp.lz");
    const u32 gMonShinyPalette_Trapinch[] = INCBIN_U32("graphics/pokemon/trapinch/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Trapinch[] = INCBIN_U32("graphics/pokemon/trapinch/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Trapinch[] = INCBIN_U32("graphics/pokemon/trapinch/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Trapinch[] = INCBIN_U32("graphics/pokemon/trapinch/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Trapinch[] = INCBIN_U32("graphics/pokemon/trapinch/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Trapinch[] = INCBIN_U8("graphics/pokemon/trapinch/icon.4bpp");
#else
    const u8 gMonIcon_Trapinch[] = INCBIN_U8("graphics/pokemon/trapinch/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Trapinch[] = INCBIN_U8("graphics/pokemon/trapinch/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Trapinch[] = INCBIN_COMP("graphics/pokemon/trapinch/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Trapinch[] = INCBIN_U32("graphics/pokemon/trapinch/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Trapinch[] = INCBIN_U32("graphics/pokemon/trapinch/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Vibrava[] = INCBIN_U32("graphics/pokemon/vibrava/anim_front.4bpp.lz");
    const u32 gMonPalette_Vibrava[] = INCBIN_U32("graphics/pokemon/vibrava/normal.gbapal.lz");
    const u32 gMonBackPic_Vibrava[] = INCBIN_U32("graphics/pokemon/vibrava/back.4bpp.lz");
    const u32 gMonShinyPalette_Vibrava[] = INCBIN_U32("graphics/pokemon/vibrava/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Vibrava[] = INCBIN_U32("graphics/pokemon/vibrava/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Vibrava[] = INCBIN_U32("graphics/pokemon/vibrava/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Vibrava[] = INCBIN_U32("graphics/pokemon/vibrava/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Vibrava[] = INCBIN_U32("graphics/pokemon/vibrava/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Vibrava[] = INCBIN_U8("graphics/pokemon/vibrava/icon.4bpp");
#else
    const u8 gMonIcon_Vibrava[] = INCBIN_U8("graphics/pokemon/vibrava/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Vibrava[] = INCBIN_U8("graphics/pokemon/vibrava/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Vibrava[] = INCBIN_COMP("graphics/pokemon/vibrava/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Vibrava[] = INCBIN_U32("graphics/pokemon/vibrava/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Vibrava[] = INCBIN_U32("graphics/pokemon/vibrava/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Flygon[] = INCBIN_U32("graphics/pokemon/flygon/anim_front.4bpp.lz");
    const u32 gMonPalette_Flygon[] = INCBIN_U32("graphics/pokemon/flygon/normal.gbapal.lz");
    const u32 gMonBackPic_Flygon[] = INCBIN_U32("graphics/pokemon/flygon/back.4bpp.lz");
    const u32 gMonShinyPalette_Flygon[] = INCBIN_U32("graphics/pokemon/flygon/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Flygon[] = INCBIN_U32("graphics/pokemon/flygon/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Flygon[] = INCBIN_U32("graphics/pokemon/flygon/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Flygon[] = INCBIN_U32("graphics/pokemon/flygon/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Flygon[] = INCBIN_U32("graphics/pokemon/flygon/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Flygon[] = INCBIN_U8("graphics/pokemon/flygon/icon.4bpp");
#else
    const u8 gMonIcon_Flygon[] = INCBIN_U8("graphics/pokemon/flygon/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Flygon[] = INCBIN_U8("graphics/pokemon/flygon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Flygon[] = INCBIN_COMP("graphics/pokemon/flygon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Flygon[] = INCBIN_U32("graphics/pokemon/flygon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Flygon[] = INCBIN_U32("graphics/pokemon/flygon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_TRAPINCH

#if P_FAMILY_CACNEA
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Cacnea[] = INCBIN_U32("graphics/pokemon/cacnea/anim_front.4bpp.lz");
    const u32 gMonPalette_Cacnea[] = INCBIN_U32("graphics/pokemon/cacnea/normal.gbapal.lz");
    const u32 gMonBackPic_Cacnea[] = INCBIN_U32("graphics/pokemon/cacnea/back.4bpp.lz");
    const u32 gMonShinyPalette_Cacnea[] = INCBIN_U32("graphics/pokemon/cacnea/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Cacnea[] = INCBIN_U32("graphics/pokemon/cacnea/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Cacnea[] = INCBIN_U32("graphics/pokemon/cacnea/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Cacnea[] = INCBIN_U32("graphics/pokemon/cacnea/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Cacnea[] = INCBIN_U32("graphics/pokemon/cacnea/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Cacnea[] = INCBIN_U8("graphics/pokemon/cacnea/icon.4bpp");
#else
    const u8 gMonIcon_Cacnea[] = INCBIN_U8("graphics/pokemon/cacnea/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Cacnea[] = INCBIN_U8("graphics/pokemon/cacnea/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Cacnea[] = INCBIN_COMP("graphics/pokemon/cacnea/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Cacnea[] = INCBIN_U32("graphics/pokemon/cacnea/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Cacnea[] = INCBIN_U32("graphics/pokemon/cacnea/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Cacturne[] = INCBIN_U32("graphics/pokemon/cacturne/anim_front.4bpp.lz");
    const u32 gMonPalette_Cacturne[] = INCBIN_U32("graphics/pokemon/cacturne/normal.gbapal.lz");
    const u32 gMonBackPic_Cacturne[] = INCBIN_U32("graphics/pokemon/cacturne/back.4bpp.lz");
    const u32 gMonShinyPalette_Cacturne[] = INCBIN_U32("graphics/pokemon/cacturne/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Cacturne[] = INCBIN_U32("graphics/pokemon/cacturne/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Cacturne[] = INCBIN_U32("graphics/pokemon/cacturne/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Cacturne[] = INCBIN_U32("graphics/pokemon/cacturne/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Cacturne[] = INCBIN_U32("graphics/pokemon/cacturne/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Cacturne[] = INCBIN_U8("graphics/pokemon/cacturne/icon.4bpp");
#else
    const u8 gMonIcon_Cacturne[] = INCBIN_U8("graphics/pokemon/cacturne/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Cacturne[] = INCBIN_U8("graphics/pokemon/cacturne/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Cacturne[] = INCBIN_COMP("graphics/pokemon/cacturne/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Cacturne[] = INCBIN_U32("graphics/pokemon/cacturne/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Cacturne[] = INCBIN_U32("graphics/pokemon/cacturne/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_CacturneF[] = INCBIN_U32("graphics/pokemon/cacturne/anim_frontf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_CacturneF[] = INCBIN_COMP("graphics/pokemon/cacturne/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_CACNEA

#if P_FAMILY_SWABLU
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Swablu[] = INCBIN_U32("graphics/pokemon/swablu/anim_front.4bpp.lz");
    const u32 gMonPalette_Swablu[] = INCBIN_U32("graphics/pokemon/swablu/normal.gbapal.lz");
    const u32 gMonBackPic_Swablu[] = INCBIN_U32("graphics/pokemon/swablu/back.4bpp.lz");
    const u32 gMonShinyPalette_Swablu[] = INCBIN_U32("graphics/pokemon/swablu/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Swablu[] = INCBIN_U32("graphics/pokemon/swablu/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Swablu[] = INCBIN_U32("graphics/pokemon/swablu/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Swablu[] = INCBIN_U32("graphics/pokemon/swablu/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Swablu[] = INCBIN_U32("graphics/pokemon/swablu/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Swablu[] = INCBIN_U8("graphics/pokemon/swablu/icon.4bpp");
#else
    const u8 gMonIcon_Swablu[] = INCBIN_U8("graphics/pokemon/swablu/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Swablu[] = INCBIN_U8("graphics/pokemon/swablu/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Swablu[] = INCBIN_COMP("graphics/pokemon/swablu/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Swablu[] = INCBIN_U32("graphics/pokemon/swablu/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Swablu[] = INCBIN_U32("graphics/pokemon/swablu/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Altaria[] = INCBIN_U32("graphics/pokemon/altaria/anim_front.4bpp.lz");
    const u32 gMonPalette_Altaria[] = INCBIN_U32("graphics/pokemon/altaria/normal.gbapal.lz");
    const u32 gMonBackPic_Altaria[] = INCBIN_U32("graphics/pokemon/altaria/back.4bpp.lz");
    const u32 gMonShinyPalette_Altaria[] = INCBIN_U32("graphics/pokemon/altaria/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Altaria[] = INCBIN_U32("graphics/pokemon/altaria/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Altaria[] = INCBIN_U32("graphics/pokemon/altaria/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Altaria[] = INCBIN_U32("graphics/pokemon/altaria/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Altaria[] = INCBIN_U32("graphics/pokemon/altaria/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Altaria[] = INCBIN_U8("graphics/pokemon/altaria/icon.4bpp");
#else
    const u8 gMonIcon_Altaria[] = INCBIN_U8("graphics/pokemon/altaria/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Altaria[] = INCBIN_U8("graphics/pokemon/altaria/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Altaria[] = INCBIN_COMP("graphics/pokemon/altaria/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Altaria[] = INCBIN_U32("graphics/pokemon/altaria/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Altaria[] = INCBIN_U32("graphics/pokemon/altaria/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SWABLU

#if P_FAMILY_ZANGOOSE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Zangoose[] = INCBIN_U32("graphics/pokemon/zangoose/anim_front.4bpp.lz");
    const u32 gMonPalette_Zangoose[] = INCBIN_U32("graphics/pokemon/zangoose/normal.gbapal.lz");
    const u32 gMonBackPic_Zangoose[] = INCBIN_U32("graphics/pokemon/zangoose/back.4bpp.lz");
    const u32 gMonShinyPalette_Zangoose[] = INCBIN_U32("graphics/pokemon/zangoose/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Zangoose[] = INCBIN_U32("graphics/pokemon/zangoose/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Zangoose[] = INCBIN_U32("graphics/pokemon/zangoose/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Zangoose[] = INCBIN_U32("graphics/pokemon/zangoose/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Zangoose[] = INCBIN_U32("graphics/pokemon/zangoose/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Zangoose[] = INCBIN_U8("graphics/pokemon/zangoose/icon.4bpp");
#else
    const u8 gMonIcon_Zangoose[] = INCBIN_U8("graphics/pokemon/zangoose/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Zangoose[] = INCBIN_U8("graphics/pokemon/zangoose/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Zangoose[] = INCBIN_COMP("graphics/pokemon/zangoose/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Zangoose[] = INCBIN_U32("graphics/pokemon/zangoose/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Zangoose[] = INCBIN_U32("graphics/pokemon/zangoose/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_ZANGOOSE

#if P_FAMILY_SEVIPER
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Seviper[] = INCBIN_U32("graphics/pokemon/seviper/anim_front.4bpp.lz");
    const u32 gMonPalette_Seviper[] = INCBIN_U32("graphics/pokemon/seviper/normal.gbapal.lz");
    const u32 gMonBackPic_Seviper[] = INCBIN_U32("graphics/pokemon/seviper/back.4bpp.lz");
    const u32 gMonShinyPalette_Seviper[] = INCBIN_U32("graphics/pokemon/seviper/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Seviper[] = INCBIN_U32("graphics/pokemon/seviper/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Seviper[] = INCBIN_U32("graphics/pokemon/seviper/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Seviper[] = INCBIN_U32("graphics/pokemon/seviper/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Seviper[] = INCBIN_U32("graphics/pokemon/seviper/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Seviper[] = INCBIN_U8("graphics/pokemon/seviper/icon.4bpp");
#else
    const u8 gMonIcon_Seviper[] = INCBIN_U8("graphics/pokemon/seviper/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Seviper[] = INCBIN_U8("graphics/pokemon/seviper/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Seviper[] = INCBIN_COMP("graphics/pokemon/seviper/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Seviper[] = INCBIN_U32("graphics/pokemon/seviper/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Seviper[] = INCBIN_U32("graphics/pokemon/seviper/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SEVIPER

#if P_FAMILY_LUNATONE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Lunatone[] = INCBIN_U32("graphics/pokemon/lunatone/anim_front.4bpp.lz");
    const u32 gMonPalette_Lunatone[] = INCBIN_U32("graphics/pokemon/lunatone/normal.gbapal.lz");
    const u32 gMonBackPic_Lunatone[] = INCBIN_U32("graphics/pokemon/lunatone/back.4bpp.lz");
    const u32 gMonShinyPalette_Lunatone[] = INCBIN_U32("graphics/pokemon/lunatone/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Lunatone[] = INCBIN_U32("graphics/pokemon/lunatone/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Lunatone[] = INCBIN_U32("graphics/pokemon/lunatone/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Lunatone[] = INCBIN_U32("graphics/pokemon/lunatone/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Lunatone[] = INCBIN_U32("graphics/pokemon/lunatone/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Lunatone[] = INCBIN_U8("graphics/pokemon/lunatone/icon.4bpp");
#else
    const u8 gMonIcon_Lunatone[] = INCBIN_U8("graphics/pokemon/lunatone/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Lunatone[] = INCBIN_U8("graphics/pokemon/lunatone/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Lunatone[] = INCBIN_COMP("graphics/pokemon/lunatone/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Lunatone[] = INCBIN_U32("graphics/pokemon/lunatone/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Lunatone[] = INCBIN_U32("graphics/pokemon/lunatone/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_LUNATONE

#if P_FAMILY_SOLROCK
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Solrock[] = INCBIN_U32("graphics/pokemon/solrock/anim_front.4bpp.lz");
    const u32 gMonPalette_Solrock[] = INCBIN_U32("graphics/pokemon/solrock/normal.gbapal.lz");
    const u32 gMonBackPic_Solrock[] = INCBIN_U32("graphics/pokemon/solrock/back.4bpp.lz");
    const u32 gMonShinyPalette_Solrock[] = INCBIN_U32("graphics/pokemon/solrock/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Solrock[] = INCBIN_U32("graphics/pokemon/solrock/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Solrock[] = INCBIN_U32("graphics/pokemon/solrock/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Solrock[] = INCBIN_U32("graphics/pokemon/solrock/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Solrock[] = INCBIN_U32("graphics/pokemon/solrock/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Solrock[] = INCBIN_U8("graphics/pokemon/solrock/icon.4bpp");
#else
    const u8 gMonIcon_Solrock[] = INCBIN_U8("graphics/pokemon/solrock/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Solrock[] = INCBIN_U8("graphics/pokemon/solrock/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Solrock[] = INCBIN_COMP("graphics/pokemon/solrock/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Solrock[] = INCBIN_U32("graphics/pokemon/solrock/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Solrock[] = INCBIN_U32("graphics/pokemon/solrock/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SOLROCK

#if P_FAMILY_BARBOACH
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Barboach[] = INCBIN_U32("graphics/pokemon/barboach/anim_front.4bpp.lz");
    const u32 gMonPalette_Barboach[] = INCBIN_U32("graphics/pokemon/barboach/normal.gbapal.lz");
    const u32 gMonBackPic_Barboach[] = INCBIN_U32("graphics/pokemon/barboach/back.4bpp.lz");
    const u32 gMonShinyPalette_Barboach[] = INCBIN_U32("graphics/pokemon/barboach/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Barboach[] = INCBIN_U32("graphics/pokemon/barboach/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Barboach[] = INCBIN_U32("graphics/pokemon/barboach/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Barboach[] = INCBIN_U32("graphics/pokemon/barboach/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Barboach[] = INCBIN_U32("graphics/pokemon/barboach/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Barboach[] = INCBIN_U8("graphics/pokemon/barboach/icon.4bpp");
#else
    const u8 gMonIcon_Barboach[] = INCBIN_U8("graphics/pokemon/barboach/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Barboach[] = INCBIN_U8("graphics/pokemon/barboach/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Barboach[] = INCBIN_COMP("graphics/pokemon/barboach/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Barboach[] = INCBIN_U32("graphics/pokemon/barboach/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Barboach[] = INCBIN_U32("graphics/pokemon/barboach/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Whiscash[] = INCBIN_U32("graphics/pokemon/whiscash/anim_front.4bpp.lz");
    const u32 gMonPalette_Whiscash[] = INCBIN_U32("graphics/pokemon/whiscash/normal.gbapal.lz");
    const u32 gMonBackPic_Whiscash[] = INCBIN_U32("graphics/pokemon/whiscash/back.4bpp.lz");
    const u32 gMonShinyPalette_Whiscash[] = INCBIN_U32("graphics/pokemon/whiscash/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Whiscash[] = INCBIN_U32("graphics/pokemon/whiscash/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Whiscash[] = INCBIN_U32("graphics/pokemon/whiscash/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Whiscash[] = INCBIN_U32("graphics/pokemon/whiscash/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Whiscash[] = INCBIN_U32("graphics/pokemon/whiscash/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Whiscash[] = INCBIN_U8("graphics/pokemon/whiscash/icon.4bpp");
#else
    const u8 gMonIcon_Whiscash[] = INCBIN_U8("graphics/pokemon/whiscash/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Whiscash[] = INCBIN_U8("graphics/pokemon/whiscash/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Whiscash[] = INCBIN_COMP("graphics/pokemon/whiscash/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Whiscash[] = INCBIN_U32("graphics/pokemon/whiscash/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Whiscash[] = INCBIN_U32("graphics/pokemon/whiscash/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_BARBOACH

#if P_FAMILY_CORPHISH
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Corphish[] = INCBIN_U32("graphics/pokemon/corphish/anim_front.4bpp.lz");
    const u32 gMonPalette_Corphish[] = INCBIN_U32("graphics/pokemon/corphish/normal.gbapal.lz");
    const u32 gMonBackPic_Corphish[] = INCBIN_U32("graphics/pokemon/corphish/back.4bpp.lz");
    const u32 gMonShinyPalette_Corphish[] = INCBIN_U32("graphics/pokemon/corphish/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Corphish[] = INCBIN_U32("graphics/pokemon/corphish/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Corphish[] = INCBIN_U32("graphics/pokemon/corphish/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Corphish[] = INCBIN_U32("graphics/pokemon/corphish/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Corphish[] = INCBIN_U32("graphics/pokemon/corphish/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Corphish[] = INCBIN_U8("graphics/pokemon/corphish/icon.4bpp");
#else
    const u8 gMonIcon_Corphish[] = INCBIN_U8("graphics/pokemon/corphish/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Corphish[] = INCBIN_U8("graphics/pokemon/corphish/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Corphish[] = INCBIN_COMP("graphics/pokemon/corphish/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Corphish[] = INCBIN_U32("graphics/pokemon/corphish/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Corphish[] = INCBIN_U32("graphics/pokemon/corphish/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Crawdaunt[] = INCBIN_U32("graphics/pokemon/crawdaunt/anim_front.4bpp.lz");
    const u32 gMonPalette_Crawdaunt[] = INCBIN_U32("graphics/pokemon/crawdaunt/normal.gbapal.lz");
    const u32 gMonBackPic_Crawdaunt[] = INCBIN_U32("graphics/pokemon/crawdaunt/back.4bpp.lz");
    const u32 gMonShinyPalette_Crawdaunt[] = INCBIN_U32("graphics/pokemon/crawdaunt/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Crawdaunt[] = INCBIN_U32("graphics/pokemon/crawdaunt/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Crawdaunt[] = INCBIN_U32("graphics/pokemon/crawdaunt/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Crawdaunt[] = INCBIN_U32("graphics/pokemon/crawdaunt/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Crawdaunt[] = INCBIN_U32("graphics/pokemon/crawdaunt/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Crawdaunt[] = INCBIN_U8("graphics/pokemon/crawdaunt/icon.4bpp");
#else
    const u8 gMonIcon_Crawdaunt[] = INCBIN_U8("graphics/pokemon/crawdaunt/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Crawdaunt[] = INCBIN_U8("graphics/pokemon/crawdaunt/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Crawdaunt[] = INCBIN_COMP("graphics/pokemon/crawdaunt/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Crawdaunt[] = INCBIN_U32("graphics/pokemon/crawdaunt/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Crawdaunt[] = INCBIN_U32("graphics/pokemon/crawdaunt/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_CORPHISH

#if P_FAMILY_BALTOY
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Baltoy[] = INCBIN_U32("graphics/pokemon/baltoy/anim_front.4bpp.lz");
    const u32 gMonPalette_Baltoy[] = INCBIN_U32("graphics/pokemon/baltoy/normal.gbapal.lz");
    const u32 gMonBackPic_Baltoy[] = INCBIN_U32("graphics/pokemon/baltoy/back.4bpp.lz");
    const u32 gMonShinyPalette_Baltoy[] = INCBIN_U32("graphics/pokemon/baltoy/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Baltoy[] = INCBIN_U32("graphics/pokemon/baltoy/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Baltoy[] = INCBIN_U32("graphics/pokemon/baltoy/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Baltoy[] = INCBIN_U32("graphics/pokemon/baltoy/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Baltoy[] = INCBIN_U32("graphics/pokemon/baltoy/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Baltoy[] = INCBIN_U8("graphics/pokemon/baltoy/icon.4bpp");
#else
    const u8 gMonIcon_Baltoy[] = INCBIN_U8("graphics/pokemon/baltoy/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Baltoy[] = INCBIN_U8("graphics/pokemon/baltoy/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Baltoy[] = INCBIN_COMP("graphics/pokemon/baltoy/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Baltoy[] = INCBIN_U32("graphics/pokemon/baltoy/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Baltoy[] = INCBIN_U32("graphics/pokemon/baltoy/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Claydol[] = INCBIN_U32("graphics/pokemon/claydol/anim_front.4bpp.lz");
    const u32 gMonPalette_Claydol[] = INCBIN_U32("graphics/pokemon/claydol/normal.gbapal.lz");
    const u32 gMonBackPic_Claydol[] = INCBIN_U32("graphics/pokemon/claydol/back.4bpp.lz");
    const u32 gMonShinyPalette_Claydol[] = INCBIN_U32("graphics/pokemon/claydol/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Claydol[] = INCBIN_U32("graphics/pokemon/claydol/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Claydol[] = INCBIN_U32("graphics/pokemon/claydol/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Claydol[] = INCBIN_U32("graphics/pokemon/claydol/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Claydol[] = INCBIN_U32("graphics/pokemon/claydol/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Claydol[] = INCBIN_U8("graphics/pokemon/claydol/icon.4bpp");
#else
    const u8 gMonIcon_Claydol[] = INCBIN_U8("graphics/pokemon/claydol/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Claydol[] = INCBIN_U8("graphics/pokemon/claydol/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Claydol[] = INCBIN_COMP("graphics/pokemon/claydol/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Claydol[] = INCBIN_U32("graphics/pokemon/claydol/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Claydol[] = INCBIN_U32("graphics/pokemon/claydol/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_BALTOY

#if P_FAMILY_LILEEP
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Lileep[] = INCBIN_U32("graphics/pokemon/lileep/anim_front.4bpp.lz");
    const u32 gMonPalette_Lileep[] = INCBIN_U32("graphics/pokemon/lileep/normal.gbapal.lz");
    const u32 gMonBackPic_Lileep[] = INCBIN_U32("graphics/pokemon/lileep/back.4bpp.lz");
    const u32 gMonShinyPalette_Lileep[] = INCBIN_U32("graphics/pokemon/lileep/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Lileep[] = INCBIN_U32("graphics/pokemon/lileep/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Lileep[] = INCBIN_U32("graphics/pokemon/lileep/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Lileep[] = INCBIN_U32("graphics/pokemon/lileep/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Lileep[] = INCBIN_U32("graphics/pokemon/lileep/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Lileep[] = INCBIN_U8("graphics/pokemon/lileep/icon.4bpp");
#else
    const u8 gMonIcon_Lileep[] = INCBIN_U8("graphics/pokemon/lileep/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Lileep[] = INCBIN_U8("graphics/pokemon/lileep/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Lileep[] = INCBIN_COMP("graphics/pokemon/lileep/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Lileep[] = INCBIN_U32("graphics/pokemon/lileep/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Lileep[] = INCBIN_U32("graphics/pokemon/lileep/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Cradily[] = INCBIN_U32("graphics/pokemon/cradily/anim_front.4bpp.lz");
    const u32 gMonPalette_Cradily[] = INCBIN_U32("graphics/pokemon/cradily/normal.gbapal.lz");
    const u32 gMonBackPic_Cradily[] = INCBIN_U32("graphics/pokemon/cradily/back.4bpp.lz");
    const u32 gMonShinyPalette_Cradily[] = INCBIN_U32("graphics/pokemon/cradily/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Cradily[] = INCBIN_U32("graphics/pokemon/cradily/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Cradily[] = INCBIN_U32("graphics/pokemon/cradily/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Cradily[] = INCBIN_U32("graphics/pokemon/cradily/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Cradily[] = INCBIN_U32("graphics/pokemon/cradily/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Cradily[] = INCBIN_U8("graphics/pokemon/cradily/icon.4bpp");
#else
    const u8 gMonIcon_Cradily[] = INCBIN_U8("graphics/pokemon/cradily/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Cradily[] = INCBIN_U8("graphics/pokemon/cradily/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Cradily[] = INCBIN_COMP("graphics/pokemon/cradily/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Cradily[] = INCBIN_U32("graphics/pokemon/cradily/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Cradily[] = INCBIN_U32("graphics/pokemon/cradily/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_LILEEP

#if P_FAMILY_ANORITH
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Anorith[] = INCBIN_U32("graphics/pokemon/anorith/anim_front.4bpp.lz");
    const u32 gMonPalette_Anorith[] = INCBIN_U32("graphics/pokemon/anorith/normal.gbapal.lz");
    const u32 gMonBackPic_Anorith[] = INCBIN_U32("graphics/pokemon/anorith/back.4bpp.lz");
    const u32 gMonShinyPalette_Anorith[] = INCBIN_U32("graphics/pokemon/anorith/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Anorith[] = INCBIN_U32("graphics/pokemon/anorith/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Anorith[] = INCBIN_U32("graphics/pokemon/anorith/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Anorith[] = INCBIN_U32("graphics/pokemon/anorith/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Anorith[] = INCBIN_U32("graphics/pokemon/anorith/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Anorith[] = INCBIN_U8("graphics/pokemon/anorith/icon.4bpp");
#else
    const u8 gMonIcon_Anorith[] = INCBIN_U8("graphics/pokemon/anorith/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Anorith[] = INCBIN_U8("graphics/pokemon/anorith/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Anorith[] = INCBIN_COMP("graphics/pokemon/anorith/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Anorith[] = INCBIN_U32("graphics/pokemon/anorith/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Anorith[] = INCBIN_U32("graphics/pokemon/anorith/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Armaldo[] = INCBIN_U32("graphics/pokemon/armaldo/anim_front.4bpp.lz");
    const u32 gMonPalette_Armaldo[] = INCBIN_U32("graphics/pokemon/armaldo/normal.gbapal.lz");
    const u32 gMonBackPic_Armaldo[] = INCBIN_U32("graphics/pokemon/armaldo/back.4bpp.lz");
    const u32 gMonShinyPalette_Armaldo[] = INCBIN_U32("graphics/pokemon/armaldo/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Armaldo[] = INCBIN_U32("graphics/pokemon/armaldo/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Armaldo[] = INCBIN_U32("graphics/pokemon/armaldo/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Armaldo[] = INCBIN_U32("graphics/pokemon/armaldo/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Armaldo[] = INCBIN_U32("graphics/pokemon/armaldo/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Armaldo[] = INCBIN_U8("graphics/pokemon/armaldo/icon.4bpp");
#else
    const u8 gMonIcon_Armaldo[] = INCBIN_U8("graphics/pokemon/armaldo/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Armaldo[] = INCBIN_U8("graphics/pokemon/armaldo/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Armaldo[] = INCBIN_COMP("graphics/pokemon/armaldo/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Armaldo[] = INCBIN_U32("graphics/pokemon/armaldo/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Armaldo[] = INCBIN_U32("graphics/pokemon/armaldo/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_ANORITH

#if P_FAMILY_FEEBAS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Feebas[] = INCBIN_U32("graphics/pokemon/feebas/anim_front.4bpp.lz");
    const u32 gMonPalette_Feebas[] = INCBIN_U32("graphics/pokemon/feebas/normal.gbapal.lz");
    const u32 gMonBackPic_Feebas[] = INCBIN_U32("graphics/pokemon/feebas/back.4bpp.lz");
    const u32 gMonShinyPalette_Feebas[] = INCBIN_U32("graphics/pokemon/feebas/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Feebas[] = INCBIN_U32("graphics/pokemon/feebas/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Feebas[] = INCBIN_U32("graphics/pokemon/feebas/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Feebas[] = INCBIN_U32("graphics/pokemon/feebas/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Feebas[] = INCBIN_U32("graphics/pokemon/feebas/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Feebas[] = INCBIN_U8("graphics/pokemon/feebas/icon.4bpp");
#else
    const u8 gMonIcon_Feebas[] = INCBIN_U8("graphics/pokemon/feebas/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Feebas[] = INCBIN_U8("graphics/pokemon/feebas/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Feebas[] = INCBIN_COMP("graphics/pokemon/feebas/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Feebas[] = INCBIN_U32("graphics/pokemon/feebas/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Feebas[] = INCBIN_U32("graphics/pokemon/feebas/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Milotic[] = INCBIN_U32("graphics/pokemon/milotic/anim_front.4bpp.lz");
    const u32 gMonPalette_Milotic[] = INCBIN_U32("graphics/pokemon/milotic/normal.gbapal.lz");
    const u32 gMonBackPic_Milotic[] = INCBIN_U32("graphics/pokemon/milotic/back.4bpp.lz");
    const u32 gMonShinyPalette_Milotic[] = INCBIN_U32("graphics/pokemon/milotic/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Milotic[] = INCBIN_U32("graphics/pokemon/milotic/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Milotic[] = INCBIN_U32("graphics/pokemon/milotic/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Milotic[] = INCBIN_U32("graphics/pokemon/milotic/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Milotic[] = INCBIN_U32("graphics/pokemon/milotic/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Milotic[] = INCBIN_U8("graphics/pokemon/milotic/icon.4bpp");
#else
    const u8 gMonIcon_Milotic[] = INCBIN_U8("graphics/pokemon/milotic/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Milotic[] = INCBIN_U8("graphics/pokemon/milotic/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Milotic[] = INCBIN_COMP("graphics/pokemon/milotic/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Milotic[] = INCBIN_U32("graphics/pokemon/milotic/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Milotic[] = INCBIN_U32("graphics/pokemon/milotic/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_MiloticF[] = INCBIN_U32("graphics/pokemon/milotic/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_MiloticF[] = INCBIN_U32("graphics/pokemon/milotic/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_MiloticF[] = INCBIN_COMP("graphics/pokemon/milotic/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_FEEBAS

#if P_FAMILY_CASTFORM
    const u32 gMonFrontPic_CastformNormal[] = INCBIN_U32("graphics/pokemon/castform/anim_front.4bpp.lz");
    const u32 gMonPalette_CastformNormal[] = INCBIN_U32("graphics/pokemon/castform/normal.gbapal.lz");
    const u32 gMonBackPic_CastformNormal[] = INCBIN_U32("graphics/pokemon/castform/back.4bpp.lz");
    const u32 gMonShinyPalette_CastformNormal[] = INCBIN_U32("graphics/pokemon/castform/shiny.gbapal.lz");
    const u8 gMonIcon_CastformNormal[] = INCBIN_U8("graphics/pokemon/castform/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Castform[] = INCBIN_U8("graphics/pokemon/castform/footprint.1bpp");
#endif //P_FOOTPRINTS

    const u32 gMonFrontPic_CastformSunny[] = INCBIN_U32("graphics/pokemon/castform/sunny/anim_front.4bpp.lz");
    const u32 gMonPalette_CastformSunny[] = INCBIN_U32("graphics/pokemon/castform/sunny/normal.gbapal.lz");
    const u32 gMonBackPic_CastformSunny[] = INCBIN_U32("graphics/pokemon/castform/sunny/back.4bpp.lz");
    const u32 gMonShinyPalette_CastformSunny[] = INCBIN_U32("graphics/pokemon/castform/sunny/shiny.gbapal.lz");
    const u8 gMonIcon_CastformSunny[] = INCBIN_U8("graphics/pokemon/castform/sunny/icon.4bpp");

    const u32 gMonFrontPic_CastformRainy[] = INCBIN_U32("graphics/pokemon/castform/rainy/anim_front.4bpp.lz");
    const u32 gMonPalette_CastformRainy[] = INCBIN_U32("graphics/pokemon/castform/rainy/normal.gbapal.lz");
    const u32 gMonBackPic_CastformRainy[] = INCBIN_U32("graphics/pokemon/castform/rainy/back.4bpp.lz");
    const u32 gMonShinyPalette_CastformRainy[] = INCBIN_U32("graphics/pokemon/castform/rainy/shiny.gbapal.lz");
    const u8 gMonIcon_CastformRainy[] = INCBIN_U8("graphics/pokemon/castform/rainy/icon.4bpp");

    const u32 gMonFrontPic_CastformSnowy[] = INCBIN_U32("graphics/pokemon/castform/snowy/anim_front.4bpp.lz");
    const u32 gMonPalette_CastformSnowy[] = INCBIN_U32("graphics/pokemon/castform/snowy/normal.gbapal.lz");
    const u32 gMonBackPic_CastformSnowy[] = INCBIN_U32("graphics/pokemon/castform/snowy/back.4bpp.lz");
    const u32 gMonShinyPalette_CastformSnowy[] = INCBIN_U32("graphics/pokemon/castform/snowy/shiny.gbapal.lz");
    const u8 gMonIcon_CastformSnowy[] = INCBIN_U8("graphics/pokemon/castform/snowy/icon.4bpp");

#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_CastformNormal[] = INCBIN_COMP("graphics/pokemon/castform/overworld.4bpp");
    const u32 gObjectEventPic_CastformSunny[] = INCBIN_COMP("graphics/pokemon/castform/sunny/overworld.4bpp");
    const u32 gObjectEventPic_CastformRainy[] = INCBIN_COMP("graphics/pokemon/castform/rainy/overworld.4bpp");
    const u32 gObjectEventPic_CastformSnowy[] = INCBIN_COMP("graphics/pokemon/castform/snowy/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_CastformNormal[] = INCBIN_U32("graphics/pokemon/castform/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_CastformSunny[] = INCBIN_U32("graphics/pokemon/castform/sunny/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_CastformRainy[] = INCBIN_U32("graphics/pokemon/castform/rainy/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_CastformSnowy[] = INCBIN_U32("graphics/pokemon/castform/snowy/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_CastformNormal[] = INCBIN_U32("graphics/pokemon/castform/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_CastformSunny[] = INCBIN_U32("graphics/pokemon/castform/sunny/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_CastformRainy[] = INCBIN_U32("graphics/pokemon/castform/rainy/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_CastformSnowy[] = INCBIN_U32("graphics/pokemon/castform/snowy/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_CASTFORM

#if P_FAMILY_KECLEON
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Kecleon[] = INCBIN_U32("graphics/pokemon/kecleon/anim_front.4bpp.lz");
    const u32 gMonPalette_Kecleon[] = INCBIN_U32("graphics/pokemon/kecleon/normal.gbapal.lz");
    const u32 gMonBackPic_Kecleon[] = INCBIN_U32("graphics/pokemon/kecleon/back.4bpp.lz");
    const u32 gMonShinyPalette_Kecleon[] = INCBIN_U32("graphics/pokemon/kecleon/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Kecleon[] = INCBIN_U32("graphics/pokemon/kecleon/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Kecleon[] = INCBIN_U32("graphics/pokemon/kecleon/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Kecleon[] = INCBIN_U32("graphics/pokemon/kecleon/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Kecleon[] = INCBIN_U32("graphics/pokemon/kecleon/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Kecleon[] = INCBIN_U8("graphics/pokemon/kecleon/icon.4bpp");
#else
    const u8 gMonIcon_Kecleon[] = INCBIN_U8("graphics/pokemon/kecleon/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Kecleon[] = INCBIN_U8("graphics/pokemon/kecleon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Kecleon[] = INCBIN_COMP("graphics/pokemon/kecleon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Kecleon[] = INCBIN_U32("graphics/pokemon/kecleon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Kecleon[] = INCBIN_U32("graphics/pokemon/kecleon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_KECLEON

#if P_FAMILY_SHUPPET
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Shuppet[] = INCBIN_U32("graphics/pokemon/shuppet/anim_front.4bpp.lz");
    const u32 gMonPalette_Shuppet[] = INCBIN_U32("graphics/pokemon/shuppet/normal.gbapal.lz");
    const u32 gMonBackPic_Shuppet[] = INCBIN_U32("graphics/pokemon/shuppet/back.4bpp.lz");
    const u32 gMonShinyPalette_Shuppet[] = INCBIN_U32("graphics/pokemon/shuppet/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Shuppet[] = INCBIN_U32("graphics/pokemon/shuppet/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Shuppet[] = INCBIN_U32("graphics/pokemon/shuppet/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Shuppet[] = INCBIN_U32("graphics/pokemon/shuppet/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Shuppet[] = INCBIN_U32("graphics/pokemon/shuppet/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Shuppet[] = INCBIN_U8("graphics/pokemon/shuppet/icon.4bpp");
#else
    const u8 gMonIcon_Shuppet[] = INCBIN_U8("graphics/pokemon/shuppet/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Shuppet[] = INCBIN_U8("graphics/pokemon/shuppet/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Shuppet[] = INCBIN_COMP("graphics/pokemon/shuppet/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Shuppet[] = INCBIN_U32("graphics/pokemon/shuppet/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Shuppet[] = INCBIN_U32("graphics/pokemon/shuppet/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Banette[] = INCBIN_U32("graphics/pokemon/banette/anim_front.4bpp.lz");
    const u32 gMonPalette_Banette[] = INCBIN_U32("graphics/pokemon/banette/normal.gbapal.lz");
    const u32 gMonBackPic_Banette[] = INCBIN_U32("graphics/pokemon/banette/back.4bpp.lz");
    const u32 gMonShinyPalette_Banette[] = INCBIN_U32("graphics/pokemon/banette/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Banette[] = INCBIN_U32("graphics/pokemon/banette/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Banette[] = INCBIN_U32("graphics/pokemon/banette/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Banette[] = INCBIN_U32("graphics/pokemon/banette/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Banette[] = INCBIN_U32("graphics/pokemon/banette/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Banette[] = INCBIN_U8("graphics/pokemon/banette/icon.4bpp");
#else
    const u8 gMonIcon_Banette[] = INCBIN_U8("graphics/pokemon/banette/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Banette[] = INCBIN_U8("graphics/pokemon/banette/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Banette[] = INCBIN_COMP("graphics/pokemon/banette/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Banette[] = INCBIN_U32("graphics/pokemon/banette/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Banette[] = INCBIN_U32("graphics/pokemon/banette/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SHUPPET

#if P_FAMILY_DUSKULL
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Duskull[] = INCBIN_U32("graphics/pokemon/duskull/anim_front.4bpp.lz");
    const u32 gMonPalette_Duskull[] = INCBIN_U32("graphics/pokemon/duskull/normal.gbapal.lz");
    const u32 gMonBackPic_Duskull[] = INCBIN_U32("graphics/pokemon/duskull/back.4bpp.lz");
    const u32 gMonShinyPalette_Duskull[] = INCBIN_U32("graphics/pokemon/duskull/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Duskull[] = INCBIN_U32("graphics/pokemon/duskull/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Duskull[] = INCBIN_U32("graphics/pokemon/duskull/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Duskull[] = INCBIN_U32("graphics/pokemon/duskull/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Duskull[] = INCBIN_U32("graphics/pokemon/duskull/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Duskull[] = INCBIN_U8("graphics/pokemon/duskull/icon.4bpp");
#else
    const u8 gMonIcon_Duskull[] = INCBIN_U8("graphics/pokemon/duskull/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Duskull[] = INCBIN_U8("graphics/pokemon/duskull/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Duskull[] = INCBIN_COMP("graphics/pokemon/duskull/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Duskull[] = INCBIN_U32("graphics/pokemon/duskull/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Duskull[] = INCBIN_U32("graphics/pokemon/duskull/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Dusclops[] = INCBIN_U32("graphics/pokemon/dusclops/anim_front.4bpp.lz");
    const u32 gMonPalette_Dusclops[] = INCBIN_U32("graphics/pokemon/dusclops/normal.gbapal.lz");
    const u32 gMonBackPic_Dusclops[] = INCBIN_U32("graphics/pokemon/dusclops/back.4bpp.lz");
    const u32 gMonShinyPalette_Dusclops[] = INCBIN_U32("graphics/pokemon/dusclops/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Dusclops[] = INCBIN_U32("graphics/pokemon/dusclops/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Dusclops[] = INCBIN_U32("graphics/pokemon/dusclops/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Dusclops[] = INCBIN_U32("graphics/pokemon/dusclops/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Dusclops[] = INCBIN_U32("graphics/pokemon/dusclops/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Dusclops[] = INCBIN_U8("graphics/pokemon/dusclops/icon.4bpp");
#else
    const u8 gMonIcon_Dusclops[] = INCBIN_U8("graphics/pokemon/dusclops/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Dusclops[] = INCBIN_U8("graphics/pokemon/dusclops/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Dusclops[] = INCBIN_COMP("graphics/pokemon/dusclops/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Dusclops[] = INCBIN_U32("graphics/pokemon/dusclops/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Dusclops[] = INCBIN_U32("graphics/pokemon/dusclops/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Dusknoir[] = INCBIN_U32("graphics/pokemon/dusknoir/anim_front.4bpp.lz");
    const u32 gMonPalette_Dusknoir[] = INCBIN_U32("graphics/pokemon/dusknoir/normal.gbapal.lz");
    const u32 gMonBackPic_Dusknoir[] = INCBIN_U32("graphics/pokemon/dusknoir/back.4bpp.lz");
    const u32 gMonShinyPalette_Dusknoir[] = INCBIN_U32("graphics/pokemon/dusknoir/shiny.gbapal.lz");
    const u8 gMonIcon_Dusknoir[] = INCBIN_U8("graphics/pokemon/dusknoir/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Dusknoir[] = INCBIN_U8("graphics/pokemon/dusknoir/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Dusknoir[] = INCBIN_COMP("graphics/pokemon/dusknoir/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Dusknoir[] = INCBIN_U32("graphics/pokemon/dusknoir/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Dusknoir[] = INCBIN_U32("graphics/pokemon/dusknoir/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_DUSKULL

#if P_FAMILY_TROPIUS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Tropius[] = INCBIN_U32("graphics/pokemon/tropius/anim_front.4bpp.lz");
    const u32 gMonPalette_Tropius[] = INCBIN_U32("graphics/pokemon/tropius/normal.gbapal.lz");
    const u32 gMonBackPic_Tropius[] = INCBIN_U32("graphics/pokemon/tropius/back.4bpp.lz");
    const u32 gMonShinyPalette_Tropius[] = INCBIN_U32("graphics/pokemon/tropius/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Tropius[] = INCBIN_U32("graphics/pokemon/tropius/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Tropius[] = INCBIN_U32("graphics/pokemon/tropius/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Tropius[] = INCBIN_U32("graphics/pokemon/tropius/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Tropius[] = INCBIN_U32("graphics/pokemon/tropius/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Tropius[] = INCBIN_U8("graphics/pokemon/tropius/icon.4bpp");
#else
    const u8 gMonIcon_Tropius[] = INCBIN_U8("graphics/pokemon/tropius/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Tropius[] = INCBIN_U8("graphics/pokemon/tropius/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Tropius[] = INCBIN_COMP("graphics/pokemon/tropius/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Tropius[] = INCBIN_U32("graphics/pokemon/tropius/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Tropius[] = INCBIN_U32("graphics/pokemon/tropius/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_TROPIUS

#if P_FAMILY_CHIMECHO
#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Chingling[] = INCBIN_U32("graphics/pokemon/chingling/anim_front.4bpp.lz");
    const u32 gMonPalette_Chingling[] = INCBIN_U32("graphics/pokemon/chingling/normal.gbapal.lz");
    const u32 gMonBackPic_Chingling[] = INCBIN_U32("graphics/pokemon/chingling/back.4bpp.lz");
    const u32 gMonShinyPalette_Chingling[] = INCBIN_U32("graphics/pokemon/chingling/shiny.gbapal.lz");
    const u8 gMonIcon_Chingling[] = INCBIN_U8("graphics/pokemon/chingling/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Chingling[] = INCBIN_U8("graphics/pokemon/chingling/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Chingling[] = INCBIN_COMP("graphics/pokemon/chingling/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Chingling[] = INCBIN_U32("graphics/pokemon/chingling/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Chingling[] = INCBIN_U32("graphics/pokemon/chingling/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_4_CROSS_EVOS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Chimecho[] = INCBIN_U32("graphics/pokemon/chimecho/anim_front.4bpp.lz");
    const u32 gMonPalette_Chimecho[] = INCBIN_U32("graphics/pokemon/chimecho/normal.gbapal.lz");
    const u32 gMonBackPic_Chimecho[] = INCBIN_U32("graphics/pokemon/chimecho/back.4bpp.lz");
    const u32 gMonShinyPalette_Chimecho[] = INCBIN_U32("graphics/pokemon/chimecho/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Chimecho[] = INCBIN_U32("graphics/pokemon/chimecho/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Chimecho[] = INCBIN_U32("graphics/pokemon/chimecho/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Chimecho[] = INCBIN_U32("graphics/pokemon/chimecho/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Chimecho[] = INCBIN_U32("graphics/pokemon/chimecho/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Chimecho[] = INCBIN_U8("graphics/pokemon/chimecho/icon.4bpp");
#else
    const u8 gMonIcon_Chimecho[] = INCBIN_U8("graphics/pokemon/chimecho/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Chimecho[] = INCBIN_U8("graphics/pokemon/chimecho/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Chimecho[] = INCBIN_COMP("graphics/pokemon/chimecho/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Chimecho[] = INCBIN_U32("graphics/pokemon/chimecho/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Chimecho[] = INCBIN_U32("graphics/pokemon/chimecho/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_CHIMECHO

#if P_FAMILY_ABSOL
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Absol[] = INCBIN_U32("graphics/pokemon/absol/anim_front.4bpp.lz");
    const u32 gMonPalette_Absol[] = INCBIN_U32("graphics/pokemon/absol/normal.gbapal.lz");
    const u32 gMonBackPic_Absol[] = INCBIN_U32("graphics/pokemon/absol/back.4bpp.lz");
    const u32 gMonShinyPalette_Absol[] = INCBIN_U32("graphics/pokemon/absol/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Absol[] = INCBIN_U32("graphics/pokemon/absol/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Absol[] = INCBIN_U32("graphics/pokemon/absol/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Absol[] = INCBIN_U32("graphics/pokemon/absol/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Absol[] = INCBIN_U32("graphics/pokemon/absol/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Absol[] = INCBIN_U8("graphics/pokemon/absol/icon.4bpp");
#else
    const u8 gMonIcon_Absol[] = INCBIN_U8("graphics/pokemon/absol/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Absol[] = INCBIN_U8("graphics/pokemon/absol/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Absol[] = INCBIN_COMP("graphics/pokemon/absol/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Absol[] = INCBIN_U32("graphics/pokemon/absol/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Absol[] = INCBIN_U32("graphics/pokemon/absol/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_ABSOL

#if P_FAMILY_SNORUNT
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Snorunt[] = INCBIN_U32("graphics/pokemon/snorunt/anim_front.4bpp.lz");
    const u32 gMonPalette_Snorunt[] = INCBIN_U32("graphics/pokemon/snorunt/normal.gbapal.lz");
    const u32 gMonBackPic_Snorunt[] = INCBIN_U32("graphics/pokemon/snorunt/back.4bpp.lz");
    const u32 gMonShinyPalette_Snorunt[] = INCBIN_U32("graphics/pokemon/snorunt/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Snorunt[] = INCBIN_U32("graphics/pokemon/snorunt/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Snorunt[] = INCBIN_U32("graphics/pokemon/snorunt/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Snorunt[] = INCBIN_U32("graphics/pokemon/snorunt/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Snorunt[] = INCBIN_U32("graphics/pokemon/snorunt/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Snorunt[] = INCBIN_U8("graphics/pokemon/snorunt/icon.4bpp");
#else
    const u8 gMonIcon_Snorunt[] = INCBIN_U8("graphics/pokemon/snorunt/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Snorunt[] = INCBIN_U8("graphics/pokemon/snorunt/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Snorunt[] = INCBIN_COMP("graphics/pokemon/snorunt/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Snorunt[] = INCBIN_U32("graphics/pokemon/snorunt/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Snorunt[] = INCBIN_U32("graphics/pokemon/snorunt/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Glalie[] = INCBIN_U32("graphics/pokemon/glalie/anim_front.4bpp.lz");
    const u32 gMonPalette_Glalie[] = INCBIN_U32("graphics/pokemon/glalie/normal.gbapal.lz");
    const u32 gMonBackPic_Glalie[] = INCBIN_U32("graphics/pokemon/glalie/back.4bpp.lz");
    const u32 gMonShinyPalette_Glalie[] = INCBIN_U32("graphics/pokemon/glalie/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Glalie[] = INCBIN_U32("graphics/pokemon/glalie/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Glalie[] = INCBIN_U32("graphics/pokemon/glalie/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Glalie[] = INCBIN_U32("graphics/pokemon/glalie/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Glalie[] = INCBIN_U32("graphics/pokemon/glalie/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Glalie[] = INCBIN_U8("graphics/pokemon/glalie/icon.4bpp");
#else
    const u8 gMonIcon_Glalie[] = INCBIN_U8("graphics/pokemon/glalie/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Glalie[] = INCBIN_U8("graphics/pokemon/glalie/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Glalie[] = INCBIN_COMP("graphics/pokemon/glalie/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Glalie[] = INCBIN_U32("graphics/pokemon/glalie/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Glalie[] = INCBIN_U32("graphics/pokemon/glalie/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#if P_GEN_4_CROSS_EVOS
    const u32 gMonFrontPic_Froslass[] = INCBIN_U32("graphics/pokemon/froslass/anim_front.4bpp.lz");
    const u32 gMonPalette_Froslass[] = INCBIN_U32("graphics/pokemon/froslass/normal.gbapal.lz");
    const u32 gMonBackPic_Froslass[] = INCBIN_U32("graphics/pokemon/froslass/back.4bpp.lz");
    const u32 gMonShinyPalette_Froslass[] = INCBIN_U32("graphics/pokemon/froslass/shiny.gbapal.lz");
    const u8 gMonIcon_Froslass[] = INCBIN_U8("graphics/pokemon/froslass/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Froslass[] = INCBIN_U8("graphics/pokemon/froslass/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Froslass[] = INCBIN_COMP("graphics/pokemon/froslass/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Froslass[] = INCBIN_U32("graphics/pokemon/froslass/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Froslass[] = INCBIN_U32("graphics/pokemon/froslass/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GEN_4_CROSS_EVOS
#endif //P_FAMILY_SNORUNT

#if P_FAMILY_SPHEAL
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Spheal[] = INCBIN_U32("graphics/pokemon/spheal/anim_front.4bpp.lz");
    const u32 gMonPalette_Spheal[] = INCBIN_U32("graphics/pokemon/spheal/normal.gbapal.lz");
    const u32 gMonBackPic_Spheal[] = INCBIN_U32("graphics/pokemon/spheal/back.4bpp.lz");
    const u32 gMonShinyPalette_Spheal[] = INCBIN_U32("graphics/pokemon/spheal/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Spheal[] = INCBIN_U32("graphics/pokemon/spheal/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Spheal[] = INCBIN_U32("graphics/pokemon/spheal/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Spheal[] = INCBIN_U32("graphics/pokemon/spheal/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Spheal[] = INCBIN_U32("graphics/pokemon/spheal/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Spheal[] = INCBIN_U8("graphics/pokemon/spheal/icon.4bpp");
#else
    const u8 gMonIcon_Spheal[] = INCBIN_U8("graphics/pokemon/spheal/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Spheal[] = INCBIN_U8("graphics/pokemon/spheal/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Spheal[] = INCBIN_COMP("graphics/pokemon/spheal/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Spheal[] = INCBIN_U32("graphics/pokemon/spheal/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Spheal[] = INCBIN_U32("graphics/pokemon/spheal/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Sealeo[] = INCBIN_U32("graphics/pokemon/sealeo/anim_front.4bpp.lz");
    const u32 gMonPalette_Sealeo[] = INCBIN_U32("graphics/pokemon/sealeo/normal.gbapal.lz");
    const u32 gMonBackPic_Sealeo[] = INCBIN_U32("graphics/pokemon/sealeo/back.4bpp.lz");
    const u32 gMonShinyPalette_Sealeo[] = INCBIN_U32("graphics/pokemon/sealeo/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Sealeo[] = INCBIN_U32("graphics/pokemon/sealeo/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Sealeo[] = INCBIN_U32("graphics/pokemon/sealeo/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Sealeo[] = INCBIN_U32("graphics/pokemon/sealeo/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Sealeo[] = INCBIN_U32("graphics/pokemon/sealeo/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Sealeo[] = INCBIN_U8("graphics/pokemon/sealeo/icon.4bpp");
#else
    const u8 gMonIcon_Sealeo[] = INCBIN_U8("graphics/pokemon/sealeo/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Sealeo[] = INCBIN_U8("graphics/pokemon/sealeo/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Sealeo[] = INCBIN_COMP("graphics/pokemon/sealeo/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Sealeo[] = INCBIN_U32("graphics/pokemon/sealeo/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Sealeo[] = INCBIN_U32("graphics/pokemon/sealeo/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Walrein[] = INCBIN_U32("graphics/pokemon/walrein/anim_front.4bpp.lz");
    const u32 gMonPalette_Walrein[] = INCBIN_U32("graphics/pokemon/walrein/normal.gbapal.lz");
    const u32 gMonBackPic_Walrein[] = INCBIN_U32("graphics/pokemon/walrein/back.4bpp.lz");
    const u32 gMonShinyPalette_Walrein[] = INCBIN_U32("graphics/pokemon/walrein/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Walrein[] = INCBIN_U32("graphics/pokemon/walrein/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Walrein[] = INCBIN_U32("graphics/pokemon/walrein/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Walrein[] = INCBIN_U32("graphics/pokemon/walrein/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Walrein[] = INCBIN_U32("graphics/pokemon/walrein/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Walrein[] = INCBIN_U8("graphics/pokemon/walrein/icon.4bpp");
#else
    const u8 gMonIcon_Walrein[] = INCBIN_U8("graphics/pokemon/walrein/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Walrein[] = INCBIN_U8("graphics/pokemon/walrein/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Walrein[] = INCBIN_COMP("graphics/pokemon/walrein/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Walrein[] = INCBIN_U32("graphics/pokemon/walrein/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Walrein[] = INCBIN_U32("graphics/pokemon/walrein/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SPHEAL

#if P_FAMILY_CLAMPERL
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Clamperl[] = INCBIN_U32("graphics/pokemon/clamperl/anim_front.4bpp.lz");
    const u32 gMonPalette_Clamperl[] = INCBIN_U32("graphics/pokemon/clamperl/normal.gbapal.lz");
    const u32 gMonBackPic_Clamperl[] = INCBIN_U32("graphics/pokemon/clamperl/back.4bpp.lz");
    const u32 gMonShinyPalette_Clamperl[] = INCBIN_U32("graphics/pokemon/clamperl/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Clamperl[] = INCBIN_U32("graphics/pokemon/clamperl/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Clamperl[] = INCBIN_U32("graphics/pokemon/clamperl/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Clamperl[] = INCBIN_U32("graphics/pokemon/clamperl/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Clamperl[] = INCBIN_U32("graphics/pokemon/clamperl/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Clamperl[] = INCBIN_U8("graphics/pokemon/clamperl/icon.4bpp");
#else
    const u8 gMonIcon_Clamperl[] = INCBIN_U8("graphics/pokemon/clamperl/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Clamperl[] = INCBIN_U8("graphics/pokemon/clamperl/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Clamperl[] = INCBIN_COMP("graphics/pokemon/clamperl/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Clamperl[] = INCBIN_U32("graphics/pokemon/clamperl/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Clamperl[] = INCBIN_U32("graphics/pokemon/clamperl/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Huntail[] = INCBIN_U32("graphics/pokemon/huntail/anim_front.4bpp.lz");
    const u32 gMonPalette_Huntail[] = INCBIN_U32("graphics/pokemon/huntail/normal.gbapal.lz");
    const u32 gMonBackPic_Huntail[] = INCBIN_U32("graphics/pokemon/huntail/back.4bpp.lz");
    const u32 gMonShinyPalette_Huntail[] = INCBIN_U32("graphics/pokemon/huntail/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Huntail[] = INCBIN_U32("graphics/pokemon/huntail/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Huntail[] = INCBIN_U32("graphics/pokemon/huntail/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Huntail[] = INCBIN_U32("graphics/pokemon/huntail/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Huntail[] = INCBIN_U32("graphics/pokemon/huntail/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Huntail[] = INCBIN_U8("graphics/pokemon/huntail/icon.4bpp");
#else
    const u8 gMonIcon_Huntail[] = INCBIN_U8("graphics/pokemon/huntail/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Huntail[] = INCBIN_U8("graphics/pokemon/huntail/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Huntail[] = INCBIN_COMP("graphics/pokemon/huntail/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Huntail[] = INCBIN_U32("graphics/pokemon/huntail/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Huntail[] = INCBIN_U32("graphics/pokemon/huntail/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Gorebyss[] = INCBIN_U32("graphics/pokemon/gorebyss/anim_front.4bpp.lz");
    const u32 gMonPalette_Gorebyss[] = INCBIN_U32("graphics/pokemon/gorebyss/normal.gbapal.lz");
    const u32 gMonBackPic_Gorebyss[] = INCBIN_U32("graphics/pokemon/gorebyss/back.4bpp.lz");
    const u32 gMonShinyPalette_Gorebyss[] = INCBIN_U32("graphics/pokemon/gorebyss/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Gorebyss[] = INCBIN_U32("graphics/pokemon/gorebyss/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Gorebyss[] = INCBIN_U32("graphics/pokemon/gorebyss/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Gorebyss[] = INCBIN_U32("graphics/pokemon/gorebyss/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Gorebyss[] = INCBIN_U32("graphics/pokemon/gorebyss/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Gorebyss[] = INCBIN_U8("graphics/pokemon/gorebyss/icon.4bpp");
#else
    const u8 gMonIcon_Gorebyss[] = INCBIN_U8("graphics/pokemon/gorebyss/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Gorebyss[] = INCBIN_U8("graphics/pokemon/gorebyss/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Gorebyss[] = INCBIN_COMP("graphics/pokemon/gorebyss/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Gorebyss[] = INCBIN_U32("graphics/pokemon/gorebyss/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Gorebyss[] = INCBIN_U32("graphics/pokemon/gorebyss/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_CLAMPERL

#if P_FAMILY_RELICANTH
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Relicanth[] = INCBIN_U32("graphics/pokemon/relicanth/anim_front.4bpp.lz");
    const u32 gMonPalette_Relicanth[] = INCBIN_U32("graphics/pokemon/relicanth/normal.gbapal.lz");
    const u32 gMonBackPic_Relicanth[] = INCBIN_U32("graphics/pokemon/relicanth/back.4bpp.lz");
    const u32 gMonShinyPalette_Relicanth[] = INCBIN_U32("graphics/pokemon/relicanth/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Relicanth[] = INCBIN_U32("graphics/pokemon/relicanth/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Relicanth[] = INCBIN_U32("graphics/pokemon/relicanth/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Relicanth[] = INCBIN_U32("graphics/pokemon/relicanth/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Relicanth[] = INCBIN_U32("graphics/pokemon/relicanth/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Relicanth[] = INCBIN_U8("graphics/pokemon/relicanth/icon.4bpp");
#else
    const u8 gMonIcon_Relicanth[] = INCBIN_U8("graphics/pokemon/relicanth/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Relicanth[] = INCBIN_U8("graphics/pokemon/relicanth/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Relicanth[] = INCBIN_COMP("graphics/pokemon/relicanth/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Relicanth[] = INCBIN_U32("graphics/pokemon/relicanth/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Relicanth[] = INCBIN_U32("graphics/pokemon/relicanth/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_RelicanthF[] = INCBIN_U32("graphics/pokemon/relicanth/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_RelicanthF[] = INCBIN_U32("graphics/pokemon/relicanth/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_RelicanthF[] = INCBIN_COMP("graphics/pokemon/relicanth/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_RELICANTH

#if P_FAMILY_LUVDISC
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Luvdisc[] = INCBIN_U32("graphics/pokemon/luvdisc/anim_front.4bpp.lz");
    const u32 gMonPalette_Luvdisc[] = INCBIN_U32("graphics/pokemon/luvdisc/normal.gbapal.lz");
    const u32 gMonBackPic_Luvdisc[] = INCBIN_U32("graphics/pokemon/luvdisc/back.4bpp.lz");
    const u32 gMonShinyPalette_Luvdisc[] = INCBIN_U32("graphics/pokemon/luvdisc/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Luvdisc[] = INCBIN_U32("graphics/pokemon/luvdisc/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Luvdisc[] = INCBIN_U32("graphics/pokemon/luvdisc/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Luvdisc[] = INCBIN_U32("graphics/pokemon/luvdisc/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Luvdisc[] = INCBIN_U32("graphics/pokemon/luvdisc/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Luvdisc[] = INCBIN_U8("graphics/pokemon/luvdisc/icon.4bpp");
#else
    const u8 gMonIcon_Luvdisc[] = INCBIN_U8("graphics/pokemon/luvdisc/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Luvdisc[] = INCBIN_U8("graphics/pokemon/luvdisc/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Luvdisc[] = INCBIN_COMP("graphics/pokemon/luvdisc/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Luvdisc[] = INCBIN_U32("graphics/pokemon/luvdisc/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Luvdisc[] = INCBIN_U32("graphics/pokemon/luvdisc/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_LUVDISC

#if P_FAMILY_BAGON
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Bagon[] = INCBIN_U32("graphics/pokemon/bagon/anim_front.4bpp.lz");
    const u32 gMonPalette_Bagon[] = INCBIN_U32("graphics/pokemon/bagon/normal.gbapal.lz");
    const u32 gMonBackPic_Bagon[] = INCBIN_U32("graphics/pokemon/bagon/back.4bpp.lz");
    const u32 gMonShinyPalette_Bagon[] = INCBIN_U32("graphics/pokemon/bagon/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Bagon[] = INCBIN_U32("graphics/pokemon/bagon/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Bagon[] = INCBIN_U32("graphics/pokemon/bagon/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Bagon[] = INCBIN_U32("graphics/pokemon/bagon/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Bagon[] = INCBIN_U32("graphics/pokemon/bagon/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Bagon[] = INCBIN_U8("graphics/pokemon/bagon/icon.4bpp");
#else
    const u8 gMonIcon_Bagon[] = INCBIN_U8("graphics/pokemon/bagon/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Bagon[] = INCBIN_U8("graphics/pokemon/bagon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Bagon[] = INCBIN_COMP("graphics/pokemon/bagon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Bagon[] = INCBIN_U32("graphics/pokemon/bagon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Bagon[] = INCBIN_U32("graphics/pokemon/bagon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Shelgon[] = INCBIN_U32("graphics/pokemon/shelgon/anim_front.4bpp.lz");
    const u32 gMonPalette_Shelgon[] = INCBIN_U32("graphics/pokemon/shelgon/normal.gbapal.lz");
    const u32 gMonBackPic_Shelgon[] = INCBIN_U32("graphics/pokemon/shelgon/back.4bpp.lz");
    const u32 gMonShinyPalette_Shelgon[] = INCBIN_U32("graphics/pokemon/shelgon/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Shelgon[] = INCBIN_U32("graphics/pokemon/shelgon/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Shelgon[] = INCBIN_U32("graphics/pokemon/shelgon/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Shelgon[] = INCBIN_U32("graphics/pokemon/shelgon/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Shelgon[] = INCBIN_U32("graphics/pokemon/shelgon/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Shelgon[] = INCBIN_U8("graphics/pokemon/shelgon/icon.4bpp");
#else
    const u8 gMonIcon_Shelgon[] = INCBIN_U8("graphics/pokemon/shelgon/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Shelgon[] = INCBIN_U8("graphics/pokemon/shelgon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Shelgon[] = INCBIN_COMP("graphics/pokemon/shelgon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Shelgon[] = INCBIN_U32("graphics/pokemon/shelgon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Shelgon[] = INCBIN_U32("graphics/pokemon/shelgon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Salamence[] = INCBIN_U32("graphics/pokemon/salamence/anim_front.4bpp.lz");
    const u32 gMonPalette_Salamence[] = INCBIN_U32("graphics/pokemon/salamence/normal.gbapal.lz");
    const u32 gMonBackPic_Salamence[] = INCBIN_U32("graphics/pokemon/salamence/back.4bpp.lz");
    const u32 gMonShinyPalette_Salamence[] = INCBIN_U32("graphics/pokemon/salamence/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Salamence[] = INCBIN_U32("graphics/pokemon/salamence/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Salamence[] = INCBIN_U32("graphics/pokemon/salamence/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Salamence[] = INCBIN_U32("graphics/pokemon/salamence/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Salamence[] = INCBIN_U32("graphics/pokemon/salamence/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Salamence[] = INCBIN_U8("graphics/pokemon/salamence/icon.4bpp");
#else
    const u8 gMonIcon_Salamence[] = INCBIN_U8("graphics/pokemon/salamence/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Salamence[] = INCBIN_U8("graphics/pokemon/salamence/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Salamence[] = INCBIN_COMP("graphics/pokemon/salamence/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Salamence[] = INCBIN_U32("graphics/pokemon/salamence/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Salamence[] = INCBIN_U32("graphics/pokemon/salamence/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_BAGON

#if P_FAMILY_BELDUM
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Beldum[] = INCBIN_U32("graphics/pokemon/beldum/anim_front.4bpp.lz");
    const u32 gMonPalette_Beldum[] = INCBIN_U32("graphics/pokemon/beldum/normal.gbapal.lz");
    const u32 gMonBackPic_Beldum[] = INCBIN_U32("graphics/pokemon/beldum/back.4bpp.lz");
    const u32 gMonShinyPalette_Beldum[] = INCBIN_U32("graphics/pokemon/beldum/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Beldum[] = INCBIN_U32("graphics/pokemon/beldum/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Beldum[] = INCBIN_U32("graphics/pokemon/beldum/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Beldum[] = INCBIN_U32("graphics/pokemon/beldum/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Beldum[] = INCBIN_U32("graphics/pokemon/beldum/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Beldum[] = INCBIN_U8("graphics/pokemon/beldum/icon.4bpp");
#else
    const u8 gMonIcon_Beldum[] = INCBIN_U8("graphics/pokemon/beldum/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Beldum[] = INCBIN_U8("graphics/pokemon/beldum/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Beldum[] = INCBIN_COMP("graphics/pokemon/beldum/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Beldum[] = INCBIN_U32("graphics/pokemon/beldum/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Beldum[] = INCBIN_U32("graphics/pokemon/beldum/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Metang[] = INCBIN_U32("graphics/pokemon/metang/anim_front.4bpp.lz");
    const u32 gMonPalette_Metang[] = INCBIN_U32("graphics/pokemon/metang/normal.gbapal.lz");
    const u32 gMonBackPic_Metang[] = INCBIN_U32("graphics/pokemon/metang/back.4bpp.lz");
    const u32 gMonShinyPalette_Metang[] = INCBIN_U32("graphics/pokemon/metang/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Metang[] = INCBIN_U32("graphics/pokemon/metang/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Metang[] = INCBIN_U32("graphics/pokemon/metang/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Metang[] = INCBIN_U32("graphics/pokemon/metang/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Metang[] = INCBIN_U32("graphics/pokemon/metang/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Metang[] = INCBIN_U8("graphics/pokemon/metang/icon.4bpp");
#else
    const u8 gMonIcon_Metang[] = INCBIN_U8("graphics/pokemon/metang/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Metang[] = INCBIN_U8("graphics/pokemon/metang/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Metang[] = INCBIN_COMP("graphics/pokemon/metang/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Metang[] = INCBIN_U32("graphics/pokemon/metang/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Metang[] = INCBIN_U32("graphics/pokemon/metang/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Metagross[] = INCBIN_U32("graphics/pokemon/metagross/anim_front.4bpp.lz");
    const u32 gMonPalette_Metagross[] = INCBIN_U32("graphics/pokemon/metagross/normal.gbapal.lz");
    const u32 gMonBackPic_Metagross[] = INCBIN_U32("graphics/pokemon/metagross/back.4bpp.lz");
    const u32 gMonShinyPalette_Metagross[] = INCBIN_U32("graphics/pokemon/metagross/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Metagross[] = INCBIN_U32("graphics/pokemon/metagross/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Metagross[] = INCBIN_U32("graphics/pokemon/metagross/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Metagross[] = INCBIN_U32("graphics/pokemon/metagross/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Metagross[] = INCBIN_U32("graphics/pokemon/metagross/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Metagross[] = INCBIN_U8("graphics/pokemon/metagross/icon.4bpp");
#else
    const u8 gMonIcon_Metagross[] = INCBIN_U8("graphics/pokemon/metagross/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Metagross[] = INCBIN_U8("graphics/pokemon/metagross/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Metagross[] = INCBIN_COMP("graphics/pokemon/metagross/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Metagross[] = INCBIN_U32("graphics/pokemon/metagross/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Metagross[] = INCBIN_U32("graphics/pokemon/metagross/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_BELDUM

#if P_FAMILY_REGIROCK
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Regirock[] = INCBIN_U32("graphics/pokemon/regirock/anim_front.4bpp.lz");
    const u32 gMonPalette_Regirock[] = INCBIN_U32("graphics/pokemon/regirock/normal.gbapal.lz");
    const u32 gMonBackPic_Regirock[] = INCBIN_U32("graphics/pokemon/regirock/back.4bpp.lz");
    const u32 gMonShinyPalette_Regirock[] = INCBIN_U32("graphics/pokemon/regirock/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Regirock[] = INCBIN_U32("graphics/pokemon/regirock/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Regirock[] = INCBIN_U32("graphics/pokemon/regirock/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Regirock[] = INCBIN_U32("graphics/pokemon/regirock/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Regirock[] = INCBIN_U32("graphics/pokemon/regirock/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Regirock[] = INCBIN_U8("graphics/pokemon/regirock/icon.4bpp");
#else
    const u8 gMonIcon_Regirock[] = INCBIN_U8("graphics/pokemon/regirock/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Regirock[] = INCBIN_U8("graphics/pokemon/regirock/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Regirock[] = INCBIN_COMP("graphics/pokemon/regirock/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Regirock[] = INCBIN_U32("graphics/pokemon/regirock/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Regirock[] = INCBIN_U32("graphics/pokemon/regirock/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_REGIROCK

#if P_FAMILY_REGICE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Regice[] = INCBIN_U32("graphics/pokemon/regice/anim_front.4bpp.lz");
    const u32 gMonPalette_Regice[] = INCBIN_U32("graphics/pokemon/regice/normal.gbapal.lz");
    const u32 gMonBackPic_Regice[] = INCBIN_U32("graphics/pokemon/regice/back.4bpp.lz");
    const u32 gMonShinyPalette_Regice[] = INCBIN_U32("graphics/pokemon/regice/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Regice[] = INCBIN_U32("graphics/pokemon/regice/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Regice[] = INCBIN_U32("graphics/pokemon/regice/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Regice[] = INCBIN_U32("graphics/pokemon/regice/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Regice[] = INCBIN_U32("graphics/pokemon/regice/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Regice[] = INCBIN_U8("graphics/pokemon/regice/icon.4bpp");
#else
    const u8 gMonIcon_Regice[] = INCBIN_U8("graphics/pokemon/regice/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Regice[] = INCBIN_U8("graphics/pokemon/regice/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Regice[] = INCBIN_COMP("graphics/pokemon/regice/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Regice[] = INCBIN_U32("graphics/pokemon/regice/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Regice[] = INCBIN_U32("graphics/pokemon/regice/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_REGICE

#if P_FAMILY_REGISTEEL
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Registeel[] = INCBIN_U32("graphics/pokemon/registeel/anim_front.4bpp.lz");
    const u32 gMonPalette_Registeel[] = INCBIN_U32("graphics/pokemon/registeel/normal.gbapal.lz");
    const u32 gMonBackPic_Registeel[] = INCBIN_U32("graphics/pokemon/registeel/back.4bpp.lz");
    const u32 gMonShinyPalette_Registeel[] = INCBIN_U32("graphics/pokemon/registeel/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Registeel[] = INCBIN_U32("graphics/pokemon/registeel/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Registeel[] = INCBIN_U32("graphics/pokemon/registeel/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Registeel[] = INCBIN_U32("graphics/pokemon/registeel/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Registeel[] = INCBIN_U32("graphics/pokemon/registeel/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Registeel[] = INCBIN_U8("graphics/pokemon/registeel/icon.4bpp");
#else
    const u8 gMonIcon_Registeel[] = INCBIN_U8("graphics/pokemon/registeel/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Registeel[] = INCBIN_U8("graphics/pokemon/registeel/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Registeel[] = INCBIN_COMP("graphics/pokemon/registeel/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Registeel[] = INCBIN_U32("graphics/pokemon/registeel/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Registeel[] = INCBIN_U32("graphics/pokemon/registeel/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_REGISTEEL

#if P_FAMILY_LATIAS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Latias[] = INCBIN_U32("graphics/pokemon/latias/anim_front.4bpp.lz");
    const u32 gMonPalette_Latias[] = INCBIN_U32("graphics/pokemon/latias/normal.gbapal.lz");
    const u32 gMonBackPic_Latias[] = INCBIN_U32("graphics/pokemon/latias/back.4bpp.lz");
    const u32 gMonShinyPalette_Latias[] = INCBIN_U32("graphics/pokemon/latias/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Latias[] = INCBIN_U32("graphics/pokemon/latias/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Latias[] = INCBIN_U32("graphics/pokemon/latias/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Latias[] = INCBIN_U32("graphics/pokemon/latias/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Latias[] = INCBIN_U32("graphics/pokemon/latias/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Latias[] = INCBIN_U8("graphics/pokemon/latias/icon.4bpp");
#else
    const u8 gMonIcon_Latias[] = INCBIN_U8("graphics/pokemon/latias/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Latias[] = INCBIN_U8("graphics/pokemon/latias/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Latias[] = INCBIN_COMP("graphics/pokemon/latias/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Latias[] = INCBIN_U32("graphics/pokemon/latias/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Latias[] = INCBIN_U32("graphics/pokemon/latias/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_LATIAS

#if P_FAMILY_LATIOS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Latios[] = INCBIN_U32("graphics/pokemon/latios/anim_front.4bpp.lz");
    const u32 gMonPalette_Latios[] = INCBIN_U32("graphics/pokemon/latios/normal.gbapal.lz");
    const u32 gMonBackPic_Latios[] = INCBIN_U32("graphics/pokemon/latios/back.4bpp.lz");
    const u32 gMonShinyPalette_Latios[] = INCBIN_U32("graphics/pokemon/latios/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Latios[] = INCBIN_U32("graphics/pokemon/latios/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Latios[] = INCBIN_U32("graphics/pokemon/latios/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Latios[] = INCBIN_U32("graphics/pokemon/latios/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Latios[] = INCBIN_U32("graphics/pokemon/latios/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Latios[] = INCBIN_U8("graphics/pokemon/latios/icon.4bpp");
#else
    const u8 gMonIcon_Latios[] = INCBIN_U8("graphics/pokemon/latios/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Latios[] = INCBIN_U8("graphics/pokemon/latios/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Latios[] = INCBIN_COMP("graphics/pokemon/latios/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Latios[] = INCBIN_U32("graphics/pokemon/latios/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Latios[] = INCBIN_U32("graphics/pokemon/latios/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_LATIOS

#if P_FAMILY_KYOGRE
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Kyogre[] = INCBIN_U32("graphics/pokemon/kyogre/anim_front.4bpp.lz");
    const u32 gMonPalette_Kyogre[] = INCBIN_U32("graphics/pokemon/kyogre/normal.gbapal.lz");
    const u32 gMonBackPic_Kyogre[] = INCBIN_U32("graphics/pokemon/kyogre/back.4bpp.lz");
    const u32 gMonShinyPalette_Kyogre[] = INCBIN_U32("graphics/pokemon/kyogre/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Kyogre[] = INCBIN_U32("graphics/pokemon/kyogre/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Kyogre[] = INCBIN_U32("graphics/pokemon/kyogre/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Kyogre[] = INCBIN_U32("graphics/pokemon/kyogre/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Kyogre[] = INCBIN_U32("graphics/pokemon/kyogre/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Kyogre[] = INCBIN_U8("graphics/pokemon/kyogre/icon.4bpp");
#else
    const u8 gMonIcon_Kyogre[] = INCBIN_U8("graphics/pokemon/kyogre/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Kyogre[] = INCBIN_U8("graphics/pokemon/kyogre/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Kyogre[] = INCBIN_COMP("graphics/pokemon/kyogre/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Kyogre[] = INCBIN_U32("graphics/pokemon/kyogre/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Kyogre[] = INCBIN_U32("graphics/pokemon/kyogre/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_PRIMAL_REVERSIONS
    const u32 gMonFrontPic_KyogrePrimal[] = INCBIN_U32("graphics/pokemon/kyogre/primal/front.4bpp.lz");
    const u32 gMonPalette_KyogrePrimal[] = INCBIN_U32("graphics/pokemon/kyogre/primal/normal.gbapal.lz");
    const u32 gMonBackPic_KyogrePrimal[] = INCBIN_U32("graphics/pokemon/kyogre/primal/back.4bpp.lz");
    const u32 gMonShinyPalette_KyogrePrimal[] = INCBIN_U32("graphics/pokemon/kyogre/primal/shiny.gbapal.lz");
    const u8 gMonIcon_KyogrePrimal[] = INCBIN_U8("graphics/pokemon/kyogre/primal/icon.4bpp");
#if OW_POKEMON_OBJECT_EVENTS && OW_BATTLE_ONLY_FORMS
    const u32 gObjectEventPic_KyogrePrimal[] = INCBIN_COMP("graphics/pokemon/kyogre/primal/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_KyogrePrimal[] = INCBIN_U32("graphics/pokemon/kyogre/primal/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_KyogrePrimal[] = INCBIN_U32("graphics/pokemon/kyogre/primal/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS && OW_BATTLE_ONLY_FORMS
#endif //P_PRIMAL_REVERSIONS
#endif //P_FAMILY_KYOGRE

#if P_FAMILY_GROUDON
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Groudon[] = INCBIN_U32("graphics/pokemon/groudon/anim_front.4bpp.lz");
    const u32 gMonPalette_Groudon[] = INCBIN_U32("graphics/pokemon/groudon/normal.gbapal.lz");
    const u32 gMonBackPic_Groudon[] = INCBIN_U32("graphics/pokemon/groudon/back.4bpp.lz");
    const u32 gMonShinyPalette_Groudon[] = INCBIN_U32("graphics/pokemon/groudon/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Groudon[] = INCBIN_U32("graphics/pokemon/groudon/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Groudon[] = INCBIN_U32("graphics/pokemon/groudon/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Groudon[] = INCBIN_U32("graphics/pokemon/groudon/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Groudon[] = INCBIN_U32("graphics/pokemon/groudon/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Groudon[] = INCBIN_U8("graphics/pokemon/groudon/icon.4bpp");
#else
    const u8 gMonIcon_Groudon[] = INCBIN_U8("graphics/pokemon/groudon/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Groudon[] = INCBIN_U8("graphics/pokemon/groudon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Groudon[] = INCBIN_COMP("graphics/pokemon/groudon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Groudon[] = INCBIN_U32("graphics/pokemon/groudon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Groudon[] = INCBIN_U32("graphics/pokemon/groudon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_PRIMAL_REVERSIONS
    const u32 gMonFrontPic_GroudonPrimal[] = INCBIN_U32("graphics/pokemon/groudon/primal/front.4bpp.lz");
    const u32 gMonPalette_GroudonPrimal[] = INCBIN_U32("graphics/pokemon/groudon/primal/normal.gbapal.lz");
    const u32 gMonBackPic_GroudonPrimal[] = INCBIN_U32("graphics/pokemon/groudon/primal/back.4bpp.lz");
    const u32 gMonShinyPalette_GroudonPrimal[] = INCBIN_U32("graphics/pokemon/groudon/primal/shiny.gbapal.lz");
    const u8 gMonIcon_GroudonPrimal[] = INCBIN_U8("graphics/pokemon/groudon/primal/icon.4bpp");
#if OW_POKEMON_OBJECT_EVENTS && OW_BATTLE_ONLY_FORMS
    const u32 gObjectEventPic_GroudonPrimal[] = INCBIN_COMP("graphics/pokemon/groudon/primal/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_GroudonPrimal[] = INCBIN_U32("graphics/pokemon/groudon/primal/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_GroudonPrimal[] = INCBIN_U32("graphics/pokemon/groudon/primal/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS && OW_BATTLE_ONLY_FORMS
#endif //P_PRIMAL_REVERSIONS
#endif //P_FAMILY_GROUDON

#if P_FAMILY_RAYQUAZA
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Rayquaza[] = INCBIN_U32("graphics/pokemon/rayquaza/anim_front.4bpp.lz");
    const u32 gMonPalette_Rayquaza[] = INCBIN_U32("graphics/pokemon/rayquaza/normal.gbapal.lz");
    const u32 gMonBackPic_Rayquaza[] = INCBIN_U32("graphics/pokemon/rayquaza/back.4bpp.lz");
    const u32 gMonShinyPalette_Rayquaza[] = INCBIN_U32("graphics/pokemon/rayquaza/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Rayquaza[] = INCBIN_U32("graphics/pokemon/rayquaza/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Rayquaza[] = INCBIN_U32("graphics/pokemon/rayquaza/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Rayquaza[] = INCBIN_U32("graphics/pokemon/rayquaza/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Rayquaza[] = INCBIN_U32("graphics/pokemon/rayquaza/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Rayquaza[] = INCBIN_U8("graphics/pokemon/rayquaza/icon.4bpp");
#else
    const u8 gMonIcon_Rayquaza[] = INCBIN_U8("graphics/pokemon/rayquaza/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Rayquaza[] = INCBIN_U8("graphics/pokemon/rayquaza/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Rayquaza[] = INCBIN_COMP("graphics/pokemon/rayquaza/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Rayquaza[] = INCBIN_U32("graphics/pokemon/rayquaza/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Rayquaza[] = INCBIN_U32("graphics/pokemon/rayquaza/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_RAYQUAZA

#if P_FAMILY_JIRACHI
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_Jirachi[] = INCBIN_U32("graphics/pokemon/jirachi/anim_front.4bpp.lz");
    const u32 gMonPalette_Jirachi[] = INCBIN_U32("graphics/pokemon/jirachi/normal.gbapal.lz");
    const u32 gMonBackPic_Jirachi[] = INCBIN_U32("graphics/pokemon/jirachi/back.4bpp.lz");
    const u32 gMonShinyPalette_Jirachi[] = INCBIN_U32("graphics/pokemon/jirachi/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_Jirachi[] = INCBIN_U32("graphics/pokemon/jirachi/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_Jirachi[] = INCBIN_U32("graphics/pokemon/jirachi/normal_gba.gbapal.lz");
    const u32 gMonBackPic_Jirachi[] = INCBIN_U32("graphics/pokemon/jirachi/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_Jirachi[] = INCBIN_U32("graphics/pokemon/jirachi/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_Jirachi[] = INCBIN_U8("graphics/pokemon/jirachi/icon.4bpp");
#else
    const u8 gMonIcon_Jirachi[] = INCBIN_U8("graphics/pokemon/jirachi/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Jirachi[] = INCBIN_U8("graphics/pokemon/jirachi/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Jirachi[] = INCBIN_COMP("graphics/pokemon/jirachi/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Jirachi[] = INCBIN_U32("graphics/pokemon/jirachi/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Jirachi[] = INCBIN_U32("graphics/pokemon/jirachi/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_JIRACHI

#if P_FAMILY_DEOXYS
#if !P_GBA_STYLE_SPECIES_GFX
    const u32 gMonFrontPic_DeoxysNormal[] = INCBIN_U32("graphics/pokemon/deoxys/anim_front.4bpp.lz");
    const u32 gMonPalette_DeoxysNormal[] = INCBIN_U32("graphics/pokemon/deoxys/normal.gbapal.lz");
    const u32 gMonBackPic_DeoxysNormal[] = INCBIN_U32("graphics/pokemon/deoxys/back.4bpp.lz");
    const u32 gMonShinyPalette_DeoxysNormal[] = INCBIN_U32("graphics/pokemon/deoxys/shiny.gbapal.lz");
#else
    const u32 gMonFrontPic_DeoxysNormal[] = INCBIN_U32("graphics/pokemon/deoxys/anim_front_gba.4bpp.lz");
    const u32 gMonPalette_DeoxysNormal[] = INCBIN_U32("graphics/pokemon/deoxys/normal_gba.gbapal.lz");
    const u32 gMonBackPic_DeoxysNormal[] = INCBIN_U32("graphics/pokemon/deoxys/back_gba.4bpp.lz");
    const u32 gMonShinyPalette_DeoxysNormal[] = INCBIN_U32("graphics/pokemon/deoxys/shiny_gba.gbapal.lz");
#endif //P_GBA_STYLE_SPECIES_GFX
#if !P_GBA_STYLE_SPECIES_ICONS
    const u8 gMonIcon_DeoxysNormal[] = INCBIN_U8("graphics/pokemon/deoxys/icon.4bpp");
#else
    const u8 gMonIcon_DeoxysNormal[] = INCBIN_U8("graphics/pokemon/deoxys/icon_gba.4bpp");
#endif //P_GBA_STYLE_SPECIES_ICONS
#if P_FOOTPRINTS
    const u8 gMonFootprint_Deoxys[] = INCBIN_U8("graphics/pokemon/deoxys/footprint.1bpp");
#endif //P_FOOTPRINTS

    const u32 gMonFrontPic_DeoxysAttack[] = INCBIN_U32("graphics/pokemon/deoxys/attack/anim_front.4bpp.lz");
    const u32 gMonPalette_DeoxysAttack[] = INCBIN_U32("graphics/pokemon/deoxys/attack/normal.gbapal.lz");
    const u32 gMonBackPic_DeoxysAttack[] = INCBIN_U32("graphics/pokemon/deoxys/attack/back.4bpp.lz");
    const u32 gMonShinyPalette_DeoxysAttack[] = INCBIN_U32("graphics/pokemon/deoxys/attack/shiny.gbapal.lz");
    const u8 gMonIcon_DeoxysAttack[] = INCBIN_U8("graphics/pokemon/deoxys/attack/icon.4bpp");

    const u32 gMonFrontPic_DeoxysDefense[] = INCBIN_U32("graphics/pokemon/deoxys/defense/anim_front.4bpp.lz");
    const u32 gMonPalette_DeoxysDefense[] = INCBIN_U32("graphics/pokemon/deoxys/defense/normal.gbapal.lz");
    const u32 gMonBackPic_DeoxysDefense[] = INCBIN_U32("graphics/pokemon/deoxys/defense/back.4bpp.lz");
    const u32 gMonShinyPalette_DeoxysDefense[] = INCBIN_U32("graphics/pokemon/deoxys/defense/shiny.gbapal.lz");
    const u8 gMonIcon_DeoxysDefense[] = INCBIN_U8("graphics/pokemon/deoxys/defense/icon.4bpp");

    const u32 gMonFrontPic_DeoxysSpeed[] = INCBIN_U32("graphics/pokemon/deoxys/speed/anim_front.4bpp.lz");
    const u32 gMonPalette_DeoxysSpeed[] = INCBIN_U32("graphics/pokemon/deoxys/speed/normal.gbapal.lz");
    const u32 gMonBackPic_DeoxysSpeed[] = INCBIN_U32("graphics/pokemon/deoxys/speed/back.4bpp.lz");
    const u32 gMonShinyPalette_DeoxysSpeed[] = INCBIN_U32("graphics/pokemon/deoxys/speed/shiny.gbapal.lz");
    const u8 gMonIcon_DeoxysSpeed[] = INCBIN_U8("graphics/pokemon/deoxys/speed/icon.4bpp");

#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_DeoxysNormal[] = INCBIN_COMP("graphics/pokemon/deoxys/overworld.4bpp");
    const u32 gObjectEventPic_DeoxysAttack[] = INCBIN_COMP("graphics/pokemon/deoxys/attack/overworld.4bpp");
    const u32 gObjectEventPic_DeoxysDefense[] = INCBIN_COMP("graphics/pokemon/deoxys/defense/overworld.4bpp");
    const u32 gObjectEventPic_DeoxysSpeed[] = INCBIN_COMP("graphics/pokemon/deoxys/speed/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_DeoxysNormal[] = INCBIN_U32("graphics/pokemon/deoxys/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_DeoxysAttack[] = INCBIN_U32("graphics/pokemon/deoxys/attack/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_DeoxysDefense[] = INCBIN_U32("graphics/pokemon/deoxys/defense/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_DeoxysSpeed[] = INCBIN_U32("graphics/pokemon/deoxys/speed/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_DeoxysNormal[] = INCBIN_U32("graphics/pokemon/deoxys/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_DeoxysAttack[] = INCBIN_U32("graphics/pokemon/deoxys/attack/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_DeoxysDefense[] = INCBIN_U32("graphics/pokemon/deoxys/defense/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_DeoxysSpeed[] = INCBIN_U32("graphics/pokemon/deoxys/speed/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_DEOXYS

#if P_FAMILY_TURTWIG
    const u32 gMonFrontPic_Turtwig[] = INCBIN_U32("graphics/pokemon/turtwig/anim_front.4bpp.lz");
    const u32 gMonPalette_Turtwig[] = INCBIN_U32("graphics/pokemon/turtwig/normal.gbapal.lz");
    const u32 gMonBackPic_Turtwig[] = INCBIN_U32("graphics/pokemon/turtwig/back.4bpp.lz");
    const u32 gMonShinyPalette_Turtwig[] = INCBIN_U32("graphics/pokemon/turtwig/shiny.gbapal.lz");
    const u8 gMonIcon_Turtwig[] = INCBIN_U8("graphics/pokemon/turtwig/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Turtwig[] = INCBIN_U8("graphics/pokemon/turtwig/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Turtwig[] = INCBIN_COMP("graphics/pokemon/turtwig/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Turtwig[] = INCBIN_U32("graphics/pokemon/turtwig/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Turtwig[] = INCBIN_U32("graphics/pokemon/turtwig/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_Grotle[] = INCBIN_U32("graphics/pokemon/grotle/anim_front.4bpp.lz");
    const u32 gMonPalette_Grotle[] = INCBIN_U32("graphics/pokemon/grotle/normal.gbapal.lz");
    const u32 gMonBackPic_Grotle[] = INCBIN_U32("graphics/pokemon/grotle/back.4bpp.lz");
    const u32 gMonShinyPalette_Grotle[] = INCBIN_U32("graphics/pokemon/grotle/shiny.gbapal.lz");
    const u8 gMonIcon_Grotle[] = INCBIN_U8("graphics/pokemon/grotle/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Grotle[] = INCBIN_U8("graphics/pokemon/grotle/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Grotle[] = INCBIN_COMP("graphics/pokemon/grotle/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Grotle[] = INCBIN_U32("graphics/pokemon/grotle/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Grotle[] = INCBIN_U32("graphics/pokemon/grotle/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_Torterra[] = INCBIN_U32("graphics/pokemon/torterra/anim_front.4bpp.lz");
    const u32 gMonPalette_Torterra[] = INCBIN_U32("graphics/pokemon/torterra/normal.gbapal.lz");
    const u32 gMonBackPic_Torterra[] = INCBIN_U32("graphics/pokemon/torterra/back.4bpp.lz");
    const u32 gMonShinyPalette_Torterra[] = INCBIN_U32("graphics/pokemon/torterra/shiny.gbapal.lz");
    const u8 gMonIcon_Torterra[] = INCBIN_U8("graphics/pokemon/torterra/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Torterra[] = INCBIN_U8("graphics/pokemon/torterra/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Torterra[] = INCBIN_COMP("graphics/pokemon/torterra/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Torterra[] = INCBIN_U32("graphics/pokemon/torterra/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Torterra[] = INCBIN_U32("graphics/pokemon/torterra/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_TURTWIG

#if P_FAMILY_CHIMCHAR
    const u32 gMonFrontPic_Chimchar[] = INCBIN_U32("graphics/pokemon/chimchar/anim_front.4bpp.lz");
    const u32 gMonPalette_Chimchar[] = INCBIN_U32("graphics/pokemon/chimchar/normal.gbapal.lz");
    const u32 gMonBackPic_Chimchar[] = INCBIN_U32("graphics/pokemon/chimchar/back.4bpp.lz");
    const u32 gMonShinyPalette_Chimchar[] = INCBIN_U32("graphics/pokemon/chimchar/shiny.gbapal.lz");
    const u8 gMonIcon_Chimchar[] = INCBIN_U8("graphics/pokemon/chimchar/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Chimchar[] = INCBIN_U8("graphics/pokemon/chimchar/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Chimchar[] = INCBIN_COMP("graphics/pokemon/chimchar/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Chimchar[] = INCBIN_U32("graphics/pokemon/chimchar/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Chimchar[] = INCBIN_U32("graphics/pokemon/chimchar/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_Monferno[] = INCBIN_U32("graphics/pokemon/monferno/anim_front.4bpp.lz");
    const u32 gMonPalette_Monferno[] = INCBIN_U32("graphics/pokemon/monferno/normal.gbapal.lz");
    const u32 gMonBackPic_Monferno[] = INCBIN_U32("graphics/pokemon/monferno/back.4bpp.lz");
    const u32 gMonShinyPalette_Monferno[] = INCBIN_U32("graphics/pokemon/monferno/shiny.gbapal.lz");
    const u8 gMonIcon_Monferno[] = INCBIN_U8("graphics/pokemon/monferno/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Monferno[] = INCBIN_U8("graphics/pokemon/monferno/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Monferno[] = INCBIN_COMP("graphics/pokemon/monferno/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Monferno[] = INCBIN_U32("graphics/pokemon/monferno/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Monferno[] = INCBIN_U32("graphics/pokemon/monferno/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_Infernape[] = INCBIN_U32("graphics/pokemon/infernape/anim_front.4bpp.lz");
    const u32 gMonPalette_Infernape[] = INCBIN_U32("graphics/pokemon/infernape/normal.gbapal.lz");
    const u32 gMonBackPic_Infernape[] = INCBIN_U32("graphics/pokemon/infernape/back.4bpp.lz");
    const u32 gMonShinyPalette_Infernape[] = INCBIN_U32("graphics/pokemon/infernape/shiny.gbapal.lz");
    const u8 gMonIcon_Infernape[] = INCBIN_U8("graphics/pokemon/infernape/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Infernape[] = INCBIN_U8("graphics/pokemon/infernape/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Infernape[] = INCBIN_COMP("graphics/pokemon/infernape/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Infernape[] = INCBIN_U32("graphics/pokemon/infernape/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Infernape[] = INCBIN_U32("graphics/pokemon/infernape/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_CHIMCHAR

#if P_FAMILY_PIPLUP
    const u32 gMonFrontPic_Piplup[] = INCBIN_U32("graphics/pokemon/piplup/anim_front.4bpp.lz");
    const u32 gMonPalette_Piplup[] = INCBIN_U32("graphics/pokemon/piplup/normal.gbapal.lz");
    const u32 gMonBackPic_Piplup[] = INCBIN_U32("graphics/pokemon/piplup/back.4bpp.lz");
    const u32 gMonShinyPalette_Piplup[] = INCBIN_U32("graphics/pokemon/piplup/shiny.gbapal.lz");
    const u8 gMonIcon_Piplup[] = INCBIN_U8("graphics/pokemon/piplup/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Piplup[] = INCBIN_U8("graphics/pokemon/piplup/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Piplup[] = INCBIN_COMP("graphics/pokemon/piplup/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Piplup[] = INCBIN_U32("graphics/pokemon/piplup/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Piplup[] = INCBIN_U32("graphics/pokemon/piplup/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_Prinplup[] = INCBIN_U32("graphics/pokemon/prinplup/anim_front.4bpp.lz");
    const u32 gMonPalette_Prinplup[] = INCBIN_U32("graphics/pokemon/prinplup/normal.gbapal.lz");
    const u32 gMonBackPic_Prinplup[] = INCBIN_U32("graphics/pokemon/prinplup/back.4bpp.lz");
    const u32 gMonShinyPalette_Prinplup[] = INCBIN_U32("graphics/pokemon/prinplup/shiny.gbapal.lz");
    const u8 gMonIcon_Prinplup[] = INCBIN_U8("graphics/pokemon/prinplup/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Prinplup[] = INCBIN_U8("graphics/pokemon/prinplup/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Prinplup[] = INCBIN_COMP("graphics/pokemon/prinplup/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Prinplup[] = INCBIN_U32("graphics/pokemon/prinplup/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Prinplup[] = INCBIN_U32("graphics/pokemon/prinplup/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_Empoleon[] = INCBIN_U32("graphics/pokemon/empoleon/anim_front.4bpp.lz");
    const u32 gMonPalette_Empoleon[] = INCBIN_U32("graphics/pokemon/empoleon/normal.gbapal.lz");
    const u32 gMonBackPic_Empoleon[] = INCBIN_U32("graphics/pokemon/empoleon/back.4bpp.lz");
    const u32 gMonShinyPalette_Empoleon[] = INCBIN_U32("graphics/pokemon/empoleon/shiny.gbapal.lz");
    const u8 gMonIcon_Empoleon[] = INCBIN_U8("graphics/pokemon/empoleon/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Empoleon[] = INCBIN_U8("graphics/pokemon/empoleon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Empoleon[] = INCBIN_COMP("graphics/pokemon/empoleon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Empoleon[] = INCBIN_U32("graphics/pokemon/empoleon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Empoleon[] = INCBIN_U32("graphics/pokemon/empoleon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_PIPLUP

#if P_FAMILY_STARLY
    const u32 gMonFrontPic_Starly[] = INCBIN_U32("graphics/pokemon/starly/anim_front.4bpp.lz");
    const u32 gMonPalette_Starly[] = INCBIN_U32("graphics/pokemon/starly/normal.gbapal.lz");
    const u32 gMonBackPic_Starly[] = INCBIN_U32("graphics/pokemon/starly/back.4bpp.lz");
    const u32 gMonShinyPalette_Starly[] = INCBIN_U32("graphics/pokemon/starly/shiny.gbapal.lz");
    const u8 gMonIcon_Starly[] = INCBIN_U8("graphics/pokemon/starly/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Starly[] = INCBIN_U8("graphics/pokemon/starly/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Starly[] = INCBIN_COMP("graphics/pokemon/starly/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Starly[] = INCBIN_U32("graphics/pokemon/starly/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Starly[] = INCBIN_U32("graphics/pokemon/starly/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_StarlyF[] = INCBIN_U32("graphics/pokemon/starly/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_StarlyF[] = INCBIN_U32("graphics/pokemon/starly/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_StarlyF[] = INCBIN_COMP("graphics/pokemon/starly/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

    const u32 gMonFrontPic_Staravia[] = INCBIN_U32("graphics/pokemon/staravia/anim_front.4bpp.lz");
    const u32 gMonPalette_Staravia[] = INCBIN_U32("graphics/pokemon/staravia/normal.gbapal.lz");
    const u32 gMonBackPic_Staravia[] = INCBIN_U32("graphics/pokemon/staravia/back.4bpp.lz");
    const u32 gMonShinyPalette_Staravia[] = INCBIN_U32("graphics/pokemon/staravia/shiny.gbapal.lz");
    const u8 gMonIcon_Staravia[] = INCBIN_U8("graphics/pokemon/staravia/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Staravia[] = INCBIN_U8("graphics/pokemon/staravia/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Staravia[] = INCBIN_COMP("graphics/pokemon/staravia/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Staravia[] = INCBIN_U32("graphics/pokemon/staravia/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Staravia[] = INCBIN_U32("graphics/pokemon/staravia/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_StaraviaF[] = INCBIN_U32("graphics/pokemon/staravia/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_StaraviaF[] = INCBIN_U32("graphics/pokemon/staravia/back.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_StaraviaF[] = INCBIN_COMP("graphics/pokemon/staravia/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

    const u32 gMonFrontPic_Staraptor[] = INCBIN_U32("graphics/pokemon/staraptor/anim_front.4bpp.lz");
    const u32 gMonPalette_Staraptor[] = INCBIN_U32("graphics/pokemon/staraptor/normal.gbapal.lz");
    const u32 gMonBackPic_Staraptor[] = INCBIN_U32("graphics/pokemon/staraptor/back.4bpp.lz");
    const u32 gMonShinyPalette_Staraptor[] = INCBIN_U32("graphics/pokemon/staraptor/shiny.gbapal.lz");
    const u8 gMonIcon_Staraptor[] = INCBIN_U8("graphics/pokemon/staraptor/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Staraptor[] = INCBIN_U8("graphics/pokemon/staraptor/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Staraptor[] = INCBIN_COMP("graphics/pokemon/staraptor/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Staraptor[] = INCBIN_U32("graphics/pokemon/staraptor/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Staraptor[] = INCBIN_U32("graphics/pokemon/staraptor/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_StaraptorF[] = INCBIN_U32("graphics/pokemon/staraptor/anim_frontf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_StaraptorF[] = INCBIN_COMP("graphics/pokemon/staraptor/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_STARLY

#if P_FAMILY_BIDOOF
    const u32 gMonFrontPic_Bidoof[] = INCBIN_U32("graphics/pokemon/bidoof/anim_front.4bpp.lz");
    const u32 gMonPalette_Bidoof[] = INCBIN_U32("graphics/pokemon/bidoof/normal.gbapal.lz");
    const u32 gMonBackPic_Bidoof[] = INCBIN_U32("graphics/pokemon/bidoof/back.4bpp.lz");
    const u32 gMonShinyPalette_Bidoof[] = INCBIN_U32("graphics/pokemon/bidoof/shiny.gbapal.lz");
    const u8 gMonIcon_Bidoof[] = INCBIN_U8("graphics/pokemon/bidoof/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Bidoof[] = INCBIN_U8("graphics/pokemon/bidoof/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Bidoof[] = INCBIN_COMP("graphics/pokemon/bidoof/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Bidoof[] = INCBIN_U32("graphics/pokemon/bidoof/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Bidoof[] = INCBIN_U32("graphics/pokemon/bidoof/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_BidoofF[] = INCBIN_U32("graphics/pokemon/bidoof/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_BidoofF[] = INCBIN_U32("graphics/pokemon/bidoof/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_BidoofF[] = INCBIN_COMP("graphics/pokemon/bidoof/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

    const u32 gMonFrontPic_Bibarel[] = INCBIN_U32("graphics/pokemon/bibarel/anim_front.4bpp.lz");
    const u32 gMonPalette_Bibarel[] = INCBIN_U32("graphics/pokemon/bibarel/normal.gbapal.lz");
    const u32 gMonBackPic_Bibarel[] = INCBIN_U32("graphics/pokemon/bibarel/back.4bpp.lz");
    const u32 gMonShinyPalette_Bibarel[] = INCBIN_U32("graphics/pokemon/bibarel/shiny.gbapal.lz");
    const u8 gMonIcon_Bibarel[] = INCBIN_U8("graphics/pokemon/bibarel/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Bibarel[] = INCBIN_U8("graphics/pokemon/bibarel/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Bibarel[] = INCBIN_COMP("graphics/pokemon/bibarel/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Bibarel[] = INCBIN_U32("graphics/pokemon/bibarel/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Bibarel[] = INCBIN_U32("graphics/pokemon/bibarel/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_BibarelF[] = INCBIN_U32("graphics/pokemon/bibarel/anim_frontf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_BibarelF[] = INCBIN_COMP("graphics/pokemon/bibarel/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_BIDOOF

#if P_FAMILY_KRICKETOT
    const u32 gMonFrontPic_Kricketot[] = INCBIN_U32("graphics/pokemon/kricketot/anim_front.4bpp.lz");
    const u32 gMonPalette_Kricketot[] = INCBIN_U32("graphics/pokemon/kricketot/normal.gbapal.lz");
    const u32 gMonBackPic_Kricketot[] = INCBIN_U32("graphics/pokemon/kricketot/back.4bpp.lz");
    const u32 gMonShinyPalette_Kricketot[] = INCBIN_U32("graphics/pokemon/kricketot/shiny.gbapal.lz");
    const u8 gMonIcon_Kricketot[] = INCBIN_U8("graphics/pokemon/kricketot/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Kricketot[] = INCBIN_U8("graphics/pokemon/kricketot/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Kricketot[] = INCBIN_COMP("graphics/pokemon/kricketot/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Kricketot[] = INCBIN_U32("graphics/pokemon/kricketot/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Kricketot[] = INCBIN_U32("graphics/pokemon/kricketot/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_KricketotF[] = INCBIN_U32("graphics/pokemon/kricketot/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_KricketotF[] = INCBIN_U32("graphics/pokemon/kricketot/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_KricketotF[] = INCBIN_COMP("graphics/pokemon/kricketot/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

    const u32 gMonFrontPic_Kricketune[] = INCBIN_U32("graphics/pokemon/kricketune/anim_front.4bpp.lz");
    const u32 gMonPalette_Kricketune[] = INCBIN_U32("graphics/pokemon/kricketune/normal.gbapal.lz");
    const u32 gMonBackPic_Kricketune[] = INCBIN_U32("graphics/pokemon/kricketune/back.4bpp.lz");
    const u32 gMonShinyPalette_Kricketune[] = INCBIN_U32("graphics/pokemon/kricketune/shiny.gbapal.lz");
    const u8 gMonIcon_Kricketune[] = INCBIN_U8("graphics/pokemon/kricketune/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Kricketune[] = INCBIN_U8("graphics/pokemon/kricketune/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Kricketune[] = INCBIN_COMP("graphics/pokemon/kricketune/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Kricketune[] = INCBIN_U32("graphics/pokemon/kricketune/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Kricketune[] = INCBIN_U32("graphics/pokemon/kricketune/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_KricketuneF[] = INCBIN_U32("graphics/pokemon/kricketune/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_KricketuneF[] = INCBIN_U32("graphics/pokemon/kricketune/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_KricketuneF[] = INCBIN_COMP("graphics/pokemon/kricketune/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_KRICKETOT

#if P_FAMILY_SHINX
    const u32 gMonFrontPic_Shinx[] = INCBIN_U32("graphics/pokemon/shinx/anim_front.4bpp.lz");
    const u32 gMonPalette_Shinx[] = INCBIN_U32("graphics/pokemon/shinx/normal.gbapal.lz");
    const u32 gMonBackPic_Shinx[] = INCBIN_U32("graphics/pokemon/shinx/back.4bpp.lz");
    const u32 gMonShinyPalette_Shinx[] = INCBIN_U32("graphics/pokemon/shinx/shiny.gbapal.lz");
    const u8 gMonIcon_Shinx[] = INCBIN_U8("graphics/pokemon/shinx/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Shinx[] = INCBIN_U8("graphics/pokemon/shinx/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Shinx[] = INCBIN_COMP("graphics/pokemon/shinx/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Shinx[] = INCBIN_U32("graphics/pokemon/shinx/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Shinx[] = INCBIN_U32("graphics/pokemon/shinx/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_ShinxF[] = INCBIN_U32("graphics/pokemon/shinx/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_ShinxF[] = INCBIN_U32("graphics/pokemon/shinx/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_ShinxF[] = INCBIN_COMP("graphics/pokemon/shinx/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

    const u32 gMonFrontPic_Luxio[] = INCBIN_U32("graphics/pokemon/luxio/anim_front.4bpp.lz");
    const u32 gMonPalette_Luxio[] = INCBIN_U32("graphics/pokemon/luxio/normal.gbapal.lz");
    const u32 gMonBackPic_Luxio[] = INCBIN_U32("graphics/pokemon/luxio/back.4bpp.lz");
    const u32 gMonShinyPalette_Luxio[] = INCBIN_U32("graphics/pokemon/luxio/shiny.gbapal.lz");
    const u8 gMonIcon_Luxio[] = INCBIN_U8("graphics/pokemon/luxio/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Luxio[] = INCBIN_U8("graphics/pokemon/luxio/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Luxio[] = INCBIN_COMP("graphics/pokemon/luxio/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Luxio[] = INCBIN_U32("graphics/pokemon/luxio/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Luxio[] = INCBIN_U32("graphics/pokemon/luxio/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_LuxioF[] = INCBIN_U32("graphics/pokemon/luxio/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_LuxioF[] = INCBIN_U32("graphics/pokemon/luxio/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_LuxioF[] = INCBIN_COMP("graphics/pokemon/luxio/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

    const u32 gMonFrontPic_Luxray[] = INCBIN_U32("graphics/pokemon/luxray/anim_front.4bpp.lz");
    const u32 gMonPalette_Luxray[] = INCBIN_U32("graphics/pokemon/luxray/normal.gbapal.lz");
    const u32 gMonBackPic_Luxray[] = INCBIN_U32("graphics/pokemon/luxray/back.4bpp.lz");
    const u32 gMonShinyPalette_Luxray[] = INCBIN_U32("graphics/pokemon/luxray/shiny.gbapal.lz");
    const u8 gMonIcon_Luxray[] = INCBIN_U8("graphics/pokemon/luxray/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Luxray[] = INCBIN_U8("graphics/pokemon/luxray/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Luxray[] = INCBIN_COMP("graphics/pokemon/luxray/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Luxray[] = INCBIN_U32("graphics/pokemon/luxray/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Luxray[] = INCBIN_U32("graphics/pokemon/luxray/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_LuxrayF[] = INCBIN_U32("graphics/pokemon/luxray/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_LuxrayF[] = INCBIN_U32("graphics/pokemon/luxray/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_LuxrayF[] = INCBIN_COMP("graphics/pokemon/luxray/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_SHINX

#if P_FAMILY_CRANIDOS
    const u32 gMonFrontPic_Cranidos[] = INCBIN_U32("graphics/pokemon/cranidos/anim_front.4bpp.lz");
    const u32 gMonPalette_Cranidos[] = INCBIN_U32("graphics/pokemon/cranidos/normal.gbapal.lz");
    const u32 gMonBackPic_Cranidos[] = INCBIN_U32("graphics/pokemon/cranidos/back.4bpp.lz");
    const u32 gMonShinyPalette_Cranidos[] = INCBIN_U32("graphics/pokemon/cranidos/shiny.gbapal.lz");
    const u8 gMonIcon_Cranidos[] = INCBIN_U8("graphics/pokemon/cranidos/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Cranidos[] = INCBIN_U8("graphics/pokemon/cranidos/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Cranidos[] = INCBIN_COMP("graphics/pokemon/cranidos/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Cranidos[] = INCBIN_U32("graphics/pokemon/cranidos/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Cranidos[] = INCBIN_U32("graphics/pokemon/cranidos/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_Rampardos[] = INCBIN_U32("graphics/pokemon/rampardos/anim_front.4bpp.lz");
    const u32 gMonPalette_Rampardos[] = INCBIN_U32("graphics/pokemon/rampardos/normal.gbapal.lz");
    const u32 gMonBackPic_Rampardos[] = INCBIN_U32("graphics/pokemon/rampardos/back.4bpp.lz");
    const u32 gMonShinyPalette_Rampardos[] = INCBIN_U32("graphics/pokemon/rampardos/shiny.gbapal.lz");
    const u8 gMonIcon_Rampardos[] = INCBIN_U8("graphics/pokemon/rampardos/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Rampardos[] = INCBIN_U8("graphics/pokemon/rampardos/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Rampardos[] = INCBIN_COMP("graphics/pokemon/rampardos/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Rampardos[] = INCBIN_U32("graphics/pokemon/rampardos/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Rampardos[] = INCBIN_U32("graphics/pokemon/rampardos/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_CRANIDOS

#if P_FAMILY_SHIELDON
    const u32 gMonFrontPic_Shieldon[] = INCBIN_U32("graphics/pokemon/shieldon/anim_front.4bpp.lz");
    const u32 gMonPalette_Shieldon[] = INCBIN_U32("graphics/pokemon/shieldon/normal.gbapal.lz");
    const u32 gMonBackPic_Shieldon[] = INCBIN_U32("graphics/pokemon/shieldon/back.4bpp.lz");
    const u32 gMonShinyPalette_Shieldon[] = INCBIN_U32("graphics/pokemon/shieldon/shiny.gbapal.lz");
    const u8 gMonIcon_Shieldon[] = INCBIN_U8("graphics/pokemon/shieldon/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Shieldon[] = INCBIN_U8("graphics/pokemon/shieldon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Shieldon[] = INCBIN_COMP("graphics/pokemon/shieldon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Shieldon[] = INCBIN_U32("graphics/pokemon/shieldon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Shieldon[] = INCBIN_U32("graphics/pokemon/shieldon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_Bastiodon[] = INCBIN_U32("graphics/pokemon/bastiodon/anim_front.4bpp.lz");
    const u32 gMonPalette_Bastiodon[] = INCBIN_U32("graphics/pokemon/bastiodon/normal.gbapal.lz");
    const u32 gMonBackPic_Bastiodon[] = INCBIN_U32("graphics/pokemon/bastiodon/back.4bpp.lz");
    const u32 gMonShinyPalette_Bastiodon[] = INCBIN_U32("graphics/pokemon/bastiodon/shiny.gbapal.lz");
    const u8 gMonIcon_Bastiodon[] = INCBIN_U8("graphics/pokemon/bastiodon/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Bastiodon[] = INCBIN_U8("graphics/pokemon/bastiodon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Bastiodon[] = INCBIN_COMP("graphics/pokemon/bastiodon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Bastiodon[] = INCBIN_U32("graphics/pokemon/bastiodon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Bastiodon[] = INCBIN_U32("graphics/pokemon/bastiodon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SHIELDON

#if P_FAMILY_BURMY
    const u32 gMonFrontPic_BurmyPlant[] = INCBIN_U32("graphics/pokemon/burmy/anim_front.4bpp.lz");
    const u32 gMonPalette_BurmyPlant[] = INCBIN_U32("graphics/pokemon/burmy/normal.gbapal.lz");
    const u32 gMonBackPic_BurmyPlant[] = INCBIN_U32("graphics/pokemon/burmy/back.4bpp.lz");
    const u32 gMonShinyPalette_BurmyPlant[] = INCBIN_U32("graphics/pokemon/burmy/shiny.gbapal.lz");
    const u8 gMonIcon_BurmyPlant[] = INCBIN_U8("graphics/pokemon/burmy/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Burmy[] = INCBIN_U8("graphics/pokemon/burmy/footprint.1bpp");
#endif //P_FOOTPRINTS

    const u32 gMonFrontPic_BurmySandy[] = INCBIN_U32("graphics/pokemon/burmy/sandy/anim_front.4bpp.lz");
    const u32 gMonPalette_BurmySandy[] = INCBIN_U32("graphics/pokemon/burmy/sandy/normal.gbapal.lz");
    const u32 gMonBackPic_BurmySandy[] = INCBIN_U32("graphics/pokemon/burmy/sandy/back.4bpp.lz");
    const u32 gMonShinyPalette_BurmySandy[] = INCBIN_U32("graphics/pokemon/burmy/sandy/shiny.gbapal.lz");
    const u8 gMonIcon_BurmySandy[] = INCBIN_U8("graphics/pokemon/burmy/sandy/icon.4bpp");

    const u32 gMonFrontPic_BurmyTrash[] = INCBIN_U32("graphics/pokemon/burmy/trash/anim_front.4bpp.lz");
    const u32 gMonPalette_BurmyTrash[] = INCBIN_U32("graphics/pokemon/burmy/trash/normal.gbapal.lz");
    const u32 gMonBackPic_BurmyTrash[] = INCBIN_U32("graphics/pokemon/burmy/trash/back.4bpp.lz");
    const u32 gMonShinyPalette_BurmyTrash[] = INCBIN_U32("graphics/pokemon/burmy/trash/shiny.gbapal.lz");
    const u8 gMonIcon_BurmyTrash[] = INCBIN_U8("graphics/pokemon/burmy/trash/icon.4bpp");

#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_BurmyPlant[] = INCBIN_COMP("graphics/pokemon/burmy/overworld.4bpp");
    const u32 gObjectEventPic_BurmySandy[] = INCBIN_COMP("graphics/pokemon/burmy/sandy/overworld.4bpp");
    const u32 gObjectEventPic_BurmyTrash[] = INCBIN_COMP("graphics/pokemon/burmy/trash/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_BurmyPlant[] = INCBIN_U32("graphics/pokemon/burmy/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_BurmySandy[] = INCBIN_U32("graphics/pokemon/burmy/sandy/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_BurmyTrash[] = INCBIN_U32("graphics/pokemon/burmy/trash/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_BurmyPlant[] = INCBIN_U32("graphics/pokemon/burmy/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_BurmySandy[] = INCBIN_U32("graphics/pokemon/burmy/sandy/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_BurmyTrash[] = INCBIN_U32("graphics/pokemon/burmy/trash/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_WormadamPlant[] = INCBIN_U32("graphics/pokemon/wormadam/anim_front.4bpp.lz");
    const u32 gMonPalette_WormadamPlant[] = INCBIN_U32("graphics/pokemon/wormadam/normal.gbapal.lz");
    const u32 gMonBackPic_WormadamPlant[] = INCBIN_U32("graphics/pokemon/wormadam/back.4bpp.lz");
    const u32 gMonShinyPalette_WormadamPlant[] = INCBIN_U32("graphics/pokemon/wormadam/shiny.gbapal.lz");
    const u8 gMonIcon_WormadamPlant[] = INCBIN_U8("graphics/pokemon/wormadam/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Wormadam[] = INCBIN_U8("graphics/pokemon/wormadam/footprint.1bpp");
#endif //P_FOOTPRINTS

    const u32 gMonFrontPic_WormadamSandy[] = INCBIN_U32("graphics/pokemon/wormadam/sandy/anim_front.4bpp.lz");
    const u32 gMonPalette_WormadamSandy[] = INCBIN_U32("graphics/pokemon/wormadam/sandy/normal.gbapal.lz");
    const u32 gMonBackPic_WormadamSandy[] = INCBIN_U32("graphics/pokemon/wormadam/sandy/back.4bpp.lz");
    const u32 gMonShinyPalette_WormadamSandy[] = INCBIN_U32("graphics/pokemon/wormadam/sandy/shiny.gbapal.lz");
    const u8 gMonIcon_WormadamSandy[] = INCBIN_U8("graphics/pokemon/wormadam/sandy/icon.4bpp");

    const u32 gMonFrontPic_WormadamTrash[] = INCBIN_U32("graphics/pokemon/wormadam/trash/anim_front.4bpp.lz");
    const u32 gMonPalette_WormadamTrash[] = INCBIN_U32("graphics/pokemon/wormadam/trash/normal.gbapal.lz");
    const u32 gMonBackPic_WormadamTrash[] = INCBIN_U32("graphics/pokemon/wormadam/trash/back.4bpp.lz");
    const u32 gMonShinyPalette_WormadamTrash[] = INCBIN_U32("graphics/pokemon/wormadam/trash/shiny.gbapal.lz");
    const u8 gMonIcon_WormadamTrash[] = INCBIN_U8("graphics/pokemon/wormadam/trash/icon.4bpp");

#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_WormadamPlant[] = INCBIN_COMP("graphics/pokemon/wormadam/overworld.4bpp");
    const u32 gObjectEventPic_WormadamSandy[] = INCBIN_COMP("graphics/pokemon/wormadam/sandy/overworld.4bpp");
    const u32 gObjectEventPic_WormadamTrash[] = INCBIN_COMP("graphics/pokemon/wormadam/trash/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_WormadamPlant[] = INCBIN_U32("graphics/pokemon/wormadam/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_WormadamSandy[] = INCBIN_U32("graphics/pokemon/wormadam/sandy/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_WormadamTrash[] = INCBIN_U32("graphics/pokemon/wormadam/trash/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_WormadamPlant[] = INCBIN_U32("graphics/pokemon/wormadam/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_WormadamSandy[] = INCBIN_U32("graphics/pokemon/wormadam/sandy/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_WormadamTrash[] = INCBIN_U32("graphics/pokemon/wormadam/trash/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_Mothim[] = INCBIN_U32("graphics/pokemon/mothim/anim_front.4bpp.lz");
    const u32 gMonPalette_Mothim[] = INCBIN_U32("graphics/pokemon/mothim/normal.gbapal.lz");
    const u32 gMonBackPic_Mothim[] = INCBIN_U32("graphics/pokemon/mothim/back.4bpp.lz");
    const u32 gMonShinyPalette_Mothim[] = INCBIN_U32("graphics/pokemon/mothim/shiny.gbapal.lz");
    const u8 gMonIcon_Mothim[] = INCBIN_U8("graphics/pokemon/mothim/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Mothim[] = INCBIN_U8("graphics/pokemon/mothim/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Mothim[] = INCBIN_COMP("graphics/pokemon/mothim/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Mothim[] = INCBIN_U32("graphics/pokemon/mothim/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Mothim[] = INCBIN_U32("graphics/pokemon/mothim/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_BURMY

#if P_FAMILY_COMBEE
    const u32 gMonFrontPic_Combee[] = INCBIN_U32("graphics/pokemon/combee/anim_front.4bpp.lz");
    const u32 gMonPalette_Combee[] = INCBIN_U32("graphics/pokemon/combee/normal.gbapal.lz");
    const u32 gMonBackPic_Combee[] = INCBIN_U32("graphics/pokemon/combee/back.4bpp.lz");
    const u32 gMonShinyPalette_Combee[] = INCBIN_U32("graphics/pokemon/combee/shiny.gbapal.lz");
    const u8 gMonIcon_Combee[] = INCBIN_U8("graphics/pokemon/combee/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Combee[] = INCBIN_U8("graphics/pokemon/combee/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Combee[] = INCBIN_COMP("graphics/pokemon/combee/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Combee[] = INCBIN_U32("graphics/pokemon/combee/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Combee[] = INCBIN_U32("graphics/pokemon/combee/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonPalette_CombeeF[] = INCBIN_U32("graphics/pokemon/combee/normalf.gbapal.lz");
    const u32 gMonShinyPalette_CombeeF[] = INCBIN_U32("graphics/pokemon/combee/shinyf.gbapal.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_CombeeF[] = INCBIN_COMP("graphics/pokemon/combee/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

    const u32 gMonFrontPic_Vespiquen[] = INCBIN_U32("graphics/pokemon/vespiquen/anim_front.4bpp.lz");
    const u32 gMonPalette_Vespiquen[] = INCBIN_U32("graphics/pokemon/vespiquen/normal.gbapal.lz");
    const u32 gMonBackPic_Vespiquen[] = INCBIN_U32("graphics/pokemon/vespiquen/back.4bpp.lz");
    const u32 gMonShinyPalette_Vespiquen[] = INCBIN_U32("graphics/pokemon/vespiquen/shiny.gbapal.lz");
    const u8 gMonIcon_Vespiquen[] = INCBIN_U8("graphics/pokemon/vespiquen/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Vespiquen[] = INCBIN_U8("graphics/pokemon/vespiquen/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Vespiquen[] = INCBIN_COMP("graphics/pokemon/vespiquen/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Vespiquen[] = INCBIN_U32("graphics/pokemon/vespiquen/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Vespiquen[] = INCBIN_U32("graphics/pokemon/vespiquen/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_COMBEE

#if P_FAMILY_PACHIRISU
    const u32 gMonFrontPic_Pachirisu[] = INCBIN_U32("graphics/pokemon/pachirisu/anim_front.4bpp.lz");
    const u32 gMonPalette_Pachirisu[] = INCBIN_U32("graphics/pokemon/pachirisu/normal.gbapal.lz");
    const u32 gMonBackPic_Pachirisu[] = INCBIN_U32("graphics/pokemon/pachirisu/back.4bpp.lz");
    const u32 gMonShinyPalette_Pachirisu[] = INCBIN_U32("graphics/pokemon/pachirisu/shiny.gbapal.lz");
    const u8 gMonIcon_Pachirisu[] = INCBIN_U8("graphics/pokemon/pachirisu/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Pachirisu[] = INCBIN_U8("graphics/pokemon/pachirisu/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Pachirisu[] = INCBIN_COMP("graphics/pokemon/pachirisu/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Pachirisu[] = INCBIN_U32("graphics/pokemon/pachirisu/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Pachirisu[] = INCBIN_U32("graphics/pokemon/pachirisu/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_PachirisuF[] = INCBIN_U32("graphics/pokemon/pachirisu/anim_frontf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_PachirisuF[] = INCBIN_COMP("graphics/pokemon/pachirisu/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_PACHIRISU

#if P_FAMILY_BUIZEL
    const u32 gMonFrontPic_Buizel[] = INCBIN_U32("graphics/pokemon/buizel/anim_front.4bpp.lz");
    const u32 gMonPalette_Buizel[] = INCBIN_U32("graphics/pokemon/buizel/normal.gbapal.lz");
    const u32 gMonBackPic_Buizel[] = INCBIN_U32("graphics/pokemon/buizel/back.4bpp.lz");
    const u32 gMonShinyPalette_Buizel[] = INCBIN_U32("graphics/pokemon/buizel/shiny.gbapal.lz");
    const u8 gMonIcon_Buizel[] = INCBIN_U8("graphics/pokemon/buizel/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Buizel[] = INCBIN_U8("graphics/pokemon/buizel/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Buizel[] = INCBIN_COMP("graphics/pokemon/buizel/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Buizel[] = INCBIN_U32("graphics/pokemon/buizel/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Buizel[] = INCBIN_U32("graphics/pokemon/buizel/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonBackPic_BuizelF[] = INCBIN_U32("graphics/pokemon/buizel/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_BuizelF[] = INCBIN_COMP("graphics/pokemon/buizel/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

    const u32 gMonFrontPic_Floatzel[] = INCBIN_U32("graphics/pokemon/floatzel/anim_front.4bpp.lz");
    const u32 gMonPalette_Floatzel[] = INCBIN_U32("graphics/pokemon/floatzel/normal.gbapal.lz");
    const u32 gMonBackPic_Floatzel[] = INCBIN_U32("graphics/pokemon/floatzel/back.4bpp.lz");
    const u32 gMonShinyPalette_Floatzel[] = INCBIN_U32("graphics/pokemon/floatzel/shiny.gbapal.lz");
    const u8 gMonIcon_Floatzel[] = INCBIN_U8("graphics/pokemon/floatzel/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Floatzel[] = INCBIN_U8("graphics/pokemon/floatzel/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Floatzel[] = INCBIN_COMP("graphics/pokemon/floatzel/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Floatzel[] = INCBIN_U32("graphics/pokemon/floatzel/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Floatzel[] = INCBIN_U32("graphics/pokemon/floatzel/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonBackPic_FloatzelF[] = INCBIN_U32("graphics/pokemon/floatzel/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_FloatzelF[] = INCBIN_COMP("graphics/pokemon/floatzel/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_BUIZEL

#if P_FAMILY_CHERUBI
    const u32 gMonFrontPic_Cherubi[] = INCBIN_U32("graphics/pokemon/cherubi/anim_front.4bpp.lz");
    const u32 gMonPalette_Cherubi[] = INCBIN_U32("graphics/pokemon/cherubi/normal.gbapal.lz");
    const u32 gMonBackPic_Cherubi[] = INCBIN_U32("graphics/pokemon/cherubi/back.4bpp.lz");
    const u32 gMonShinyPalette_Cherubi[] = INCBIN_U32("graphics/pokemon/cherubi/shiny.gbapal.lz");
    const u8 gMonIcon_Cherubi[] = INCBIN_U8("graphics/pokemon/cherubi/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Cherubi[] = INCBIN_U8("graphics/pokemon/cherubi/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Cherubi[] = INCBIN_COMP("graphics/pokemon/cherubi/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Cherubi[] = INCBIN_U32("graphics/pokemon/cherubi/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Cherubi[] = INCBIN_U32("graphics/pokemon/cherubi/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_CherrimOvercast[] = INCBIN_U32("graphics/pokemon/cherrim/anim_front.4bpp.lz");
    const u32 gMonPalette_CherrimOvercast[] = INCBIN_U32("graphics/pokemon/cherrim/normal.gbapal.lz");
    const u32 gMonBackPic_CherrimOvercast[] = INCBIN_U32("graphics/pokemon/cherrim/back.4bpp.lz");
    const u32 gMonShinyPalette_CherrimOvercast[] = INCBIN_U32("graphics/pokemon/cherrim/shiny.gbapal.lz");
    const u8 gMonIcon_CherrimOvercast[] = INCBIN_U8("graphics/pokemon/cherrim/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Cherrim[] = INCBIN_U8("graphics/pokemon/cherrim/footprint.1bpp");
#endif //P_FOOTPRINTS

    const u32 gMonFrontPic_CherrimSunshine[] = INCBIN_U32("graphics/pokemon/cherrim/sunshine/anim_front.4bpp.lz");
    const u32 gMonPalette_CherrimSunshine[] = INCBIN_U32("graphics/pokemon/cherrim/sunshine/normal.gbapal.lz");
    const u32 gMonBackPic_CherrimSunshine[] = INCBIN_U32("graphics/pokemon/cherrim/sunshine/back.4bpp.lz");
    const u32 gMonShinyPalette_CherrimSunshine[] = INCBIN_U32("graphics/pokemon/cherrim/sunshine/shiny.gbapal.lz");
    const u8 gMonIcon_CherrimSunshine[] = INCBIN_U8("graphics/pokemon/cherrim/sunshine/icon.4bpp");

#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_CherrimOvercast[] = INCBIN_COMP("graphics/pokemon/cherrim/overworld.4bpp");
    // const u32 gObjectEventPic_CherrimSunshine[] = INCBIN_COMP("graphics/pokemon/cherrim/sunshine/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_CherrimOvercast[] = INCBIN_U32("graphics/pokemon/cherrim/overworld_normal.gbapal.lz");
    // const u32 gOverworldPalette_CherrimSunshine[] = INCBIN_U32("graphics/pokemon/cherrim/sunshine/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_CherrimOvercast[] = INCBIN_U32("graphics/pokemon/cherrim/overworld_shiny.gbapal.lz");
    // const u32 gShinyOverworldPalette_CherrimSunshine[] = INCBIN_U32("graphics/pokemon/cherrim/sunshine/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_CHERUBI

#if P_FAMILY_SHELLOS
    const u32 gMonFrontPic_ShellosWestSea[] = INCBIN_U32("graphics/pokemon/shellos/anim_front.4bpp.lz");
    const u32 gMonPalette_ShellosWestSea[] = INCBIN_U32("graphics/pokemon/shellos/normal.gbapal.lz");
    const u32 gMonBackPic_ShellosWestSea[] = INCBIN_U32("graphics/pokemon/shellos/back.4bpp.lz");
    const u32 gMonShinyPalette_ShellosWestSea[] = INCBIN_U32("graphics/pokemon/shellos/shiny.gbapal.lz");
    const u8 gMonIcon_ShellosWestSea[] = INCBIN_U8("graphics/pokemon/shellos/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Shellos[] = INCBIN_U8("graphics/pokemon/shellos/footprint.1bpp");
#endif //P_FOOTPRINTS

    const u32 gMonFrontPic_ShellosEast[] = INCBIN_U32("graphics/pokemon/shellos/east/anim_front.4bpp.lz");
    const u32 gMonPalette_ShellosEast[] = INCBIN_U32("graphics/pokemon/shellos/east/normal.gbapal.lz");
    const u32 gMonBackPic_ShellosEast[] = INCBIN_U32("graphics/pokemon/shellos/east/back.4bpp.lz");
    const u32 gMonShinyPalette_ShellosEast[] = INCBIN_U32("graphics/pokemon/shellos/east/shiny.gbapal.lz");
    const u8 gMonIcon_ShellosEast[] = INCBIN_U8("graphics/pokemon/shellos/east/icon.4bpp");

#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_ShellosWestSea[] = INCBIN_COMP("graphics/pokemon/shellos/overworld.4bpp");
    const u32 gObjectEventPic_ShellosEast[] = INCBIN_COMP("graphics/pokemon/shellos/east/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_ShellosWestSea[] = INCBIN_U32("graphics/pokemon/shellos/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_ShellosEast[] = INCBIN_U32("graphics/pokemon/shellos/east/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_ShellosWestSea[] = INCBIN_U32("graphics/pokemon/shellos/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_ShellosEast[] = INCBIN_U32("graphics/pokemon/shellos/east/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_GastrodonWestSea[] = INCBIN_U32("graphics/pokemon/gastrodon/anim_front.4bpp.lz");
    const u32 gMonPalette_GastrodonWestSea[] = INCBIN_U32("graphics/pokemon/gastrodon/normal.gbapal.lz");
    const u32 gMonBackPic_GastrodonWestSea[] = INCBIN_U32("graphics/pokemon/gastrodon/back.4bpp.lz");
    const u32 gMonShinyPalette_GastrodonWestSea[] = INCBIN_U32("graphics/pokemon/gastrodon/shiny.gbapal.lz");
    const u8 gMonIcon_GastrodonWestSea[] = INCBIN_U8("graphics/pokemon/gastrodon/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Gastrodon[] = INCBIN_U8("graphics/pokemon/gastrodon/footprint.1bpp");
#endif //P_FOOTPRINTS

    const u32 gMonFrontPic_GastrodonEast[] = INCBIN_U32("graphics/pokemon/gastrodon/east/anim_front.4bpp.lz");
    const u32 gMonPalette_GastrodonEast[] = INCBIN_U32("graphics/pokemon/gastrodon/east/normal.gbapal.lz");
    const u32 gMonBackPic_GastrodonEast[] = INCBIN_U32("graphics/pokemon/gastrodon/east/back.4bpp.lz");
    const u32 gMonShinyPalette_GastrodonEast[] = INCBIN_U32("graphics/pokemon/gastrodon/east/shiny.gbapal.lz");
    const u8 gMonIcon_GastrodonEast[] = INCBIN_U8("graphics/pokemon/gastrodon/east/icon.4bpp");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_GastrodonWestSea[] = INCBIN_COMP("graphics/pokemon/gastrodon/overworld.4bpp");
    const u32 gObjectEventPic_GastrodonEast[] = INCBIN_COMP("graphics/pokemon/gastrodon/east/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_GastrodonWestSea[] = INCBIN_U32("graphics/pokemon/gastrodon/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_GastrodonEast[] = INCBIN_U32("graphics/pokemon/gastrodon/east/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_GastrodonWestSea[] = INCBIN_U32("graphics/pokemon/gastrodon/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_GastrodonEast[] = INCBIN_U32("graphics/pokemon/gastrodon/east/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SHELLOS

#if P_FAMILY_DRIFLOON
    const u32 gMonFrontPic_Drifloon[] = INCBIN_U32("graphics/pokemon/drifloon/anim_front.4bpp.lz");
    const u32 gMonPalette_Drifloon[] = INCBIN_U32("graphics/pokemon/drifloon/normal.gbapal.lz");
    const u32 gMonBackPic_Drifloon[] = INCBIN_U32("graphics/pokemon/drifloon/back.4bpp.lz");
    const u32 gMonShinyPalette_Drifloon[] = INCBIN_U32("graphics/pokemon/drifloon/shiny.gbapal.lz");
    const u8 gMonIcon_Drifloon[] = INCBIN_U8("graphics/pokemon/drifloon/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Drifloon[] = INCBIN_U8("graphics/pokemon/drifloon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Drifloon[] = INCBIN_COMP("graphics/pokemon/drifloon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Drifloon[] = INCBIN_U32("graphics/pokemon/drifloon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Drifloon[] = INCBIN_U32("graphics/pokemon/drifloon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_Drifblim[] = INCBIN_U32("graphics/pokemon/drifblim/anim_front.4bpp.lz");
    const u32 gMonPalette_Drifblim[] = INCBIN_U32("graphics/pokemon/drifblim/normal.gbapal.lz");
    const u32 gMonBackPic_Drifblim[] = INCBIN_U32("graphics/pokemon/drifblim/back.4bpp.lz");
    const u32 gMonShinyPalette_Drifblim[] = INCBIN_U32("graphics/pokemon/drifblim/shiny.gbapal.lz");
    const u8 gMonIcon_Drifblim[] = INCBIN_U8("graphics/pokemon/drifblim/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Drifblim[] = INCBIN_U8("graphics/pokemon/drifblim/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Drifblim[] = INCBIN_COMP("graphics/pokemon/drifblim/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Drifblim[] = INCBIN_U32("graphics/pokemon/drifblim/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Drifblim[] = INCBIN_U32("graphics/pokemon/drifblim/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_DRIFLOON

#if P_FAMILY_BUNEARY
    const u32 gMonFrontPic_Buneary[] = INCBIN_U32("graphics/pokemon/buneary/anim_front.4bpp.lz");
    const u32 gMonPalette_Buneary[] = INCBIN_U32("graphics/pokemon/buneary/normal.gbapal.lz");
    const u32 gMonBackPic_Buneary[] = INCBIN_U32("graphics/pokemon/buneary/back.4bpp.lz");
    const u32 gMonShinyPalette_Buneary[] = INCBIN_U32("graphics/pokemon/buneary/shiny.gbapal.lz");
    const u8 gMonIcon_Buneary[] = INCBIN_U8("graphics/pokemon/buneary/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Buneary[] = INCBIN_U8("graphics/pokemon/buneary/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Buneary[] = INCBIN_COMP("graphics/pokemon/buneary/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Buneary[] = INCBIN_U32("graphics/pokemon/buneary/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Buneary[] = INCBIN_U32("graphics/pokemon/buneary/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_Lopunny[] = INCBIN_U32("graphics/pokemon/lopunny/anim_front.4bpp.lz");
    const u32 gMonPalette_Lopunny[] = INCBIN_U32("graphics/pokemon/lopunny/normal.gbapal.lz");
    const u32 gMonBackPic_Lopunny[] = INCBIN_U32("graphics/pokemon/lopunny/back.4bpp.lz");
    const u32 gMonShinyPalette_Lopunny[] = INCBIN_U32("graphics/pokemon/lopunny/shiny.gbapal.lz");
    const u8 gMonIcon_Lopunny[] = INCBIN_U8("graphics/pokemon/lopunny/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Lopunny[] = INCBIN_U8("graphics/pokemon/lopunny/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Lopunny[] = INCBIN_COMP("graphics/pokemon/lopunny/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Lopunny[] = INCBIN_U32("graphics/pokemon/lopunny/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Lopunny[] = INCBIN_U32("graphics/pokemon/lopunny/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_BUNEARY

#if P_FAMILY_GLAMEOW
    const u32 gMonFrontPic_Glameow[] = INCBIN_U32("graphics/pokemon/glameow/anim_front.4bpp.lz");
    const u32 gMonPalette_Glameow[] = INCBIN_U32("graphics/pokemon/glameow/normal.gbapal.lz");
    const u32 gMonBackPic_Glameow[] = INCBIN_U32("graphics/pokemon/glameow/back.4bpp.lz");
    const u32 gMonShinyPalette_Glameow[] = INCBIN_U32("graphics/pokemon/glameow/shiny.gbapal.lz");
    const u8 gMonIcon_Glameow[] = INCBIN_U8("graphics/pokemon/glameow/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Glameow[] = INCBIN_U8("graphics/pokemon/glameow/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Glameow[] = INCBIN_COMP("graphics/pokemon/glameow/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Glameow[] = INCBIN_U32("graphics/pokemon/glameow/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Glameow[] = INCBIN_U32("graphics/pokemon/glameow/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_Purugly[] = INCBIN_U32("graphics/pokemon/purugly/anim_front.4bpp.lz");
    const u32 gMonPalette_Purugly[] = INCBIN_U32("graphics/pokemon/purugly/normal.gbapal.lz");
    const u32 gMonBackPic_Purugly[] = INCBIN_U32("graphics/pokemon/purugly/back.4bpp.lz");
    const u32 gMonShinyPalette_Purugly[] = INCBIN_U32("graphics/pokemon/purugly/shiny.gbapal.lz");
    const u8 gMonIcon_Purugly[] = INCBIN_U8("graphics/pokemon/purugly/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Purugly[] = INCBIN_U8("graphics/pokemon/purugly/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Purugly[] = INCBIN_COMP("graphics/pokemon/purugly/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Purugly[] = INCBIN_U32("graphics/pokemon/purugly/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Purugly[] = INCBIN_U32("graphics/pokemon/purugly/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_GLAMEOW

#if P_FAMILY_STUNKY
    const u32 gMonFrontPic_Stunky[] = INCBIN_U32("graphics/pokemon/stunky/anim_front.4bpp.lz");
    const u32 gMonPalette_Stunky[] = INCBIN_U32("graphics/pokemon/stunky/normal.gbapal.lz");
    const u32 gMonBackPic_Stunky[] = INCBIN_U32("graphics/pokemon/stunky/back.4bpp.lz");
    const u32 gMonShinyPalette_Stunky[] = INCBIN_U32("graphics/pokemon/stunky/shiny.gbapal.lz");
    const u8 gMonIcon_Stunky[] = INCBIN_U8("graphics/pokemon/stunky/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Stunky[] = INCBIN_U8("graphics/pokemon/stunky/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Stunky[] = INCBIN_COMP("graphics/pokemon/stunky/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Stunky[] = INCBIN_U32("graphics/pokemon/stunky/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Stunky[] = INCBIN_U32("graphics/pokemon/stunky/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_Skuntank[] = INCBIN_U32("graphics/pokemon/skuntank/anim_front.4bpp.lz");
    const u32 gMonPalette_Skuntank[] = INCBIN_U32("graphics/pokemon/skuntank/normal.gbapal.lz");
    const u32 gMonBackPic_Skuntank[] = INCBIN_U32("graphics/pokemon/skuntank/back.4bpp.lz");
    const u32 gMonShinyPalette_Skuntank[] = INCBIN_U32("graphics/pokemon/skuntank/shiny.gbapal.lz");
    const u8 gMonIcon_Skuntank[] = INCBIN_U8("graphics/pokemon/skuntank/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Skuntank[] = INCBIN_U8("graphics/pokemon/skuntank/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Skuntank[] = INCBIN_COMP("graphics/pokemon/skuntank/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Skuntank[] = INCBIN_U32("graphics/pokemon/skuntank/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Skuntank[] = INCBIN_U32("graphics/pokemon/skuntank/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_STUNKY

#if P_FAMILY_BRONZOR
    const u32 gMonFrontPic_Bronzor[] = INCBIN_U32("graphics/pokemon/bronzor/anim_front.4bpp.lz");
    const u32 gMonPalette_Bronzor[] = INCBIN_U32("graphics/pokemon/bronzor/normal.gbapal.lz");
    const u32 gMonBackPic_Bronzor[] = INCBIN_U32("graphics/pokemon/bronzor/back.4bpp.lz");
    const u32 gMonShinyPalette_Bronzor[] = INCBIN_U32("graphics/pokemon/bronzor/shiny.gbapal.lz");
    const u8 gMonIcon_Bronzor[] = INCBIN_U8("graphics/pokemon/bronzor/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Bronzor[] = INCBIN_U8("graphics/pokemon/bronzor/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Bronzor[] = INCBIN_COMP("graphics/pokemon/bronzor/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Bronzor[] = INCBIN_U32("graphics/pokemon/bronzor/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Bronzor[] = INCBIN_U32("graphics/pokemon/bronzor/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_Bronzong[] = INCBIN_U32("graphics/pokemon/bronzong/anim_front.4bpp.lz");
    const u32 gMonPalette_Bronzong[] = INCBIN_U32("graphics/pokemon/bronzong/normal.gbapal.lz");
    const u32 gMonBackPic_Bronzong[] = INCBIN_U32("graphics/pokemon/bronzong/back.4bpp.lz");
    const u32 gMonShinyPalette_Bronzong[] = INCBIN_U32("graphics/pokemon/bronzong/shiny.gbapal.lz");
    const u8 gMonIcon_Bronzong[] = INCBIN_U8("graphics/pokemon/bronzong/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Bronzong[] = INCBIN_U8("graphics/pokemon/bronzong/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Bronzong[] = INCBIN_COMP("graphics/pokemon/bronzong/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Bronzong[] = INCBIN_U32("graphics/pokemon/bronzong/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Bronzong[] = INCBIN_U32("graphics/pokemon/bronzong/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_BRONZOR

#if P_FAMILY_CHATOT
    const u32 gMonFrontPic_Chatot[] = INCBIN_U32("graphics/pokemon/chatot/anim_front.4bpp.lz");
    const u32 gMonPalette_Chatot[] = INCBIN_U32("graphics/pokemon/chatot/normal.gbapal.lz");
    const u32 gMonBackPic_Chatot[] = INCBIN_U32("graphics/pokemon/chatot/back.4bpp.lz");
    const u32 gMonShinyPalette_Chatot[] = INCBIN_U32("graphics/pokemon/chatot/shiny.gbapal.lz");
    const u8 gMonIcon_Chatot[] = INCBIN_U8("graphics/pokemon/chatot/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Chatot[] = INCBIN_U8("graphics/pokemon/chatot/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Chatot[] = INCBIN_COMP("graphics/pokemon/chatot/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Chatot[] = INCBIN_U32("graphics/pokemon/chatot/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Chatot[] = INCBIN_U32("graphics/pokemon/chatot/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_CHATOT

#if P_FAMILY_SPIRITOMB
    const u32 gMonFrontPic_Spiritomb[] = INCBIN_U32("graphics/pokemon/spiritomb/anim_front.4bpp.lz");
    const u32 gMonPalette_Spiritomb[] = INCBIN_U32("graphics/pokemon/spiritomb/normal.gbapal.lz");
    const u32 gMonBackPic_Spiritomb[] = INCBIN_U32("graphics/pokemon/spiritomb/back.4bpp.lz");
    const u32 gMonShinyPalette_Spiritomb[] = INCBIN_U32("graphics/pokemon/spiritomb/shiny.gbapal.lz");
    const u8 gMonIcon_Spiritomb[] = INCBIN_U8("graphics/pokemon/spiritomb/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Spiritomb[] = INCBIN_U8("graphics/pokemon/spiritomb/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Spiritomb[] = INCBIN_COMP("graphics/pokemon/spiritomb/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Spiritomb[] = INCBIN_U32("graphics/pokemon/spiritomb/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Spiritomb[] = INCBIN_U32("graphics/pokemon/spiritomb/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SPIRITOMB

#if P_FAMILY_GIBLE
    const u32 gMonFrontPic_Gible[] = INCBIN_U32("graphics/pokemon/gible/anim_front.4bpp.lz");
    const u32 gMonPalette_Gible[] = INCBIN_U32("graphics/pokemon/gible/normal.gbapal.lz");
    const u32 gMonBackPic_Gible[] = INCBIN_U32("graphics/pokemon/gible/back.4bpp.lz");
    const u32 gMonShinyPalette_Gible[] = INCBIN_U32("graphics/pokemon/gible/shiny.gbapal.lz");
    const u8 gMonIcon_Gible[] = INCBIN_U8("graphics/pokemon/gible/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Gible[] = INCBIN_U8("graphics/pokemon/gible/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Gible[] = INCBIN_COMP("graphics/pokemon/gible/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Gible[] = INCBIN_U32("graphics/pokemon/gible/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Gible[] = INCBIN_U32("graphics/pokemon/gible/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_GibleF[] = INCBIN_U32("graphics/pokemon/gible/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_GibleF[] = INCBIN_U32("graphics/pokemon/gible/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_GibleF[] = INCBIN_COMP("graphics/pokemon/gible/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

    const u32 gMonFrontPic_Gabite[] = INCBIN_U32("graphics/pokemon/gabite/anim_front.4bpp.lz");
    const u32 gMonPalette_Gabite[] = INCBIN_U32("graphics/pokemon/gabite/normal.gbapal.lz");
    const u32 gMonBackPic_Gabite[] = INCBIN_U32("graphics/pokemon/gabite/back.4bpp.lz");
    const u32 gMonShinyPalette_Gabite[] = INCBIN_U32("graphics/pokemon/gabite/shiny.gbapal.lz");
    const u8 gMonIcon_Gabite[] = INCBIN_U8("graphics/pokemon/gabite/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Gabite[] = INCBIN_U8("graphics/pokemon/gabite/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Gabite[] = INCBIN_COMP("graphics/pokemon/gabite/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Gabite[] = INCBIN_U32("graphics/pokemon/gabite/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Gabite[] = INCBIN_U32("graphics/pokemon/gabite/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_GabiteF[] = INCBIN_U32("graphics/pokemon/gabite/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_GabiteF[] = INCBIN_U32("graphics/pokemon/gabite/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_GabiteF[] = INCBIN_COMP("graphics/pokemon/gabite/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

    const u32 gMonFrontPic_Garchomp[] = INCBIN_U32("graphics/pokemon/garchomp/anim_front.4bpp.lz");
    const u32 gMonPalette_Garchomp[] = INCBIN_U32("graphics/pokemon/garchomp/normal.gbapal.lz");
    const u32 gMonBackPic_Garchomp[] = INCBIN_U32("graphics/pokemon/garchomp/back.4bpp.lz");
    const u32 gMonShinyPalette_Garchomp[] = INCBIN_U32("graphics/pokemon/garchomp/shiny.gbapal.lz");
    const u8 gMonIcon_Garchomp[] = INCBIN_U8("graphics/pokemon/garchomp/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Garchomp[] = INCBIN_U8("graphics/pokemon/garchomp/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Garchomp[] = INCBIN_COMP("graphics/pokemon/garchomp/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Garchomp[] = INCBIN_U32("graphics/pokemon/garchomp/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Garchomp[] = INCBIN_U32("graphics/pokemon/garchomp/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_GarchompF[] = INCBIN_U32("graphics/pokemon/garchomp/anim_frontf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_GarchompF[] = INCBIN_COMP("graphics/pokemon/garchomp/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_GIBLE

#if P_FAMILY_RIOLU
    const u32 gMonFrontPic_Riolu[] = INCBIN_U32("graphics/pokemon/riolu/anim_front.4bpp.lz");
    const u32 gMonPalette_Riolu[] = INCBIN_U32("graphics/pokemon/riolu/normal.gbapal.lz");
    const u32 gMonBackPic_Riolu[] = INCBIN_U32("graphics/pokemon/riolu/back.4bpp.lz");
    const u32 gMonShinyPalette_Riolu[] = INCBIN_U32("graphics/pokemon/riolu/shiny.gbapal.lz");
    const u8 gMonIcon_Riolu[] = INCBIN_U8("graphics/pokemon/riolu/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Riolu[] = INCBIN_U8("graphics/pokemon/riolu/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Riolu[] = INCBIN_COMP("graphics/pokemon/riolu/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Riolu[] = INCBIN_U32("graphics/pokemon/riolu/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Riolu[] = INCBIN_U32("graphics/pokemon/riolu/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_Lucario[] = INCBIN_U32("graphics/pokemon/lucario/anim_front.4bpp.lz");
    const u32 gMonPalette_Lucario[] = INCBIN_U32("graphics/pokemon/lucario/normal.gbapal.lz");
    const u32 gMonBackPic_Lucario[] = INCBIN_U32("graphics/pokemon/lucario/back.4bpp.lz");
    const u32 gMonShinyPalette_Lucario[] = INCBIN_U32("graphics/pokemon/lucario/shiny.gbapal.lz");
    const u8 gMonIcon_Lucario[] = INCBIN_U8("graphics/pokemon/lucario/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Lucario[] = INCBIN_U8("graphics/pokemon/lucario/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Lucario[] = INCBIN_COMP("graphics/pokemon/lucario/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Lucario[] = INCBIN_U32("graphics/pokemon/lucario/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Lucario[] = INCBIN_U32("graphics/pokemon/lucario/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_RIOLU

#if P_FAMILY_HIPPOPOTAS
    const u32 gMonFrontPic_Hippopotas[] = INCBIN_U32("graphics/pokemon/hippopotas/anim_front.4bpp.lz");
    const u32 gMonPalette_Hippopotas[] = INCBIN_U32("graphics/pokemon/hippopotas/normal.gbapal.lz");
    const u32 gMonBackPic_Hippopotas[] = INCBIN_U32("graphics/pokemon/hippopotas/back.4bpp.lz");
    const u32 gMonShinyPalette_Hippopotas[] = INCBIN_U32("graphics/pokemon/hippopotas/shiny.gbapal.lz");
    const u8 gMonIcon_Hippopotas[] = INCBIN_U8("graphics/pokemon/hippopotas/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Hippopotas[] = INCBIN_U8("graphics/pokemon/hippopotas/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Hippopotas[] = INCBIN_COMP("graphics/pokemon/hippopotas/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Hippopotas[] = INCBIN_U32("graphics/pokemon/hippopotas/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Hippopotas[] = INCBIN_U32("graphics/pokemon/hippopotas/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonPalette_HippopotasF[] = INCBIN_U32("graphics/pokemon/hippopotas/normalf.gbapal.lz");
    const u32 gMonShinyPalette_HippopotasF[] = INCBIN_U32("graphics/pokemon/hippopotas/shinyf.gbapal.lz");
#if P_CUSTOM_GENDER_DIFF_ICONS
    const u8 gMonIcon_HippopotasF[] = INCBIN_U8("graphics/pokemon/hippopotas/iconf.4bpp");
#endif
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_HippopotasF[] = INCBIN_COMP("graphics/pokemon/hippopotas/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

    const u32 gMonFrontPic_Hippowdon[] = INCBIN_U32("graphics/pokemon/hippowdon/anim_front.4bpp.lz");
    const u32 gMonPalette_Hippowdon[] = INCBIN_U32("graphics/pokemon/hippowdon/normal.gbapal.lz");
    const u32 gMonBackPic_Hippowdon[] = INCBIN_U32("graphics/pokemon/hippowdon/back.4bpp.lz");
    const u32 gMonShinyPalette_Hippowdon[] = INCBIN_U32("graphics/pokemon/hippowdon/shiny.gbapal.lz");
    const u8 gMonIcon_Hippowdon[] = INCBIN_U8("graphics/pokemon/hippowdon/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Hippowdon[] = INCBIN_U8("graphics/pokemon/hippowdon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Hippowdon[] = INCBIN_COMP("graphics/pokemon/hippowdon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Hippowdon[] = INCBIN_U32("graphics/pokemon/hippowdon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Hippowdon[] = INCBIN_U32("graphics/pokemon/hippowdon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonPalette_HippowdonF[] = INCBIN_U32("graphics/pokemon/hippowdon/normalf.gbapal.lz");
    const u32 gMonShinyPalette_HippowdonF[] = INCBIN_U32("graphics/pokemon/hippowdon/shinyf.gbapal.lz");
#if P_CUSTOM_GENDER_DIFF_ICONS
    const u8 gMonIcon_HippowdonF[] = INCBIN_U8("graphics/pokemon/hippowdon/iconf.4bpp");
#endif
#if OW_POKEMON_OBJECT_EVENTS
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_HippowdonF[] = INCBIN_U32("graphics/pokemon/hippowdon/overworld_normalf.gbapal.lz");
    const u32 gShinyOverworldPalette_HippowdonF[] = INCBIN_U32("graphics/pokemon/hippowdon/overworld_shinyf.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_HIPPOPOTAS

#if P_FAMILY_SKORUPI
    const u32 gMonFrontPic_Skorupi[] = INCBIN_U32("graphics/pokemon/skorupi/anim_front.4bpp.lz");
    const u32 gMonPalette_Skorupi[] = INCBIN_U32("graphics/pokemon/skorupi/normal.gbapal.lz");
    const u32 gMonBackPic_Skorupi[] = INCBIN_U32("graphics/pokemon/skorupi/back.4bpp.lz");
    const u32 gMonShinyPalette_Skorupi[] = INCBIN_U32("graphics/pokemon/skorupi/shiny.gbapal.lz");
    const u8 gMonIcon_Skorupi[] = INCBIN_U8("graphics/pokemon/skorupi/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Skorupi[] = INCBIN_U8("graphics/pokemon/skorupi/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Skorupi[] = INCBIN_COMP("graphics/pokemon/skorupi/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Skorupi[] = INCBIN_U32("graphics/pokemon/skorupi/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Skorupi[] = INCBIN_U32("graphics/pokemon/skorupi/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_Drapion[] = INCBIN_U32("graphics/pokemon/drapion/anim_front.4bpp.lz");
    const u32 gMonPalette_Drapion[] = INCBIN_U32("graphics/pokemon/drapion/normal.gbapal.lz");
    const u32 gMonBackPic_Drapion[] = INCBIN_U32("graphics/pokemon/drapion/back.4bpp.lz");
    const u32 gMonShinyPalette_Drapion[] = INCBIN_U32("graphics/pokemon/drapion/shiny.gbapal.lz");
    const u8 gMonIcon_Drapion[] = INCBIN_U8("graphics/pokemon/drapion/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Drapion[] = INCBIN_U8("graphics/pokemon/drapion/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Drapion[] = INCBIN_COMP("graphics/pokemon/drapion/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Drapion[] = INCBIN_U32("graphics/pokemon/drapion/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Drapion[] = INCBIN_U32("graphics/pokemon/drapion/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SKORUPI

#if P_FAMILY_CROAGUNK
    const u32 gMonFrontPic_Croagunk[] = INCBIN_U32("graphics/pokemon/croagunk/anim_front.4bpp.lz");
    const u32 gMonPalette_Croagunk[] = INCBIN_U32("graphics/pokemon/croagunk/normal.gbapal.lz");
    const u32 gMonBackPic_Croagunk[] = INCBIN_U32("graphics/pokemon/croagunk/back.4bpp.lz");
    const u32 gMonShinyPalette_Croagunk[] = INCBIN_U32("graphics/pokemon/croagunk/shiny.gbapal.lz");
    const u8 gMonIcon_Croagunk[] = INCBIN_U8("graphics/pokemon/croagunk/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Croagunk[] = INCBIN_U8("graphics/pokemon/croagunk/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Croagunk[] = INCBIN_COMP("graphics/pokemon/croagunk/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Croagunk[] = INCBIN_U32("graphics/pokemon/croagunk/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Croagunk[] = INCBIN_U32("graphics/pokemon/croagunk/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_CroagunkF[] = INCBIN_U32("graphics/pokemon/croagunk/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_CroagunkF[] = INCBIN_U32("graphics/pokemon/croagunk/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_CroagunkF[] = INCBIN_COMP("graphics/pokemon/croagunk/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

    const u32 gMonFrontPic_Toxicroak[] = INCBIN_U32("graphics/pokemon/toxicroak/anim_front.4bpp.lz");
    const u32 gMonPalette_Toxicroak[] = INCBIN_U32("graphics/pokemon/toxicroak/normal.gbapal.lz");
    const u32 gMonBackPic_Toxicroak[] = INCBIN_U32("graphics/pokemon/toxicroak/back.4bpp.lz");
    const u32 gMonShinyPalette_Toxicroak[] = INCBIN_U32("graphics/pokemon/toxicroak/shiny.gbapal.lz");
    const u8 gMonIcon_Toxicroak[] = INCBIN_U8("graphics/pokemon/toxicroak/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Toxicroak[] = INCBIN_U8("graphics/pokemon/toxicroak/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Toxicroak[] = INCBIN_COMP("graphics/pokemon/toxicroak/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Toxicroak[] = INCBIN_U32("graphics/pokemon/toxicroak/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Toxicroak[] = INCBIN_U32("graphics/pokemon/toxicroak/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_ToxicroakF[] = INCBIN_U32("graphics/pokemon/toxicroak/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_ToxicroakF[] = INCBIN_U32("graphics/pokemon/toxicroak/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_ToxicroakF[] = INCBIN_COMP("graphics/pokemon/toxicroak/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_CROAGUNK

#if P_FAMILY_CARNIVINE
    const u32 gMonFrontPic_Carnivine[] = INCBIN_U32("graphics/pokemon/carnivine/anim_front.4bpp.lz");
    const u32 gMonPalette_Carnivine[] = INCBIN_U32("graphics/pokemon/carnivine/normal.gbapal.lz");
    const u32 gMonBackPic_Carnivine[] = INCBIN_U32("graphics/pokemon/carnivine/back.4bpp.lz");
    const u32 gMonShinyPalette_Carnivine[] = INCBIN_U32("graphics/pokemon/carnivine/shiny.gbapal.lz");
    const u8 gMonIcon_Carnivine[] = INCBIN_U8("graphics/pokemon/carnivine/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Carnivine[] = INCBIN_U8("graphics/pokemon/carnivine/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Carnivine[] = INCBIN_COMP("graphics/pokemon/carnivine/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Carnivine[] = INCBIN_U32("graphics/pokemon/carnivine/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Carnivine[] = INCBIN_U32("graphics/pokemon/carnivine/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_CARNIVINE

#if P_FAMILY_FINNEON
    const u32 gMonFrontPic_Finneon[] = INCBIN_U32("graphics/pokemon/finneon/anim_front.4bpp.lz");
    const u32 gMonPalette_Finneon[] = INCBIN_U32("graphics/pokemon/finneon/normal.gbapal.lz");
    const u32 gMonBackPic_Finneon[] = INCBIN_U32("graphics/pokemon/finneon/back.4bpp.lz");
    const u32 gMonShinyPalette_Finneon[] = INCBIN_U32("graphics/pokemon/finneon/shiny.gbapal.lz");
    const u8 gMonIcon_Finneon[] = INCBIN_U8("graphics/pokemon/finneon/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Finneon[] = INCBIN_U8("graphics/pokemon/finneon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Finneon[] = INCBIN_COMP("graphics/pokemon/finneon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Finneon[] = INCBIN_U32("graphics/pokemon/finneon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Finneon[] = INCBIN_U32("graphics/pokemon/finneon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_FinneonF[] = INCBIN_U32("graphics/pokemon/finneon/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_FinneonF[] = INCBIN_U32("graphics/pokemon/finneon/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_FinneonF[] = INCBIN_COMP("graphics/pokemon/finneon/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

    const u32 gMonFrontPic_Lumineon[] = INCBIN_U32("graphics/pokemon/lumineon/anim_front.4bpp.lz");
    const u32 gMonPalette_Lumineon[] = INCBIN_U32("graphics/pokemon/lumineon/normal.gbapal.lz");
    const u32 gMonBackPic_Lumineon[] = INCBIN_U32("graphics/pokemon/lumineon/back.4bpp.lz");
    const u32 gMonShinyPalette_Lumineon[] = INCBIN_U32("graphics/pokemon/lumineon/shiny.gbapal.lz");
    const u8 gMonIcon_Lumineon[] = INCBIN_U8("graphics/pokemon/lumineon/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Lumineon[] = INCBIN_U8("graphics/pokemon/lumineon/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Lumineon[] = INCBIN_COMP("graphics/pokemon/lumineon/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Lumineon[] = INCBIN_U32("graphics/pokemon/lumineon/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Lumineon[] = INCBIN_U32("graphics/pokemon/lumineon/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_LumineonF[] = INCBIN_U32("graphics/pokemon/lumineon/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_LumineonF[] = INCBIN_U32("graphics/pokemon/lumineon/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_LumineonF[] = INCBIN_COMP("graphics/pokemon/lumineon/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_FINNEON

#if P_FAMILY_SNOVER
    const u32 gMonFrontPic_Snover[] = INCBIN_U32("graphics/pokemon/snover/anim_front.4bpp.lz");
    const u32 gMonPalette_Snover[] = INCBIN_U32("graphics/pokemon/snover/normal.gbapal.lz");
    const u32 gMonBackPic_Snover[] = INCBIN_U32("graphics/pokemon/snover/back.4bpp.lz");
    const u32 gMonShinyPalette_Snover[] = INCBIN_U32("graphics/pokemon/snover/shiny.gbapal.lz");
    const u8 gMonIcon_Snover[] = INCBIN_U8("graphics/pokemon/snover/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Snover[] = INCBIN_U8("graphics/pokemon/snover/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Snover[] = INCBIN_COMP("graphics/pokemon/snover/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Snover[] = INCBIN_U32("graphics/pokemon/snover/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Snover[] = INCBIN_U32("graphics/pokemon/snover/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_SnoverF[] = INCBIN_U32("graphics/pokemon/snover/anim_frontf.4bpp.lz");
    const u32 gMonBackPic_SnoverF[] = INCBIN_U32("graphics/pokemon/snover/backf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_SnoverF[] = INCBIN_COMP("graphics/pokemon/snover/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES

    const u32 gMonFrontPic_Abomasnow[] = INCBIN_U32("graphics/pokemon/abomasnow/anim_front.4bpp.lz");
    const u32 gMonPalette_Abomasnow[] = INCBIN_U32("graphics/pokemon/abomasnow/normal.gbapal.lz");
    const u32 gMonBackPic_Abomasnow[] = INCBIN_U32("graphics/pokemon/abomasnow/back.4bpp.lz");
    const u32 gMonShinyPalette_Abomasnow[] = INCBIN_U32("graphics/pokemon/abomasnow/shiny.gbapal.lz");
    const u8 gMonIcon_Abomasnow[] = INCBIN_U8("graphics/pokemon/abomasnow/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Abomasnow[] = INCBIN_U8("graphics/pokemon/abomasnow/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Abomasnow[] = INCBIN_COMP("graphics/pokemon/abomasnow/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Abomasnow[] = INCBIN_U32("graphics/pokemon/abomasnow/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Abomasnow[] = INCBIN_U32("graphics/pokemon/abomasnow/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

#if P_GENDER_DIFFERENCES
    const u32 gMonFrontPic_AbomasnowF[] = INCBIN_U32("graphics/pokemon/abomasnow/anim_frontf.4bpp.lz");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_AbomasnowF[] = INCBIN_COMP("graphics/pokemon/abomasnow/overworldf.4bpp");
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_GENDER_DIFFERENCES
#endif //P_FAMILY_SNOVER

#if P_FAMILY_ROTOM
    const u32 gMonFrontPic_Rotom[] = INCBIN_U32("graphics/pokemon/rotom/anim_front.4bpp.lz");
    const u32 gMonPalette_Rotom[] = INCBIN_U32("graphics/pokemon/rotom/normal.gbapal.lz");
    const u32 gMonBackPic_Rotom[] = INCBIN_U32("graphics/pokemon/rotom/back.4bpp.lz");
    const u32 gMonShinyPalette_Rotom[] = INCBIN_U32("graphics/pokemon/rotom/shiny.gbapal.lz");
    const u8 gMonIcon_Rotom[] = INCBIN_U8("graphics/pokemon/rotom/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Rotom[] = INCBIN_U8("graphics/pokemon/rotom/normal/footprint.1bpp");
#endif //P_FOOTPRINTS

    const u32 gMonFrontPic_RotomHeat[] = INCBIN_U32("graphics/pokemon/rotom/heat/anim_front.4bpp.lz");
    const u32 gMonPalette_RotomHeat[] = INCBIN_U32("graphics/pokemon/rotom/heat/normal.gbapal.lz");
    const u32 gMonBackPic_RotomHeat[] = INCBIN_U32("graphics/pokemon/rotom/heat/back.4bpp.lz");
    const u32 gMonShinyPalette_RotomHeat[] = INCBIN_U32("graphics/pokemon/rotom/heat/shiny.gbapal.lz");
    const u8 gMonIcon_RotomHeat[] = INCBIN_U8("graphics/pokemon/rotom/heat/icon.4bpp");

    const u32 gMonFrontPic_RotomWash[] = INCBIN_U32("graphics/pokemon/rotom/wash/anim_front.4bpp.lz");
    const u32 gMonPalette_RotomWash[] = INCBIN_U32("graphics/pokemon/rotom/wash/normal.gbapal.lz");
    const u32 gMonBackPic_RotomWash[] = INCBIN_U32("graphics/pokemon/rotom/wash/back.4bpp.lz");
    const u32 gMonShinyPalette_RotomWash[] = INCBIN_U32("graphics/pokemon/rotom/wash/shiny.gbapal.lz");
    const u8 gMonIcon_RotomWash[] = INCBIN_U8("graphics/pokemon/rotom/wash/icon.4bpp");

    const u32 gMonFrontPic_RotomFrost[] = INCBIN_U32("graphics/pokemon/rotom/frost/anim_front.4bpp.lz");
    const u32 gMonPalette_RotomFrost[] = INCBIN_U32("graphics/pokemon/rotom/frost/normal.gbapal.lz");
    const u32 gMonBackPic_RotomFrost[] = INCBIN_U32("graphics/pokemon/rotom/frost/back.4bpp.lz");
    const u32 gMonShinyPalette_RotomFrost[] = INCBIN_U32("graphics/pokemon/rotom/frost/shiny.gbapal.lz");
    const u8 gMonIcon_RotomFrost[] = INCBIN_U8("graphics/pokemon/rotom/frost/icon.4bpp");

    const u32 gMonFrontPic_RotomFan[] = INCBIN_U32("graphics/pokemon/rotom/fan/anim_front.4bpp.lz");
    const u32 gMonPalette_RotomFan[] = INCBIN_U32("graphics/pokemon/rotom/fan/normal.gbapal.lz");
    const u32 gMonBackPic_RotomFan[] = INCBIN_U32("graphics/pokemon/rotom/fan/back.4bpp.lz");
    const u32 gMonShinyPalette_RotomFan[] = INCBIN_U32("graphics/pokemon/rotom/fan/shiny.gbapal.lz");
    const u8 gMonIcon_RotomFan[] = INCBIN_U8("graphics/pokemon/rotom/fan/icon.4bpp");

    const u32 gMonFrontPic_RotomMow[] = INCBIN_U32("graphics/pokemon/rotom/mow/anim_front.4bpp.lz");
    const u32 gMonPalette_RotomMow[] = INCBIN_U32("graphics/pokemon/rotom/mow/normal.gbapal.lz");
    const u32 gMonBackPic_RotomMow[] = INCBIN_U32("graphics/pokemon/rotom/mow/back.4bpp.lz");
    const u32 gMonShinyPalette_RotomMow[] = INCBIN_U32("graphics/pokemon/rotom/mow/shiny.gbapal.lz");
    const u8 gMonIcon_RotomMow[] = INCBIN_U8("graphics/pokemon/rotom/mow/icon.4bpp");

#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Rotom[] = INCBIN_COMP("graphics/pokemon/rotom/overworld.4bpp");
    const u32 gObjectEventPic_RotomHeat[] = INCBIN_COMP("graphics/pokemon/rotom/heat/overworld.4bpp");
    const u32 gObjectEventPic_RotomWash[] = INCBIN_COMP("graphics/pokemon/rotom/wash/overworld.4bpp");
    const u32 gObjectEventPic_RotomFrost[] = INCBIN_COMP("graphics/pokemon/rotom/frost/overworld.4bpp");
    const u32 gObjectEventPic_RotomFan[] = INCBIN_COMP("graphics/pokemon/rotom/fan/overworld.4bpp");
    const u32 gObjectEventPic_RotomMow[] = INCBIN_COMP("graphics/pokemon/rotom/mow/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Rotom[] = INCBIN_U32("graphics/pokemon/rotom/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_RotomHeat[] = INCBIN_U32("graphics/pokemon/rotom/heat/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_RotomWash[] = INCBIN_U32("graphics/pokemon/rotom/wash/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_RotomFrost[] = INCBIN_U32("graphics/pokemon/rotom/frost/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_RotomFan[] = INCBIN_U32("graphics/pokemon/rotom/fan/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_RotomMow[] = INCBIN_U32("graphics/pokemon/rotom/mow/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Rotom[] = INCBIN_U32("graphics/pokemon/rotom/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_RotomHeat[] = INCBIN_U32("graphics/pokemon/rotom/heat/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_RotomWash[] = INCBIN_U32("graphics/pokemon/rotom/wash/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_RotomFrost[] = INCBIN_U32("graphics/pokemon/rotom/frost/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_RotomFan[] = INCBIN_U32("graphics/pokemon/rotom/fan/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_RotomMow[] = INCBIN_U32("graphics/pokemon/rotom/mow/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_ROTOM

#if P_FAMILY_UXIE
    const u32 gMonFrontPic_Uxie[] = INCBIN_U32("graphics/pokemon/uxie/anim_front.4bpp.lz");
    const u32 gMonPalette_Uxie[] = INCBIN_U32("graphics/pokemon/uxie/normal.gbapal.lz");
    const u32 gMonBackPic_Uxie[] = INCBIN_U32("graphics/pokemon/uxie/back.4bpp.lz");
    const u32 gMonShinyPalette_Uxie[] = INCBIN_U32("graphics/pokemon/uxie/shiny.gbapal.lz");
    const u8 gMonIcon_Uxie[] = INCBIN_U8("graphics/pokemon/uxie/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Uxie[] = INCBIN_U8("graphics/pokemon/uxie/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Uxie[] = INCBIN_COMP("graphics/pokemon/uxie/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Uxie[] = INCBIN_U32("graphics/pokemon/uxie/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Uxie[] = INCBIN_U32("graphics/pokemon/uxie/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_UXIE

#if P_FAMILY_MESPRIT
    const u32 gMonFrontPic_Mesprit[] = INCBIN_U32("graphics/pokemon/mesprit/anim_front.4bpp.lz");
    const u32 gMonPalette_Mesprit[] = INCBIN_U32("graphics/pokemon/mesprit/normal.gbapal.lz");
    const u32 gMonBackPic_Mesprit[] = INCBIN_U32("graphics/pokemon/mesprit/back.4bpp.lz");
    const u32 gMonShinyPalette_Mesprit[] = INCBIN_U32("graphics/pokemon/mesprit/shiny.gbapal.lz");
    const u8 gMonIcon_Mesprit[] = INCBIN_U8("graphics/pokemon/mesprit/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Mesprit[] = INCBIN_U8("graphics/pokemon/mesprit/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Mesprit[] = INCBIN_COMP("graphics/pokemon/mesprit/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Mesprit[] = INCBIN_U32("graphics/pokemon/mesprit/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Mesprit[] = INCBIN_U32("graphics/pokemon/mesprit/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_MESPRIT

#if P_FAMILY_AZELF
    const u32 gMonFrontPic_Azelf[] = INCBIN_U32("graphics/pokemon/azelf/anim_front.4bpp.lz");
    const u32 gMonPalette_Azelf[] = INCBIN_U32("graphics/pokemon/azelf/normal.gbapal.lz");
    const u32 gMonBackPic_Azelf[] = INCBIN_U32("graphics/pokemon/azelf/back.4bpp.lz");
    const u32 gMonShinyPalette_Azelf[] = INCBIN_U32("graphics/pokemon/azelf/shiny.gbapal.lz");
    const u8 gMonIcon_Azelf[] = INCBIN_U8("graphics/pokemon/azelf/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Azelf[] = INCBIN_U8("graphics/pokemon/azelf/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Azelf[] = INCBIN_COMP("graphics/pokemon/azelf/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Azelf[] = INCBIN_U32("graphics/pokemon/azelf/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Azelf[] = INCBIN_U32("graphics/pokemon/azelf/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_AZELF

#if P_FAMILY_DIALGA
    const u32 gMonFrontPic_Dialga[] = INCBIN_U32("graphics/pokemon/dialga/anim_front.4bpp.lz");
    const u32 gMonPalette_Dialga[] = INCBIN_U32("graphics/pokemon/dialga/normal.gbapal.lz");
    const u32 gMonBackPic_Dialga[] = INCBIN_U32("graphics/pokemon/dialga/back.4bpp.lz");
    const u32 gMonShinyPalette_Dialga[] = INCBIN_U32("graphics/pokemon/dialga/shiny.gbapal.lz");
    const u8 gMonIcon_Dialga[] = INCBIN_U8("graphics/pokemon/dialga/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Dialga[] = INCBIN_U8("graphics/pokemon/dialga/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Dialga[] = INCBIN_COMP("graphics/pokemon/dialga/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Dialga[] = INCBIN_U32("graphics/pokemon/dialga/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Dialga[] = INCBIN_U32("graphics/pokemon/dialga/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_DialgaOrigin[] = INCBIN_U32("graphics/pokemon/dialga/origin/front.4bpp.lz");
    const u32 gMonPalette_DialgaOrigin[] = INCBIN_U32("graphics/pokemon/dialga/origin/normal.gbapal.lz");
    const u32 gMonBackPic_DialgaOrigin[] = INCBIN_U32("graphics/pokemon/dialga/origin/back.4bpp.lz");
    const u32 gMonShinyPalette_DialgaOrigin[] = INCBIN_U32("graphics/pokemon/dialga/origin/shiny.gbapal.lz");
    const u8 gMonIcon_DialgaOrigin[] = INCBIN_U8("graphics/pokemon/dialga/origin/icon.4bpp");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_DialgaOrigin[] = INCBIN_COMP("graphics/pokemon/dialga/origin/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_DialgaOrigin[] = INCBIN_U32("graphics/pokemon/dialga/origin/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_DialgaOrigin[] = INCBIN_U32("graphics/pokemon/dialga/origin/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_DIALGA

#if P_FAMILY_PALKIA
    const u32 gMonFrontPic_Palkia[] = INCBIN_U32("graphics/pokemon/palkia/anim_front.4bpp.lz");
    const u32 gMonPalette_Palkia[] = INCBIN_U32("graphics/pokemon/palkia/normal.gbapal.lz");
    const u32 gMonBackPic_Palkia[] = INCBIN_U32("graphics/pokemon/palkia/back.4bpp.lz");
    const u32 gMonShinyPalette_Palkia[] = INCBIN_U32("graphics/pokemon/palkia/shiny.gbapal.lz");
    const u8 gMonIcon_Palkia[] = INCBIN_U8("graphics/pokemon/palkia/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Palkia[] = INCBIN_U8("graphics/pokemon/palkia/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Palkia[] = INCBIN_COMP("graphics/pokemon/palkia/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Palkia[] = INCBIN_U32("graphics/pokemon/palkia/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Palkia[] = INCBIN_U32("graphics/pokemon/palkia/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_PalkiaOrigin[] = INCBIN_U32("graphics/pokemon/palkia/origin/front.4bpp.lz");
    const u32 gMonPalette_PalkiaOrigin[] = INCBIN_U32("graphics/pokemon/palkia/origin/normal.gbapal.lz");
    const u32 gMonBackPic_PalkiaOrigin[] = INCBIN_U32("graphics/pokemon/palkia/origin/back.4bpp.lz");
    const u32 gMonShinyPalette_PalkiaOrigin[] = INCBIN_U32("graphics/pokemon/palkia/origin/shiny.gbapal.lz");
    const u8 gMonIcon_PalkiaOrigin[] = INCBIN_U8("graphics/pokemon/palkia/origin/icon.4bpp");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_PalkiaOrigin[] = INCBIN_COMP("graphics/pokemon/palkia/origin/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_PalkiaOrigin[] = INCBIN_U32("graphics/pokemon/palkia/origin/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_PalkiaOrigin[] = INCBIN_U32("graphics/pokemon/palkia/origin/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_PALKIA

#if P_FAMILY_HEATRAN
    const u32 gMonFrontPic_Heatran[] = INCBIN_U32("graphics/pokemon/heatran/anim_front.4bpp.lz");
    const u32 gMonPalette_Heatran[] = INCBIN_U32("graphics/pokemon/heatran/normal.gbapal.lz");
    const u32 gMonBackPic_Heatran[] = INCBIN_U32("graphics/pokemon/heatran/back.4bpp.lz");
    const u32 gMonShinyPalette_Heatran[] = INCBIN_U32("graphics/pokemon/heatran/shiny.gbapal.lz");
    const u8 gMonIcon_Heatran[] = INCBIN_U8("graphics/pokemon/heatran/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Heatran[] = INCBIN_U8("graphics/pokemon/heatran/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Heatran[] = INCBIN_COMP("graphics/pokemon/heatran/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Heatran[] = INCBIN_U32("graphics/pokemon/heatran/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Heatran[] = INCBIN_U32("graphics/pokemon/heatran/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_HEATRAN

#if P_FAMILY_REGIGIGAS
    const u32 gMonFrontPic_Regigigas[] = INCBIN_U32("graphics/pokemon/regigigas/anim_front.4bpp.lz");
    const u32 gMonPalette_Regigigas[] = INCBIN_U32("graphics/pokemon/regigigas/normal.gbapal.lz");
    const u32 gMonBackPic_Regigigas[] = INCBIN_U32("graphics/pokemon/regigigas/back.4bpp.lz");
    const u32 gMonShinyPalette_Regigigas[] = INCBIN_U32("graphics/pokemon/regigigas/shiny.gbapal.lz");
    const u8 gMonIcon_Regigigas[] = INCBIN_U8("graphics/pokemon/regigigas/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Regigigas[] = INCBIN_U8("graphics/pokemon/regigigas/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Regigigas[] = INCBIN_COMP("graphics/pokemon/regigigas/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Regigigas[] = INCBIN_U32("graphics/pokemon/regigigas/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Regigigas[] = INCBIN_U32("graphics/pokemon/regigigas/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_REGIGIGAS

#if P_FAMILY_GIRATINA
    const u32 gMonFrontPic_GiratinaAltered[] = INCBIN_U32("graphics/pokemon/giratina/anim_front.4bpp.lz");
    const u32 gMonPalette_GiratinaAltered[] = INCBIN_U32("graphics/pokemon/giratina/normal.gbapal.lz");
    const u32 gMonBackPic_GiratinaAltered[] = INCBIN_U32("graphics/pokemon/giratina/back.4bpp.lz");
    const u32 gMonShinyPalette_GiratinaAltered[] = INCBIN_U32("graphics/pokemon/giratina/shiny.gbapal.lz");
    const u8 gMonIcon_GiratinaAltered[] = INCBIN_U8("graphics/pokemon/giratina/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_GiratinaAltered[] = INCBIN_U8("graphics/pokemon/giratina/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_GiratinaAltered[] = INCBIN_COMP("graphics/pokemon/giratina/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_GiratinaAltered[] = INCBIN_U32("graphics/pokemon/giratina/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_GiratinaAltered[] = INCBIN_U32("graphics/pokemon/giratina/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_GiratinaOrigin[] = INCBIN_U32("graphics/pokemon/giratina/origin/anim_front.4bpp.lz");
    const u32 gMonPalette_GiratinaOrigin[] = INCBIN_U32("graphics/pokemon/giratina/origin/normal.gbapal.lz");
    const u32 gMonBackPic_GiratinaOrigin[] = INCBIN_U32("graphics/pokemon/giratina/origin/back.4bpp.lz");
    const u32 gMonShinyPalette_GiratinaOrigin[] = INCBIN_U32("graphics/pokemon/giratina/origin/shiny.gbapal.lz");
    const u8 gMonIcon_GiratinaOrigin[] = INCBIN_U8("graphics/pokemon/giratina/origin/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_GiratinaOrigin[] = INCBIN_U8("graphics/pokemon/giratina/origin/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_GiratinaOrigin[] = INCBIN_COMP("graphics/pokemon/giratina/origin/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_GiratinaOrigin[] = INCBIN_U32("graphics/pokemon/giratina/origin/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_GiratinaOrigin[] = INCBIN_U32("graphics/pokemon/giratina/origin/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_GIRATINA

#if P_FAMILY_CRESSELIA
    const u32 gMonFrontPic_Cresselia[] = INCBIN_U32("graphics/pokemon/cresselia/anim_front.4bpp.lz");
    const u32 gMonPalette_Cresselia[] = INCBIN_U32("graphics/pokemon/cresselia/normal.gbapal.lz");
    const u32 gMonBackPic_Cresselia[] = INCBIN_U32("graphics/pokemon/cresselia/back.4bpp.lz");
    const u32 gMonShinyPalette_Cresselia[] = INCBIN_U32("graphics/pokemon/cresselia/shiny.gbapal.lz");
    const u8 gMonIcon_Cresselia[] = INCBIN_U8("graphics/pokemon/cresselia/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Cresselia[] = INCBIN_U8("graphics/pokemon/cresselia/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Cresselia[] = INCBIN_COMP("graphics/pokemon/cresselia/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Cresselia[] = INCBIN_U32("graphics/pokemon/cresselia/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Cresselia[] = INCBIN_U32("graphics/pokemon/cresselia/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_CRESSELIA

#if P_FAMILY_MANAPHY
    const u32 gMonFrontPic_Phione[] = INCBIN_U32("graphics/pokemon/phione/anim_front.4bpp.lz");
    const u32 gMonPalette_Phione[] = INCBIN_U32("graphics/pokemon/phione/normal.gbapal.lz");
    const u32 gMonBackPic_Phione[] = INCBIN_U32("graphics/pokemon/phione/back.4bpp.lz");
    const u32 gMonShinyPalette_Phione[] = INCBIN_U32("graphics/pokemon/phione/shiny.gbapal.lz");
    const u8 gMonIcon_Phione[] = INCBIN_U8("graphics/pokemon/phione/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Phione[] = INCBIN_U8("graphics/pokemon/phione/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Phione[] = INCBIN_COMP("graphics/pokemon/phione/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Phione[] = INCBIN_U32("graphics/pokemon/phione/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Phione[] = INCBIN_U32("graphics/pokemon/phione/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_Manaphy[] = INCBIN_U32("graphics/pokemon/manaphy/anim_front.4bpp.lz");
    const u32 gMonPalette_Manaphy[] = INCBIN_U32("graphics/pokemon/manaphy/normal.gbapal.lz");
    const u32 gMonBackPic_Manaphy[] = INCBIN_U32("graphics/pokemon/manaphy/back.4bpp.lz");
    const u32 gMonShinyPalette_Manaphy[] = INCBIN_U32("graphics/pokemon/manaphy/shiny.gbapal.lz");
    const u8 gMonIcon_Manaphy[] = INCBIN_U8("graphics/pokemon/manaphy/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Manaphy[] = INCBIN_U8("graphics/pokemon/manaphy/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Manaphy[] = INCBIN_COMP("graphics/pokemon/manaphy/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Manaphy[] = INCBIN_U32("graphics/pokemon/manaphy/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Manaphy[] = INCBIN_U32("graphics/pokemon/manaphy/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_MANAPHY

#if P_FAMILY_DARKRAI
    const u32 gMonFrontPic_Darkrai[] = INCBIN_U32("graphics/pokemon/darkrai/anim_front.4bpp.lz");
    const u32 gMonPalette_Darkrai[] = INCBIN_U32("graphics/pokemon/darkrai/normal.gbapal.lz");
    const u32 gMonBackPic_Darkrai[] = INCBIN_U32("graphics/pokemon/darkrai/back.4bpp.lz");
    const u32 gMonShinyPalette_Darkrai[] = INCBIN_U32("graphics/pokemon/darkrai/shiny.gbapal.lz");
    const u8 gMonIcon_Darkrai[] = INCBIN_U8("graphics/pokemon/darkrai/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Darkrai[] = INCBIN_U8("graphics/pokemon/darkrai/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_Darkrai[] = INCBIN_COMP("graphics/pokemon/darkrai/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_Darkrai[] = INCBIN_U32("graphics/pokemon/darkrai/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_Darkrai[] = INCBIN_U32("graphics/pokemon/darkrai/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_DARKRAI

#if P_FAMILY_SHAYMIN
    const u32 gMonFrontPic_ShayminLand[] = INCBIN_U32("graphics/pokemon/shaymin/anim_front.4bpp.lz");
    const u32 gMonPalette_ShayminLand[] = INCBIN_U32("graphics/pokemon/shaymin/normal.gbapal.lz");
    const u32 gMonBackPic_ShayminLand[] = INCBIN_U32("graphics/pokemon/shaymin/back.4bpp.lz");
    const u32 gMonShinyPalette_ShayminLand[] = INCBIN_U32("graphics/pokemon/shaymin/shiny.gbapal.lz");
    const u8 gMonIcon_ShayminLand[] = INCBIN_U8("graphics/pokemon/shaymin/icon.4bpp");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Shaymin[] = INCBIN_U8("graphics/pokemon/shaymin/footprint.1bpp");
#endif //P_FOOTPRINTS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_ShayminLand[] = INCBIN_COMP("graphics/pokemon/shaymin/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_ShayminLand[] = INCBIN_U32("graphics/pokemon/shaymin/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_ShayminLand[] = INCBIN_U32("graphics/pokemon/shaymin/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS

    const u32 gMonFrontPic_ShayminSky[] = INCBIN_U32("graphics/pokemon/shaymin/sky/anim_front.4bpp.lz");
    const u32 gMonPalette_ShayminSky[] = INCBIN_U32("graphics/pokemon/shaymin/sky/normal.gbapal.lz");
    const u32 gMonBackPic_ShayminSky[] = INCBIN_U32("graphics/pokemon/shaymin/sky/back.4bpp.lz");
    const u32 gMonShinyPalette_ShayminSky[] = INCBIN_U32("graphics/pokemon/shaymin/sky/shiny.gbapal.lz");
    const u8 gMonIcon_ShayminSky[] = INCBIN_U8("graphics/pokemon/shaymin/sky/icon.4bpp");
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_ShayminSky[] = INCBIN_COMP("graphics/pokemon/shaymin/sky/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_ShayminSky[] = INCBIN_U32("graphics/pokemon/shaymin/sky/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_ShayminSky[] = INCBIN_U32("graphics/pokemon/shaymin/sky/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_SHAYMIN

#if P_FAMILY_ARCEUS
    const u32 gMonFrontPic_Arceus[] = INCBIN_U32("graphics/pokemon/arceus/anim_front.4bpp.lz");
    const u32 gMonBackPic_Arceus[] = INCBIN_U32("graphics/pokemon/arceus/back.4bpp.lz");
#if P_FOOTPRINTS
    const u8 gMonFootprint_Arceus[] = INCBIN_U8("graphics/pokemon/arceus/footprint.1bpp");
#endif //P_FOOTPRINTS

    const u32 gMonPalette_ArceusNormal[] = INCBIN_U32("graphics/pokemon/arceus/normal.gbapal.lz");
    const u32 gMonShinyPalette_ArceusNormal[] = INCBIN_U32("graphics/pokemon/arceus/shiny.gbapal.lz");
    const u8 gMonIcon_ArceusNormal[] = INCBIN_U8("graphics/pokemon/arceus/icon.4bpp");

    const u32 gMonPalette_ArceusFighting[] = INCBIN_U32("graphics/pokemon/arceus/fighting/normal.gbapal.lz");
    const u32 gMonShinyPalette_ArceusFighting[] = INCBIN_U32("graphics/pokemon/arceus/fighting/shiny.gbapal.lz");

    const u32 gMonPalette_ArceusFlying[] = INCBIN_U32("graphics/pokemon/arceus/flying/normal.gbapal.lz");
    const u32 gMonShinyPalette_ArceusFlying[] = INCBIN_U32("graphics/pokemon/arceus/flying/shiny.gbapal.lz");

    const u32 gMonPalette_ArceusPoison[] = INCBIN_U32("graphics/pokemon/arceus/poison/normal.gbapal.lz");
    const u32 gMonShinyPalette_ArceusPoison[] = INCBIN_U32("graphics/pokemon/arceus/poison/shiny.gbapal.lz");

    const u32 gMonPalette_ArceusGround[] = INCBIN_U32("graphics/pokemon/arceus/ground/normal.gbapal.lz");
    const u32 gMonShinyPalette_ArceusGround[] = INCBIN_U32("graphics/pokemon/arceus/ground/shiny.gbapal.lz");

    const u32 gMonPalette_ArceusRock[] = INCBIN_U32("graphics/pokemon/arceus/rock/normal.gbapal.lz");
    const u32 gMonShinyPalette_ArceusRock[] = INCBIN_U32("graphics/pokemon/arceus/rock/shiny.gbapal.lz");

    const u32 gMonPalette_ArceusBug[] = INCBIN_U32("graphics/pokemon/arceus/bug/normal.gbapal.lz");
    const u32 gMonShinyPalette_ArceusBug[] = INCBIN_U32("graphics/pokemon/arceus/bug/shiny.gbapal.lz");

    const u32 gMonPalette_ArceusGhost[] = INCBIN_U32("graphics/pokemon/arceus/ghost/normal.gbapal.lz");
    const u32 gMonShinyPalette_ArceusGhost[] = INCBIN_U32("graphics/pokemon/arceus/ghost/shiny.gbapal.lz");

    const u32 gMonPalette_ArceusSteel[] = INCBIN_U32("graphics/pokemon/arceus/steel/normal.gbapal.lz");
    const u32 gMonShinyPalette_ArceusSteel[] = INCBIN_U32("graphics/pokemon/arceus/steel/shiny.gbapal.lz");

    const u32 gMonPalette_ArceusFire[] = INCBIN_U32("graphics/pokemon/arceus/fire/normal.gbapal.lz");
    const u32 gMonShinyPalette_ArceusFire[] = INCBIN_U32("graphics/pokemon/arceus/fire/shiny.gbapal.lz");

    const u32 gMonPalette_ArceusWater[] = INCBIN_U32("graphics/pokemon/arceus/water/normal.gbapal.lz");
    const u32 gMonShinyPalette_ArceusWater[] = INCBIN_U32("graphics/pokemon/arceus/water/shiny.gbapal.lz");

    const u32 gMonPalette_ArceusGrass[] = INCBIN_U32("graphics/pokemon/arceus/grass/normal.gbapal.lz");
    const u32 gMonShinyPalette_ArceusGrass[] = INCBIN_U32("graphics/pokemon/arceus/grass/shiny.gbapal.lz");

    const u32 gMonPalette_ArceusElectric[] = INCBIN_U32("graphics/pokemon/arceus/electric/normal.gbapal.lz");
    const u32 gMonShinyPalette_ArceusElectric[] = INCBIN_U32("graphics/pokemon/arceus/electric/shiny.gbapal.lz");

    const u32 gMonPalette_ArceusPsychic[] = INCBIN_U32("graphics/pokemon/arceus/psychic/normal.gbapal.lz");
    const u32 gMonShinyPalette_ArceusPsychic[] = INCBIN_U32("graphics/pokemon/arceus/psychic/shiny.gbapal.lz");

    const u32 gMonPalette_ArceusIce[] = INCBIN_U32("graphics/pokemon/arceus/ice/normal.gbapal.lz");
    const u32 gMonShinyPalette_ArceusIce[] = INCBIN_U32("graphics/pokemon/arceus/ice/shiny.gbapal.lz");

    const u32 gMonPalette_ArceusDragon[] = INCBIN_U32("graphics/pokemon/arceus/dragon/normal.gbapal.lz");
    const u32 gMonShinyPalette_ArceusDragon[] = INCBIN_U32("graphics/pokemon/arceus/dragon/shiny.gbapal.lz");

    const u32 gMonPalette_ArceusDark[] = INCBIN_U32("graphics/pokemon/arceus/dark/normal.gbapal.lz");
    const u32 gMonShinyPalette_ArceusDark[] = INCBIN_U32("graphics/pokemon/arceus/dark/shiny.gbapal.lz");

    const u32 gMonPalette_ArceusFairy[] = INCBIN_U32("graphics/pokemon/arceus/fairy/normal.gbapal.lz");
    const u32 gMonShinyPalette_ArceusFairy[] = INCBIN_U32("graphics/pokemon/arceus/fairy/shiny.gbapal.lz");

#if P_ARCEUS_UNIQUE_FORM_ICONS >= GEN_9
    const u8 gMonIcon_ArceusFighting[] = INCBIN_U8("graphics/pokemon/arceus/fighting/icon.4bpp");
    const u8 gMonIcon_ArceusFlying[] = INCBIN_U8("graphics/pokemon/arceus/flying/icon.4bpp");
    const u8 gMonIcon_ArceusPoison[] = INCBIN_U8("graphics/pokemon/arceus/poison/icon.4bpp");
    const u8 gMonIcon_ArceusGround[] = INCBIN_U8("graphics/pokemon/arceus/ground/icon.4bpp");
    const u8 gMonIcon_ArceusRock[] = INCBIN_U8("graphics/pokemon/arceus/rock/icon.4bpp");
    const u8 gMonIcon_ArceusBug[] = INCBIN_U8("graphics/pokemon/arceus/bug/icon.4bpp");
    const u8 gMonIcon_ArceusGhost[] = INCBIN_U8("graphics/pokemon/arceus/ghost/icon.4bpp");
    const u8 gMonIcon_ArceusSteel[] = INCBIN_U8("graphics/pokemon/arceus/steel/icon.4bpp");
    const u8 gMonIcon_ArceusFire[] = INCBIN_U8("graphics/pokemon/arceus/fire/icon.4bpp");
    const u8 gMonIcon_ArceusWater[] = INCBIN_U8("graphics/pokemon/arceus/water/icon.4bpp");
    const u8 gMonIcon_ArceusGrass[] = INCBIN_U8("graphics/pokemon/arceus/grass/icon.4bpp");
    const u8 gMonIcon_ArceusElectric[] = INCBIN_U8("graphics/pokemon/arceus/electric/icon.4bpp");
    const u8 gMonIcon_ArceusPsychic[] = INCBIN_U8("graphics/pokemon/arceus/psychic/icon.4bpp");
    const u8 gMonIcon_ArceusIce[] = INCBIN_U8("graphics/pokemon/arceus/ice/icon.4bpp");
    const u8 gMonIcon_ArceusDragon[] = INCBIN_U8("graphics/pokemon/arceus/dragon/icon.4bpp");
    const u8 gMonIcon_ArceusDark[] = INCBIN_U8("graphics/pokemon/arceus/dark/icon.4bpp");
    const u8 gMonIcon_ArceusFairy[] = INCBIN_U8("graphics/pokemon/arceus/fairy/icon.4bpp");
#endif //P_ARCEUS_UNIQUE_FORM_ICONS
#if OW_POKEMON_OBJECT_EVENTS
    const u32 gObjectEventPic_ArceusNormal[] = INCBIN_COMP("graphics/pokemon/arceus/overworld.4bpp");
    const u32 gObjectEventPic_ArceusFighting[] = INCBIN_COMP("graphics/pokemon/arceus/overworld.4bpp");
    const u32 gObjectEventPic_ArceusFlying[] = INCBIN_COMP("graphics/pokemon/arceus/overworld.4bpp");
    const u32 gObjectEventPic_ArceusPoison[] = INCBIN_COMP("graphics/pokemon/arceus/overworld.4bpp");
    const u32 gObjectEventPic_ArceusGround[] = INCBIN_COMP("graphics/pokemon/arceus/overworld.4bpp");
    const u32 gObjectEventPic_ArceusRock[] = INCBIN_COMP("graphics/pokemon/arceus/overworld.4bpp");
    const u32 gObjectEventPic_ArceusBug[] = INCBIN_COMP("graphics/pokemon/arceus/overworld.4bpp");
    const u32 gObjectEventPic_ArceusGhost[] = INCBIN_COMP("graphics/pokemon/arceus/overworld.4bpp");
    const u32 gObjectEventPic_ArceusSteel[] = INCBIN_COMP("graphics/pokemon/arceus/overworld.4bpp");
    const u32 gObjectEventPic_ArceusFire[] = INCBIN_COMP("graphics/pokemon/arceus/overworld.4bpp");
    const u32 gObjectEventPic_ArceusWater[] = INCBIN_COMP("graphics/pokemon/arceus/overworld.4bpp");
    const u32 gObjectEventPic_ArceusGrass[] = INCBIN_COMP("graphics/pokemon/arceus/overworld.4bpp");
    const u32 gObjectEventPic_ArceusElectric[] = INCBIN_COMP("graphics/pokemon/arceus/overworld.4bpp");
    const u32 gObjectEventPic_ArceusPsychic[] = INCBIN_COMP("graphics/pokemon/arceus/overworld.4bpp");
    const u32 gObjectEventPic_ArceusIce[] = INCBIN_COMP("graphics/pokemon/arceus/overworld.4bpp");
    const u32 gObjectEventPic_ArceusDragon[] = INCBIN_COMP("graphics/pokemon/arceus/overworld.4bpp");
    const u32 gObjectEventPic_ArceusDark[] = INCBIN_COMP("graphics/pokemon/arceus/overworld.4bpp");
    const u32 gObjectEventPic_ArceusFairy[] = INCBIN_COMP("graphics/pokemon/arceus/overworld.4bpp");
#if OW_PKMN_OBJECTS_SHARE_PALETTES == FALSE
    const u32 gOverworldPalette_ArceusNormal[] = INCBIN_U32("graphics/pokemon/arceus/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_ArceusFighting[] = INCBIN_U32("graphics/pokemon/arceus/fighting/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_ArceusFlying[] = INCBIN_U32("graphics/pokemon/arceus/flying/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_ArceusPoison[] = INCBIN_U32("graphics/pokemon/arceus/poison/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_ArceusGround[] = INCBIN_U32("graphics/pokemon/arceus/ground/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_ArceusRock[] = INCBIN_U32("graphics/pokemon/arceus/rock/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_ArceusBug[] = INCBIN_U32("graphics/pokemon/arceus/bug/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_ArceusGhost[] = INCBIN_U32("graphics/pokemon/arceus/ghost/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_ArceusSteel[] = INCBIN_U32("graphics/pokemon/arceus/steel/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_ArceusFire[] = INCBIN_U32("graphics/pokemon/arceus/fire/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_ArceusWater[] = INCBIN_U32("graphics/pokemon/arceus/water/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_ArceusGrass[] = INCBIN_U32("graphics/pokemon/arceus/grass/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_ArceusElectric[] = INCBIN_U32("graphics/pokemon/arceus/electric/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_ArceusPsychic[] = INCBIN_U32("graphics/pokemon/arceus/psychic/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_ArceusIce[] = INCBIN_U32("graphics/pokemon/arceus/ice/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_ArceusDragon[] = INCBIN_U32("graphics/pokemon/arceus/dragon/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_ArceusDark[] = INCBIN_U32("graphics/pokemon/arceus/dark/overworld_normal.gbapal.lz");
    const u32 gOverworldPalette_ArceusFairy[] = INCBIN_U32("graphics/pokemon/arceus/fairy/overworld_normal.gbapal.lz");
    const u32 gShinyOverworldPalette_ArceusNormal[] = INCBIN_U32("graphics/pokemon/arceus/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_ArceusFighting[] = INCBIN_U32("graphics/pokemon/arceus/fighting/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_ArceusFlying[] = INCBIN_U32("graphics/pokemon/arceus/flying/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_ArceusPoison[] = INCBIN_U32("graphics/pokemon/arceus/poison/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_ArceusGround[] = INCBIN_U32("graphics/pokemon/arceus/ground/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_ArceusRock[] = INCBIN_U32("graphics/pokemon/arceus/rock/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_ArceusBug[] = INCBIN_U32("graphics/pokemon/arceus/bug/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_ArceusGhost[] = INCBIN_U32("graphics/pokemon/arceus/ghost/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_ArceusSteel[] = INCBIN_U32("graphics/pokemon/arceus/steel/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_ArceusFire[] = INCBIN_U32("graphics/pokemon/arceus/fire/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_ArceusWater[] = INCBIN_U32("graphics/pokemon/arceus/water/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_ArceusGrass[] = INCBIN_U32("graphics/pokemon/arceus/grass/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_ArceusElectric[] = INCBIN_U32("graphics/pokemon/arceus/electric/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_ArceusPsychic[] = INCBIN_U32("graphics/pokemon/arceus/psychic/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_ArceusIce[] = INCBIN_U32("graphics/pokemon/arceus/ice/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_ArceusDragon[] = INCBIN_U32("graphics/pokemon/arceus/dragon/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_ArceusDark[] = INCBIN_U32("graphics/pokemon/arceus/dark/overworld_shiny.gbapal.lz");
    const u32 gShinyOverworldPalette_ArceusFairy[] = INCBIN_U32("graphics/pokemon/arceus/fairy/overworld_shiny.gbapal.lz");
#endif //OW_PKMN_OBJECTS_SHARE_PALETTES
#endif //OW_POKEMON_OBJECT_EVENTS
#endif //P_FAMILY_ARCEUS

    const u32 gMonFrontPic_Egg[] = INCBIN_U32("graphics/pokemon/egg/anim_front.4bpp.lz");
    const u32 gMonPalette_Egg[] = INCBIN_U32("graphics/pokemon/egg/normal.gbapal.lz");
    const u8 gMonIcon_Egg[] = INCBIN_U8("graphics/pokemon/egg/icon.4bpp");
