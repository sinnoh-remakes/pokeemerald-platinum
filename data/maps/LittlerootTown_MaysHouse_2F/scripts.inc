LittlerootTown_MaysHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_2F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MaysHouse_2F_OnFrame
	.byte 0

LittlerootTown_MaysHouse_2F_OnTransition:
	end

LittlerootTown_MaysHouse_2F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 4, LittlerootTown_MaysHouse_2F_EventScript_MeetRival
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
	setvar VAR_LITTLEROOT_INTRO_STATE, 5
	setvar VAR_LITTLEROOT_TOWN_STATE, 1
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	msgbox LittlerootTown_MaysHouse_2F_TakeBag, MSGBOX_SIGN
	applymovement LOCALID_RIVAL, Common_Movement_FaceLeft
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox LittlerootTown_MaysHouse_2F_GoingLake, MSGBOX_SIGN
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_RivalRun1
	waitmovement 0
	applymovement LOCALID_PLAYER, LittlerootTown_MaysHouse_2F_Movement_BumpPlayer
	applymovement LOCALID_RIVAL, LittlerootTown_MaysHouse_2F_Movement_RivalRun2
	waitmovement 0
	removeobject LOCALID_RIVAL
	release
	end

LittlerootTown_MaysHouse_2F_Movement_RivalRun1:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end
	
LittlerootTown_MaysHouse_2F_Movement_RivalRun2:
	walk_fast_left
	step_end

LittlerootTown_MaysHouse_2F_Movement_BumpPlayer:
	walk_fast_down
	face_up
	step_end

LittlerootTown_MaysHouse_2F_TakeBag:
	.string "{RIVAL}: ...I'd better take\n"
	.string "my Bag and Journal, too...$"

@ TODO: Add dollar sign ₽
LittlerootTown_MaysHouse_2F_GoingLake:
	.string "Oh hey! {PLAYER}!\p"
	.string "I'll be waiting on the road!\n"
	.string "It's a 10 million fine if you're late!$"
