EternaCityNorth_MapScripts::
	.byte 0

@ if the var ETERNA_CITY_STATE is 0, then eligble for Barry Cutscene
@ if the var ETERNA_CITY_STATE is 1, then eligble for Cynthia Cutscene
EternaCityNorth_EventScript_GalacticGrunt_Basic::
	msgbox EternaCityNorth_EventScript_GalacticGrunt_See_Msg, MSGBOX_NPC
	end

EternaCityNorth_EventScript_BarryApproach1::
	lock
	clearflag FLAG_HIDE_BARRY_ETERNA_CITY
	addobject LOCALID_BARRY_ETERNA_CITY, MAP_ETERNA_CITY_NORTH
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCityNorth_Movement_BarryApproach1_Rush
	waitmovement 0
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCityNorth_Movement_BarryApproach1_Push
	waitmovement 0
	applymovement LOCALID_PLAYER, EternaCityNorth_Movement_BarryApproach1_PlayerPushed
	waitmovement 0
	playbgm MUS_DP_RIVAL, TRUE
	call EternaCityNorth_EventScript_BarryThud
	closemessage
	call EternaCityNorth_EventScript_BarryPrimaryMsg
	closemessage
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCityNorth_Movement_BarryApproach1_MoveAroundPlayer
	waitmovement 0
	delay 20
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCityNorth_Movement_BarryApproach1_MoveToStatue
	applymovement LOCALID_PLAYER, EternaCityNorth_Movement_BarryApproach1_PlayerFollowBarry
	waitmovement 0
	call EternaCityNorth_EventScript_BarrySecondaryMsg
	closemessage
	playbgm MUS_DP_RIVAL, FALSE
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, EternaCityNorth_Movement_BarryApproach1_InevitableCameraPan
	waitmovement 0
	call EternaCityNorth_EventScript_CyrusMain
	closemessage
	applymovement LOCALID_CAMERA, EternaCityNorth_Movement_BarryApproach1_InevitableCameraPan2
	applymovement LOCALID_CYRUS_ETERNA, EternaCityNorth_Movement_BarryApproach1_CyrusApproach
	waitmovement 0
	special RemoveCameraObject
	call EternaCityNorth_EventScript_CyrusStepAside
	closemessage
	applymovement LOCALID_PLAYER, EternaCityNorth_Movement_BarryApproach1_PlayerStepAside
	applymovement LOCALID_CYRUS_ETERNA, EternaCityNorth_Movement_BarryApproach1_CyrusLeave
	applymovement LOCALID_BARRY_ETERNA_CITY, Common_Movement_WalkInPlaceFasterLeft
	waitmovement LOCALID_CYRUS_ETERNA
	waitmovement 0
	removeobject LOCALID_CYRUS_ETERNA
	setflag FLAG_HIDE_CYRUS_ETERNA
	applymovement LOCALID_BARRY_ETERNA_CITY, Common_Movement_WalkDownFast
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	call EternaCityNorth_EventScript_BarrysAdvice
	closemessage
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCityNorth_Movement_BarryApproach1_BarryGoByeBye
	waitmovement 0
	setvar VAR_ETERNA_CITY_STATE, 1
	setflag FLAG_HIDE_BARRY_ETERNA_CITY
	removeobject LOCALID_BARRY_ETERNA_CITY
	release
	end

