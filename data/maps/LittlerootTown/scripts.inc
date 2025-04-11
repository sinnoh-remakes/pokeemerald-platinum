.set LOCALID_RIVAL, 4
.set LOCALID_BLOCK, 3

LittlerootTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_OnFrame
	.byte 0

	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
	@ 1: Left with Rival to see lake
	@ 2: Entered lake event
	@ 3: Left Twinleaf with Running Shoes

	@ State descriptions for VAR_LITTLEROOT_INTRO_STATE
	@ 1: Talked to Mom once
	@ 2: Talked to Mom twice
	@ 3: Bumped into Rival
	@ 4: Spoken to Rival in room
	@ 5: Returned from lake event
	@ 6: Received Running Shoes

	@ State descriptions for VAR_ALTERNATE_TEXT
	@ 1: Talked to Mom saying bye in intro event
	@ 2: Talked to Rival's Mom after Rival leaves Twinleaf

LittlerootTown_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 6, LittlerootTown_EventScript_LeaveRunning
	setflag FLAG_VISITED_LITTLEROOT_TOWN
	end

LittlerootTown_OnFrame:
	.2byte 0

LittlerootTown_EventScript_RivalMeet::
	lock
	setvar VAR_LITTLEROOT_INTRO_STATE, 3
	opendoor 3, 12
	waitdooranim
	addobject LOCALID_RIVAL
	applymovement LOCALID_RIVAL, LittlerootTown_Movement_RivalBump
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerBump
	waitmovement 0
	closedoor 3, 12
	waitdooranim
	msgbox LittlerootTown_Text_Thud, MSGBOX_DEFAULT
	delay 48
	delay 48
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox LittlerootTown_Text_RivalBump, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerFaceRight
	applymovement LOCALID_RIVAL, LittlerootTown_Movement_RivalRight
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerFaceUp
	applymovement LOCALID_RIVAL, LittlerootTown_Movement_RivalLeft
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 30
	msgbox LittlerootTown_Text_RivalForget, MSGBOX_SIGN
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	opendoor 3, 12
	waitdooranim
	waitmovement 0
	applymovement LOCALID_RIVAL, LittlerootTown_Movement_RivalUp
	waitmovement 0
	closedoor 3, 12
	removeobject LOCALID_RIVAL
	waitdooranim
	release
	end

LittlerootTown_Movement_PlayerBump:
	walk_fast_down
	face_up
	step_end

LittlerootTown_Movement_PlayerFaceRight:
	delay_16
	face_right
	step_end

LittlerootTown_Movement_PlayerFaceUp:
	delay_16
	face_up
	step_end

LittlerootTown_Movement_RivalBump:
	walk_fast_down
	step_end

LittlerootTown_Movement_RivalRight:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LittlerootTown_Movement_RivalLeft:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_down
	step_end

LittlerootTown_Movement_RivalUp:
	walk_fast_up
	step_end

LittlerootTown_EventScript_BlockBump::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_PlayerBump
	applymovement LOCALID_BLOCK, LittlerootTown_Movement_RivalBump
	waitmovement 0
	delay 60
	msgbox LittlerootTown_Text_Guitarist1, MSGBOX_DEFAULT
	closemessage
	delay 30
	return

LittlerootTown_EventScript_BlockExclaim::
	applymovement LOCALID_BLOCK, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 10
	playse SE_PIN
	applymovement LOCALID_BLOCK, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	return

LittlerootTown_EventScript_LeaveBlock1::
	lockall
	call LittlerootTown_EventScript_BlockExclaim
	applymovement LOCALID_BLOCK, LittlerootTown_Movement_RunRight1
	applymovement LOCALID_BLOCK, Common_Movement_FaceDown
	waitmovement 0
	call LittlerootTown_EventScript_BlockBump
	applymovement LOCALID_BLOCK, LittlerootTown_Movement_WalkLeft1
	waitmovement 0
	delay 30
	releaseall
	end

