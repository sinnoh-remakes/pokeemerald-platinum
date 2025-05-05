#ifndef GUARD_CONFIG_SPECIES_ENABLED_H
#define GUARD_CONFIG_SPECIES_ENABLED_H

// WARNING: For some reason, using 1/0 instead of TRUE/FALSE causes cry IDs to be shifted.
// Please use TRUE/FALSE when using the family toggles.

// Modifying the latest generation WILL change the saveblock due to Dex flags and will require a new save file.
// Generations of Pokémon are defined by the first member introduced,
// so Pikachu depends on the Gen 1 setting despite Pichu being the lowest member of the evolution tree.
// Eg: If P_GEN_2_POKEMON is set to FALSE, all members of the Sneasel Family will be disabled
// (Sneasel + Hisuian, Weavile and Sneasler).
#define P_GEN_1_POKEMON                  TRUE  // Generation 1 Pokémon (RGBY)
#define P_GEN_2_POKEMON                  TRUE  // Generation 2 Pokémon (GSC)
#define P_GEN_3_POKEMON                  TRUE  // Generation 3 Pokémon (RSE, FRLG)
#define P_GEN_4_POKEMON                  TRUE  // Generation 4 Pokémon (DPPt, HGSS)

// Battle gimmick specific Forms.
#define P_MEGA_EVOLUTIONS                FALSE
#define P_PRIMAL_REVERSIONS              FALSE // Groudon and Kyogre only.
#define P_ULTRA_BURST_FORMS              FALSE // Ultra Necrozma only.
#define P_GIGANTAMAX_FORMS               FALSE
#define P_TERA_FORMS                     FALSE

// Fusion forms
#define P_FUSION_FORMS                   FALSE

// Regional Forms. Includes Regional Form evolutions, like Sirfetch'd.
#define P_REGIONAL_FORMS                 FALSE
#define P_ALOLAN_FORMS                   P_REGIONAL_FORMS
#define P_GALARIAN_FORMS                 P_REGIONAL_FORMS
#define P_HISUIAN_FORMS                  P_REGIONAL_FORMS
#define P_PALDEAN_FORMS                  P_REGIONAL_FORMS

// Cross-generation evolutions. Includes pre-evolutions.
#define P_CROSS_GENERATION_EVOS          TRUE
#define P_GEN_2_CROSS_EVOS               P_CROSS_GENERATION_EVOS
#define P_GEN_3_CROSS_EVOS               P_CROSS_GENERATION_EVOS
#define P_GEN_4_CROSS_EVOS               P_CROSS_GENERATION_EVOS
//#define P_GEN_5_CROSS_EVOS             // Gen 5 didn't introduce any cross-gen evos.
#define P_GEN_6_CROSS_EVOS               FALSE // Just Sylveon.
//#define P_GEN_7_CROSS_EVOS             // Alolan evolutions handled by P_ALOLAN_FORMS.
#define P_GEN_8_CROSS_EVOS               FALSE // Regional evolutions handled by P_GALARIAN_FORMS and P_HISUIAN_FORMS.
#define P_GEN_9_CROSS_EVOS               FALSE // Clodsire handled by P_PALDEAN_FORMS.

