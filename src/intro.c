#include "global.h"
#include "main.h"
#include "palette.h"
#include "scanline_effect.h"
#include "task.h"
#include "title_screen.h"
#include "libgcnmultiboot.h"
#include "malloc.h"
#include "gpu_regs.h"
#include "link.h"
#include "multiboot_pokemon_colosseum.h"
#include "load_save.h"
#include "save.h"
#include "new_game.h"
#include "m4a.h"
#include "random.h"
#include "decompress.h"
#include "constants/songs.h"
#include "intro_credits_graphics.h"
#include "trig.h"
#include "intro.h"
#include "graphics.h"
#include "sound.h"
#include "util.h"
#include "title_screen.h"
#include "expansion_intro.h"
#include "battle_anim.h"
#include "intro_frlg.h"
#include "constants/rgb.h"
#include "constants/battle_anim.h"
#include "pokemon.h"

/*
    The intro is grouped into the following scenes
    Scene 0. Copyright screen
    Scene 1. GF Logo, pan up over plants, Flygon silhouette goes by
    Scene 2. Player biking on path, joined by Pokémon
    Scene 3. A fight between Groudon/Kyogre ends with Rayquaza

    After this it progresses to the title screen
*/

static void IntroResetGpuRegs(void);

// Scene 2 main tasks
static void UNUSED Task_Scene2_Load(u8);
static void Task_Scene2_CreateSprites(u8);
static void Task_Scene2_BikeRide(u8);
static void Task_Scene2_End(u8);

// Scene 2 supplemental functions
static void SpriteCB_Torchic(struct Sprite *sprite);
static void SpriteCB_Manectric(struct Sprite *sprite);
static void SpriteCB_Volbeat(struct Sprite *sprite);
static void SpriteCB_Flygon(struct Sprite *);
static void SpriteCB_PlayerOnBicycle(struct Sprite *);

// Scene 3 main tasks
static void Task_Scene3_Load(u8);
static void Task_Scene3_SpinPokeball(u8);
static void Task_Scene3_WaitGroudon(u8);
static void Task_Scene3_LoadGroudon(u8);
static void Task_Scene3_InitGroudonBg(u8);
static void Task_Scene3_NarrowWindow(u8);
static void Task_Scene3_EndNarrowWindow(u8);
static void Task_Scene3_StartGroudon(u8);
static void Task_Scene3_Groudon(u8);
static void Task_Scene3_LoadKyogre(u8);
static void Task_Scene3_Kyogre(u8);
static void Task_Scene3_LoadClouds1(u8);
static void Task_Scene3_LoadClouds2(u8);
static void Task_Scene3_InitClouds(u8);
static void Task_Scene3_Clouds(u8);
static void Task_Scene3_LoadLightning(u8);
static void Task_Scene3_Lightning(u8);
static void Task_Scene3_LoadRayquazaAttack(u8);
static void Task_Scene3_Rayquaza(u8);
static void Task_EndIntroMovie(u8);

// Scene 3 supplemental functions
static void CreateGroudonRockSprites(u8);
static void CreateKyogreBubbleSprites_Body(u8);
static void CreateKyogreBubbleSprites_Fins(void);
static void Task_RayquazaAttack(u8);
static void SpriteCB_GroudonRocks(struct Sprite *);
static void SpriteCB_KyogreBubbles(struct Sprite *sprite);
static void SpriteCB_Lightning(struct Sprite *sprite);
static void SpriteCB_RayquazaOrb(struct Sprite *sprite);

static void MainCB2_EndIntro(void);

extern const struct BattleAnimation gBattleAnimTable[ANIM_TAG_COUNT];
extern const struct SpriteTemplate gAncientPowerRockSpriteTemplate;

enum {
    COPYRIGHT_INITIALIZE,
    COPYRIGHT_EMULATOR_BLEND,
    COPYRIGHT_START_FADE = 240,
    COPYRIGHT_FADE_OUT,
    COPYRIGHT_START_INTRO,
};

#define TAG_VOLBEAT   1500
#define TAG_TORCHIC   1501
#define TAG_MANECTRIC 1502
#define TAG_LIGHTNING 1503
#define TAG_BUBBLES   1504
#define TAG_SPARKLE   1505

#define GFXTAG_DROPS_LOGO 2000
#define PALTAG_DROPS      2000
#define PALTAG_LOGO       2001

#define TAG_FLYGON_SILHOUETTE 2002
#define TAG_RAYQUAZA_ORB      2003

#define COLOSSEUM_GAME_CODE 0x65366347 // "Gc6e" in ASCII

// Used by various tasks and sprites
#define tState data[0]
#define sState data[0]

/*
    gIntroFrameCounter is used as a persistent timer throughout the
    intro cinematic. At various points it's used to determine when
    to trigger actions or progress through the cutscene.
    The values for these are defined contiguously below.
*/
#define TIMER_BIG_DROP_START             76
#define TIMER_LOGO_APPEAR               128
#define TIMER_LOGO_LETTERS_COLOR        144
#define TIMER_BIG_DROP_FALLS            251
#define TIMER_LOGO_BLEND_OUT            256
#define TIMER_LOGO_DISAPPEAR            272
#define TIMER_SMALL_DROP_1              368
#define TIMER_SMALL_DROP_2              384
#define TIMER_SPARKLES                  560
#define TIMER_FLYGON_SILHOUETTE_APPEAR  832
#define TIMER_END_PAN_UP                904
#define TIMER_END_SCENE_1              1007
#define TIMER_START_SCENE_2            1026
#define TIMER_MANECTRIC_ENTER          1088
#define TIMER_PLAYER_DRIFT_BACK        1109
#define TIMER_MANECTRIC_RUN_CIRCULAR   1168
#define TIMER_PLAYER_MOVE_FORWARD      1214
#define TIMER_TORCHIC_ENTER            1224
#define TIMER_FLYGON_ENTER             1394
#define TIMER_PLAYER_MOVE_BACKWARD     1398
#define TIMER_PLAYER_HOLD_POSITION     1576
#define TIMER_PLAYER_EXIT              1727
#define TIMER_TORCHIC_SPEED_UP         1735
#define TIMER_TORCHIC_EXIT             1856
#define TIMER_END_SCENE_2              1946
#define TIMER_START_SCENE_3            2068
// timer is reset for scene 3
#define TIMER_POKEBALL_FADE              28
#define TIMER_START_LEGENDARIES          43

static EWRAM_DATA enum Gender sIntroCharacterGender = 0;
static EWRAM_DATA u16 sFlygonYOffset = 0;

COMMON_DATA bool8 gIntroSkipped = FALSE;
COMMON_DATA u32 gIntroFrameCounter = 0;
COMMON_DATA struct GcmbStruct gMultibootProgramStruct = {0};

