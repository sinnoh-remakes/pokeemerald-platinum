LittlerootTown_OtherHouseB_MapScripts::
	.byte 0

LittlerootTown_OtherHouseB_EventScript_Man::
	lock
	faceplayer
	msgbox LittlerootTown_OtherHouseB_Text_Man, MSGBOX_DEFAULT
	closemessage
	release

LittlerootTown_OtherHouseB_Text_Man:
	.string "I went on an adventure with some\n"
	.string "Pokémon a long time ago.\p"
	.string "It was only to the next town, though.\n"
	.string "Yeah, good times...$"
