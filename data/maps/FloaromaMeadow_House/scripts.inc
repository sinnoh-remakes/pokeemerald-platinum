FloaromaMeadow_House_MapScripts::
	.byte 0

FloaromaMeadow_House_EventScript_Hiker::
	msgbox FloaromaMeadow_House_Text_FlowersThatGrow, MSGBOX_NPC
	end

FloaromaMeadow_House_EventScript_NinjaBoy::
	msgbox FloaromaMeadow_House_Text_PutHoney, MSGBOX_NPC
	end

FloaromaMeadow_House_Text_FlowersThatGrow:
	.string "The flowers that grow in the fields\n"
	.string "here are special.\p"
	.string "Do you see how they’re more vivid\n"
	.string "than flowers elsewhere in Sinnoh?\p"
	.string "You can thank Pokémon for that.$"

FloaromaMeadow_House_Text_PutHoney:
	.string "If you put Honey on a tree, check\n"
	.string "back later to see if it’s rustling.\p"
	.string "If it is, it’s quite often a rare\n"
	.string "Pokémon.\p"
	.string "It gets my hopes up if I see that\n"
	.string "happening.$"