static const u16 sIntroPokeball_Pal[]         = INCGFX_U16("graphics/intro/scene_3/pokeball.png", ".gbapal");
static const u32 sIntroPokeball_Tilemap[]     = INCGFX_U32("graphics/intro/scene_3/pokeball_map.bin", ".smolTM");
static const u32 sIntroPokeball_Gfx[]         = INCGFX_U32("graphics/intro/scene_3/pokeball.png", ".8bpp.smol");
static const u16 sIntroStreaks_Pal[]          = INCGFX_U16("graphics/intro/scene_3/streaks.png", ".gbapal"); // Unused
static const u32 sIntroStreaks_Gfx[]          = INCGFX_U32("graphics/intro/scene_3/streaks.png", ".4bpp.smol"); // Unused
static const u32 sIntroStreaks_Tilemap[]      = INCGFX_U32("graphics/intro/scene_3/streaks_map.bin", ".smolTM"); // Unused
static const u16 sIntroRayquzaOrb_Pal[]       = INCGFX_U16("graphics/intro/scene_3/rayquaza_orb.pal", ".gbapal");
static const u16 sIntroMisc_Pal[]             = INCGFX_U16("graphics/intro/scene_3/misc.pal", ".gbapal"); // Unused
static const u32 sIntroMisc_Gfx[]             = INCGFX_U32("graphics/intro/scene_3/misc.png", ".4bpp.smol"); // Rayquza orb, and misc unused gfx
static const struct CompressedSpriteSheet sSpriteSheet_RunningPokemon[] =
{
    {gIntroVolbeat_Gfx, 0x400, TAG_VOLBEAT},
    {gIntroTorchic_Gfx, 0xC00, TAG_TORCHIC},
    {gIntroManectric_Gfx, 0x2000, TAG_MANECTRIC},
    {},
};
static const struct SpritePalette sSpritePalettes_RunningPokemon[] =
{
    {gIntroVolbeat_Pal, TAG_VOLBEAT},
    {gIntroTorchic_Pal, TAG_TORCHIC},
    {gIntroManectric_Pal, TAG_MANECTRIC},
    {},
};
static const struct OamData sOamData_Volbeat =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd sAnim_Volbeat[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_JUMP(0),
};
static const union AnimCmd *const sAnims_Volbeat[] =
{
    sAnim_Volbeat,
};
static const struct SpriteTemplate sSpriteTemplate_Volbeat =
{
    .tileTag = TAG_VOLBEAT,
    .paletteTag = TAG_VOLBEAT,
    .oam = &sOamData_Volbeat,
    .anims = sAnims_Volbeat,
    .callback = SpriteCB_Volbeat,
};
static const struct OamData sOamData_Torchic =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd sAnim_Torchic_Walk[] =
{
    ANIMCMD_FRAME(0, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_FRAME(32, 5),
    ANIMCMD_FRAME(16, 5),
    ANIMCMD_JUMP(0),
};
static const union AnimCmd sAnim_Torchic_Run[] =
{
    ANIMCMD_FRAME(0, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_FRAME(32, 3),
    ANIMCMD_FRAME(16, 3),
    ANIMCMD_JUMP(0),
};
static const union AnimCmd sAnim_Torchic_Trip[] =
{
    ANIMCMD_FRAME(48, 4),
    ANIMCMD_FRAME(64, 6),
    ANIMCMD_FRAME(80, 0),
    ANIMCMD_END,
};
enum {
    TORCHIC_ANIM_WALK,
    TORCHIC_ANIM_RUN,
    TORCHIC_ANIM_TRIP,
};
static const union AnimCmd *const sAnims_Torchic[] =
{
    [TORCHIC_ANIM_WALK] = sAnim_Torchic_Walk,
    [TORCHIC_ANIM_RUN]  = sAnim_Torchic_Run,
    [TORCHIC_ANIM_TRIP] = sAnim_Torchic_Trip,
};
static const struct SpriteTemplate sSpriteTemplate_Torchic =
{
    .tileTag = TAG_TORCHIC,
    .paletteTag = TAG_TORCHIC,
    .oam = &sOamData_Torchic,
    .anims = sAnims_Torchic,
    .callback = SpriteCB_Torchic,
};
static const struct OamData sOamData_Manectric =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd sAnim_Manectric[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_FRAME(128, 4),
    ANIMCMD_FRAME(192, 4),
    ANIMCMD_JUMP(0),
};
static const union AnimCmd *const sAnims_Manectric[] =
{
    sAnim_Manectric,
};
static const struct SpriteTemplate sSpriteTemplate_Manectric =
{
    .tileTag = TAG_MANECTRIC,
    .paletteTag = TAG_MANECTRIC,
    .oam = &sOamData_Manectric,
    .anims = sAnims_Manectric,
    .callback = SpriteCB_Manectric,
};
static const struct CompressedSpriteSheet sSpriteSheet_Lightning[] =
{
    {gIntroLightning_Gfx, 0xC00, TAG_LIGHTNING},
    {},
};
static const struct SpritePalette sSpritePalette_Lightning[] =
{
    {gIntroLightning_Pal, TAG_LIGHTNING},
    {},
};
static const struct OamData sOamData_Lightning =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd sAnim_Lightning_Top[] =
{
    ANIMCMD_FRAME(0, 2),
    ANIMCMD_FRAME(48, 2),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_Lightning_Middle[] =
{
    ANIMCMD_FRAME(16, 2),
    ANIMCMD_FRAME(64, 2),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_Lightning_Bottom[] =
{
    ANIMCMD_FRAME(32, 2),
    ANIMCMD_FRAME(80, 2),
    ANIMCMD_END,
};
static const union AnimCmd *const sAnims_Lightning[] =
{
    sAnim_Lightning_Top,
    sAnim_Lightning_Middle,
    sAnim_Lightning_Bottom,
};
static const struct SpriteTemplate sSpriteTemplate_Lightning =
{
    .tileTag = TAG_LIGHTNING,
    .paletteTag = TAG_LIGHTNING,
    .oam = &sOamData_Lightning,
    .anims = sAnims_Lightning,
    .callback = SpriteCB_Lightning,
};
// x coord, anim number, speed
// Smaller anim numbers are larger rocks, and are given slower speeds
static const s16 sGroudonRockData[][3] =
{
    {104, 0, 0x0C0},
    {142, 3, 0x280},
    { 83, 1, 0x180},
    {155, 0, 0x080},
    { 56, 2, 0x200},
    {174, 1, 0x100},
};
static const struct CompressedSpriteSheet sSpriteSheet_Bubbles[] =
{
    {gIntroBubbles_Gfx, 0x600, TAG_BUBBLES},
    {},
};
static const struct SpritePalette sSpritePalette_Bubbles[] =
{
    {gIntroBubbles_Pal, TAG_BUBBLES},
    {},
};
#define NUM_BUBBLES_IN_SET 6
// x coord, y coord, delay before animation
// Can be produced in two different sets depending on the function called to create the sprites
static const s16 sKyogreBubbleData[NUM_BUBBLES_IN_SET * 2][3] =
{
    // Set 1, for Kyogre's body
    { 66,  64,  1},
    { 96,  96,  8},
    {128,  64,  1},
    {144,  48,  8},
    {160,  72,  1},
    {176,  96,  8},
    // Set 2, for Kyogre's fins
    { 96,  96,  4},
    {112, 104,  8},
    {128,  96,  4},
    { 88,  32,  4},
    {104,  24,  8},
    {120,  32,  4},
};
static const struct OamData sOamData_Bubbles =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(16x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(16x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd sAnim_Bubbles[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(8, 4),
    ANIMCMD_FRAME(16, 4),
    ANIMCMD_FRAME(24, 4),
    ANIMCMD_FRAME(32, 4),
    ANIMCMD_END,
};
static const union AnimCmd *const sAnims_Bubbles[] =
{
    sAnim_Bubbles,
};
static const struct SpriteTemplate sSpriteTemplate_Bubbles =
{
    .tileTag = TAG_BUBBLES,
    .paletteTag = TAG_BUBBLES,
    .oam = &sOamData_Bubbles,
    .anims = sAnims_Bubbles,
    .callback = SpriteCB_KyogreBubbles,
};
static const union AnimCmd sAnim_PlayerBicycle_Fast[] =
{
    ANIMCMD_FRAME(0, 4),
    ANIMCMD_FRAME(64, 4),
    ANIMCMD_FRAME(128, 4),
    ANIMCMD_FRAME(192, 4),
    ANIMCMD_JUMP(0),
};
static const union AnimCmd sAnim_PlayerBicycle_Slow[] =
{
    ANIMCMD_FRAME(0, 8),
    ANIMCMD_FRAME(64, 8),
    ANIMCMD_FRAME(128, 8),
    ANIMCMD_FRAME(192, 8),
    ANIMCMD_JUMP(0),
};
// The below two animations appear to be copied from the Credits version
// of the player graphic, where additional frames are present to show
// the player turning around to look at their rival.
// They go unused here, and if they were used they'd overflow beyond
// the player graphics data.
// The above sAnim_PlayerBicycle_Slow, while valid, is likewise unused
static const union AnimCmd sAnim_PlayerBicycle_LookBack[] =
{
    ANIMCMD_FRAME(256, 4),
    ANIMCMD_FRAME(320, 4),
    ANIMCMD_FRAME(384, 4),
    ANIMCMD_END,
};
static const union AnimCmd sAnim_PlayerBicycle_LookForward[] =
{
    ANIMCMD_FRAME(384, 16),
    ANIMCMD_FRAME(320, 16),
    ANIMCMD_FRAME(256, 16),
    ANIMCMD_END,
};
static const union AnimCmd *const sAnims_PlayerBicycle[] =
{
    sAnim_PlayerBicycle_Fast,
    sAnim_PlayerBicycle_Slow,
    sAnim_PlayerBicycle_LookBack,
    sAnim_PlayerBicycle_LookForward,
};
static const struct OamData sOamData_RayquazaOrb =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};
static const union AnimCmd sAnim_RayquazaOrb[] =
{
    ANIMCMD_FRAME(16, 8),
    ANIMCMD_END,
};
static const union AnimCmd *const sAnims_RayquazaOrb[] =
{
    sAnim_RayquazaOrb,
};
static const struct SpriteTemplate sSpriteTemplate_RayquazaOrb =
{
    .tileTag = TAG_RAYQUAZA_ORB,
    .paletteTag = TAG_RAYQUAZA_ORB,
    .oam = &sOamData_RayquazaOrb,
    .anims = sAnims_RayquazaOrb,
    .callback = SpriteCB_RayquazaOrb,
};
static const struct CompressedSpriteSheet sSpriteSheet_RayquazaOrb[] =
{
    {sIntroMisc_Gfx, 0xA00, TAG_RAYQUAZA_ORB},
    {},
};
static const struct SpritePalette sSpritePalette_RayquazaOrb[] =
{
    {sIntroRayquzaOrb_Pal, TAG_RAYQUAZA_ORB},
    {},
};



#define TAG_PT_STARS 2004

static EWRAM_DATA u8 sPtCopyrightAlpha = 0;
static EWRAM_DATA u8 sPtCopyrightAlphaDelay = 0;

static const u16 sPtCopyright_Pal[]         = INCGFX_U16("graphics/intro_pt/copyright.png", ".gbapal");
static const u32 sPtCopyright_Gfx[]         = INCGFX_U32("graphics/intro_pt/copyright.png", ".4bpp.smol");
static const u32 sPtCopyright_Tilemap[]     = INCGFX_U32("graphics/intro_pt/copyright.bin", ".smolTM");

static const u16 sPtScene1Bg_Pal[]          = INCGFX_U16("graphics/intro_pt/scene_1_bg.png", ".gbapal");
static const u32 sPtScene1Bg_Gfx[]          = INCGFX_U32("graphics/intro_pt/scene_1_bg.png", ".4bpp.smol");
static const u32 sPtScene1Bg_Tilemap[]      = INCGFX_U32("graphics/intro_pt/scene_1_bg.bin", ".smolTM");

static const u16 sPtGfLogo_Pal[]            = INCGFX_U16("graphics/intro_pt/gamefreak_logo.png", ".gbapal");
static const u32 sPtGfLogo_Gfx[]            = INCGFX_U32("graphics/intro_pt/gamefreak_logo.png", ".4bpp.smol");
static const u32 sPtGfLogo_Tilemap[]        = INCGFX_U32("graphics/intro_pt/gamefreak_logo.bin", ".smolTM");

static const u16 sPtGfPresents_Pal[]        = INCGFX_U16("graphics/intro_pt/gamefreak_presents.png", ".gbapal");
static const u32 sPtGfPresents_Gfx[]        = INCGFX_U32("graphics/intro_pt/gamefreak_presents.png", ".4bpp.smol");
static const u32 sPtGfPresents_Tilemap[]    = INCGFX_U32("graphics/intro_pt/gamefreak_presents.bin", ".smolTM");

static const u16 sPtStars_Pal[]             = INCGFX_U16("graphics/intro_pt/stars.png", ".gbapal");
static const u32 sPtStars_Gfx[]             = INCGFX_U32("graphics/intro_pt/stars.png", ".4bpp.smol");

static void SpriteCB_PtStar(struct Sprite *sprite);
static void Task_Scene1_Pt(u8 taskId);

static const struct OamData sOamData_PtStar =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_PtStar_0[] = { ANIMCMD_FRAME( 0, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtStar_1[] = { ANIMCMD_FRAME(16, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtStar_2[] = { ANIMCMD_FRAME(32, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtStar_3[] = { ANIMCMD_FRAME(48, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtStar_4[] = { ANIMCMD_FRAME(64, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtStar_5[] = { ANIMCMD_FRAME(80, 8), ANIMCMD_END };

static const union AnimCmd *const sAnims_PtStars[] =
{
    sAnim_PtStar_0,
    sAnim_PtStar_1,
    sAnim_PtStar_2,
    sAnim_PtStar_3,
    sAnim_PtStar_4,
    sAnim_PtStar_5,
};

static const struct SpriteTemplate sSpriteTemplate_PtStar =
{
    .tileTag = TAG_PT_STARS,
    .paletteTag = TAG_PT_STARS,
    .oam = &sOamData_PtStar,
    .anims = sAnims_PtStars,
    .callback = SpriteCB_PtStar,
};

static const struct CompressedSpriteSheet sPtStars_SpriteSheet =
{
    sPtStars_Gfx, 0xC00, TAG_PT_STARS
};

static const struct SpritePalette sPtStars_SpritePal =
{
    sPtStars_Pal, TAG_PT_STARS
};

#define TAG_PT_BALL_FX 2005

static const u16 sPtLogoInv_Pal[]       = INCGFX_U16("graphics/intro_pt/pokemon_logo_inv.png", ".gbapal");
static const u32 sPtLogoInv_Gfx[]       = INCGFX_U32("graphics/intro_pt/pokemon_logo_inv.png", ".4bpp.smol");
static const u32 sPtLogoInv_Tilemap[]   = INCGFX_U32("graphics/intro_pt/pokemon_logo_inv.bin", ".smolTM");

static const u16 sPtLogo_Pal[]          = INCGFX_U16("graphics/intro_pt/pokemon_logo.png", ".gbapal");
static const u32 sPtLogo_Gfx[]          = INCGFX_U32("graphics/intro_pt/pokemon_logo.png", ".4bpp.smol");
static const u32 sPtLogo_Tilemap[]      = INCGFX_U32("graphics/intro_pt/pokemon_logo.bin", ".smolTM");


static const u16 sPtRoute204_Pal[]      = INCGFX_U16("graphics/intro_pt/route_204.png", ".gbapal");
static const u32 sPtRoute204_Gfx[]      = INCGFX_U32("graphics/intro_pt/route_204.png", ".4bpp.smol");
static const u32 sPtRoute204_Tilemap[]  = INCGFX_U32("graphics/intro_pt/route_204.bin", ".smolTM");



#define TAG_PT_LOOKER 2006
#define TAG_PT_CHARON 2007



#define TAG_PT_S7_LUCAS_THROW   2010
#define TAG_PT_S7_DAWN_THROW    2011
#define TAG_PT_S7_LUCAS_HP      2012
#define TAG_PT_S7_DAWN_HP       2013
#define TAG_PT_S7_LUCAS_HAND    2014
#define TAG_PT_S7_DAWN_HAND     2015
#define TAG_PT_S7_POKEBALL      2016

static const u16 sPtS7Bars_Pal[]        = INCGFX_U16("graphics/intro_pt/s7_bars.png", ".gbapal");
static const u32 sPtS7Bars_Gfx[]        = INCGFX_U32("graphics/intro_pt/s7_bars.png", ".4bpp.smol");
static const u32 sPtS7Bars_Map[]        = INCGFX_U32("graphics/intro_pt/s7_bars.bin", ".smolTM");

static const u16 sPtS7LucasFx_Pal[]     = INCGFX_U16("graphics/intro_pt/lucas_effect.png", ".gbapal");
static const u32 sPtS7LucasFx_Gfx[]     = INCGFX_U32("graphics/intro_pt/lucas_effect.png", ".4bpp.smol");
static const u32 sPtS7LucasFx_Map[]     = INCGFX_U32("graphics/intro_pt/lucas_effect.bin", ".smolTM");

static const u16 sPtS7DawnFx_Pal[]      = INCGFX_U16("graphics/intro_pt/dawn_effect.png", ".gbapal");
static const u32 sPtS7DawnFx_Gfx[]      = INCGFX_U32("graphics/intro_pt/dawn_effect.png", ".4bpp.smol");
static const u32 sPtS7DawnFx_Map[]      = INCGFX_U32("graphics/intro_pt/dawn_effect.bin", ".smolTM");

static const u16 sPtS7LucasThrow_Pal[]  = INCGFX_U16("graphics/intro_pt/lucas_throw.png", ".gbapal");
static const u32 sPtS7LucasThrow_Gfx[]  = INCGFX_U32("graphics/intro_pt/lucas_throw.png", ".4bpp.smol");
static const u16 sPtS7DawnThrow_Pal[]   = INCGFX_U16("graphics/intro_pt/dawn_throw.png", ".gbapal");
static const u32 sPtS7DawnThrow_Gfx[]   = INCGFX_U32("graphics/intro_pt/dawn_throw.png", ".4bpp.smol");

static const u16 sPtS7LucasHP_Pal[]     = INCGFX_U16("graphics/intro_pt/lucas_hand_pokeball.png", ".gbapal");
static const u32 sPtS7LucasHP_Gfx[]     = INCGFX_U32("graphics/intro_pt/lucas_hand_pokeball.png", ".4bpp.smol");
static const u16 sPtS7DawnHP_Pal[]      = INCGFX_U16("graphics/intro_pt/dawn_hand_pokeball.png", ".gbapal");
static const u32 sPtS7DawnHP_Gfx[]      = INCGFX_U32("graphics/intro_pt/dawn_hand_pokeball.png", ".4bpp.smol");

static const u16 sPtS7LucasHand_Pal[]   = INCGFX_U16("graphics/intro_pt/lucas_hand.png", ".gbapal");
static const u32 sPtS7LucasHand_Gfx[]   = INCGFX_U32("graphics/intro_pt/lucas_hand.png", ".4bpp.smol");
static const u16 sPtS7DawnHand_Pal[]    = INCGFX_U16("graphics/intro_pt/dawn_hand.png", ".gbapal");
static const u32 sPtS7DawnHand_Gfx[]    = INCGFX_U32("graphics/intro_pt/dawn_hand.png", ".4bpp.smol");

static const u16 sPtS7Ball_Pal[]        = INCGFX_U16("graphics/intro_pt/s7_pokeball.png", ".gbapal");
static const u32 sPtS7Ball_Gfx[]        = INCGFX_U32("graphics/intro_pt/s7_pokeball.png", ".4bpp.smol");

static void Task_Scene7_Pt_Load(u8 taskId);
static void Task_Scene7_Pt(u8 taskId);
static void SpriteCB_PtS7HandZip(struct Sprite *sprite);
static void SpriteCB_PtS7SpinBall(struct Sprite *sprite);



static const u16 sPtS9Cyrus_Pal[]       = INCGFX_U16("graphics/intro_pt/cyrus.png", ".gbapal");
static const u32 sPtS9Cyrus_Gfx[]       = INCGFX_U32("graphics/intro_pt/cyrus.png", ".4bpp.smol");
static const u32 sPtS9Cyrus_Map[]       = INCGFX_U32("graphics/intro_pt/cyrus.bin", ".smolTM");

static void Task_Scene9_Pt_Load(u8 taskId);
static void Task_Scene9_Pt(u8 taskId);

static const u16 sPtS10Bg0_Pal[]        = INCGFX_U16("graphics/intro_pt/giratina_bg0.png", ".gbapal");
static const u32 sPtS10Bg0_Gfx[]        = INCGFX_U32("graphics/intro_pt/giratina_bg0.png", ".4bpp.smol");
static const u32 sPtS10Bg0_Map[]        = INCGFX_U32("graphics/intro_pt/giratina_bg0.bin", ".smolTM");

static const u16 sPtS10Bg1_Pal[]        = INCGFX_U16("graphics/intro_pt/giratina_bg1.png", ".gbapal");
static const u32 sPtS10Bg1_Gfx[]        = INCGFX_U32("graphics/intro_pt/giratina_bg1.png", ".4bpp.smol");
static const u32 sPtS10Bg1_Map[]        = INCGFX_U32("graphics/intro_pt/giratina_bg1.bin", ".smolTM");


#define TAG_PT_S10_EYE0     2023
#define TAG_PT_S10_EYE1     2024
#define TAG_PT_S10_EYE2     2025
#define TAG_PT_S10_EYE3     2026
#define TAG_PT_S10_MOUTH0   2027
#define TAG_PT_S10_MOUTH1   2028
#define TAG_PT_S10_MOUTH2   2029
#define TAG_PT_S10_MOUTH3   2030

static const u16 sPtS10Eye0_Pal[]      = INCGFX_U16("graphics/intro_pt/giratina_eye0.png", ".gbapal");
static const u32 sPtS10Eye0_Gfx[]      = INCGFX_U32("graphics/intro_pt/giratina_eye0.png", ".4bpp.smol");
static const u16 sPtS10Eye1_Pal[]      = INCGFX_U16("graphics/intro_pt/giratina_eye1.png", ".gbapal");
static const u32 sPtS10Eye1_Gfx[]      = INCGFX_U32("graphics/intro_pt/giratina_eye1.png", ".4bpp.smol");
static const u16 sPtS10Eye2_Pal[]      = INCGFX_U16("graphics/intro_pt/giratina_eye2.png", ".gbapal");
static const u32 sPtS10Eye2_Gfx[]      = INCGFX_U32("graphics/intro_pt/giratina_eye2.png", ".4bpp.smol");
static const u16 sPtS10Eye3_Pal[]      = INCGFX_U16("graphics/intro_pt/giratina_eye3.png", ".gbapal");
static const u32 sPtS10Eye3_Gfx[]      = INCGFX_U32("graphics/intro_pt/giratina_eye3.png", ".4bpp.smol");

static const u16 sPtS10Mouth0_Pal[]    = INCGFX_U16("graphics/intro_pt/giratina_mouth0.png", ".gbapal");
static const u32 sPtS10Mouth0_Gfx[]    = INCGFX_U32("graphics/intro_pt/giratina_mouth0.png", ".4bpp.smol");
static const u16 sPtS10Mouth1_Pal[]    = INCGFX_U16("graphics/intro_pt/giratina_mouth1.png", ".gbapal");
static const u32 sPtS10Mouth1_Gfx[]    = INCGFX_U32("graphics/intro_pt/giratina_mouth1.png", ".4bpp.smol");
static const u16 sPtS10Mouth2_Pal[]    = INCGFX_U16("graphics/intro_pt/giratina_mouth2.png", ".gbapal");
static const u32 sPtS10Mouth2_Gfx[]    = INCGFX_U32("graphics/intro_pt/giratina_mouth2.png", ".4bpp.smol");
static const u16 sPtS10Mouth3_Pal[]    = INCGFX_U16("graphics/intro_pt/giratina_mouth3.png", ".gbapal");
static const u32 sPtS10Mouth3_Gfx[]    = INCGFX_U32("graphics/intro_pt/giratina_mouth3.png", ".4bpp.smol");

static const u16 sPtS10M4_Pal[]       = INCGFX_U16("graphics/intro_pt/giratina_m4_pal.png", ".gbapal");
static const u8  sPtS10M4_Bg0[]       = INCBIN_U8("graphics/intro_pt/giratina_m4_0.bin");
static const u8  sPtS10M4_Bg1[]       = INCBIN_U8("graphics/intro_pt/giratina_m4_1.bin");

static void Task_Scene10_Pt_Load(u8 taskId);
static void Task_Scene10_Pt(u8 taskId);


#define TAG_PT_S8_TORTERRA      2017
#define TAG_PT_S8_PRINPLUP      2018
#define TAG_PT_S8_CHIMCHAR      2019
#define TAG_PT_S8_INFERNAPE     2020
#define TAG_PT_S8_GROTLE        2021
#define TAG_PT_S8_PIPLUP        2022

static const u16 sPtS8GreenFx_Pal[]     = INCGFX_U16("graphics/intro_pt/green_effect.png", ".gbapal");
static const u32 sPtS8GreenFx_Gfx[]     = INCGFX_U32("graphics/intro_pt/green_effect.png", ".4bpp.smol");
static const u32 sPtS8GreenFx_Map[]     = INCGFX_U32("graphics/intro_pt/green_effect.bin", ".smolTM");

static const u16 sPtS8RedFx_Pal[]       = INCGFX_U16("graphics/intro_pt/red_effect.png", ".gbapal");
static const u32 sPtS8RedFx_Gfx[]       = INCGFX_U32("graphics/intro_pt/red_effect.png", ".4bpp.smol");
static const u32 sPtS8RedFx_Map[]       = INCGFX_U32("graphics/intro_pt/red_effect.bin", ".smolTM");

static const u16 sPtS8Torterra_Pal[]    = INCGFX_U16("graphics/intro_pt/s8_torterra.png", ".gbapal");
static const u32 sPtS8Torterra_Gfx[]    = INCGFX_U32("graphics/intro_pt/s8_torterra.png", ".4bpp.smol");
static const u16 sPtS8Prinplup_Pal[]    = INCGFX_U16("graphics/intro_pt/s8_prinplup.png", ".gbapal");
static const u32 sPtS8Prinplup_Gfx[]    = INCGFX_U32("graphics/intro_pt/s8_prinplup.png", ".4bpp.smol");
static const u16 sPtS8Chimchar_Pal[]    = INCGFX_U16("graphics/intro_pt/s8_chimchar.png", ".gbapal");
static const u32 sPtS8Chimchar_Gfx[]    = INCGFX_U32("graphics/intro_pt/s8_chimchar.png", ".4bpp.smol");
static const u16 sPtS8Infernape_Pal[]   = INCGFX_U16("graphics/intro_pt/s8_infernape.png", ".gbapal");
static const u32 sPtS8Infernape_Gfx[]   = INCGFX_U32("graphics/intro_pt/s8_infernape.png", ".4bpp.smol");
static const u16 sPtS8Grotle_Pal[]      = INCGFX_U16("graphics/intro_pt/s8_grotle.png", ".gbapal");
static const u32 sPtS8Grotle_Gfx[]      = INCGFX_U32("graphics/intro_pt/s8_grotle.png", ".4bpp.smol");
static const u16 sPtS8Piplup_Pal[]      = INCGFX_U16("graphics/intro_pt/s8_piplup.png", ".gbapal");
static const u32 sPtS8Piplup_Gfx[]      = INCGFX_U32("graphics/intro_pt/s8_piplup.png", ".4bpp.smol");

static void Task_Scene8_Pt_Load(u8 taskId);
static void Task_Scene8_Pt(u8 taskId);
static void SpriteCB_PtS8Slide(struct Sprite *sprite);

#define TAG_PT_RUNNER 2008

static const u16 sPtLucasSky_Pal[]      = INCGFX_U16("graphics/intro_pt/lucas_sky.png", ".gbapal");
static const u32 sPtLucasSky_Gfx[]      = INCGFX_U32("graphics/intro_pt/lucas_sky.png", ".4bpp.smol");
static const u32 sPtLucasSky_Map[]      = INCGFX_U32("graphics/intro_pt/lucas_sky.bin", ".smolTM");
static const u16 sPtLucasBld_Pal[]      = INCGFX_U16("graphics/intro_pt/lucas_buildings.png", ".gbapal");
static const u32 sPtLucasBld_Gfx[]      = INCGFX_U32("graphics/intro_pt/lucas_buildings.png", ".4bpp.smol");
static const u32 sPtLucasBld_Map[]      = INCGFX_U32("graphics/intro_pt/lucas_buildings.bin", ".smolTM");
static const u16 sPtLucasTrees_Pal[]    = INCGFX_U16("graphics/intro_pt/lucas_trees.png", ".gbapal");
static const u32 sPtLucasTrees_Gfx[]    = INCGFX_U32("graphics/intro_pt/lucas_trees.png", ".4bpp.smol");
static const u32 sPtLucasTrees_Map[]    = INCGFX_U32("graphics/intro_pt/lucas_trees.bin", ".smolTM");
static const u16 sPtLucasRun_Pal[]      = INCGFX_U16("graphics/intro_pt/lucas_run.png", ".gbapal");
static const u32 sPtLucasRun_Gfx[]      = INCGFX_U32("graphics/intro_pt/lucas_run.png", ".4bpp.smol");

static const u16 sPtDawnSky_Pal[]       = INCGFX_U16("graphics/intro_pt/dawn_sky.png", ".gbapal");
static const u32 sPtDawnSky_Gfx[]       = INCGFX_U32("graphics/intro_pt/dawn_sky.png", ".4bpp.smol");
static const u32 sPtDawnSky_Map[]       = INCGFX_U32("graphics/intro_pt/dawn_sky.bin", ".smolTM");
static const u16 sPtDawnBld_Pal[]       = INCGFX_U16("graphics/intro_pt/dawn_buildings.png", ".gbapal");
static const u32 sPtDawnBld_Gfx[]       = INCGFX_U32("graphics/intro_pt/dawn_buildings.png", ".4bpp.smol");
static const u32 sPtDawnBld_Map[]       = INCGFX_U32("graphics/intro_pt/dawn_buildings.bin", ".smolTM");
static const u16 sPtDawnTrees_Pal[]     = INCGFX_U16("graphics/intro_pt/dawn_trees.png", ".gbapal");
static const u32 sPtDawnTrees_Gfx[]     = INCGFX_U32("graphics/intro_pt/dawn_trees.png", ".4bpp.smol");
static const u32 sPtDawnTrees_Map[]     = INCGFX_U32("graphics/intro_pt/dawn_trees.bin", ".smolTM");
static const u16 sPtDawnRun_Pal[]       = INCGFX_U16("graphics/intro_pt/dawn_run.png", ".gbapal");
static const u32 sPtDawnRun_Gfx[]       = INCGFX_U32("graphics/intro_pt/dawn_run.png", ".4bpp.smol");

static void Task_Scene6_Pt_Load(u8 taskId);
static void Task_Scene6_Pt(u8 taskId);

// 2 frames of 2 stacked 64x64 sprites (frame 0: tiles 0 & 64; frame 1: tiles 128 & 192)
static const union AnimCmd sAnim_PtRunner_Top0[] = { ANIMCMD_FRAME(  0, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtRunner_Bot0[] = { ANIMCMD_FRAME( 64, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtRunner_Top1[] = { ANIMCMD_FRAME(128, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtRunner_Bot1[] = { ANIMCMD_FRAME(192, 8), ANIMCMD_END };

static const union AnimCmd *const sAnims_PtRunner[] =
{
    sAnim_PtRunner_Top0,
    sAnim_PtRunner_Bot0,
    sAnim_PtRunner_Top1,
    sAnim_PtRunner_Bot1,
};

#define TAG_PT_RUNNER_DAWN 2009

static const struct CompressedSpriteSheet sPtLucasRun_Sheet = { sPtLucasRun_Gfx, 0x2000, TAG_PT_RUNNER };
static const struct SpritePalette sPtLucasRun_PalEntry    = { sPtLucasRun_Pal, TAG_PT_RUNNER };
static const struct CompressedSpriteSheet sPtDawnRun_Sheet  = { sPtDawnRun_Gfx,  0x2000, TAG_PT_RUNNER_DAWN };
static const struct SpritePalette sPtDawnRun_PalEntry     = { sPtDawnRun_Pal,  TAG_PT_RUNNER_DAWN };

static const u16 sPtEternaCity_Pal[]    = INCGFX_U16("graphics/intro_pt/eterna_city_pal.png", ".gbapal");
static const u8  sPtEternaCity_Bitmap[] = INCBIN_U8("graphics/intro_pt/eterna_city.bin");

static const u16 sPtLooker_Pal[]        = INCGFX_U16("graphics/intro_pt/looker.png", ".gbapal");
static const u32 sPtLooker_Gfx[]        = INCGFX_U32("graphics/intro_pt/looker.png", ".4bpp.smol");

static const u16 sPtCharon_Pal[]        = INCGFX_U16("graphics/intro_pt/charon.png", ".gbapal");
static const u32 sPtCharon_Gfx[]        = INCGFX_U32("graphics/intro_pt/charon.png", ".4bpp.smol");

static u16 sPtMode4XLut[DISPLAY_WIDTH];

static void SpriteCB_PtCharSlide(struct Sprite *sprite);
static void Task_Scene5_Pt_Load(u8 taskId);
static void Task_Scene5_Pt(u8 taskId);

static const struct OamData sOamData_PtChar64x64 =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_PtCharTop[]    = { ANIMCMD_FRAME( 0, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtCharBottom[] = { ANIMCMD_FRAME(64, 8), ANIMCMD_END };
static const union AnimCmd *const sAnims_PtChar[] = { sAnim_PtCharTop, sAnim_PtCharBottom };

static const struct SpriteTemplate sSpriteTemplate_PtLooker =
{
    .tileTag = TAG_PT_LOOKER,
    .paletteTag = TAG_PT_LOOKER,
    .oam = &sOamData_PtChar64x64,
    .anims = sAnims_PtChar,
    .callback = SpriteCB_PtCharSlide,
};

static const struct SpriteTemplate sSpriteTemplate_PtRunner =
{
    .tileTag = TAG_PT_RUNNER,
    .paletteTag = TAG_PT_RUNNER,
    .oam = &sOamData_PtChar64x64,
    .anims = sAnims_PtRunner,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_PtRunnerDawn =
{
    .tileTag = TAG_PT_RUNNER_DAWN,
    .paletteTag = TAG_PT_RUNNER_DAWN,
    .oam = &sOamData_PtChar64x64,
    .anims = sAnims_PtRunner,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_PtCharon =
{
    .tileTag = TAG_PT_CHARON,
    .paletteTag = TAG_PT_CHARON,
    .oam = &sOamData_PtChar64x64,
    .anims = sAnims_PtChar,
    .callback = SpriteCB_PtCharSlide,
};

static const struct CompressedSpriteSheet sPtScene5_SpriteSheets[] =
{
    { sPtLooker_Gfx, 0x1000, TAG_PT_LOOKER },
    { sPtCharon_Gfx, 0x1000, TAG_PT_CHARON },
};


static const struct OamData sOamData_PtS7Char64x64 =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x64),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x64),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const struct OamData sOamData_PtS7Ball =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_DOUBLE,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(32x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(32x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_PtS7ThrowL[] = { ANIMCMD_FRAME( 0, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtS7ThrowR[] = { ANIMCMD_FRAME(64, 8), ANIMCMD_END };
static const union AnimCmd *const sAnims_PtS7Throw[] = { sAnim_PtS7ThrowL, sAnim_PtS7ThrowR };

static const union AnimCmd sAnim_PtS7Single[] = { ANIMCMD_FRAME(0, 8), ANIMCMD_END };
static const union AnimCmd *const sAnims_PtS7Single[] = { sAnim_PtS7Single };

static const struct SpriteTemplate sSpriteTemplate_PtS7LucasThrow = {
    .tileTag = TAG_PT_S7_LUCAS_THROW,
    .paletteTag = TAG_PT_S7_LUCAS_THROW,
    .oam = &sOamData_PtS7Char64x64,
    .anims = sAnims_PtS7Throw,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteTemplate sSpriteTemplate_PtS7DawnThrow  = {
    .tileTag = TAG_PT_S7_DAWN_THROW,
    .paletteTag = TAG_PT_S7_DAWN_THROW,
    .oam = &sOamData_PtS7Char64x64,
    .anims = sAnims_PtS7Throw,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteTemplate sSpriteTemplate_PtS7LucasHP    = {
    .tileTag = TAG_PT_S7_LUCAS_HP,
    .paletteTag = TAG_PT_S7_LUCAS_HP,
    .oam = &sOamData_PtS7Char64x64,
    .anims = sAnims_PtS7Single,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteTemplate sSpriteTemplate_PtS7DawnHP     = {
    .tileTag = TAG_PT_S7_DAWN_HP,
    .paletteTag = TAG_PT_S7_DAWN_HP,
    .oam = &sOamData_PtS7Char64x64,
    .anims = sAnims_PtS7Single,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};
static const struct SpriteTemplate sSpriteTemplate_PtS7LucasHand  = {
    .tileTag = TAG_PT_S7_LUCAS_HAND,
    .paletteTag = TAG_PT_S7_LUCAS_HAND,
    .oam = &sOamData_PtS7Char64x64,
    .anims = sAnims_PtS7Single,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PtS7HandZip,
};
static const struct SpriteTemplate sSpriteTemplate_PtS7DawnHand   = {
    .tileTag = TAG_PT_S7_DAWN_HAND,
    .paletteTag = TAG_PT_S7_DAWN_HAND,
    .oam = &sOamData_PtS7Char64x64,
    .anims = sAnims_PtS7Single,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PtS7HandZip,
};
static const struct SpriteTemplate sSpriteTemplate_PtS7Ball       = {
    .tileTag = TAG_PT_S7_POKEBALL,
    .paletteTag = TAG_PT_S7_POKEBALL,
    .oam = &sOamData_PtS7Ball,
    .anims = sAnims_PtS7Single,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PtS7SpinBall,
};

static const struct CompressedSpriteSheet sPtS7_SpriteSheets[] =
{
    { sPtS7LucasThrow_Gfx, 0x1000, TAG_PT_S7_LUCAS_THROW },
    { sPtS7DawnThrow_Gfx,  0x1000, TAG_PT_S7_DAWN_THROW },
    { sPtS7LucasHP_Gfx,    0x800,  TAG_PT_S7_LUCAS_HP },
    { sPtS7DawnHP_Gfx,     0x800,  TAG_PT_S7_DAWN_HP },
    { sPtS7LucasHand_Gfx,  0x800,  TAG_PT_S7_LUCAS_HAND },
    { sPtS7DawnHand_Gfx,   0x800,  TAG_PT_S7_DAWN_HAND },
    { sPtS7Ball_Gfx,       0x200,  TAG_PT_S7_POKEBALL },
    {}
};

static const struct SpritePalette sPtS7_SpritePals[] =
{
    { sPtS7LucasThrow_Pal, TAG_PT_S7_LUCAS_THROW },
    { sPtS7DawnThrow_Pal,  TAG_PT_S7_DAWN_THROW },
    { sPtS7LucasHP_Pal,    TAG_PT_S7_LUCAS_HP },
    { sPtS7DawnHP_Pal,     TAG_PT_S7_DAWN_HP },
    { sPtS7LucasHand_Pal,  TAG_PT_S7_LUCAS_HAND },
    { sPtS7DawnHand_Pal,   TAG_PT_S7_DAWN_HAND },
    { sPtS7Ball_Pal,       TAG_PT_S7_POKEBALL },
    {}
};


static const struct OamData sOamData_PtS8Char64x32 =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 1,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_PtS8_TL[] = { ANIMCMD_FRAME(  0, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtS8_TR[] = { ANIMCMD_FRAME( 64, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtS8_BL[] = { ANIMCMD_FRAME(128, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtS8_BR[] = { ANIMCMD_FRAME(160, 8), ANIMCMD_END };

static const union AnimCmd *const sAnims_PtS8_Top[] = { sAnim_PtS8_TL, sAnim_PtS8_TR };
static const union AnimCmd *const sAnims_PtS8_Bot[] = { sAnim_PtS8_BL, sAnim_PtS8_BR };

static const struct SpriteTemplate sSpriteTemplate_PtS8TorterraTop  = {
    .tileTag = TAG_PT_S8_TORTERRA,
    .paletteTag = TAG_PT_S8_TORTERRA,
    .oam = &sOamData_PtS7Char64x64,
    .anims = sAnims_PtS8_Top,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PtS8Slide,
};
static const struct SpriteTemplate sSpriteTemplate_PtS8TorterraBot  = {
    .tileTag = TAG_PT_S8_TORTERRA,
    .paletteTag = TAG_PT_S8_TORTERRA,
    .oam = &sOamData_PtS8Char64x32,
    .anims = sAnims_PtS8_Bot,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PtS8Slide,
};
static const struct SpriteTemplate sSpriteTemplate_PtS8PrinplupTop  = {
    .tileTag = TAG_PT_S8_PRINPLUP,
    .paletteTag = TAG_PT_S8_PRINPLUP,
    .oam = &sOamData_PtS7Char64x64,
    .anims = sAnims_PtS8_Top,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PtS8Slide,
};
static const struct SpriteTemplate sSpriteTemplate_PtS8ChimcharTop  = {
    .tileTag = TAG_PT_S8_CHIMCHAR,
    .paletteTag = TAG_PT_S8_CHIMCHAR,
    .oam = &sOamData_PtS7Char64x64,
    .anims = sAnims_PtS8_Top,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PtS8Slide,
};
static const struct SpriteTemplate sSpriteTemplate_PtS8ChimcharBot  = {
    .tileTag = TAG_PT_S8_CHIMCHAR,
    .paletteTag = TAG_PT_S8_CHIMCHAR,
    .oam = &sOamData_PtS8Char64x32,
    .anims = sAnims_PtS8_Bot,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PtS8Slide,
};
static const struct SpriteTemplate sSpriteTemplate_PtS8InfernapeTop = {
    .tileTag = TAG_PT_S8_INFERNAPE,
    .paletteTag = TAG_PT_S8_INFERNAPE,
    .oam = &sOamData_PtS7Char64x64,
    .anims = sAnims_PtS8_Top,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PtS8Slide,
};
static const struct SpriteTemplate sSpriteTemplate_PtS8InfernapeBot = {
    .tileTag = TAG_PT_S8_INFERNAPE,
    .paletteTag = TAG_PT_S8_INFERNAPE,
    .oam = &sOamData_PtS8Char64x32,
    .anims = sAnims_PtS8_Bot,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PtS8Slide,
};
static const struct SpriteTemplate sSpriteTemplate_PtS8GrotleTop    = {
    .tileTag = TAG_PT_S8_GROTLE,
    .paletteTag = TAG_PT_S8_GROTLE,
    .oam = &sOamData_PtS7Char64x64,
    .anims = sAnims_PtS8_Top,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PtS8Slide,
};
static const struct SpriteTemplate sSpriteTemplate_PtS8PiplupTop    = {
    .tileTag = TAG_PT_S8_PIPLUP,
    .paletteTag = TAG_PT_S8_PIPLUP,
    .oam = &sOamData_PtS7Char64x64,
    .anims = sAnims_PtS8_Top,
    .images = NULL,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCB_PtS8Slide,
};

static const struct CompressedSpriteSheet sPtS8_SpriteSheets[] =
{
    { sPtS8Torterra_Gfx,  0x1800, TAG_PT_S8_TORTERRA },
    { sPtS8Prinplup_Gfx,  0x1000, TAG_PT_S8_PRINPLUP },
    { sPtS8Chimchar_Gfx,  0x1800, TAG_PT_S8_CHIMCHAR },
    { sPtS8Infernape_Gfx, 0x1800, TAG_PT_S8_INFERNAPE },
    { sPtS8Grotle_Gfx,    0x1000, TAG_PT_S8_GROTLE },
    { sPtS8Piplup_Gfx,    0x1000, TAG_PT_S8_PIPLUP },
    {}
};

static const struct SpritePalette sPtS8_SpritePals[] =
{
    { sPtS8Torterra_Pal,  TAG_PT_S8_TORTERRA },
    { sPtS8Prinplup_Pal,  TAG_PT_S8_PRINPLUP },
    { sPtS8Chimchar_Pal,  TAG_PT_S8_CHIMCHAR },
    { sPtS8Infernape_Pal, TAG_PT_S8_INFERNAPE },
    { sPtS8Grotle_Pal,    TAG_PT_S8_GROTLE },
    { sPtS8Piplup_Pal,    TAG_PT_S8_PIPLUP },
    {}
};


static const union AnimCmd sAnim_PtS10_EyeL[]   = { ANIMCMD_FRAME( 0, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtS10_EyeR[]   = { ANIMCMD_FRAME(32, 8), ANIMCMD_END };
static const union AnimCmd *const sAnims_PtS10_Eye[] = { sAnim_PtS10_EyeL, sAnim_PtS10_EyeR };

static const union AnimCmd sAnim_PtS10_MouthL[] = { ANIMCMD_FRAME( 0, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtS10_MouthR[] = { ANIMCMD_FRAME(64, 8), ANIMCMD_END };
static const union AnimCmd *const sAnims_PtS10_Mouth[] = { sAnim_PtS10_MouthL, sAnim_PtS10_MouthR };

static const struct SpriteTemplate sSpriteTemplate_PtS10Eye =
{
    .tileTag = TAG_PT_S10_EYE0,
    .paletteTag = TAG_PT_S10_EYE0,
    .oam = &sOamData_PtS8Char64x32,
    .anims = sAnims_PtS10_Eye,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct SpriteTemplate sSpriteTemplate_PtS10Mouth =
{
    .tileTag = TAG_PT_S10_MOUTH0,
    .paletteTag = TAG_PT_S10_MOUTH0,
    .oam = &sOamData_PtS8Char64x32,
    .anims = sAnims_PtS10_Mouth,
    .affineAnims = gDummySpriteAffineAnimTable,
    .callback = SpriteCallbackDummy,
};

static const struct CompressedSpriteSheet sPtS10_SpriteSheets[] =
{
    { sPtS10Eye0_Gfx,   0x400, TAG_PT_S10_EYE0 },
    { sPtS10Eye1_Gfx,   0x400, TAG_PT_S10_EYE1 },
    { sPtS10Eye2_Gfx,   0x400, TAG_PT_S10_EYE2 },
    { sPtS10Eye3_Gfx,   0x400, TAG_PT_S10_EYE3 },
    { sPtS10Mouth0_Gfx, 0x400, TAG_PT_S10_MOUTH0 },
    { sPtS10Mouth1_Gfx, 0x400, TAG_PT_S10_MOUTH1 },
    { sPtS10Mouth2_Gfx, 0x400, TAG_PT_S10_MOUTH2 },
    { sPtS10Mouth3_Gfx, 0x400, TAG_PT_S10_MOUTH3 },
    {}
};

static const struct SpritePalette sPtS10_SpritePals[] =
{
    { sPtS10Eye0_Pal,   TAG_PT_S10_EYE0 },
    { sPtS10Mouth0_Pal, TAG_PT_S10_MOUTH0 },
    {}
};

static const u16 *const sPtS10EyePals[4]   = { sPtS10Eye0_Pal,   sPtS10Eye1_Pal,   sPtS10Eye2_Pal,   sPtS10Eye3_Pal };
static const u16 *const sPtS10MouthPals[4] = { sPtS10Mouth0_Pal, sPtS10Mouth1_Pal, sPtS10Mouth2_Pal, sPtS10Mouth3_Pal };

static const struct SpritePalette sPtScene5_SpritePals[] =
{
    { sPtLooker_Pal, TAG_PT_LOOKER },
    { sPtCharon_Pal, TAG_PT_CHARON },
    {}
};

static const u16 sPtEternaForest_Pal[]      = INCGFX_U16("graphics/intro_pt/eterna_forest.png", ".gbapal");
static const u32 sPtEternaForest_Gfx[]      = INCGFX_U32("graphics/intro_pt/eterna_forest.png", ".4bpp.smol");
static const u32 sPtEternaForest_Tilemap[]  = INCGFX_U32("graphics/intro_pt/eterna_forest.bin", ".smolTM");

static void Task_Scene4_Pt_Load(u8 taskId);
static void Task_Scene4_Pt(u8 taskId);

static void Task_Scene3_Pt_Load(u8 taskId);
static void Task_Scene3_Pt(u8 taskId);

static const u16 sPtBallFx_Pal[]        = INCGFX_U16("graphics/intro_pt/ball_effects.png", ".gbapal");
static const u32 sPtBallFx_Gfx[]        = INCGFX_U32("graphics/intro_pt/ball_effects.png", ".4bpp.smol");

static void SpriteCB_PtBallFx(struct Sprite *sprite);
static void Task_Scene2_Pt_Load(u8 taskId);
static void Task_Scene2_Pt(u8 taskId);

static const struct OamData sOamData_PtBallFx =
{
    .y = DISPLAY_HEIGHT,
    .affineMode = ST_OAM_AFFINE_OFF,
    .objMode = ST_OAM_OBJ_NORMAL,
    .mosaic = FALSE,
    .bpp = ST_OAM_4BPP,
    .shape = SPRITE_SHAPE(64x32),
    .x = 0,
    .matrixNum = 0,
    .size = SPRITE_SIZE(64x32),
    .tileNum = 0,
    .priority = 0,
    .paletteNum = 0,
    .affineParam = 0,
};

static const union AnimCmd sAnim_PtBallFx_0[]  = { ANIMCMD_FRAME( 0 * 32, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtBallFx_1[]  = { ANIMCMD_FRAME( 1 * 32, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtBallFx_2[]  = { ANIMCMD_FRAME( 2 * 32, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtBallFx_3[]  = { ANIMCMD_FRAME( 3 * 32, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtBallFx_4[]  = { ANIMCMD_FRAME( 4 * 32, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtBallFx_5[]  = { ANIMCMD_FRAME( 5 * 32, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtBallFx_6[]  = { ANIMCMD_FRAME( 6 * 32, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtBallFx_7[]  = { ANIMCMD_FRAME( 7 * 32, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtBallFx_8[]  = { ANIMCMD_FRAME( 8 * 32, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtBallFx_9[]  = { ANIMCMD_FRAME( 9 * 32, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtBallFx_10[] = { ANIMCMD_FRAME(10 * 32, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtBallFx_11[] = { ANIMCMD_FRAME(11 * 32, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtBallFx_12[] = { ANIMCMD_FRAME(12 * 32, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtBallFx_13[] = { ANIMCMD_FRAME(13 * 32, 8), ANIMCMD_END };
static const union AnimCmd sAnim_PtBallFx_14[] = { ANIMCMD_FRAME(14 * 32, 8), ANIMCMD_END };

static const union AnimCmd *const sAnims_PtBallFx[] =
{
    sAnim_PtBallFx_0,
    sAnim_PtBallFx_1,
    sAnim_PtBallFx_2,
    sAnim_PtBallFx_3,
    sAnim_PtBallFx_4,
    sAnim_PtBallFx_5,
    sAnim_PtBallFx_6,
    sAnim_PtBallFx_7,
    sAnim_PtBallFx_8,
    sAnim_PtBallFx_9,
    sAnim_PtBallFx_10,
    sAnim_PtBallFx_11,
    sAnim_PtBallFx_12,
    sAnim_PtBallFx_13,
    sAnim_PtBallFx_14,
};

static const struct SpriteTemplate sSpriteTemplate_PtBallFx =
{
    .tileTag = TAG_PT_BALL_FX,
    .paletteTag = TAG_PT_BALL_FX,
    .oam = &sOamData_PtBallFx,
    .anims = sAnims_PtBallFx,
    .callback = SpriteCB_PtBallFx,
};

static const struct CompressedSpriteSheet sPtBallFx_SpriteSheet =
{
    sPtBallFx_Gfx, 0x3C00, TAG_PT_BALL_FX
};

static const struct SpritePalette sPtBallFx_SpritePal =
{
    sPtBallFx_Pal, TAG_PT_BALL_FX
};

static void VBlankCB_Intro(void)
{
    LoadOam();
    ProcessSpriteCopyRequests();
    TransferPlttBuffer();
    ScanlineEffect_InitHBlankDmaTransfer();
}

void MainCB2_Intro(void)
{
    RunTasks();
    AnimateSprites();
    BuildOamBuffer();
    UpdatePaletteFade();
    if (gMain.newKeys != 0 && !gPaletteFade.active)
    {
        gIntroSkipped = TRUE;
        SetMainCallback2(MainCB2_EndIntro);
    }
    else if (gIntroFrameCounter != -1)
        gIntroFrameCounter++;
}

static void FreePtScene6DawnBuffer(void)
{
    u8 taskId;

    // Scene 6 normally frees this at the halfway swap; skipping the intro bypasses that code.
    for (taskId = 0; taskId < NUM_TASKS; taskId++)
    {
        if (gTasks[taskId].isActive && gTasks[taskId].func == Task_Scene6_Pt)
        {
            u8 *dawnBuf = (u8 *)GetWordTaskArg(taskId, 6);

            if (dawnBuf != NULL)
            {
                Free(dawnBuf);
                SetWordTaskArg(taskId, 6, 0);
            }
            break;
        }
    }
}

static void MainCB2_EndIntro(void)
{
    FreePtScene6DawnBuffer();
    if (!UpdatePaletteFade())
        SetMainCallback2(CB2_InitTitleScreen);
}

static void SerialCB_CopyrightScreen(void)
{
    GameCubeMultiBoot_HandleSerialInterrupt(&gMultibootProgramStruct);
}

static u8 SetUpCopyrightScreen(void)
{
    if (IS_FRLG)
        return SetUpCopyrightScreenFrlg();

    switch (gMain.state)
    {
    case COPYRIGHT_INITIALIZE:
        SetVBlankCallback(NULL);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        SetGpuReg(REG_OFFSET_BLDY, 0);
        SetGpuReg(REG_OFFSET_DISPCNT, 0);
        SetGpuReg(REG_OFFSET_BG0HOFS, 0);
        SetGpuReg(REG_OFFSET_BG0VOFS, 0);
        SetGpuReg(REG_OFFSET_BG3HOFS, 0);
        SetGpuReg(REG_OFFSET_BG3VOFS, 0);
        CpuFill32(0, (void *)VRAM, VRAM_SIZE);
        CpuFill32(0, (void *)OAM, OAM_SIZE);
        CpuFill16(0, (void *)PLTT, PLTT_SIZE);
        ResetPaletteFade();

        // Load transparent-background copyright onto BG0 and Scene 1 BG onto BG3
        DecompressDataWithHeaderVram(sPtCopyright_Gfx, (void *)BG_CHAR_ADDR(0));
        DecompressDataWithHeaderVram(sPtCopyright_Tilemap, (void *)BG_SCREEN_ADDR(28));
        LoadPalette(sPtCopyright_Pal, BG_PLTT_ID(0), PLTT_SIZE_4BPP);

        DecompressDataWithHeaderVram(sPtScene1Bg_Gfx, (void *)BG_CHAR_ADDR(2));
        DecompressDataWithHeaderVram(sPtScene1Bg_Tilemap, (void *)BG_SCREEN_ADDR(30));
        LoadPalette(sPtScene1Bg_Pal, BG_PLTT_ID(2), PLTT_SIZE_4BPP);

        ScanlineEffect_Stop();
        ResetTasks();
        ResetSpriteData();
        FreeAllSpritePalettes();
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0)
                                   | BGCNT_CHARBASE(0)
                                   | BGCNT_SCREENBASE(28)
                                   | BGCNT_16COLOR
                                   | BGCNT_TXT256x256);
        SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3)
                                   | BGCNT_CHARBASE(2)
                                   | BGCNT_SCREENBASE(30)
                                   | BGCNT_16COLOR
                                   | BGCNT_TXT256x256);
        EnableInterrupts(INTR_FLAG_VBLANK);
        SetVBlankCallback(VBlankCB_Intro);
        REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON;
        m4aSongNumStart(MUS_PL_INTRO);
        SetSerialCallback(SerialCB_CopyrightScreen);
        GameCubeMultiBoot_Init(&gMultibootProgramStruct);
    case COPYRIGHT_EMULATOR_BLEND:
        // Older VBA and John GBA Lite versions require this second DISPCNT write
        // for the intro to render correctly.
        REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG0_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON;
    default:
        UpdatePaletteFade();
        gMain.state++;
        GameCubeMultiBoot_Main(&gMultibootProgramStruct);
        break;
    case COPYRIGHT_START_FADE:
        GameCubeMultiBoot_Main(&gMultibootProgramStruct);
        if (gMultibootProgramStruct.gcmb_field_2 != 1)
        {
            // Blend only BG0 out so BG3 (Scene 1 BG) stays unchanged
            sPtCopyrightAlpha = 16;
            sPtCopyrightAlphaDelay = 0;
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_BD);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
            gMain.state = COPYRIGHT_FADE_OUT;
        }
        break;
    case COPYRIGHT_FADE_OUT:
        if (++sPtCopyrightAlphaDelay & 1)
        {
            if (sPtCopyrightAlpha > 0)
            {
                sPtCopyrightAlpha--;
                SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(sPtCopyrightAlpha, 16 - sPtCopyrightAlpha));
            }
        }
        if (sPtCopyrightAlpha == 0)
        {
            REG_DISPCNT = DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG3_ON | DISPCNT_OBJ_ON;
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            gMain.state = COPYRIGHT_START_INTRO;
        }
        break;
    case COPYRIGHT_START_INTRO:
#if EXPANSION_INTRO == TRUE
        SetMainCallback2(CB2_ExpansionIntro);
        CreateTask(Task_HandleExpansionIntro, 0);
#else
        CreateTask(Task_Scene1_Load, 0);
        SetMainCallback2(MainCB2_Intro);
#endif
        if (gMultibootProgramStruct.gcmb_field_2 != 0)
        {
            if (gMultibootProgramStruct.gcmb_field_2 == 2)
            {
                // check the multiboot ROM header game code to see if we already did this
                if (*(u32 *)(EWRAM_START + 0xAC) == COLOSSEUM_GAME_CODE)
                {
                    CpuCopy16(&gMultiBootProgram_PokemonColosseum_Start, (void *)EWRAM_START, sizeof(gMultiBootProgram_PokemonColosseum_Start));
                    *(u32 *)(EWRAM_START + 0xAC) = COLOSSEUM_GAME_CODE;
                }
                GameCubeMultiBoot_ExecuteProgram(&gMultibootProgramStruct);
            }
        }
        else
        {
            GameCubeMultiBoot_Quit();
            SetSerialCallback(SerialCB);
        }
        return 0;
    }

    return 1;
}

void CB2_InitCopyrightScreenAfterBootup(void)
{
    if (!SetUpCopyrightScreen())
    {
        SetSaveBlocksPointers(GetSaveBlocksPointersBaseOffset());
        ResetMenuAndMonGlobals();
        Save_ResetSaveCounters();
        LoadGameSave(SAVE_NORMAL);
       if (gSaveFileStatus == SAVE_STATUS_OUTDATED)
       {
           if (UpdateSaveFile())
               gSaveFileStatus = SAVE_STATUS_UPDATED;
       }
        if (gSaveFileStatus == SAVE_STATUS_EMPTY || gSaveFileStatus == SAVE_STATUS_CORRUPT)
            Sav2_ClearSetDefault();
        SetPokemonCryStereo(gSaveBlock2Ptr->optionsSound);
        InitHeap(gHeap, HEAP_SIZE);
    }
}

void CB2_InitCopyrightScreenAfterTitleScreen(void)
{
    SetUpCopyrightScreen();
}

#define sBigDropSpriteId data[0]

static const u8 sPtStarSpawnX[] = { 48, 188, 96, 152, 28, 212, 72, 172, 120, 40, 196, 136 };

#define PT_STAR_SPAWN_INTERVAL  14
#define PT_STAR_TOTAL_COUNT     24

// data[0]: vertical fall speed (pixels per frame)
// data[1]: horizontal drift counter
// data[4]: affine scale pulse phase (used by alternating stars)
static void SpriteCB_PtStar(struct Sprite *sprite)
{
    sprite->y += sprite->data[0];
    sprite->data[1]++;
    if ((sprite->data[1] & 7) == 0)
        sprite->x += (sprite->data[1] & 8) ? 1 : -1;

    if (sprite->oam.affineMode != ST_OAM_AFFINE_OFF)
    {
        s16 scale;
        sprite->data[4] = (sprite->data[4] + 4) & 0xFF;
        // GBA affine scaling is reciprocal: 256 is normal size, and
        // larger values shrink the sprite. This range (256-448) never
        // enlarges the star beyond its original size.
        scale = 352 + Cos((u8)sprite->data[4], 96);

        SetOamMatrix(sprite->oam.matrixNum, scale, 0, 0, scale);
    }

    if (sprite->y > DISPLAY_HEIGHT + 32)
    {
        if (sprite->oam.affineMode != ST_OAM_AFFINE_OFF)
            FreeOamMatrix(sprite->oam.matrixNum);
        DestroySprite(sprite);
    }
}

static void SpawnPtStar(u8 index)
{
    u8 x = sPtStarSpawnX[index % ARRAY_COUNT(sPtStarSpawnX)];
    u8 spriteId = CreateSprite(&sSpriteTemplate_PtStar, x, -16, 0);
    if (spriteId != MAX_SPRITES)
    {
        StartSpriteAnim(&gSprites[spriteId], index % ARRAY_COUNT(sAnims_PtStars));
        gSprites[spriteId].data[0] = 2 + (index & 1);
        gSprites[spriteId].data[1] = index * 3;

        // Apply affine scaling to alternating stars for a size pulse.
        if (index & 1)
        {
            s8 matrixNum = AllocOamMatrix();
            if (matrixNum >= 0)
            {
                gSprites[spriteId].oam.affineMode = ST_OAM_AFFINE_DOUBLE;
                gSprites[spriteId].oam.matrixNum = matrixNum;
                CalcCenterToCornerVec(&gSprites[spriteId], SPRITE_SHAPE(32x32), SPRITE_SIZE(32x32), ST_OAM_AFFINE_DOUBLE);

                gSprites[spriteId].data[4] = (index * 31) & 0xFF;
            }
        }
    }
}

void Task_Scene1_Load(u8 taskId)
{
    sIntroCharacterGender = MOD(Random(), GENDER_COUNT);
    gIntroFrameCounter = 0;
    gIntroSkipped = FALSE;

    // BG3 carries over from the copyright screen, set up BG1 for the GF logo
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1)
                               | BGCNT_CHARBASE(1)
                               | BGCNT_SCREENBASE(29)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);

    DecompressDataWithHeaderVram(sPtGfLogo_Gfx, (void *)BG_CHAR_ADDR(1));
    DecompressDataWithHeaderVram(sPtGfLogo_Tilemap, (void *)BG_SCREEN_ADDR(29));
    LoadPalette(sPtGfLogo_Pal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);

    LoadCompressedSpriteSheet(&sPtStars_SpriteSheet);
    LoadSpritePalette(&sPtStars_SpritePal);

    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_BD);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG1_ON | DISPCNT_BG3_ON | DISPCNT_OBJ_ON);

    gTasks[taskId].data[0] = 0; // state
    gTasks[taskId].data[1] = 0; // timer
    gTasks[taskId].data[2] = 0; // alpha
    gTasks[taskId].data[3] = 0; // stars spawned
    gTasks[taskId].func = Task_Scene1_Pt;
}

#define tPtState    data[0]
#define tPtTimer    data[1]
#define tPtAlpha    data[2]
#define tPtStars    data[3]

static void Task_Scene1_Pt(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    // Spawn falling stars once the logo appears and during the transition to Presents
    if (tPtState >= 1 && tPtState <= 4 && tPtStars < PT_STAR_TOTAL_COUNT)
    {
        if ((gIntroFrameCounter % PT_STAR_SPAWN_INTERVAL) == 0)
        {
            SpawnPtStar(tPtStars);
            tPtStars++;
        }
    }

    switch (tPtState)
    {
    case 0: // Fade in Game Freak logo over BG3 (48 frames)
        if (++tPtTimer >= 3)
        {
            tPtTimer = 0;
            tPtAlpha++;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(tPtAlpha, 16 - tPtAlpha));
            if (tPtAlpha >= 16)
            {
                SetGpuReg(REG_OFFSET_BLDCNT, 0);
                SetGpuReg(REG_OFFSET_BLDALPHA, 0);
                tPtState = 1;
            }
        }
        break;
    case 1: // Hold logo while stars fall
        if (++tPtTimer >= 220)
        {
            tPtTimer = 0;
            tPtAlpha = 16;
            SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_BD);
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(16, 0));
            tPtState = 2;
        }
        break;
    case 2: // Fade out Game Freak logo (48 frames)
        if (++tPtTimer >= 3)
        {
            tPtTimer = 0;
            tPtAlpha--;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(tPtAlpha, 16 - tPtAlpha));
            if (tPtAlpha <= 0)
            {
                DecompressDataWithHeaderVram(sPtGfPresents_Gfx, (void *)BG_CHAR_ADDR(1));
                DecompressDataWithHeaderVram(sPtGfPresents_Tilemap, (void *)BG_SCREEN_ADDR(29));
                LoadPalette(sPtGfPresents_Pal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
                tPtState = 3;
            }
        }
        break;
    case 3: // Fade in Game Freak Presents over BG3 (48 frames)
        if (++tPtTimer >= 3)
        {
            tPtTimer = 0;
            tPtAlpha++;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(tPtAlpha, 16 - tPtAlpha));
            if (tPtAlpha >= 16)
            {
                SetGpuReg(REG_OFFSET_BLDCNT, 0);
                SetGpuReg(REG_OFFSET_BLDALPHA, 0);
                tPtState = 4;
            }
        }
        break;
    case 4: // Hold Game Freak Presents until the scene ends
        if (++tPtTimer >= 305)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 1, 0, 16, RGB_BLACK);
            tPtState = 5;
        }
        break;
    case 5: // Fade out and transition to Scene 2
        if (!gPaletteFade.active)
        {
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_OBJ_ON);
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);
            ResetSpriteData();
            FreeAllSpritePalettes();
            gTasks[taskId].data[0] = 0;
            gTasks[taskId].data[1] = 0;
            gTasks[taskId].func = Task_Scene2_Pt_Load;
        }
        break;
    }
}

#undef tPtState
#undef tPtTimer
#undef tPtAlpha
#undef tPtStars


#define PT_S2_BLACK_HOLD_FRAMES     270 // ~4.5s (restored so Scene 8 stays at 1m 06s)
#define PT_S2_LOGO_HOLD_FRAMES      180 // 3.0s
#define PT_S2_BALL_PHASE1_FRAMES    120 // 2.0s
#define PT_S2_BALL_PHASE2_FRAMES     90 // 1.5s
#define PT_S2_POST_FLASH_RAMP       240 // 4.0s after white flash
#define PT_S2_POST_FLASH_TAPER_END  280 // End the low-density effect phase
#define PT_S2_POST_FLASH_END        288 // 4.8s after the flash; Scene 3 starts at 32.5s

static void SpriteCB_PtBallFx(struct Sprite *sprite)
{
    sprite->x += sprite->data[0];
    if (sprite->x > DISPLAY_WIDTH + 48)
        DestroySprite(sprite);
}

static void SpawnPtBallFx(u8 speed)
{
    u8 y = Random() % (DISPLAY_HEIGHT - 24);
    u8 spriteId = CreateSprite(&sSpriteTemplate_PtBallFx, -48, y, 0);
    if (spriteId != MAX_SPRITES)
    {
        StartSpriteAnim(&gSprites[spriteId], Random() % ARRAY_COUNT(sAnims_PtBallFx));
        gSprites[spriteId].data[0] = speed;
    }
}

static void Task_Scene2_Pt_Load(u8 taskId)
{
    if (gTasks[taskId].data[0] == 0)
    {
        CpuFill16(RGB_BLACK, gPlttBufferUnfaded, PLTT_SIZE);
        CpuFill16(RGB_BLACK, gPlttBufferFaded, PLTT_SIZE);

        SetGpuReg(REG_OFFSET_BG1HOFS, 0);
        SetGpuReg(REG_OFFSET_BG1VOFS, 0);
        SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1)
                                   | BGCNT_CHARBASE(1)
                                   | BGCNT_SCREENBASE(29)
                                   | BGCNT_16COLOR
                                   | BGCNT_TXT256x256);

        DecompressDataWithHeaderVram(sPtLogoInv_Gfx, (void *)BG_CHAR_ADDR(1));
        DecompressDataWithHeaderVram(sPtLogoInv_Tilemap, (void *)BG_SCREEN_ADDR(29));
        LoadPalette(sPtLogoInv_Pal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);

        LoadCompressedSpriteSheet(&sPtBallFx_SpriteSheet);
        LoadSpritePalette(&sPtBallFx_SpritePal);
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);

        gTasks[taskId].data[0] = 1;
        gTasks[taskId].data[1] = 0;
    }

    // Stay black for ~4.5 seconds before fading in inverted logo
    if (++gTasks[taskId].data[1] >= PT_S2_BLACK_HOLD_FRAMES)
    {
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG1_ON | DISPCNT_OBJ_ON);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].data[2] = 0;
        gTasks[taskId].func = Task_Scene2_Pt;
    }
}

#define tS2State    data[0]
#define tS2Timer    data[1]
#define tS2FlashClk data[2]

static void Task_Scene2_Pt(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (tS2State)
    {
    case 0: // Wait for inverted logo fade-in
        if (!gPaletteFade.active)
        {
            tS2Timer = 0;
            tS2State = 1;
        }
        break;
    case 1: // Hold inverted logo for 3.0s
        if (++tS2Timer >= PT_S2_LOGO_HOLD_FRAMES)
        {
            tS2Timer = 0;
            tS2State = 2;
        }
        break;
    case 2: // Ball effects slide across the inverted logo
        if ((tS2Timer % 7) == 0)
            SpawnPtBallFx(6 + (Random() & 1));
        if (++tS2Timer >= PT_S2_BALL_PHASE1_FRAMES)
        {
            tS2Timer = 0;
            tS2State = 3;
        }
        break;
    case 3: // Ball effects increase in density and speed
        if ((tS2Timer % 3) == 0)
            SpawnPtBallFx(7 + (Random() % 3));
        if (++tS2Timer >= PT_S2_BALL_PHASE2_FRAMES)
        {
            tS2Timer = 0;
            tS2FlashClk = 0;
            BlendPalettes(PALETTES_ALL, 16, RGB_WHITE);
            tS2State = 4;
        }
        break;
    case 4: // White flash into the normal logo
        tS2FlashClk++;
        if (++tS2Timer >= 2)
        {
            DecompressDataWithHeaderVram(sPtLogo_Gfx, (void *)BG_CHAR_ADDR(1));
            DecompressDataWithHeaderVram(sPtLogo_Tilemap, (void *)BG_SCREEN_ADDR(29));
            LoadPalette(sPtLogo_Pal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
            BlendPalettes(PALETTES_ALL, 16, RGB_WHITE);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_WHITE);
            tS2Timer = 0;
            tS2State = 5;
        }
        break;
    case 5: // High intensity ball effects
        tS2FlashClk++;
        if ((tS2FlashClk % 3) == 0)
        {
            SpawnPtBallFx(9 + (Random() % 4));
            SpawnPtBallFx(9 + (Random() % 4));
        }
        if (tS2FlashClk >= PT_S2_POST_FLASH_RAMP)
            tS2State = 6;
        break;
    case 6: // Taper off before the transition to Route 204
        tS2FlashClk++;
        // Reduce the spawn rate during the final, low-density phase.
        if (tS2FlashClk < PT_S2_POST_FLASH_TAPER_END)
        {
            if ((tS2FlashClk % 14) == 0)
                SpawnPtBallFx(5 + (Random() & 1));
        }

        if (tS2FlashClk >= PT_S2_POST_FLASH_END) // 32.5s after bootup -> Scene 3
        {
            BlendPalettes(PALETTES_ALL, 16, RGB_WHITE);
            tS2State = 7;
        }
        break;
    case 7: // Flash out and move to Scene 3
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        ResetSpriteData();
        FreeAllSpritePalettes();
        gTasks[taskId].data[0] = 0;
        gTasks[taskId].data[1] = 0;
        gTasks[taskId].func = Task_Scene3_Pt_Load;
        break;
    }
}

#undef tS2State
#undef tS2Timer
#undef tS2FlashClk


#define PT_S3_START_VOFS    352 // Bottom of Route 204 (512 - 160)
#define PT_S3_ZOOM_FRAMES    45 // 0.75s fast zoom-in
#define PT_S3_TOTAL_FRAMES  448 // 7.5s (from 32.5s to 40.0s)

static void Task_Scene3_Pt_Load(u8 taskId)
{
    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);

    // Load Route 204 on BG2
    SetGpuReg(REG_OFFSET_BG2HOFS, 8); // Center 240px screen in 256px width
    SetGpuReg(REG_OFFSET_BG2VOFS, PT_S3_START_VOFS);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(24)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x512);

    DecompressDataWithHeaderVram(sPtRoute204_Gfx, (void *)BG_CHAR_ADDR(0));
    DecompressDataWithHeaderVram(sPtRoute204_Tilemap, (void *)BG_SCREEN_ADDR(24));
    LoadPalette(sPtRoute204_Pal, BG_PLTT_ID(2), PLTT_SIZE_4BPP);

    // Initial white flash fade-in with fast zoom-in mosaic
    BlendPalettes(PALETTES_ALL, 16, RGB_WHITE);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_WHITE);

    SetGpuRegBits(REG_OFFSET_BG2CNT, BGCNT_MOSAIC);
    SetGpuReg(REG_OFFSET_MOSAIC, (15 << 0) | (15 << 4)); // Start high mosaic
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_BG2_ON);

    gTasks[taskId].data[0] = 0; // timer
    SetWordTaskArg(taskId, 1, (u32)(PT_S3_START_VOFS << 8));
    gTasks[taskId].func = Task_Scene3_Pt;
}

static void Task_Scene3_Pt(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 timer = data[0]++;

    // Zoom in using mosaic effect
    if (timer < PT_S3_ZOOM_FRAMES)
    {
        u8 m = 15 - (timer * 15 / PT_S3_ZOOM_FRAMES);
        SetGpuReg(REG_OFFSET_MOSAIC, (m << 0) | (m << 4));
        if (timer == PT_S3_ZOOM_FRAMES - 1)
            ClearGpuRegBits(REG_OFFSET_BG2CNT, BGCNT_MOSAIC);
    }
    else
    {
        // Scroll up at a constant rate
        s32 vofs = (s32)GetWordTaskArg(taskId, 1) - ((PT_S3_START_VOFS << 8) / (PT_S3_TOTAL_FRAMES - PT_S3_ZOOM_FRAMES));
        if (vofs < 0)
            vofs = 0;
        SetWordTaskArg(taskId, 1, (u32)vofs);
        SetGpuReg(REG_OFFSET_BG2VOFS, vofs >> 8);
    }

    // Transition to Scene 4 (Eterna Forest) with a white flash
    if (timer >= PT_S3_TOTAL_FRAMES)
    {
        BlendPalettes(PALETTES_ALL, 16, RGB_WHITE);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        ClearGpuRegBits(REG_OFFSET_BG2CNT, BGCNT_MOSAIC);
        data[0] = 0;
        data[1] = 0;
        gTasks[taskId].func = Task_Scene4_Pt_Load;
    }
}


#define PT_S4_SCROLL_DIST    272 // 512 - 240 pixels (full horizontal scroll)
#define PT_S4_TOTAL_FRAMES   418 // 7.0s (from 40.0s to 47.0s)

static void Task_Scene4_Pt_Load(u8 taskId)
{
    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);

    // Load Eterna Forest on BG2 as a 512x256 text background
    SetGpuReg(REG_OFFSET_BG2HOFS, 0); // Start at leftmost edge
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(24)
                               | BGCNT_16COLOR
                               | BGCNT_TXT512x256);

    DecompressDataWithHeaderVram(sPtEternaForest_Gfx, (void *)BG_CHAR_ADDR(0));
    DecompressDataWithHeaderVram(sPtEternaForest_Tilemap, (void *)BG_SCREEN_ADDR(24));
    LoadPalette(sPtEternaForest_Pal, BG_PLTT_ID(2), PLTT_SIZE_4BPP);

    // Fade from white into Eterna Forest
    BlendPalettes(PALETTES_ALL, 16, RGB_WHITE);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_WHITE);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_BG2_ON);

    gTasks[taskId].data[0] = 0; // timer
    SetWordTaskArg(taskId, 1, 0); // 24.8 fixed point HOFS (starts at 0)
    gTasks[taskId].func = Task_Scene4_Pt;
}

static void Task_Scene4_Pt(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 timer = data[0]++;

    // Smooth horizontal scroll from left (HOFS = 0) to rightmost (HOFS = 272)
    // (418 frames to cover 272 pixels = ~0.6507 px/frame)
    s32 hofs = (s32)GetWordTaskArg(taskId, 1) + ((PT_S4_SCROLL_DIST << 8) / PT_S4_TOTAL_FRAMES);
    if (hofs > (PT_S4_SCROLL_DIST << 8))
        hofs = PT_S4_SCROLL_DIST << 8;
    SetWordTaskArg(taskId, 1, (u32)hofs);
    SetGpuReg(REG_OFFSET_BG2HOFS, hofs >> 8);

    // Transition to Scene 5 (Eterna City) with a black flash
    if (timer >= PT_S4_TOTAL_FRAMES)
    {
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP);
        SetGpuReg(REG_OFFSET_BLDCNT, 0);
        SetGpuReg(REG_OFFSET_BLDALPHA, 0);
        data[0] = 0;
        data[1] = 0;
        gTasks[taskId].func = Task_Scene5_Pt_Load;
    }
}


#define PT_S5_TOTAL_FRAMES      412 // +3 load frames = 415 frames (~6.95s: 47.03s -> 53.98s)
#define PT_S5_LOOKER_SPAWN      57  // 48.0s
#define PT_S5_CHARON_SPAWN      131 // 1.0s (60 frames) after Looker stops (57 + 14 + 60)
#define PT_S5_EXIT_START        315 // ~52.3s: slide off + slow fade to white
#define PT_S5_SLIDE_FRAMES      14  // ~0.23s snappy slide-in

#define PT_S5_SRC_W             524
#define PT_S5_SRC_H             256
#define PT_S5_ZOOM_IN           0x0E8 // ~1.10x zoom in
#define PT_S5_ZOOM_OUT          0x168 // 0.71x zoom out
#define PT_S5_START_TEX_X       413
#define PT_S5_END_TEX_X         172
#define PT_S5_CENTER_TEX_Y      128

static void ComputeEternaCityCamera(u16 timer, u16 *outTexX, u16 *outScale)
{
    if (timer <= 250)
        *outTexX = PT_S5_START_TEX_X - ((s32)(PT_S5_START_TEX_X - PT_S5_END_TEX_X) * timer) / 250;
    else
        *outTexX = PT_S5_END_TEX_X;

    if (timer < 150)
        *outScale = PT_S5_ZOOM_IN;
    else if (timer <= 250)
        *outScale = PT_S5_ZOOM_IN + ((s32)(PT_S5_ZOOM_OUT - PT_S5_ZOOM_IN) * (timer - 150)) / (250 - 150);
    else
        *outScale = PT_S5_ZOOM_OUT;
}

__attribute__((target("arm")))
static void RenderEternaCityRows(u8 page, u16 texX, u16 texY, u16 scale, u8 yStart, u8 yEnd, bool8 computeXLut)
{
    u32 *dstBase = (u32 *)(page ? (BG_VRAM + 0xA000) : BG_VRAM);
    s32 startX = ((s32)texX << 8) - (DISPLAY_WIDTH / 2) * (s32)scale;
    s32 startY = ((s32)texY << 8) - (DISPLAY_HEIGHT / 2) * (s32)scale;
    u16 x, y;

    if (computeXLut)
    {
        s32 curX = startX;
        for (x = 0; x < DISPLAY_WIDTH; x++)
        {
            s32 sx = curX >> 8;
            if (sx < 0)
                sx = 0;
            else if (sx >= PT_S5_SRC_W)
                sx = PT_S5_SRC_W - 1;
            sPtMode4XLut[x] = sx;
            curX += scale;
        }
    }

    for (y = yStart; y < yEnd; y++)
    {
        s32 sy = (startY + (s32)y * (s32)scale) >> 8;
        const u8 *srcRow;
        u32 *dstRow;

        if (sy < 0)
            sy = 0;
        else if (sy >= PT_S5_SRC_H)
            sy = PT_S5_SRC_H - 1;

        srcRow = &sPtEternaCity_Bitmap[sy * PT_S5_SRC_W];
        dstRow = &dstBase[y * (DISPLAY_WIDTH / 4)];

        for (x = 0; x < DISPLAY_WIDTH; x += 4)
        {
            u32 p0 = srcRow[sPtMode4XLut[x]];
            u32 p1 = srcRow[sPtMode4XLut[x + 1]];
            u32 p2 = srcRow[sPtMode4XLut[x + 2]];
            u32 p3 = srcRow[sPtMode4XLut[x + 3]];
            *dstRow++ = p0 | (p1 << 8) | (p2 << 16) | (p3 << 24);
        }
    }
}

// data[0]: state (0=entering, 1=idle, 2=exiting)
// data[1]: startX, data[2]: targetX, data[3]: timer, data[4]: exitDir (px/frame)
static void SpriteCB_PtCharSlide(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        s32 t = ++sprite->data[3];
        s32 d = PT_S5_SLIDE_FRAMES;
        if (t >= d)
        {
            sprite->x = sprite->data[2];
            sprite->data[0] = 1;
        }
        else
        {
            s32 rem = d - t;
            s32 delta = sprite->data[2] - sprite->data[1];
            s32 num = (d * d - rem * rem);
            sprite->x = sprite->data[1] + (delta * num) / (d * d);
        }
    }
    else if (sprite->data[0] == 2)
    {
        sprite->x += sprite->data[4];
        if (sprite->x < -48 || sprite->x > DISPLAY_WIDTH + 48)
            DestroySprite(sprite);
    }
}

static void SpawnPtCharacter(const struct SpriteTemplate *tmpl, s16 startX, s16 targetX, s16 topCenterY, s16 exitDir, u8 subpriority, u8 *outTop, u8 *outBot)
{
    u8 idTop = CreateSprite(tmpl, startX, topCenterY, subpriority);
    u8 idBot = CreateSprite(tmpl, startX, topCenterY + 64, subpriority);

    if (idTop != MAX_SPRITES)
    {
        StartSpriteAnim(&gSprites[idTop], 0);
        gSprites[idTop].data[0] = 0;
        gSprites[idTop].data[1] = startX;
        gSprites[idTop].data[2] = targetX;
        gSprites[idTop].data[3] = 0;
        gSprites[idTop].data[4] = exitDir;
    }
    if (idBot != MAX_SPRITES)
    {
        StartSpriteAnim(&gSprites[idBot], 1);
        gSprites[idBot].data[0] = 0;
        gSprites[idBot].data[1] = startX;
        gSprites[idBot].data[2] = targetX;
        gSprites[idBot].data[3] = 0;
        gSprites[idBot].data[4] = exitDir;
    }
    *outTop = idTop;
    *outBot = idBot;
}

static void Task_Scene5_Pt_Load(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    switch (data[0])
    {
    case 0:
        DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
        ResetSpriteData();
        FreeAllSpritePalettes();

        // Reserve tiles 0-511 for Mode 4 so sprite sheets don't overlap
        AllocSpriteTiles(512);
        LoadCompressedSpriteSheet(&sPtScene5_SpriteSheets[0]);
        LoadCompressedSpriteSheet(&sPtScene5_SpriteSheets[1]);
        LoadSpritePalettes(sPtScene5_SpritePals);
        LoadPalette(sPtEternaCity_Pal, BG_PLTT_ID(0), PLTT_SIZE_8BPP);

        RenderEternaCityRows(0, PT_S5_START_TEX_X, PT_S5_CENTER_TEX_Y, PT_S5_ZOOM_IN, 0, 54, TRUE);
        data[0] = 1;
        break;
    case 1:
        RenderEternaCityRows(0, PT_S5_START_TEX_X, PT_S5_CENTER_TEX_Y, PT_S5_ZOOM_IN, 54, 108, FALSE);
        data[0] = 2;
        break;
    case 2:
        RenderEternaCityRows(0, PT_S5_START_TEX_X, PT_S5_CENTER_TEX_Y, PT_S5_ZOOM_IN, 108, DISPLAY_HEIGHT, FALSE);

        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_4 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG2_ON | DISPCNT_OBJ_ON);

        data[0] = 0;           // timer
        data[1] = MAX_SPRITES; // Looker top
        data[2] = MAX_SPRITES; // Looker bottom
        data[3] = MAX_SPRITES; // Charon top
        data[4] = MAX_SPRITES; // Charon bottom
        data[5] = 0;           // exit triggered
        data[6] = 0;           // displayed Mode 4 page (0 or 1)
        data[7] = 0;           // render slice (0, 1, 2)
        data[8] = PT_S5_START_TEX_X;
        data[9] = PT_S5_ZOOM_IN;
        gTasks[taskId].func = Task_Scene5_Pt;
        break;
    }
}

static void Task_Scene5_Pt(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 timer = data[0]++;
    u16 texX, scale;
    u8 top, bot;
    u8 backPage = data[6] ^ 1;

    // Update Mode 4 camera across 3 frames to avoid overrunning VBlank
    if (timer <= 253 || data[7] != 0)
    {
        if (data[7] == 0)
        {
            ComputeEternaCityCamera(timer + 2, &texX, &scale);
            data[8] = texX;
            data[9] = scale;
            RenderEternaCityRows(backPage, texX, PT_S5_CENTER_TEX_Y, scale, 0, 54, TRUE);
            data[7] = 1;
        }
        else if (data[7] == 1)
        {
            RenderEternaCityRows(backPage, data[8], PT_S5_CENTER_TEX_Y, data[9], 54, 108, FALSE);
            data[7] = 2;
        }
        else
        {
            RenderEternaCityRows(backPage, data[8], PT_S5_CENTER_TEX_Y, data[9], 108, DISPLAY_HEIGHT, FALSE);
            data[6] = backPage;
            data[7] = 0;
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_4 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG2_ON | DISPCNT_OBJ_ON | (backPage ? 0x10 : 0));
        }
    }

    // Looker enters from the left
    if (timer == PT_S5_LOOKER_SPAWN)
    {
        SpawnPtCharacter(&sSpriteTemplate_PtLooker, -32, 164, 60, 12, 1, &top, &bot);
        data[1] = top;
        data[2] = bot;
    }

    // Charon enters from the right
    if (timer == PT_S5_CHARON_SPAWN)
    {
        SpawnPtCharacter(&sSpriteTemplate_PtCharon, DISPLAY_WIDTH + 32, 76, 78, -12, 0, &top, &bot);
        data[3] = top;
        data[4] = bot;
    }

    // Slide both characters off-screen and fade to white
    if (timer == PT_S5_EXIT_START && !data[5])
    {
        data[5] = 1;
        for (top = 1; top <= 4; top++)
        {
            if (data[top] != MAX_SPRITES)
                gSprites[data[top]].data[0] = 2;
        }
        BeginNormalPaletteFade(PALETTES_ALL, 4, 0, 16, RGB_WHITE);
    }

    // Transition to Scene 6 (Lucas & Dawn)
    if (timer >= PT_S5_TOTAL_FRAMES && !gPaletteFade.active)
    {
        data[0] = 0;
        gTasks[taskId].func = Task_Scene6_Pt_Load;
    }
}


#define PT_S6_PHASE_FRAMES  240 // 4.0s per character
#define PT_S6_TOTAL_FRAMES  480 // 8.0s total (54.0s to 62.0s)
#define PT_S6_BASE_VOFS      16 // Aligns bottom of 160px scene to top of 16px bottom letterbox bar

// 4bpp graphics sizes: sky 80 tiles (2560 B), buildings 192 tiles (6144 B), trees 96 tiles (3072 B).
#define PT_S6_DAWN_SKY_GFX_SZ   0x0A00
#define PT_S6_DAWN_BLD_GFX_SZ   0x1800
#define PT_S6_DAWN_TREE_GFX_SZ  0x0C00
#define PT_S6_DAWN_MAP_SZ       0x0800
#define PT_S6_DAWN_BUF_SZ       (PT_S6_DAWN_SKY_GFX_SZ + PT_S6_DAWN_BLD_GFX_SZ + PT_S6_DAWN_TREE_GFX_SZ + PT_S6_DAWN_MAP_SZ * 3)

static void Task_Scene6_Pt_Load(u8 taskId)
{
    u8 idLTop, idLBot, idDTop, idDBot;
    u8 *dawnBuf;

    // Disable palette transfer during setup to avoid a 1-frame flash
    gPaletteFade.bufferTransferDisabled = TRUE;

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    ResetSpriteData();
    FreeAllSpritePalettes();
    IntroResetGpuRegs();

    SetGpuReg(REG_OFFSET_BG3CNT, BGCNT_PRIORITY(3) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(28) | BGCNT_16COLOR | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) | BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(29) | BGCNT_16COLOR | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1) | BGCNT_CHARBASE(2) | BGCNT_SCREENBASE(30) | BGCNT_16COLOR | BGCNT_TXT256x256);

    DecompressDataWithHeaderVram(sPtLucasSky_Gfx,   (void *)BG_CHAR_ADDR(0));
    DecompressDataWithHeaderVram(sPtLucasSky_Map,   (void *)BG_SCREEN_ADDR(28));
    DecompressDataWithHeaderVram(sPtLucasBld_Gfx,   (void *)BG_CHAR_ADDR(1));
    DecompressDataWithHeaderVram(sPtLucasBld_Map,   (void *)BG_SCREEN_ADDR(29));
    DecompressDataWithHeaderVram(sPtLucasTrees_Gfx, (void *)BG_CHAR_ADDR(2));
    DecompressDataWithHeaderVram(sPtLucasTrees_Map, (void *)BG_SCREEN_ADDR(30));

    LoadPalette(sPtLucasSky_Pal,   BG_PLTT_ID(0), PLTT_SIZE_4BPP);
    LoadPalette(sPtLucasBld_Pal,   BG_PLTT_ID(1), PLTT_SIZE_4BPP);
    LoadPalette(sPtLucasTrees_Pal, BG_PLTT_ID(2), PLTT_SIZE_4BPP);

    SetGpuReg(REG_OFFSET_BG3VOFS, PT_S6_BASE_VOFS);
    SetGpuReg(REG_OFFSET_BG2VOFS, PT_S6_BASE_VOFS);
    SetGpuReg(REG_OFFSET_BG1VOFS, PT_S6_BASE_VOFS);

    // Pre-load both runner sprite sheets
    LoadCompressedSpriteSheet(&sPtLucasRun_Sheet);
    LoadCompressedSpriteSheet(&sPtDawnRun_Sheet);
    LoadSpritePalette(&sPtLucasRun_PalEntry);
    LoadSpritePalette(&sPtDawnRun_PalEntry);

    idLTop = CreateSprite(&sSpriteTemplate_PtRunner, 76, 72, 0);
    idLBot = CreateSprite(&sSpriteTemplate_PtRunner, 76, 136, 0);
    if (idLTop != MAX_SPRITES)
        StartSpriteAnim(&gSprites[idLTop], 0);
    if (idLBot != MAX_SPRITES)
        StartSpriteAnim(&gSprites[idLBot], 1);

    idDTop = CreateSprite(&sSpriteTemplate_PtRunnerDawn, 164, 72, 0);
    idDBot = CreateSprite(&sSpriteTemplate_PtRunnerDawn, 164, 136, 0);
    if (idDTop != MAX_SPRITES)
    {
        StartSpriteAnim(&gSprites[idDTop], 0);
        gSprites[idDTop].invisible = TRUE;
    }
    if (idDBot != MAX_SPRITES)
    {
        StartSpriteAnim(&gSprites[idDBot], 1);
        gSprites[idDBot].invisible = TRUE;
    }

    // Pre-decompress Dawn BGs so the swap at the halfway point is instant
    dawnBuf = Alloc(PT_S6_DAWN_BUF_SZ);
    if (dawnBuf != NULL)
    {
        u8 *p = dawnBuf;
        DecompressDataWithHeaderWram(sPtDawnSky_Gfx, p);   p += PT_S6_DAWN_SKY_GFX_SZ;
        DecompressDataWithHeaderWram(sPtDawnBld_Gfx, p);   p += PT_S6_DAWN_BLD_GFX_SZ;
        DecompressDataWithHeaderWram(sPtDawnTrees_Gfx, p); p += PT_S6_DAWN_TREE_GFX_SZ;
        DecompressDataWithHeaderWram(sPtDawnSky_Map, p);   p += PT_S6_DAWN_MAP_SZ;
        DecompressDataWithHeaderWram(sPtDawnBld_Map, p);   p += PT_S6_DAWN_MAP_SZ;
        DecompressDataWithHeaderWram(sPtDawnTrees_Map, p);
    }

    // Letterbox: horizontal black bars at the top and bottom, sprites drawn outside the window
    SetGpuReg(REG_OFFSET_WIN0H, WIN_RANGE(0, DISPLAY_WIDTH));
    SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(16, DISPLAY_HEIGHT - 16));
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_ALL);
    SetGpuReg(REG_OFFSET_WINOUT, WINOUT_WIN01_OBJ);

    // Start solid white, then slowly fade in from white
    BlendPalettes(PALETTES_ALL, 16, RGB_WHITE);
    gPaletteFade.bufferTransferDisabled = FALSE;
    BeginNormalPaletteFade(PALETTES_ALL, 2, 16, 0, RGB_WHITE);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG1_ON
                                | DISPCNT_BG2_ON
                                | DISPCNT_BG3_ON
                                | DISPCNT_OBJ_ON
                                | DISPCNT_WIN0_ON);

    gTasks[taskId].data[0] = 0; // timer
    gTasks[taskId].data[1] = idLTop;
    gTasks[taskId].data[2] = idLBot;
    gTasks[taskId].data[3] = idDTop;
    gTasks[taskId].data[4] = idDBot;
    gTasks[taskId].data[5] = 0; // current anim frame (0 or 1)
    SetWordTaskArg(taskId, 6, (u32)dawnBuf);
    gTasks[taskId].func = Task_Scene6_Pt;
}

static void Task_Scene6_Pt(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 timer = data[0]++;
    u16 phaseTimer;
    u8 frame, idTop, idBot;

    // Flash white before swapping VRAM to Dawn's backgrounds
    if (timer == PT_S6_PHASE_FRAMES - 2)
    {
        BlendPalettes(PALETTES_ALL, 16, RGB_WHITE);
    }
    else if (timer == PT_S6_PHASE_FRAMES)
    {
        u8 *dawnBuf = (u8 *)GetWordTaskArg(taskId, 6);

        gPaletteFade.bufferTransferDisabled = TRUE;

        if (data[1] != MAX_SPRITES) gSprites[data[1]].invisible = TRUE;
        if (data[2] != MAX_SPRITES) gSprites[data[2]].invisible = TRUE;
        if (data[3] != MAX_SPRITES) gSprites[data[3]].invisible = FALSE;
        if (data[4] != MAX_SPRITES) gSprites[data[4]].invisible = FALSE;

        if (dawnBuf != NULL)
        {
            const u8 *p = dawnBuf;
            DmaCopy32(3, p, (void *)BG_CHAR_ADDR(0), PT_S6_DAWN_SKY_GFX_SZ);  p += PT_S6_DAWN_SKY_GFX_SZ;
            DmaCopy32(3, p, (void *)BG_CHAR_ADDR(1), PT_S6_DAWN_BLD_GFX_SZ);  p += PT_S6_DAWN_BLD_GFX_SZ;
            DmaCopy32(3, p, (void *)BG_CHAR_ADDR(2), PT_S6_DAWN_TREE_GFX_SZ); p += PT_S6_DAWN_TREE_GFX_SZ;
            DmaCopy32(3, p, (void *)BG_SCREEN_ADDR(28), PT_S6_DAWN_MAP_SZ);   p += PT_S6_DAWN_MAP_SZ;
            DmaCopy32(3, p, (void *)BG_SCREEN_ADDR(29), PT_S6_DAWN_MAP_SZ);   p += PT_S6_DAWN_MAP_SZ;
            DmaCopy32(3, p, (void *)BG_SCREEN_ADDR(30), PT_S6_DAWN_MAP_SZ);
            Free(dawnBuf);
            SetWordTaskArg(taskId, 6, 0);
        }

        LoadPalette(sPtDawnSky_Pal,   BG_PLTT_ID(0), PLTT_SIZE_4BPP);
        LoadPalette(sPtDawnBld_Pal,   BG_PLTT_ID(1), PLTT_SIZE_4BPP);
        LoadPalette(sPtDawnTrees_Pal, BG_PLTT_ID(2), PLTT_SIZE_4BPP);
        BlendPalettes(PALETTES_ALL, 16, RGB_WHITE);

        SetGpuReg(REG_OFFSET_BG2VOFS, PT_S6_BASE_VOFS);
        SetGpuReg(REG_OFFSET_BG1VOFS, PT_S6_BASE_VOFS);

        gPaletteFade.bufferTransferDisabled = FALSE;
        BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_WHITE);
        data[5] = 0;
    }

    if (timer < PT_S6_PHASE_FRAMES)
    {
        phaseTimer = timer;
        idTop = data[1];
        idBot = data[2];
    }
    else
    {
        phaseTimer = timer - PT_S6_PHASE_FRAMES;
        idTop = data[3];
        idBot = data[4];
    }

    // Animate the running cycle and bob the sprite
    frame = (phaseTimer / 15) & 1;
    if (frame != data[5])
    {
        s8 dx = (timer < PT_S6_PHASE_FRAMES) ? -2 : 2;
        s8 bobY = frame ? -2 : 0;
        data[5] = frame;
        if (idTop != MAX_SPRITES)
        {
            gSprites[idTop].x += dx;
            gSprites[idTop].y2 = bobY;
            StartSpriteAnim(&gSprites[idTop], frame * 2);
        }
        if (idBot != MAX_SPRITES)
        {
            gSprites[idBot].x += dx;
            gSprites[idBot].y2 = bobY;
            StartSpriteAnim(&gSprites[idBot], frame * 2 + 1);
        }
    }

    // Parallax scroll: buildings faster, trees slower
    SetGpuReg(REG_OFFSET_BG2VOFS, PT_S6_BASE_VOFS - (phaseTimer / 30));
    SetGpuReg(REG_OFFSET_BG1VOFS, PT_S6_BASE_VOFS - (phaseTimer / 60));

    // Fade out and transition to Scene 7
    if (timer == PT_S6_TOTAL_FRAMES - 16)
    {
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
    }
    else if (timer >= PT_S6_TOTAL_FRAMES && !gPaletteFade.active)
    {
        data[0] = 0;
        gTasks[taskId].func = Task_Scene7_Pt_Load;
    }
}


// Lucas strip: Y=8..71 (center Y=40); Dawn strip: Y=88..151 (center Y=120)
#define PT_S7_LUCAS_STRIP_Y     40
#define PT_S7_DAWN_STRIP_Y      120
#define PT_S7_LUCAS_HP_Y        (PT_S7_LUCAS_STRIP_Y + 11) // 51 (11px down)
#define PT_S7_DAWN_HP_Y         (PT_S7_DAWN_STRIP_Y + 11)  // 131 (11px down)
#define PT_S7_LUCAS_THROW_X     144
#define PT_S7_DAWN_THROW_X      32

#define PT_S7_THROW_HOLD_FRAMES 90  // 1.5s
#define PT_S7_HP_HOLD_FRAMES    30  // 0.5s
#define PT_S7_TOTAL_FRAMES      238 // 238 frames (~4.0s); Scene 8 follows at 1m 06s
#define PT_S7_FADE_FRAMES       28  // Begin the white fade ~0.47s before the transition

static void SpriteCB_PtS7HandZip(struct Sprite *sprite)
{
    sprite->x += sprite->data[0];
    if (sprite->x < -48 || sprite->x > DISPLAY_WIDTH + 48)
        DestroySprite(sprite);
}

// data[0]: frame counter, data[1]: dirX (-1 left, +1 right), data[2]: angle, data[3]: angVel
static void SpriteCB_PtS7SpinBall(struct Sprite *sprite)
{
    s16 c, s;

    // Smooth 0.5 px/frame drift without fixed-point s16 overflow
    if (++sprite->data[0] & 1)
        sprite->x += sprite->data[1];

    sprite->data[2] = (sprite->data[2] + sprite->data[3]) & 0xFF;
    c = Cos(sprite->data[2], 256);
    s = Sin(sprite->data[2], 256);
    SetOamMatrix(sprite->oam.matrixNum, c, s, -s, c);
}

static void Task_Scene7_Pt_Load(u8 taskId)
{
    int i;
    u8 id;

    gPaletteFade.bufferTransferDisabled = TRUE;
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    ResetSpriteData();
    FreeAllSpritePalettes();
    IntroResetGpuRegs();

    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(28) | BGCNT_16COLOR | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(2) | BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(29) | BGCNT_16COLOR | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) | BGCNT_CHARBASE(2) | BGCNT_SCREENBASE(30) | BGCNT_16COLOR | BGCNT_TXT256x256);

    DecompressDataWithHeaderVram(sPtS7Bars_Gfx,    (void *)BG_CHAR_ADDR(0));
    DecompressDataWithHeaderVram(sPtS7Bars_Map,    (void *)BG_SCREEN_ADDR(28));
    DecompressDataWithHeaderVram(sPtS7LucasFx_Gfx, (void *)BG_CHAR_ADDR(1));
    DecompressDataWithHeaderVram(sPtS7LucasFx_Map, (void *)BG_SCREEN_ADDR(29));
    DecompressDataWithHeaderVram(sPtS7DawnFx_Gfx,  (void *)BG_CHAR_ADDR(2));
    DecompressDataWithHeaderVram(sPtS7DawnFx_Map,  (void *)BG_SCREEN_ADDR(30));

    LoadPalette(sPtS7Bars_Pal,    BG_PLTT_ID(0), PLTT_SIZE_4BPP);
    LoadPalette(sPtS7LucasFx_Pal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
    LoadPalette(sPtS7DawnFx_Pal,  BG_PLTT_ID(2), PLTT_SIZE_4BPP);

    // Load all Scene 7 sprite sheets upfront
    for (i = 0; sPtS7_SpriteSheets[i].data != NULL; i++)
        LoadCompressedSpriteSheet(&sPtS7_SpriteSheets[i]);
    LoadSpritePalettes(sPtS7_SpritePals);

    // Create Lucas throw (id 1 & 2) and Dawn throw (id 3 & 4)
    id = CreateSprite(&sSpriteTemplate_PtS7LucasThrow, PT_S7_LUCAS_THROW_X, PT_S7_LUCAS_STRIP_Y, 0);
    gTasks[taskId].data[1] = id;
    if (id != MAX_SPRITES) StartSpriteAnim(&gSprites[id], 0);

    id = CreateSprite(&sSpriteTemplate_PtS7LucasThrow, PT_S7_LUCAS_THROW_X + 64, PT_S7_LUCAS_STRIP_Y, 0);
    gTasks[taskId].data[2] = id;
    if (id != MAX_SPRITES) StartSpriteAnim(&gSprites[id], 1);

    id = CreateSprite(&sSpriteTemplate_PtS7DawnThrow, PT_S7_DAWN_THROW_X, PT_S7_DAWN_STRIP_Y, 0);
    gTasks[taskId].data[3] = id;
    if (id != MAX_SPRITES) StartSpriteAnim(&gSprites[id], 0);

    id = CreateSprite(&sSpriteTemplate_PtS7DawnThrow, PT_S7_DAWN_THROW_X + 64, PT_S7_DAWN_STRIP_Y, 0);
    gTasks[taskId].data[4] = id;
    if (id != MAX_SPRITES) StartSpriteAnim(&gSprites[id], 1);

    BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
    gPaletteFade.bufferTransferDisabled = FALSE;
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG0_ON
                                | DISPCNT_BG1_ON
                                | DISPCNT_BG2_ON
                                | DISPCNT_OBJ_ON);

    gTasks[taskId].data[0] = 0; // timer
    gTasks[taskId].data[5] = 0; // BG1HOFS
    gTasks[taskId].data[6] = 0; // BG2HOFS
    gTasks[taskId].data[7] = 0; // state (0=throw, 1=dip1, 2=hp, 3=dip2, 4=balls)
    gTasks[taskId].data[8] = 0; // state timer
    gTasks[taskId].func = Task_Scene7_Pt;
}

static void Task_Scene7_Pt(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 timer = data[0]++;
    u8 id;

    // Continuously scroll the effect bars
    data[5] = (data[5] - 12) & 0xFF;
    data[6] = (data[6] + 12) & 0xFF;
    SetGpuReg(REG_OFFSET_BG1HOFS, data[5]);
    SetGpuReg(REG_OFFSET_BG2HOFS, data[6]);

    switch (data[7])
    {
    case 0: // Hold the throw pose
        if (++data[8] >= PT_S7_THROW_HOLD_FRAMES)
        {
            // Short black dip on character sprites
            BlendPalettes(PALETTES_OBJECTS, 16, RGB_BLACK);
            if (data[1] != MAX_SPRITES) DestroySprite(&gSprites[data[1]]);
            if (data[2] != MAX_SPRITES) DestroySprite(&gSprites[data[2]]);
            if (data[3] != MAX_SPRITES) DestroySprite(&gSprites[data[3]]);
            if (data[4] != MAX_SPRITES) DestroySprite(&gSprites[data[4]]);

            data[1] = CreateSprite(&sSpriteTemplate_PtS7LucasHP, DISPLAY_WIDTH / 2, PT_S7_LUCAS_HP_Y, 0);
            data[2] = CreateSprite(&sSpriteTemplate_PtS7DawnHP,  DISPLAY_WIDTH / 2, PT_S7_DAWN_HP_Y, 0);

            data[8] = 0;
            data[7] = 1;
        }
        break;

    case 1: // 2-frame sprite black dip -> fade sprites in
        if (++data[8] >= 2)
        {
            BeginNormalPaletteFade(PALETTES_OBJECTS, 0, 16, 0, RGB_BLACK);
            data[8] = 0;
            data[7] = 2;
        }
        break;

    case 2: // Hold the hand+pokeball pose
        if (++data[8] >= PT_S7_HP_HOLD_FRAMES)
        {
            // Short black dip on character sprites before throw
            BlendPalettes(PALETTES_OBJECTS, 16, RGB_BLACK);
            if (data[1] != MAX_SPRITES) DestroySprite(&gSprites[data[1]]);
            if (data[2] != MAX_SPRITES) DestroySprite(&gSprites[data[2]]);

            // Lucas hand flies right
            id = CreateSprite(&sSpriteTemplate_PtS7LucasHand, DISPLAY_WIDTH / 2, PT_S7_LUCAS_HP_Y, 0);
            if (id != MAX_SPRITES) gSprites[id].data[0] = 16;

            // Lucas pokeball spins counterclockwise and drifts left
            id = CreateSprite(&sSpriteTemplate_PtS7Ball, DISPLAY_WIDTH / 2, PT_S7_LUCAS_HP_Y, 0);
            if (id != MAX_SPRITES)
            {
                CalcCenterToCornerVec(&gSprites[id], SPRITE_SHAPE(32x32), SPRITE_SIZE(32x32), ST_OAM_AFFINE_DOUBLE);
                gSprites[id].oam.matrixNum = 0;
                gSprites[id].data[0] = 0;
                gSprites[id].data[1] = -1; // -1px every 2 frames
                gSprites[id].data[2] = 0;
                gSprites[id].data[3] = -20;
            }

            // Dawn hand flies left
            id = CreateSprite(&sSpriteTemplate_PtS7DawnHand, DISPLAY_WIDTH / 2, PT_S7_DAWN_HP_Y, 0);
            if (id != MAX_SPRITES) gSprites[id].data[0] = -16;

            // Dawn pokeball spins clockwise and drifts right
            id = CreateSprite(&sSpriteTemplate_PtS7Ball, DISPLAY_WIDTH / 2, PT_S7_DAWN_HP_Y, 0);
            if (id != MAX_SPRITES)
            {
                CalcCenterToCornerVec(&gSprites[id], SPRITE_SHAPE(32x32), SPRITE_SIZE(32x32), ST_OAM_AFFINE_DOUBLE);
                gSprites[id].oam.matrixNum = 1;
                gSprites[id].data[0] = 0;
                gSprites[id].data[1] = 1; // +1px every 2 frames
                gSprites[id].data[2] = 0;
                gSprites[id].data[3] = 20;
            }

            data[8] = 0;
            data[7] = 3;
        }
        break;

    case 3: // 2-frame sprite black dip -> fade sprites in
        if (++data[8] >= 2)
        {
            BeginNormalPaletteFade(PALETTES_OBJECTS, 0, 16, 0, RGB_BLACK);
            data[8] = 0;
            data[7] = 4;
        }
        break;

    case 4: // Begin the white fade before transitioning to Scene 8
        if (timer == PT_S7_TOTAL_FRAMES - PT_S7_FADE_FRAMES)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 2, 0, 16, RGB_WHITE);
        }
        break;
    }

    // Transition to Scene 8 while the screen is white
    if (timer >= PT_S7_TOTAL_FRAMES && !gPaletteFade.active)
    {
        data[0] = 0;
        gTasks[taskId].func = Task_Scene8_Pt_Load;
    }
}

#define PT_S8_PAIR1_FRAME       4   // Torterra & Infernape
#define PT_S8_PAIR2_FRAME       22  // +0.3s: Prinplup & Grotle
#define PT_S8_PAIR3_FRAME       40  // +0.3s: Chimchar & Piplup
#define PT_S8_SLIDE_FRAMES      12  // ~0.20s snappy slide-in
#define PT_S8_CONVERGE_FRAME    167 // 167 frames (~2.8s after Scene 8 starts)
#define PT_S8_TOTAL_FRAMES      209 // 209 frames (~3.5s minimum before Scene 9 can start)

// data[0]: state (0=sliding, 1=settled, 2=converging), data[1]: startX, data[2]: targetX, data[3]: timer, data[4]: exitVelX
static void SpriteCB_PtS8Slide(struct Sprite *sprite)
{
    if (sprite->data[0] == 0)
    {
        s32 t = ++sprite->data[3];
        s32 d = PT_S8_SLIDE_FRAMES;
        if (t >= d)
        {
            sprite->x = sprite->data[2];
            sprite->data[0] = 1;
        }
        else
        {
            s32 rem = d - t;
            s32 delta = sprite->data[2] - sprite->data[1];
            s32 num = d * d - rem * rem;
            sprite->x = sprite->data[1] + (delta * num) / (d * d);
        }
    }
    else if (sprite->data[0] == 2)
    {
        sprite->x += sprite->data[4];
        if (sprite->x < -96 || sprite->x > DISPLAY_WIDTH + 96)
            sprite->invisible = TRUE;
    }
}

static void SpawnPtS8Pokemon(const struct SpriteTemplate *tmplTop, const struct SpriteTemplate *tmplBot,
                             s16 startLeftX, s16 targetLeftX, s16 topY, s16 exitVelX, u8 subpriority)
{
    u8 id;
    s16 startL = startLeftX + 32;
    s16 startR = startLeftX + 96;
    s16 targetL = targetLeftX + 32;
    s16 targetR = targetLeftX + 96;

    id = CreateSprite(tmplTop, startL, topY + 32, subpriority);
    if (id != MAX_SPRITES)
    {
        StartSpriteAnim(&gSprites[id], 0);
        gSprites[id].data[1] = startL;
        gSprites[id].data[2] = targetL;
        gSprites[id].data[4] = exitVelX;
    }

    id = CreateSprite(tmplTop, startR, topY + 32, subpriority);
    if (id != MAX_SPRITES)
    {
        StartSpriteAnim(&gSprites[id], 1);
        gSprites[id].data[1] = startR;
        gSprites[id].data[2] = targetR;
        gSprites[id].data[4] = exitVelX;
    }

    if (tmplBot != NULL)
    {
        id = CreateSprite(tmplBot, startL, topY + 80, subpriority);
        if (id != MAX_SPRITES)
        {
            StartSpriteAnim(&gSprites[id], 0);
            gSprites[id].data[1] = startL;
            gSprites[id].data[2] = targetL;
            gSprites[id].data[4] = exitVelX;
        }

        id = CreateSprite(tmplBot, startR, topY + 80, subpriority);
        if (id != MAX_SPRITES)
        {
            StartSpriteAnim(&gSprites[id], 1);
            gSprites[id].data[1] = startR;
            gSprites[id].data[2] = targetR;
            gSprites[id].data[4] = exitVelX;
        }
    }
}

static void Task_Scene8_Pt_Load(u8 taskId)
{
    int i;

    gPaletteFade.bufferTransferDisabled = TRUE;
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    ResetSpriteData();
    FreeAllSpritePalettes();
    IntroResetGpuRegs();

    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(28) | BGCNT_16COLOR | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(2) | BGCNT_CHARBASE(1) | BGCNT_SCREENBASE(29) | BGCNT_16COLOR | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2) | BGCNT_CHARBASE(2) | BGCNT_SCREENBASE(30) | BGCNT_16COLOR | BGCNT_TXT256x256);

    DecompressDataWithHeaderVram(sPtS7Bars_Gfx,    (void *)BG_CHAR_ADDR(0));
    DecompressDataWithHeaderVram(sPtS7Bars_Map,    (void *)BG_SCREEN_ADDR(28));
    DecompressDataWithHeaderVram(sPtS8GreenFx_Gfx, (void *)BG_CHAR_ADDR(1));
    DecompressDataWithHeaderVram(sPtS8GreenFx_Map, (void *)BG_SCREEN_ADDR(29));
    DecompressDataWithHeaderVram(sPtS8RedFx_Gfx,   (void *)BG_CHAR_ADDR(2));
    DecompressDataWithHeaderVram(sPtS8RedFx_Map,   (void *)BG_SCREEN_ADDR(30));

    LoadPalette(sPtS7Bars_Pal,    BG_PLTT_ID(0), PLTT_SIZE_4BPP);
    LoadPalette(sPtS8GreenFx_Pal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);
    LoadPalette(sPtS8RedFx_Pal,   BG_PLTT_ID(2), PLTT_SIZE_4BPP);

    for (i = 0; sPtS8_SpriteSheets[i].data != NULL; i++)
        LoadCompressedSpriteSheet(&sPtS8_SpriteSheets[i]);
    LoadSpritePalettes(sPtS8_SpritePals);

    BlendPalettes(PALETTES_ALL, 16, RGB_WHITE);
    gPaletteFade.bufferTransferDisabled = FALSE;
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_WHITE);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG0_ON
                                | DISPCNT_BG1_ON
                                | DISPCNT_BG2_ON
                                | DISPCNT_OBJ_ON);

    gTasks[taskId].data[0] = 0; // timer
    gTasks[taskId].data[1] = 0; // BG1HOFS (green_effect)
    gTasks[taskId].data[2] = 0; // BG2HOFS (red_effect)
    gTasks[taskId].data[3] = 0; // transition state (0=idle, 1=to white, 2=white to black)
    gTasks[taskId].func = Task_Scene8_Pt;
}

static void Task_Scene8_Pt(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 timer = data[0]++;
    int i;

    // Scroll effect bars the same way as Scene 7
    data[1] = (data[1] - 12) & 0xFF;
    data[2] = (data[2] + 12) & 0xFF;
    SetGpuReg(REG_OFFSET_BG1HOFS, data[1]);
    SetGpuReg(REG_OFFSET_BG2HOFS, data[2]);

    // Torterra slides in from the right, Infernape from the left
    if (timer == PT_S8_PAIR1_FRAME)
    {
        SpawnPtS8Pokemon(&sSpriteTemplate_PtS8TorterraTop,  &sSpriteTemplate_PtS8TorterraBot,  240,  136,  4, -7, 2);
        SpawnPtS8Pokemon(&sSpriteTemplate_PtS8InfernapeTop, &sSpriteTemplate_PtS8InfernapeBot, -128,  -2, 84,  7, 2);
    }
    // Layer 2 (+0.3s, middle, subpriority 1): Prinplup (from right) & Grotle (from left)
    else if (timer == PT_S8_PAIR2_FRAME)
    {
        SpawnPtS8Pokemon(&sSpriteTemplate_PtS8PrinplupTop, NULL, 240,  68, 18, -7, 1);
        SpawnPtS8Pokemon(&sSpriteTemplate_PtS8GrotleTop,   NULL, -128, 94, 89,  7, 1);
    }
    // Layer 3 (+0.3s, frontmost, subpriority 0): Chimchar (from right) & Piplup (from left)
    else if (timer == PT_S8_PAIR3_FRAME)
    {
        SpawnPtS8Pokemon(&sSpriteTemplate_PtS8ChimcharTop, &sSpriteTemplate_PtS8ChimcharBot, 240,  91,  5, -7, 0);
        SpawnPtS8Pokemon(&sSpriteTemplate_PtS8PiplupTop,   NULL,                             -128, 50, 92,  7, 0);
    }

    switch (data[3])
    {
    case 0:
        if (timer >= PT_S8_CONVERGE_FRAME)
        {
            for (i = 0; i < MAX_SPRITES; i++)
            {
                if (gSprites[i].inUse && gSprites[i].callback == SpriteCB_PtS8Slide)
                    gSprites[i].data[0] = 2;
            }
            BeginNormalPaletteFade(PALETTES_ALL, 1, 0, 16, RGB_WHITE);
            data[3] = 1;
        }
        break;

    case 1: // Wait for smooth white flash -> fade smoothly from white into black
        if (!gPaletteFade.active)
        {
            CpuFill16(RGB_WHITE, gPlttBufferUnfaded, PLTT_SIZE);
            BeginNormalPaletteFade(PALETTES_ALL, 1, 0, 16, RGB_BLACK);
            data[3] = 2;
        }
        break;

    case 2: // Enter Scene 9 after the timer threshold and black fade complete
        if (!gPaletteFade.active && timer >= PT_S8_TOTAL_FRAMES)
        {
            data[0] = 0;
            gTasks[taskId].func = Task_Scene9_Pt_Load;
        }
        break;
    }
}


#define PT_S9_SCROLL_STEP   30  // Very slow downward scroll (~0.117 px/frame, stops at 4s regardless)
#define PT_S9_TOTAL_FRAMES  240 // 4.0s

static void Task_Scene9_Pt_Load(u8 taskId)
{
    gPaletteFade.bufferTransferDisabled = TRUE;
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    ResetSpriteData();
    FreeAllSpritePalettes();
    IntroResetGpuRegs();

    SetGpuReg(REG_OFFSET_BG2HOFS, 8); // Center 256px Cyrus in 240px screen
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(28)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);

    DecompressDataWithHeaderVram(sPtS9Cyrus_Gfx, (void *)BG_CHAR_ADDR(0));
    DecompressDataWithHeaderVram(sPtS9Cyrus_Map, (void *)BG_SCREEN_ADDR(28));
    LoadPalette(sPtS9Cyrus_Pal, BG_PLTT_ID(0), PLTT_SIZE_4BPP);

    // Stay black, then fade in Cyrus very slowly (~1.76s)
    BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
    gPaletteFade.bufferTransferDisabled = FALSE;
    BeginNormalPaletteFade(PALETTES_ALL, 14, 16, 0, RGB_BLACK);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_BG2_ON);

    gTasks[taskId].data[0] = 0; // timer
    SetWordTaskArg(taskId, 1, 0); // 24.8 fixed point VOFS
    gTasks[taskId].func = Task_Scene9_Pt;
}

static void Task_Scene9_Pt(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 timer = data[0]++;
    s32 vofs = (s32)GetWordTaskArg(taskId, 1) + PT_S9_SCROLL_STEP;

    if (vofs > (72 << 8))
        vofs = 72 << 8;
    SetWordTaskArg(taskId, 1, (u32)vofs);
    SetGpuReg(REG_OFFSET_BG2VOFS, vofs >> 8);

    // Fade out to black near the end of 4 seconds, then transition to Giratina BG
    if (timer == PT_S9_TOTAL_FRAMES - 24)
    {
        BeginNormalPaletteFade(PALETTES_ALL, 2, 0, 16, RGB_BLACK);
    }
    else if (timer >= PT_S9_TOTAL_FRAMES && !gPaletteFade.active)
    {
        data[0] = 0;
        gTasks[taskId].func = Task_Scene10_Pt_Load;
    }
}


#define PT_S10_FRAME_PERIOD 12  // ~5 frames per second (0.2s/frame)
#define PT_S10_EYE_START    180 // 3.0s: eyes fade in & open 2.4 -> 2.1
#define PT_S10_MOUTH_START  360 // 6.0s: eye blink (2.1 -> 2.4 -> 2.1) + mouth 3 -> 6 -> 3
#define PT_S10_FADE_OUT     448 // ~7.5s: eyes & mouth fade out slowly (finishes at 512)
#define PT_S10_ZOOM_START   516 // ~8.6s: switch to Mode 4 and zoom into black portal center
#define PT_S10_ZOOM_FRAMES  76  // ~1.27s accelerating zoom into portal
#define PT_S10_SRC_W        240
#define PT_S10_SRC_H        160

static void ComputeGiratinaZoomCamera(u16 zoomTimer, u16 *outTexY, u16 *outScale)
{
    u32 t = (zoomTimer > PT_S10_ZOOM_FRAMES) ? PT_S10_ZOOM_FRAMES : zoomTimer;
    u32 u = (t * t * 256) / (PT_S10_ZOOM_FRAMES * PT_S10_ZOOM_FRAMES); // Quadratic ease-in (0..256)

    // Smoothly zoom 1.0x (0x100) -> 8.0x (0x020) while centering on black portal center (120, 71)
    *outScale = 0x100 - ((0x100 - 0x020) * u) / 256;
    *outTexY = 80 - ((80 - 71) * u) / 256;
}

__attribute__((target("arm")))
static void RenderGiratinaMode4Rows(u8 page, const u8 *bitmap, u16 texY, u16 scale, u8 yStart, u8 yEnd)
{
    u32 *dstBase = (u32 *)(page ? (BG_VRAM + 0xA000) : BG_VRAM);
    s32 startX = ((s32)120 << 8) - (DISPLAY_WIDTH / 2) * (s32)scale;
    s32 startY = ((s32)texY << 8) - (DISPLAY_HEIGHT / 2) * (s32)scale;
    u16 x, y;

    if (yStart == 0)
    {
        s32 curX = startX;
        for (x = 0; x < DISPLAY_WIDTH; x++)
        {
            s32 sx = curX >> 8;
            if (sx < 0)
                sx = 0;
            else if (sx >= PT_S10_SRC_W)
                sx = PT_S10_SRC_W - 1;
            sPtMode4XLut[x] = sx;
            curX += scale;
        }
    }

    for (y = yStart; y < yEnd; y++)
    {
        s32 sy = (startY + (s32)y * (s32)scale) >> 8;
        const u8 *srcRow;
        u32 *dstRow;

        if (sy < 0)
            sy = 0;
        else if (sy >= PT_S10_SRC_H)
            sy = PT_S10_SRC_H - 1;

        srcRow = &bitmap[sy * PT_S10_SRC_W];
        dstRow = &dstBase[y * (DISPLAY_WIDTH / 4)];

        for (x = 0; x < DISPLAY_WIDTH; x += 4)
        {
            u32 p0 = srcRow[sPtMode4XLut[x]];
            u32 p1 = srcRow[sPtMode4XLut[x + 1]];
            u32 p2 = srcRow[sPtMode4XLut[x + 2]];
            u32 p3 = srcRow[sPtMode4XLut[x + 3]];
            *dstRow++ = p0 | (p1 << 8) | (p2 << 16) | (p3 << 24);
        }
    }
}

static void SetPtS10EyeFrame(u8 spriteId, u8 frame)
{
    u16 base;

    if (spriteId == MAX_SPRITES)
        return;

    base = GetSpriteTileStartByTag(TAG_PT_S10_EYE0 + frame);
    gSprites[spriteId].sheetTileStart = base;
    gSprites[spriteId].oam.tileNum = base;
    LoadPalette(sPtS10EyePals[frame], OBJ_PLTT_ID(gSprites[spriteId].oam.paletteNum), PLTT_SIZE_4BPP);
}

static void SetPtS10MouthFrame(u8 spriteId, u8 frame)
{
    u16 base;

    if (spriteId == MAX_SPRITES)
        return;

    base = GetSpriteTileStartByTag(TAG_PT_S10_MOUTH0 + frame);
    gSprites[spriteId].sheetTileStart = base;
    gSprites[spriteId].oam.tileNum = base;
    LoadPalette(sPtS10MouthPals[frame], OBJ_PLTT_ID(gSprites[spriteId].oam.paletteNum), PLTT_SIZE_4BPP);
}

static void Task_Scene10_Pt_Load(u8 taskId)
{
    int i;
    u8 idEL, idML;

    gPaletteFade.bufferTransferDisabled = TRUE;
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
    DmaFill16(3, 0, (void *)VRAM, VRAM_SIZE);
    ResetSpriteData();
    FreeAllSpritePalettes();
    IntroResetGpuRegs();

    DecompressDataWithHeaderVram(sPtS10Bg0_Gfx, (void *)BG_CHAR_ADDR(0));
    DecompressDataWithHeaderVram(sPtS10Bg0_Map, (void *)BG_SCREEN_ADDR(28));
    DecompressDataWithHeaderVram(sPtS10Bg1_Gfx, (void *)BG_CHAR_ADDR(1));
    DecompressDataWithHeaderVram(sPtS10Bg1_Map, (void *)BG_SCREEN_ADDR(29));
    LoadPalette(sPtS10Bg0_Pal, BG_PLTT_ID(0), PLTT_SIZE_4BPP);
    LoadPalette(sPtS10Bg1_Pal, BG_PLTT_ID(1), PLTT_SIZE_4BPP);

    for (i = 0; sPtS10_SpriteSheets[i].data != NULL; i++)
        LoadCompressedSpriteSheet(&sPtS10_SpriteSheets[i]);
    LoadSpritePalettes(sPtS10_SpritePals);

    // 0.5x Eyes & Mouth: single 64x32 sprites centered in the portal
    idEL = CreateSprite(&sSpriteTemplate_PtS10Eye, 120, 60, 0);
    if (idEL != MAX_SPRITES) { StartSpriteAnim(&gSprites[idEL], 0); gSprites[idEL].invisible = TRUE; }
    SetPtS10EyeFrame(idEL, 3); // Start at 2.4

    idML = CreateSprite(&sSpriteTemplate_PtS10Mouth, 120, 80, 1);
    if (idML != MAX_SPRITES) { StartSpriteAnim(&gSprites[idML], 0); gSprites[idML].invisible = TRUE; }
    SetPtS10MouthFrame(idML, 0); // Start at 3

    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(3)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(28)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);

    // Hardware alpha blend for OBJ (eyes & mouth) over BG2 (portal)
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_OBJ | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BD);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(0, 16));

    BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
    gPaletteFade.bufferTransferDisabled = FALSE;
    BeginNormalPaletteFade(PALETTES_ALL, 1, 16, 0, RGB_BLACK);

    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG2_ON | DISPCNT_OBJ_ON);

    gTasks[taskId].data[0] = 0;    // timer
    gTasks[taskId].data[1] = 0;    // active BG frame
    gTasks[taskId].data[2] = idEL;
    gTasks[taskId].data[4] = idML;
    gTasks[taskId].data[6] = 3;    // current eye frame (0=2.1 .. 3=2.4)
    gTasks[taskId].data[7] = 0;    // current mouth frame (0=3 .. 3=6)
    gTasks[taskId].data[8] = 0;    // current alpha (0..16)
    gTasks[taskId].data[9] = 0;    // Mode 4 zoom phase (0=Mode0, 1=Mode4 zooming, 2=black hold)
    gTasks[taskId].data[10] = 0;   // Mode 4 displayed page (0 or 1)
    gTasks[taskId].data[11] = 0;   // Mode 4 render slice (0 or 1)
    gTasks[taskId].data[12] = 80;  // Mode 4 latched texY
    gTasks[taskId].data[13] = 0x100; // Mode 4 latched scale
    gTasks[taskId].data[14] = 0;   // Mode 4 latched bgFrame
    gTasks[taskId].func = Task_Scene10_Pt;
}

static void Task_Scene10_Pt(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 timer = data[0]++;
    u8 bgFrame = (timer / PT_S10_FRAME_PERIOD) & 1;

    // Phase 0: Mode 0 portal + Giratina eyes & mouth fade/animation
    if (data[9] == 0)
    {
        u8 eyeFrame = data[6];
        u8 mouthFrame = data[7];
        u8 eva = data[8];

        if (bgFrame != data[1])
        {
            data[1] = bgFrame;
            SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(3)
                                       | BGCNT_CHARBASE(bgFrame ? 1 : 0)
                                       | BGCNT_SCREENBASE(bgFrame ? 29 : 28)
                                       | BGCNT_16COLOR
                                       | BGCNT_TXT256x256);
        }

        // At 3.0s: fade in eyes and open 2.4 -> 2.1, then hold 2.1 until 6.0s
        if (timer == PT_S10_EYE_START)
        {
            if (data[2] != MAX_SPRITES) gSprites[data[2]].invisible = FALSE;
            eyeFrame = 3;
        }
        else if (timer > PT_S10_EYE_START && timer < PT_S10_MOUTH_START)
        {
            u16 dt = timer - PT_S10_EYE_START;
            if (dt < 6)       eyeFrame = 3; // 2.4
            else if (dt < 12) eyeFrame = 2; // 2.3
            else if (dt < 18) eyeFrame = 1; // 2.2
            else              eyeFrame = 0; // 2.1 (hold)
        }

        // At 6.0s: blink eyes (2.1 -> 2.4 -> 2.1 -> hold) AND play mouth 3 -> 6 -> 3
        if (timer == PT_S10_MOUTH_START)
        {
            if (data[4] != MAX_SPRITES) gSprites[data[4]].invisible = FALSE;
            eyeFrame = 0;
            mouthFrame = 0;
        }
        else if (timer > PT_S10_MOUTH_START)
        {
            u16 dt = timer - PT_S10_MOUTH_START;

            if (dt < 4)       eyeFrame = 0; // 2.1
            else if (dt < 8)  eyeFrame = 1; // 2.2
            else if (dt < 12) eyeFrame = 2; // 2.3
            else if (dt < 16) eyeFrame = 3; // 2.4
            else if (dt < 20) eyeFrame = 2; // 2.3
            else if (dt < 24) eyeFrame = 1; // 2.2
            else              eyeFrame = 0; // 2.1 (hold)

            if (dt < 8)       mouthFrame = 0; // giratina_3
            else if (dt < 16) mouthFrame = 1; // giratina_4
            else if (dt < 24) mouthFrame = 2; // giratina_5
            else if (dt < 66) mouthFrame = 3; // giratina_6 (hold open)
            else if (dt < 74) mouthFrame = 2; // giratina_5
            else if (dt < 82) mouthFrame = 1; // giratina_4
            else              mouthFrame = 0; // giratina_3
        }

        if (eyeFrame != data[6])
        {
            data[6] = eyeFrame;
            SetPtS10EyeFrame(data[2], eyeFrame);
        }
        if (mouthFrame != data[7])
        {
            data[7] = mouthFrame;
            SetPtS10MouthFrame(data[4], mouthFrame);
        }

        if (timer >= PT_S10_EYE_START && timer < PT_S10_FADE_OUT)
        {
            u16 dt = timer - PT_S10_EYE_START;
            eva = (dt >= 32) ? 16 : (dt >> 1);
        }
        else if (timer >= PT_S10_FADE_OUT)
        {
            u16 dt = timer - PT_S10_FADE_OUT;
            u16 sub = dt >> 2;
            eva = (sub >= 16) ? 0 : (16 - sub);
            if (eva == 0)
            {
                if (data[2] != MAX_SPRITES) gSprites[data[2]].invisible = TRUE;
                if (data[4] != MAX_SPRITES) gSprites[data[4]].invisible = TRUE;
            }
        }

        if (eva != data[8])
        {
            data[8] = eva;
            SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(eva, 16 - eva));
        }

        // Seamless switch from Mode 0 -> Mode 4 at 1:1 scale once Giratina has faded away
        if (timer >= PT_S10_ZOOM_START)
        {
            const u8 *curBmp = bgFrame ? sPtS10M4_Bg1 : sPtS10M4_Bg0;

            ResetSpriteData();
            SetGpuReg(REG_OFFSET_BLDCNT, 0);
            SetGpuReg(REG_OFFSET_BLDALPHA, 0);

            VBlankIntrWait();
            REG_DISPCNT = DISPCNT_MODE_4 | DISPCNT_BG2_ON;
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_4 | DISPCNT_BG2_ON);
            LoadPalette(sPtS10M4_Pal, BG_PLTT_ID(0), 64);
            DmaCopy16(3, sPtS10M4_Pal, (void *)BG_PLTT, 64);
            DmaCopy32(3, curBmp, (void *)BG_VRAM, PT_S10_SRC_W * PT_S10_SRC_H);

            data[9] = 1;
            data[10] = 0;
            data[11] = 0;
        }
    }
    // Phase 1: Mode 4 2-frame-split zoom into the black center of the portal
    else if (data[9] == 1)
    {
        u16 zt = timer - PT_S10_ZOOM_START;
        u8 backPage = data[10] ^ 1;
        const u8 *bmp;
        u16 texY, scale;

        if (zt == PT_S10_ZOOM_FRAMES - 24)
            BeginNormalPaletteFade(PALETTES_ALL, 1, 0, 16, RGB_BLACK);

        if (data[11] == 0)
        {
            ComputeGiratinaZoomCamera(zt + 1, &texY, &scale);
            data[12] = texY;
            data[13] = scale;
            data[14] = bgFrame;
            bmp = bgFrame ? sPtS10M4_Bg1 : sPtS10M4_Bg0;
            RenderGiratinaMode4Rows(backPage, bmp, texY, scale, 0, DISPLAY_HEIGHT / 2);
            data[11] = 1;
        }
        else
        {
            bmp = data[14] ? sPtS10M4_Bg1 : sPtS10M4_Bg0;
            RenderGiratinaMode4Rows(backPage, bmp, data[12], data[13], DISPLAY_HEIGHT / 2, DISPLAY_HEIGHT);
            data[10] = backPage;
            data[11] = 0;
            SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_4 | DISPCNT_BG2_ON | (backPage ? 0x10 : 0));

            if (zt >= PT_S10_ZOOM_FRAMES)
                data[9] = 2;
        }
    }
    // Phase 2: Pure black inside the portal -> smooth transition to Title Screen
    else
    {
        if (!gPaletteFade.active)
        {
            data[0] = 0;
            gTasks[taskId].func = Task_EndIntroMovie;
        }
    }
}
static void UNUSED Task_Scene2_Load(u8 taskId)
{
    IntroResetGpuRegs();
    SetVBlankCallback(NULL);
    ResetSpriteData();
    FreeAllSpritePalettes();
    gIntroCredits_MovingSceneryVBase = 0;
    gIntroCredits_MovingSceneryVOffset = 0;
    sFlygonYOffset = 0;
    LoadIntroPart2Graphics(1);
    gTasks[taskId].func = Task_Scene2_CreateSprites;
}

#define tBgAnimTaskId   data[0]
#define tPlayerSpriteId data[1]
#define tFlygonSpriteId data[2]
#define tFlygonTimer    data[3]

static void Task_Scene2_CreateSprites(u8 taskId)
{
    u8 spriteId;

    // Load sprite sheets
    if (sIntroCharacterGender == MALE)
        LoadCompressedSpriteSheet(gSpriteSheet_IntroBrendan);
    else
        LoadCompressedSpriteSheet(gSpriteSheet_IntroMay);

    LoadCompressedSpriteSheet(gSpriteSheet_IntroBicycle);
    LoadCompressedSpriteSheet(gSpriteSheet_IntroFlygon);

    // Load sprite palettes
    for (spriteId = 0; spriteId < ARRAY_COUNT(sSpriteSheet_RunningPokemon) - 1; spriteId++)
        LoadCompressedSpriteSheet(&sSpriteSheet_RunningPokemon[spriteId]);

    LoadSpritePalettes(gSpritePalettes_IntroPlayerFlygon);
    LoadSpritePalettes(sSpritePalettes_RunningPokemon);

    // Create Pokémon and player sprites
    CreateSprite(&sSpriteTemplate_Manectric, DISPLAY_WIDTH + 32, 128, 0);
    CreateSprite(&sSpriteTemplate_Torchic, DISPLAY_WIDTH + 48, 110, 1);

    if (sIntroCharacterGender == MALE)
        spriteId = CreateIntroBrendanSprite(DISPLAY_WIDTH + 32, 100);
    else
        spriteId = CreateIntroMaySprite(DISPLAY_WIDTH + 32, 100);

    gSprites[spriteId].callback = SpriteCB_PlayerOnBicycle;
    gSprites[spriteId].anims = sAnims_PlayerBicycle;
    gTasks[taskId].tPlayerSpriteId = spriteId;
    CreateSprite(&sSpriteTemplate_Volbeat, DISPLAY_WIDTH + 32, 80, 4);
    spriteId = CreateIntroFlygonSprite(-64, 60);
    gSprites[spriteId].callback = SpriteCB_Flygon;
    gTasks[taskId].tFlygonSpriteId = spriteId;

    // Fade in and start bike ride
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_WHITEALPHA);
    SetVBlankCallback(VBlankCB_Intro);
    gTasks[taskId].tBgAnimTaskId = CreateBicycleBgAnimationTask(1, 0x4000, 0x400, 0x10);
    SetIntroPart2BgCnt(1);
    gTasks[taskId].func = Task_Scene2_BikeRide;
}

static void Task_Scene2_BikeRide(u8 taskId)
{
    u16 offset;

    if (gIntroFrameCounter == TIMER_TORCHIC_EXIT)
    {
        // Stop the moving scenery/backgrounds, for when the camera fixes on Torchic
        gIntroCredits_MovingSceneryState = INTROCRED_SCENERY_FROZEN;
        DestroyTask(gTasks[taskId].tBgAnimTaskId);
    }

    if (gIntroFrameCounter > TIMER_END_SCENE_2)
    {
        // Fade out to next scene
        BeginNormalPaletteFade(PALETTES_ALL, 8, 0, 16, RGB_WHITEALPHA);
        gTasks[taskId].func = Task_Scene2_End;
    }

    // Check for updates to player/flygon sprites
    // These states are for SpriteCB_PlayerOnBicycle and SpriteCB_Flygon respectively
    if (gIntroFrameCounter == TIMER_PLAYER_DRIFT_BACK)
        gSprites[gTasks[taskId].tPlayerSpriteId].sState = 1;
    if (gIntroFrameCounter == TIMER_PLAYER_MOVE_FORWARD)
        gSprites[gTasks[taskId].tPlayerSpriteId].sState = 0;
    if (gIntroFrameCounter == TIMER_FLYGON_ENTER)
        gSprites[gTasks[taskId].tFlygonSpriteId].sState = 1;
    if (gIntroFrameCounter == TIMER_PLAYER_MOVE_BACKWARD)
        gSprites[gTasks[taskId].tPlayerSpriteId].sState = 2;
    if (gIntroFrameCounter == TIMER_PLAYER_HOLD_POSITION)
        gSprites[gTasks[taskId].tPlayerSpriteId].sState = 3;
    if (gIntroFrameCounter == TIMER_PLAYER_EXIT)
        gSprites[gTasks[taskId].tPlayerSpriteId].sState = 4;

    // Handle flygon's y movement
    offset = Sin(gTasks[taskId].tFlygonTimer >> 2 & 0x7F, 48);
    sFlygonYOffset = offset;
    if (gTasks[taskId].tFlygonTimer < 512)
        gTasks[taskId].tFlygonTimer++;

    // Alternate colors of the trees
    CycleSceneryPalette(0);
}

static void Task_Scene2_End(u8 taskId)
{
    if (gIntroFrameCounter > TIMER_START_SCENE_3)
        gTasks[taskId].func = Task_Scene3_Load;
}

#define sStateDelay data[1]
#define sNextState  data[2]
#define sCosYIdx    data[3]
#define sSinXIdx    data[4]
#define sSinYIdx    data[5]
#define sFig8Loops  data[6]

enum {
    VOLBEAT_WAIT_ENTER,
    VOLBEAT_ENTER,
    VOLBEAT_ZIP_BACKWARD,
    VOLBEAT_ZIP_DOWN,
    VOLBEAT_ZIP_FORWARD,
    VOLBEAT_INIT_FIGURE_8,
    VOLBEAT_FIGURE_8,
    VOLBEAT_EXIT,
    VOLBEAT_WAIT_STATE
};

static void SpriteCB_Volbeat(struct Sprite *sprite)
{
    sprite->sCosYIdx += 4;
    switch (sprite->sState)
    {
    case VOLBEAT_WAIT_ENTER:
        if (++sprite->sStateDelay < 180)
            break;
        sprite->sState++;
        // fallthrough
    case VOLBEAT_ENTER:
        sprite->x -= 4;
        if (sprite->x == 60)
        {
            sprite->sState = VOLBEAT_WAIT_STATE;
            sprite->sStateDelay = 20;
            sprite->sNextState = VOLBEAT_ZIP_BACKWARD;
        }
        break;
    case VOLBEAT_ZIP_BACKWARD:
        sprite->x += 8;
        sprite->y -= 2;
        if (sprite->x == 124)
        {
            sprite->sState = VOLBEAT_WAIT_STATE;
            sprite->sStateDelay = 20;
            sprite->sNextState = VOLBEAT_ZIP_DOWN;
        }
        break;
    case VOLBEAT_ZIP_DOWN:
        sprite->y += 4;
        if (sprite->y == 80)
        {
            sprite->sState = VOLBEAT_WAIT_STATE;
            sprite->sStateDelay = 10;
            sprite->sNextState = VOLBEAT_ZIP_FORWARD;
        }
        break;
    case VOLBEAT_ZIP_FORWARD:
        sprite->x -= 8;
        sprite->y -= 2;
        if (sprite->x == 60)
        {
            sprite->sState = VOLBEAT_WAIT_STATE;
            sprite->sStateDelay = 10;
            sprite->sNextState = VOLBEAT_INIT_FIGURE_8;
        }
        break;
    case VOLBEAT_INIT_FIGURE_8:
        sprite->x += 60;
        sprite->sSinXIdx = 0xC0;
        sprite->sSinYIdx = 0x80;
        sprite->sFig8Loops = 3;
        sprite->sState++;
        // fallthrough
    case VOLBEAT_FIGURE_8:
        sprite->x2 = Sin((u8)sprite->sSinXIdx, 0x3C);
        sprite->y2 = Sin((u8)sprite->sSinYIdx, 0x14);
        sprite->sSinXIdx += 2;
        sprite->sSinYIdx += 4;
        if ((sprite->sSinXIdx & 0xFF) == 64)
        {
            sprite->hFlip = FALSE;
            if (--sprite->sFig8Loops == 0)
            {
                sprite->x += sprite->x2;
                sprite->x2 = 0;
                sprite->sState++;
            }
        }
        break;
    case VOLBEAT_EXIT:
        sprite->x -= 2;
        sprite->y2 = Sin((u8)sprite->sSinYIdx, 0x14);
        sprite->sSinYIdx += 4;
        if (sprite->x < -16)
            DestroySprite(sprite);
        break;
    case VOLBEAT_WAIT_STATE:
        // Wait for state progression, fly idly until then
        sprite->y2 = Cos((u8)sprite->sCosYIdx, 2);
        if (!--sprite->sStateDelay)
            sprite->sState = sprite->sNextState;
        break;
    }
}

#undef sStateDelay
#undef sNextState
#undef sCosYIdx
#undef sSinXIdx
#undef sSinYIdx
#undef sFig8Loops

#define sMoveTimer data[1]
#define sDelay     data[2]

static void SpriteCB_Torchic(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        if (gIntroFrameCounter == TIMER_TORCHIC_ENTER)
        {
            StartSpriteAnim(sprite, TORCHIC_ANIM_RUN);
            sprite->sState++;
        }
        break;
    case 1:
        if (gIntroFrameCounter == TIMER_PLAYER_HOLD_POSITION)
        {
            StartSpriteAnim(sprite, TORCHIC_ANIM_WALK);
            sprite->sState++;
        }
        else
        {
            sprite->sMoveTimer += 64;
            if (sprite->sMoveTimer & 0xFF00)
            {
                sprite->x--;
                sprite->sMoveTimer &= 0xFF;
            }
        }
        break;
    case 2:
        if (gIntroFrameCounter != TIMER_TORCHIC_SPEED_UP)
        {
            sprite->sMoveTimer += 32;
            if (sprite->sMoveTimer & 0xFF00)
            {
                sprite->x++;
                sprite->sMoveTimer &= 0xFF;
            }
        }
        else
        {
            StartSpriteAnim(sprite, TORCHIC_ANIM_RUN);
            sprite->sState++;
            sprite->sDelay = 80;
        }
        break;
    case 3:
        if (--sprite->sDelay)
        {
            sprite->sMoveTimer += 64;
            if (sprite->sMoveTimer & 0xFF00)
            {
                sprite->x--;
                sprite->sMoveTimer &= 0xFF;
            }
        }
        else
        {
            StartSpriteAnim(sprite, TORCHIC_ANIM_TRIP);
            sprite->sState++;
        }
        break;
    case 4:
        if (sprite->animEnded)
            sprite->x += 4;

        if (sprite->x > 336)
        {
            StartSpriteAnim(sprite, TORCHIC_ANIM_RUN);
            sprite->sState++;
        }
        break;
    case 5:
        if (gIntroFrameCounter >= TIMER_TORCHIC_EXIT)
            sprite->x -= 2;
        break;
    }
}

#undef sMoveTimer
#undef sDelay

#define sSinIdx data[1]
#define sCosIdx data[2]

static void SpriteCB_Manectric(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        if (gIntroFrameCounter == TIMER_MANECTRIC_ENTER)
            sprite->sState++;
        break;
    case 1:
        sprite->x -= 2;
        if (gIntroFrameCounter != TIMER_MANECTRIC_RUN_CIRCULAR)
            break;

        // Initialize circular pattern running
        sprite->y -= 12;
        sprite->sSinIdx = 0x80;
        sprite->sCosIdx = 0;
        sprite->sState++;
        // fallthrough
    case 2:
        if (sprite->x + sprite->x2 <= -32)
        {
            // Manectric is offscreen now, destroy it
            DestroySprite(sprite);
        }
        else
        {
            // Run in circular pattern
            if ((sprite->sSinIdx & 0xFF) < 64)
            {
                sprite->x2 = Sin((u8)sprite->sSinIdx, 16);
            }
            else
            {
                if ((sprite->sSinIdx & 0xFF) == 64)
                    sprite->x -= 48;
                sprite->x2 = Sin((u8)sprite->sSinIdx, 64);
            }
            sprite->sSinIdx++;
            sprite->y2 = Cos((u8)sprite->sCosIdx, 12);
            sprite->sCosIdx++;
        }
        break;
    }
}

#undef sSinIdx
#undef sCosIdx

#define tAlpha        data[0]
#define tZoomDiv      data[1]
#define tZoomDivSpeed data[2]

static void Task_Scene3_Load(u8 taskId)
{
    IntroResetGpuRegs();
    DecompressDataWithHeaderVram(sIntroPokeball_Gfx, (void *)VRAM);
    DecompressDataWithHeaderVram(sIntroPokeball_Tilemap, (void *)(BG_CHAR_ADDR(1)));
    LoadPalette(sIntroPokeball_Pal, BG_PLTT_ID(0), sizeof(sIntroPokeball_Pal));
    gTasks[taskId].tAlpha = 0;
    gTasks[taskId].tZoomDiv = 0;
    gTasks[taskId].tZoomDivSpeed = 0;
    gTasks[taskId].data[3] = 0;
    PanFadeAndZoomScreen(DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, 0, 0);
    ResetSpriteData();
    FreeAllSpritePalettes();
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_WHITEALPHA);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(3) | BGCNT_CHARBASE(0) | BGCNT_SCREENBASE(8) | BGCNT_256COLOR | BGCNT_AFF256x256);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1 | DISPCNT_OBJ_1D_MAP | DISPCNT_BG2_ON | DISPCNT_OBJ_ON);
    gTasks[taskId].func = Task_Scene3_SpinPokeball;
    gIntroFrameCounter = 0;
    m4aSongNumStart(MUS_INTRO_BATTLE);
}
static void Task_Scene3_SpinPokeball(u8 taskId)
{
    gTasks[taskId].tAlpha += 0x400;

    if (gTasks[taskId].tZoomDiv <= 0x6BF)
    {
        gTasks[taskId].tZoomDiv += gTasks[taskId].tZoomDivSpeed;
        gTasks[taskId].tZoomDivSpeed += 2;
    }
    else
    {
        gTasks[taskId].func = Task_Scene3_WaitGroudon;
    }

    PanFadeAndZoomScreen(DISPLAY_WIDTH / 2, DISPLAY_HEIGHT / 2, SAFE_DIV(0x10000, gTasks[taskId].tZoomDiv), gTasks[taskId].tAlpha);

    if (gIntroFrameCounter == TIMER_POKEBALL_FADE)
        BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_WHITEALPHA);
}

#undef tAlpha
#undef tZoomDiv
#undef tZoomDivSpeed

static void Task_Scene3_WaitGroudon(u8 taskId)
{
    if (gIntroFrameCounter > TIMER_START_LEGENDARIES)
        gTasks[taskId].func = Task_Scene3_LoadGroudon;
}

static void Task_Scene3_LoadGroudon(u8 taskId)
{
    if (!gPaletteFade.active)
    {
        IntroResetGpuRegs();
        ResetSpriteData();
        FreeAllSpritePalettes();
        gReservedSpritePaletteCount = 8;
        DecompressDataWithHeaderVram(gIntroGroudon_Gfx, (void *)VRAM);
        DecompressDataWithHeaderVram(gIntroGroudon_Tilemap, (void *)(BG_CHAR_ADDR(3)));
        DecompressDataWithHeaderVram(gIntroLegendBg_Gfx, (void *)(BG_CHAR_ADDR(1)));
        DecompressDataWithHeaderVram(gIntroGroudonBg_Tilemap, (void *)(BG_SCREEN_ADDR(28)));
        LoadCompressedSpriteSheetUsingHeap(&gBattleAnimTable[GET_TRUE_SPRITE_INDEX(ANIM_TAG_ROCKS)].pic);
        LoadSpritePalette(&gBattleAnimTable[GET_TRUE_SPRITE_INDEX(ANIM_TAG_ROCKS)].palette);
        CpuCopy16(gIntro3Bg_Pal, gPlttBufferUnfaded, sizeof(gIntro3Bg_Pal));
        gTasks[taskId].func = Task_Scene3_InitGroudonBg;
    }
}

#define tWinPos  data[0]
#define tScreenX data[1]
#define tScreenY data[2]
#define tZoom    data[3]

static void Task_Scene3_InitGroudonBg(u8 taskId)
{
    SetGpuReg(REG_OFFSET_WIN0H, DISPLAY_WIDTH);
    SetGpuReg(REG_OFFSET_WIN0V, DISPLAY_HEIGHT);
    SetGpuReg(REG_OFFSET_WININ, WININ_WIN0_ALL);
    SetGpuReg(REG_OFFSET_WINOUT, 0);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(0)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(24)
                               | BGCNT_256COLOR
                               | BGCNT_WRAP
                               | BGCNT_AFF512x512);
    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(1)
                               | BGCNT_CHARBASE(1)
                               | BGCNT_SCREENBASE(28)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_1
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG1_ON
                                | DISPCNT_BG2_ON
                                | DISPCNT_OBJ_ON
                                | DISPCNT_WIN0_ON);
    BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_WHITEALPHA);
    gTasks[taskId].tWinPos = 0;
    gTasks[taskId].tScreenX = 0xFFA0;
    gTasks[taskId].tScreenY = 0xFF51;
    gTasks[taskId].tZoom = 0x100;
    PanFadeAndZoomScreen(gTasks[taskId].tScreenX, gTasks[taskId].tScreenY, gTasks[taskId].tZoom, 0);
    gTasks[taskId].func = Task_Scene3_NarrowWindow;
}

