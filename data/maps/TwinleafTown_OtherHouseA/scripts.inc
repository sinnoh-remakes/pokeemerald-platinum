TwinleafTown_OtherHouseA_MapScripts::
	.byte 0

TwinleafTown_OtherHouseA_EventScript_Elder::
	lock
	faceplayer
	msgbox TwinleafTown_OtherHouseA_Text_Elder, MSGBOX_DEFAULT
	closemessage
	release
	end

TwinleafTown_OtherHouseA_EventScript_Twin::
	lock
	faceplayer
	msgbox TwinleafTown_OtherHouseA_Text_Twin, MSGBOX_DEFAULT
	closemessage
	release
	end

TwinleafTown_OtherHouseA_Text_Elder:
	.string "Did you hear?\p"
	.string "The Pokémon Professor returned\n"
	.string "to the next town over.\p"
	.string "They say he was gone for four long\n"
	.string "years.\p"
	.string "I wonder if he found some amazing\n"
	.string "Pokémon while he was gone?$"

TwinleafTown_OtherHouseA_Text_Twin:
	.string "Listen, listen {PLAYER}.\n"
	.string "I want a cute Pokémon!$"
