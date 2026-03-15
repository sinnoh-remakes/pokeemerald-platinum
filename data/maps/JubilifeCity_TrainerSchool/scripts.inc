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
	clearflag FLAG_HIDE_JUBILIFE_POKETCH
	setvar VAR_JUBILIFE_CITY_STATE, 2
	release
	end

JubilifeCity_TrainerSchool_EventScript_BarryLeaveAlternate::
	applymovement LOCALID_TRAINER_SCHOOL_BARRY, JubilifeCity_TrainerSchool_Movement_BarryLeaveAlternate
	waitmovement 0
	removeobject LOCALID_TRAINER_SCHOOL_BARRY
	setflag FLAG_HIDE_TRAINER_SCHOOL_RIVAL
	clearflag FLAG_HIDE_JUBILIFE_POKETCH
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
	lock
	faceplayer
	goto_if_set FLAG_TRAINER_SCHOOL_RECEIVED_POTION, JubilifeCity_TrainerSchool_EventScript_HarrisonDefeated
	goto_if_defeated TRAINER_PT_HARRISON, JubilifeCity_TrainerSchool_EventScript_HarrisonCheckChristine
	msgbox JubilifeCity_TrainerSchool_Text_DoingIt, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, JubilifeCity_TrainerSchool_EventScript_HarrisonDecline
	msgbox JubilifeCity_TrainerSchool_Text_HarrisonIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PT_HARRISON, JubilifeCity_TrainerSchool_Text_HarrisonDefeated
	goto_if_defeated TRAINER_PT_CHRISTINE, JubilifeCity_TrainerSchool_EventScript_HarrisonGivePotion
	goto JubilifeCity_TrainerSchool_EventScript_HarrisonDefeated
	end

JubilifeCity_TrainerSchool_EventScript_HarrisonCheckChristine::
	goto_if_defeated TRAINER_PT_CHRISTINE, JubilifeCity_TrainerSchool_EventScript_HarrisonGivePotion
	goto JubilifeCity_TrainerSchool_EventScript_HarrisonDefeated
	end

JubilifeCity_TrainerSchool_EventScript_HarrisonGivePotion::
	msgbox JubilifeCity_TrainerSchool_Text_HarrisonEventText, MSGBOX_DEFAULT
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox JubilifeCity_TrainerSchool_Text_PotionIsUsed, MSGBOX_AUTOCLOSE
	setflag FLAG_TRAINER_SCHOOL_RECEIVED_POTION
	release
	end

JubilifeCity_TrainerSchool_EventScript_HarrisonDefeated::
	msgbox JubilifeCity_TrainerSchool_Text_HarrisonPostBattle, MSGBOX_AUTOCLOSE
	release
	end

JubilifeCity_TrainerSchool_EventScript_HarrisonDecline::
	msgbox JubilifeCity_TrainerSchool_Text_AwwButBattling, MSGBOX_AUTOCLOSE
	release
	end

JubilifeCity_TrainerSchool_EventScript_Christine::
	lock
	faceplayer
	goto_if_set FLAG_TRAINER_SCHOOL_RECEIVED_POTION, JubilifeCity_TrainerSchool_EventScript_ChristineDefeated
	goto_if_defeated TRAINER_PT_CHRISTINE, JubilifeCity_TrainerSchool_EventScript_ChristineDefeated
	msgbox JubilifeCity_TrainerSchool_Text_JustBecameFriends, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, JubilifeCity_TrainerSchool_EventScript_ChristineDecline
	msgbox JubilifeCity_TrainerSchool_Text_ChristineIntro, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_PT_CHRISTINE, JubilifeCity_TrainerSchool_Text_ChristineDefeated
	msgbox JubilifeCity_TrainerSchool_Text_ChristineEventText, MSGBOX_AUTOCLOSE
	release
	end

JubilifeCity_TrainerSchool_EventScript_ChristineDefeated::
	msgbox JubilifeCity_TrainerSchool_Text_ChristinePostBattle, MSGBOX_AUTOCLOSE
	release
	end

JubilifeCity_TrainerSchool_EventScript_ChristineDecline::
	msgbox JubilifeCity_TrainerSchool_Text_SenseOfAdventure, MSGBOX_AUTOCLOSE
	release
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

JubilifeCity_TrainerSchool_EventScript_PictureBooks::
	msgbox JubilifeCity_TrainerSchool_Text_PictureBooks, MSGBOX_SIGN
	end

JubilifeCity_TrainerSchool_EventScript_PokemonBooks::
	msgbox JubilifeCity_TrainerSchool_Text_PokemonBooks, MSGBOX_SIGN
	end

