.set LOCALID_HELPER, 1
.set LOCALID_RIVAL, 2
.set LOCALID_PROF, 3

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
	call_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_WaitingDawn
	call_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_WaitingLucas
	return

OldaleTown_EventScript_WaitingDawn::
	msgbox OldaleTown_Text_WaitingDawn, MSGBOX_SIGN
	return

OldaleTown_EventScript_WaitingLucas::
	msgbox OldaleTown_Text_WaitingLucas, MSGBOX_SIGN
	return

OldaleTown_EventScript_HelperToLab::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_OurLabDawn
	call_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_OurLabLucas
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
	removeobject LOCALID_RIVAL
	checkplayergender
	call_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_AnywayDawn
	call_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_AnywayLucas
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_TurnUp
	applymovement LOCALID_HELPER, OldaleTown_Movement_HelperEnter
	waitmovement 0
	@ TODO: Cannot hide helper or will not show in next sandgem scene
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

OldaleTown_EventScript_OurLabDawn::
	msgbox OldaleTown_Text_OurLabDawn, MSGBOX_DEFAULT
	return

OldaleTown_EventScript_OurLabLucas::
	msgbox OldaleTown_Text_OurLabLucas, MSGBOX_DEFAULT
	return

OldaleTown_EventScript_AnywayDawn::
	msgbox OldaleTown_Text_AnywayDawn, MSGBOX_SIGN
	return

OldaleTown_EventScript_AnywayLucas::
	msgbox OldaleTown_Text_AnywayLucas, MSGBOX_SIGN
	return

OldaleTown_EventScript_MoveHelper::
	addobject LOCALID_HELPER
	setobjectxy LOCALID_HELPER, 11, 8
	setobjectmovementtype LOCALID_HELPER, MOVEMENT_TYPE_FACE_UP
	return

OldaleTown_EventScript_HelperBuildings::
	lock
	setvar VAR_OLDALE_TOWN_STATE, 2
	opendoor 11, 6
	waitdooranim
	addobject LOCALID_PROF
	msgbox OldaleTown_Text_Thud, MSGBOX_DEFAULT
	delay 48
	delay 48
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox OldaleTown_Text_Surprise, MSGBOX_SIGN
	playse SE_PIN
	applymovement LOCALID_HELPER, Common_Movement_ExclamationMark
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox OldaleTown_Text_SomethingGood, MSGBOX_DEFAULT
	giveitem ITEM_TM_RETURN
	setflag FLAG_RECEIVED_TM_RETURN
	@ goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox OldaleTown_Text_TechnicalMove, MSGBOX_SIGN
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceUp
	waitmovement 0
	removeobject LOCALID_PROF
	closedoor 11, 6
	waitdooranim
	special SpawnCameraObject
	delay 48
	checkplayergender
	call_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_ShockDawn
	call_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_ShockLucas
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	applymovement LOCALID_HELPER, Common_Movement_WalkUp
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_MentorDawn
	call_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_MentorLucas
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper_Guide1
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_Player_Guide1
	applymovement OBJ_EVENT_ID_CAMERA, OldaleTown_Movement_Player_Guide1
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_CenterDawn
	call_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_CenterLucas
	applymovement LOCALID_HELPER, OldaleTown_Movement_Helper_Guide2
	applymovement OBJ_EVENT_ID_PLAYER, OldaleTown_Movement_Helper_Guide2
	applymovement OBJ_EVENT_ID_CAMERA, OldaleTown_Movement_Helper_Guide2
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_MartDawn
	call_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_MartLucas
	applymovement LOCALID_HELPER, Common_Movement_WalkInPlaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_HELPER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	checkplayergender
	call_if_eq VAR_RESULT, MALE, OldaleTown_EventScript_FamilyDawn
	call_if_eq VAR_RESULT, FEMALE, OldaleTown_EventScript_FamilyLucas
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

OldaleTown_EventScript_ShockDawn::
	msgbox OldaleTown_Text_ShockDawn, MSGBOX_SIGN
	return

OldaleTown_EventScript_MentorDawn::
	msgbox OldaleTown_Text_MentorDawn, MSGBOX_SIGN
	return

OldaleTown_EventScript_CenterDawn::
	msgbox OldaleTown_Text_CenterDawn, MSGBOX_SIGN
	return

OldaleTown_EventScript_MartDawn::
	msgbox OldaleTown_Text_MartDawn, MSGBOX_SIGN
	return

OldaleTown_EventScript_FamilyDawn::
	msgbox OldaleTown_Text_FamilyDawn, MSGBOX_SIGN
	return

OldaleTown_EventScript_ShockLucas::
	msgbox OldaleTown_Text_ShockLucas, MSGBOX_SIGN
	return

OldaleTown_EventScript_MentorLucas::
	msgbox OldaleTown_Text_MentorLucas, MSGBOX_SIGN
	return

OldaleTown_EventScript_CenterLucas::
	msgbox OldaleTown_Text_CenterLucas, MSGBOX_SIGN
	return

OldaleTown_EventScript_MartLucas::
	msgbox OldaleTown_Text_MartLucas, MSGBOX_SIGN
	return

