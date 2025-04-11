.set LOCALID_HELPER, 1

Route202_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route202_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route202_OnFrame
	.byte 0

	@ State descriptions for VAR_ROUTE202_STATE
	@ 1: Completed catching tutorial
	
Route202_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

Route202_OnFrame:
	.2byte 0

Route202_EventScript_HelperExclaim::
	lockall
	setvar VAR_ROUTE202_STATE, 1
	applymovement LOCALID_HELPER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 10
	playse SE_PIN
	applymovement LOCALID_HELPER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_HELPER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_HELPER, Common_Movement_Delay48
	waitmovement 0
	return

Route202_EventScript_HelperTeach1::
	call Route202_EventScript_HelperExclaim
	applymovement LOCALID_HELPER, Route202_Movement_Helper1
	waitmovement 0
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 8, Route202_EventScript_HelperAccept
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 7, Route202_EventScript_HelperDecline
	applymovement OBJ_EVENT_ID_PLAYER, Route202_Movement_HelperBump
	applymovement LOCALID_HELPER, Route202_Movement_HelperReturn1
	waitmovement 0
	releaseall
	end

Route202_EventScript_HelperTeach2::
	call Route202_EventScript_HelperExclaim
	applymovement LOCALID_HELPER, Route202_Movement_Helper2
	waitmovement 0
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 8, Route202_EventScript_HelperAccept
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 7, Route202_EventScript_HelperDecline
	applymovement OBJ_EVENT_ID_PLAYER, Route202_Movement_HelperBump
	applymovement LOCALID_HELPER, Route202_Movement_HelperReturn2
	waitmovement 0
	releaseall
	end

Route202_EventScript_HelperTeach3::
	call Route202_EventScript_HelperExclaim
	applymovement LOCALID_HELPER, Route202_Movement_Helper3
	waitmovement 0
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 8, Route202_EventScript_HelperAccept
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 7, Route202_EventScript_HelperDecline
	applymovement OBJ_EVENT_ID_PLAYER, Route202_Movement_HelperBump
	applymovement LOCALID_HELPER, Route202_Movement_HelperReturn3
	waitmovement 0
	releaseall
	end

Route202_EventScript_HelperTeach4::
	call Route202_EventScript_HelperExclaim
	applymovement LOCALID_HELPER, Route202_Movement_Helper4
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 8, Route202_EventScript_HelperAccept
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 7, Route202_EventScript_HelperDecline
	applymovement OBJ_EVENT_ID_PLAYER, Route202_Movement_HelperBump
	applymovement LOCALID_HELPER, Route202_Movement_HelperReturn4
	waitmovement 0
	releaseall
	end

Route202_EventScript_HelperDecline::
	goto_if_lt VAR_ALTERNATE_TEXT, 3, Route202_EventScript_HelperDeclineFirst
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route202_EventScript_TellFamilyA
	call_if_eq VAR_RESULT, FEMALE, Route202_EventScript_TellFamilyB
	return

Route202_EventScript_HelperDeclineFirst::
	setvar VAR_ALTERNATE_TEXT, 3
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route202_EventScript_ReallyEagerA
	call_if_eq VAR_RESULT, FEMALE, Route202_EventScript_ReallyEagerB
	return

Route202_EventScript_HelperAccept::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route202_EventScript_DemonstrateA
	call_if_eq VAR_RESULT, FEMALE, Route202_EventScript_DemonstrateB
	applymovement LOCALID_HELPER, Common_Movement_WalkLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_HELPER, Common_Movement_WalkLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	delay 16
	special StartWallyTutorialBattle
	waitstate
	applymovement LOCALID_HELPER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route202_EventScript_LoweredA
	call_if_eq VAR_RESULT, FEMALE, Route202_EventScript_LoweredB
	giveitem ITEM_POKE_BALL, 5
	setvar VAR_RESULT, 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route202_EventScript_FartherA
	call_if_eq VAR_RESULT, FEMALE, Route202_EventScript_FartherB
	applymovement LOCALID_HELPER, Route202_Movement_HelperLeave
	waitmovement 0
	removeobject LOCALID_HELPER
	setflag FLAG_HIDE_ROUTE_202_HELPER
	setvar VAR_ROUTE202_STATE, 2
	delay 48
	releaseall
	end

