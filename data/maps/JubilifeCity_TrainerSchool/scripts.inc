JubilifeCity_TrainerSchool_MapScripts::
	.byte 0

JubilifeCity_TrainerSchool_EventScript_Harrison::
	goto_if_set FLAG_TRAINER_SCHOOL_RECEIVED_POTION, JubilifeCity_TrainerSchool_EventScript_HarrisonDefeated
	goto_if_set FLAG_DEFEATED_HARRISON_TRAINER_SCHOOL, JubilifeCity_TrainerSchool_EventScript_HarrisonCheckChristine
	msgbox JubilifeCity_TrainerSchool_Text_DoingIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, JubilifeCity_TrainerSchool_EventScript_HarrisonDecline
	trainerbattle_single TRAINER_HARRISON_PT, JubilifeCity_TrainerSchool_Text_HarrisonIntro, JubilifeCity_TrainerSchool_Text_HarrisonDefeated
	setflag FLAG_DEFEATED_HARRISON_TRAINER_SCHOOL
	goto JubilifeCity_TrainerSchool_EventScript_HarrisonGivePotion
	end

JubilifeCity_TrainerSchool_EventScript_HarrisonCheckChristine::
	goto_if_set FLAG_DEFEATED_CHRISTINE_TRAINER_SCHOOL, JubilifeCity_TrainerSchool_EventScript_HarrisonGivePotion
	goto JubilifeCity_TrainerSchool_EventScript_HarrisonDefeated
	end

JubilifeCity_TrainerSchool_EventScript_HarrisonGivePotion::
	msgbox JubilifeCity_TrainerSchool_Text_HarrisonEventText, MSGBOX_DEFAULT
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox JubilifeCity_TrainerSchool_Text_PotionIsUsed, MSGBOX_AUTOCLOSE
	setflag FLAG_TRAINER_SCHOOL_RECEIVED_POTION
	end

JubilifeCity_TrainerSchool_EventScript_HarrisonDefeated::
	msgbox JubilifeCity_TrainerSchool_Text_HarrisonPostBattle, MSGBOX_AUTOCLOSE
	end

JubilifeCity_TrainerSchool_EventScript_HarrisonDecline::
	msgbox JubilifeCity_TrainerSchool_Text_AwwButBattling, MSGBOX_AUTOCLOSE
	end

JubilifeCity_TrainerSchool_EventScript_Christine::
	goto_if_set FLAG_TRAINER_SCHOOL_RECEIVED_POTION, JubilifeCity_TrainerSchool_EventScript_ChristineDefeated
	goto_if_set FLAG_DEFEATED_CHRISTINE_TRAINER_SCHOOL, JubilifeCity_TrainerSchool_EventScript_ChristineDefeated
	msgbox JubilifeCity_TrainerSchool_Text_JustBecameFriends, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, JubilifeCity_TrainerSchool_EventScript_ChristineDecline
	trainerbattle_single TRAINER_CHRISTINE, JubilifeCity_TrainerSchool_Text_ChristineIntro, JubilifeCity_TrainerSchool_Text_ChristineDefeated
	setflag FLAG_DEFEATED_CHRISTINE_TRAINER_SCHOOL
	msgbox JubilifeCity_TrainerSchool_Text_ChristineEventText, MSGBOX_AUTOCLOSE
	end

JubilifeCity_TrainerSchool_EventScript_ChristineDefeated::
	msgbox JubilifeCity_TrainerSchool_Text_ChristinePostBattle, MSGBOX_AUTOCLOSE
	end

JubilifeCity_TrainerSchool_EventScript_ChristineDecline::
	msgbox JubilifeCity_TrainerSchool_Text_SenseOfAdventure, MSGBOX_AUTOCLOSE
	end

JubilifeCity_TrainerSchool_Text_DoingIt:
	.string "Doing it is the best way to learn!\n"
	.string "Can we get a battle with you?$"

JubilifeCity_TrainerSchool_Text_AwwButBattling:
	.string "Aww! But battling is the best way\n"
	.string "to learn about Pokémon!$"

JubilifeCity_TrainerSchool_Text_PotionIsUsed:
	.string "When a Potion is used, it restores the\n"
	.string "HP, the health, of a Pokémon.\p"
	.string "Being a good Trainer isn’t only about\n"
	.string "ordering your Pokémon around.\p"
	.string "A superior Trainer knows how to use\n"
	.string "items to the full advantage!$"

JubilifeCity_TrainerSchool_Text_JustBecameFriends:
	.string "I just became friends with my\n"
	.string "Pokémon.\p"
	.string "I’m not sure if we can do this\n"
	.string "properly, but may we battle?$"

JubilifeCity_TrainerSchool_Text_SenseOfAdventure:
	.string "Boo!\n"
	.string "Where’s your sense of adventure?\p"
	.string "Don’t be shy about talking to people\n"
	.string "and getting into battles!$"
