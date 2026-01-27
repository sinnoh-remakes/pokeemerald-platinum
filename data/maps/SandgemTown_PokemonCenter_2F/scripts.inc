SandgemTown_PokemonCenter_2F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SandgemTown_PokemonCenter_2F_OnTransition
	map_script MAP_SCRIPT_ON_RESUME, CableClub_OnResume
	.byte 0

SandgemTown_PokemonCenter_2F_OnTransition:
	setrespawn HEAL_LOCATION_SANDGEM_TOWN
	call Common_EventScript_UpdateBrineyLocation
	end

SandgemTown_PokemonCenter_2F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_OLDALE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

SandgemTown_PokemonCenter_2F_EventScript_Gentleman::
	msgbox SandgemTown_PokemonCenter_2F_Text_TrainersCanUsePC, MSGBOX_NPC
	end

SandgemTown_PokemonCenter_2F_EventScript_Boy::
	msgbox SandgemTown_PokemonCenter_2F_Text_PokemonCentersAreGreat, MSGBOX_NPC
	end

SandgemTown_PokemonCenter_2F_EventScript_Girl::
	lock
	faceplayer
	goto_if_set FLAG_SYS_POKEDEX_GET, SandgemTown_PokemonCenter_2F_EventScript_WirelessClubAvailable
	msgbox SandgemTown_PokemonCenter_2F_Text_WirelessClubNotAvailable, MSGBOX_DEFAULT
	release
	end

SandgemTown_PokemonCenter_2F_EventScript_WirelessClubAvailable::
	msgbox SandgemTown_PokemonCenter_2F_Text_TradedInWirelessClub, MSGBOX_DEFAULT
	release
	end

SandgemTown_PokemonCenter_2F_Text_TrainersCanUsePC:
	.string "That PC in the corner there is\n"
	.string "for any POKéMON TRAINER to use.\p"
	.string "Naturally, that means you're welcome\n"
	.string "to use it, too.$"

SandgemTown_PokemonCenter_2F_Text_PokemonCentersAreGreat:
	.string "POKéMON CENTERS are great!\p"
	.string "You can use their services as much\n"
	.string "as you like, and it's all for free.\l"
	.string "You never have to worry!$"

SandgemTown_PokemonCenter_2F_Text_WirelessClubNotAvailable:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "But they say they're still making\n"
	.string "adjustments.$"

SandgemTown_PokemonCenter_2F_Text_TradedInWirelessClub:
	.string "The POKéMON WIRELESS CLUB on\n"
	.string "the second floor was built recently.\p"
	.string "I traded POKéMON right away.$"

