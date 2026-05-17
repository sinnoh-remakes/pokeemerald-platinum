OreburghCity_PokemonCenter_1F_MapScripts::
	.byte 0

OreburghCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_OREBURGH_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

OreburghCity_PokemonCenter_1F_EventScript_AceTrainerF::
	msgbox OreburghCity_PokemonCenter_1F_Text_SwitchOn, MSGBOX_NPC
	end

OreburghCity_PokemonCenter_1F_EventScript_Psychic::
	lock
	msgbox OreburghCity_PokemonCenter_1F_Text_FavoriteKind, MSGBOX_DEFAULT
	goto OreburghCity_PokemonCenter_1F_EventScript_PsychicTrainerClass
	end

OreburghCity_PokemonCenter_1F_EventScript_PsychicTrainerClass:
	@ FODO: Store trainer class value for future detection
	msgbox OreburghCity_PokemonCenter_1F_Text_KindOfTrainer, MSGBOX_DEFAULT
	multichoice 20, 0, MULTI_OREBURGH_CITY_TRAINERS, FALSE
	switch VAR_RESULT
	case 0, OreburghCity_PokemonCenter_1F_EventScript_MultiChoiceSchoolKid
	closemessage
	release
	end

OreburghCity_PokemonCenter_1F_EventScript_PsychicDecline::
	msgbox OreburghCity_PokemonCenter_1F_Text_TalkToYouLater, MSGBOX_DEFAULT
	release
	end

OreburghCity_PokemonCenter_1F_EventScript_MultiChoiceSchoolKid::
	msgbox OreburghCity_PokemonCenter_1F_Text_YouWantToBeSchoolKid, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, OreburghCity_PokemonCenter_1F_EventScript_PsychicTrainerClass
	case YES, OreburghCity_PokemonCenter_1F_EventScript_SelectSchoolKid
	case MULTI_B_PRESSED, OreburghCity_PokemonCenter_1F_EventScript_PsychicDecline
	end

OreburghCity_PokemonCenter_1F_EventScript_SelectSchoolKid::
	msgbox OreburghCity_PokemonCenter_1F_Text_ISeeSchoolKid, MSGBOX_DEFAULT
	msgbox OreburghCity_PokemonCenter_1F_Text_OthersMayCome, MSGBOX_DEFAULT
	release
	end

OreburghCity_PokemonCenter_1F_EventScript_MultiChoiceBugCatcher::
	msgbox OreburghCity_PokemonCenter_1F_Text_YouWantToBeBugCatcher, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, OreburghCity_PokemonCenter_1F_EventScript_PsychicTrainerClass
	case YES, OreburghCity_PokemonCenter_1F_EventScript_SelectBugCatcher
	case MULTI_B_PRESSED, OreburghCity_PokemonCenter_1F_EventScript_PsychicDecline
	end

OreburghCity_PokemonCenter_1F_EventScript_SelectBugCatcher::
	msgbox OreburghCity_PokemonCenter_1F_Text_ISeeBugCatcher, MSGBOX_DEFAULT
	msgbox OreburghCity_PokemonCenter_1F_Text_OthersMayCome, MSGBOX_DEFAULT
	release
	end

OreburghCity_PokemonCenter_1F_EventScript_MultiChoiceAceTrainer::
	msgbox OreburghCity_PokemonCenter_1F_Text_YouWantToBeAceTrainer, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, OreburghCity_PokemonCenter_1F_EventScript_PsychicTrainerClass
	case YES, OreburghCity_PokemonCenter_1F_EventScript_SelectAceTrainer
	case MULTI_B_PRESSED, OreburghCity_PokemonCenter_1F_EventScript_PsychicDecline
	end

OreburghCity_PokemonCenter_1F_EventScript_SelectAceTrainer::
	msgbox OreburghCity_PokemonCenter_1F_Text_ISeeAceTrainer, MSGBOX_DEFAULT
	msgbox OreburghCity_PokemonCenter_1F_Text_OthersMayCome, MSGBOX_DEFAULT
	release
	end

OreburghCity_PokemonCenter_1F_EventScript_MultiChoiceRoughneck::
	msgbox OreburghCity_PokemonCenter_1F_Text_YouWantToBeRoughneck, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, OreburghCity_PokemonCenter_1F_EventScript_PsychicTrainerClass
	case YES, OreburghCity_PokemonCenter_1F_EventScript_SelectRoughneck
	case MULTI_B_PRESSED, OreburghCity_PokemonCenter_1F_EventScript_PsychicDecline
	end

OreburghCity_PokemonCenter_1F_EventScript_SelectRoughneck::
	msgbox OreburghCity_PokemonCenter_1F_Text_ISeeRoughneck, MSGBOX_DEFAULT
	msgbox OreburghCity_PokemonCenter_1F_Text_OthersMayCome, MSGBOX_DEFAULT
	release
	end

OreburghCity_PokemonCenter_1F_EventScript_NinjaBoy::
	msgbox OreburghCity_PokemonCenter_1F_Text_GotAPalPad, MSGBOX_NPC
	end

