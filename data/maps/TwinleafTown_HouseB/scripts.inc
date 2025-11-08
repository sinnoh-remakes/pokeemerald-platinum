TwinleafTown_HouseB_MapScripts::
	.byte 0

TwinleafTown_HouseB_EventScript_Man::
	lock
	faceplayer
	msgbox TwinleafTown_HouseB_Text_Man, MSGBOX_DEFAULT
	closemessage
	release
	end

TwinleafTown_HouseB_Text_Man:
	.string "I went on an adventure with some\n"
	.string "Pokémon a long time ago.\p"
	.string "It was only to the next town, though.\n"
	.string "Yeah, good times...$"
