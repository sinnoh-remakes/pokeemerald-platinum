EternaCityNorth_MapScripts::
	.byte 0

EternaCity_EventScript_GalacticGrunt_Basic::
	msgbox EternaCity_EventScript_GalacticGrunt_See_Msg, MSGBOX_NPC
	end

EternaCity_EventScript_BarryApproach1::
	clearflag FLAG_HIDE_BARRY_ETERNA_CITY
	addobject LOCALID_BARRY_ETERNA_CITY, MAP_ETERNA_CITY_NORTH
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach1_Movement
	waitmovement 0
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach1_Push
	waitmovement 0
	applymovement LOCALID_PLAYER, EternaCity_EventScript_BarryApproach1_PlayerPushed
	waitmovement 0
	lock
	msgbox EternaCity_Text_BarryApproach1_BarryMsg, MSGBOX_DEFAULT
	release
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach1_MoveAroundPlayer
	waitmovement 0
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach1_MoveToStatue
	applymovement LOCALID_PLAYER, EternaCity_EventScript_BarryApproach1_PlayerFollowBarry
	waitmovement 0
	lock
	msgbox EternaCity_Text_BarryApproach1_BarryMsg2, MSGBOX_DEFAULT
	release
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, EternaCity_EventScript_BarryApproach1_InevitableCameraPan
	waitmovement 0
	lock
	msgbox EternaCity_Text_BarryApproach1_CyrusQuiet, MSGBOX_DEFAULT
	release
	applymovement LOCALID_CAMERA, EternaCity_EventScript_BarryApproach1_InevitableCameraPan2
	applymovement LOCALID_CYRUS_ETERNA, EternaCity_EventScript_BarryApproach1_CyrusApproach
	waitmovement 0
	special RemoveCameraObject
	lock
	msgbox EternaCity_Text_BarryApproach1_CyrusStepAside, MSGBOX_DEFAULT
	release
	applymovement LOCALID_PLAYER, EternaCity_EventScript_BarryApproach1_PlayerStepAside
	applymovement LOCALID_CYRUS_ETERNA, EternaCity_EventScript_BarryApproach1_CyrusLeave
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach1_BarryLookAtCyrus
	waitmovement LOCALID_CYRUS_ETERNA
	waitmovement 0
	removeobject LOCALID_CYRUS_ETERNA
	setflag FLAG_HIDE_GALACTIC_ETERNA
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach1_LookAtPlayer
	applymovement LOCALID_PLAYER, EternaCity_EventScript_BarryApproach1_LookAtBarry
	waitmovement 0
	lock
	msgbox EternaCity_Text_BarryApproach1_BarryAdvice, MSGBOX_DEFAULT
	release
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach1_BarryGoByeBye
	waitmovement 0
	setvar VAR_ETERNA_CITY_STATE, 1
	setflag FLAG_HIDE_BARRY_ETERNA_CITY
	removeobject LOCALID_BARRY_ETERNA_CITY
	end

