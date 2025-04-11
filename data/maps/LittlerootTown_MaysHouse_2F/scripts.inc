.set LOCALID_RIVAL, 1

LittlerootTown_MaysHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MaysHouse_2F_OnFrame
	.byte 0

LittlerootTown_MaysHouse_2F_OnTransition:
	end

LittlerootTown_MaysHouse_2F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_MaysHouse_2F_EventScript_MeetRival
	.2byte 0

LittlerootTown_MaysHouse_2F_EventScript_CheckRivalsPC::
	msgbox gText_PokemonTrainerSchoolEmail, MSGBOX_DEFAULT
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_Temp::
	setobjectxyperm LOCALID_RIVAL, 5, 2
	return

LittlerootTown_MaysHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_MAYS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

LittlerootTown_MaysHouse_2F_EventScript_MeetRival::
	lock
	setvar VAR_LITTLEROOT_INTRO_STATE, 4
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox LittlerootTown_MaysHouse_2F_RivalMessage1, MSGBOX_SIGN
	applymovement LOCALID_RIVAL, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox LittlerootTown_MaysHouse_2F_RivalMessage2, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkLeft
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_RivalRun1
	waitmovement 0
	applymovement OBJ_EVENT_ID_CAMERA, Common_Movement_WalkDown
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_BumpPlayer
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_RivalRun2
	waitmovement 0
	removeobject LOCALID_RIVAL
	special RemoveCameraObject
	release
	end

LittlerootTown_MaysHouse_2F_Movement_RivalRun1:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
	
LittlerootTown_MaysHouse_2F_Movement_RivalRun2:
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end

LittlerootTown_MaysHouse_2F_Movement_BumpPlayer:
	walk_fast_down
	face_up
	step_end

LittlerootTown_MaysHouse_2F_RivalMessage1:
	.string "...I'd better take my Bag and Journal,\n"
	.string "too...$"

@ TODO: Fix dollar sign ₽
LittlerootTown_MaysHouse_2F_RivalMessage2:
	.string "Oh hey! {PLAYER}!\p"
	.string "We're going to the lake!\n"
	.string "I'll be waiting on the road!\p"
	.string "It's a 10 million fine if you're late!$"
