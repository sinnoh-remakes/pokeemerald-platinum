JubilifeCity_TrainerSchool_MapScripts::
	.byte 0

JubilifeCity_TrainerSchool_EventScript_Barry::
	lock
	faceplayer
	msgbox JubilifeCity_TrainerSchool_Text_ComeToStudy, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message JubilifeCity_TrainerSchool_Text_DeliveredTheParcel
	waitmessage
	waitfanfare
	msgbox JubilifeCity_TrainerSchool_Text_WhatIsThis, MSGBOX_DEFAULT
	giveitem ITEM_TOWN_MAP
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox JubilifeCity_TrainerSchool_Text_AccordingToTownMap, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, JubilifeCity_TrainerSchool_EventScript_BarryLeaveAlternate
	applymovement LOCALID_TRAINER_SCHOOL_BARRY, JubilifeCity_TrainerSchool_Movement_BarryLeave
	waitmovement 0
	removeobject LOCALID_TRAINER_SCHOOL_BARRY
	setflag FLAG_HIDE_TRAINER_SCHOOL_RIVAL
	setvar VAR_JUBILIFE_CITY_STATE, 2
	release
	end

JubilifeCity_TrainerSchool_EventScript_BarryLeaveAlternate::
	applymovement LOCALID_TRAINER_SCHOOL_BARRY, JubilifeCity_TrainerSchool_Movement_BarryLeaveAlternate
	waitmovement 0
	removeobject LOCALID_TRAINER_SCHOOL_BARRY
	setflag FLAG_HIDE_TRAINER_SCHOOL_RIVAL
	setvar VAR_JUBILIFE_CITY_STATE, 2
	release
	end

JubilifeCity_TrainerSchool_Movement_BarryLeave:
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

JubilifeCity_TrainerSchool_Movement_BarryLeaveAlternate:
	walk_fast_right
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

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

JubilifeCity_TrainerSchool_EventScript_AceTrainerF::
	msgbox JubilifeCity_TrainerSchool_Text_PerfectlyFine, MSGBOX_NPC
	end

JubilifeCity_TrainerSchool_EventScript_Lass::
	msgbox JubilifeCity_TrainerSchool_Text_SmartEnough, MSGBOX_NPC
	end

JubilifeCity_TrainerSchool_EventScript_Youngster1::
	msgbox JubilifeCity_TrainerSchool_Text_WroteAnEssay, MSGBOX_NPC
	end

JubilifeCity_TrainerSchool_EventScript_Youngster2::
	msgbox JubilifeCity_TrainerSchool_Text_LearnedAboutTypes, MSGBOX_NPC
	end

JubilifeCity_TrainerSchool_EventScript_Notebook::
	msgbox JubilifeCity_TrainerSchool_Text_NotebookWithWriting, MSGBOX_SIGN
	end

JubilifeCity_TrainerSchool_Text_ComeToStudy:
	.string "{RIVAL}: Hey, {PLAYER}!\n"
	.string "Did you come to study, too?\p"
	.string "I went ahead and memorized everything\n"
	.string "that was up on the blackboard.\p"
	.string "After all, it’s the Trainer’s job to\n"
	.string "avoid having their precious Pokémon\l"
	.string "hurt in battle, right?\p"
	.string "So, {PLAYER}, what brings you?\n"
	.string "Huh?\l"
	.string "You’ve got something for me?$"

JubilifeCity_TrainerSchool_Text_DeliveredTheParcel:
	.string "{PLAYER} delivered the Parcel.$"

JubilifeCity_TrainerSchool_Text_WhatIsThis:
	.string "{RIVAL}: So, what is this...?\p"
	.string "Score!\n"
	.string "It’s a Town Map!\p"
	.string "Huh?!\n"
	.string "Why are there two in here?\p"
	.string "I like it a lot, but I don’t need two.\n"
	.string "Here, {PLAYER}, you take one!$"

JubilifeCity_TrainerSchool_Text_AccordingToTownMap:
	.string "{RIVAL}: Hmm...\p"
	.string "Well, according to the Town Map,\n"
	.string "I guess Oreburgh City is where\l"
	.string "I should be going next.\p"
	.string "There’s a Gym, so it’d be perfect for\n"
	.string "raising the Pokémon I just caught.\p"
	.string "Well, I’m on the road to becoming\n"
	.string "the greatest Trainer of all time!\p"
	.string "See you around!$"

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

JubilifeCity_TrainerSchool_Text_PerfectlyFine:
	.string "It’s perfectly fine for Trainers and\n"
	.string "Pokémon to develop at their own pace.\p"
	.string "If there is anything you’re not familiar\n"
	.string "with, you can look it up here.$"

JubilifeCity_TrainerSchool_Text_SmartEnough:
	.string "Pokémon are smart enough to use\n"
	.string "items they’re holding.\p"
	.string "But they won’t know what to do with\n"
	.string "man-made items like Potions and\l"
	.string "Antidotes.$"

JubilifeCity_TrainerSchool_Text_WroteAnEssay:
	.string "I wrote an essay in my notebook on \n"
	.string "what makes a true Pokémon Trainer.$"

JubilifeCity_TrainerSchool_Text_LearnedAboutTypes:
	.string "We learned about Pokémon types\n"
	.string "today. Umm...\p"
	.string "Grass is weak to Fire,\p"
	.string "Fire is weak to Water,\p"
	.string "and Water is weak to Grass!$"

JubilifeCity_TrainerSchool_Text_NotebookWithWriting:
	.string "It’s a notebook filled with writing.\n"
	.string "Let’s see...\p"
	.string "Pokémon are to be caught using\n"
	.string "Poké Balls.\p"
	.string "Up to six Pokémon can accompany\n"
	.string "a Trainer.\p"
	.string "A Trainer is someone who catches\n"
	.string "Pokémon, raises them, and battles\l"
	.string "with them.\p"
	.string "A Trainer’s mission is to defeat the\n"
	.string "strong Trainers who await challengers\l"
	.string "in Pokémon Gyms.$"
