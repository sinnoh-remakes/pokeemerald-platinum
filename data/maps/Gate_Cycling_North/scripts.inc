Gate_Cycling_North_MapScripts::
	.byte 0

Gate_Cycling_North_EventScript_BlockWalking::
	lockall
	specialvar VAR_RESULT, GetPlayerAvatarBike
	goto_if_eq VAR_RESULT, 0, Gate_Cycling_North_EventScript_NoBike
	releaseall
	end

Gate_Cycling_North_EventScript_NoBike::
	playse SE_PIN
	applymovement LOCALID_CYCLING_CLERK_NORTH, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	msgbox Gate_Cycling_North_Text_GetOnBicycle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	releaseall
	end

Gate_Cycling_North_EventScript_Scientist::
	lock
	faceplayer
	goto_if_set FLAG_RECEIVED_EXP_SHARE, Gate_Cycling_North_EventScript_ExplainExpShare
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Gate_Cycling_North_EventScript_LongTime_Dawn
	call_if_eq VAR_RESULT, FEMALE, Gate_Cycling_North_EventScript_LongTime_Lucas
	setvar VAR_0x8004, 1
	@ FODO: Does this handle proper dex seen count?
	special ScriptGetPokedexInfo
	buffernumberstring STR_VAR_1, VAR_0x8005
	goto_if_lt VAR_0x8005, 35, Gate_Cycling_North_EventScript_NotEnoughSeen
	msgbox Gate_Cycling_North_Text_SomethingForYou, MSGBOX_DEFAULT
	giveitem ITEM_EXP_SHARE
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_EXP_SHARE
	goto Gate_Cycling_North_EventScript_ExplainExpShare
	end

Gate_Cycling_North_EventScript_LongTime_Dawn::
	msgbox Gate_Cycling_North_Text_LongTime_Dawn, MSGBOX_DEFAULT
	return

Gate_Cycling_North_EventScript_LongTime_Lucas::
	msgbox Gate_Cycling_North_Text_LongTime_Lucas, MSGBOX_DEFAULT
	return

Gate_Cycling_North_EventScript_ExplainExpShare::
	msgbox Gate_Cycling_North_Text_HoldingExp, MSGBOX_DEFAULT
	release
	end

Gate_Cycling_North_EventScript_NotEnoughSeen::
	msgbox Gate_Cycling_North_Text_FindAtLeast, MSGBOX_DEFAULT
	release
	end

Gate_Cycling_North_EventScript_ShiftGears::
	msgbox Gate_Cycling_North_Text_ShiftGears, MSGBOX_NPC
	end

Gate_Cycling_North_Text_GetOnBicycle:
	.string "Cycling Road is only for Bicycles!\p"
	.string "Please get on your Bicycle!$"

Gate_Cycling_North_Text_ShiftGears:
	.string "Learn how to shift gears, and you’ll\n"
	.string "be able to ride anywhere.$"

Gate_Cycling_North_Text_LongTime_Dawn:
	.string "{PLAYER}, long time, no see!\p"
	.string "Oh? You look puzzled.\n"
	.string "You’re wondering who I am.\p"
	.string "I’m Professor Rowan’s assistant and\n"
	.string "Dawn’s father.\p"
	.string "I’ve come a long way to help you on\n"
	.string "your adventure at the professor’s\l"
	.string "behest.\p"
	.string "{PLAYER}, let me ask you,\n"
	.string "how many Pokémon have you met?$"

Gate_Cycling_North_Text_LongTime_Lucas:
	.string "{PLAYER}, long time, no see!\p"
	.string "Oh? You look puzzled.\n"
	.string "You’re wondering who I am.\p"
	.string "I’m Professor Rowan’s assistant and\n"
	.string "Lucas’s father.\p"
	.string "I’ve come a long way to help you on\n"
	.string "your adventure at the professor’s\l"
	.string "behest.\p"
	.string "{PLAYER}, let me ask you,\n"
	.string "how many Pokémon have you met?$"

Gate_Cycling_North_Text_SomethingForYou:
	.string "Oh, my!\n"
	.string "You’ve met {STR_VAR_1} Pokémon!\p"
	.string "Wonderful! Yes, bravo!\n"
	.string "Professor Rowan should be delighted!\p"
	.string "Here is something for you!$"

Gate_Cycling_North_Text_HoldingExp:
	.string "A Pokémon holding an Exp. Share will get\n"
	.string "some of the Exp. Points from battle.\p"
	.string "It will get Exp. Points even if it didn’t\n"
	.string "actually battle.\p"
	.string "Therefore, it should be held by a\n"
	.string "Pokémon you want to raise quickly.\p"
	.string "Also, a Pokémon you get in a trade may\n"
	.string "disobey you if it is too high in level.\p"
	.string "Don’t worry, though. It will obey if\n"
	.string "you have enough Gym Badges.$"

Gate_Cycling_North_Text_FindAtLeast:
	.string "You’ve met only {STR_VAR_1} Pokémon?\p"
	.string "Hmm...\n"
	.string "You’ve got to find at least 35.\p"
	.string "If you can’t, it will be tough to\n"
	.string "complete the Sinnoh Pokédex.$"

