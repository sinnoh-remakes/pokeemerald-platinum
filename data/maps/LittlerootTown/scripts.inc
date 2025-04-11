.set LOCALID_RIVAL, 4
.set LOCALID_BLOCK, 3

LittlerootTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_OnFrame
	.byte 0

	@ State descriptions for VAR_LITTLEROOT_TOWN_STATE
	@ 1: Left with Rival to see lake
	@ 2: Returned from lake
	@ 3: Returned from lab

	@ State descriptions for VAR_LITTLEROOT_INTRO_STATE
	@ 1: Talked to Mom once
	@ 2: Talked to Mom twice
	@ 3: Bumped into Rival
	@ 4: Spoken to Rival in room

LittlerootTown_OnTransition:
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
	applymovement LOCALID_RIVAL, LittlerootTown_Movement_BumpRival
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_BumpPlayer
	waitmovement 0
	closedoor 3, 12
	waitdooranim
	msgbox LittlerootTown_Text_Thud, MSGBOX_DEFAULT
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	closemessage
	msgbox LittlerootTown_Text_RivalBump, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, LittlerootTown_Movement_RunRight
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, LittlerootTown_Movement_RunLeft
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 30
	msgbox LittlerootTown_Text_RivalForget, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	opendoor 3, 12
	waitdooranim
	waitmovement 0
	applymovement LOCALID_RIVAL, LittlerootTown_Movement_LeaveRival
	waitmovement 0
	closedoor 3, 12
	removeobject LOCALID_RIVAL
	waitdooranim
	release
	end

LittlerootTown_Movement_BumpPlayer:
	walk_fast_down
	face_up
	step_end

LittlerootTown_Movement_BumpRival:
	walk_fast_down
	step_end

LittlerootTown_Movement_RunRight:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

LittlerootTown_Movement_RunLeft:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_down
	step_end

LittlerootTown_Movement_LeaveRival:
	walk_fast_up
	step_end

LittlerootTown_EventScript_BlockBump::
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_Movement_BumpPlayer
	applymovement LOCALID_BLOCK, LittlerootTown_Movement_BumpRival
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
	applymovement LOCALID_BLOCK, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_BLOCK, Common_Movement_Delay48
	waitmovement 0
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

LittlerootTown_Text_Thud:
	.string "Thud!!$"

LittlerootTown_Text_RivalBump:
	.string "{RIVAL}: What was that about?!\p"
	.string "Oh hey! B!\p"
	.string "Hey! I'm going to the lake!\n"
	.string "You come too! And be quick about it!\p"
	.string "OK, B?\n"
	@ TODO: Fix dollar sign ₽
	.string "I'm fining you 1 million if you're late!$"

LittlerootTown_Text_RivalForget:
	.string "Barry: Oh, jeez!\n"
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
	msgbox LittlerootTown_Text_Aroma, MSGBOX_NPC
	end

LittlerootTown_EventScript_Guitarist::
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 4, LittlerootTown_EventScript_Guitarist_Talk1
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, LittlerootTown_EventScript_Guitarist_Talk2
	end

LittlerootTown_EventScript_Guitarist_Talk1::
	msgbox LittlerootTown_Text_Guitarist1, MSGBOX_NPC
	end

LittlerootTown_EventScript_Guitarist_Talk2::
	msgbox LittlerootTown_Text_Guitarist2, MSGBOX_NPC
	end

LittlerootTown_Text_FatMan:
	.string "Technology just blows me away!\p"
	.string "I mean, now you can play with people\n"
	.string "around the world... wirelessly!$"

LittlerootTown_Text_Aroma:
	.string "It's true that wild Pokemon do attack\n"
	.string "people sometimes...\p"
	.string "However, Pokemon also let you become\n"
	.string "friends with them.$"
	
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

LittlerootTown_Text_TownSign:
	.string "Twinleaf Town\n"
	.string "Fresh and free!$"

LittlerootTown_Text_PlayersHouse:
	.string "{PLAYER}'s House$"

LittlerootTown_Text_ProfBirchsHouse:
	.string "{RIVAL}'s House$"
