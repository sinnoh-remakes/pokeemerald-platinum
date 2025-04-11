.set LOCALID_HELPER, 1
.set LOCALID_RIVAL, 2

OldaleTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, OldaleTown_OnFrame
	.byte 0

	@ State descriptions for VAR_OLDALE_TOWN_STATE
	@ 1: Entered initial lab scene
	@ 2: Entered second helper scene

OldaleTown_OnTransition:
	call_if_eq VAR_OLDALE_TOWN_STATE, 1, OldaleTown_EventScript_MoveHelper
  @ TODO: Rename SetupRivalGfxId to SetupHelperGfxId
	call Common_EventScript_SetupRivalGfxId
	setflag FLAG_VISITED_OLDALE_TOWN
	end

OldaleTown_OnFrame:
	map_script_2 VAR_OLDALE_TOWN_STATE, 1, OldaleTown_EventScript_HelperBuildings
	.2byte 0

OldaleTown_EventScript_HelperExclaim::
	lock
	setvar VAR_OLDALE_TOWN_STATE, 1
	special SpawnCameraObject
	playse SE_PIN
	applymovement LOCALID_HELPER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	return

OldaleTown_EventScript_HelperLab1::
	call OldaleTown_EventScript_HelperExclaim
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper1
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	call OldaleTown_EventScript_HelperTalk1
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper6
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_Player1
	applymovement OBJ_EVENT_ID_CAMERA, OldaleTown_Movement_Player1
	waitmovement 0
	goto OldaleTown_EventScript_HelperToLab

OldaleTown_EventScript_HelperLab2::
	call OldaleTown_EventScript_HelperExclaim
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper2
	waitmovement 0
	call OldaleTown_EventScript_HelperTalk1
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper7
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_Player2
	applymovement OBJ_EVENT_ID_CAMERA, OldaleTown_Movement_Player2
	waitmovement 0
	goto OldaleTown_EventScript_HelperToLab

OldaleTown_EventScript_HelperLab3::
	call OldaleTown_EventScript_HelperExclaim
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper3
	waitmovement 0
	call OldaleTown_EventScript_HelperTalk1
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper8
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_Player3
	applymovement OBJ_EVENT_ID_CAMERA, OldaleTown_Movement_Player3
	waitmovement 0
	goto OldaleTown_EventScript_HelperToLab

OldaleTown_EventScript_HelperLab4::
	call OldaleTown_EventScript_HelperExclaim
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper4
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	call OldaleTown_EventScript_HelperTalk1
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper9
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_Player4
	applymovement OBJ_EVENT_ID_CAMERA, OldaleTown_Movement_Player4
	waitmovement 0
	goto OldaleTown_EventScript_HelperToLab

OldaleTown_EventScript_HelperLab5::
	call OldaleTown_EventScript_HelperExclaim
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper5
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	call OldaleTown_EventScript_HelperTalk1
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper10
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_Player5
	applymovement OBJ_EVENT_ID_CAMERA, OldaleTown_Movement_Player5
	waitmovement 0
	goto OldaleTown_EventScript_HelperToLab

OldaleTown_Movement_Helper1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	face_up
	step_end

OldaleTown_Movement_Helper2:
	walk_left
	walk_left
	walk_left
	walk_up
	walk_left
	step_end

OldaleTown_Movement_Helper3:
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

OldaleTown_Movement_Helper4:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	face_down
	step_end

OldaleTown_Movement_Helper5:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	face_down
	step_end

OldaleTown_Movement_Helper6:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end

OldaleTown_Movement_Helper7:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end

OldaleTown_Movement_Helper8:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end
	
OldaleTown_Movement_Helper9:
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end

OldaleTown_Movement_Helper10:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end

OldaleTown_Movement_Player1:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end

OldaleTown_Movement_Player2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end

OldaleTown_Movement_Player3:
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end

OldaleTown_Movement_Player4:
	walk_up
	walk_right
	walk_right
	walk_up
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end

OldaleTown_Movement_Player5:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end

OldaleTown_EventScript_HelperTalk1::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_Helper_Dawn1
	call_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_Helper_Lucas1
	return

OldaleTown_EventScript_Helper_Dawn1::
	msgbox OldaleTown_Text_Helper_Dawn1, MSGBOX_SIGN
	return

