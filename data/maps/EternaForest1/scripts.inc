EternaForest1_MapScripts::
	.byte 0

EternaForest1_EventScript_Jack::
	trainerbattle_single TRAINER_PT_JACK, EternaForest1_Text_JackIntro, EternaForest1_Text_JackDefeated
	msgbox EternaForest1_Text_JackPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest1_EventScript_Briana::
	trainerbattle_single TRAINER_PT_BRIANA, EternaForest1_Text_BrianaIntro, EternaForest1_Text_BrianaDefeated
	msgbox EternaForest1_Text_BrianaPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest1_EventScript_Lindsey::
	trainerbattle_single TRAINER_PT_LINDSEY, EternaForest1_Text_LindseyIntro, EternaForest1_Text_LindseyDefeated
	msgbox EternaForest1_Text_LindseyPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest1_EventScript_Elijah::
	trainerbattle_single TRAINER_PT_ELIJAH, EternaForest1_Text_ElijahIntro, EternaForest1_Text_ElijahDefeated
	msgbox EternaForest1_Text_ElijahPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest1_EventScript_Phillip::
	trainerbattle_single TRAINER_PT_PHILLIP, EternaForest1_Text_PhillipIntro, EternaForest1_Text_PhillipDefeated
	msgbox EternaForest1_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest1_EventScript_Donald::
	trainerbattle_single TRAINER_PT_DONALD, EternaForest1_Text_DonaldIntro, EternaForest1_Text_DonaldDefeated
	msgbox EternaForest1_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest1_EventScript_Kody::
	trainerbattle_single TRAINER_PT_KODY, EternaForest1_Text_KodyIntro, EternaForest1_Text_KodyDefeated
	msgbox EternaForest1_Text_KodyPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest1_EventScript_Rachael::
	trainerbattle_single TRAINER_PT_RACHAEL, EternaForest1_Text_RachaelIntro, EternaForest1_Text_RachaelDefeated
	msgbox EternaForest1_Text_RachaelPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest1_EventScript_BugCatcher::
	msgbox EternaForest1_Text_BugPokemon, MSGBOX_NPC
	end

EternaForest1_EventScript_MossyRock::
	msgbox EternaForest1_Text_MossyRock, MSGBOX_SIGN
	end

EternaForest1_EventScript_RouteSign::
	msgbox EternaForest1_Text_RouteSign, MSGBOX_SIGN
	end

EternaForest1_EventScript_TrainerTips::
	msgbox EternaForest1_Text_TrainerTips, MSGBOX_SIGN
	end

EternaForest1_Text_BugPokemon:
	.string "I’m searching for bug Pokémon so I can\n"
	.string "win at the Eterna Gym.\p"
	.string "Bug Pokémon are great, you know?\n"
	.string "They grow really fast!$"

EternaForest1_Text_MossyRock::
	.string "The rock is covered in moss.\n"
	.string "It feels pleasantly cool.$"

EternaForest1_Text_RouteSign:
	.string "The Eterna Forest\n"
	.string "Where Time Flows Eternally$"

EternaForest1_Text_TrainerTips:
	.string "Trainer Tips!\p"
	.string "In forests and caves, there are many\n"
	.string "items on the ground that cannot be\l"
	.string "seen in the murky darkness.\p"
	.string "Take the time to search carefully!$"
