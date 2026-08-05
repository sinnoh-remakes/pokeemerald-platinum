FloaromaTown_HouseB_MapScripts::
	.byte 0

FloaromaTown_HouseB_EventScript_PokeFanM::
	msgbox FloaromaTown_HouseB_Text_SomeKinds, MSGBOX_NPC
	end

FloaromaTown_HouseB_EventScript_PokeFanF::
	msgbox FloaromaTown_HouseB_Text_AcuteSense, MSGBOX_NPC
	end

FloaromaTown_HouseB_Text_SomeKinds:
	.string "Some kinds of Pokémon appear only\n"
	.string "if they’re attracted by the sweet\l"
	.string "scent of Honey.$"

FloaromaTown_HouseB_Text_AcuteSense:
	.string "Pokémon must have an acute sense\n"
	.string "of smell.\p"
	.string "They can sense the aroma of Honey\n"
	.string "from very far away.$"