EternaCityNorth_EventScript_BarryApproach2::
	lock
	clearflag FLAG_HIDE_BARRY_ETERNA_CITY
	addobject LOCALID_BARRY_ETERNA_CITY, MAP_ETERNA_CITY_NORTH
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCityNorth_Movement_BarryApproach2_Rush
	waitmovement 0
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCityNorth_Movement_BarryApproach1_Push
	waitmovement 0
	applymovement LOCALID_PLAYER, EternaCityNorth_Movement_BarryApproach1_PlayerPushed
	waitmovement 0
	playbgm MUS_DP_RIVAL, TRUE
	call EternaCityNorth_EventScript_BarryThud
	closemessage
	call EternaCityNorth_EventScript_BarryPrimaryMsg
	closemessage
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCityNorth_Movement_BarryApproach2_MoveAroundPlayer
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	delay 20
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCityNorth_Movement_BarryApproach2_MoveAroundContinue
	waitmovement 0
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCityNorth_Movement_BarryApproach2_MoveToStatue
	applymovement LOCALID_PLAYER, EternaCityNorth_Movement_BarryApproach2_PlayerFollowBarry
	waitmovement 0
	call EternaCityNorth_EventScript_BarrySecondaryMsg
	closemessage
	playbgm MUS_DP_RIVAL, FALSE
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, EternaCityNorth_Movement_BarryApproach1_InevitableCameraPan
	waitmovement 0
	call EternaCityNorth_EventScript_CyrusMain
	closemessage
	applymovement LOCALID_CAMERA, EternaCityNorth_Movement_BarryApproach1_InevitableCameraPan2
	applymovement LOCALID_CYRUS_ETERNA, EternaCityNorth_Movement_BarryApproach1_CyrusApproach
	waitmovement 0
	special RemoveCameraObject
	call EternaCityNorth_EventScript_CyrusStepAside
	closemessage
	applymovement LOCALID_PLAYER, EternaCityNorth_Movement_BarryApproach1_PlayerStepAside
	applymovement LOCALID_CYRUS_ETERNA, EternaCityNorth_Movement_BarryApproach1_CyrusLeave
	applymovement LOCALID_BARRY_ETERNA_CITY, Common_Movement_WalkInPlaceFasterLeft
	waitmovement LOCALID_CYRUS_ETERNA
	waitmovement 0
	removeobject LOCALID_CYRUS_ETERNA
	setflag FLAG_HIDE_CYRUS_ETERNA
	applymovement LOCALID_BARRY_ETERNA_CITY, Common_Movement_WalkDownFast
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	call EternaCityNorth_EventScript_BarrysAdvice
	closemessage
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCityNorth_Movement_BarryApproach1_BarryGoByeBye
	waitmovement 0
	setvar VAR_ETERNA_CITY_STATE, 1
	setflag FLAG_HIDE_BARRY_ETERNA_CITY
	removeobject LOCALID_BARRY_ETERNA_CITY
	release
	end

EternaCityNorth_EventScript_BarryApproach3::
	lock
	clearflag FLAG_HIDE_BARRY_ETERNA_CITY
	addobject LOCALID_BARRY_ETERNA_CITY, MAP_ETERNA_CITY_NORTH
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCityNorth_Movement_BarryApproach3_Rush
	waitmovement 0
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCityNorth_Movement_BarryApproach1_Push
	waitmovement 0
	applymovement LOCALID_PLAYER, EternaCityNorth_Movement_BarryApproach1_PlayerPushed
	waitmovement 0
	playbgm MUS_DP_RIVAL, TRUE
	call EternaCityNorth_EventScript_BarryThud
	closemessage
	call EternaCityNorth_EventScript_BarryPrimaryMsg
	closemessage
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCityNorth_Movement_BarryApproach3_MoveAroundPlayer
	waitmovement 0
	delay 20
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCityNorth_Movement_BarryApproach3_MoveToStatue
	applymovement LOCALID_PLAYER, EternaCityNorth_Movement_BarryApproach3_PlayerFollowBarry
	waitmovement 0
	call EternaCityNorth_EventScript_BarrySecondaryMsg
	closemessage
	playbgm MUS_DP_RIVAL, FALSE
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, EternaCityNorth_Movement_BarryApproach1_InevitableCameraPan
	waitmovement 0
	call EternaCityNorth_EventScript_CyrusMain
	closemessage
	applymovement LOCALID_CAMERA, EternaCityNorth_Movement_BarryApproach1_InevitableCameraPan2
	applymovement LOCALID_CYRUS_ETERNA, EternaCityNorth_Movement_BarryApproach1_CyrusApproach
	waitmovement 0
	special RemoveCameraObject
	call EternaCityNorth_EventScript_CyrusStepAside
	closemessage
	applymovement LOCALID_PLAYER, EternaCityNorth_Movement_BarryApproach1_PlayerStepAside
	applymovement LOCALID_CYRUS_ETERNA, EternaCityNorth_Movement_BarryApproach1_CyrusLeave
	applymovement LOCALID_BARRY_ETERNA_CITY, Common_Movement_WalkInPlaceFasterLeft
	waitmovement LOCALID_CYRUS_ETERNA
	waitmovement 0
	removeobject LOCALID_CYRUS_ETERNA
	setflag FLAG_HIDE_CYRUS_ETERNA
	applymovement LOCALID_BARRY_ETERNA_CITY, Common_Movement_WalkDownFast
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	call EternaCityNorth_EventScript_BarrysAdvice
	closemessage
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCityNorth_Movement_BarryApproach1_BarryGoByeBye
	waitmovement 0
	setvar VAR_ETERNA_CITY_STATE, 1
	setflag FLAG_HIDE_BARRY_ETERNA_CITY
	removeobject LOCALID_BARRY_ETERNA_CITY
	release
	end


