OreburghCity_TowerB_1F_MapScripts::
	.byte 0

OreburghCity_TowerB_1F_EventScript_Breeder::
	msgbox OreburghCity_TowerB_1F_Text_WhenYouTrade, MSGBOX_NPC
	end

OreburghCity_TowerB_1F_EventScript_SchoolKidF::
	lock
	faceplayer
	goto_if_set FLAG_OREBURGH_NPC_TRADE_COMPLETED, OreburghCity_TowerB_1F_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_ABRA
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox OreburghCity_TowerB_1F_Text_ListenListen, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, OreburghCity_TowerB_1F_EventScript_SchoolKidFReject
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, OreburghCity_TowerB_1F_EventScript_SchoolKidFReject
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, OreburghCity_TowerB_1F_EventScript_WhatIAskedFor
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	lock
	faceplayer
	msgbox OreburghCity_TowerB_1F_Text_BeNiceTo, MSGBOX_DEFAULT
	setflag FLAG_OREBURGH_NPC_TRADE_COMPLETED
	release
	end

OreburghCity_TowerB_1F_EventScript_WhatIAskedFor::
	lock
	faceplayer
	msgbox OreburghCity_TowerB_1F_Text_WhatIAskedFor, MSGBOX_DEFAULT
	release
	end

OreburghCity_TowerB_1F_EventScript_SchoolKidFReject::
	lock
	msgbox OreburghCity_TowerB_1F_Text_MakeYouTradeMe, MSGBOX_DEFAULT
	release
	end

OreburghCity_TowerB_1F_EventScript_TradeCompleted::
	lock
	msgbox OreburghCity_TowerB_1F_Text_FriendsWithYou, MSGBOX_DEFAULT
	release
	end

OreburghCity_TowerB_1F_EventScript_Expert::
	msgbox OreburghCity_TowerB_1F_Text_ObtainedInATrade, MSGBOX_NPC
	end

OreburghCity_TowerB_1F_Text_WhenYouTrade:
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

OreburghCity_TowerB_1F_Text_WhatIAskedFor:
	.string "What I asked for was a MACHOP...$"

OreburghCity_TowerB_1F_Text_MakeYouTradeMe:
	.string "Oh, OK...\n"
	.string "Well, I can’t make you trade me.\p"
	.string "But if you change your mind,\n"
	.string "I’ll be right here waiting!$"

OreburghCity_TowerB_1F_Text_FriendsWithYou:
	.string "Thanks to Pokémon, I got to be\n"
	.string "friends with you!$"

OreburghCity_TowerB_1F_Text_ObtainedInATrade:
	.string "A Pokémon obtained in a trade grows\n"
	.string "quickly.\p"
	.string "But if a Pokémon grows too much, it may\n"
	.string "ignore the Trainer.\p"
	.string "Of course, it won’t matter if you have\n"
	.string "lots of Gym Badges.$"
