OreburghCitySouth_MapScripts::
	.byte 0

OreburghCitySouth_EventScript_PokefanF::
	msgbox OreburghCitySouth_Text_EveryoneProud, MSGBOX_NPC
	end

OreburghCitySouth_EventScript_Worker1::
	msgbox OreburghCitySouth_Text_DirtySand, MSGBOX_NPC
	end

OreburghCitySouth_EventScript_Machop1::
	msgbox OreburghCitySouth_Text_Machop1, MSGBOX_NPC
	end

OreburghCitySouth_EventScript_Worker2::
	msgbox OreburghCitySouth_Text_ChopChop, MSGBOX_NPC
	end

OreburghCitySouth_EventScript_Machop2::
	msgbox OreburghCitySouth_Text_Machop2, MSGBOX_NPC
	end

OreburghCitySouth_EventScript_WorkerSuperPotion::
	goto_if_set FLAG_ITEM_OREBURGH_CITY_SUPER_POTION, OreburghCitySouth_EventScript_WorkerSuperPotionGiven
	msgbox OreburghCitySouth_Text_NoQuestion, MSGBOX_DEFAULT
	giveitem ITEM_SUPER_POTION
	setflag FLAG_ITEM_OREBURGH_CITY_SUPER_POTION
	msgbox OreburghCitySouth_Text_HaleHearty, MSGBOX_DEFAULT
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	closemessage
	end

OreburghCitySouth_EventScript_WorkerSuperPotionGiven::
	msgbox OreburghCitySouth_Text_HaleHearty, MSGBOX_NPC
	end

OreburghCitySouth_EventScript_Machop3::
	msgbox OreburghCitySouth_Text_Machop3, MSGBOX_NPC
	end

OreburghCitySouth_Text_EveryoneProud:
	.string "Everyone’s proud of the mine.\p"
	.string "They’re digging for coal under the\n"
	.string "sea as we speak...\p"
	.string "It’s amazing how they do it!$"

OreburghCitySouth_Text_DirtySand:
	.string "This pile of dirty sand is called\n"
	.string "a slag heap.\p"
	.string "It’s the waste from sorting coal.$"

OreburghCitySouth_Text_Machop1:
	.string "MACHOP: Gwooh! Gogogooh!$"

OreburghCitySouth_Text_ChopChop:
	.string "Chop, chop, MACHOP!\n"
	@ .string "Chop, chop away on rocks! ~$"
	.string "Chop, chop away on rocks! ~$"

OreburghCitySouth_Text_Machop2:
	.string "MACHOP: Pigyooh!$"
	
OreburghCitySouth_Text_NoQuestion:
	.string "There’s no question. This is hard,\n"
	.string "hard work.\p"
	.string "But working alongside Pokémon...\n"
	.string "It gives me a boost somehow.\p"
	.string "Here, take one of these.$"

OreburghCitySouth_Text_HaleHearty:
	.string "Feeling hale and hearty puts a smile\n"
	.string "on my face. And that makes me happy.$"

OreburghCitySouth_Text_Machop3:
	.string "MACHOP: Macho! Chopo!$"
