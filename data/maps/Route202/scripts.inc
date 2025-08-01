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
	applymovement LOCALID_ROUTE202_HELPER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 10
	playse SE_PIN
	applymovement LOCALID_ROUTE202_HELPER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE202_HELPER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_ROUTE202_HELPER, Common_Movement_Delay48
	waitmovement 0
	return

Route202_EventScript_HelperTeach1::
	call Route202_EventScript_HelperExclaim
	applymovement LOCALID_ROUTE202_HELPER, Route202_Movement_Helper1
	waitmovement 0
	goto_if_eq VAR_TWINLEAF_INTRO_STATE, 9, Route202_EventScript_HelperAccept
	call_if_eq VAR_TWINLEAF_INTRO_STATE, 8, Route202_EventScript_HelperDecline
	applymovement LOCALID_PLAYER, Route202_Movement_HelperBump
	applymovement LOCALID_ROUTE202_HELPER, Route202_Movement_HelperReturn1
	waitmovement 0
	releaseall
	end

Route202_EventScript_HelperTeach2::
	call Route202_EventScript_HelperExclaim
	applymovement LOCALID_ROUTE202_HELPER, Route202_Movement_Helper2
	waitmovement 0
	goto_if_eq VAR_TWINLEAF_INTRO_STATE, 9, Route202_EventScript_HelperAccept
	call_if_eq VAR_TWINLEAF_INTRO_STATE, 8, Route202_EventScript_HelperDecline
	applymovement LOCALID_PLAYER, Route202_Movement_HelperBump
	applymovement LOCALID_ROUTE202_HELPER, Route202_Movement_HelperReturn2
	waitmovement 0
	releaseall
	end

Route202_EventScript_HelperTeach3::
	call Route202_EventScript_HelperExclaim
	applymovement LOCALID_ROUTE202_HELPER, Route202_Movement_Helper3
	waitmovement 0
	goto_if_eq VAR_TWINLEAF_INTRO_STATE, 9, Route202_EventScript_HelperAccept
	call_if_eq VAR_TWINLEAF_INTRO_STATE, 8, Route202_EventScript_HelperDecline
	applymovement LOCALID_PLAYER, Route202_Movement_HelperBump
	applymovement LOCALID_ROUTE202_HELPER, Route202_Movement_HelperReturn3
	waitmovement 0
	releaseall
	end

Route202_EventScript_HelperTeach4::
	call Route202_EventScript_HelperExclaim
	applymovement LOCALID_ROUTE202_HELPER, Route202_Movement_Helper4
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	goto_if_eq VAR_TWINLEAF_INTRO_STATE, 9, Route202_EventScript_HelperAccept
	call_if_eq VAR_TWINLEAF_INTRO_STATE, 8, Route202_EventScript_HelperDecline
	applymovement LOCALID_PLAYER, Route202_Movement_HelperBump
	applymovement LOCALID_ROUTE202_HELPER, Route202_Movement_HelperReturn4
	waitmovement 0
	releaseall
	end

Route202_EventScript_HelperTeach5::
	call Route202_EventScript_HelperExclaim
	applymovement LOCALID_ROUTE202_HELPER, Route202_Movement_Helper5
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	goto_if_eq VAR_TWINLEAF_INTRO_STATE, 9, Route202_EventScript_HelperAccept
	call_if_eq VAR_TWINLEAF_INTRO_STATE, 8, Route202_EventScript_HelperDecline
	applymovement LOCALID_PLAYER, Route202_Movement_HelperBump
	applymovement LOCALID_ROUTE202_HELPER, Route202_Movement_HelperReturn5
	waitmovement 0
	releaseall
	end

Route202_EventScript_HelperDecline::
	goto_if_lt VAR_ALTERNATE_TEXT, 3, Route202_EventScript_HelperDeclineFirst
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route202_EventScript_TellFamilyDawn
	call_if_eq VAR_RESULT, FEMALE, Route202_EventScript_TellFamilyLucas
	return

Route202_EventScript_HelperDeclineFirst::
	setvar VAR_ALTERNATE_TEXT, 3
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route202_EventScript_ReallyEagerDawn
	call_if_eq VAR_RESULT, FEMALE, Route202_EventScript_ReallyEagerLucas
	return

