TwinleafTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TwinleafTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TwinleafTown_OnFrame
	.byte 0

	@ State descriptions for VAR_TWINLEAF_TOWN_STATE
	@ 1: Entered rival running scene
	@ 2: Returned with Pokémon
	@ 3: Left Twinleaf with Running Shoes
	@ 4: Received Pokédex
	@ 5: Leave Twinleaf with Pokédex

	@ State descriptions for VAR_TWINLEAF_INTRO_STATE
	@ 1: Talked to Rival in room
	@ 2: Talked to Mom once
	@ 3: Talked to Mom twice
	@ 4: Bumped into Rival
	@ 5: Spoken to Rival in their room
	@ 6: Obtained first Pokémon
	@ 7: Received Running Shoes
	@ 8: Received Pokédex
	@ 9: Received Parcel

	@ State descriptions for VAR_ALTERNATE_TEXT
	@ 1: Mom saying bye in intro event
	@ 2: Rival's Mom speaking after Rival leaves Twinleaf
	@ 3: Helper Route 202 requesting you notify family

TwinleafTown_OnTransition:
	call_if_eq VAR_TWINLEAF_INTRO_STATE, 7, TwinleafTown_EventScript_LeaveRunning
	call_if_eq VAR_TWINLEAF_INTRO_STATE, 8, TwinleafTown_EventScript_LeaveParcel
	setflag FLAG_VISITED_TWINLEAF_TOWN
	end

TwinleafTown_OnFrame:
	.2byte 0

TwinleafTown_EventScript_LeaveRunning::
	setvar VAR_TWINLEAF_TOWN_STATE, 3
	end

TwinleafTown_EventScript_LeaveParcel::
	setvar VAR_TWINLEAF_TOWN_STATE, 5
	end

TwinleafTown_EventScript_RivalMeet::
	lock
	setvar VAR_TWINLEAF_INTRO_STATE, 4
	opendoor 3, 12
	waitdooranim
	addobject LOCALID_TWINLEAF_RIVAL
	applymovement LOCALID_TWINLEAF_RIVAL, TwinleafTown_Movement_RivalBump
	applymovement LOCALID_PLAYER, TwinleafTown_Movement_PlayerBump
	waitmovement 0
	closedoor 3, 12
	waitdooranim
	msgbox TwinleafTown_Text_Thud, MSGBOX_DEFAULT
	delay 48
	delay 48
	playse SE_PIN
	applymovement LOCALID_TWINLEAF_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	msgbox TwinleafTown_Text_RivalBump, MSGBOX_SIGN
	applymovement LOCALID_PLAYER, TwinleafTown_Movement_PlayerFaceRight
	applymovement LOCALID_TWINLEAF_RIVAL, TwinleafTown_Movement_RivalRight
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_TWINLEAF_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	applymovement LOCALID_PLAYER, TwinleafTown_Movement_PlayerFaceUp
	applymovement LOCALID_TWINLEAF_RIVAL, TwinleafTown_Movement_RivalLeft
	waitmovement 0
	applymovement LOCALID_TWINLEAF_RIVAL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 30
	msgbox TwinleafTown_Text_RivalForget, MSGBOX_SIGN
	applymovement LOCALID_TWINLEAF_RIVAL, Common_Movement_FaceUp
	opendoor 3, 12
	waitdooranim
	waitmovement 0
	applymovement LOCALID_TWINLEAF_RIVAL, TwinleafTown_Movement_RivalUp
	waitmovement 0
	closedoor 3, 12
	removeobject LOCALID_TWINLEAF_RIVAL
	waitdooranim
	release
	end

TwinleafTown_Movement_PlayerBump:
	face_up
	lock_facing_direction
	walk_fast_down
	unlock_facing_direction
	step_end

TwinleafTown_Movement_PlayerFaceRight:
	delay_16
	face_right
	step_end

TwinleafTown_Movement_PlayerFaceUp:
	delay_16
	face_up
	step_end

