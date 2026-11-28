#include "global.h"
#include "config/save.h"
#include "battle_pike.h"
#include "battle_pyramid.h"
#include "battle_pyramid_bag.h"
#include "bg.h"
#include "debug.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_object_lock.h"
#include "event_scripts.h"
#include "fieldmap.h"
#include "field_effect.h"
#include "field_player_avatar.h"
#include "field_specials.h"
#include "field_weather.h"
#include "field_screen_effect.h"
#include "frontier_pass.h"
#include "frontier_util.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item_menu.h"
#include "link.h"
#include "load_save.h"
#include "main.h"
#include "menu.h"
#include "new_game.h"
#include "option_menu.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "pokedex.h"
#include "pokenav.h"
#include "safari_zone.h"
#include "save.h"
#include "scanline_effect.h"
#include "script.h"
#include "sound.h"
#include "start_menu.h"
#if START_MENU_USE_ICONS
#include "sprite.h"
#endif
#include "strings.h"
#include "string_util.h"
#include "task.h"
#include "text.h"
#include "text_window.h"
#include "trainer_card.h"
#include "window.h"
#include "union_room.h"
#include "dexnav.h"
#include "wild_encounter.h"
#include "constants/battle_frontier.h"
#include "constants/rgb.h"
#include "constants/songs.h"

// Menu actions
enum
{
    MENU_ACTION_POKEDEX,
    MENU_ACTION_POKEMON,
    MENU_ACTION_BAG,
    MENU_ACTION_POKENAV,
    MENU_ACTION_PLAYER,
    MENU_ACTION_SAVE,
    MENU_ACTION_OPTION,
    MENU_ACTION_EXIT,
    MENU_ACTION_RETIRE_SAFARI,
    MENU_ACTION_PLAYER_LINK,
    MENU_ACTION_REST_FRONTIER,
    MENU_ACTION_RETIRE_FRONTIER,
    MENU_ACTION_PYRAMID_BAG,
    MENU_ACTION_DEBUG,
    MENU_ACTION_DEXNAV,
};

// Save status
enum
{
    SAVE_IN_PROGRESS,
    SAVE_SUCCESS,
    SAVE_CANCELED,
    SAVE_ERROR
};

// IWRAM common
COMMON_DATA bool8 (*gMenuCallback)(void) = NULL;

// EWRAM
EWRAM_DATA static u8 sSafariBallsWindowId = 0;
EWRAM_DATA static u8 sBattlePyramidFloorWindowId = 0;
EWRAM_DATA static u8 sStartMenuCursorPos = 0;
EWRAM_DATA static u8 sNumStartMenuActions = 0;
EWRAM_DATA static u8 sCurrentStartMenuActions[9] = {0};
EWRAM_DATA static s8 sInitStartMenuData[2] = {0};

EWRAM_DATA static u8 (*sSaveDialogCallback)(void) = NULL;
EWRAM_DATA static u8 sSaveDialogTimer = 0;
EWRAM_DATA static bool8 sSavingComplete = FALSE;
EWRAM_DATA static u8 sSaveInfoWindowId = 0;

// Menu action callbacks
static bool8 StartMenuPokedexCallback(void);
static bool8 StartMenuPokemonCallback(void);
static bool8 StartMenuBagCallback(void);
static bool8 StartMenuPokeNavCallback(void);
static bool8 StartMenuPlayerNameCallback(void);
static bool8 StartMenuSaveCallback(void);
static bool8 StartMenuOptionCallback(void);
static bool8 StartMenuExitCallback(void);
static bool8 StartMenuSafariZoneRetireCallback(void);
static bool8 StartMenuLinkModePlayerNameCallback(void);
static bool8 StartMenuBattlePyramidRetireCallback(void);
static bool8 StartMenuBattlePyramidBagCallback(void);
static bool8 StartMenuDebugCallback(void);
static bool8 StartMenuDexNavCallback(void);

// Menu callbacks
static bool8 SaveStartCallback(void);
static bool8 SaveCallback(void);
static bool8 BattlePyramidRetireStartCallback(void);
static bool8 BattlePyramidRetireReturnCallback(void);
static bool8 BattlePyramidRetireCallback(void);
static bool8 HandleStartMenuInput(void);

// Save dialog callbacks
static u8 SaveConfirmSaveCallback(void);
static u8 SaveYesNoCallback(void);
static u8 SaveConfirmInputCallback(void);
static u8 SaveFileExistsCallback(void);
static u8 SaveConfirmOverwriteDefaultNoCallback(void);
static u8 SaveConfirmOverwriteCallback(void);
static u8 SaveOverwriteInputCallback(void);
static u8 SaveSavingMessageCallback(void);
static u8 SaveDoSaveCallback(void);
static u8 SaveSuccessCallback(void);
static u8 SaveReturnSuccessCallback(void);
static u8 SaveErrorCallback(void);
static u8 SaveReturnErrorCallback(void);
static u8 BattlePyramidConfirmRetireCallback(void);
static u8 BattlePyramidRetireYesNoCallback(void);
static u8 BattlePyramidRetireInputCallback(void);

// Task callbacks
static void StartMenuTask(u8 taskId);
static void SaveGameTask(u8 taskId);
static void Task_SaveAfterLinkBattle(u8 taskId);
static void Task_WaitForBattleTowerLinkSave(u8 taskId);
static bool8 FieldCB_ReturnToFieldStartMenu(void);

#if START_MENU_USE_ICONS
#define START_MENU_ICON_FRAMES 16
#define START_MENU_ICON_POSITION_COUNT 9
#define START_MENU_HIGHLIGHT_SPRITE_COUNT 2

static const u32 sStartMenuIconsGfx[] = INCBIN_U32("graphics/interface/start_menu_icons.4bpp");
static const u16 sStartMenuIconsPal[] = INCBIN_U16("graphics/interface/start_menu_icons.gbapal");

// The selection frame is split across two adjacent 64x32 OBJ sprites.
static const u32 sStartMenuHighlightGfx[] =
    INCBIN_U32("graphics/interface/start_menu_frame.4bpp");
static const u16 sStartMenuHighlightPal[] =
    INCBIN_U16("graphics/interface/start_menu_frame.gbapal");

static const struct SpritePalette sStartMenuHighlightPalette =
{
    .data = sStartMenuHighlightPal,
    .tag = START_MENU_FRAME_PALETTE_TAG,
};

static const struct SpriteFrameImage sStartMenuHighlightFrames[2] =
{
    overworld_frame(sStartMenuHighlightGfx, 8, 4, 0),
    overworld_frame(sStartMenuHighlightGfx, 8, 4, 1),
};

// Each half explicitly selects its own image from the frame sheet.
static const union AnimCmd sStartMenuHighlightAnimLeft[] =
{
    ANIMCMD_FRAME(0, 1),
    ANIMCMD_END,
};

static const union AnimCmd sStartMenuHighlightAnimRight[] =
{
    ANIMCMD_FRAME(1, 1),
    ANIMCMD_END,
};

static const union AnimCmd *const sStartMenuHighlightAnims[] =
{
    sStartMenuHighlightAnimLeft,
    sStartMenuHighlightAnimRight,
};

static const struct SpritePalette sStartMenuIconPalette =
{
    .data = sStartMenuIconsPal,
    .tag = START_MENU_ICON_PALETTE_TAG,
};

static const struct SpriteFrameImage sStartMenuIconFrames[START_MENU_ICON_FRAMES] =
{
    overworld_frame(sStartMenuIconsGfx, 4, 4, 0),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 1),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 2),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 3),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 4),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 5),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 6),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 7),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 8),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 9),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 10),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 11),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 12),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 13),
    // Dawn's Bag: normal and selected.
    overworld_frame(sStartMenuIconsGfx, 4, 4, 14),
    overworld_frame(sStartMenuIconsGfx, 4, 4, 15),
};

#define START_MENU_ICON_ANIM(n) \
    static const union AnimCmd sStartMenuIconAnim##n[] = { \
        ANIMCMD_FRAME(n, 30, FALSE, FALSE), ANIMCMD_END \
    }