Route202_EventScript_HelperAccept::
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route202_EventScript_DemonstrateDawn
	call_if_eq VAR_RESULT, FEMALE, Route202_EventScript_DemonstrateLucas
	applymovement LOCALID_ROUTE202_HELPER, Common_Movement_WalkLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_ROUTE202_HELPER, Common_Movement_WalkLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	delay 16
	special StartWallyTutorialBattle
	waitstate
	applymovement LOCALID_ROUTE202_HELPER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route202_EventScript_LoweredDawn
	call_if_eq VAR_RESULT, FEMALE, Route202_EventScript_LoweredLucas
	giveitem ITEM_POKE_BALL, 5
	setvar VAR_RESULT, 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route202_EventScript_FartherDawn
	call_if_eq VAR_RESULT, FEMALE, Route202_EventScript_FartherLucas
	applymovement LOCALID_ROUTE202_HELPER, Route202_Movement_HelperLeave
	waitmovement 0
	removeobject LOCALID_ROUTE202_HELPER
	setflag FLAG_HIDE_ROUTE_202_HELPER
	setvar VAR_ROUTE202_STATE, 1
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

Route202_Movement_Helper5:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
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

Route202_Movement_HelperReturn5:
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_up
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

Route202_EventScript_ReallyEagerDawn::
	msgbox Route202_Text_ReallyEagerDawn, MSGBOX_SIGN
	return

Route202_EventScript_ReallyEagerLucas::
	msgbox Route202_Text_ReallyEagerLucas, MSGBOX_SIGN
	return

Route202_EventScript_TellFamilyDawn::
	msgbox Route202_Text_TellFamilyDawn, MSGBOX_SIGN
	return

Route202_EventScript_TellFamilyLucas::
	msgbox Route202_Text_TellFamilyLucas, MSGBOX_SIGN
	return

Route202_EventScript_DemonstrateDawn::
	msgbox Route202_Text_DemonstrateDawn, MSGBOX_SIGN
	return

Route202_EventScript_DemonstrateLucas::
	msgbox Route202_Text_DemonstrateLucas, MSGBOX_SIGN
	return

Route202_EventScript_LoweredDawn::
	msgbox Route202_Text_LoweredDawn, MSGBOX_DEFAULT
	return

Route202_EventScript_LoweredLucas::
	msgbox Route202_Text_LoweredLucas, MSGBOX_DEFAULT
	return

Route202_EventScript_FartherDawn::
	msgbox Route202_Text_FartherDawn, MSGBOX_SIGN
	return

Route202_EventScript_FartherLucas::
	msgbox Route202_Text_FartherLucas, MSGBOX_SIGN
	return

Route202_EventScript_RouteSignSandgem::
	msgbox Route202_Text_RouteSignSandgem, MSGBOX_SIGN
	end

Route202_EventScript_RouteSignJubilife::
	msgbox Route202_Text_RouteSignJubilife, MSGBOX_SIGN
	end

Route202_EventScript_Boy::
	msgbox Route202_Text_KeepWaiting, MSGBOX_NPC
	end

Route202_EventScript_TrainerTips::
	msgbox Route202_Text_TrainerTips, MSGBOX_SIGN
	end

Route202_EventScript_Tristan::
	trainerbattle_single TRAINER_TRISTAN_1, Route202_Text_TristanIntro, Route202_Text_TristanDefeated, Route202_EventScript_TristanRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route202_EventScript_TristanRematch
	setvar VAR_0x8004, TRAINER_TRISTAN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route202_EventScript_TristanTryRegister
	msgbox Route202_Text_TristanPostBattle, MSGBOX_DEFAULT
	release
	end

Route202_EventScript_TristanRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route202_EventScript_TristanRegisterMatchCall
	release
	end

Route202_EventScript_TristanRegisterMatchCall::
	msgbox Route202_Text_TristanRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_TRISTAN_1
	release
	end

Route202_EventScript_TristanTryRegister::
	goto_if_set FLAG_HAS_MATCH_CALL, Route202_EventScript_TristanRegister
	msgbox Route202_Text_TristanPostBattle, MSGBOX_DEFAULT
	release
	end