// Before the Groudon scene starts, the black top/bottom edges of the screen
// come inward for a more 'cinematic' look
#define NARROW_HEIGHT 32
static void Task_Scene3_NarrowWindow(u8 taskId)
{
    if (gTasks[taskId].tWinPos != NARROW_HEIGHT)
    {
        gTasks[taskId].tWinPos += 4;
        SetGpuReg(REG_OFFSET_WIN0V, (gTasks[taskId].tWinPos * 256) - (gTasks[taskId].tWinPos - DISPLAY_HEIGHT));
    }
    else
    {
        SetGpuReg(REG_OFFSET_WIN0V, WIN_RANGE(NARROW_HEIGHT, DISPLAY_HEIGHT - NARROW_HEIGHT));
        gTasks[taskId].func = Task_Scene3_EndNarrowWindow;
    }
}
#undef tWinPos
#undef tScreenX
#undef tScreenY
#undef tZoom

static void Task_Scene3_EndNarrowWindow(u8 taskId)
{
    gTasks[taskId].func = Task_Scene3_StartGroudon;
}

static void Task_Scene3_StartGroudon(u8 taskId)
{
    gTasks[taskId].tState = 0;
    gTasks[taskId].func = Task_Scene3_Groudon;
    ScanlineEffect_InitWave(0, DISPLAY_HEIGHT, 4, 4, 1, SCANLINE_EFFECT_REG_BG1HOFS, FALSE);
}

