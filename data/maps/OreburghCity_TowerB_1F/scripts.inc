OreburghCity_TowerB_1F_MapScripts::
	.byte 0

OreburghCity_TowerB_1F_EventScript_Breeder::
	msgbox OreburghCity_TowerB_1F_WhenYouTrade, MSGBOX_NPC
	end

OreburghCity_TowerB_1F_EventScript_SchoolKidF::
	msgbox OreburghCity_TowerB_1F_Text_ListenListen, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, OreburghCity_TowerB_1F_EventScript_SchoolKidFTrade
	@ FODO: Implement Abra trade
	case YES, OreburghCity_TowerB_1F_EventScript_SchoolKidFReject
	case MULTI_B_PRESSED, OreburghCity_TowerB_1F_EventScript_SchoolKidFReject
	end

OreburghCity_TowerB_1F_EventScript_SchoolKidFTrade::
	msgbox OreburghCity_TowerB_1F_Text_BeNiceTo, MSGBOX_DEFAULT
	closemessage
	end

OreburghCity_TowerB_1F_EventScript_SchoolKidFReject::
	msgbox OreburghCity_TowerB_1F_Text_MakeYouTradeMe, MSGBOX_DEFAULT
	closemessage
	end

OreburghCity_TowerB_1F_EventScript_Expert::
	msgbox OreburghCity_TowerB_1F_ObtainedInATrade, MSGBOX_NPC
	end

OreburghCity_TowerB_1F_WhenYouTrade:
	.string "When you trade a Pokémon, the item it’s\n"
	.string "holding is traded as well.\p"
	.string "That’s pretty cool, huh?\p"
	.string "It means you can send an item as a gift\n"
	.string "along with your Pokémon in a trade!$"

OreburghCity_TowerB_1F_Text_ListenListen:
	.string "Listen, listen. Do you have a Pokémon\n"
	.string "called MACHOP?\p"
	.string "Would you be willing to trade your\n"
	.string "MACHOP for my ABRA?$"

OreburghCity_TowerB_1F_Text_BeNiceTo:
	.string "Be nice to my ABRA!\p"
	.string "I’ll be sure to look after your MACHOP\n"
	.string "in return!$"

@ OreburghCity_TowerB_1F_WhatIAskedFor:
@ 	.string "What I asked for was a MACHOP..$."

OreburghCity_TowerB_1F_Text_MakeYouTradeMe:
	.string "Oh, OK...\n"
	.string "Well, I can’t make you trade me.\p"
	.string "But if you change your mind,\n"
	.string "I’ll be right here waiting!$"

@ OreburghCity_TowerB_1F_FriendsWithYou:
@ 	.string "Thanks to Pokémon, I got to be\n"
@ 	.string "friends with you!$"

OreburghCity_TowerB_1F_ObtainedInATrade:
	.string "A Pokémon obtained in a trade grows\n"
	.string "quickly.\p"
	.string "But if a Pokémon grows too much, it may\n"
	.string "ignore the Trainer.\p"
	.string "Of course, it won’t matter if you have\n"
	.string "lots of Gym Badges.$"