TwinleafTown_Movement_RivalBump:
	walk_fast_down
	step_end

TwinleafTown_Movement_RivalRight:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

TwinleafTown_Movement_RivalLeft:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	face_down
	step_end

TwinleafTown_Movement_RivalUp:
	walk_fast_up
	step_end

TwinleafTown_EventScript_BlockBump::
	applymovement LOCALID_PLAYER, TwinleafTown_Movement_PlayerBump
	applymovement LOCALID_TWINLEAF_GUITARIST, TwinleafTown_Movement_RivalBump
	waitmovement 0
	delay 60
	msgbox TwinleafTown_Text_Guitarist1, MSGBOX_DEFAULT
	closemessage
	delay 30
	return

TwinleafTown_EventScript_BlockExclaim::
	applymovement LOCALID_TWINLEAF_GUITARIST, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 10
	playse SE_PIN
	applymovement LOCALID_TWINLEAF_GUITARIST, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	return

TwinleafTown_EventScript_LeaveBlock1::
	lockall
	call TwinleafTown_EventScript_BlockExclaim
	applymovement LOCALID_TWINLEAF_GUITARIST, TwinleafTown_Movement_RunRight1
	applymovement LOCALID_TWINLEAF_GUITARIST, Common_Movement_FaceDown
	waitmovement 0
	call TwinleafTown_EventScript_BlockBump
	applymovement LOCALID_TWINLEAF_GUITARIST, TwinleafTown_Movement_WalkLeft1
	waitmovement 0
	delay 30
	releaseall
	end

TwinleafTown_EventScript_LeaveBlock2::
	lockall
	call TwinleafTown_EventScript_BlockExclaim
	applymovement LOCALID_TWINLEAF_GUITARIST, TwinleafTown_Movement_RunRight2
	applymovement LOCALID_TWINLEAF_GUITARIST, Common_Movement_FaceDown
	waitmovement 0
	call TwinleafTown_EventScript_BlockBump
	applymovement LOCALID_TWINLEAF_GUITARIST, TwinleafTown_Movement_WalkLeft2
	waitmovement 0
	delay 30
	releaseall
	end

TwinleafTown_EventScript_LeaveBlock3::
	lockall
	call TwinleafTown_EventScript_BlockExclaim
	applymovement LOCALID_TWINLEAF_GUITARIST, TwinleafTown_Movement_RunRight3
	applymovement LOCALID_TWINLEAF_GUITARIST, Common_Movement_FaceDown
	waitmovement 0
	call TwinleafTown_EventScript_BlockBump
	applymovement LOCALID_TWINLEAF_GUITARIST, TwinleafTown_Movement_WalkLeft3
	waitmovement 0
	delay 30
	releaseall
	end

TwinleafTown_EventScript_LeaveBlock4::
	lockall
	call TwinleafTown_EventScript_BlockExclaim
	applymovement LOCALID_TWINLEAF_GUITARIST, TwinleafTown_Movement_RunRight4
	applymovement LOCALID_TWINLEAF_GUITARIST, Common_Movement_FaceDown
	waitmovement 0
	call TwinleafTown_EventScript_BlockBump
	applymovement LOCALID_TWINLEAF_GUITARIST, TwinleafTown_Movement_WalkLeft4
	waitmovement 0
	delay 30
	releaseall
	end

TwinleafTown_EventScript_LeaveBlock5::
	lockall
	call TwinleafTown_EventScript_BlockExclaim
	applymovement LOCALID_TWINLEAF_GUITARIST, TwinleafTown_Movement_RunRight5
	applymovement LOCALID_TWINLEAF_GUITARIST, Common_Movement_FaceDown
	waitmovement 0
	call TwinleafTown_EventScript_BlockBump
	applymovement LOCALID_TWINLEAF_GUITARIST, TwinleafTown_Movement_WalkLeft5
	waitmovement 0
	delay 30
	releaseall
	end

