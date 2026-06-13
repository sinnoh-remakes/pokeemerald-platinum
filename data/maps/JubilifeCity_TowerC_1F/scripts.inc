JubilifeCity_TowerC_1F_MapScripts::
	.byte 0

JubilifeCity_TowerC_1F_EventScript_Beauty::
	goto_if_set FLAG_JUBILIFE_CITY_QUICK_CLAW, JubilifeCity_TowerC_1F_EventScript_BeautyQuickClawGiven
	lock
	faceplayer
	msgbox JubilifeCity_TowerC_1F_Text_QuiteAdorable, MSGBOX_DEFAULT
	giveitem ITEM_QUICK_CLAW
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_JUBILIFE_CITY_QUICK_CLAW
	msgbox JubilifeCity_TowerC_1F_Text_HoldingThatQuickClaw, MSGBOX_DEFAULT
	closemessage
	release
	end

JubilifeCity_TowerC_1F_EventScript_BeautyQuickClawGiven::
	msgbox JubilifeCity_TowerC_1F_Text_HoldingThatQuickClaw, MSGBOX_NPC
	end

JubilifeCity_TowerC_1F_EventScript_Pachirisu::
	msgbox JubilifeCity_TowerC_1F_Text_Pachirisu, MSGBOX_NPC
	end

JubilifeCity_TowerC_1F_EventScript_Pikachu::
	msgbox JubilifeCity_TowerC_1F_Text_Pikachu, MSGBOX_NPC
	end

JubilifeCity_TowerC_1F_EventScript_Expert::
	msgbox JubilifeCity_TowerC_1F_Text_HelloDarlings, MSGBOX_NPC
	end

JubilifeCity_TowerC_1F_Text_QuiteAdorable:
	.string "Oh, your Pokémon is quite adorable!\p"
	.string "Here, try making it hold this\n"
	.string "Quick Claw.$"

JubilifeCity_TowerC_1F_Text_HoldingThatQuickClaw:
	.string "A Pokémon holding that Quick Claw can\n"
	.string "sometimes attack first, even if it is\l"
	.string "normally a little bit slow.\p"
	.string "There are other items that are only\n"
	.string "useful when given to a Pokémon.\p"
	.string "Try finding other items that you can\n"
	.string "make your Pokémon hold.\p"
	.string "...I sound like I’m a teacher or\n"
	.string "something.$"

JubilifeCity_TowerC_1F_Text_Pachirisu:
	.string "PACHIRISU: Pachipachii?$"

JubilifeCity_TowerC_1F_Text_Pikachu:
	.string "PIKACHU: Piika pi!$"

JubilifeCity_TowerC_1F_Text_HelloDarlings:
	.string "Oh, hello, darlings.\n"
	.string "Isn’t my Pokétch quite fetching?\p"
	.string "It’s the latest design that just came\n"
	.string "out. I obtained it instantly, of course.\p"
	.string "A Trainer would be simply lost without\n"
	.string "a Pokétch, after all.$"
