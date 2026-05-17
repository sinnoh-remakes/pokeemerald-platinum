OreburghCity_Mart_MapScripts::
	.byte 0

OreburghCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart OreburghCity_Mart_Pokemart_Primary
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OreburghCity_Mart_Pokemart_Primary:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	pokemartlistend

OreburghCity_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart OreburghCity_Mart_Pokemart_Secondary
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
OreburghCity_Mart_Pokemart_Secondary:
	.2byte ITEM_ORANGE_MAIL @ FODO: Implement ITEM_TUNNEL_MAIL
	.2byte ITEM_HEAL_BALL
	.2byte ITEM_NET_BALL
	pokemartlistend

OreburghCity_Mart_EventScript_Hiker::
	msgbox OreburghCity_Mart_Text_GymsGiveYou, MSGBOX_NPC
	end

OreburghCity_Mart_EventScript_Collector::
	msgbox OreburghCity_Mart_Text_StaffedBy, MSGBOX_NPC
	end

OreburghCity_Mart_Text_GymsGiveYou:
	.string "The Badges that Pokémon Gyms give you\n"
	.string "are a measure of a Trainer’s worth.\p"
	.string "By getting more Badges, you get to\n"
	.string "buy more items in Poké Marts.$"

OreburghCity_Mart_Text_StaffedBy:
	.string "The Poké Mart is staffed by a lady and\n"
	.string "a young fellow.\p"
	.string "They offer different kinds of\n"
	.string "merchandise. Did you know?$"