@ text calls
EternaCityNorth_EventScript_BarryThud::
	msgbox EternaCityNorth_Text_BarryThud, MSGBOX_DEFAULT
	return

EternaCityNorth_EventScript_BarryPrimaryMsg::
	msgbox EternaCityNorth_Text_BarryApproach1_BarryMsg, MSGBOX_DEFAULT
	return

EternaCityNorth_EventScript_BarrySecondaryMsg::
	msgbox EternaCityNorth_Text_BarryApproach1_BarryMsg2, MSGBOX_DEFAULT
	return

EternaCityNorth_EventScript_CyrusMain::
	msgbox EternaCityNorth_Text_BarryApproach1_CyrusQuiet, MSGBOX_DEFAULT
	return

EternaCityNorth_EventScript_CyrusStepAside::
	msgbox EternaCityNorth_Text_BarryApproach1_CyrusStepAside, MSGBOX_DEFAULT
	return

EternaCityNorth_EventScript_BarrysAdvice::
	msgbox EternaCityNorth_Text_BarryApproach1_BarryAdvice, MSGBOX_DEFAULT
	return


@ Cynthia cutscene
EternaCityNorth_EventScript_CynthiaApproach1::
	lock
	clearflag FLAG_HIDE_CYNTHIA_ETERNA_CITY
	addobject LOCALID_CYNTHIA_ETERNA, MAP_ETERNA_CITY_NORTH
	setobjectxy LOCALID_CYNTHIA_ETERNA, 24, 12
	delay 45
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCityNorth_Movement_CynthiaApproach_Movement1
	waitmovement 0
	playse SE_PIN
	waitse
	delay 30
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCityNorth_Movement_CynthiaApproach_Movement2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	call EternaCityNorth_EventScript_CynthiaText1
	closemessage
	applymovement LOCALID_CYNTHIA_ETERNA, Common_Movement_FaceRight
	waitmovement 0
	delay 45
	applymovement LOCALID_CYNTHIA_ETERNA, Common_Movement_FaceLeft
	waitmovement 0
	call EternaCityNorth_EventScript_CynthiaText2
	closemessage
	giveitem ITEM_HM01
	setflag FLAG_RECEIVED_HM_CUT
	waitmessage
	call EternaCityNorth_EventScript_CynthiaText3
	closemessage
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCityNorth_Movement_CynthiaApproach_Leave
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement LOCALID_CYNTHIA_ETERNA
	setflag FLAG_HIDE_CYNTHIA_ETERNA_CITY
	removeobject LOCALID_CYNTHIA_ETERNA
	setvar VAR_ETERNA_CITY_STATE, 2
	release
	end

EternaCityNorth_EventScript_CynthiaApproach2::
	lock
	clearflag FLAG_HIDE_CYNTHIA_ETERNA_CITY
	addobject LOCALID_CYNTHIA_ETERNA, MAP_ETERNA_CITY_NORTH
	setobjectxy LOCALID_CYNTHIA_ETERNA, 24, 13
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCityNorth_Movement_CynthiaApproach_Movement1
	waitmovement 0
	playse SE_PIN
	waitse
	delay 30
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCityNorth_Movement_CynthiaApproach_Movement2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	call EternaCityNorth_EventScript_CynthiaText1
	closemessage
	applymovement LOCALID_CYNTHIA_ETERNA, Common_Movement_FaceRight
	waitmovement 0
	delay 45
	applymovement LOCALID_CYNTHIA_ETERNA, Common_Movement_FaceLeft
	waitmovement 0
	call EternaCityNorth_EventScript_CynthiaText2
	closemessage
	giveitem ITEM_HM01
	setflag FLAG_RECEIVED_HM_CUT
	waitmessage
	call EternaCityNorth_EventScript_CynthiaText3
	closemessage
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCityNorth_Movement_CynthiaApproach_Leave
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement LOCALID_CYNTHIA_ETERNA
	setflag FLAG_HIDE_CYNTHIA_ETERNA_CITY
	removeobject LOCALID_CYNTHIA_ETERNA
	setvar VAR_ETERNA_CITY_STATE, 2
	release
	end