// To disable specific families, replace P_GEN_x_POKEMON with FALSE.
#define P_FAMILY_BULBASAUR               P_GEN_1_POKEMON
#define P_FAMILY_CHARMANDER              P_GEN_1_POKEMON
#define P_FAMILY_SQUIRTLE                P_GEN_1_POKEMON
#define P_FAMILY_CATERPIE                P_GEN_1_POKEMON
#define P_FAMILY_WEEDLE                  P_GEN_1_POKEMON
#define P_FAMILY_PIDGEY                  P_GEN_1_POKEMON
#define P_FAMILY_RATTATA                 P_GEN_1_POKEMON
#define P_FAMILY_SPEAROW                 P_GEN_1_POKEMON
#define P_FAMILY_EKANS                   P_GEN_1_POKEMON
#define P_FAMILY_PIKACHU                 P_GEN_1_POKEMON
#define P_FAMILY_SANDSHREW               P_GEN_1_POKEMON
#define P_FAMILY_NIDORAN                 P_GEN_1_POKEMON
#define P_FAMILY_CLEFAIRY                P_GEN_1_POKEMON
#define P_FAMILY_VULPIX                  P_GEN_1_POKEMON
#define P_FAMILY_JIGGLYPUFF              P_GEN_1_POKEMON
#define P_FAMILY_ZUBAT                   P_GEN_1_POKEMON
#define P_FAMILY_ODDISH                  P_GEN_1_POKEMON
#define P_FAMILY_PARAS                   P_GEN_1_POKEMON
#define P_FAMILY_VENONAT                 P_GEN_1_POKEMON
#define P_FAMILY_DIGLETT                 P_GEN_1_POKEMON
#define P_FAMILY_MEOWTH                  P_GEN_1_POKEMON
#define P_FAMILY_PSYDUCK                 P_GEN_1_POKEMON
#define P_FAMILY_MANKEY                  P_GEN_1_POKEMON
#define P_FAMILY_GROWLITHE               P_GEN_1_POKEMON
#define P_FAMILY_POLIWAG                 P_GEN_1_POKEMON
#define P_FAMILY_ABRA                    P_GEN_1_POKEMON
#define P_FAMILY_MACHOP                  P_GEN_1_POKEMON
#define P_FAMILY_BELLSPROUT              P_GEN_1_POKEMON
#define P_FAMILY_TENTACOOL               P_GEN_1_POKEMON
#define P_FAMILY_GEODUDE                 P_GEN_1_POKEMON
#define P_FAMILY_PONYTA                  P_GEN_1_POKEMON
#define P_FAMILY_SLOWPOKE                P_GEN_1_POKEMON
#define P_FAMILY_MAGNEMITE               P_GEN_1_POKEMON
#define P_FAMILY_FARFETCHD               P_GEN_1_POKEMON
#define P_FAMILY_DODUO                   P_GEN_1_POKEMON
#define P_FAMILY_SEEL                    P_GEN_1_POKEMON
#define P_FAMILY_GRIMER                  P_GEN_1_POKEMON
#define P_FAMILY_SHELLDER                P_GEN_1_POKEMON
#define P_FAMILY_GASTLY                  P_GEN_1_POKEMON
#define P_FAMILY_ONIX                    P_GEN_1_POKEMON
#define P_FAMILY_DROWZEE                 P_GEN_1_POKEMON
#define P_FAMILY_KRABBY                  P_GEN_1_POKEMON
#define P_FAMILY_VOLTORB                 P_GEN_1_POKEMON
#define P_FAMILY_EXEGGCUTE               P_GEN_1_POKEMON
#define P_FAMILY_CUBONE                  P_GEN_1_POKEMON
#define P_FAMILY_HITMONS                 P_GEN_1_POKEMON
#define P_FAMILY_LICKITUNG               P_GEN_1_POKEMON
#define P_FAMILY_KOFFING                 P_GEN_1_POKEMON
#define P_FAMILY_RHYHORN                 P_GEN_1_POKEMON
#define P_FAMILY_CHANSEY                 P_GEN_1_POKEMON
#define P_FAMILY_TANGELA                 P_GEN_1_POKEMON
#define P_FAMILY_KANGASKHAN              P_GEN_1_POKEMON
#define P_FAMILY_HORSEA                  P_GEN_1_POKEMON
#define P_FAMILY_GOLDEEN                 P_GEN_1_POKEMON
#define P_FAMILY_STARYU                  P_GEN_1_POKEMON
#define P_FAMILY_MR_MIME                 P_GEN_1_POKEMON
#define P_FAMILY_SCYTHER                 P_GEN_1_POKEMON
#define P_FAMILY_JYNX                    P_GEN_1_POKEMON
#define P_FAMILY_ELECTABUZZ              P_GEN_1_POKEMON
#define P_FAMILY_MAGMAR                  P_GEN_1_POKEMON
#define P_FAMILY_PINSIR                  P_GEN_1_POKEMON
#define P_FAMILY_TAUROS                  P_GEN_1_POKEMON
#define P_FAMILY_MAGIKARP                P_GEN_1_POKEMON
#define P_FAMILY_LAPRAS                  P_GEN_1_POKEMON
#define P_FAMILY_DITTO                   P_GEN_1_POKEMON
#define P_FAMILY_EEVEE                   P_GEN_1_POKEMON
#define P_FAMILY_PORYGON                 P_GEN_1_POKEMON
#define P_FAMILY_OMANYTE                 P_GEN_1_POKEMON
#define P_FAMILY_KABUTO                  P_GEN_1_POKEMON
#define P_FAMILY_AERODACTYL              P_GEN_1_POKEMON
#define P_FAMILY_SNORLAX                 P_GEN_1_POKEMON
#define P_FAMILY_ARTICUNO                P_GEN_1_POKEMON
#define P_FAMILY_ZAPDOS                  P_GEN_1_POKEMON
#define P_FAMILY_MOLTRES                 P_GEN_1_POKEMON
#define P_FAMILY_DRATINI                 P_GEN_1_POKEMON
#define P_FAMILY_MEWTWO                  P_GEN_1_POKEMON
#define P_FAMILY_MEW                     P_GEN_1_POKEMON