#define tScreenX data[1]
#define tScreenY data[2]
#define tZoom    data[3]
#define tYShake  data[4]
#define tTimer   data[5]
#define tDelay   data[6]
#define tTrigIdx data[6] // Re-used
#define tPalIdx  data[7]

// Treats gIntro3Bg_Pal as u8* and iterates by 1
#define INTRO3_RAW_PTR(palId)(((void *) &gIntro3Bg_Pal) + palId)

static void Task_Scene3_Groudon(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    tTimer++;
    if ((tState >= 1 && tState <= 7) && tTimer % 2 == 0)
        tYShake ^= 3;
    PanFadeAndZoomScreen(tScreenX, tScreenY + tYShake, tZoom, 0);
    switch (tState)
    {
    case 0:
        tScreenX += 16;
        if (tScreenX == 160)
        {
            tState++;
            tDelay = 2;
            tPalIdx = 0x1E2;
            CreateGroudonRockSprites(taskId);
        }
        break;
    case 1:
        if (--tDelay == 0)
        {
            tDelay = 2;
            CpuCopy16(INTRO3_RAW_PTR(tPalIdx), &gPlttBufferFaded[BG_PLTT_ID(1) + 15], PLTT_SIZEOF(1));
            tPalIdx += 2;
            if (tPalIdx == 0x1EC)
                tState++;
        }
        break;
    case 2:
        if (--tDelay == 0)
        {
            tDelay = 2;
            tState++;
        }
        break;
    case 3:
        if (--tDelay == 0)
        {
            tDelay = 2;
            CpuCopy16(INTRO3_RAW_PTR(tPalIdx), &gPlttBufferFaded[BG_PLTT_ID(1) + 15], PLTT_SIZEOF(1));
            tPalIdx -= 2;
            if (tPalIdx == 0x1E0)
            {
                tDelay = 8;
                tState++;
            }
        }
        break;
    case 4:
        if (--tDelay == 0)
        {
            tScreenX = -96;
            tScreenY = 169;
            tDelay = 3;
            tState++;
        }
        break;
    case 5:
        if (--tDelay == 0)
        {
            tScreenX = 80;
            tScreenY = 41;
            tDelay = 16;
            if (IsSpeciesEnabled(SPECIES_GROUDON))
                PlayCryInternal(SPECIES_GROUDON, 0, 100, CRY_PRIORITY_NORMAL, CRY_MODE_NORMAL);
            tState++;
        }
        break;
    case 6:
        if (--tDelay == 0)
        {
            tScreenX = 80;
            tScreenY = 40;
            tState++;
        }
        break;
    case 7:
        tScreenX += 4;
        tScreenY += 4;
        tTrigIdx += 0x666;
        tZoom = Sin((tTrigIdx & 0xFF00) >> 8, 64) + 256;
        if (tScreenX == 120)
        {
            BeginNormalPaletteFade(PALETTES_ALL & ~1, 3, 0, 16, RGB_WHITE);
            tZoom = 256;
            tYShake = 0;
            tState++;
        }
        break;
    case 8:
        if (tZoom)
            tZoom -= 8;
        else
            tState++;
        break;
    case 9:
        if (!gPaletteFade.active)
        {
            gTasks[taskId].func = Task_Scene3_LoadKyogre;
            gScanlineEffect.state = 3;
        }
        break;
    }
}

