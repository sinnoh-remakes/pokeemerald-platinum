LittlerootTown_BrendansHouse_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_2F_OnTransition
	.byte 0

LittlerootTown_BrendansHouse_2F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 0, LittlerootTown_BrendansHouse_2F_Init
	end

LittlerootTown_BrendansHouse_2F_Init::
	setrespawn HEAL_LOCATION_LITTLEROOT_TOWN_BRENDANS_HOUSE_2F
	end

LittlerootTown_BrendansHouse_2F_EventScript_PC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_TurnOffPlayerPC::
	setvar VAR_0x8004, PC_LOCATION_BRENDANS_HOUSE
	playse SE_PC_OFF
	special DoPCTurnOffEffect
	releaseall
	end

LittlerootTown_BrendansHouse_2F_EventScript_Controls::
	msgbox LittlerootTown_BrendansHouse_2F_Text_Controls, MSGBOX_SIGN
	return

LittlerootTown_BrendansHouse_2F_EventScript_Notebook::
	msgbox LittlerootTown_BrendansHouse_2F_Text_Notebook, MSGBOX_SIGN
	end

LittlerootTown_BrendansHouse_2F_EventScript_TV::
	msgbox LittlerootTown_BrendansHouse_2F_Text_TV, MSGBOX_SIGN
	end

LittlerootTown_BrendansHouse_2F_EventScript_GameCube::
	msgbox LittlerootTown_BrendansHouse_2F_Text_GameCube, MSGBOX_SIGN
	end

LittlerootTown_BrendansHouse_2F_Text_Controls:
	.string "The X button opens the menu!$"

LittlerootTown_BrendansHouse_2F_Text_Notebook:
	.string "Pokémon Basics...\p"
	.string "People live alongside Pokémon in\n"
	.string "this world.\p"
	.string "The people that battle Pokémon are\n"
	.string "called Pokémon Trainers.$"

LittlerootTown_BrendansHouse_2F_Text_TV:
	.string "The TV is showing the title screen\n"
	.string "of a video game.$"

LittlerootTown_BrendansHouse_2F_Text_GameCube:
	.string "It's a Nintendo GameCube!\p"
	.string "It's controlled by a Gameboy Advance!$"

Common_Text_LookCloserAtMap:
	.string "{PLAYER} took a closer look at the\n"
	.string "SINNOH region map.$"
