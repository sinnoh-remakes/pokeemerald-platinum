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
	setflag FLAG_HIDE_CYRUS_ETERNA
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
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach2_MoveAroundPlayer
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
	setflag FLAG_HIDE_CYRUS_ETERNA
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
	applymovement LOCALID_BARRY_ETERNA_CITY, EternaCity_EventScript_BarryApproach3_MoveAroundPlayer
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
	setflag FLAG_HIDE_CYRUS_ETERNA
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

EternaCity_EventScript_CynthiaApproach1::
	clearflag FLAG_HIDE_CYNTHIA_ETERNA_CITY
	addobject LOCALID_CYNTHIA_ETERNA, MAP_ETERNA_CITY_NORTH
	setobjectxy LOCALID_CYNTHIA_ETERNA, 24, 12
	delay 45
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCity_EventScript_CynthiaApproach_Movement1
	waitmovement
	playse SE_PIN
	waitse
	delay 30
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCity_EventScript_CynthiaApproach_Movement2
	waitmovement
	applymovement LOCALID_PLAYER, EternaCity_EventScript_CynthiaApproach_LookRight
	waitmovement
	lock
	msgbox EternaCity_Text_Cynthia1, MSGBOX_DEFAULT
	release
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCity_EventScript_CynthiaApproach_LookRight
	waitmovement
	delay 45
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCity_EventScript_CynthiaApproach_LookLeft
	lock
	msgbox EternaCity_Text_Cynthia2, MSGBOX_DEFAULT
	release
	giveitem ITEM_HM01
	setflag FLAG_RECEIVED_HM_CUT
	waitmessage
	lock
	msgbox EternaCity_Text_Cynthia3, MSGBOX_DEFAULT
	release
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCity_EventScript_CynthiaApproach_Leave
	applymovement LOCALID_PLAYER, EternaCity_EventScript_CynthiaApproach_LookLeft
	waitmovement LOCALID_CYNTHIA_ETERNA
	setflag FLAG_HIDE_CYNTHIA_ETERNA_CITY
	removeobject LOCALID_CYNTHIA_ETERNA
	setvar VAR_ETERNA_CITY_STATE, 2
	end

EternaCity_EventScript_CynthiaApproach2::
	clearflag FLAG_HIDE_CYNTHIA_ETERNA_CITY
	addobject LOCALID_CYNTHIA_ETERNA, MAP_ETERNA_CITY_NORTH
	setobjectxy LOCALID_CYNTHIA_ETERNA, 24, 13
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCity_EventScript_CynthiaApproach_Movement1
	waitmovement
	playse SE_PIN
	waitse
	delay 30
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCity_EventScript_CynthiaApproach_Movement2
	waitmovement
	applymovement LOCALID_PLAYER, EternaCity_EventScript_CynthiaApproach_LookRight
	waitmovement
	lock
	msgbox EternaCity_Text_Cynthia1, MSGBOX_DEFAULT
	release
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCity_EventScript_CynthiaApproach_LookRight
	waitmovement
	delay 45
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCity_EventScript_CynthiaApproach_LookLeft
	lock
	msgbox EternaCity_Text_Cynthia2, MSGBOX_DEFAULT
	release
	giveitem ITEM_HM01
	setflag FLAG_RECEIVED_HM_CUT
	waitmessage
	lock
	msgbox EternaCity_Text_Cynthia3, MSGBOX_DEFAULT
	release
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCity_EventScript_CynthiaApproach_Leave
	applymovement LOCALID_PLAYER, EternaCity_EventScript_CynthiaApproach_LookLeft
	waitmovement LOCALID_CYNTHIA_ETERNA
	setflag FLAG_HIDE_CYNTHIA_ETERNA_CITY
	removeobject LOCALID_CYNTHIA_ETERNA
	setvar VAR_ETERNA_CITY_STATE, 2
	end