OldaleTown_EventScript_Helper_Lucas1::
	msgbox OldaleTown_Text_Helper_Lucas1, MSGBOX_SIGN
	return

OldaleTown_EventScript_HelperToLab::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_Helper_Dawn2
	call_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_Helper_Lucas2
	opendoor 11, 6
	waitdooranim
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalBump
	waitmovement 0
	msgbox OldaleTown_Text_Thud, MSGBOX_DEFAULT
	delay 48
	delay 48
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	msgbox OldaleTown_Text_Rival, MSGBOX_SIGN
	applymovement LOCALID_HELPER, OldaleTown_Movement_TurnRight
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_TurnRight
	applymovement LOCALID_RIVAL, OldaleTown_Movement_RivalRun
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_Helper_Dawn3
	call_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_Helper_Lucas3
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_TurnUp
	applymovement LOCALID_HELPER, OldaleTown_Movement_HelperEnter
	waitmovement 0
	@ TODO: Cannot hide helper or will not show in next scene
	setobjectxy LOCALID_HELPER 25, 5
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_PlayerEnter
	applymovement OBJ_EVENT_ID_CAMERA, OldaleTown_Movement_PlayerEnter
	waitmovement 0
	removeobject OBJ_EVENT_ID_PLAYER
	closedoor 11, 6
	waitdooranim
	special RemoveCameraObject
	warp MAP_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB, 0
	waitstate
	release
	end

OldaleTown_Movement_RivalBump:
	walk_fast_down
	step_end

OldaleTown_Movement_RivalRun:
	walk_fast_right
	walk_fast_right
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

OldaleTown_Movement_HelperEnter:
	walk_up
	walk_left
	walk_up
	step_end

OldaleTown_Movement_PlayerEnter:
	walk_up
	walk_up
	step_end

OldaleTown_Movement_TurnRight:
	delay_16
	walk_in_place_right
	step_end

OldaleTown_Movement_TurnUp:
	delay_16
	walk_in_place_up
	step_end

OldaleTown_EventScript_Helper_Dawn2::
	msgbox OldaleTown_Text_Helper_Dawn2, MSGBOX_DEFAULT
	return

OldaleTown_EventScript_Helper_Lucas2::
	msgbox OldaleTown_Text_Helper_Lucas2, MSGBOX_DEFAULT
	return

OldaleTown_EventScript_Helper_Dawn3::
	msgbox OldaleTown_Text_Helper_Dawn3, MSGBOX_SIGN
	return

OldaleTown_EventScript_Helper_Lucas3::
	msgbox OldaleTown_Text_Helper_Lucas3, MSGBOX_SIGN
	return

OldaleTown_EventScript_MoveHelper::
	addobject LOCALID_HELPER
	setobjectxy LOCALID_HELPER, 11, 8
	setobjectmovementtype LOCALID_HELPER, MOVEMENT_TYPE_FACE_UP
	return

OldaleTown_EventScript_HelperBuildings::
	lock
	special SpawnCameraObject
	setvar VAR_OLDALE_TOWN_STATE, 2
	applymovement LOCALID_HELPER, Common_Movement_WalkUp
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_Helper_Dawn4
	call_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_Helper_Lucas4
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper_Guide1
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_Player_Guide1
	applymovement OBJ_EVENT_ID_CAMERA, OldaleTown_Movement_Player_Guide1
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_Helper_Dawn5
	call_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_Helper_Lucas5
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper_Guide2
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_Helper_Guide2
	applymovement OBJ_EVENT_ID_CAMERA, OldaleTown_Movement_Helper_Guide2
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_Helper_Dawn6
	call_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_Helper_Lucas6
	applymovement LOCALID_HELPER, Common_Movement_WalkInPlaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_HELPER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	checkplayergender
	call_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_Helper_Dawn7
	call_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_Helper_Lucas7
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_Player_Guide2
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper_Guide3
	waitmovement 0
	removeobject LOCALID_HELPER
	setflag FLAG_HIDE_OLDALE_HELPER
	special RemoveCameraObject
	delay 48
	delay 48
	release
	end

OldaleTown_EventScript_Helper_Dawn4::
	msgbox OldaleTown_Text_Helper_Dawn4, MSGBOX_SIGN
	return

