JubilifeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, JubilifeCity_OnTransition
	.byte 0

@ State descriptions For VAR_JUBILIFE_CITY_STATE
@ 1: Encountered helper

JubilifeCity_OnTransition:
	setflag FLAG_VISITED_JUBILIFE_CITY
	call Common_EventScript_SetupRivalGfxId
	end

JubilifeCity_EventScript_HelperEncounter_1::
	lockall
	special SpawnCameraObject
	setvar VAR_JUBILIFE_CITY_STATE, 1
	setobjectxy LOCALID_JUBILIFE_HELPER, 54, 54
	call JubilifeCity_EventScript_HelperWalkDown
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_WalkRight
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_WalkUp
	applymovement LOCALID_CAMERA, Common_Movement_WalkRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	goto JubilifeCity_EventScript_HelperWalkUp
	end

JubilifeCity_EventScript_HelperEncounter_2::
	lockall
	special SpawnCameraObject
	setvar VAR_JUBILIFE_CITY_STATE, 1
	call JubilifeCity_EventScript_HelperWalkDown
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_WalkUp
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	goto JubilifeCity_EventScript_HelperWalkUp
	end

JubilifeCity_EventScript_HelperEncounter_3::
	lockall
	special SpawnCameraObject
	setvar VAR_JUBILIFE_CITY_STATE, 1
	setobjectxy LOCALID_JUBILIFE_HELPER, 56, 54
	call JubilifeCity_EventScript_HelperWalkDown
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_WalkLeft
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_WalkUp
	applymovement LOCALID_CAMERA, Common_Movement_WalkLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	goto JubilifeCity_EventScript_HelperWalkUp
	end

JubilifeCity_EventScript_HelperWalkDown::
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_WalkDown2
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_WalkDown3
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, JubilifeCity_EventScript_DawnCountParty
	call_if_eq VAR_RESULT, FEMALE, JubilifeCity_EventScript_LucasCountParty
	return

JubilifeCity_EventScript_DawnCountParty::
	msgbox JubilifeCity_Text_AreYouCatching, MSGBOX_DEFAULT
	specialvar VAR_0x8004, CalculatePlayerPartyCount
	call_if_le VAR_0x8004, 3, JubilifeCity_EventScript_DawnFew
	call_if_eq VAR_0x8004, 4, JubilifeCity_EventScript_Dawn4
	call_if_eq VAR_0x8004, 5, JubilifeCity_EventScript_Dawn5
	call_if_eq VAR_0x8004, 6, JubilifeCity_EventScript_Dawn6
	msgbox JubilifeCity_Text_DawnKnowMore, MSGBOX_DEFAULT
	closemessage
	return

JubilifeCity_EventScript_LucasCountParty::
	msgbox JubilifeCity_Text_HowManyCaught, MSGBOX_DEFAULT
	specialvar VAR_0x8004, CalculatePlayerPartyCount
	call_if_le VAR_0x8004, 3, JubilifeCity_EventScript_LucasFew
	call_if_eq VAR_0x8004, 4, JubilifeCity_EventScript_Lucas4
	call_if_eq VAR_0x8004, 5, JubilifeCity_EventScript_Lucas5
	call_if_eq VAR_0x8004, 6, JubilifeCity_EventScript_Lucas6
	msgbox JubilifeCity_Text_LucasKnowMore, MSGBOX_DEFAULT
	closemessage
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

JubilifeCity_EventScript_HelperWalkUp::
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_Walk_Up17
	applymovement LOCALID_CAMERA, Common_Movement_Walk_Up17
	applymovement LOCALID_PLAYER, Common_Movement_Walk_Up17
	waitmovement 0
	msgbox JubilifeCity_Text_ThatMan, MSGBOX_SIGN
	applymovement LOCALID_JUBILIFE_LOOKER, JubilifeCity_Movement_LookerScurry1
	waitmovement 0
	applymovement LOCALID_JUBILIFE_LOOKER, JubilifeCity_Movement_LookerScurry2
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_WalkUp2
	applymovement LOCALID_CAMERA, JubilifeCity_Movement_PlayerMeetLooker
	applymovement LOCALID_PLAYER, JubilifeCity_Movement_PlayerMeetLooker
	waitmovement 0
	special RemoveCameraObject
	setflag FLAG_HIDE_JUBILIFE_LOOKER
	end
	
JubilifeCity_Movement_LookerScurry1:
	walk_in_place_left
	delay_16
	delay_16
	walk_in_place_down
	delay_16
	delay_16
	walk_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_in_place_right
	delay_16
	delay_16
	walk_in_place_up
	delay_16
	delay_16
	step_end

JubilifeCity_Movement_LookerScurry2:
	walk_right
	walk_fast_right
	walk_fast_right
	step_end

JubilifeCity_Movement_PlayerMeetLooker:
	walk_up
	walk_up
	walk_right
	walk_up
	step_end

JubilifeCity_Text_AreYouCatching:
	.string "Dawn: Hi, {PLAYER}!\n"
	.string "Are you catching Pokemon?$"

JubilifeCity_Text_HowManyCaught:
	.string "Lucas: Hey, {PLAYER}!\n"
	.string "How many Pokemon have you caught?$"
	
JubilifeCity_Text_FeelSafer:
	.string "...Um...\p"
	.string "I think you'd feel a lot safer if you\n"
	.string "were to catch some more.\p"
	.string "You know, like when you need to travel\n"
	.string "to faraway places.$"

JubilifeCity_Text_CatchMore:
	.string "Huh?\n"
	.string "I think you should catch some more.\p"
	.string "It might be more of a challenge\n"
	.string "raising a lot of Pokemon...\p"
	.string "But it's worth it. The more Pokemon\n"
	.string "you have, the happier you'll be.$"

JubilifeCity_Text_AlreadyGot4:
	.string "Wow! You've already got 4 Pokemon\n"
	.string "with you!\p"
	.string "At that pace, your Pokedex should\n"
	.string "be full in non time at all!$"

JubilifeCity_Text_AlreadyGot5:
	.string "Wow! You've already got 5 Pokemon\n"
	.string "with you!\p"
	.string "At that pace, your Pokedex should\n"
	.string "be full in non time at all!$"

JubilifeCity_Text_AlreadyGot6:
	.string "Wow! You've already got 6 Pokemon\n"
	.string "with you!\p"
	.string "At that pace, your Pokedex should\n"
	.string "be full in non time at all!$"

JubilifeCity_Text_AlreadyHave4:
	.string "Whoa! You already have 4 Pokemon\n"
	.string "with you!$"

JubilifeCity_Text_AlreadyHave5:
	.string "Whoa! You already have 5 Pokemon\n"
	.string "with you!$"

JubilifeCity_Text_AlreadyHave6:
	.string "Whoa! You already have 6 Pokemon\n"
	.string "with you!$"

JubilifeCity_Text_DawnKnowMore:
	.string "Oh, I know! Don't you think it's\n"
	.string "better to know more about Pokemon?\p"
	.string "Sure it is!\n"
	.string "I know just the place.\p"
	.string "Come on!\n"
	.string "Don't be shy. Follow me!$"

JubilifeCity_Text_LucasKnowMore:
	.string "Hey, that's right! Don't you think it's\n"
	.string "better to know more about Pokemon?\p"
	.string "Sure it is!\n"
	.string "There's this great place for that.\p"
	.string "Come on! It's all right.\n"
	.string "Follow me.$"

JubilifeCity_Text_ThatMan:
	.string "Dawn: That man...\n"
	.string "What is he doing?$"
