.set LOCALID_HELPER, 1
.set LOCALID_RIVAL, 2

OldaleTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, OldaleTown_OnTransition
	.byte 0

	@ State descriptions for VAR_OLDALE_TOWN_STATE
	@ 1: Entered initial lab scene

OldaleTown_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	setflag FLAG_VISITED_OLDALE_TOWN
	end

OldaleTown_EventScript_HelperExclaim::
	lock
	setvar VAR_OLDALE_TOWN_STATE, 1
	setflag FLAG_HIDE_OLDALE_HELPER
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
	call_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_HelperSay1
	call_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_HelperSay2
	return

OldaleTown_EventScript_HelperSay1::
	msgbox OldaleTown_Text_HelperSay1, MSGBOX_SIGN
	return

OldaleTown_EventScript_HelperSay2::
	msgbox OldaleTown_Text_HelperSay2, MSGBOX_SIGN
	return

OldaleTown_EventScript_HelperToLab::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_HelperSay3
	call_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_HelperSay4
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
	call_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_HelperSay5
	call_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_HelperSay6
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_TurnUp
	applymovement LOCALID_HELPER, OldaleTown_Movement_HelperEnter
	waitmovement 0
	removeobject LOCALID_HELPER
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

OldaleTown_EventScript_HelperSay3::
	msgbox OldaleTown_Text_HelperSay3, MSGBOX_DEFAULT
	return

OldaleTown_EventScript_HelperSay4::
	msgbox OldaleTown_Text_HelperSay4, MSGBOX_DEFAULT
	return

OldaleTown_EventScript_HelperSay5::
	msgbox OldaleTown_Text_HelperSay5, MSGBOX_SIGN
	return

OldaleTown_EventScript_HelperSay6::
	msgbox OldaleTown_Text_HelperSay6, MSGBOX_SIGN
	return

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

OldaleTown_Text_HelperSay1:
	.string "Dawn: Oh! There you are!\n"
	.string "Please, come with me!\l"
	.string "The professor is waiting!$"

OldaleTown_Text_HelperSay2:
	.string "Lucas: Oh! There you are!$"

OldaleTown_Text_HelperSay3:
	.string "This is it!\n"
	.string "Our Pokémon Research Lab!\p"
	.string "Lets go...$"

OldaleTown_Text_HelperSay4:
	.string "This is it!$"

OldaleTown_Text_HelperSay5:
	.string "Dawn: Wow, what was that?\p"
	.string "Your friend sure seems to be really\n"
	.string "impatient.\p"
	.string "Well, anyway...\n"
	.string "Let's go inside.$"

OldaleTown_Text_HelperSay6:
	.string "Lucas: Wow, what was that?$"

OldaleTown_Text_Thud:
	.string "THUD!!$"

OldaleTown_Text_Rival:
	.string "Oh, it's you, {PLAYER}!\p"
	.string "That old guy... He's not scary so\n"
	.string "much as he is totally out there!\p"
	.string "Aww, it doesn't matter, {PLAYER}.\n"
	.string "I'm out of here. See you later!$"

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
