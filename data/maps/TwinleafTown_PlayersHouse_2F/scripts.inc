TwinleafTown_PlayersHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TwinleafTown_PlayersHouse_2F_OnTransition
	.byte 0

TwinleafTown_PlayersHouse_2F_OnTransition:
	call_if_eq VAR_TWINLEAF_INTRO_STATE, 0, TwinleafTown_PlayersHouse_2F_Init
	end

TwinleafTown_PlayersHouse_2F_Init::
	setrespawn HEAL_LOCATION_TWINLEAF_TOWN_PLAYERS_HOUSE
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	end

TwinleafTown_PlayersHouse_2F_EventScript_RivalEnterUp::
	lock
	setvar VAR_TWINLEAF_INTRO_STATE, 1
	call TwinleafTown_PlayersHouse_2F_EventScript_RivalEnter
	applymovement LOCALID_TWINLEAF_PLAYER2F_RIVAL, TwinleafTown_PlayersHouse_2F_Movement_MeetUp
	waitmovement 0
	call TwinleafTown_PlayersHouse_2F_EventScript_RivalExplain
	applymovement LOCALID_PLAYER, TwinleafTown_PlayersHouse_2F_Movement_PlayerLeft
	applymovement LOCALID_TWINLEAF_PLAYER2F_RIVAL, TwinleafTown_PlayersHouse_2F_Movement_PCUp
	waitmovement 0
	call TwinleafTown_PlayersHouse_2F_EventScript_RivalPC
	applymovement LOCALID_TWINLEAF_PLAYER2F_RIVAL, TwinleafTown_PlayersHouse_2F_Movement_ReturnUp
	waitmovement 0
	msgbox TwinleafTown_PlayersHouse_2F_Text_RightRight, MSGBOX_SIGN
	applymovement LOCALID_PLAYER, TwinleafTown_PlayersHouse_2F_Movement_PlayerRight
	applymovement LOCALID_TWINLEAF_PLAYER2F_RIVAL, TwinleafTown_PlayersHouse_2F_Movement_ExitUp
	waitmovement 0
	removeobject LOCALID_TWINLEAF_PLAYER2F_RIVAL
	delay 48
	release
	end

TwinleafTown_PlayersHouse_2F_EventScript_RivalEnterLeft::
	lock
	setvar VAR_TWINLEAF_INTRO_STATE, 1
	call TwinleafTown_PlayersHouse_2F_EventScript_RivalEnter
	applymovement LOCALID_TWINLEAF_PLAYER2F_RIVAL, TwinleafTown_PlayersHouse_2F_Movement_MeetLeft
	waitmovement 0
	call TwinleafTown_PlayersHouse_2F_EventScript_RivalExplain
	applymovement LOCALID_PLAYER, TwinleafTown_PlayersHouse_2F_Movement_PlayerLeft
	applymovement LOCALID_TWINLEAF_PLAYER2F_RIVAL, TwinleafTown_PlayersHouse_2F_Movement_PCLeft
	waitmovement 0
	call TwinleafTown_PlayersHouse_2F_EventScript_RivalPC
	applymovement LOCALID_TWINLEAF_PLAYER2F_RIVAL, TwinleafTown_PlayersHouse_2F_Movement_ReturnLeft
	waitmovement 0
	msgbox TwinleafTown_PlayersHouse_2F_Text_RightRight, MSGBOX_SIGN
	applymovement LOCALID_PLAYER, TwinleafTown_PlayersHouse_2F_Movement_PlayerRight
	applymovement LOCALID_TWINLEAF_PLAYER2F_RIVAL, TwinleafTown_PlayersHouse_2F_Movement_ExitLeft
	waitmovement 0
	removeobject LOCALID_TWINLEAF_PLAYER2F_RIVAL
	delay 48
	release
	end