Route202_EventScript_TristanRegister::
	msgbox Route202_Text_TristanRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_TRISTAN_1
	release
	end

Route202_EventScript_TristanRematch::
	trainerbattle_rematch TRAINER_TRISTAN_1, Route202_Text_TristanRematchIntro, Route202_Text_TristanRematchDefeated
	msgbox Route202_Text_TristanRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route202_EventScript_Natalie::
	trainerbattle_single TRAINER_NATALIE, Route202_Text_NatalieIntro, Route202_Text_NatalieDefeated
	msgbox Route202_Text_NataliePostBattle, MSGBOX_AUTOCLOSE
	end

Route202_EventScript_Logan::
	trainerbattle_single TRAINER_LOGAN, Route202_Text_LoganIntro, Route202_Text_LoganDefeated
	msgbox Route202_Text_LoganPostBattle, MSGBOX_AUTOCLOSE
	end

SandgemTown_ProfessorRowansLab_EventScript_MayGivePokeBalls::
	giveitem ITEM_POKE_BALL, 5
	setvar VAR_RESULT, 0
	return

Route202_Text_ReallyEagerDawn:
	.string "Dawn: {PLAYER}?!\p"
	.string "Did you tell your family that you're\n"
	.string "helping the professor?\p"
	.string "...You didn't, did you?\p"
	.string "I know that you're really eager to\n"
	.string "see all kinds of Pokémon.\p"
	.string "But you shouldn't make your mom\n"
	.string "worry that you've disappeared.$"

Route202_Text_ReallyEagerLucas:
	.string "Lucas: {PLAYER}?!\p"
	.string "Did you tell your family that you're\n"
	.string "helping the professor?\p"
	.string "...I bet you didn't, did you?\p"
	.string "I know that you're eager to\n"
	.string "see all kinds of Pokémon.\p"
	.string "But you shouldn't make your mom\n"
	.string "worry that you've upped and left.$"

Route202_Text_TellFamilyDawn:
	.string "Dawn: You should go tell your family\n"
	.string "that you're helping the professor.\p"
	.string "The faster the better, too$"

Route202_Text_TellFamilyLucas:
	.string "Lucas: Why don't you go tell your\n"
	.string "family that the professor asked for\l"
	.string "your help?\p"
	.string "You should do it right away.$"

Route202_Text_DemonstrateDawn:
	.string "Dawn: Oh, that's right!\p"
	.string "{PLAYER}, I haven't shown you\n"
	.string "how to catch a Pokémon.\p"
	.string "I'll demonstrate how to catch\n"
	.string "one, so just watch me, OK?$"

Route202_Text_DemonstrateLucas:
	.string "Lucas: {PLAYER}, do you know\n"
	.string "how to catch a Pokémon?\p"
	.string "I'll demonstrate how to catch\n"
	.string "one, so just watch, OK?$"

Route202_Text_LoweredDawn:
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

Route202_Text_LoweredLucas:
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

Route202_Text_FartherDawn:
	.string "If you have lots of Pokémon with you,\n"
	.string "it will be safer on long trips.\p"
	.string "Plus, it will be alot more fun\n"
	.string "having your Pokémon friends along.\p"
	.string "OK, I need to get going.\n"
	.string "Bye, now!$"

Route202_Text_FartherLucas:
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

Route202_Text_KeepWaiting:
	.string "Some Pokémon only appear in the\n"
	.string "morning. Some only come out at night.\p"
	.string "I'm going to keep waiting right here\n"
	.string "till I've seen every last one of 'em!$"

Route202_Text_TrainerTips:
	.string "TRAINER TIPS!\p"
	.string "All Pokémon that are involved in\n"
	.string "a battle earn Exp. Points\p"
	.string "The more your Pokémon battle,\n"
	.string "the stronger they will become.$"

Route202_Text_RouteSignSandgem:
	.string "{DOWN_ARROW} Rt.202\n"
	.string "   Sandgem Town$"

Route202_Text_RouteSignJubilife:
	.string "{UP_ARROW} Rt.202\n"
	.string "   Jubilife City$"