#undef tScreenX
#undef tScreenY
#undef tZoom
#undef tYShake
#undef tTimer
#undef tDelay
#undef tTrigIdx
#undef tPalIdx

#define sRockId data[1]
#define sSpeed  data[2]
#define sTimer  data[3]
#define sTaskId data[4]

static void CreateGroudonRockSprites(u8 taskId)
{
    int i;
    u8 spriteId;

    for (i = 0; i < (int)ARRAY_COUNT(sGroudonRockData); i++)
    {
        spriteId = CreateSprite(&gAncientPowerRockSpriteTemplate, sGroudonRockData[i][0], DISPLAY_HEIGHT, i);
        gSprites[spriteId].callback = SpriteCB_GroudonRocks;
        gSprites[spriteId].oam.priority = 0;
        gSprites[spriteId].sRockId = i;
        gSprites[spriteId].sTaskId = taskId;
        StartSpriteAnim(&gSprites[spriteId], sGroudonRockData[i][1]);
    }
}

static void SpriteCB_GroudonRocks(struct Sprite *sprite)
{
    // Introduce some wobble to the floating
    sprite->sTimer++;
    if (sprite->sTimer % 2 == 0)
        sprite->y2 ^= 3;

    switch (sprite->sState)
    {
    case 0:
        // Rock floats up
        sprite->sSpeed += sGroudonRockData[sprite->sRockId][2];
        sprite->y -= (sprite->sSpeed & 0xFF00) >> 8;
        sprite->sSpeed &= 0xFF;

        // Check if Groudon scene is ending
        if (gTasks[sprite->sTaskId].tState > 7)
            sprite->sState++;
        break;
    case 1:
        // Scene zooms in, move rock offscreen
        if (sprite->x < DISPLAY_WIDTH / 2)
            sprite->x -= 2;
        else
            sprite->x += 2;

        if (sprite->y < DISPLAY_HEIGHT / 2)
            sprite->y -= 2;
        else
            sprite->y += 2;
        break;
    }
}