START_MENU_ICON_ANIM(0);
START_MENU_ICON_ANIM(1);
START_MENU_ICON_ANIM(2);
START_MENU_ICON_ANIM(3);
START_MENU_ICON_ANIM(4);
START_MENU_ICON_ANIM(5);
START_MENU_ICON_ANIM(6);
START_MENU_ICON_ANIM(7);
START_MENU_ICON_ANIM(8);
START_MENU_ICON_ANIM(9);
START_MENU_ICON_ANIM(10);
START_MENU_ICON_ANIM(11);
START_MENU_ICON_ANIM(12);
START_MENU_ICON_ANIM(13);
START_MENU_ICON_ANIM(14);
START_MENU_ICON_ANIM(15);

static const union AnimCmd *const sStartMenuIconAnims[START_MENU_ICON_FRAMES] =
{
    sStartMenuIconAnim0, sStartMenuIconAnim1, sStartMenuIconAnim2, sStartMenuIconAnim3,
    sStartMenuIconAnim4, sStartMenuIconAnim5, sStartMenuIconAnim6, sStartMenuIconAnim7,
    sStartMenuIconAnim8, sStartMenuIconAnim9, sStartMenuIconAnim10, sStartMenuIconAnim11,
    sStartMenuIconAnim12, sStartMenuIconAnim13,
    sStartMenuIconAnim14, sStartMenuIconAnim15,
};

// Unselected icons remain at their normal size and orientation.
static const union AffineAnimCmd sStartMenuIconAffineAnimIdle[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),
    AFFINEANIMCMD_END,
};

// The selection animation scales the icon before the tilt callback takes over.
static const union AffineAnimCmd sStartMenuIconAffineAnimSelected[] =
{
    AFFINEANIMCMD_FRAME(0x100, 0x100, 0, 0),

    // Enlarge briefly, then return to the original size.
    AFFINEANIMCMD_FRAME( 4,  4, 0, 5),
    AFFINEANIMCMD_FRAME(-4, -4, 0, 5),

    // The tilt is handled separately by SpriteCB_StartMenuIconTilt.
    AFFINEANIMCMD_END,
};

static const union AffineAnimCmd *const sStartMenuIconAffineAnims[] =
{
    sStartMenuIconAffineAnimIdle,
    sStartMenuIconAffineAnimSelected,
};

// The sprite engine keeps pointers to its template and OAM data, so these must
// remain alive for as long as the icon sprites exist.
static struct OamData sStartMenuIconOam;
static struct SpriteTemplate sStartMenuIconSpriteTemplate;
static struct OamData sStartMenuHighlightOam;
static struct SpriteTemplate sStartMenuHighlightSpriteTemplate;
static bool8 sStartMenuIconSpriteDataInitialized = FALSE;

EWRAM_DATA bool8 gShouldStartMenuIconsBePrinted = FALSE;
EWRAM_DATA static u8 sStartMenuIconSpriteIds[START_MENU_ICON_POSITION_COUNT];
EWRAM_DATA static u8 sStartMenuIconFrameIds[START_MENU_ICON_POSITION_COUNT] = {0};
EWRAM_DATA static u8 sStartMenuIconSelectedFrameIds[START_MENU_ICON_POSITION_COUNT];
EWRAM_DATA static u8 sStartMenuHighlightSpriteIds[START_MENU_HIGHLIGHT_SPRITE_COUNT];

static void DeleteAllStartMenuIcons(void);
static void CreateStartMenuIconForAction(u8 action, u8 position);
static void SpriteCB_StartMenuIconTilt(struct Sprite *sprite);
static void SetStartMenuHighlightPosition(u8 position);

static void InitStartMenuIconSpriteData(void)
{
    u8 i;

    if (sStartMenuIconSpriteDataInitialized)
        return;

    // EWRAM_DATA arrays must use zero initializers. Set the unused sprite IDs
    // to SPRITE_NONE at runtime instead.
    for (i = 0; i < START_MENU_ICON_POSITION_COUNT; i++)
        sStartMenuIconSpriteIds[i] = SPRITE_NONE;

    for (i = 0; i < START_MENU_HIGHLIGHT_SPRITE_COUNT; i++)
        sStartMenuHighlightSpriteIds[i] = SPRITE_NONE;

    sStartMenuIconOam = gDummyOamData;
    sStartMenuIconOam.shape = SPRITE_SHAPE(32x32);
    sStartMenuIconOam.size = SPRITE_SIZE(32x32);
    sStartMenuIconOam.affineMode = ST_OAM_AFFINE_DOUBLE;
    sStartMenuIconOam.priority = 0;

    sStartMenuIconSpriteTemplate.tileTag = TAG_NONE;
    sStartMenuIconSpriteTemplate.paletteTag = START_MENU_ICON_PALETTE_TAG;
    sStartMenuIconSpriteTemplate.oam = &sStartMenuIconOam;
    sStartMenuIconSpriteTemplate.anims = sStartMenuIconAnims;
    sStartMenuIconSpriteTemplate.images = sStartMenuIconFrames;
    sStartMenuIconSpriteTemplate.affineAnims = sStartMenuIconAffineAnims;
    sStartMenuIconSpriteTemplate.callback = SpriteCallbackDummy;

    sStartMenuHighlightOam = gDummyOamData;
    sStartMenuHighlightOam.shape = SPRITE_SHAPE(64x32);
    sStartMenuHighlightOam.size = SPRITE_SIZE(64x32);
    sStartMenuHighlightOam.affineMode = ST_OAM_AFFINE_OFF;
    sStartMenuHighlightOam.priority = 0;

    sStartMenuHighlightSpriteTemplate.tileTag = TAG_NONE;
    sStartMenuHighlightSpriteTemplate.paletteTag = START_MENU_FRAME_PALETTE_TAG;
    sStartMenuHighlightSpriteTemplate.oam = &sStartMenuHighlightOam;
    sStartMenuHighlightSpriteTemplate.anims = sStartMenuHighlightAnims;
    sStartMenuHighlightSpriteTemplate.images = sStartMenuHighlightFrames;
    sStartMenuHighlightSpriteTemplate.affineAnims = sStartMenuIconAffineAnims;
    sStartMenuHighlightSpriteTemplate.callback = SpriteCallbackDummy;
    sStartMenuIconSpriteDataInitialized = TRUE;
}

u8 GetStartMenuIconRowY(u8 position)
{
    u16 windowHeight = gWindows[GetStartMenuWindowId()].window.height * 8;
    u16 rowSpacing;
    u16 usedHeight;
    u16 topOffset;

    if (sNumStartMenuActions <= 1)
        return (windowHeight - 16) / 2;

    // Keep each 16-pixel text row evenly spaced and center the whole list.
    rowSpacing = (windowHeight - 16) / (sNumStartMenuActions - 1);
    usedHeight = 16 + rowSpacing * (sNumStartMenuActions - 1);
    topOffset = (windowHeight - usedHeight) / 2;

    return topOffset + position * rowSpacing;
}

static bool8 LoadStartMenuIconPalette(void)
{
    if (IndexOfSpritePaletteTag(START_MENU_ICON_PALETTE_TAG) == 0xFF
        && LoadSpritePalette(&sStartMenuIconPalette) == 0xFF)
        return FALSE;

    return TRUE;
}

static bool8 LoadStartMenuHighlightPalette(void)
{
    if (IndexOfSpritePaletteTag(START_MENU_FRAME_PALETTE_TAG) == 0xFF
        && LoadSpritePalette(&sStartMenuHighlightPalette) == 0xFF)
        return FALSE;

    return TRUE;
}

