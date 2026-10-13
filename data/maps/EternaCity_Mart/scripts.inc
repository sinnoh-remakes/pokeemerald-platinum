EternaCity_Mart_MapScripts::
	.byte 0

EternaCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart EternaCity_Mart_Pokemart_Primary
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
EternaCity_Mart_Pokemart_Primary:
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

EternaCity_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart EternaCity_Mart_Pokemart_Secondary
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
EternaCity_Mart_Pokemart_Secondary:
	.2byte ITEM_ORANGE_MAIL @ FODO: Implement ITEM_AIR_MAIL
	.2byte ITEM_HEAL_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_NEST_BALL
	pokemartlistend

EternaCity_Mart_EventScript_Guitarist::
	msgbox EternaCity_Mart_Text_MoreGymBadges, MSGBOX_NPC
	end

EternaCity_Mart_EventScript_Hiker::
	msgbox EternaCity_Mart_Text_EscapeRope, MSGBOX_NPC
	end

EternaCity_Mart_Text_MoreGymBadges:
	.string "The more Gym Badges you have, the\n"
	.string "better they treat you at Poké Marts.\p"
	.string "You get to buy a better selection of\n"
	.string "merchandise, you see.\p"
	.string "But I don’t have a single Gym Badge.\n"
	.string "It’s because Gardenia’s too much!\p"
	.string "Argh! I don’t want to see another\n"
	.string "grass Pokémon ever again!\p"
	.string "If only I had Flying-type Pokémon...\n"
	.string "Then my losing streak would end!$"

EternaCity_Mart_Text_EscapeRope:
	.string "An Escape Rope is indispensable!\p"
	.string "I wish I’d had one when I got into a \n"
	.string "tough spot in the Eterna Forest.\p"
	.string "I would’ve been able to warp to the\n"
	.string "entrance instantly!$"