EternaCityNorth_EventScript_CynthiaApproach3::
	lock
	clearflag FLAG_HIDE_CYNTHIA_ETERNA_CITY
	addobject LOCALID_CYNTHIA_ETERNA, MAP_ETERNA_CITY_NORTH
	setobjectxy LOCALID_CYNTHIA_ETERNA, 24, 14
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCityNorth_Movement_CynthiaApproach_Movement1
	waitmovement 0
	playse SE_PIN
	waitse
	delay 30
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCityNorth_Movement_CynthiaApproach_Movement2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	call EternaCityNorth_EventScript_CynthiaText1
	closemessage
	applymovement LOCALID_CYNTHIA_ETERNA, Common_Movement_FaceRight
	waitmovement 0
	delay 45
	applymovement LOCALID_CYNTHIA_ETERNA, Common_Movement_FaceLeft
	waitmovement 0
	call EternaCityNorth_EventScript_CynthiaText2
	closemessage
	giveitem ITEM_HM01
	setflag FLAG_RECEIVED_HM_CUT
	waitmessage
	call EternaCityNorth_EventScript_CynthiaText3
	closemessage
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCityNorth_Movement_CynthiaApproach_Leave2
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement LOCALID_CYNTHIA_ETERNA
	setflag FLAG_HIDE_CYNTHIA_ETERNA_CITY
	removeobject LOCALID_CYNTHIA_ETERNA
	setvar VAR_ETERNA_CITY_STATE, 2
	release
	end

@ Cynthia cutscene text scripts
EternaCityNorth_EventScript_CynthiaText1::
	msgbox EternaCityNorth_Text_Cynthia1, MSGBOX_DEFAULT
	return

EternaCityNorth_EventScript_CynthiaText2::
	msgbox EternaCityNorth_Text_Cynthia2, MSGBOX_DEFAULT
	return

EternaCityNorth_EventScript_CynthiaText3::
	msgbox EternaCityNorth_Text_Cynthia3, MSGBOX_DEFAULT
	return

EternaCityNorth_Movement_BarryApproach1_Rush:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	step_end

EternaCityNorth_Movement_BarryApproach1_Push:
	walk_faster_right
	step_end

EternaCityNorth_Movement_BarryApproach1_PlayerPushed:
	walk_faster_right
	face_left
	step_end

EternaCityNorth_Movement_BarryApproach1_MoveAroundPlayer:
	walk_up
	walk_right
	face_down
	step_end

EternaCityNorth_Movement_BarryApproach1_PlayerFollowBarry:
	walk_up
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
	walk_slow_diag_northeast @ stairs
	walk_slow_diag_northeast @ stairs
	walk_right
	walk_down
	walk_right
	step_end

EternaCityNorth_Movement_BarryApproach1_InevitableCameraPan:
	walk_slow_right
	walk_slow_right
	walk_slow_right
	walk_slow_right
	step_end

EternaCityNorth_Movement_BarryApproach1_MoveToStatue:
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
	walk_slow_diag_northeast @ stairs
	walk_slow_diag_northeast @ stairs
	walk_right
	walk_right
	face_right
	step_end

EternaCityNorth_Movement_BarryApproach1_InevitableCameraPan2:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

EternaCityNorth_Movement_BarryApproach1_CyrusApproach:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	face_left
	step_end

EternaCityNorth_Movement_BarryApproach1_PlayerStepAside:
	walk_down
	face_left
	step_end

EternaCityNorth_Movement_BarryApproach1_CyrusLeave:
	walk_left
	walk_left
	walk_left
	walk_left @ stairs
	walk_left @ stairs
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

EternaCityNorth_Movement_BarryApproach1_LookAtPlayer:
	walk_fast_down
	step_end

EternaCityNorth_Movement_BarryApproach1_BarryGoByeBye:
	walk_fast_left
	walk_fast_left
	walk_diag_southwest @ stairs
	walk_diag_southwest @ stairs
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

EternaCityNorth_Movement_BarryApproach2_Rush:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	step_end

EternaCityNorth_Movement_BarryApproach2_MoveAroundPlayer:
	walk_down
	walk_right
	face_up
	step_end

EternaCityNorth_Movement_BarryApproach2_MoveAroundContinue:
	walk_right
	walk_up
	step_end

EternaCityNorth_Movement_BarryApproach2_MoveToStatue:
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
	walk_slow_diag_northeast @ stairs
	walk_slow_diag_northeast @ stairs
	walk_right
	walk_right
	face_right
	step_end