// Position the two halves of the selection frame.
static void SetStartMenuHighlightPosition(u8 position)
{
    u8 i;
    u8 windowId;
    u32 spriteId;
    s16 frameLeft;
    s16 frameY;
    bool8 recreate = FALSE;

    if (!gShouldStartMenuIconsBePrinted || position >= sNumStartMenuActions)
        return;

    InitStartMenuIconSpriteData();

    if (!LoadStartMenuHighlightPalette())
        return;

    windowId = GetStartMenuWindowId();

    frameLeft = (gWindows[windowId].window.tilemapLeft * 8) - 16;
    frameY = (gWindows[windowId].window.tilemapTop * 8)
           + GetStartMenuIconRowY(position) + 5;

    for (i = 0; i < START_MENU_HIGHLIGHT_SPRITE_COUNT; i++)
    {
        spriteId = sStartMenuHighlightSpriteIds[i];

        if (spriteId >= MAX_SPRITES || !gSprites[spriteId].inUse)
            recreate = TRUE;
    }

    if (recreate)
    {
        // Remove any leftover half before creating a complete pair.
        for (i = 0; i < START_MENU_HIGHLIGHT_SPRITE_COUNT; i++)
        {
            spriteId = sStartMenuHighlightSpriteIds[i];

            if (spriteId < MAX_SPRITES && gSprites[spriteId].inUse)
                DestroySpriteAndFreeResources(&gSprites[spriteId]);

            sStartMenuHighlightSpriteIds[i] = SPRITE_NONE;
        }

        spriteId = CreateSpriteUnchecked(
            &sStartMenuHighlightSpriteTemplate,
            frameLeft + 32, frameY, 0);

        if (spriteId >= MAX_SPRITES)
            return;

        sStartMenuHighlightSpriteIds[0] = spriteId;
        StartSpriteAnim(&gSprites[spriteId], 0);

        spriteId = CreateSpriteUnchecked(
            &sStartMenuHighlightSpriteTemplate,
            frameLeft + 96, frameY, 0);

        if (spriteId >= MAX_SPRITES)
        {
            DestroySpriteAndFreeResources(
                &gSprites[sStartMenuHighlightSpriteIds[0]]);
            sStartMenuHighlightSpriteIds[0] = SPRITE_NONE;
            return;
        }

        sStartMenuHighlightSpriteIds[1] = spriteId;
        StartSpriteAnim(&gSprites[spriteId], 1);
    }

    // Moving the sprites rather than recreating them avoids OAM churn.
    for (i = 0; i < START_MENU_HIGHLIGHT_SPRITE_COUNT; i++)
    {
        struct Sprite *sprite = &gSprites[sStartMenuHighlightSpriteIds[i]];

        sprite->x = frameLeft + 32 + (i * 64);
        sprite->y = frameY;
        sprite->x2 = 0;
        sprite->y2 = 0;
    }
}

static void SpriteCB_StartMenuIconTilt(struct Sprite *sprite)
{
    s16 angle;

    // Let the one-time enlargement finish before taking control of rotation.
    if (!sprite->affineAnimEnded)
        return;

    // Prevent the affine animation system from overwriting our rotation.
    sprite->affineAnimPaused = TRUE;

    angle = sprite->data[0];

    // Rotate at a constant speed and reverse at each end of the tilt.
    if (sprite->data[1] == 0)
    {
        angle += 0x40;

        if (angle >= 0x0C16)
        {
            // Reflect any overshoot immediately and reverse direction.
            angle = 0x0C16 - (angle - 0x0C16);
            sprite->data[1] = 1;
        }
    }
    else
    {
        angle -= 0x40;

        if (angle <= -0x0C16)
        {
            angle = -0x0C16 + (-0x0C16 - angle);
            sprite->data[1] = 0;
        }
    }

    sprite->data[0] = angle;

    SetOamMatrixRotationScaling(sprite->oam.matrixNum,
                                0x100, 0x100, (u16)angle);
}

static void DeleteAllStartMenuIcons(void)
{
    u8 i;

    InitStartMenuIconSpriteData();

    for (i = 0; i < START_MENU_ICON_POSITION_COUNT; i++)
    {
        u8 spriteId = sStartMenuIconSpriteIds[i];
        if (spriteId < MAX_SPRITES && gSprites[spriteId].inUse)
            DestroySpriteAndFreeResources(&gSprites[spriteId]);
        sStartMenuIconSpriteIds[i] = SPRITE_NONE;
        sStartMenuIconFrameIds[i] = 0;
        sStartMenuIconSelectedFrameIds[i] = 0;
    }

    FreeSpritePaletteByTag(START_MENU_ICON_PALETTE_TAG);
    gShouldStartMenuIconsBePrinted = FALSE;

    // Remove both parts of the selection frame as well as the icons.
    for (i = 0; i < START_MENU_HIGHLIGHT_SPRITE_COUNT; i++)
    {
        u8 spriteId = sStartMenuHighlightSpriteIds[i];

        if (spriteId < MAX_SPRITES && gSprites[spriteId].inUse)
            DestroySpriteAndFreeResources(&gSprites[spriteId]);

        sStartMenuHighlightSpriteIds[i] = SPRITE_NONE;
    }

    FreeSpritePaletteByTag(START_MENU_FRAME_PALETTE_TAG);
}

bool8 IsAStartMenuIconAtPosition(u8 position)
{
    u8 spriteId;

    InitStartMenuIconSpriteData();

    if (position >= START_MENU_ICON_POSITION_COUNT)
        return FALSE;

    spriteId = sStartMenuIconSpriteIds[position];
    return spriteId < MAX_SPRITES && gSprites[spriteId].inUse;
}

void SetStartMenuIconSelected(u8 position, bool8 selected)
{
    struct Sprite *sprite;
    u8 spriteId;

    if (!IsAStartMenuIconAtPosition(position))
        return;

    spriteId = sStartMenuIconSpriteIds[position];
    sprite = &gSprites[spriteId];
    StartSpriteAnim(sprite, selected
                    ? sStartMenuIconSelectedFrameIds[position]
                    : sStartMenuIconFrameIds[position]);

    // Never retain vertical displacement from an earlier animation.
    sprite->y2 = 0;
    sprite->data[0] = 0;
    sprite->data[1] = 0;
    sprite->affineAnimPaused = FALSE;
    StartSpriteAffineAnim(sprite, selected ? 1 : 0);
    sprite->callback = selected ? SpriteCB_StartMenuIconTilt : SpriteCallbackDummy;
}

static void CreateStartMenuIconForAction(u8 action, u8 position)
{
    u8 iconId;
    u8 selectedIconId;
    u32 spriteId;
    s16 x;
    s16 y;
    u8 rowY;

    if (!gShouldStartMenuIconsBePrinted || position >= START_MENU_ICON_POSITION_COUNT)
        return;

    if (position == sStartMenuCursorPos)
        SetStartMenuHighlightPosition(position);

    // The frame ordering is Pokédex, Pokémon, Bag, Trainer Card, Save, Options, Exit.
    // Platinum-specific extensions without an original DPPt icon retain the normal cursor.
    switch (action)
    {
    case MENU_ACTION_POKEDEX:
        iconId = 2;
        break;
    case MENU_ACTION_POKEMON:
        iconId = 1;
        break;
    case MENU_ACTION_BAG:
    case MENU_ACTION_PYRAMID_BAG:
        iconId = (gSaveBlock2Ptr->playerGender == MALE) ? 0 : 14;
        break;
    case MENU_ACTION_PLAYER:
    case MENU_ACTION_PLAYER_LINK:
        iconId = 3;
        break;
    case MENU_ACTION_SAVE:
    case MENU_ACTION_REST_FRONTIER:
        iconId = 4;
        break;
    case MENU_ACTION_OPTION:
        iconId = 5;
        break;
    case MENU_ACTION_EXIT:
        iconId = 6;
        break;
    default:
        return;
    }

    // Most icons use the normal selected-frame offset.
    selectedIconId = iconId + START_MENU_ICON_SELECTED_OFFSET;

    // Dawn's Bag has its own selected artwork at frame 15.
    if ((action == MENU_ACTION_BAG || action == MENU_ACTION_PYRAMID_BAG)
        && gSaveBlock2Ptr->playerGender != MALE)
        selectedIconId = 15;

    InitStartMenuIconSpriteData();
    if (!LoadStartMenuIconPalette())
        return;

    rowY = GetStartMenuIconRowY(position);
    x = (gWindows[GetStartMenuWindowId()].window.tilemapLeft * 8) + START_MENU_ICON_SPRITE_X;
    // Sprite coordinates are centered; align the icon with the text row.
    y = (gWindows[GetStartMenuWindowId()].window.tilemapTop * 8) + rowY + 8;
    spriteId = CreateSpriteUnchecked(&sStartMenuIconSpriteTemplate, x, y, 0);
    if (spriteId >= MAX_SPRITES)
        return;

    sStartMenuIconSpriteIds[position] = spriteId;
    sStartMenuIconFrameIds[position] = iconId;
    sStartMenuIconSelectedFrameIds[position] = selectedIconId;
    SetStartMenuIconSelected(position, position == sStartMenuCursorPos);
}
#endif // START_MENU_USE_ICONS