Route202_Movement_Helper1:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_up
	walk_right
	step_end

Route202_Movement_Helper2:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	step_end

Route202_Movement_Helper3:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route202_Movement_Helper4:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	step_end

Route202_Movement_HelperReturn1:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_in_place_right
	step_end

Route202_Movement_HelperReturn2:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_down
	walk_in_place_right
	step_end

Route202_Movement_HelperReturn3:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_in_place_right
	step_end

Route202_Movement_HelperReturn4:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
	walk_in_place_right
	step_end

Route202_Movement_HelperBump:
	walk_right
	walk_in_place_left
	step_end

Route202_Movement_HelperLeave:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

Route202_EventScript_ReallyEagerA::
	msgbox Route202_Text_ReallyEagerA, MSGBOX_SIGN
	return

Route202_EventScript_ReallyEagerB::
	msgbox Route202_Text_ReallyEagerB, MSGBOX_SIGN
	return

Route202_EventScript_TellFamilyA::
	msgbox Route202_Text_TellFamilyA, MSGBOX_SIGN
	return

Route202_EventScript_TellFamilyB::
	msgbox Route202_Text_TellFamilyB, MSGBOX_SIGN
	return

Route202_EventScript_DemonstrateA::
	msgbox Route202_Text_DemonstrateA, MSGBOX_SIGN
	return

Route202_EventScript_DemonstrateB::
	msgbox Route202_Text_DemonstrateB, MSGBOX_SIGN
	return

Route202_EventScript_LoweredA::
	msgbox Route202_Text_LoweredA, MSGBOX_DEFAULT
	return

Route202_EventScript_LoweredB::
	msgbox Route202_Text_LoweredB, MSGBOX_DEFAULT
	return

Route202_EventScript_FartherA::
	msgbox Route202_Text_FartherA, MSGBOX_SIGN
	return

Route202_EventScript_FartherB::
	msgbox Route202_Text_FartherB, MSGBOX_SIGN
	return

Route202_EventScript_LittleBoy::
	msgbox Route202_Text_ImNotVeryTall, MSGBOX_NPC
	end

Route202_EventScript_RouteSignOldale::
	msgbox Route202_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route202_EventScript_RouteSignPetalburg::
	msgbox Route202_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route202_EventScript_Boy::
	msgbox Route202_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

Route202_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, Route202_Text_CalvinIntro, Route202_Text_CalvinDefeated, Route202_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route202_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route202_EventScript_CalvinTryRegister
	msgbox Route202_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route202_EventScript_CalvinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route202_EventScript_CalvinRegisterMatchCall
	release
	end

Route202_EventScript_CalvinRegisterMatchCall::
	msgbox Route202_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route202_EventScript_CalvinTryRegister::
	goto_if_set FLAG_HAS_MATCH_CALL, Route202_EventScript_CalvinRegister
	msgbox Route202_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route202_EventScript_CalvinRegister::
	msgbox Route202_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route202_EventScript_CalvinRematch::
	trainerbattle_rematch TRAINER_CALVIN_1, Route202_Text_CalvinRematchIntro, Route202_Text_CalvinRematchDefeated
	msgbox Route202_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route202_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, Route202_Text_RickIntro, Route202_Text_RickDefeated
	msgbox Route202_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route202_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, Route202_Text_TianaIntro, Route202_Text_TianaDefeated
	msgbox Route202_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route202_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN, Route202_Text_AllenIntro, Route202_Text_AllenDefeated
	msgbox Route202_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end

LittlerootTown_ProfessorBirchsLab_EventScript_MayGivePokeBalls::
	giveitem ITEM_POKE_BALL, 5
	setvar VAR_RESULT, 0
	return

Route202_Text_ReallyEagerA:
	.string "Dawn: {PLAYER}?!\p"
	.string "Did you tell your family that you're\n"
	.string "helping the professor?\p"
	.string "...You didn't, did you?\p"
	.string "I know that you're really eager to\n"
	.string "see all kinds of Pokémon.\p"
	.string "But you shouldn't make your mom\n"
	.string "worry that you've disappeared.$"

Route202_Text_TellFamilyA:
	.string "Dawn: You should go tell your family\n"
	.string "that you're helping the professor.\p"
	.string "The faster the better, too$"