OldaleTown_EventScript_FamilyLucas::
	msgbox OldaleTown_Text_FamilyLucas, MSGBOX_SIGN
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

OldaleTown_Text_WaitingDawn:
	.string "Dawn: Oh! There you are!\n"
	.string "Please, come with me!\l"
	.string "The professor is waiting!$"

OldaleTown_Text_OurLabDawn:
	.string "This is it!\n"
	.string "Our Pokémon Research Lab!\p"
	.string "Lets go...$"

OldaleTown_Text_AnywayDawn:
	.string "Dawn: Wow, what was that?\p"
	.string "Your friend sure seems to be really\n"
	.string "impatient.\p"
	.string "Well, anyway...\n"
	.string "Let's go inside.$"

OldaleTown_Text_WaitingLucas:
	.string "Lucas: Hi! I've been waiting for you!\n"
	.string "Please, come with me.\l"
	.string "The prof's waiting to see you.$"

OldaleTown_Text_OurLabLucas:
	.string "See? This is our Pokémon Research\n"
	.string "Lab.\p"
	.string "We'll just go ahead and...$"

OldaleTown_Text_AnywayLucas:
	.string "Lucas: What was that?!\p"
	.string "Your friend always seems to be\n"
	.string "in such a rush.\p"
	.string "Anyway...\n"
	.string "Let's go in.$"

@ TODO: THUD change to Thud? Also in LittlerootTown
OldaleTown_Text_Thud:
	.string "THUD!!$"

OldaleTown_Text_Rival:
	.string	"{RIVAL}: What the...\p"
	.string "Oh, it's you, {PLAYER}!\p"
	.string "That old guy... He's not scary so\n"
	.string "much as he is totally out there!\p"
	.string "Aww, it doesn't matter, {PLAYER}.\n"
	.string "I'm out of here. See you later!$"

OldaleTown_Text_Surprise:
	.string "{PLAYER}!$"

OldaleTown_Text_SomethingGood:
	.string "Rowan: I have something good here.\n"
	.string "You should take this as well.$"

OldaleTown_Text_TechnicalMove:
	.string "Rowan: That is a Technical Machine.\n"
	.string "That one contains the move Return.\p"
	.string "Using a Technical Machine, or TM for\n"
	.string "short, teaches a move instantly to\l"
	.string "a Pokémon.\p"
	.string "Bear in mind, however, that a TM is\n"
	.string "single-use only.\p"
	.string "The move Return gains power the more\n"
	.string "friendly your Pokémon is with you.\p"
	.string "It's up to you, of course, if you want\n"
	.string "to use that TM or not.\p"
	.string "I'll send you off with the wish that\n"
	.string "your journey will be fun.$"
	
OldaleTown_Text_ShockDawn:
	.string "Dawn: Oh, wow.\n"
	.string "I didn't know the professor had TMs.\p"
	.string "Was he a Trainer when he was\n"
	.string "young...?$"

OldaleTown_Text_MentorDawn:
	.string "Dawn: OK, {PLAYER}, I'll act as\n"
	.string "your mentor.\p"
	.string "I've got a bit more experience than\n"
	.string "you as a Trainer as as the\l"
	.string "professor's assistant.\p"
	.string "OK, follow me!$"
	
OldaleTown_Text_CenterDawn:
	.string "This building with the red roof is\n"
	.string "the Pokémon Center.\p"
	.string "It's the place that heals Pokémon\n"
	.string "that have been hurt in battle.\p"
	.string "You can find a Pokémon Center in\n"
	.string "most towns.$"

OldaleTown_Text_MartDawn:
	.string "The building with the blue roof over\n"
	.string "here is the Poké Mart.\p"
	.string "It's a shop where you can buy and\n"
	.string "sell items and medicine.\p"
	.string "{PLAYER}, since you're a novice\n"
	.string "Trainer, you won't be able to buy\l"
	.string "many kinds of merchandise.\p"
	.string "Don't let it bother you!$"
	
OldaleTown_Text_FamilyDawn:
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
	
OldaleTown_Text_ShockLucas:
	.string "Lucas: Well, I'll be...\n"
	.string "The professor had TMs...?\p"
	.string "Next thing, he'll tell me he battled\n"
	.string "when he was young.$"

OldaleTown_Text_MentorLucas:
	.string "Lucas: Hey, {PLAYER}!\n"
	.string "I want to show you a few things.\l"
	.string "So, follow me!$"

OldaleTown_Text_CenterLucas:
	.string "This building with the red roof is\n"
	.string "the Pokémon Center.\p"
	.string "You can get your Pokémon healed if\n"
	.string "it's been hurt in battle.$"
	.string "You'll find a Pokémon Center in most\n"
	.string "towns.$"

OldaleTown_Text_MartLucas:
	.string "Over here, the building with the blue\n"
	.string "roof is the Poké Mart.\p"
	.string "It's a shop where you can buy and\n"
	.string "sell all sorts of items.\p"
	.string "{PLAYER}, since you're a rookie\n"
	.string "Trainer, you won't be able to buy\l"
	.string "very much stuff.\p"
	.string "Don't worry about it, OK?$"

OldaleTown_Text_FamilyLucas:
	.string "Oh yeah, right!\n"
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