static const struct WindowTemplate sWindowTemplate_SafariBalls = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 9,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x8
};

static const u8 *const sPyramidFloorNames[FRONTIER_STAGES_PER_CHALLENGE + 1] =
{
    gText_Floor1,
    gText_Floor2,
    gText_Floor3,
    gText_Floor4,
    gText_Floor5,
    gText_Floor6,
    gText_Floor7,
    gText_Peak
};

static const struct WindowTemplate sWindowTemplate_PyramidFloor = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 10,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x8
};

static const struct WindowTemplate sWindowTemplate_PyramidPeak = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 12,
    .height = 4,
    .paletteNum = 15,
    .baseBlock = 0x8
};

static const u8 sText_MenuDebug[] = _("DEBUG");

static const struct MenuAction sStartMenuItems[] =
{
    [MENU_ACTION_POKEDEX]         = {gText_MenuPokedex, {.u8_void = StartMenuPokedexCallback}},
    [MENU_ACTION_POKEMON]         = {gText_MenuPokemon, {.u8_void = StartMenuPokemonCallback}},
    [MENU_ACTION_BAG]             = {gText_MenuBag,     {.u8_void = StartMenuBagCallback}},
    [MENU_ACTION_POKENAV]         = {gText_MenuPokenav, {.u8_void = StartMenuPokeNavCallback}},
    [MENU_ACTION_PLAYER]          = {gText_MenuPlayer,  {.u8_void = StartMenuPlayerNameCallback}},
    [MENU_ACTION_SAVE]            = {gText_MenuSave,    {.u8_void = StartMenuSaveCallback}},
    [MENU_ACTION_OPTION]          = {gText_MenuOption,  {.u8_void = StartMenuOptionCallback}},
    [MENU_ACTION_EXIT]            = {gText_MenuExit,    {.u8_void = StartMenuExitCallback}},
    [MENU_ACTION_RETIRE_SAFARI]   = {gText_MenuRetire,  {.u8_void = StartMenuSafariZoneRetireCallback}},
    [MENU_ACTION_PLAYER_LINK]     = {gText_MenuPlayer,  {.u8_void = StartMenuLinkModePlayerNameCallback}},
    [MENU_ACTION_REST_FRONTIER]   = {gText_MenuRest,    {.u8_void = StartMenuSaveCallback}},
    [MENU_ACTION_RETIRE_FRONTIER] = {gText_MenuRetire,  {.u8_void = StartMenuBattlePyramidRetireCallback}},
    [MENU_ACTION_PYRAMID_BAG]     = {gText_MenuBag,     {.u8_void = StartMenuBattlePyramidBagCallback}},
    [MENU_ACTION_DEBUG]           = {sText_MenuDebug,   {.u8_void = StartMenuDebugCallback}},
    [MENU_ACTION_DEXNAV]          = {gText_MenuDexNav,  {.u8_void = StartMenuDexNavCallback}},
};

static const struct BgTemplate sBgTemplates_LinkBattleSave[] =
{
    {
        .bg = 0,
        .charBaseIndex = 2,
        .mapBaseIndex = 31,
        .screenSize = 0,
        .paletteMode = 0,
        .priority = 0,
        .baseTile = 0
    }
};

static const struct WindowTemplate sWindowTemplates_LinkBattleSave[] =
{
    {
        .bg = 0,
        .tilemapLeft = 2,
        .tilemapTop = 15,
        .width = 26,
        .height = 4,
        .paletteNum = 15,
        .baseBlock = 0x194
    },
    DUMMY_WIN_TEMPLATE
};

static const struct WindowTemplate sSaveInfoWindowTemplate = {
    .bg = 0,
    .tilemapLeft = 1,
    .tilemapTop = 1,
    .width = 14,
    .height = 10,
    .paletteNum = 15,
    .baseBlock = 8
};

// Local functions
static void BuildStartMenuActions(void);
static void AddStartMenuAction(u8 action);
static void BuildNormalStartMenu(void);
static void BuildDebugStartMenu(void);
static void BuildSafariZoneStartMenu(void);
static void BuildLinkModeStartMenu(void);
static void BuildUnionRoomStartMenu(void);
static void BuildBattlePikeStartMenu(void);
static void BuildBattlePyramidStartMenu(void);
static void BuildMultiPartnerRoomStartMenu(void);
static void ShowSafariBallsWindow(void);
static void ShowPyramidFloorWindow(void);
static void RemoveExtraStartMenuWindows(void);
static bool32 PrintStartMenuActions(s8 *pIndex, u32 count);
static bool32 InitStartMenuStep(void);
static void InitStartMenu(void);
static void CreateStartMenuTask(TaskFunc followupFunc);
static void InitSave(void);
static u8 RunSaveCallback(void);
static void ShowSaveMessage(const u8 *message, u8 (*saveCallback)(void));
static void HideSaveMessageWindow(void);
static void HideSaveInfoWindow(void);
static void SaveStartTimer(void);
static bool8 SaveSuccesTimer(void);
static bool8 SaveErrorTimer(void);
static void InitBattlePyramidRetire(void);
static void VBlankCB_LinkBattleSave(void);
static bool32 InitSaveWindowAfterLinkBattle(u8 *par1);
static void CB2_SaveAfterLinkBattle(void);
static void ShowSaveInfoWindow(void);
static void RemoveSaveInfoWindow(void);
static void HideStartMenuWindow(void);
static void HideStartMenuDebug(void);

static void BuildStartMenuActions(void)
{
    sNumStartMenuActions = 0;

    if (IsOverworldLinkActive() == TRUE)
    {
        BuildLinkModeStartMenu();
    }
    else if (InUnionRoom() == TRUE)
    {
        BuildUnionRoomStartMenu();
    }
    else if (GetSafariZoneFlag() == TRUE)
    {
        BuildSafariZoneStartMenu();
    }
    else if (InBattlePike())
    {
        BuildBattlePikeStartMenu();
    }
    else if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
    {
        BuildBattlePyramidStartMenu();
    }
    else if (InMultiPartnerRoom())
    {
        BuildMultiPartnerRoomStartMenu();
    }
    else
    {
        if (DEBUG_OVERWORLD_MENU == TRUE && DEBUG_OVERWORLD_IN_MENU == TRUE)
            BuildDebugStartMenu();
        else
            BuildNormalStartMenu();
    }
}

static void AddStartMenuAction(u8 action)
{
    AppendToList(sCurrentStartMenuActions, &sNumStartMenuActions, action);
}

static void BuildNormalStartMenu(void)
{
    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKEDEX);

    if (DN_FLAG_DEXNAV_GET != 0 && FlagGet(DN_FLAG_DEXNAV_GET))
        AddStartMenuAction(MENU_ACTION_DEXNAV);

    if (FlagGet(FLAG_SYS_POKEMON_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKEMON);

    AddStartMenuAction(MENU_ACTION_BAG);

    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKENAV);

    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_SAVE);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildDebugStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_DEBUG);
    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKEDEX);
    if (FlagGet(FLAG_SYS_POKEMON_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);
    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
        AddStartMenuAction(MENU_ACTION_POKENAV);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_SAVE);
    AddStartMenuAction(MENU_ACTION_OPTION);
}