TwinleafTown_EventScript_LeaveBlock6::
	lockall
	call TwinleafTown_EventScript_BlockExclaim
	applymovement LOCALID_TWINLEAF_GUITARIST, TwinleafTown_Movement_RunRight6
	applymovement LOCALID_TWINLEAF_GUITARIST, Common_Movement_FaceDown
	waitmovement 0
	call TwinleafTown_EventScript_BlockBump
	applymovement LOCALID_TWINLEAF_GUITARIST, TwinleafTown_Movement_WalkLeft6
	waitmovement 0
	delay 30
	releaseall
	end

TwinleafTown_EventScript_LeaveBlock7::
	lockall
	call TwinleafTown_EventScript_BlockExclaim
	applymovement LOCALID_TWINLEAF_GUITARIST, TwinleafTown_Movement_RunRight7
	applymovement LOCALID_TWINLEAF_GUITARIST, Common_Movement_FaceDown
	waitmovement 0
	call TwinleafTown_EventScript_BlockBump
	applymovement LOCALID_TWINLEAF_GUITARIST, TwinleafTown_Movement_WalkLeft7
	waitmovement 0
	delay 30
	releaseall
	end

TwinleafTown_Movement_RunRight1:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	step_end

TwinleafTown_Movement_RunRight2:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	step_end

TwinleafTown_Movement_RunRight3:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

TwinleafTown_Movement_RunRight4:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

TwinleafTown_Movement_RunRight5:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

TwinleafTown_Movement_RunRight6:
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

TwinleafTown_Movement_RunRight7:
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

TwinleafTown_Movement_WalkLeft1:
	walk_left
	walk_down
	step_end

TwinleafTown_Movement_WalkLeft2:
	walk_left
	walk_left
	walk_down
	step_end

TwinleafTown_Movement_WalkLeft3:
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

TwinleafTown_Movement_WalkLeft4:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

TwinleafTown_Movement_WalkLeft5:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

TwinleafTown_Movement_WalkLeft6:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

TwinleafTown_Movement_WalkLeft7:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	step_end

TwinleafTown_Text_Thud:
	.string "THUD!!$"

TwinleafTown_Text_RivalBump:
	.string "{RIVAL}: What was that about?!\p"
	.string "Oh hey! {PLAYER}!\p"
	.string "Hey! I'm going to see Prof. Rowan!\n"
	.string "You should come, too! And quickly!$"

TwinleafTown_Text_RivalForget:
	.string "{RIVAL}: Oh, jeez!\n"
	.string "Forgot something!$"

TwinleafTown_EventScript_TownSign::
	msgbox TwinleafTown_Text_TownSign, MSGBOX_SIGN
	end

TwinleafTown_EventScript_PlayersHouseSign::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, TwinleafTown_EventScript_PlayersHouseSignMale
	call_if_eq VAR_RESULT, FEMALE, TwinleafTown_EventScript_BirchsHouseSignFemale
	releaseall
	end

TwinleafTown_EventScript_PlayersHouseSignMale::
	msgbox TwinleafTown_Text_PlayersHouse, MSGBOX_DEFAULT
	return

TwinleafTown_EventScript_BirchsHouseSignFemale::
	msgbox TwinleafTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
	return

TwinleafTown_EventScript_MaysHouseSign::
	lockall
	checkplayergender
	call_if_eq VAR_RESULT, MALE, TwinleafTown_EventScript_BirchsHouseSignMale
	call_if_eq VAR_RESULT, FEMALE, TwinleafTown_EventScript_PlayersHouseSignFemale
	releaseall
	end

TwinleafTown_EventScript_BirchsHouseSignMale::
	msgbox TwinleafTown_Text_ProfBirchsHouse, MSGBOX_DEFAULT
	return

TwinleafTown_EventScript_PlayersHouseSignFemale::
	msgbox TwinleafTown_Text_PlayersHouse, MSGBOX_DEFAULT
	return

TwinleafTown_EventScript_FatMan::
	msgbox TwinleafTown_Text_FatMan, MSGBOX_NPC
	end