#define P_FAMILY_CHIKORITA               P_GEN_2_POKEMON
#define P_FAMILY_CYNDAQUIL               P_GEN_2_POKEMON
#define P_FAMILY_TOTODILE                P_GEN_2_POKEMON
#define P_FAMILY_SENTRET                 P_GEN_2_POKEMON
#define P_FAMILY_HOOTHOOT                P_GEN_2_POKEMON
#define P_FAMILY_LEDYBA                  P_GEN_2_POKEMON
#define P_FAMILY_SPINARAK                P_GEN_2_POKEMON
#define P_FAMILY_CHINCHOU                P_GEN_2_POKEMON
#define P_FAMILY_TOGEPI                  P_GEN_2_POKEMON
#define P_FAMILY_NATU                    P_GEN_2_POKEMON
#define P_FAMILY_MAREEP                  P_GEN_2_POKEMON
#define P_FAMILY_MARILL                  P_GEN_2_POKEMON
#define P_FAMILY_SUDOWOODO               P_GEN_2_POKEMON
#define P_FAMILY_HOPPIP                  P_GEN_2_POKEMON
#define P_FAMILY_AIPOM                   P_GEN_2_POKEMON
#define P_FAMILY_SUNKERN                 P_GEN_2_POKEMON
#define P_FAMILY_YANMA                   P_GEN_2_POKEMON
#define P_FAMILY_WOOPER                  P_GEN_2_POKEMON
#define P_FAMILY_MURKROW                 P_GEN_2_POKEMON
#define P_FAMILY_MISDREAVUS              P_GEN_2_POKEMON
#define P_FAMILY_UNOWN                   P_GEN_2_POKEMON
#define P_FAMILY_WOBBUFFET               P_GEN_2_POKEMON
#define P_FAMILY_GIRAFARIG               P_GEN_2_POKEMON
#define P_FAMILY_PINECO                  P_GEN_2_POKEMON
#define P_FAMILY_DUNSPARCE               P_GEN_2_POKEMON
#define P_FAMILY_GLIGAR                  P_GEN_2_POKEMON
#define P_FAMILY_SNUBBULL                P_GEN_2_POKEMON
#define P_FAMILY_QWILFISH                P_GEN_2_POKEMON
#define P_FAMILY_SHUCKLE                 P_GEN_2_POKEMON
#define P_FAMILY_HERACROSS               P_GEN_2_POKEMON
#define P_FAMILY_SNEASEL                 P_GEN_2_POKEMON
#define P_FAMILY_TEDDIURSA               P_GEN_2_POKEMON
#define P_FAMILY_SLUGMA                  P_GEN_2_POKEMON
#define P_FAMILY_SWINUB                  P_GEN_2_POKEMON
#define P_FAMILY_CORSOLA                 P_GEN_2_POKEMON
#define P_FAMILY_REMORAID                P_GEN_2_POKEMON
#define P_FAMILY_DELIBIRD                P_GEN_2_POKEMON
#define P_FAMILY_MANTINE                 P_GEN_2_POKEMON
#define P_FAMILY_SKARMORY                P_GEN_2_POKEMON
#define P_FAMILY_HOUNDOUR                P_GEN_2_POKEMON
#define P_FAMILY_PHANPY                  P_GEN_2_POKEMON
#define P_FAMILY_STANTLER                P_GEN_2_POKEMON
#define P_FAMILY_SMEARGLE                P_GEN_2_POKEMON
#define P_FAMILY_MILTANK                 P_GEN_2_POKEMON
#define P_FAMILY_RAIKOU                  P_GEN_2_POKEMON
#define P_FAMILY_ENTEI                   P_GEN_2_POKEMON
#define P_FAMILY_SUICUNE                 P_GEN_2_POKEMON
#define P_FAMILY_LARVITAR                P_GEN_2_POKEMON
#define P_FAMILY_LUGIA                   P_GEN_2_POKEMON
#define P_FAMILY_HO_OH                   P_GEN_2_POKEMON
#define P_FAMILY_CELEBI                  P_GEN_2_POKEMON