EternaCity_EventScript_BarryApproach2::
	clearflag FLAG_HIDE_BARRY_ETERNA_CITY
	addobject LOCALID_BARRY_ETERNA_CITY, MAP_ETERNA_CITY_NORTH
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach2_Movement
	waitmovement 0
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach1_Push
	waitmovement 0
	applymovement LOCALID_PLAYER, EternaCity_EventScript_BarryApproach1_PlayerPushed
	waitmovement 0
	lock
	msgbox EternaCity_Text_BarryApproach1_BarryMsg, MSGBOX_DEFAULT
	release
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach1_MoveAroundPlayer
	waitmovement 0
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach2_MoveToStatue
	applymovement LOCALID_PLAYER, EternaCity_EventScript_BarryApproach2_PlayerFollowBarry
	waitmovement 0
	lock
	msgbox EternaCity_Text_BarryApproach1_BarryMsg2, MSGBOX_DEFAULT
	release
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, EternaCity_EventScript_BarryApproach1_InevitableCameraPan
	waitmovement 0
	lock
	msgbox EternaCity_Text_BarryApproach1_CyrusQuiet, MSGBOX_DEFAULT
	release
	applymovement LOCALID_CAMERA, EternaCity_EventScript_BarryApproach1_InevitableCameraPan2
	applymovement LOCALID_CYRUS_ETERNA, EternaCity_EventScript_BarryApproach1_CyrusApproach
	waitmovement 0
	special RemoveCameraObject
	lock
	msgbox EternaCity_Text_BarryApproach1_CyrusStepAside, MSGBOX_DEFAULT
	release
	applymovement LOCALID_PLAYER, EternaCity_EventScript_BarryApproach1_PlayerStepAside
	applymovement LOCALID_CYRUS_ETERNA, EternaCity_EventScript_BarryApproach1_CyrusLeave
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach1_BarryLookAtCyrus
	waitmovement LOCALID_CYRUS_ETERNA
	waitmovement 0
	removeobject LOCALID_CYRUS_ETERNA
	setflag FLAG_HIDE_GALACTIC_ETERNA
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach1_LookAtPlayer
	applymovement LOCALID_PLAYER, EternaCity_EventScript_BarryApproach1_LookAtBarry
	waitmovement 0
	lock
	msgbox EternaCity_Text_BarryApproach1_BarryAdvice, MSGBOX_DEFAULT
	release
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach1_BarryGoByeBye
	waitmovement 0
	setvar VAR_ETERNA_CITY_STATE, 1
	setflag FLAG_HIDE_BARRY_ETERNA_CITY
	removeobject LOCALID_BARRY_ETERNA_CITY
	end

EternaCity_EventScript_BarryApproach3::
	clearflag FLAG_HIDE_BARRY_ETERNA_CITY
	addobject LOCALID_BARRY_ETERNA_CITY, MAP_ETERNA_CITY_NORTH
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach3_Movement
	waitmovement 0
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach1_Push
	waitmovement 0
	applymovement LOCALID_PLAYER, EternaCity_EventScript_BarryApproach1_PlayerPushed
	waitmovement 0
	lock
	msgbox EternaCity_Text_BarryApproach1_BarryMsg, MSGBOX_DEFAULT
	release
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach1_MoveAroundPlayer
	waitmovement 0
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach3_MoveToStatue
	applymovement LOCALID_PLAYER, EternaCity_EventScript_BarryApproach3_PlayerFollowBarry
	waitmovement 0
	lock
	msgbox EternaCity_Text_BarryApproach1_BarryMsg2, MSGBOX_DEFAULT
	release
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, EternaCity_EventScript_BarryApproach1_InevitableCameraPan
	waitmovement 0
	lock
	msgbox EternaCity_Text_BarryApproach1_CyrusQuiet, MSGBOX_DEFAULT
	release
	applymovement LOCALID_CAMERA, EternaCity_EventScript_BarryApproach1_InevitableCameraPan2
	applymovement LOCALID_CYRUS_ETERNA, EternaCity_EventScript_BarryApproach1_CyrusApproach
	waitmovement 0
	special RemoveCameraObject
	lock
	msgbox EternaCity_Text_BarryApproach1_CyrusStepAside, MSGBOX_DEFAULT
	release
	applymovement LOCALID_PLAYER, EternaCity_EventScript_BarryApproach1_PlayerStepAside
	applymovement LOCALID_CYRUS_ETERNA, EternaCity_EventScript_BarryApproach1_CyrusLeave
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach1_BarryLookAtCyrus
	waitmovement LOCALID_CYRUS_ETERNA
	removeobject LOCALID_CYRUS_ETERNA
	setflag FLAG_HIDE_GALACTIC_ETERNA
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach1_LookAtPlayer
	applymovement LOCALID_PLAYER, EternaCity_EventScript_BarryApproach1_LookAtBarry
	waitmovement 0
	lock
	msgbox EternaCity_Text_BarryApproach1_BarryAdvice, MSGBOX_DEFAULT
	release
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach1_BarryGoByeBye
	waitmovement 0
	setvar VAR_ETERNA_CITY_STATE, 1
	setflag FLAG_HIDE_BARRY_ETERNA_CITY
	removeobject LOCALID_BARRY_ETERNA_CITY
	end

EternaCity_EventScript_BarryApproach1_Movement:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_right
	step_end