static void BuildSafariZoneStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_RETIRE_SAFARI);
    AddStartMenuAction(MENU_ACTION_POKEDEX);
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildLinkModeStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);

    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
    {
        AddStartMenuAction(MENU_ACTION_POKENAV);
    }

    AddStartMenuAction(MENU_ACTION_PLAYER_LINK);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildUnionRoomStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_BAG);

    if (FlagGet(FLAG_SYS_POKENAV_GET) == TRUE)
    {
        AddStartMenuAction(MENU_ACTION_POKENAV);
    }

    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildBattlePikeStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEDEX);
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildBattlePyramidStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_PYRAMID_BAG);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_REST_FRONTIER);
    AddStartMenuAction(MENU_ACTION_RETIRE_FRONTIER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void BuildMultiPartnerRoomStartMenu(void)
{
    AddStartMenuAction(MENU_ACTION_POKEMON);
    AddStartMenuAction(MENU_ACTION_PLAYER);
    AddStartMenuAction(MENU_ACTION_OPTION);
    AddStartMenuAction(MENU_ACTION_EXIT);
}

static void ShowSafariBallsWindow(void)
{
    sSafariBallsWindowId = AddWindow(&sWindowTemplate_SafariBalls);
    PutWindowTilemap(sSafariBallsWindowId);
    DrawStdWindowFrame(sSafariBallsWindowId, FALSE);
    if (IS_FRLG)
    {
        ConvertIntToDecimalStringN(gStringVar1, gSafariZoneStepCounter, STR_CONV_MODE_RIGHT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar2, 600, STR_CONV_MODE_RIGHT_ALIGN, 3);
        ConvertIntToDecimalStringN(gStringVar3, gNumSafariBalls, STR_CONV_MODE_RIGHT_ALIGN, 2);
        StringExpandPlaceholders(gStringVar4, gText_MenuSafariStats);
        AddTextPrinterParameterized(sSafariBallsWindowId, FONT_NORMAL, gStringVar4, 4, 3, 0xFF, NULL);
    }
    else
    {
        ConvertIntToDecimalStringN(gStringVar1, gNumSafariBalls, STR_CONV_MODE_RIGHT_ALIGN, 2);
        StringExpandPlaceholders(gStringVar4, gText_SafariBallStock);
        AddTextPrinterParameterized(sSafariBallsWindowId, FONT_NORMAL, gStringVar4, 0, 1, TEXT_SKIP_DRAW, NULL);
    }
    CopyWindowToVram(sSafariBallsWindowId, COPYWIN_GFX);
}

static void ShowPyramidFloorWindow(void)
{
    if (gSaveBlock2Ptr->frontier.curChallengeBattleNum == FRONTIER_STAGES_PER_CHALLENGE)
        sBattlePyramidFloorWindowId = AddWindow(&sWindowTemplate_PyramidPeak);
    else
        sBattlePyramidFloorWindowId = AddWindow(&sWindowTemplate_PyramidFloor);

    PutWindowTilemap(sBattlePyramidFloorWindowId);
    DrawStdWindowFrame(sBattlePyramidFloorWindowId, FALSE);
    StringCopy(gStringVar1, sPyramidFloorNames[gSaveBlock2Ptr->frontier.curChallengeBattleNum]);
    StringExpandPlaceholders(gStringVar4, gText_BattlePyramidFloor);
    AddTextPrinterParameterized(sBattlePyramidFloorWindowId, FONT_NORMAL, gStringVar4, 0, 1, TEXT_SKIP_DRAW, NULL);
    CopyWindowToVram(sBattlePyramidFloorWindowId, COPYWIN_GFX);
}

static void RemoveExtraStartMenuWindows(void)
{
    if (GetSafariZoneFlag())
    {
        ClearStdWindowAndFrameToTransparent(sSafariBallsWindowId, FALSE);
        CopyWindowToVram(sSafariBallsWindowId, COPYWIN_GFX);
        RemoveWindow(sSafariBallsWindowId);
    }
    if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
    {
        ClearStdWindowAndFrameToTransparent(sBattlePyramidFloorWindowId, FALSE);
        RemoveWindow(sBattlePyramidFloorWindowId);
    }
}

static bool32 PrintStartMenuActions(s8 *pIndex, u32 count)
{
    s8 index = *pIndex;

    do
    {
        u8 action = sCurrentStartMenuActions[index];
#if START_MENU_USE_ICONS
        u8 textX = gShouldStartMenuIconsBePrinted ? START_MENU_ICON_TEXT_X : 8;
        u8 textY = gShouldStartMenuIconsBePrinted
                   ? GetStartMenuIconRowY(index)
                   : (index << 4) + 9;
#else
        u8 textX = 8;
        u8 textY = (index << 4) + 9;
#endif

        if (sStartMenuItems[action].func.u8_void == StartMenuPlayerNameCallback)
            PrintPlayerNameOnWindow(GetStartMenuWindowId(), sStartMenuItems[action].text, textX, textY);
        else
        {
            StringExpandPlaceholders(gStringVar4, sStartMenuItems[action].text);
            AddTextPrinterParameterized(GetStartMenuWindowId(), FONT_NORMAL, gStringVar4, textX, textY, TEXT_SKIP_DRAW, NULL);
        }

#if START_MENU_USE_ICONS
        if (gShouldStartMenuIconsBePrinted)
            CreateStartMenuIconForAction(action, index);
#endif

        index++;
        if (index >= sNumStartMenuActions)
        {
            *pIndex = index;
            return TRUE;
        }

        count--;
    }
    while (count != 0);

    *pIndex = index;
    return FALSE;
}

static bool32 InitStartMenuStep(void)
{
    s8 state = sInitStartMenuData[0];

    switch (state)
    {
    case 0:
        sInitStartMenuData[0]++;
        break;
    case 1:
        BuildStartMenuActions();
        sInitStartMenuData[0]++;
        break;
    case 2:
        LoadMessageBoxAndBorderGfx();
        // Window frame IDs are zero-based: index 12 selects visual Frame 13.
        LoadWindowGfx(0, 12, STD_WINDOW_BASE_TILE_NUM, BG_PLTT_ID(STD_WINDOW_PALETTE_NUM));
        DrawStdWindowFrame(AddStartMenuWindow(sNumStartMenuActions), FALSE);
        sInitStartMenuData[1] = 0;
        sInitStartMenuData[0]++;
        break;
    case 3:
        if (GetSafariZoneFlag())
            ShowSafariBallsWindow();
        if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
            ShowPyramidFloorWindow();
        sInitStartMenuData[0]++;
        break;
    case 4:
        if (PrintStartMenuActions(&sInitStartMenuData[1], 2))
            sInitStartMenuData[0]++;
        break;
    case 5:
        sStartMenuCursorPos = InitMenuNormal(GetStartMenuWindowId(), FONT_NORMAL, 0, 9, 16, sNumStartMenuActions, sStartMenuCursorPos);
        CopyWindowToVram(GetStartMenuWindowId(), COPYWIN_MAP);
        return TRUE;
    }

    return FALSE;
}

static void InitStartMenu(void)
{
    sInitStartMenuData[0] = 0;
    sInitStartMenuData[1] = 0;
    while (!InitStartMenuStep())
        ;
}

static void StartMenuTask(u8 taskId)
{
    if (InitStartMenuStep() == TRUE)
        SwitchTaskToFollowupFunc(taskId);
}

static void CreateStartMenuTask(TaskFunc followupFunc)
{
    u8 taskId;

    sInitStartMenuData[0] = 0;
    sInitStartMenuData[1] = 0;
    taskId = CreateTask(StartMenuTask, 0x50);
    SetTaskFuncWithFollowupFunc(taskId, StartMenuTask, followupFunc);
}

static bool8 FieldCB_ReturnToFieldStartMenu(void)
{
    if (InitStartMenuStep() == FALSE)
    {
        return FALSE;
    }

    ReturnToFieldOpenStartMenu();
    return TRUE;
}

void ShowReturnToFieldStartMenu(void)
{
#if START_MENU_USE_ICONS
    gShouldStartMenuIconsBePrinted = TRUE;
#endif
    sInitStartMenuData[0] = 0;
    sInitStartMenuData[1] = 0;
    gFieldCallback2 = FieldCB_ReturnToFieldStartMenu;
}

void Task_ShowStartMenu(u8 taskId)
{
    struct Task *task = &gTasks[taskId];

    switch (task->data[0])
    {
    case 0:
        if (InUnionRoom() == TRUE)
            SetUsingUnionRoomStartMenu();

        gMenuCallback = HandleStartMenuInput;
        task->data[0]++;
        break;
    case 1:
        if (gMenuCallback() == TRUE)
            DestroyTask(taskId);
        break;
    }
}

void ShowStartMenu(void)
{
    if (!IsOverworldLinkActive())
    {
        FreezeObjectEvents();
        PlayerFreeze();
        StopPlayerAvatar();
    }
#if START_MENU_USE_ICONS
    gShouldStartMenuIconsBePrinted = TRUE;
#endif
    CreateStartMenuTask(Task_ShowStartMenu);
    LockPlayerFieldControls();
}

static bool8 HandleStartMenuInput(void)
{
    if (JOY_REPEAT(DPAD_UP))
    {
        u8 oldCursorPos = sStartMenuCursorPos;
        PlaySE(SE_SELECT);
        sStartMenuCursorPos = Menu_MoveCursor(-1);
#if START_MENU_USE_ICONS
        SetStartMenuIconSelected(oldCursorPos, FALSE);
        SetStartMenuIconSelected(sStartMenuCursorPos, TRUE);
        SetStartMenuHighlightPosition(sStartMenuCursorPos);
#endif
    }

    if (JOY_REPEAT(DPAD_DOWN))
    {
        u8 oldCursorPos = sStartMenuCursorPos;
        PlaySE(SE_SELECT);
        sStartMenuCursorPos = Menu_MoveCursor(1);
#if START_MENU_USE_ICONS
        SetStartMenuIconSelected(oldCursorPos, FALSE);
        SetStartMenuIconSelected(sStartMenuCursorPos, TRUE);
        SetStartMenuHighlightPosition(sStartMenuCursorPos);
#endif
    }

    if (JOY_NEW(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        if (sStartMenuItems[sCurrentStartMenuActions[sStartMenuCursorPos]].func.u8_void == StartMenuPokedexCallback)
        {
            if (GetNationalPokedexCount(FLAG_GET_SEEN) == 0)
                return FALSE;
        }
        if (sCurrentStartMenuActions[sStartMenuCursorPos] == MENU_ACTION_DEXNAV
          && MapHasNoEncounterData())
            return FALSE;

        gMenuCallback = sStartMenuItems[sCurrentStartMenuActions[sStartMenuCursorPos]].func.u8_void;
#if START_MENU_USE_ICONS
        // The next screen may reset sprite data or reuse the menu window.
        DeleteAllStartMenuIcons();
#endif

        if (gMenuCallback != StartMenuSaveCallback
            && gMenuCallback != StartMenuExitCallback
            && gMenuCallback != StartMenuDebugCallback
            && gMenuCallback != StartMenuSafariZoneRetireCallback
            && gMenuCallback != StartMenuBattlePyramidRetireCallback)
        {
           FadeScreen(FADE_TO_BLACK, 0);
        }

        return FALSE;
    }

    if (JOY_NEW(START_BUTTON | B_BUTTON))
    {
#if START_MENU_USE_ICONS
        DeleteAllStartMenuIcons();
#endif
        RemoveExtraStartMenuWindows();
        HideStartMenu();
        return TRUE;
    }

    return FALSE;
}

bool8 StartMenuPokedexCallback(void)
{
    if (!gPaletteFade.active)
    {
        IncrementGameStat(GAME_STAT_CHECKED_POKEDEX);
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_OpenPokedex);

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuPokemonCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_PartyMenuFromStartMenu); // Display party menu

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuBagCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_BagMenuFromStartMenu); // Display bag menu

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuPokeNavCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_InitPokeNav);  // Display PokéNav

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuPlayerNameCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();

        if (IsOverworldLinkActive() || InUnionRoom())
            ShowPlayerTrainerCard(CB2_ReturnToFieldWithOpenMenu); // Display trainer card
        else if (FlagGet(FLAG_SYS_FRONTIER_PASS))
            ShowFrontierPass(CB2_ReturnToFieldWithOpenMenu); // Display frontier pass
        else
            ShowPlayerTrainerCard(CB2_ReturnToFieldWithOpenMenu); // Display trainer card

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuSaveCallback(void)
{
    if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
        RemoveExtraStartMenuWindows();

    gMenuCallback = SaveStartCallback; // Display save menu

    return FALSE;
}