JubilifeCity_TrainerSchool_EventScript_Blackboard::
	lock
	msgbox JubilifeCity_TrainerSchool_Text_ListStatusChanges, MSGBOX_DEFAULT
	goto JubilifeCity_TrainerSchool_EventScript_BlackboardList
	end

JubilifeCity_TrainerSchool_EventScript_BlackboardList:
	msgbox JubilifeCity_TrainerSchool_Text_ReadAbout, MSGBOX_DEFAULT
	multichoice 20, 0, MULTI_TRAINER_SCHOOL_BLACKBOARD, FALSE
	switch VAR_RESULT
	case 0, JubilifeCity_TrainerSchool_EventScript_BlackboardPoison
	case 1, JubilifeCity_TrainerSchool_EventScript_BlackboardParalyze
	case 2, JubilifeCity_TrainerSchool_EventScript_BlackboardSleep
	case 3, JubilifeCity_TrainerSchool_EventScript_BlackboardBurn
	case 4, JubilifeCity_TrainerSchool_EventScript_BlackboardFrozen
	closemessage
	release
	end

JubilifeCity_TrainerSchool_EventScript_BlackboardPoison::
	msgbox JubilifeCity_TrainerSchool_Text_BlackboardPoison
	goto JubilifeCity_TrainerSchool_EventScript_BlackboardList
	end

JubilifeCity_TrainerSchool_EventScript_BlackboardParalyze::
	msgbox JubilifeCity_TrainerSchool_Text_BlackboardParalyze
	goto JubilifeCity_TrainerSchool_EventScript_BlackboardList
	end

JubilifeCity_TrainerSchool_EventScript_BlackboardSleep::
	msgbox JubilifeCity_TrainerSchool_Text_BlackboardSleep
	goto JubilifeCity_TrainerSchool_EventScript_BlackboardList
	end

JubilifeCity_TrainerSchool_EventScript_BlackboardBurn::
	msgbox JubilifeCity_TrainerSchool_Text_BlackboardBurn
	goto JubilifeCity_TrainerSchool_EventScript_BlackboardList
	end

JubilifeCity_TrainerSchool_EventScript_BlackboardFrozen::
	msgbox JubilifeCity_TrainerSchool_Text_BlackboardFrozen
	goto JubilifeCity_TrainerSchool_EventScript_BlackboardList
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

JubilifeCity_TrainerSchool_Text_PictureBooks:
	.string "It's lined with Pokémon picture books.$"

JubilifeCity_TrainerSchool_Text_PokemonBooks:
	.string "It's chock-full of Pokémon books and\n"
	.string "photo collections.$"

JubilifeCity_TrainerSchool_Text_ListStatusChanges:
	.string "The blackboard lists status changes\n"
	.string "that may affect Pokémon in battle.$"
	.string "Which would you like to read about?$"

JubilifeCity_TrainerSchool_Text_ReadAbout:
	.string "Which would you like to read about?$"

JubilifeCity_TrainerSchool_Text_BlackboardPoison:
	.string "If a Pokémon is poisoned, it will\n"
	.string "steadily lose HP.\p"
	.string "The effects of poison remain after\n"
	.string "a battle.\p"
	.string "A poisoned Pokémon’s HP will drop\n"
	.string "while it is traveling.\p"
	.string "Heal a poisoning using an Antidote.$"

JubilifeCity_TrainerSchool_Text_BlackboardParalyze:
	.string "If a Pokémon becomes paralyzed,\n"
	.string "its Speed stat drops.\p"
	.string "In addition, it may not be able to\n"
	.string "move while it is in battle.\p"
	.string "Paralysis remains after battle.\n"
	.string "Cure it using a Parlyz Heal.$"

JubilifeCity_TrainerSchool_Text_BlackboardSleep:
	.string "If a Pokémon falls asleep, it will be\n"
	.string "unable to attack.\p"
	.string "The Pokémon may wake up on its own,\n"
	.string "but if a battle ends while it is\l"
	.string "sleeping, it will stay asleep.\p"
	.string "Wake it up using an Awakening.$"

JubilifeCity_TrainerSchool_Text_BlackboardBurn:
	.string "A burn reduces the Attack stat and\n"
	.string "steadily reduces the victim’s HP.\p"
	.string "A burn lingers after battle.\n"
	.string "Cure a burn using a Burn Heal.$"

JubilifeCity_TrainerSchool_Text_BlackboardFrozen:
	.string "If a Pokémon is frozen, it becomes\n"
	.string "completely helpless.\p"
	.string "The Pokémon may thaw out on its own,\n"
	.string "but if a battle ends while it is\l"
	.string "frozen, it will stay frozen."
	.string "Thaw it out using an Ice Heal.$"