#undef sRockId
#undef sSpeed
#undef sTimer
#undef sTaskId

#define tScreenX data[1]
#define tScreenY data[2]
#define tZoom    data[3]
#define tDelay   data[6]
#define tTrigIdx data[6] // Re-used
#define tPalIdx  data[7]

static void Task_Scene3_LoadKyogre(u8 taskId)
{
    ResetSpriteData();
    DecompressDataWithHeaderVram(gIntroKyogre_Gfx, (void *)VRAM);
    DecompressDataWithHeaderVram(gIntroKyogre_Tilemap, (void *)(BG_CHAR_ADDR(3)));
    DecompressDataWithHeaderVram(gIntroKyogreBg_Tilemap, (void *)(BG_SCREEN_ADDR(28)));
    LoadCompressedSpriteSheet(sSpriteSheet_Bubbles);
    LoadSpritePalette(sSpritePalette_Bubbles);
    BeginNormalPaletteFade(PALETTES_ALL & ~1, 0, 16, 0, RGB_WHITEALPHA);
    gTasks[taskId].func = Task_Scene3_Kyogre;
    gTasks[taskId].tState = 0;
    gTasks[taskId].tScreenX = 336;
    gTasks[taskId].tScreenY = 80;
    gTasks[taskId].tDelay = 16;
    gTasks[taskId].tZoom = 256;
    PanFadeAndZoomScreen(gTasks[taskId].tScreenX, gTasks[taskId].tScreenY, gTasks[taskId].tZoom, 0);
    ScanlineEffect_InitWave(0, DISPLAY_HEIGHT, 4, 4, 1, SCANLINE_EFFECT_REG_BG1VOFS, FALSE);
}

