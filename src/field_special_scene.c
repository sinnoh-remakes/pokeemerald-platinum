#include "global.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "field_camera.h"
#include "field_screen_effect.h"
#include "field_specials.h"
#include "fieldmap.h"
#include "main.h"
#include "overworld.h"
#include "palette.h"
#include "script.h"
#include "script_movement.h"
#include "sound.h"
#include "sprite.h"
#include "task.h"
#include "constants/event_objects.h"
#include "constants/event_object_movement.h"
#include "constants/field_specials.h"
#include "constants/songs.h"
#include "constants/metatile_labels.h"

// porthole states
enum
{
    INIT_PORTHOLE,
    IDLE_CHECK,
    EXECUTE_MOVEMENT,
    EXIT_PORTHOLE,
};

static const u8 sSSTidalSailEastMovementScript[] =
{
    MOVEMENT_ACTION_WALK_FAST_RIGHT,
    MOVEMENT_ACTION_STEP_END
};

static const u8 sSSTidalSailWestMovementScript[] =
{
    MOVEMENT_ACTION_WALK_FAST_LEFT,
    MOVEMENT_ACTION_STEP_END
};

#define unused_0 data[0]
#define unused_1 data[1]
#define unused_2 data[2]
#define unused_3 data[3]

bool8 TrySetPortholeWarpDestination(void)
{
    s8 mapGroup, mapNum;
    s16 x, y;

    if (GetSSTidalLocation(&mapGroup, &mapNum, &x, &y) != SS_TIDAL_LOCATION_CURRENTS)
    {
        return FALSE;
    }
    else
    {
        SetWarpDestination(mapGroup, mapNum, WARP_ID_NONE, x, y);
        return TRUE;
    }
}

void Task_HandlePorthole(u8 taskId)
{
    s16 *data = gTasks[taskId].data;
    u16 *cruiseState = GetVarPointer(VAR_SS_TIDAL_STATE);
    struct WarpData *location = &gSaveBlock1Ptr->location;

    switch (data[0])
    {
    case INIT_PORTHOLE: // finish fading before making porthole finish.
        if (!gPaletteFade.active)
        {
            data[1] = 0;
            data[0] = EXECUTE_MOVEMENT; // execute movement before checking if should be exited. strange?
        }
        break;
    case IDLE_CHECK:
        if (JOY_NEW(A_BUTTON))
            data[1] = 1;
        if (!ScriptMovement_IsObjectMovementFinished(OBJ_EVENT_ID_PLAYER, location->mapNum, location->mapGroup))
            return;
        if (CountSSTidalStep(1) == TRUE)
        {
            if (*cruiseState == SS_TIDAL_DEPART_SLATEPORT)
                *cruiseState = SS_TIDAL_EXIT_CURRENTS_RIGHT;
            else
                *cruiseState = SS_TIDAL_EXIT_CURRENTS_LEFT;
            data[0] = EXIT_PORTHOLE;
            return;
        }
        data[0] = EXECUTE_MOVEMENT;
        //fallthrough
    case EXECUTE_MOVEMENT:
        if (data[1])
        {
            data[0] = EXIT_PORTHOLE;
            return;
        }

        if (*cruiseState == SS_TIDAL_DEPART_SLATEPORT)
        {
            ScriptMovement_StartObjectMovementScript(OBJ_EVENT_ID_PLAYER, location->mapNum, location->mapGroup, sSSTidalSailEastMovementScript);
            data[0] = IDLE_CHECK;
        }
        else
        {
            ScriptMovement_StartObjectMovementScript(OBJ_EVENT_ID_PLAYER, location->mapNum, location->mapGroup, sSSTidalSailWestMovementScript);
            data[0] = IDLE_CHECK;
        }
        break;
    case EXIT_PORTHOLE:
        FlagClear(FLAG_DONT_TRANSITION_MUSIC);
        FlagClear(FLAG_HIDE_MAP_NAME_POPUP);
        SetWarpDestinationToDynamicWarp(0);
        DoDiveWarp();
        DestroyTask(taskId);
        break;
    }
}

static void ShowSSTidalWhileSailing(void)
{
    u8 spriteId = CreateObjectGraphicsSprite(OBJ_EVENT_GFX_SS_TIDAL, SpriteCallbackDummy, 112, 80, 0);

    gSprites[spriteId].coordOffsetEnabled = FALSE;

    if (VarGet(VAR_SS_TIDAL_STATE) == SS_TIDAL_DEPART_SLATEPORT)
        StartSpriteAnim(&gSprites[spriteId], GetFaceDirectionAnimNum(DIR_EAST));
    else
        StartSpriteAnim(&gSprites[spriteId], GetFaceDirectionAnimNum(DIR_WEST));
}

void FieldCB_ShowPortholeView(void)
{
    ShowSSTidalWhileSailing();
    gObjectEvents[gPlayerAvatar.objectEventId].invisible = TRUE;
    FadeInFromBlack();
    CreateTask(Task_HandlePorthole, 80);
    LockPlayerFieldControls();
}

void LookThroughPorthole(void)
{
    FlagSet(FLAG_SYS_CRUISE_MODE);
    FlagSet(FLAG_DONT_TRANSITION_MUSIC);
    FlagSet(FLAG_HIDE_MAP_NAME_POPUP);
    SetDynamicWarp(0, gSaveBlock1Ptr->location.mapGroup, gSaveBlock1Ptr->location.mapNum, WARP_ID_NONE);
    TrySetPortholeWarpDestination();
    DoPortholeWarp();
}
