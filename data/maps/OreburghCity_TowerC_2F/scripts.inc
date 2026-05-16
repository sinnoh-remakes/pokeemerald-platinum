OreburghCity_TowerC_2F_MapScripts::
	.byte 0

OreburghCity_TowerC_2F_EventScript_YoungsterGreatBall::
	goto_if_set FLAG_OREBURGH_CITY_GREAT_BALL, OreburghCity_TowerC_2F_EventScript_YoungsterGreatBallReceived
	msgbox OreburghCity_TowerC_2F_Text_TwinklingBrightly, MSGBOX_DEFAULT
	giveitem ITEM_GREAT_BALL
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_OREBURGH_CITY_GREAT_BALL
	msgbox OreburghCity_TowerC_2F_Text_YouKnowHow, MSGBOX_DEFAULT
	closemessage
	end

OreburghCity_TowerC_2F_EventScript_YoungsterGreatBallReceived::
	msgbox OreburghCity_TowerC_2F_Text_YouKnowHow, MSGBOX_NPC
	end

OreburghCity_TowerC_2F_EventScript_Gentleman::
	msgbox OreburghCity_TowerC_2F_Text_MineIsOperated, MSGBOX_NPC
	end

OreburghCity_TowerC_2F_EventScript_Scientist::
	msgbox OreburghCity_TowerC_2F_Text_CoalIsCarried, MSGBOX_NPC
	end

OreburghCity_TowerC_2F_Text_TwinklingBrightly:
	.string "Wow... Your Pokémon’s eyes are\n"
	.string "twinkling brightly!\p"
	.string "Seeing that makes me happy!\n"
	.string "Here, I want you to have this!$"

OreburghCity_TowerC_2F_Text_YouKnowHow:
	.string "You know how Pokémon stay inside\n"
	.string "their Poké Balls?\p"
	.string "I try to think about what would be\n"
	.string "the best Poké Balls for them.$"

OreburghCity_TowerC_2F_Text_MineIsOperated:
	.string "The Oreburgh Mine is operated\n"
	.string "with the utmost care.\p"
	.string "We avoid causing any damage to\n"
	.string "the natural habitats of Pokémon.$"

OreburghCity_TowerC_2F_Text_CoalIsCarried:
	.string "Coal is carried out of Oreburgh Mine on\n"
	.string "a fully automated system.\p"
	.string "Machines do all the work automatically.\n"
	.string "So, it’s all very easy.$"
