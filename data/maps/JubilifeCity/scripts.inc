JubilifeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, JubilifeCity_OnTransition
	.byte 0

@ State descriptions For VAR_JUBILIFE_CITY_STATE
@ 1: Encounter Helper
@ 2: Encounter Looker
@ 3: Recieve a Poketch

JubilifeCity_OnTransition:
	setflag FLAG_VISITED_JUBILIFE_CITY
	call Common_EventScript_SetupRivalGfxId
	end

Jubilife_EventScript_HelperEncounter_Left::
    lockall
    applymovement 1, Common_Movement_WalkLeft
    waitmovement 0
    applymovement 1, Common_Movement_WalkDown4
    waitmovement 0
    playse SE_PIN
    applymovement 1, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement 1, Common_Movement_WalkDown3
    goto Jubilife_EventScript_Helper_Main

Jubilife_EventScript_HelperEncounter_Center::
    lockall
    applymovement 1, Common_Movement_WalkDown4
    waitmovement 0
    playse SE_PIN
    applymovement 1, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement 1, Common_Movement_WalkDown3
    goto Jubilife_EventScript_Helper_Main

Jubilife_EventScript_HelperEncounter_Right::
    lockall
    applymovement 1, Common_Movement_WalkRight
    waitmovement 0
    applymovement 1, Common_Movement_WalkDown4
    waitmovement 0
    playse SE_PIN
    applymovement 1, Common_Movement_ExclamationMark
    waitmovement 0
    applymovement 1, Common_Movement_WalkDown3
    goto Jubilife_EventScript_Helper_Main

Jubilife_EventScript_Helper_Main::
    checkplayergender
	call_if_eq VAR_RESULT, MALE, JubilifeCity_EventScript_Dawn
	call_if_eq VAR_RESULT, FEMALE, JubilifeCity_EventScript_Lucas

JubilifeCity_EventScript_Dawn::
	end

JubilifeCity_EventScript_Lucas::
	end