OreburghCity_PokemonCenter_1F_EventScript_Gentleman::
	msgbox OreburghCity_PokemonCenter_1F_Text_ThisTeamGalactic, MSGBOX_NPC
	end

OreburghCity_PokemonCenter_1F_EventScript_NDSKidA::
	msgbox OreburghCity_PokemonCenter_1F_Text_BattleAFriend, MSGBOX_NPC
	end

OreburghCity_PokemonCenter_1F_EventScript_NDSKidB::
	msgbox OreburghCity_PokemonCenter_1F_Text_HaveAVsRecorder, MSGBOX_NPC
	end

OreburghCity_PokemonCenter_1F_EventScript_Teala::
	msgbox OreburghCity_PokemonCenter_1F_Text_WorkingUnderground, MSGBOX_NPC
	end
	end

OreburghCity_PokemonCenter_1F_Text_SwitchOn:
	.string "Switch on the PC at any Pokémon\n"
	.string "Center.\p"
	.string "Connect to “Someone’s PC” and access\n"
	.string "the Pokémon Storage System.\p"
	.string "That’s all you need to do to store\n"
	.string "or bring out your Pokémon$."

OreburghCity_PokemonCenter_1F_Text_FavoriteKind:
	.string "Hmmm...!\p"
	.string "What is your favorite kind of Trainer?\n"
	.string "Can you tell me?$"

OreburghCity_PokemonCenter_1F_Text_KindOfTrainer:
	.string "Which kind of Trainer would you like\n"
	.string "to be?$"

OreburghCity_PokemonCenter_1F_Text_YouWantToBeSchoolKid:
	.string "A School Kid is the kind of Trainer\n"
	.string "you want to be?$"

OreburghCity_PokemonCenter_1F_Text_YouWantToBeBugCatcher:
	.string "A Bug Catcher is the kind of Trainer\n"
	.string "you want to be?$"

OreburghCity_PokemonCenter_1F_Text_YouWantToBeAceTrainer:
	.string "An Ace Trainer is the kind of Trainer\n"
	.string "you want to be?$"

OreburghCity_PokemonCenter_1F_Text_YouWantToBeRoughneck:
	.string "A Roughneck is the kind of Trainer\n"
	.string "you want to be?$"

OreburghCity_PokemonCenter_1F_Text_ISeeSchoolKid:
	.string "I see! So a School Kid is the kind\n"
	.string "of Trainer you like.$"

OreburghCity_PokemonCenter_1F_Text_ISeeBugCatcher:
	.string "I see! So a Bug Catcher is the kind\n"
	.string "of Trainer you like.$"

OreburghCity_PokemonCenter_1F_Text_ISeeAceTrainer:
	.string "I see! So an Ace Trainer is the kind\n"
	.string "of Trainer you like.$"

OreburghCity_PokemonCenter_1F_Text_ISeeRoughneck:
	.string "I see! So a Roughneck is the kind\n"
	.string "of Trainer you like.$"
	
OreburghCity_PokemonCenter_1F_Text_OthersMayCome:
	.string "If that’s the case, others may come\n"
	.string "to see you in the same way.\r"
	.string "OK, then I’ll just talk to you later!$"
	
OreburghCity_PokemonCenter_1F_Text_TalkToYouLater:
	.string "OK, then I’ll just talk to you later!$"

	@ .string "Hello! You’ve been mistaken for\n"
	@ .string "{STRVAR_1, 14, 0, 0}, haven’t you?\p"
	@ .string "But I think you can also pass for\n"
	@ .string "a different kind of Trainer.\r"
	@ .string "So, how about telling me what kind of\n"
	@ .string "Trainer that you like?\p"

OreburghCity_PokemonCenter_1F_Text_GotAPalPad:
	.string "Yay! I got a Pal Pad at the\n"
	.string "Pokémon Wi-Fi Club downstairs!$"

OreburghCity_PokemonCenter_1F_Text_ThisTeamGalactic:
	.string "Hmmm!\n"
	.string "What, or who, is this Team Galactic?!\p"
	.string "They make wonderful claims of a dream\n"
	.string "energy source on one hand...\p"
	.string "But rumor has it, they steal Pokémon\n"
	.string "from others by force.\p"
	.string "It’s a mystery! They’re mysterious!\n"
	.string "Isn’t anyone investigating them?$"

OreburghCity_PokemonCenter_1F_Text_BattleAFriend:
	.string "You know how you can battle a friend\n"
	.string "using wireless communications?\p"
	.string "Well now, you can capture it as a Battle\n"
	.string "Video using a Vs. Recorder!$"

OreburghCity_PokemonCenter_1F_Text_HaveAVsRecorder:
	.string "Cool!\n"
	.string "You have a Vs. Recorder!\p"
	.string "So, did you go to the Global Terminal in\n"
	.string "Jubilife City? Did ya? Did ya?$"

OreburghCity_PokemonCenter_1F_Text_WorkingUnderground::
	.string "I'm very sorry.\p"
	.string "We are working underground right now.\n"
	.string "It's off-limits to the public.\p"
	.string "Please try later on.$"
