SandgemTown_PokemonCenter_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SandgemTown_PokemonCenter_1F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SandgemTown_PokemonCenter_1F_OnTransition:
	setrespawn HEAL_LOCATION_SANDGEM_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

SandgemTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_SANDGEM_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SandgemTown_PokemonCenter_1F_EventScript_Gentleman::
	msgbox SandgemTown_PokemonCenter_1F_Text_FancyBlueOne, MSGBOX_NPC
	end

SandgemTown_PokemonCenter_1F_EventScript_Boy::
	msgbox SandgemTown_PokemonCenter_1F_Text_NiceLady, MSGBOX_NPC
	end

SandgemTown_PokemonCenter_1F_EventScript_Girl::
	lock
	faceplayer
	msgbox SandgemTown_PokemonCenter_1F_Text_TopFloor, MSGBOX_DEFAULT
	release
	end

SandgemTown_PokemonCenter_1F_EventScript_Lady::
	lock
	faceplayer
	msgbox SandgemTown_PokemonCenter_1F_Text_WorkingUnderground, MSGBOX_DEFAULT
	release
	end

SandgemTown_PokemonCenter_1F_Text_FancyBlueOne:
	.string "Do you see that PC over there?\n"
	.string "That fancy blue one?.\p"
	.string "If you've got Pokémon with you,\n"
	.string "it's free to use.$"

SandgemTown_PokemonCenter_1F_Text_NiceLady:
	.string "Talk to that nice lady at the counter\n"
	.string "and hand her your Pokémon.\p"
	.string "She'll heal your Pokémon to perfect\n"
	.string "health in no time at all!$"

SandgemTown_PokemonCenter_1F_Text_TopFloor:
	.string "The top floor of any Pokémon Center\n"
	.string "is the Pokémon Communication Club.\p"
	.string "There, you can have all sorts of fun\n"
	.string "with your friends.$"

SandgemTown_PokemonCenter_1F_Text_WorkingUnderground:
	.string "I'm very sorry\p"
	.string "We are working underground right now.\n"
	.string "It's off-limits to the public.\p"
	.string "Please try later on.$"
