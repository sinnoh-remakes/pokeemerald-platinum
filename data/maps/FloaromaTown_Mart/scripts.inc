FloaromaTown_Mart_MapScripts::
	.byte 0

FloaromaTown_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FloaromaTown_Mart_Pokemart_Primary
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FloaromaTown_Mart_Pokemart_Primary:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	pokemartlistend

FloaromaTown_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FloaromaTown_Mart_Pokemart_Secondary
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FloaromaTown_Mart_Pokemart_Secondary:
	.2byte ITEM_ORANGE_MAIL @ FODO: Implement ITEM_BLOOM_MAIL
	.2byte ITEM_HEAL_BALL
	.2byte ITEM_NET_BALL
	pokemartlistend

FloaromaTown_Mart_EventScript_SchoolKidF::
	msgbox FloaromaTown_Mart_Text_DressUp, MSGBOX_NPC
	end

FloaromaTown_Mart_EventScript_BattleGirl::
	msgbox FloaromaTown_Mart_Text_BuyBerries, MSGBOX_NPC
	end

FloaromaTown_Mart_Text_DressUp:
	.string "I'm going to dress up my Pokémon with\n"
	.string "cute Accessories and take it to the\l"
	.string "TV station in Jubilife City.\p"
	.string "That way, everyone in the region\n"
	.string "will be able to see my Pokémon!$"

FloaromaTown_Mart_Text_BuyBerries:
	.string "You can’t buy Berries or Accessories\n"
	.string "at Poké Marts.\p"
	.string "It’s better for me that way.\n"
	.string "I won’t waste money impulse shopping.$"