static void Task_Scene3_Kyogre(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    PanFadeAndZoomScreen(tScreenX, tScreenY, tZoom, 0);

    switch (tState)
    {
    case 0:
        if (--tDelay != 0)
            break;
        tState++;
    case 1:
        tTrigIdx += 4;
        gTasks[taskId].tScreenX = 344 - Sin(tTrigIdx, 0x100);
        gTasks[taskId].tScreenY = 84 - Cos(tTrigIdx, 0x40);
        if (tTrigIdx == 64)
        {
            tDelay = 0x19;
            tPalIdx = 1;
            tState++;
            CreateKyogreBubbleSprites_Body(0);
        }
        break;
    case 2:
        if (--tDelay == 0)
        {
            gTasks[taskId].tScreenX += 256;
            gTasks[taskId].tScreenY -= 258;
            tDelay = 8;
            tState++;
            CreateKyogreBubbleSprites_Body(0);
            CreateKyogreBubbleSprites_Fins();
        }
        break;
    case 3:
        if (--tDelay == 0)
        {
            gTasks[taskId].tScreenX -= 256;
            gTasks[taskId].tScreenY += 258;
            tDelay = 8;
            tState++;
        }
        break;
    case 4:
        if (--tDelay == 0)
        {
            gTasks[taskId].tScreenY -= 252;
            tDelay = 8;
            tState++;
        }
        break;
    case 5:
        if (--tDelay == 0)
        {
            gTasks[taskId].tScreenY += 252;
            if (tPalIdx != 0)
            {
                tDelay = 12;
                tPalIdx--;
                tState = 2;
            }
            else
            {
                tDelay = 1;
                tState++;
                if (IsSpeciesEnabled(SPECIES_KYOGRE))
                    PlayCryInternal(SPECIES_KYOGRE, 0, 120, CRY_PRIORITY_NORMAL, CRY_MODE_NORMAL);
            }
        }
        break;
    case 6:
        if (--tDelay == 0)
        {
            tDelay = 4;
            tPalIdx = 0x1EA;
            tState++;
        }
        break;
    case 7:
        if (--tDelay == 0)
        {
            tDelay = 4;
            CpuCopy16(INTRO3_RAW_PTR(tPalIdx), &gPlttBufferFaded[BG_PLTT_ID(2) + 15], PLTT_SIZEOF(1));
            tPalIdx -= 2;
            if (tPalIdx == 0x1E0)
                tState++;
        }
        break;
    case 8:
        if (--tDelay == 0)
        {
            tDelay = 4;
            tPalIdx = 0x1E2;
            tState++;
        }
        break;
    case 9:
        if (--tDelay == 0)
        {
            tDelay = 4;
            CpuCopy16(INTRO3_RAW_PTR(tPalIdx), &gPlttBufferFaded[BG_PLTT_ID(2) + 15], PLTT_SIZEOF(1));
            tPalIdx += 2;
            if (tPalIdx == 0x1EE)
            {
                tDelay = 16;
                tState++;
            }
        }
        break;
    case 10:
        if (--tDelay == 0)
        {
            tTrigIdx = 0;
            tState++;
            CreateKyogreBubbleSprites_Body(taskId);
        }
        break;
    case 11:
        tTrigIdx += 4;
        tZoom -= 8;
        gTasks[taskId].tScreenX = Sin(tTrigIdx, 0x3C) + 88;
        if (tTrigIdx == 64)
        {
            BeginNormalPaletteFade(PALETTES_ALL & ~1, 3, 0, 16, RGB_WHITE);
            tState++;
        }
        break;
    case 12:
        tTrigIdx += 4;
        tZoom -= 8;
        gTasks[taskId].tScreenX = Sin(tTrigIdx, 0x14) + 128;
        if (tTrigIdx == 128)
            tState++;
        break;
    case 13:
        if (!gPaletteFade.active)
        {
            gTasks[taskId].func = Task_Scene3_LoadClouds1;
            gScanlineEffect.state = 3;
        }
        break;
    }
}