TwinleafTown_PlayersHouse_2F_EventScript_RivalEnterDown::
	lock
	setvar VAR_TWINLEAF_INTRO_STATE, 1
	call TwinleafTown_PlayersHouse_2F_EventScript_RivalEnter
	applymovement LOCALID_TWINLEAF_PLAYER2F_RIVAL, TwinleafTown_PlayersHouse_2F_Movement_MeetDown
	waitmovement 0
	call TwinleafTown_PlayersHouse_2F_EventScript_RivalExplain
	applymovement LOCALID_PLAYER, TwinleafTown_PlayersHouse_2F_Movement_PlayerLeft
	applymovement LOCALID_TWINLEAF_PLAYER2F_RIVAL, TwinleafTown_PlayersHouse_2F_Movement_PCDown
	waitmovement 0
	call TwinleafTown_PlayersHouse_2F_EventScript_RivalPC
	applymovement LOCALID_TWINLEAF_PLAYER2F_RIVAL, TwinleafTown_PlayersHouse_2F_Movement_ReturnDown
	waitmovement 0
	msgbox TwinleafTown_PlayersHouse_2F_Text_RightRight, MSGBOX_SIGN
	applymovement LOCALID_PLAYER, TwinleafTown_PlayersHouse_2F_Movement_PlayerRight
	applymovement LOCALID_TWINLEAF_PLAYER2F_RIVAL, TwinleafTown_PlayersHouse_2F_Movement_ExitDown
	waitmovement 0
	removeobject LOCALID_TWINLEAF_PLAYER2F_RIVAL
	delay 48
	release
	end

TwinleafTown_PlayersHouse_2F_EventScript_RivalEnterRight::
	lock
	setvar VAR_TWINLEAF_INTRO_STATE, 1
	call TwinleafTown_PlayersHouse_2F_EventScript_RivalEnter
	applymovement LOCALID_TWINLEAF_PLAYER2F_RIVAL, TwinleafTown_PlayersHouse_2F_Movement_MeetRight
	waitmovement 0
	call TwinleafTown_PlayersHouse_2F_EventScript_RivalExplain
	applymovement LOCALID_PLAYER, TwinleafTown_PlayersHouse_2F_Movement_PlayerLeft
	applymovement LOCALID_TWINLEAF_PLAYER2F_RIVAL, TwinleafTown_PlayersHouse_2F_Movement_PCRight
	waitmovement 0
	call TwinleafTown_PlayersHouse_2F_EventScript_RivalPC
	applymovement LOCALID_TWINLEAF_PLAYER2F_RIVAL, TwinleafTown_PlayersHouse_2F_Movement_ReturnRight
	waitmovement 0
	msgbox TwinleafTown_PlayersHouse_2F_Text_RightRight, MSGBOX_SIGN
	applymovement LOCALID_PLAYER, TwinleafTown_PlayersHouse_2F_Movement_PlayerRight
	applymovement LOCALID_TWINLEAF_PLAYER2F_RIVAL, TwinleafTown_PlayersHouse_2F_Movement_ExitRight
	waitmovement 0
	removeobject LOCALID_TWINLEAF_PLAYER2F_RIVAL
	delay 48
	release
	end

TwinleafTown_PlayersHouse_2F_EventScript_RivalEnter::
	addobject LOCALID_TWINLEAF_PLAYER2F_RIVAL
	applymovement LOCALID_TWINLEAF_PLAYER2F_RIVAL, TwinleafTown_PlayersHouse_2F_Movement_RivalEnter
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_FaceRight
	applymovement LOCALID_TWINLEAF_PLAYER2F_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	msgbox TwinleafTown_PlayersHouse_2F_Text_ThereYouAre, MSGBOX_SIGN
	return

TwinleafTown_PlayersHouse_2F_EventScript_RivalExplain::
	msgbox TwinleafTown_PlayersHouse_2F_Text_SeeTV, MSGBOX_SIGN
	playse SE_PIN
	applymovement LOCALID_TWINLEAF_PLAYER2F_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	return

TwinleafTown_PlayersHouse_2F_EventScript_RivalPC::
	msgbox TwinleafTown_PlayersHouse_2F_Text_NewPC, MSGBOX_SIGN
	applymovement LOCALID_TWINLEAF_PLAYER2F_RIVAL, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox TwinleafTown_PlayersHouse_2F_Text_WhereWas, MSGBOX_SIGN
	return

TwinleafTown_PlayersHouse_2F_Movement_RivalEnter:
	walk_fast_left
	step_end

TwinleafTown_PlayersHouse_2F_Movement_PlayerLeft:
	delay_16
	delay_16
	walk_in_place_left
	step_end

TwinleafTown_PlayersHouse_2F_Movement_PlayerRight:
	delay_16
	delay_16
	walk_in_place_right
	step_end
	
TwinleafTown_PlayersHouse_2F_Movement_MeetUp:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
	
TwinleafTown_PlayersHouse_2F_Movement_MeetLeft:
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
	
TwinleafTown_PlayersHouse_2F_Movement_MeetDown:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end
	
TwinleafTown_PlayersHouse_2F_Movement_MeetRight:
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

