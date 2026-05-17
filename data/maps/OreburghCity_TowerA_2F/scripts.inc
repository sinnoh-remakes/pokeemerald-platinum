OreburghCity_TowerA_2F_MapScripts::
	.byte 0

OreburghCity_TowerA_2F_EventScript_LassDuskBall::
	goto_if_set FLAG_OREBURGH_CITY_DUSK_BALL, OreburghCity_TowerA_2F_EventScript_LassDuskBallGiven
	lock
	faceplayer
	msgbox OreburghCity_TowerA_2F_Text_AreYouCatching, MSGBOX_DEFAULT
	giveitem ITEM_DUSK_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_OREBURGH_CITY_DUSK_BALL
	msgbox OreburghCity_TowerA_2F_Text_TheDuskBall, MSGBOX_DEFAULT
	closemessage
	release
	end

OreburghCity_TowerA_2F_EventScript_LassDuskBallGiven::
	msgbox OreburghCity_TowerA_2F_Text_TheDuskBall, MSGBOX_NPC
	end

OreburghCity_TowerA_2F_EventScript_Worker::
	msgbox OreburghCity_TowerA_2F_Text_GivingNicknames, MSGBOX_NPC
	end

OreburghCity_TowerA_2F_EventScript_Psyduck::
	@ FODO: Play Psyduck sound
	msgbox OreburghCity_TowerA_2F_Text_Duck, MSGBOX_NPC
	end

OreburghCity_TowerA_2F_EventScript_SchoolKidF::
	msgbox OreburghCity_TowerA_2F_Text_ButHeNamed, MSGBOX_NPC
	end

OreburghCity_TowerA_2F_Text_AreYouCatching:
	.string "Are you catching Pokémon?\n"
	.string "Here, take this if you’d like.$"

OreburghCity_TowerA_2F_Text_TheDuskBall:
	.string "The Dusk Ball is a Poké Ball designed\n"
	.string "for use in darkness.\p"
	.string "It works better if you use it at\n"
	.string "night or in a cave.$"

OreburghCity_TowerA_2F_Text_GivingNicknames:
	.string "Giving nicknames to Pokémon is\n"
	.string "the way to go.\p"
	.string "It makes you feel as if they’re your\n"
	.string "very own.$"

OreburghCity_TowerA_2F_Text_Duck:
	.string "Yellow: Duuuck?$"

OreburghCity_TowerA_2F_Text_ButHeNamed:
	.string "But he named our PSYDUCK “Yellow”\n"
	.string "just because of its color...\p"
	.string "I don’t understand the logic behind\n"
	.string "that at all.$"