OldaleTown_EventScript_Helper_Dawn5::
	msgbox OldaleTown_Text_Helper_Dawn5, MSGBOX_SIGN
	return

OldaleTown_EventScript_Helper_Dawn6::
	msgbox OldaleTown_Text_Helper_Dawn6, MSGBOX_SIGN
	return

OldaleTown_EventScript_Helper_Dawn7::
	msgbox OldaleTown_Text_Helper_Dawn7, MSGBOX_SIGN
	return

OldaleTown_EventScript_Helper_Lucas4::
	msgbox OldaleTown_Text_Helper_Lucas4, MSGBOX_SIGN
	return

OldaleTown_EventScript_Helper_Lucas5::
	msgbox OldaleTown_Text_Helper_Lucas5, MSGBOX_SIGN
	return

OldaleTown_EventScript_Helper_Lucas6::
	msgbox OldaleTown_Text_Helper_Lucas6, MSGBOX_SIGN
	return

OldaleTown_EventScript_Helper_Lucas7::
	msgbox OldaleTown_Text_Helper_Lucas7, MSGBOX_SIGN
	return

OldaleTown_Movement_Helper_Guide1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end

OldaleTown_Movement_Helper_Guide2:
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
	walk_in_place_up
	step_end
	
OldaleTown_Movement_Helper_Guide3:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

OldaleTown_Movement_Player_Guide1:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_up
	step_end
	
OldaleTown_Movement_Player_Guide2:
	delay_16
	walk_in_place_down
	delay_16
	walk_in_place_left
	step_end

OldaleTown_EventScript_TownSign::
	msgbox OldaleTown_Text_TownSign, MSGBOX_SIGN
	end

OldaleTown_EventScript_LabSign::
	msgbox OldaleTown_Text_LabSign, MSGBOX_SIGN
	end

OldaleTown_EventScript_RivalSign::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_DawnSign
	call_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_LucasSign
	end

OldaleTown_EventScript_DawnSign::
	msgbox OldaleTown_Text_DawnSign, MSGBOX_SIGN
	return

OldaleTown_EventScript_LucasSign::
	msgbox OldaleTown_Text_LucasSign, MSGBOX_SIGN
	return

OldaleTown_EventScript_Boy::
	msgbox OldaleTown_Text_Boy, MSGBOX_NPC
	end

OldaleTown_EventScript_Lady::
	msgbox OldaleTown_Text_Lady, MSGBOX_NPC
	end

OldaleTown_EventScript_Youngster::
	msgbox OldaleTown_Text_Youngster, MSGBOX_NPC
	end

OldaleTown_Text_Helper_Dawn1:
	.string "Dawn: Oh! There you are!\n"
	.string "Please, come with me!\l"
	.string "The professor is waiting!$"

OldaleTown_Text_Helper_Dawn2:
	.string "This is it!\n"
	.string "Our Pokémon Research Lab!\p"
	.string "Lets go...$"

OldaleTown_Text_Helper_Dawn3:
	.string "Dawn: Wow, what was that?\p"
	.string "Your friend sure seems to be really\n"
	.string "impatient.\p"
	.string "Well, anyway...\n"
	.string "Let's go inside.$"

OldaleTown_Text_Helper_Lucas1:
	.string "Lucas: Hi! I've been waiting for you!\n"
	.string "Please, come with me.\l"
	.string "The prof's waiting to see you.$"

OldaleTown_Text_Helper_Lucas2:
	.string "See? This is our Pokémon Research\n"
	.string "Lab.\p"
	.string "We'll just go ahead and...$"

OldaleTown_Text_Helper_Lucas3:
	.string "Lucas: What was that?!\p"
	.string "Your friend always seems to be\n"
	.string "in such a rush.\p"
	.string "Anyway...\n"
	.string "Let's go in.\p"

@ TODO: THUD change to Thud? Also in LittlerootTown
OldaleTown_Text_Thud:
	.string "THUD!!$"

OldaleTown_Text_Rival:
	.string "Oh, it's you, {PLAYER}!\p"
	.string "That old guy... He's not scary so\n"
	.string "much as he is totally out there!\p"
	.string "Aww, it doesn't matter, {PLAYER}.\n"
	.string "I'm out of here. See you later!$"