static bool8 StartMenuOptionCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_InitOptionMenu); // Display option menu
        gMain.savedCallback = CB2_ReturnToFieldWithOpenMenu;

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuExitCallback(void)
{
    RemoveExtraStartMenuWindows();
    HideStartMenu(); // Hide start menu

    return TRUE;
}

static bool8 StartMenuDebugCallback(void)
{
    RemoveExtraStartMenuWindows();
    HideStartMenuDebug(); // Hide start menu without enabling movement

    if (DEBUG_OVERWORLD_MENU)
    {
        FreezeObjectEvents();
        Debug_ShowMainMenu();
    }

return TRUE;
}

static bool8 StartMenuSafariZoneRetireCallback(void)
{
    RemoveExtraStartMenuWindows();
    HideStartMenu();
    SafariZoneRetirePrompt();

    return TRUE;
}

static void HideStartMenuDebug(void)
{
#if START_MENU_USE_ICONS
    DeleteAllStartMenuIcons();
#endif
    PlaySE(SE_SELECT);
    ClearStdWindowAndFrame(GetStartMenuWindowId(), TRUE);
    RemoveStartMenuWindow();
}

static bool8 StartMenuLinkModePlayerNameCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        CleanupOverworldWindowsAndTilemaps();
        ShowTrainerCardInLink(gLocalLinkPlayerId, CB2_ReturnToFieldWithOpenMenu);

        return TRUE;
    }

    return FALSE;
}

static bool8 StartMenuBattlePyramidRetireCallback(void)
{
    gMenuCallback = BattlePyramidRetireStartCallback; // Confirm retire

    return FALSE;
}

// Functionally unused
void ShowBattlePyramidStartMenu(void)
{
#if START_MENU_USE_ICONS
    gShouldStartMenuIconsBePrinted = TRUE;
#endif
    ClearDialogWindowAndFrameToTransparent(0, FALSE);
    ScriptUnfreezeObjectEvents();
    CreateStartMenuTask(Task_ShowStartMenu);
    LockPlayerFieldControls();
}

static bool8 StartMenuBattlePyramidBagCallback(void)
{
    if (!gPaletteFade.active)
    {
        PlayRainStoppingSoundEffect();
        RemoveExtraStartMenuWindows();
        CleanupOverworldWindowsAndTilemaps();
        SetMainCallback2(CB2_PyramidBagMenuFromStartMenu);

        return TRUE;
    }

    return FALSE;
}

static bool8 SaveStartCallback(void)
{
    InitSave();
    gMenuCallback = SaveCallback;

    return FALSE;
}

static bool8 SaveCallback(void)
{
    switch (RunSaveCallback())
    {
    case SAVE_IN_PROGRESS:
        return FALSE;
    case SAVE_CANCELED: // Back to start menu
        ClearDialogWindowAndFrameToTransparent(0, FALSE);
#if START_MENU_USE_ICONS
        gShouldStartMenuIconsBePrinted = TRUE;
#endif
        InitStartMenu();
        gMenuCallback = HandleStartMenuInput;
        return FALSE;
    case SAVE_SUCCESS:
    case SAVE_ERROR:    // Close start menu
        ClearDialogWindowAndFrameToTransparent(0, TRUE);
        ScriptUnfreezeObjectEvents();
        UnlockPlayerFieldControls();
        SoftResetInBattlePyramid();
        return TRUE;
    }

    return FALSE;
}

static bool8 BattlePyramidRetireStartCallback(void)
{
    InitBattlePyramidRetire();
    gMenuCallback = BattlePyramidRetireCallback;

    return FALSE;
}

static bool8 BattlePyramidRetireReturnCallback(void)
{
#if START_MENU_USE_ICONS
    gShouldStartMenuIconsBePrinted = TRUE;
#endif
    InitStartMenu();
    gMenuCallback = HandleStartMenuInput;

    return FALSE;
}

static bool8 BattlePyramidRetireCallback(void)
{
    switch (RunSaveCallback())
    {
    case SAVE_SUCCESS: // No (Stay in battle pyramid)
        RemoveExtraStartMenuWindows();
        gMenuCallback = BattlePyramidRetireReturnCallback;
        return FALSE;
    case SAVE_IN_PROGRESS:
        return FALSE;
    case SAVE_CANCELED: // Yes (Retire from battle pyramid)
        ClearDialogWindowAndFrameToTransparent(0, TRUE);
        ScriptUnfreezeObjectEvents();
        UnlockPlayerFieldControls();
        ScriptContext_SetupScript(BattlePyramid_Retire);
        return TRUE;
    }

    return FALSE;
}

static void InitSave(void)
{
    SaveMapView();
    sSaveDialogCallback = SaveConfirmSaveCallback;
    sSavingComplete = FALSE;
}

static u8 RunSaveCallback(void)
{
    // True if text is still printing
    if (RunTextPrintersAndIsPrinter0Active() == TRUE)
    {
        return SAVE_IN_PROGRESS;
    }

    sSavingComplete = FALSE;
    return sSaveDialogCallback();
}