LittlerootTown_EventScript_LeaveBlock2::
	lockall
	call LittlerootTown_EventScript_BlockExclaim
	applymovement LOCALID_BLOCK, LittlerootTown_Movement_RunRight2
	applymovement LOCALID_BLOCK, Common_Movement_FaceDown
	waitmovement 0
	call LittlerootTown_EventScript_BlockBump
	applymovement LOCALID_BLOCK, LittlerootTown_Movement_WalkLeft2
	waitmovement 0
	delay 30
	releaseall
	end

LittlerootTown_EventScript_LeaveBlock3::
	lockall
	call LittlerootTown_EventScript_BlockExclaim
	applymovement LOCALID_BLOCK, LittlerootTown_Movement_RunRight3
	applymovement LOCALID_BLOCK, Common_Movement_FaceDown
	waitmovement 0
	call LittlerootTown_EventScript_BlockBump
	applymovement LOCALID_BLOCK, LittlerootTown_Movement_WalkLeft3
	waitmovement 0
	delay 30
	releaseall
	end

LittlerootTown_EventScript_LeaveBlock4::
	lockall
	call LittlerootTown_EventScript_BlockExclaim
	applymovement LOCALID_BLOCK, LittlerootTown_Movement_RunRight4
	applymovement LOCALID_BLOCK, Common_Movement_FaceDown
	waitmovement 0
	call LittlerootTown_EventScript_BlockBump
	applymovement LOCALID_BLOCK, LittlerootTown_Movement_WalkLeft4
	waitmovement 0
	delay 30
	releaseall
	end

LittlerootTown_EventScript_LeaveBlock5::
	lockall
	call LittlerootTown_EventScript_BlockExclaim
	applymovement LOCALID_BLOCK, LittlerootTown_Movement_RunRight5
	applymovement LOCALID_BLOCK, Common_Movement_FaceDown
	waitmovement 0
	call LittlerootTown_EventScript_BlockBump
	applymovement LOCALID_BLOCK, LittlerootTown_Movement_WalkLeft5
	waitmovement 0
	delay 30
	releaseall
	end

LittlerootTown_EventScript_LeaveBlock6::
	lockall
	call LittlerootTown_EventScript_BlockExclaim
	applymovement LOCALID_BLOCK, LittlerootTown_Movement_RunRight6
	applymovement LOCALID_BLOCK, Common_Movement_FaceDown
	waitmovement 0
	call LittlerootTown_EventScript_BlockBump
	applymovement LOCALID_BLOCK, LittlerootTown_Movement_WalkLeft6
	waitmovement 0
	delay 30
	releaseall
	end

LittlerootTown_EventScript_LeaveBlock7::
	lockall
	call LittlerootTown_EventScript_BlockExclaim
	applymovement LOCALID_BLOCK, LittlerootTown_Movement_RunRight7
	applymovement LOCALID_BLOCK, Common_Movement_FaceDown
	waitmovement 0
	call LittlerootTown_EventScript_BlockBump
	applymovement LOCALID_BLOCK, LittlerootTown_Movement_WalkLeft7
	waitmovement 0
	delay 30
	releaseall
	end

LittlerootTown_Movement_RunRight1:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	step_end

LittlerootTown_Movement_RunRight2:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	step_end

LittlerootTown_Movement_RunRight3:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LittlerootTown_Movement_RunRight4:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LittlerootTown_Movement_RunRight5:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LittlerootTown_Movement_RunRight6:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LittlerootTown_Movement_RunRight7:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LittlerootTown_Movement_WalkLeft1:
	walk_left
	walk_down
	step_end

LittlerootTown_Movement_WalkLeft2:
	walk_left
	walk_left
	walk_down
	step_end

LittlerootTown_Movement_WalkLeft3:
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

LittlerootTown_Movement_WalkLeft4:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

LittlerootTown_Movement_WalkLeft5:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

LittlerootTown_Movement_WalkLeft6:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

LittlerootTown_Movement_WalkLeft7:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

LittlerootTown_EventScript_LeaveRunning::
	setvar VAR_LITTLEROOT_TOWN_STATE, 3
	end

LittlerootTown_Text_Thud:
	.string "THUD!!$"