EternaCityNorth_Movement_BarryApproach2_PlayerFollowBarry:
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
	walk_slow_diag_northeast @ stairs
	walk_slow_diag_northeast @ stairs
	walk_right
	walk_down
	walk_right
	step_end

EternaCityNorth_Movement_BarryApproach3_MoveAroundPlayer:
	walk_down
	walk_right
	face_up
	step_end

EternaCityNorth_Movement_BarryApproach3_Rush:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	step_end

EternaCityNorth_Movement_BarryApproach3_MoveToStatue:
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
	walk_slow_diag_northeast @ stairs
	walk_slow_diag_northeast @ stairs
	walk_right
	walk_right
	face_right
	step_end

EternaCityNorth_Movement_BarryApproach3_PlayerFollowBarry:
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
	walk_right
	walk_right
	walk_right
	walk_slow_diag_northeast @ stairs
	walk_slow_diag_northeast @ stairs
	walk_right
	walk_down
	walk_right
	step_end

EternaCityNorth_Movement_CynthiaApproach_Movement1:
	walk_left
	walk_left
	walk_left
	emote_exclamation_mark
	step_end

EternaCityNorth_Movement_CynthiaApproach_Movement2:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

EternaCityNorth_Movement_CynthiaApproach_Leave:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EternaCityNorth_Movement_CynthiaApproach_Leave2:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EternaCityNorth_EventScript_GalacticGrunt_See_Msg:
	.string "Hey, you! Yeah, you, Trainer!\p"
	.string "Err...\n"
	.string "It's OK. Never mind. You look tough.\p"
	.string "I won't take... Um, I'll just let you\n"
	.string "keep your POKéMON. Carry on!$"

EternaCityNorth_Text_BarryThud:
	.string "Barry: THUD!$"

EternaCityNorth_Text_BarryApproach1_BarryMsg:
	.string "Hey, {PLAYER}!\p"
	.string "You came to see the POKéMON,\n"
	.string "right? I'll take you there!$"

EternaCityNorth_Text_BarryApproach1_BarryMsg2:
	.string "Barry: What the...$"

EternaCityNorth_Text_BarryApproach1_CyrusQuiet:
	.string "Cyrus: ...So, this is Eterna's POKéMON\n"
	.string "statue...\p"
	.string "Shaping our world are time and space\n"
	.string "in an intertwining spiral.\p"
	.string "Revered in Sinnoh are the POKéMON of\n"
	.string "time and space...\p"
	.string "Sinnoh's myth...\n"
	.string "Its truth needs investigation...$"

EternaCityNorth_Text_BarryApproach1_CyrusStepAside:
	.string "...Pardon me.\n"
	.string "Stand aside.$"

EternaCityNorth_Text_BarryApproach1_BarryAdvice:
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

EternaCityNorth_Text_Cynthia1:
	.string "Oh, that device you have...\p"
	.string "It is a POKéDEX?\n"
	.string "Wow, it brings back some memories.\p"
	.string "Pardon me, but what's your name?\p"
	.string "...\p"
	.string "OK, hello, {PLAYER}.\n"
	.string "I'll be sure to remember that name!\p"
	.string "My name is Cynthia.\n"
	.string "I'm a Trainer just like you.\p"
	.string "I've been studying POKéMON mythology\n"
	.string "lately, just out of curiosity.$"

EternaCityNorth_Text_Cynthia2:
	.string "Here in Eterna City, there is a statue\n"
	.string "of an ancient POKéMON.\p"
	.string "Have you seen it already?\p"
	.string "According to myth, it was an extremely\n"
	.string "powerful POKéMON.\p"
	.string "Who knows? You may encounter something\n"
	.string "like it while you're travelling with your\l"
	.string "POKéDEX.\p"
	.string "Oh, I know! Try using this.\n"
	.string "It should be helpful.$"

EternaCityNorth_Text_Cynthia3:
	.string "Cynthia: Remember, the hidden move\n"
	.string "Cut, can be used in the field.\p"
	.string "It will let you go places that were\n"
	.string "previously inaccessible to you.\p"
	.string "That's important for filling up your\n"
	.string "POKéDEX, right?\p"
	.string "Then luck be with you, young Trainer!\p"
	.string "Oh, there's one last thing!\n"
	.string "Please give my regards to Prof. Rowan.$"