void SaveGame(void)
{
    InitSave();
    CreateTask(SaveGameTask, 0x50);
}

static void ShowSaveMessage(const u8 *message, u8 (*saveCallback)(void))
{
    StringExpandPlaceholders(gStringVar4, message);
    LoadMessageBoxAndFrameGfx(0, TRUE);
    AddTextPrinterForMessage(TRUE);
    sSavingComplete = TRUE;
    sSaveDialogCallback = saveCallback;
}

static void SaveGameTask(u8 taskId)
{
    u8 status = RunSaveCallback();

    switch (status)
    {
    case SAVE_CANCELED:
    case SAVE_ERROR:
        gSpecialVar_Result = 0;
        break;
    case SAVE_SUCCESS:
        gSpecialVar_Result = status;
        break;
    case SAVE_IN_PROGRESS:
        return;
    }

    DestroyTask(taskId);
    ScriptContext_Enable();
}

static void HideSaveMessageWindow(void)
{
    ClearDialogWindowAndFrame(0, TRUE);
}

static void HideSaveInfoWindow(void)
{
    RemoveSaveInfoWindow();
}

static void SaveStartTimer(void)
{
    sSaveDialogTimer = 60;
}

static bool8 SaveSuccesTimer(void)
{
    sSaveDialogTimer--;

    if (JOY_HELD(A_BUTTON))
    {
        PlaySE(SE_SELECT);
        return TRUE;
    }
    if (sSaveDialogTimer == 0)
    {
        return TRUE;
    }

    return FALSE;
}

static bool8 SaveErrorTimer(void)
{
    if (sSaveDialogTimer != 0)
    {
        sSaveDialogTimer--;
    }
    else if (JOY_HELD(A_BUTTON))
    {
        return TRUE;
    }

    return FALSE;
}