TwinleafTown_EventScript_Aroma::
	goto_if_lt VAR_TWINLEAF_INTRO_STATE, 6, TwinleafTown_EventScript_Aroma_Talk1
	goto_if_eq VAR_TWINLEAF_INTRO_STATE, 6, TwinleafTown_EventScript_Aroma_Talk2
	goto TwinleafTown_EventScript_Aroma_Talk3
	end

TwinleafTown_EventScript_Aroma_Talk1::
	msgbox TwinleafTown_Text_Aroma1, MSGBOX_NPC
	end

TwinleafTown_EventScript_Aroma_Talk2::
	msgbox TwinleafTown_Text_Aroma2, MSGBOX_NPC
	end

TwinleafTown_EventScript_Aroma_Talk3::
	msgbox TwinleafTown_Text_Aroma3, MSGBOX_NPC
	end

TwinleafTown_EventScript_Guitarist::
	goto_if_lt VAR_TWINLEAF_INTRO_STATE, 5, TwinleafTown_EventScript_Guitarist_Talk1
	goto_if_eq VAR_TWINLEAF_INTRO_STATE, 5, TwinleafTown_EventScript_Guitarist_Talk2
	goto_if_eq VAR_TWINLEAF_INTRO_STATE, 6, TwinleafTown_EventScript_Guitarist_Talk3
	goto TwinleafTown_EventScript_Guitarist_Talk4
	end

TwinleafTown_EventScript_Guitarist_Talk1::
	msgbox TwinleafTown_Text_Guitarist1, MSGBOX_NPC
	end

TwinleafTown_EventScript_Guitarist_Talk2::
	msgbox TwinleafTown_Text_Guitarist2, MSGBOX_NPC
	end

TwinleafTown_EventScript_Guitarist_Talk3::
	msgbox TwinleafTown_Text_Guitarist3, MSGBOX_NPC
	end

TwinleafTown_EventScript_Guitarist_Talk4::
	msgbox TwinleafTown_Text_Guitarist4, MSGBOX_NPC
	end

TwinleafTown_Text_FatMan:
	.string "Technology just blows me away!\p"
	.string "I mean, now you can play with people\n"
	.string "around the world... wirelessly!$"

TwinleafTown_Text_Aroma1:
	.string "It's true that wild Pokémon do attack\n"
	.string "people sometimes...\p"
	.string "However, Pokémon also let you become\n"
	.string "friends with them.$"

TwinleafTown_Text_Aroma2:
	.string "Oh! A Pokémon!\n"
	.string "You look good together!$"

TwinleafTown_Text_Aroma3:
	.string "Oh, you're helping put together\n"
	.string "a Pokédex?\p"
	.string "That means you're going to travel\n"
	.string "all over the region with Pokémon!\p"
	.string "That sounds like a lot of fun\n"
	.string "I'm a little envious, to be honest!$"
	
TwinleafTown_Text_Guitarist1:
	.string "Hiya, {PLAYER}.\n"
	.string "{RIVAL} was looking for you.\p"
	.string "I think he's home now.\n"
	.string "Why don't you go check it out?$"
	
TwinleafTown_Text_Guitarist2:
	.string "Hiya, {PLAYER}.\n"
	.string "You're looking for {RIVAL}?\p"
	.string "He just went tearing off a little\n"
	.string "while ago.\p"
	.string "He's probably not gone too far.\n"
	.string "Why not go chase after him?$"
	
TwinleafTown_Text_Guitarist3:
	.string "{RIVAL}? He went tearing off\n"
	.string "in a huge rush a while ago.$"

TwinleafTown_Text_Guitarist4:
	.string "Everyone goes off on adventures,\n"
	.string "and then they gradually grow up...$"

TwinleafTown_Text_TownSign:
	.string "Twinleaf Town\n"
	.string "Fresh and free!$"

TwinleafTown_Text_PlayersHouse:
	.string "{PLAYER}'s House$"

TwinleafTown_Text_ProfBirchsHouse:
	.string "{RIVAL}'s House$"
