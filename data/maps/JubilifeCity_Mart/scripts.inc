JubilifeCity_Mart_MapScripts::
	.byte 0

JubilifeCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart JubilifeCity_Mart_Pokemart_Primary
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
JubilifeCity_Mart_Pokemart_Primary:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	pokemartlistend

JubilifeCity_Mart_EventScript_Clerk2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart JubilifeCity_Mart_Pokemart_Secondary
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
JubilifeCity_Mart_Pokemart_Secondary:
	.2byte ITEM_ORANGE_MAIL @ FODO: Implement ITEM_AIR_MAIL
	.2byte ITEM_HEAL_BALL
	pokemartlistend

JubilifeCity_Mart_EventScript_Woman::
	msgbox JubilifeCity_Mart_Text_PackPotions, MSGBOX_DEFAULT
	release
	end

JubilifeCity_Mart_EventScript_Guitarist::
	msgbox JubilifeCity_Mart_Text_WastedMoney, MSGBOX_DEFAULT
	release
	end

JubilifeCity_Mart_EventScript_Beauty::
	msgbox JubilifeCity_Mart_Text_AvoidBattles, MSGBOX_DEFAULT
	release
	end

JubilifeCity_Mart_Text_PackPotions::
	.string "The one thing you must remember is to\n"
	.string "pack some Potions.\p"
	.string "If all your Pokémon faint, it'll be\n"
	.string "lights out for you, too!$"

JubilifeCity_Mart_Text_WastedMoney::
	.string "Aww, man.\n"
	.string "I wasted money on some Poké Balls.\p"
	.string "I should've lowered the HP of wild\n"
	.string "Pokémon more before throwing them.$"

JubilifeCity_Mart_Text_AvoidBattles::
	.string "Potions are important, but sometimes,\n"
	.string "it's better to simply avoid battles.\p"
	.string "If you want to avoid wild Pokémon for a\n"
	.string "while, just use a Repel.\p"
	.string "After all, if you don't battle, your\n"
	.string "Pokémon can't lose HP.$"