EternaCity_EventScript_BarryApproach1_Push:
	walk_faster_right
	step_end

EternaCity_EventScript_BarryApproach1_PlayerPushed:
	walk_faster_right
	face_left
	step_end

EternaCity_EventScript_BarryApproach1_MoveAroundPlayer:
	walk_up
	walk_right
	walk_right
	walk_down
	step_end

EternaCity_EventScript_BarryApproach1_PlayerFollowBarry:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_right
	walk_right
	step_end

EternaCity_EventScript_BarryApproach1_InevitableCameraPan:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	step_end

EternaCity_EventScript_BarryApproach1_MoveToStatue:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_right
	walk_right
	walk_up
	face_right
	step_end

EternaCity_EventScript_BarryApproach1_InevitableCameraPan2:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

EternaCity_EventScript_BarryApproach1_CyrusApproach:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	face_left
	step_end

EternaCity_EventScript_BarryApproach1_PlayerStepAside:
	walk_down
	face_left
	step_end

EternaCity_EventScript_BarryApproach1_CyrusLeave:
	walk_left
	walk_left
	walk_left
	walk_diag_southwest
	walk_diag_southwest
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

EternaCity_EventScript_BarryApproach1_BarryLookAtCyrus:
	face_left
	step_end

EternaCity_EventScript_BarryApproach1_LookAtPlayer:
	walk_fast_down
	step_end

EternaCity_EventScript_BarryApproach1_BarryGoByeBye:
	walk_fast_left
	walk_fast_left
	walk_diag_southwest
	walk_diag_southwest
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

EternaCity_EventScript_BarryApproach1_LookAtBarry:
	face_up
	step_end

EternaCity_EventScript_BarryApproach2_Movement:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_right
	step_end

EternaCity_EventScript_BarryApproach2_MoveToStatue:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_right
	walk_right
	walk_up
	face_right
	step_end

EternaCity_EventScript_BarryApproach2_PlayerFollowBarry:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_right
	walk_right
	step_end

EternaCity_EventScript_BarryApproach3_Movement:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_right
	step_end

EternaCity_EventScript_BarryApproach3_MoveToStatue:
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_right
	walk_right
	walk_up
	face_right
	step_end

EternaCity_EventScript_BarryApproach3_PlayerFollowBarry:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_right
	walk_right
	step_end

EternaCity_EventScript_GalacticGrunt_See_Msg:
	.string "Hey, you! Yeah, you, Trainer!\p"
	.string "Err...\n"
	.string "It's OK. Never mind. You look tough.\p"
	.string "I won't take... Um, I'll just let you\n"
	.string "keep your POKéMON. Carry on!$"

EternaCity_Text_BarryApproach1_BarryMsg:
	.string "Barry: THUD!\p"
	.string "Hey, {PLAYER}!\p"
	.string "You came to see the POKéMON,\n"
	.string "right? I'll take you there!$"

EternaCity_Text_BarryApproach1_BarryMsg2:
	.string "Barry: What the...$"

EternaCity_Text_BarryApproach1_CyrusQuiet:
	.string "Cyrus: ...So, this is Eterna's POKéMON\n"
	.string "statue...\p"
	.string "Shaping our world are time and space\n"
	.string "in an intertwining spiral.\p"
	.string "Revered in Sinnoh are the POKéMON of\n"
	.string "time and space...\p"
	.string "Sinnoh's myth...\n"
	.string "Its truth needs investigation...$"

EternaCity_Text_BarryApproach1_CyrusStepAside:
	.string "...Pardon me.\n"
	.string "Stand aside.$"

EternaCity_Text_BarryApproach1_BarryAdvice:
	.string "Barry: Oh, hey!\p"
	.string "When we smacked together, a brilliant\n"
	.string "flash of inspiration came to me!\p"
	.string "An easy way to become a great Trainer!\n"
	.string "Yeah, that!\p"
	.string "All right.\n"
	.string "Listen close...\p"
	.string "Make certain all your attacks hit!\n"
	.string "Avoid enemy attacks for sure!\p"
	.string "You do that, you'd never lose!\n"
	.string "You'd be the invincible Trainer!\p"
	.string "Anyway, go check out the POKéMON\n"
	.string "statue. See you around!$"