LittlerootTown_Text_RivalBump:
	.string "{RIVAL}: What was that about?!\p"
	.string "Oh hey! B!\p"
	.string "Hey! I'm going to the lake!\n"
	.string "You come too! And be quick about it!\p"
	.string "OK, B?\n"
	@ TODO: Add dollar sign ₽
	.string "I'm fining you 1 million if you're late!$"

LittlerootTown_Text_RivalForget:
	.string "{RIVAL}: Oh, jeez!\n"
	.string "Forgot something!$"

LittlerootTown_EventScript_TownSign::
	msgbox LittlerootTown_Text_TownSign, MSGBOX_SIGN
	end

LittlerootTown_EventScript_BrendansHouseSign::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_PlayersHouseSignMale
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_BirchsHouseSignFemale
	releaseall
	end

LittlerootTown_EventScript_PlayersHouseSignMale::
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_BirchsHouseSignFemale::
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_MaysHouseSign::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_EventScript_BirchsHouseSignMale
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_EventScript_PlayersHouseSignFemale
	releaseall
	end

LittlerootTown_EventScript_BirchsHouseSignMale::
	msgbox LittlerootTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_PlayersHouseSignFemale::
	msgbox LittlerootTown_Text_PlayersHouse, MSGBOX_DEFAULT
	return

LittlerootTown_EventScript_FatMan::
	msgbox LittlerootTown_Text_FatMan, MSGBOX_NPC
	end

LittlerootTown_EventScript_Aroma::
	goto_if_lt VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_EventScript_Aroma_Talk1
	goto LittlerootTown_EventScript_Aroma_Talk2
	end

LittlerootTown_EventScript_Aroma_Talk1::
	msgbox LittlerootTown_Text_Aroma1, MSGBOX_NPC
	end

LittlerootTown_EventScript_Aroma_Talk2::
	msgbox LittlerootTown_Text_Aroma2, MSGBOX_NPC
	end

LittlerootTown_EventScript_Guitarist::
	goto_if_lt VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_EventScript_Guitarist_Talk1
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_EventScript_Guitarist_Talk2
	goto LittlerootTown_EventScript_Guitarist_Talk3
	end

LittlerootTown_EventScript_Guitarist_Talk1::
	msgbox LittlerootTown_Text_Guitarist1, MSGBOX_NPC
	end

LittlerootTown_EventScript_Guitarist_Talk2::
	msgbox LittlerootTown_Text_Guitarist2, MSGBOX_NPC
	end

LittlerootTown_EventScript_Guitarist_Talk3::
	msgbox LittlerootTown_Text_Guitarist3, MSGBOX_NPC
	end

LittlerootTown_Text_FatMan:
	.string "Technology just blows me away!\p"
	.string "I mean, now you can play with people\n"
	.string "around the world... wirelessly!$"

LittlerootTown_Text_Aroma1:
	.string "It's true that wild Pokémon do attack\n"
	.string "people sometimes...\p"
	.string "However, Pokémon also let you become\n"
	.string "friends with them.$"

LittlerootTown_Text_Aroma2:
	.string "Oh! A Pokémon!\n"
	.string "You look good together!$"
	
LittlerootTown_Text_Guitarist1:
	.string "Hiya, {PLAYER}.\n"
	.string "{RIVAL} was looking for you.\p"
	.string "I think he's home now.\n"
	.string "Why don't you go check it out?$"
	
LittlerootTown_Text_Guitarist2:
	.string "Hiya, {PLAYER}.\n"
	.string "You're looking for {RIVAL}?\p"
	.string "He just went tearing off a little\n"
	.string "while ago.\p"
	.string "He's probably not gone too far.\n"
	.string "Why not go chase after him?$"
	
LittlerootTown_Text_Guitarist3:
	.string "{RIVAL}? He went tearing off\n"
	.string "in a huge rush a while ago.$"

LittlerootTown_Text_TownSign:
	.string "Twinleaf Town\n"
	.string "Fresh and free!$"

LittlerootTown_Text_PlayersHouse:
	.string "{PLAYER}'s House$"

LittlerootTown_Text_ProfBirchsHouse:
	.string "{RIVAL}'s House$"