EternaCity_EventScript_CynthiaApproach3::
	clearflag FLAG_HIDE_CYNTHIA_ETERNA_CITY
	addobject LOCALID_CYNTHIA_ETERNA, MAP_ETERNA_CITY_NORTH
	setobjectxy LOCALID_CYNTHIA_ETERNA, 24, 14
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCity_EventScript_CynthiaApproach_Movement1
	waitmovement
	playse SE_PIN
	waitse
	delay 30
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCity_EventScript_CynthiaApproach_Movement2
	waitmovement
	applymovement LOCALID_PLAYER, EternaCity_EventScript_CynthiaApproach_LookRight
	waitmovement
	lock
	msgbox EternaCity_Text_Cynthia1, MSGBOX_DEFAULT
	release
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCity_EventScript_CynthiaApproach_LookRight
	waitmovement
	delay 45
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCity_EventScript_CynthiaApproach_LookLeft
	lock
	msgbox EternaCity_Text_Cynthia2, MSGBOX_DEFAULT
	release
	giveitem ITEM_HM01
	setflag FLAG_RECEIVED_HM_CUT
	waitmessage
	lock
	msgbox EternaCity_Text_Cynthia3, MSGBOX_DEFAULT
	release
	applymovement LOCALID_CYNTHIA_ETERNA, EternaCity_EventScript_CynthiaApproach_Leave2
	applymovement LOCALID_PLAYER, EternaCity_EventScript_CynthiaApproach_LookLeft
	waitmovement LOCALID_CYNTHIA_ETERNA
	setflag FLAG_HIDE_CYNTHIA_ETERNA_CITY
	removeobject LOCALID_CYNTHIA_ETERNA
	setvar VAR_ETERNA_CITY_STATE, 2
	end

EternaCity_EventScript_BarryApproach1_Movement:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
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
	face_down
	step_end

EternaCity_EventScript_BarryApproach1_PlayerFollowBarry:
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
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_right
	walk_right
	walk_down
	face_right
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

EternaCity_EventScript_BarryApproach2_MoveAroundPlayer:
	walk_down
	walk_right
	walk_right
	walk_up
	step_end


EternaCity_EventScript_BarryApproach2_MoveToStatue:
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
	face_right
	step_end

EternaCity_EventScript_BarryApproach2_PlayerFollowBarry:
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
	walk_down
	face_right
	step_end

EternaCity_EventScript_BarryApproach3_MoveAroundPlayer:
	walk_down
	walk_right
	face_up
	step_end

EternaCity_EventScript_BarryApproach3_Movement:
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

EternaCity_EventScript_BarryApproach3_MoveToStatue:
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
	face_right
	step_end

EternaCity_EventScript_BarryApproach3_PlayerFollowBarry:
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
	walk_slow_diag_northeast
	walk_slow_diag_northeast
	walk_right
	walk_right
	walk_down
	face_right
	step_end

EternaCity_EventScript_CynthiaApproach_Movement1:
	walk_left
	walk_left
	walk_left
	emote_exclamation_mark
	step_end

EternaCity_EventScript_CynthiaApproach_Movement2:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

EternaCity_EventScript_CynthiaApproach_LookRight:
	face_right
	step_end

EternaCity_EventScript_CynthiaApproach_LookLeft:
	face_left
	step_end

EternaCity_EventScript_CynthiaApproach_Leave:
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

EternaCity_EventScript_CynthiaApproach_Leave2:
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

EternaCity_Text_Cynthia1:
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

EternaCity_Text_Cynthia2:
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

EternaCity_Text_Cynthia3:
	.string "Cynthia: Remember, the hidden move\n"
	.string "Cut, can be used in the field.\p"
	.string "It will let you go places that were\n"
	.string "previously inaccessible to you.\p"
	.string "That's important for filling up your\n"
	.string "POKéDEX, right?\p"
	.string "Then luck be with you, young Trainer!\p"
	.string "Oh, there's one last thing!\n"
	.string "Please give my regards to Prof. Rowan.$"