#define P_FAMILY_TREECKO                 P_GEN_3_POKEMON
#define P_FAMILY_TORCHIC                 P_GEN_3_POKEMON
#define P_FAMILY_MUDKIP                  P_GEN_3_POKEMON
#define P_FAMILY_POOCHYENA               P_GEN_3_POKEMON
#define P_FAMILY_ZIGZAGOON               P_GEN_3_POKEMON
#define P_FAMILY_WURMPLE                 P_GEN_3_POKEMON
#define P_FAMILY_LOTAD                   P_GEN_3_POKEMON
#define P_FAMILY_SEEDOT                  P_GEN_3_POKEMON
#define P_FAMILY_TAILLOW                 P_GEN_3_POKEMON
#define P_FAMILY_WINGULL                 P_GEN_3_POKEMON
#define P_FAMILY_RALTS                   P_GEN_3_POKEMON
#define P_FAMILY_SURSKIT                 P_GEN_3_POKEMON
#define P_FAMILY_SHROOMISH               P_GEN_3_POKEMON
#define P_FAMILY_SLAKOTH                 P_GEN_3_POKEMON
#define P_FAMILY_NINCADA                 P_GEN_3_POKEMON
#define P_FAMILY_WHISMUR                 P_GEN_3_POKEMON
#define P_FAMILY_MAKUHITA                P_GEN_3_POKEMON
#define P_FAMILY_NOSEPASS                P_GEN_3_POKEMON
#define P_FAMILY_SKITTY                  P_GEN_3_POKEMON
#define P_FAMILY_SABLEYE                 P_GEN_3_POKEMON
#define P_FAMILY_MAWILE                  P_GEN_3_POKEMON
#define P_FAMILY_ARON                    P_GEN_3_POKEMON
#define P_FAMILY_MEDITITE                P_GEN_3_POKEMON
#define P_FAMILY_ELECTRIKE               P_GEN_3_POKEMON
#define P_FAMILY_PLUSLE                  P_GEN_3_POKEMON
#define P_FAMILY_MINUN                   P_GEN_3_POKEMON
#define P_FAMILY_VOLBEAT_ILLUMISE        P_GEN_3_POKEMON
#define P_FAMILY_ROSELIA                 P_GEN_3_POKEMON
#define P_FAMILY_GULPIN                  P_GEN_3_POKEMON
#define P_FAMILY_CARVANHA                P_GEN_3_POKEMON
#define P_FAMILY_WAILMER                 P_GEN_3_POKEMON
#define P_FAMILY_NUMEL                   P_GEN_3_POKEMON
#define P_FAMILY_TORKOAL                 P_GEN_3_POKEMON
#define P_FAMILY_SPOINK                  P_GEN_3_POKEMON
#define P_FAMILY_SPINDA                  P_GEN_3_POKEMON
#define P_FAMILY_TRAPINCH                P_GEN_3_POKEMON
#define P_FAMILY_CACNEA                  P_GEN_3_POKEMON
#define P_FAMILY_SWABLU                  P_GEN_3_POKEMON
#define P_FAMILY_ZANGOOSE                P_GEN_3_POKEMON
#define P_FAMILY_SEVIPER                 P_GEN_3_POKEMON
#define P_FAMILY_LUNATONE                P_GEN_3_POKEMON
#define P_FAMILY_SOLROCK                 P_GEN_3_POKEMON
#define P_FAMILY_BARBOACH                P_GEN_3_POKEMON
#define P_FAMILY_CORPHISH                P_GEN_3_POKEMON
#define P_FAMILY_BALTOY                  P_GEN_3_POKEMON
#define P_FAMILY_LILEEP                  P_GEN_3_POKEMON
#define P_FAMILY_ANORITH                 P_GEN_3_POKEMON
#define P_FAMILY_FEEBAS                  P_GEN_3_POKEMON
#define P_FAMILY_CASTFORM                P_GEN_3_POKEMON
#define P_FAMILY_KECLEON                 P_GEN_3_POKEMON
#define P_FAMILY_SHUPPET                 P_GEN_3_POKEMON
#define P_FAMILY_DUSKULL                 P_GEN_3_POKEMON
#define P_FAMILY_TROPIUS                 P_GEN_3_POKEMON
#define P_FAMILY_CHIMECHO                P_GEN_3_POKEMON
#define P_FAMILY_ABSOL                   P_GEN_3_POKEMON
#define P_FAMILY_SNORUNT                 P_GEN_3_POKEMON
#define P_FAMILY_SPHEAL                  P_GEN_3_POKEMON
#define P_FAMILY_CLAMPERL                P_GEN_3_POKEMON
#define P_FAMILY_RELICANTH               P_GEN_3_POKEMON
#define P_FAMILY_LUVDISC                 P_GEN_3_POKEMON
#define P_FAMILY_BAGON                   P_GEN_3_POKEMON
#define P_FAMILY_BELDUM                  P_GEN_3_POKEMON
#define P_FAMILY_REGIROCK                P_GEN_3_POKEMON
#define P_FAMILY_REGICE                  P_GEN_3_POKEMON
#define P_FAMILY_REGISTEEL               P_GEN_3_POKEMON
#define P_FAMILY_LATIAS                  P_GEN_3_POKEMON
#define P_FAMILY_LATIOS                  P_GEN_3_POKEMON
#define P_FAMILY_KYOGRE                  P_GEN_3_POKEMON
#define P_FAMILY_GROUDON                 P_GEN_3_POKEMON
#define P_FAMILY_RAYQUAZA                P_GEN_3_POKEMON
#define P_FAMILY_JIRACHI                 P_GEN_3_POKEMON
#define P_FAMILY_DEOXYS                  P_GEN_3_POKEMON