#undef tScreenX
#undef tScreenY
#undef tZoom
#undef tDelay
#undef tTrigIdx
#undef tPalIdx

#define sSinIdx data[1]
#define sBaseY  data[2]
#define sTaskId data[5]
#define sDelay  data[6]
#define sUnk    data[7] // Never read

// taskId is used inconsistently for these two functions.
// The sprite callback for the bubbles will always read it, unless delay is 0 to
// start (it never is), but the first function is often passed 0 instead of a
// taskId, and the second function doesn't take/assign a taskId at all.
// The only time an actual taskId is given is when it actually needs the
// result of reading it, to zoom in at the end of the scene.

// Creates bubbles at positions spread across Kyogre's body
static void CreateKyogreBubbleSprites_Body(u8 taskId)
{
    int i;
    u8 spriteId;

    for (i = 0; i < NUM_BUBBLES_IN_SET; i++)
    {
        spriteId = CreateSprite(&sSpriteTemplate_Bubbles,
                                sKyogreBubbleData[i][0],
                                sKyogreBubbleData[i][1],
                                i);
        gSprites[spriteId].invisible = TRUE;
        gSprites[spriteId].sTaskId = taskId;
        gSprites[spriteId].sDelay = sKyogreBubbleData[i][2];
        gSprites[spriteId].sUnk = 64;
    }
}

// Creates bubbles at positions around Kyogre's fins, for when it's moving them
static void CreateKyogreBubbleSprites_Fins(void)
{
    int i;
    u8 spriteId;

    for (i = 0; i < NUM_BUBBLES_IN_SET; i++)
    {
        spriteId = CreateSprite(&sSpriteTemplate_Bubbles,
                                sKyogreBubbleData[i + NUM_BUBBLES_IN_SET][0],
                                sKyogreBubbleData[i + NUM_BUBBLES_IN_SET][1],
                                i);
        gSprites[spriteId].invisible = TRUE;
#ifdef BUGFIX
        gSprites[spriteId].sDelay = sKyogreBubbleData[i + NUM_BUBBLES_IN_SET][2];
#else
        gSprites[spriteId].sDelay = sKyogreBubbleData[i][2]; // Using the wrong set of delays here
#endif
        gSprites[spriteId].sUnk = 64;
    }
}

static void SpriteCB_KyogreBubbles(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        if (sprite->sDelay == 0)
        {
            // Animation has started, float bubbles up
            sprite->sSinIdx = (sprite->sSinIdx + 11) & 0xFF;
            sprite->x2 = Sin(sprite->sSinIdx, 4);
            sprite->sBaseY += 48;
            sprite->y2 = -(sprite->sBaseY >> 8);
            if (sprite->animEnded)
                DestroySprite(sprite);
        }
        else if (--sprite->sDelay == 0)
        {
            // Start bubble animation after delay has finished
            StartSpriteAnim(sprite, 0);
            sprite->invisible = FALSE;
        }

        // Check if Kyogre scene is ending
        // For all but the last bubbles, sTaskId isn't actually set
        if (gTasks[sprite->sTaskId].tState > 11)
            sprite->sState++;
        break;
    case 1:
        // Scene zooms in, move bubbles offscreen
        if (sprite->x < DISPLAY_WIDTH / 2)
            sprite->x -= 3;
        else
            sprite->x += 3;

        if (sprite->y < DISPLAY_HEIGHT / 2)
            sprite->y -= 3;
        else
            sprite->y += 3;

        if ((u16)(sprite->y - 20) > DISPLAY_HEIGHT - 20)
            DestroySprite(sprite);
        break;
    }
}

#undef sSinIdx
#undef sBaseY
#undef sTaskId
#undef sDelay
#undef sUnk

static void Task_Scene3_LoadClouds1(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BLDCNT, BLDCNT_TGT1_BG0
                               | BLDCNT_TGT1_BG1
                               | BLDCNT_TGT1_BG2
                               | BLDCNT_EFFECT_LIGHTEN);
    SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(31, 31));
    SetGpuReg(REG_OFFSET_BLDY, 31);
    SetGpuReg(REG_OFFSET_BG0CNT, BGCNT_PRIORITY(0)
                               | BGCNT_CHARBASE(0)
                               | BGCNT_SCREENBASE(24)
                               | BGCNT_16COLOR
                               | BGCNT_TXT512x256);
    SetGpuReg(REG_OFFSET_BG1CNT, BGCNT_PRIORITY(0)
                               | BGCNT_CHARBASE(1)
                               | BGCNT_SCREENBASE(26)
                               | BGCNT_16COLOR
                               | BGCNT_TXT512x256);
    SetGpuReg(REG_OFFSET_BG2CNT, BGCNT_PRIORITY(2)
                               | BGCNT_CHARBASE(1)
                               | BGCNT_SCREENBASE(28)
                               | BGCNT_16COLOR
                               | BGCNT_TXT256x256);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG0_ON
                                | DISPCNT_BG1_ON
                                | DISPCNT_BG2_ON
                                | DISPCNT_OBJ_ON
                                | DISPCNT_WIN0_ON);
    SetGpuReg(REG_OFFSET_BG0HOFS, 80);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, -80);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    DecompressDataWithHeaderVram(gIntroClouds_Gfx, (void *)VRAM);
    DecompressDataWithHeaderVram(gIntroClouds_Gfx, (void *)(BG_CHAR_ADDR(1)));
    DecompressDataWithHeaderVram(gIntroCloudsSun_Tilemap, (void *)(BG_SCREEN_ADDR(28)));
    gTasks[taskId].func = Task_Scene3_LoadClouds2;
}

static void Task_Scene3_LoadClouds2(u8 taskId)
{
    DecompressDataWithHeaderVram(gIntroCloudsLeft_Tilemap, (void *)(BG_CHAR_ADDR(3)));
    DecompressDataWithHeaderVram(gIntroCloudsRight_Tilemap, (void *)(BG_SCREEN_ADDR(26)));
    gTasks[taskId].func = Task_Scene3_InitClouds;
}

#define tCloudPos data[6]

static void Task_Scene3_InitClouds(u8 taskId)
{
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
    gTasks[taskId].func = Task_Scene3_Clouds;
    gTasks[taskId].tState = 0;
    gTasks[taskId].tCloudPos = 16;
}

// Clouds coming in from the sides before Rayquaza appears
static void Task_Scene3_Clouds(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    // Left clouds are on BG0, right clouds are on BG1
    SetGpuReg(REG_OFFSET_BG0HOFS, (tCloudPos >> 8));
    SetGpuReg(REG_OFFSET_BG1HOFS, -(tCloudPos >> 8));

    switch (tState)
    {
    case 0:
        // Cloud position is used briefly as a delay, before
        // the scene has faded in from white
        if (--tCloudPos == 0)
        {
            // Start fade in from white, set cloud starting positions
            BeginNormalPaletteFade(PALETTES_ALL & ~1, 0, 16, 0, RGB_WHITEALPHA);
            tCloudPos = 80 << 8;
            tState++;
        }
        break;
    case 1:
        // Start fading out
        if (tCloudPos == 40 << 8)
            BeginNormalPaletteFade(PALETTES_BG & ~1, 3, 0, 16, RGB(9, 10, 10));

        // Move clouds inward toward each other
        if (tCloudPos != 0)
            tCloudPos -= 128;
        else if (!gPaletteFade.active)
            gTasks[taskId].func = Task_Scene3_LoadLightning;
        break;
    }
}
#undef tCloudPos

#define tDelay data[6]
#define tTimer data[7]

static void Task_Scene3_LoadLightning(u8 taskId)
{
    DecompressDataWithHeaderVram(gIntroRayquaza_Tilemap, (void *)(BG_SCREEN_ADDR(28)));
    DecompressDataWithHeaderVram(gIntroRayquazaClouds_Tilemap, (void *)(BG_CHAR_ADDR(3)));
    DecompressDataWithHeaderVram(gIntroRayquaza_Gfx, (void *)(BG_CHAR_ADDR(1)));
    DecompressDataWithHeaderVram(gIntroRayquazaClouds_Gfx, (void *)VRAM);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG0_ON
                                | DISPCNT_BG2_ON
                                | DISPCNT_OBJ_ON
                                | DISPCNT_WIN0_ON);
    gTasks[taskId].func = Task_Scene3_Lightning;
    gTasks[taskId].tState = 0;
    gTasks[taskId].tDelay = 1;
    gTasks[taskId].tTimer = 0;
    LoadCompressedSpriteSheetUsingHeap(sSpriteSheet_Lightning);
    LoadSpritePalettes(sSpritePalette_Lightning);
}

static void Task_Scene3_Lightning(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u8 spriteId;

    switch (tState)
    {
    case 0:
        if (--tDelay == 0)
        {
            // Do first lightning bolt
            CreateSprite(&sSpriteTemplate_Lightning, 200, 48, 0);
            spriteId = CreateSprite(&sSpriteTemplate_Lightning, 200, 80, 1);
            StartSpriteAnim(&gSprites[spriteId], 1);
            spriteId = CreateSprite(&sSpriteTemplate_Lightning, 200, 112, 2);
            StartSpriteAnim(&gSprites[spriteId], 2);
            tState++;
            tDelay = 72;
        }
        break;
    case 1:
        if (--tDelay == 0)
        {
            // Do second lightning bolt
            CreateSprite(&sSpriteTemplate_Lightning, 40, 48, 0);
            spriteId = CreateSprite(&sSpriteTemplate_Lightning, 40, 80, 1);
            StartSpriteAnim(&gSprites[spriteId], 1);
            spriteId = CreateSprite(&sSpriteTemplate_Lightning, 40, 112, 2);
            StartSpriteAnim(&gSprites[spriteId], 2);
            tState++;
            tDelay = 48;
        }
        break;
    case 2:
        if (--tDelay == 0)
            gTasks[taskId].func = Task_Scene3_LoadRayquazaAttack;
        break;
    }
}

#define sPalIdx data[1]
#define sDelay data[2]

static void SpriteCB_Lightning(struct Sprite *sprite)
{
    if (sprite->animEnded)
        sprite->invisible = TRUE;

    switch (sprite->sState)
    {
    case 0:
        sprite->sPalIdx = 0x1C2;
        sprite->sState++;
    case 1:
        CpuCopy16(INTRO3_RAW_PTR(sprite->sPalIdx), &gPlttBufferFaded[BG_PLTT_ID(5) + 13], PLTT_SIZEOF(1));
        sprite->sPalIdx += 2;
        if (sprite->sPalIdx != 0x1CE)
            break;
        sprite->sPalIdx = 0x1CC;
        sprite->sDelay = 4;
        sprite->sState++;
    case 2:
        if (--sprite->sDelay == 0)
        {
            sprite->sDelay = 4;
            CpuCopy16(INTRO3_RAW_PTR(sprite->sPalIdx), &gPlttBufferFaded[BG_PLTT_ID(5) + 13], PLTT_SIZEOF(1));
            sprite->sPalIdx -= 2;
            if (sprite->sPalIdx == 0x1C0)
                DestroySprite(sprite);
        }
        break;
    }
}

#undef sPalIdx
#undef sDelay

#define tRayquazaTaskId data[4]

static void Task_Scene3_LoadRayquazaAttack(u8 taskId)
{
    u8 attackTaskId;

    LoadCompressedSpriteSheet(sSpriteSheet_RayquazaOrb);
    LoadSpritePalettes(sSpritePalette_RayquazaOrb);
    SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0
                                | DISPCNT_OBJ_1D_MAP
                                | DISPCNT_BG0_ON
                                | DISPCNT_BG2_ON
                                | DISPCNT_OBJ_ON
                                | DISPCNT_WIN0_ON);
    gTasks[taskId].func = Task_Scene3_Rayquaza;
    BeginNormalPaletteFade(PALETTES_BG & ~(0x21), 0, 16, 0, RGB(9, 10, 10));
    gTasks[taskId].tState = 0;
    gTasks[taskId].data[1] = 0xA8;
    gTasks[taskId].data[2] = -0x10;
    gTasks[taskId].data[3] = -0x88;
    gTasks[taskId].data[4] = -0x10;
    attackTaskId = CreateTask(Task_RayquazaAttack, 0);
    gTasks[attackTaskId].tRayquazaTaskId = taskId;
}

static void Task_Scene3_Rayquaza(u8 taskId)
{
    s16 *data = gTasks[taskId].data;

    if (tTimer % 2 == 0)
        data[6] ^= 2;

    tTimer++;

    switch (tState)
    {
    case 0:
        if ((tTimer & 1) != 0)
        {
            data[1] -= 2;
            data[2]++;
            data[3] += 2;
            data[4]++;
        }
        if (data[1] == 0x68)
        {
            tState++;
            data[5] = 1;
        }
        break;
    case 1:
        tState++;
        data[5] = 4;
        break;
    case 2:
        data[1] += 4;
        data[2] -= 2;
        data[3] -= 4;
        data[4] -= 2;
        if (!gPaletteFade.active)
        {
            data[5] = 0x8C;
            tState++;
        }
        break;
    case 3:
        if (--data[5] == 0)
            gTasks[taskId].func = Task_EndIntroMovie;
        break;
    }
}
#undef tDelay
#undef tTimer

static void Task_EndIntroMovie(u8 taskId)
{
    DestroyTask(taskId);
    SetMainCallback2(MainCB2_EndIntro);
}

static void Task_RayquazaAttack(u8 taskId)
{
    u8 spriteId;
    s16 *data = gTasks[taskId].data;
    data[2]++;

    switch (tState)
    {
    case 0:
        if ((data[2] & 1) != 0)
        {
            CpuCopy16(INTRO3_RAW_PTR(0x1A2 + data[1] * 2), &gPlttBufferFaded[BG_PLTT_ID(5) + 14], PLTT_SIZEOF(1));
            data[1]++;
        }
        if (data[1] == 6)
        {
            tState++;
            data[1] = 0;
            data[3] = 10;
        }
        break;
    case 1:
        if (data[3] == 0)
        {
            if ((data[2] & 1) != 0)
            {
                CpuCopy16(INTRO3_RAW_PTR(0x1A2 + data[1] * 2), &gPlttBufferFaded[BG_PLTT_ID(5) + 8], PLTT_SIZEOF(1));
                data[1]++;
            }
            if (data[1] == 6)
            {
                tState++;
                data[3] = 10;
            }
        }
        else
        {
            data[3]--;
        }
        break;
    case 2:
        if (data[3] == 0)
        {
            if ((data[2] & 1) != 0)
            {
                CpuCopy16(INTRO3_RAW_PTR(0x182 + data[1] * 2), &gPlttBufferFaded[BG_PLTT_ID(5) + 12], PLTT_SIZEOF(1));
                data[1]++;
            }
            if (data[1] == 6)
            {
                spriteId = CreateSprite(&sSpriteTemplate_RayquazaOrb, 120, 88, 15);
                PlaySE(SE_INTRO_BLAST);
                gSprites[spriteId].invisible = TRUE;
                gSprites[spriteId].data[3] = tRayquazaTaskId;
                tState++;
                data[3] = 16;
            }
        }
        else
        {
            data[3]--;
        }
        break;
    case 3:
        if ((data[2] & 1) != 0)
        {
            if (--data[3] != 0)
            {
                BlendPalette(BG_PLTT_ID(5), 16, data[3], RGB(9, 10, 10));
                CpuCopy16(INTRO3_RAW_PTR(428), &gPlttBufferFaded[BG_PLTT_ID(5) + 14], PLTT_SIZEOF(1));
                CpuCopy16(INTRO3_RAW_PTR(428), &gPlttBufferFaded[BG_PLTT_ID(5) + 8], PLTT_SIZEOF(1));
                CpuCopy16(INTRO3_RAW_PTR(396), &gPlttBufferFaded[BG_PLTT_ID(5) + 12], PLTT_SIZEOF(1));
            }
            else
            {
                tState++;
                data[3] = 53;
            }
        }
        break;
    case 4:
        if (--data[3] == 0)
        {
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_WHITE);
            tState++;
        }
        break;
    case 5:
        if (!gPaletteFade.active)
            DestroyTask(taskId);
        break;
    }
}

static void IntroResetGpuRegs(void)
{
    SetGpuReg(REG_OFFSET_DISPCNT, 0);
    SetGpuReg(REG_OFFSET_BG3HOFS, 0);
    SetGpuReg(REG_OFFSET_BG3VOFS, 0);
    SetGpuReg(REG_OFFSET_BG2HOFS, 0);
    SetGpuReg(REG_OFFSET_BG2VOFS, 0);
    SetGpuReg(REG_OFFSET_BG1HOFS, 0);
    SetGpuReg(REG_OFFSET_BG1VOFS, 0);
    SetGpuReg(REG_OFFSET_BG0HOFS, 0);
    SetGpuReg(REG_OFFSET_BG0VOFS, 0);
    SetGpuReg(REG_OFFSET_BLDCNT, 0);
    SetGpuReg(REG_OFFSET_BLDALPHA, 0);
    SetGpuReg(REG_OFFSET_BLDY, 0);
}

void PanFadeAndZoomScreen(u16 screenX, u16 screenY, u16 zoom, u16 alpha)
{
    struct BgAffineSrcData src;
    struct BgAffineDstData dest;

    src.texX = 0x8000;
    src.texY = 0x8000;
    src.scrX = screenX;
    src.scrY = screenY;
    src.sx = zoom;
    src.sy = zoom;
    src.alpha = alpha;
    BgAffineSet(&src, &dest, 1);
    SetGpuReg(REG_OFFSET_BG2PA, dest.pa);
    SetGpuReg(REG_OFFSET_BG2PB, dest.pb);
    SetGpuReg(REG_OFFSET_BG2PC, dest.pc);
    SetGpuReg(REG_OFFSET_BG2PD, dest.pd);
    SetGpuReg(REG_OFFSET_BG2X_L, dest.dx);
    SetGpuReg(REG_OFFSET_BG2X_H, dest.dx >> 16);
    SetGpuReg(REG_OFFSET_BG2Y_L, dest.dy);
    SetGpuReg(REG_OFFSET_BG2Y_H, dest.dy >> 16);
}

// State is handled by Task_Scene2_BikeRide
static void SpriteCB_PlayerOnBicycle(struct Sprite *sprite)
{
    // Adjust x position
    switch (sprite->sState)
    {
    case 0:
        // Move forwards
        StartSpriteAnimIfDifferent(sprite, 0);
        sprite->x--;
        break;
    case 1:
        // Drift backwards slowly
        StartSpriteAnimIfDifferent(sprite, 0);
        if (gIntroFrameCounter & 7)
            return;
        sprite->x++;
        break;
    case 2:
        // Move backwards
        if (sprite->x <= 120 || gIntroFrameCounter & 7)
            sprite->x++;
        break;
    case 3:
        // Bike in place
        break;
    case 4:
        // Exit to the left
        if (sprite->x > -32)
            sprite->x -= 2;
        break;
    }

    if (gIntroFrameCounter & 7)
        return;

    // Adjust y position
    if (sprite->y2 != 0)
    {
        // Return to neutral after wobble
        sprite->y2 = 0;
    }
    else
    {
        // Random wobble on y axis
        switch (Random() & 3)
        {
        case 0:
            sprite->y2 = -1;
            break;
        case 1:
            sprite->y2 = 1;
            break;
        case 2:
        case 3:
            sprite->y2 = 0;
            break;
        }
    }
}

#define sSinIdx data[1]

// Movement is started by setting state to 1 in Task_Scene2_BikeRide
static void SpriteCB_Flygon(struct Sprite *sprite)
{
    switch (sprite->sState)
    {
    case 0:
        break;
    case 1:
        if (sprite->x2 + sprite->x < DISPLAY_WIDTH + 64)
            sprite->x2 += 8;
        else
            sprite->sState = 2;
        break;
    case 2:
        if (sprite->x2 + sprite->x > 120)
            sprite->x2 -= 1;
        else
            sprite->sState = 3;
        break;
    case 3:
        if (sprite->x2 > 0)
            sprite->x2 -= 2;
        break;
    }
    sprite->y2 = Sin((u8)sprite->sSinIdx, 8) - sFlygonYOffset;
    sprite->sSinIdx += 4;
}

#undef sSinIdx

static void SpriteCB_RayquazaOrb(struct Sprite *sprite)
{
    u16 foo;
    switch (sprite->sState)
    {
    case 0:
    default:
        sprite->invisible = FALSE;
        sprite->oam.affineMode = ST_OAM_AFFINE_DOUBLE;
        sprite->oam.matrixNum = 18;
        CalcCenterToCornerVec(sprite, SPRITE_SHAPE(64x64), SPRITE_SIZE(64x64), ST_OAM_AFFINE_DOUBLE);
        sprite->data[1] = 0;
        sprite->sState = 1;
        //fall through
    case 1:
        sprite->data[7]++;
        if (sprite->data[7] & 1)
        {
            sprite->invisible = TRUE;
        }
        else
        {
            sprite->invisible = FALSE;
            if (sprite->data[1] < 64)
                sprite->data[1]++;
        }
        foo = 256 - gSineTable[(u8)sprite->data[1]] / 2;
        SetOamMatrix(18, foo, 0, 0, foo);
        break;
    }
}
