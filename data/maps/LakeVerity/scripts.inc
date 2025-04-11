.set LOCALID_RIVAL, 1
.set LOCALID_CYRUS, 2

LakeVerity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LakeVerity_OnFrame
	.byte 0

	@ State descriptions for VAR_VERITY_STATE
	@ 1: After First Lake Scene

LakeVerity_OnFrame:
	map_script_2 VAR_VERITY_STATE, 0, LakeVerity_EventScript_IntroScene
	.2byte 0

LakeVerity_EventScript_IntroScene::
	lock
	special SpawnCameraObject
	setvar VAR_VERITY_STATE, 1
	setvar VAR_ROUTE201_STATE, 4
	setflag FLAG_HIDE_ROUTE_201_RIVAL
	msgbox LakeVerity_Text_WhatsGoing, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_CAMERA, LakeVerity_Movement_CameraPan1
	waitmovement 0
	delay 48
	msgbox LakeVerity_Text_TimeSpace, MSGBOX_SIGN
	delay 48
	delay 48
	applymovement OBJ_EVENT_ID_CAMERA, LakeVerity_Movement_CameraPan2
	applymovement LOCALID_CYRUS, LakeVerity_Movement_CyrusLeave1
	waitmovement 0
	delay 10
	msgbox LakeVerity_Text_AllowPass, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceLeft
	waitmovement 0
	applymovement LOCALID_CYRUS, LakeVerity_Movement_CyrusLeave2
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_CYRUS
	delay 48
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox LakeVerity_Text_WhatsAbout, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 48
	msgbox LakeVerity_Text_LetsCatch, MSGBOX_DEFAULT
	@ FODO: Play mesprit sound
	msgbox LakeVerity_Text_Kyaun, MSGBOX_SIGN
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	applymovement LOCALID_RIVAL, LakeVerity_Movement_RunUp
	waitmovement 0
	delay 48
	delay 48
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 10
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 10
	applymovement LOCALID_RIVAL, LakeVerity_Movement_RunDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 48
	applymovement LOCALID_RIVAL, LakeVerity_Movement_Scurry
	waitmovement 0
	msgbox LakeVerity_Text_HearThat, MSGBOX_SIGN
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	msgbox LakeVerity_Text_NoBalls, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	applymovement LOCALID_RIVAL, LakeVerity_Movement_RivalLeave
	waitmovement 0
	playse SE_EXIT
	destroyfollower
	removeobject LOCALID_RIVAL
	special RemoveCameraObject
	setflag FLAG_HIDE_VERITY_INTRO
	release
	end

LakeVerity_Movement_CameraPan1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LakeVerity_Movement_CameraPan2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeVerity_Movement_CyrusLeave1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeVerity_Movement_CyrusLeave2:
	walk_down
	walk_down
	step_end

LakeVerity_Movement_RunUp:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

LakeVerity_Movement_RunDown:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

LakeVerity_Movement_Scurry:
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	walk_in_place_fast_left
	step_end

LakeVerity_Movement_RivalLeave:
	walk_fast_down
	walk_fast_down
	step_end

LakeVerity_Text_WhatsGoing:
	.string "{RIVAL}: What's going on...?$"

LakeVerity_Text_TimeSpace:
	.string "...The flowing time...\n"
	.string "...The expanding space...\p"
	.string "I will make it all mine one day...\n"
	.string "Cyrus is my name. Remember it...\p"
	.string "Until then, sleep while you can,\n"
	.string "legendary Pokémon of the lake bed...$"

LakeVerity_Text_AllowPass:
	.string "Allow me to pass.\n"
	.string "Step aside.$"

LakeVerity_Text_WhatsAbout:
	.string "{RIVAL}: What was that about?\n"
	.string "Weird guy...$"

LakeVerity_Text_LetsCatch:
	.string "OK, {PLAYER}!\n"
	.string "Let's catch that legendary Pokémon!$"

LakeVerity_Text_Kyaun:
	.string "Kyauuun!$"

LakeVerity_Text_HearThat:
	.string "{RIVAL}: !\n"
	.string "Did you hear that, {PLAYER}?!\p"
	.string "That was the legendary Pokémon crying!\n"
	.string "That had to be it!\p"
	.string "OK! This is our chance!\n"
	.string "Let's catch it!$"

LakeVerity_Text_NoBalls:
	.string "...Wait!\n"
	.string "What...?!\p"
	.string "We don't have anything on us!\p"
	.string "You know, Poké Balls!\n"
	.string "P-O-K-accent-E-Balls!\p"
	.string "If we don't have those, we can't catch\n"
	.string "Pokémon or take them around with us!\p"
	.string "...Do you think Prof. Rowan'd give us\n"
	.string "some if we asked him?\p"
	.string "You know, you remember what he said,\n"
	.string "don't you?\p"
	.string "He said to visit him at his lab if we\n"
	.string "needed anything.\p"
	.string "OK, {PLAYER}!\n"
	.string "I'll race you!\p"
	.string "First one to the professor's lab in\n"
	.string "Sandgem Town rules!$"
