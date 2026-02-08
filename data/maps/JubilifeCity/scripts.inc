JubilifeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, JubilifeCity_OnTransition
	.byte 0

@ State descriptions For VAR_JUBILIFE_CITY_STATE
@ 1: Encounter Helper

JubilifeCity_OnTransition:
	setflag FLAG_VISITED_JUBILIFE_CITY
	call Common_EventScript_SetupRivalGfxId
	end

JubilifeCity_EventScript_HelperEncounter_1::
	lockall
	setobjectxy LOCALID_JUBILIFE_HELPER, 54, 54
	call JubilifeCity_EventScript_HelperWalkDown
	end

JubilifeCity_EventScript_HelperEncounter_2::
	lockall
	call JubilifeCity_EventScript_HelperWalkDown
	end


JubilifeCity_EventScript_HelperEncounter_3::
	lockall
	setobjectxy LOCALID_JUBILIFE_HELPER, 56, 64
	call JubilifeCity_EventScript_HelperWalkDown
	end

JubilifeCity_EventScript_HelperWalkDown::
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_WalkDown2
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_WalkDown3
	checkplayergender
	call_if_eq VAR_RESULT, MALE, JubilifeCity_EventScript_DawnCountParty
	call_if_eq VAR_RESULT, FEMALE, JubilifeCity_EventScript_LucasCountParty
	return

JubilifeCity_EventScript_DawnCountParty::
	msgbox JubilifeCity_Text_AreYouCatching, MSGBOX_DEFAULT
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	call_if_le VAR_RESULT, 3, JubilifeCity_EventScript_DawnFew
	call_if_eq VAR_RESULT, 4, JubilifeCity_EventScript_Dawn4
	call_if_eq VAR_RESULT, 5, JubilifeCity_EventScript_Dawn5
	call_if_eq VAR_RESULT, 6, JubilifeCity_EventScript_Dawn6
	msgbox JubilifeCity_Text_DawnKnowMore, MSGBOX_DEFAULT
	return

JubilifeCity_EventScript_LucasCountParty::
	msgbox JubilifeCity_Text_HowManyCaught, MSGBOX_DEFAULT
	specialvar VAR_RESULT, CalculatePlayerPartyCount
	call_if_le VAR_RESULT, 3, JubilifeCity_EventScript_LucasFew
	call_if_eq VAR_RESULT, 4, JubilifeCity_EventScript_Lucas4
	call_if_eq VAR_RESULT, 5, JubilifeCity_EventScript_Lucas5
	call_if_eq VAR_RESULT, 6, JubilifeCity_EventScript_Lucas6
	msgbox JubilifeCity_Text_LucasKnowMore, MSGBOX_DEFAULT
	return

JubilifeCity_EventScript_DawnFew::
	msgbox JubilifeCity_Text_FeelSafer, MSGBOX_DEFAULT
	return

JubilifeCity_EventScript_LucasFew::
	msgbox JubilifeCity_Text_CatchMore, MSGBOX_DEFAULT
	return

JubilifeCity_EventScript_Dawn4::
	msgbox JubilifeCity_Text_AlreadyGot4, MSGBOX_DEFAULT
	return

JubilifeCity_EventScript_Dawn5::
	msgbox JubilifeCity_Text_AlreadyGot5, MSGBOX_DEFAULT
	return

JubilifeCity_EventScript_Dawn6::
	msgbox JubilifeCity_Text_AlreadyGot6, MSGBOX_DEFAULT
	return

JubilifeCity_EventScript_Lucas4::
	msgbox JubilifeCity_Text_AlreadyHave4, MSGBOX_DEFAULT
	return

JubilifeCity_EventScript_Lucas5::
	msgbox JubilifeCity_Text_AlreadyHave5, MSGBOX_DEFAULT
	return

JubilifeCity_EventScript_Lucas6::
	msgbox JubilifeCity_Text_AlreadyHave6, MSGBOX_DEFAULT
	return

JubilifeCity_Text_AreYouCatching:
	.string "Dawn: Hi, {PLAYER}!\p"
	.string "Are you catching Pokemon?$"

JubilifeCity_Text_HowManyCaught:
	.string "Lucas: Hey, {PLAYER}!\p"
	.string "How many Pokemon have you caught?"
	
JubilifeCity_Text_FeelSafer:
	.string "...Um...\n"
	.string "I think you'd feel a lot safer if you\p"
	.string "were to catch some more.\n"
	.string "You know, like when you need to travel\p"
	.string "to faraway places.$"

JubilifeCity_Text_CatchMore:
	.string "Huh?\p"
	.string "I think you should catch some more.\n"
	.string "it might be more of a challenge\p"
	.string "raising a lot of Pokemon...\n"
	.string "But it's worth it. The more Pokemon\p"
	.string "you have, the happier you'll be.$"

JubilifeCity_Text_AlreadyGot4:
	.string "Wow! You've already got 4 Pokemon\p"
	.string "with you!\n"
	.string "At that pace, your Pokedex should\p"
	.string "be full in non time at all!$"

JubilifeCity_Text_AlreadyGot5:
	.string "Wow! You've already got 5 Pokemon\p"
	.string "with you!\n"
	.string "At that pace, your Pokedex should\p"
	.string "be full in non time at all!$"

JubilifeCity_Text_AlreadyGot6:
	.string "Wow! You've already got 6 Pokemon\p"
	.string "with you!\n"
	.string "At that pace, your Pokedex should\p"
	.string "be full in non time at all!$"

JubilifeCity_Text_AlreadyHave4:
	.string "Whoa! You already have 4 Pokemon\p"
	.string "with you!$"

JubilifeCity_Text_AlreadyHave5:
	.string "Whoa! You already have 5 Pokemon\p"
	.string "with you!$"

JubilifeCity_Text_AlreadyHave6:
	.string "Whoa! You already have 6 Pokemon\p"
	.string "with you!$"

JubilifeCity_Text_DawnKnowMore:
	.string "Oh, I know! Don't you think it's\p"
	.string "better to know more about Pokemon?\n"
	.string "Sure it is!\p"
	.string "I know just the place.\n"
	.string "Come on!\p"
	.string "Don't be shy. Follow me!$"

JubilifeCity_Text_LucasKnowMore:
	.string "Hey, that's right! Don't you think it's\p"
	.string "better to know more about Pokemon?\n"
	.string "Sure it is!\p"
	.string "There's this great place for that.\n"
	.string "Come on! It's all right.\p"
	.string "Follow me.$"
