TwinleafTown_OtherHouseB_MapScripts::
	.byte 0

TwinleafTown_OtherHouseB_EventScript_Man::
	lock
	faceplayer
	msgbox TwinleafTown_OtherHouseB_Text_Man, MSGBOX_DEFAULT
	closemessage
	release
	end

TwinleafTown_OtherHouseB_Text_Man:
	.string "I went on an adventure with some\n"
	.string "Pokémon a long time ago.\p"
	.string "It was only to the next town, though.\n"
	.string "Yeah, good times...$"