TwinleafTown_PlayersHouse_2F_Movement_PCUp:
	walk_fast_down
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end
	
TwinleafTown_PlayersHouse_2F_Movement_PCLeft:
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_in_place_up
	step_end

TwinleafTown_PlayersHouse_2F_Movement_PCDown:
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_up
	step_end

TwinleafTown_PlayersHouse_2F_Movement_PCRight:
	walk_fast_up
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_in_place_up
	step_end

TwinleafTown_PlayersHouse_2F_Movement_ReturnUp:
	walk_fast_right
	walk_fast_right
	step_end

TwinleafTown_PlayersHouse_2F_Movement_ReturnLeft:
	walk_fast_right
	walk_fast_down
	walk_in_place_right
	step_end

TwinleafTown_PlayersHouse_2F_Movement_ReturnDown:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_right
	step_end

TwinleafTown_PlayersHouse_2F_Movement_ReturnRight:
	walk_fast_right
	walk_fast_down
	walk_fast_right
	walk_fast_right
	step_end
	
TwinleafTown_PlayersHouse_2F_Movement_ExitUp:
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	step_end
	
TwinleafTown_PlayersHouse_2F_Movement_ExitLeft:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_right
	walk_fast_right
	step_end
	
TwinleafTown_PlayersHouse_2F_Movement_ExitDown:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_up
	walk_fast_right
	walk_fast_right
	step_end
	
TwinleafTown_PlayersHouse_2F_Movement_ExitRight:
	walk_fast_up
	walk_fast_right
	walk_fast_right
	walk_fast_up
	walk_fast_right
	walk_fast_right
	step_end

TwinleafTown_PlayersHouse_2F_EventScript_PC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

TwinleafTown_PlayersHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

TwinleafTown_PlayersHouse_2F_EventScript_Controls::
	msgbox TwinleafTown_PlayersHouse_2F_Text_Controls, MSGBOX_SIGN
	return

TwinleafTown_PlayersHouse_2F_EventScript_Notebook::
	msgbox TwinleafTown_PlayersHouse_2F_Text_Notebook, MSGBOX_SIGN
	end

TwinleafTown_PlayersHouse_2F_EventScript_TV::
	msgbox TwinleafTown_PlayersHouse_2F_Text_TV, MSGBOX_SIGN
	end

TwinleafTown_PlayersHouse_2F_EventScript_GameCube::
	msgbox TwinleafTown_PlayersHouse_2F_Text_GameCube, MSGBOX_SIGN
	end

TwinleafTown_PlayersHouse_2F_Text_ThereYouAre:
	.string "{RIVAL}: There you are!$"

TwinleafTown_PlayersHouse_2F_Text_SeeTV:
	.string "Hey, {PLAYER}!\n"
	.string "Did you just see the TV? Sure you did!\p"
	.string "Prof. Rowan's that really important\n"
	.string "guy who studies Pokémon, right?\p"
	.string "That means he must have lots and lots\n"
	.string "of Pokémon.\p"
	.string "So, if we ask him, I bet he'd give us\n"
	.string "some Pokémon!$"

TwinleafTown_PlayersHouse_2F_Text_NewPC:
	.string "Oh, hey!\n"
	.string "Is this a new PC?!$"
	
TwinleafTown_PlayersHouse_2F_Text_WhereWas:
	.string "{RIVAL}: Uh...\n"
	.string "Where was I?$"

TwinleafTown_PlayersHouse_2F_Text_RightRight:
	.string "Oh, right, right! We're going to go see\n"
	.string "Prof. Rowan to get some Pokémon.\p"
	.string "I'll be waiting outside.\p"
	.string "OK, {PLAYER}? If' you're late, I'm\n"
	.string "fining you ₽10 million!$"

TwinleafTown_PlayersHouse_2F_Text_Controls:
	.string "The X button opens the menu!$"

TwinleafTown_PlayersHouse_2F_Text_Notebook:
	.string "Pokémon Basics...\p"
	.string "People live alongside Pokémon in\n"
	.string "this world.\p"
	.string "The people that battle Pokémon are\n"
	.string "called Pokémon Trainers.$"

TwinleafTown_PlayersHouse_2F_Text_TV:
	.string "The TV is showing the title screen\n"
	.string "of a video game.$"

TwinleafTown_PlayersHouse_2F_Text_GameCube:
	.string "It's a Nintendo GameCube!\p"
	.string "It's controlled by a Gameboy Advance!$"