#define P_FAMILY_TURTWIG                 P_GEN_4_POKEMON
#define P_FAMILY_CHIMCHAR                P_GEN_4_POKEMON
#define P_FAMILY_PIPLUP                  P_GEN_4_POKEMON
#define P_FAMILY_STARLY                  P_GEN_4_POKEMON
#define P_FAMILY_BIDOOF                  P_GEN_4_POKEMON
#define P_FAMILY_KRICKETOT               P_GEN_4_POKEMON
#define P_FAMILY_SHINX                   P_GEN_4_POKEMON
#define P_FAMILY_CRANIDOS                P_GEN_4_POKEMON
#define P_FAMILY_SHIELDON                P_GEN_4_POKEMON
#define P_FAMILY_BURMY                   P_GEN_4_POKEMON
#define P_FAMILY_COMBEE                  P_GEN_4_POKEMON
#define P_FAMILY_PACHIRISU               P_GEN_4_POKEMON
#define P_FAMILY_BUIZEL                  P_GEN_4_POKEMON
#define P_FAMILY_CHERUBI                 P_GEN_4_POKEMON
#define P_FAMILY_SHELLOS                 P_GEN_4_POKEMON
#define P_FAMILY_DRIFLOON                P_GEN_4_POKEMON
#define P_FAMILY_BUNEARY                 P_GEN_4_POKEMON
#define P_FAMILY_GLAMEOW                 P_GEN_4_POKEMON
#define P_FAMILY_STUNKY                  P_GEN_4_POKEMON
#define P_FAMILY_BRONZOR                 P_GEN_4_POKEMON
#define P_FAMILY_CHATOT                  P_GEN_4_POKEMON
#define P_FAMILY_SPIRITOMB               P_GEN_4_POKEMON
#define P_FAMILY_GIBLE                   P_GEN_4_POKEMON
#define P_FAMILY_RIOLU                   P_GEN_4_POKEMON
#define P_FAMILY_HIPPOPOTAS              P_GEN_4_POKEMON
#define P_FAMILY_SKORUPI                 P_GEN_4_POKEMON
#define P_FAMILY_CROAGUNK                P_GEN_4_POKEMON
#define P_FAMILY_CARNIVINE               P_GEN_4_POKEMON
#define P_FAMILY_FINNEON                 P_GEN_4_POKEMON
#define P_FAMILY_SNOVER                  P_GEN_4_POKEMON
#define P_FAMILY_ROTOM                   P_GEN_4_POKEMON
#define P_FAMILY_UXIE                    P_GEN_4_POKEMON
#define P_FAMILY_MESPRIT                 P_GEN_4_POKEMON
#define P_FAMILY_AZELF                   P_GEN_4_POKEMON
#define P_FAMILY_DIALGA                  P_GEN_4_POKEMON
#define P_FAMILY_PALKIA                  P_GEN_4_POKEMON
#define P_FAMILY_HEATRAN                 P_GEN_4_POKEMON
#define P_FAMILY_REGIGIGAS               P_GEN_4_POKEMON
#define P_FAMILY_GIRATINA                P_GEN_4_POKEMON
#define P_FAMILY_CRESSELIA               P_GEN_4_POKEMON
#define P_FAMILY_MANAPHY                 P_GEN_4_POKEMON
#define P_FAMILY_DARKRAI                 P_GEN_4_POKEMON
#define P_FAMILY_SHAYMIN                 P_GEN_4_POKEMON
#define P_FAMILY_ARCEUS                  P_GEN_4_POKEMON

#endif // GUARD_CONFIG_SPECIES_ENABLED_H