Route202_Text_ReallyEagerB:
	.string "Dawn: {PLAYER}?!\p"
	.string "Did you tell your family that you're\n"
	.string "helping the professor?\p"
	.string "...I bet you didn't, did you?\p"
	.string "I know that you're eager to\n"
	.string "see all kinds of Pokémon.\p"
	.string "But you shouldn't make your mom\n"
	.string "worry that you've upped and left.$"

Route202_Text_TellFamilyB:
	.string "Lucas: Why don't you go tell your\n"
	.string "family that the professor asked for\l"
	.string "your help?\p"
	.string "You should do it right away.$"

Route202_Text_DemonstrateA:
	.string "Dawn: Oh, that's right!\p"
	.string "{PLAYER}, I haven't shown you\n"
	.string "how to catch a Pokémon.\p"
	.string "I'll demonstrate how to catch\n"
	.string "one, so just watch me, OK?$"

Route202_Text_DemonstrateB:
	.string "Lucas: {PLAYER}, do you know\n"
	.string "how to catch a Pokémon?\p"
	.string "I'll demonstrate how to catch\n"
	.string "one, so just watch, OK?$"

Route202_Text_LoweredA:
	.string "Lucas: And that's how it's done.\p"
	.string "Actually, I should have lowered the\n"
	.string "target's HP some more.\p"
	.string "Yup, the important thing is to lower\n"
	.string "the Pokémon's HP as much as possible.\p"
	.string "See, a healthy Pokémon isn't easy to\n"
	.string "catch.\p"
	.string "Oh, yeah. They also get easier to\n"
	.string "catch if you make one of your\l"
	.string "Pokémon put them to sleep or such.\p"
	.string "Here, {PLAYER}, I'll give you\n"
	.string "five Poké Balls to get you started.$"

Route202_Text_LoweredB:
	.string "Dawn: Giggle...\n"
	.string "See? Isn't it neat?\p"
	.string "Actually, it's better to lower your\n"
	.string "target's HP more than I did.\p"
	.string "It's important to get the Pokémon's\n"
	.string "HP down as low as possible\p"
	.string "This is because a healthy Pokémon\n"
	.string "is very difficult to catch.\p"
	.string "Oh, Pokémon also get easier to catch\n"
	.string "if you make them sleep or something\l"
	.string "by using a Pokémon's move.\p"
	.string "OK, {PLAYER}, to get you\n"
	.string "started, I'll give you five\l"
	.string "Poké Balls!$"

Route202_Text_FartherA:
	.string "If you have lots of Pokémon with you,\n"
	.string "it will be safer on long trips.\p"
	.string "Plus, it will be alot more fun\n"
	.string "having your Pokémon friends along.\p"
	.string "OK, I need to get going.\n"
	.string "Bye, now!$"

Route202_Text_FartherB:
	.string "If you have lots of Pokémon with you,\n"
	.string "you'll be able to travel farther.\p"
	.string "That way, you'll have a better shot\n"
	.string "at meeting more Pokémon.\p"
	.string "See you around!$"

Route202_Text_WatchMeCatchPokemon:
	.string "WALLY: {PLAYER}…\n"
	.string "POKéMON hide in tall grass like this,\l"
	.string "don't they?\p"
	.string "Please watch me and see if I can\n"
	.string "catch one properly.\p"
	.string "…Whoa!$"

Route202_Text_WallyIDidIt:
	.string "WALLY: I did it… It's my…\n"
	.string "My POKéMON!$"

Route202_Text_LetsGoBack:
	.string "{PLAYER}, thank you!\n"
	.string "Let's go back to the GYM!$"

Route202_Text_ImNotVeryTall:
	.string "I'm…not very tall, so I sink right\n"
	.string "into tall grass.\p"
	.string "The grass goes up my nose and…\n"
	.string "Fwafwafwafwafwa…\p"
	.string "Fwatchoo!$"

Route202_Text_CatchWholeBunchOfPokemon:
	.string "I'm going to catch a whole bunch of\n"
	.string "POKéMON!$"

Route202_Text_RouteSignOldale:
	.string "ROUTE 202\n"
	.string "{RIGHT_ARROW} OLDALE TOWN$"

Route202_Text_RouteSignPetalburg:
	.string "ROUTE 202\n"
	.string "{LEFT_ARROW} PETALBURG CITY$"