OldaleTown_Text_Helper_Dawn4:
	.string "Dawn: OK, {PLAYER}, I'll act as\n"
	.string "your mentor.\p"
	.string "I've got a bit more experience than\n"
	.string "you as a Trainer as as the\l"
	.string "professor's assistant.\p"
	.string "OK, follow me!$"
	
OldaleTown_Text_Helper_Dawn5:
	.string "This building with the red roof is\n"
	.string "the Pokémon Center.\p"
	.string "It's the place that heals Pokémon\n"
	.string "that have been hurt in battle.\p"
	.string "You can find a Pokémon Center in\n"
	.string "most towns.$"

OldaleTown_Text_Helper_Dawn6:
	.string "The building with the blue roof over\n"
	.string "here is the Poké Mart.\p"
	.string "It's a shop where you can buy and\n"
	.string "sell items and medicine.\p"
	.string "{PLAYER}, since you're a novice\n"
	.string "Trainer, you won't be able to buy\l"
	.string "many kinds of merchandise.\p"
	.string "Don't let it bother you!$"
	
OldaleTown_Text_Helper_Dawn7:
	.string "Oh, that's right!\n"
	.string "{PLAYER}...\p"
	.string "Don't you need to let your family\n"
	.string "know that you're going to be helping\l"
	.string "Prof. Rowan with the Pokédex?\p"
	.string "You may need to go far away, so I\n"
	.string "think you should let someone know.\p"
	.string "Oh, but before you go, heal up your\n"
	.string "Pokémon at the Poké Center.\p"
	.string "It will be a lot less scary that way.\n"
	.string "OK, bye now!$"
	
OldaleTown_Text_Helper_Lucas4:
	.string "Lucas: Hey, {PLAYER}!\n"
	.string "I want to show you a few things.\l"
	.string "So, follow me!$"

OldaleTown_Text_Helper_Lucas5:
	.string "This building with the red roof is\n"
	.string "the Pokémon Center.\p"
	.string "You can get your Pokémon healed if\n"
	.string "it's been hurt in battle.$"
	.string "You'll find a Pokémon Center in most\n"
	.string "towns.$"

OldaleTown_Text_Helper_Lucas6:
	.string "Over here, the building with the blue\n"
	.string "roof is the Poké Mart.\p"
	.string "It's a shop where you can buy and\n"
	.string "sell all sorts of items.\p"
	.string "{PLAYER}, since you're a rookie\n"
	.string "Trainer, you won't be able to buy\l"
	.string "very much stuff.\p"
	.string "Don't worry about it, OK?$"

OldaleTown_Text_Helper_Lucas7:
	.string "Oh year, right!\n"
	.string "{PLAYER}...\p"
	.string "You should let your family know\n"
	.string "you're helping Prof. Rowan put\l"
	.string "together his Pokédex.\p"
	.string "Sometimes, you have to go far away,\n"
	.string "so you should let someone know.\p"
	.string "Oh, but first, go heal up your\n"
	.string "Pokémon at the Poké Center.\p"
	.string "You'll be safe then.\n"
	.string "OK, be seeing you!$"

OldaleTown_Text_TownSign:
	.string "Sandgem Town\n"
	.string "Town of Sand!$"

OldaleTown_Text_LabSign:
	.string "Pokémon Research Lab$"

OldaleTown_Text_DawnSign:
	.string "Dawn's House$"

OldaleTown_Text_LucasSign:
	.string "Lucas's House$"

OldaleTown_Text_Boy:
	.string "The thing you have!\p"
	.string "It's a Pokédex, isn't it?!\p"
	.string "You're off to see all kinds of\n"
	.string "Pokémon now! Lucky you!$"

OldaleTown_Text_Lady:
	.string "So I don't forget what's happened,\n"
	.string "till now, I'd better save this...\p"
	.string "There!\n"
	.string "Now I can take a break.$"

OldaleTown_Text_Youngster:
	.string "Oh, wow!\n"
	.string "Pokémon are so cool!\p"
	.string "You can make yours battle and make\n"
	.string "them stronger!\p"
	.string "I wish I had some!\n"
	.string "It's so cool!$"
