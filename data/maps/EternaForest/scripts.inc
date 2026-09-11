EternaForest_MapScripts::
	.byte 0

EternaForest_EventScript_Jack::
	trainerbattle_single TRAINER_PT_JACK, EternaForest_Text_JackIntro, EternaForest_Text_JackDefeated
	msgbox EternaForest_Text_JackPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest_EventScript_Briana::
	trainerbattle_single TRAINER_PT_BRIANA, EternaForest_Text_BrianaIntro, EternaForest_Text_BrianaDefeated
	msgbox EternaForest_Text_BrianaPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest_EventScript_Lindsey::
	trainerbattle_single TRAINER_PT_LINDSEY, EternaForest_Text_LindseyIntro, EternaForest_Text_LindseyDefeated
	msgbox EternaForest_Text_LindseyPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest_EventScript_Elijah::
	trainerbattle_single TRAINER_PT_ELIJAH, EternaForest_Text_ElijahIntro, EternaForest_Text_ElijahDefeated
	msgbox EternaForest_Text_ElijahPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest_EventScript_Phillip::
	trainerbattle_single TRAINER_PT_PHILLIP, EternaForest_Text_PhillipIntro, EternaForest_Text_PhillipDefeated
	msgbox EternaForest_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest_EventScript_Donald::
	trainerbattle_single TRAINER_PT_DONALD, EternaForest_Text_DonaldIntro, EternaForest_Text_DonaldDefeated
	msgbox EternaForest_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest_EventScript_Kody::
	trainerbattle_single TRAINER_PT_KODY, EternaForest_Text_KodyIntro, EternaForest_Text_KodyDefeated
	msgbox EternaForest_Text_KodyPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest_EventScript_Rachael::
	trainerbattle_single TRAINER_PT_RACHAEL, EternaForest_Text_RachaelIntro, EternaForest_Text_RachaelDefeated
	msgbox EternaForest_Text_RachaelPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest_EventScript_BugCatcher::
	msgbox EternaForest_Text_BugPokemon, MSGBOX_NPC
	end

EternaForest_EventScript_MossyRock::
	msgbox EternaForest_Text_MossyRock, MSGBOX_SIGN
	end

EternaForest_EventScript_RouteSign::
	msgbox EternaForest_Text_RouteSign, MSGBOX_SIGN
	end

EternaForest_EventScript_TrainerTips::
	msgbox EternaForest_Text_TrainerTips, MSGBOX_SIGN
	end

EternaForest_Text_BugPokemon:
	.string "I’m searching for bug Pokémon so I can\n"
	.string "win at the Eterna Gym.\p"
	.string "Bug Pokémon are great, you know?\n"
	.string "They grow really fast!$"

EternaForest_Text_MossyRock::
	.string "The rock is covered in moss.\n"
	.string "It feels pleasantly cool.$"

EternaForest_Text_RouteSign:
	.string "The Eterna Forest\n"
	.string "Where Time Flows Eternally$"

EternaForest_Text_TrainerTips:
	.string "Trainer Tips!\p"
	.string "In forests and caves, there are many\n"
	.string "items on the ground that cannot be\l"
	.string "seen in the murky darkness.\p"
	.string "Take the time to search carefully!$"