static u8 SaveConfirmSaveCallback(void)
{
    ClearStdWindowAndFrame(GetStartMenuWindowId(), FALSE);
    RemoveStartMenuWindow();
    ShowSaveInfoWindow();

    if (CurrentBattlePyramidLocation() != PYRAMID_LOCATION_NONE)
    {
        ShowSaveMessage(gText_BattlePyramidConfirmRest, SaveYesNoCallback);
    }
    else
    {
        ShowSaveMessage(gText_ConfirmSave, SaveYesNoCallback);
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveYesNoCallback(void)
{
    DisplayYesNoMenuDefaultYes(); // Show Yes/No menu
    sSaveDialogCallback = SaveConfirmInputCallback;
    return SAVE_IN_PROGRESS;
}

static u8 SaveConfirmInputCallback(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Yes
        switch (gSaveFileStatus)
        {
        case SAVE_STATUS_EMPTY:
        case SAVE_STATUS_CORRUPT:
            if (gDifferentSaveFile == FALSE && !SKIP_SAVE_CONFIRMATION)
            {
                sSaveDialogCallback = SaveFileExistsCallback;
                return SAVE_IN_PROGRESS;
            }

            sSaveDialogCallback = SaveSavingMessageCallback;
            return SAVE_IN_PROGRESS;
        default:
            if (SKIP_SAVE_CONFIRMATION)
                sSaveDialogCallback = SaveSavingMessageCallback;
            else
                sSaveDialogCallback = SaveFileExistsCallback;
            return SAVE_IN_PROGRESS;
        }
    case MENU_B_PRESSED:
    case 1: // No
        HideSaveInfoWindow();
        HideSaveMessageWindow();
        return SAVE_CANCELED;
    }

    return SAVE_IN_PROGRESS;
}

// A different save file exists
static u8 SaveFileExistsCallback(void)
{
    if (gDifferentSaveFile == TRUE)
    {
        ShowSaveMessage(gText_DifferentSaveFile, SaveConfirmOverwriteDefaultNoCallback);
    }
    else
    {
        ShowSaveMessage(gText_AlreadySavedFile, SaveConfirmOverwriteCallback);
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveConfirmOverwriteDefaultNoCallback(void)
{
    DisplayYesNoMenuWithDefault(1); // Show Yes/No menu (No selected as default)
    sSaveDialogCallback = SaveOverwriteInputCallback;
    return SAVE_IN_PROGRESS;
}

static u8 SaveConfirmOverwriteCallback(void)
{
    DisplayYesNoMenuDefaultYes(); // Show Yes/No menu
    sSaveDialogCallback = SaveOverwriteInputCallback;
    return SAVE_IN_PROGRESS;
}

static u8 SaveOverwriteInputCallback(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Yes
        sSaveDialogCallback = SaveSavingMessageCallback;
        return SAVE_IN_PROGRESS;
    case MENU_B_PRESSED:
    case 1: // No
        HideSaveInfoWindow();
        HideSaveMessageWindow();
        return SAVE_CANCELED;
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveSavingMessageCallback(void)
{
    ShowSaveMessage(gText_SavingDontTurnOff, SaveDoSaveCallback);
    return SAVE_IN_PROGRESS;
}

static u8 SaveDoSaveCallback(void)
{
    u8 saveStatus;

    IncrementGameStat(GAME_STAT_SAVED_GAME);
    PausePyramidChallenge();

    if (gDifferentSaveFile == TRUE)
    {
        saveStatus = TrySavingData(SAVE_OVERWRITE_DIFFERENT_FILE);
        gDifferentSaveFile = FALSE;
    }
    else
    {
        saveStatus = TrySavingData(SAVE_NORMAL);
    }

    if (saveStatus == SAVE_STATUS_OK)
        ShowSaveMessage(gText_PlayerSavedGame, SaveSuccessCallback);
    else
        ShowSaveMessage(gText_SaveError, SaveErrorCallback);

    SaveStartTimer();
    return SAVE_IN_PROGRESS;
}

static u8 SaveSuccessCallback(void)
{
    if (!IsTextPrinterActiveOnWindow(0))
    {
        PlaySE(SE_SAVE);
        sSaveDialogCallback = SaveReturnSuccessCallback;
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveReturnSuccessCallback(void)
{
    if (!IsSEPlaying() && SaveSuccesTimer())
    {
        HideSaveInfoWindow();
        return SAVE_SUCCESS;
    }
    else
    {
        return SAVE_IN_PROGRESS;
    }
}

static u8 SaveErrorCallback(void)
{
    if (!IsTextPrinterActiveOnWindow(0))
    {
        PlaySE(SE_BOO);
        sSaveDialogCallback = SaveReturnErrorCallback;
    }

    return SAVE_IN_PROGRESS;
}

static u8 SaveReturnErrorCallback(void)
{
    if (!SaveErrorTimer())
    {
        return SAVE_IN_PROGRESS;
    }
    else
    {
        HideSaveInfoWindow();
        return SAVE_ERROR;
    }
}

static void InitBattlePyramidRetire(void)
{
    sSaveDialogCallback = BattlePyramidConfirmRetireCallback;
    sSavingComplete = FALSE;
}

static u8 BattlePyramidConfirmRetireCallback(void)
{
    ClearStdWindowAndFrame(GetStartMenuWindowId(), FALSE);
    RemoveStartMenuWindow();
    ShowSaveMessage(gText_BattlePyramidConfirmRetire, BattlePyramidRetireYesNoCallback);

    return SAVE_IN_PROGRESS;
}

static u8 BattlePyramidRetireYesNoCallback(void)
{
    DisplayYesNoMenuWithDefault(1); // Show Yes/No menu (No selected as default)
    sSaveDialogCallback = BattlePyramidRetireInputCallback;

    return SAVE_IN_PROGRESS;
}

static u8 BattlePyramidRetireInputCallback(void)
{
    switch (Menu_ProcessInputNoWrapClearOnChoose())
    {
    case 0: // Yes
        return SAVE_CANCELED;
    case MENU_B_PRESSED:
    case 1: // No
        HideSaveMessageWindow();
        return SAVE_SUCCESS;
    }

    return SAVE_IN_PROGRESS;
}

static void VBlankCB_LinkBattleSave(void)
{
    TransferPlttBuffer();
}

static bool32 InitSaveWindowAfterLinkBattle(u8 *state)
{
    switch (*state)
    {
    case 0:
        SetGpuReg(REG_OFFSET_DISPCNT, DISPCNT_MODE_0);
        SetVBlankCallback(NULL);
        ScanlineEffect_Stop();
        DmaClear16(3, PLTT, PLTT_SIZE);
        DmaClearLarge16(3, (void *)VRAM, VRAM_SIZE, 0x1000);
        break;
    case 1:
        ResetSpriteData();
        ResetTasks();
        ResetPaletteFade();
        ScanlineEffect_Clear();
        break;
    case 2:
        ResetBgsAndClearDma3BusyFlags(0);
        InitBgsFromTemplates(0, sBgTemplates_LinkBattleSave, ARRAY_COUNT(sBgTemplates_LinkBattleSave));
        InitWindows(sWindowTemplates_LinkBattleSave);
        LoadUserWindowBorderGfx_(0, 8, BG_PLTT_ID(14));
        Menu_LoadStdPalAt(BG_PLTT_ID(15));
        break;
    case 3:
        ShowBg(0);
        BlendPalettes(PALETTES_ALL, 16, RGB_BLACK);
        SetVBlankCallback(VBlankCB_LinkBattleSave);
        EnableInterrupts(1);
        break;
    case 4:
        return TRUE;
    }

    (*state)++;
    return FALSE;
}

void CB2_SetUpSaveAfterLinkBattle(void)
{
    if (InitSaveWindowAfterLinkBattle(&gMain.state))
    {
        CreateTask(Task_SaveAfterLinkBattle, 0x50);
        SetMainCallback2(CB2_SaveAfterLinkBattle);
    }
}

static void CB2_SaveAfterLinkBattle(void)
{
    RunTasks();
    UpdatePaletteFade();
}

static void Task_SaveAfterLinkBattle(u8 taskId)
{
    s16 *state = gTasks[taskId].data;

    if (!gPaletteFade.active)
    {
        switch (*state)
        {
        case 0:
            FillWindowPixelBuffer(0, PIXEL_FILL(1));
            AddTextPrinterParameterized2(0,
                                        FONT_NORMAL,
                                        gText_SavingDontTurnOffPower,
                                        TEXT_SKIP_DRAW,
                                        NULL,
                                        TEXT_COLOR_DARK_GRAY,
                                        TEXT_COLOR_WHITE,
                                        TEXT_COLOR_LIGHT_GRAY);
            DrawTextBorderOuter(0, 8, 14);
            PutWindowTilemap(0);
            CopyWindowToVram(0, COPYWIN_FULL);
            BeginNormalPaletteFade(PALETTES_ALL, 0, 16, 0, RGB_BLACK);

            if (gWirelessCommType != 0 && InUnionRoom())
            {
                if (Link_AnyPartnersPlayingFRLG_JP())
                {
                    *state = 1;
                }
                else
                {
                    *state = 5;
                }
            }
            else
            {
                gSoftResetDisabled = TRUE;
                *state = 1;
            }
            break;
        case 1:
            SetContinueGameWarpStatusToDynamicWarp();
            WriteSaveBlock2();
            *state = 2;
            break;
        case 2:
            if (WriteSaveBlock1Sector())
            {
                ClearContinueGameWarpStatus2();
                *state = 3;
                gSoftResetDisabled = FALSE;
            }
            break;
        case 3:
            BeginNormalPaletteFade(PALETTES_ALL, 0, 0, 16, RGB_BLACK);
            *state = 4;
            break;
        case 4:
            FreeAllWindowBuffers();
            SetMainCallback2(gMain.savedCallback);
            DestroyTask(taskId);
            break;
        case 5:
            CreateTask(Task_LinkFullSave, 5);
            *state = 6;
            break;
        case 6:
            if (!FuncIsActiveTask(Task_LinkFullSave))
            {
                *state = 3;
            }
            break;
        }
    }
}

static void ShowSaveInfoWindow(void)
{
    struct WindowTemplate saveInfoWindow = sSaveInfoWindowTemplate;
    enum Gender gender;
    u8 color;
    u32 xOffset;
    u32 yOffset;

    if (!FlagGet(FLAG_SYS_POKEDEX_GET))
    {
        saveInfoWindow.height -= 2;
    }

    sSaveInfoWindowId = AddWindow(&saveInfoWindow);
    DrawStdWindowFrame(sSaveInfoWindowId, FALSE);

    gender = gSaveBlock2Ptr->playerGender;
    color = TEXT_COLOR_RED;  // Red when female, blue when male.

    if (gender == MALE)
        color = TEXT_COLOR_BLUE;

    // Print region name
    yOffset = 1;
    BufferSaveMenuText(SAVE_MENU_LOCATION, gStringVar4, TEXT_COLOR_GREEN);
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gStringVar4, 0, yOffset, TEXT_SKIP_DRAW, NULL);

    // Print player name
    yOffset += 16;
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gText_SavingPlayer, 0, yOffset, TEXT_SKIP_DRAW, NULL);
    BufferSaveMenuText(SAVE_MENU_NAME, gStringVar4, color);
    xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gStringVar4, 0x70);
    PrintPlayerNameOnWindow(sSaveInfoWindowId, gStringVar4, xOffset, yOffset);

    // Print badge count
    yOffset += 16;
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gText_SavingBadges, 0, yOffset, TEXT_SKIP_DRAW, NULL);
    BufferSaveMenuText(SAVE_MENU_BADGES, gStringVar4, color);
    xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gStringVar4, 0x70);
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gStringVar4, xOffset, yOffset, TEXT_SKIP_DRAW, NULL);

    if (FlagGet(FLAG_SYS_POKEDEX_GET) == TRUE)
    {
        // Print Pokédex count
        yOffset += 16;
        AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gText_SavingPokedex, 0, yOffset, TEXT_SKIP_DRAW, NULL);
        BufferSaveMenuText(SAVE_MENU_CAUGHT, gStringVar4, color);
        xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gStringVar4, 0x70);
        AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gStringVar4, xOffset, yOffset, TEXT_SKIP_DRAW, NULL);
    }

    // Print play time
    yOffset += 16;
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gText_SavingTime, 0, yOffset, TEXT_SKIP_DRAW, NULL);
    BufferSaveMenuText(SAVE_MENU_PLAY_TIME, gStringVar4, color);
    xOffset = GetStringRightAlignXOffset(FONT_NORMAL, gStringVar4, 0x70);
    AddTextPrinterParameterized(sSaveInfoWindowId, FONT_NORMAL, gStringVar4, xOffset, yOffset, TEXT_SKIP_DRAW, NULL);

    CopyWindowToVram(sSaveInfoWindowId, COPYWIN_GFX);
}

static void RemoveSaveInfoWindow(void)
{
    ClearStdWindowAndFrame(sSaveInfoWindowId, FALSE);
    RemoveWindow(sSaveInfoWindowId);
}

static void Task_WaitForBattleTowerLinkSave(u8 taskId)
{
    if (!FuncIsActiveTask(Task_LinkFullSave))
    {
        DestroyTask(taskId);
        ScriptContext_Enable();
    }
}

#define tInBattleTower data[2]

void SaveForBattleTowerLink(void)
{
    u8 taskId = CreateTask(Task_LinkFullSave, 5);
    gTasks[taskId].tInBattleTower = TRUE;
    gTasks[CreateTask(Task_WaitForBattleTowerLinkSave, 6)].data[1] = taskId;
}

#undef tInBattleTower

static void HideStartMenuWindow(void)
{
#if START_MENU_USE_ICONS
    DeleteAllStartMenuIcons();
#endif
    ClearStdWindowAndFrame(GetStartMenuWindowId(), TRUE);
    RemoveStartMenuWindow();
    ScriptUnfreezeObjectEvents();
    UnlockPlayerFieldControls();
}

void HideStartMenu(void)
{
    PlaySE(SE_SELECT);
    HideStartMenuWindow();
}

void AppendToList(u8 *list, u8 *pos, u8 newEntry)
{
    list[*pos] = newEntry;
    (*pos)++;
}

static bool8 StartMenuDexNavCallback(void)
{
    CreateTask(Task_OpenDexNavFromStartMenu, 0);
    return TRUE;
}

void Script_ForceSaveGame(struct ScriptContext *ctx)
{
    SaveGame();
    ShowSaveInfoWindow();
    gMenuCallback = SaveCallback;
    sSaveDialogCallback = SaveSavingMessageCallback;
}
