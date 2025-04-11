.set LOCALID_RIVAL, 1
.set LOCALID_PROF, 2
.set LOCALID_HELPER, 3
.set LOCALID_BRIEFCASE, 8

Route201_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route201_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route201_OnFrame
	.byte 0

	@ State descriptions for VAR_ROUTE201_STATE
	@ 1: Entered rival running scene
	@ 2: Met the professor
	@ 3: Entered lake event
	@ 4: Finished lake event
	@ 5: Received Potion sample
	
	@ State descriptions for VAR_FOLLOWER_TEXT
	@ 1-6: Visit lake with Rival

Route201_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

Route201_OnFrame:
	.2byte 0

Route201_EventScript_RivalSee1::
	setvar VAR_0x8004, 1
	goto Route201_EventScript_RivalSee

Route201_EventScript_RivalSee2::
	setvar VAR_0x8004, 2
	goto Route201_EventScript_RivalSee

Route201_EventScript_RivalSee3::
	setvar VAR_0x8004, 3
	goto Route201_EventScript_RivalSee

Route201_EventScript_RivalSee4::
	setvar VAR_0x8004, 4
	goto Route201_EventScript_RivalSee

Route201_EventScript_RivalSee::
	lock
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 10
	playse SE_PIN
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	goto_if_eq VAR_ROUTE201_STATE, 2, Route201_EventScript_RivalLake
	setvar VAR_ROUTE201_STATE, 1
	msgbox Route201_Text_TooSlow, MSGBOX_SIGN
	call_if_eq VAR_0x8004, 1, Route201_EventScript_RivalShift1
	call_if_eq VAR_0x8004, 2, Route201_EventScript_RivalShift2
	call_if_eq VAR_0x8004, 3, Route201_EventScript_RivalShift3
	call_if_eq VAR_0x8004, 4, Route201_EventScript_RivalShift4
	waitmovement 0
	msgbox Route201_Text_GetMoving, MSGBOX_SIGN
	call_if_eq VAR_0x8004, 1, Route201_EventScript_RivalGrass1
	call_if_eq VAR_0x8004, 2, Route201_EventScript_RivalGrass2
	call_if_eq VAR_0x8004, 3, Route201_EventScript_RivalGrass3
	call_if_eq VAR_0x8004, 4, Route201_EventScript_RivalGrass4
	msgbox Route201_Text_DoNotGo, MSGBOX_SIGN
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox Route201_Text_ScootOver, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_PLAYER, Route201_Movement_RunWatch1
	applymovement LOCALID_RIVAL, Route201_Movement_RunPrep
	waitmovement 0
	msgbox Route201_Text_HereGoes, MSGBOX_SIGN
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Route201_Movement_RunWatch2
	applymovement LOCALID_RIVAL, Route201_Movement_RunGrass
	waitmovement 0
	msgbox Route201_Text_HoldIt, MSGBOX_SIGN
	playse SE_PIN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_ExclamationMark
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	goto Route201_EventScript_ProfessorMeet

Route201_EventScript_RivalShift1::
	applymovement LOCALID_RIVAL, Route201_Movement_RivalShift1
	waitmovement 0
	return

Route201_EventScript_RivalShift2::
	applymovement LOCALID_RIVAL, Route201_Movement_RivalShift2
	waitmovement 0
	return

Route201_EventScript_RivalShift3::
	applymovement LOCALID_RIVAL, Route201_Movement_RunDown
	waitmovement 0
	return

Route201_EventScript_RivalShift4::
	applymovement LOCALID_RIVAL, Route201_Movement_RivalShift4
	waitmovement 0
	return

Route201_EventScript_RouteSign::
	msgbox Route201_Text_RouteSign, MSGBOX_SIGN
	end

Route201_Movement_RunDown:
	walk_fast_down
	step_end

Route201_Movement_RivalShift1:
	walk_fast_left
	walk_fast_left
	walk_fast_down
	step_end

Route201_Movement_RivalShift2:
	walk_fast_left
	walk_fast_down
	step_end

Route201_Movement_RivalShift4:
	walk_fast_right
	walk_fast_down
	step_end

Route201_EventScript_RivalGrass1::
	applymovement OBJ_EVENT_ID_PLAYER, Route201_Movement_PlayerGrass1
	applymovement LOCALID_RIVAL, Route201_Movement_RivalGrass1
	waitmovement 0
	return

Route201_EventScript_RivalGrass2::
	applymovement OBJ_EVENT_ID_PLAYER, Route201_Movement_PlayerGrass2
	applymovement LOCALID_RIVAL, Route201_Movement_RivalGrass2
	waitmovement 0
	return

Route201_EventScript_RivalGrass3::
	applymovement OBJ_EVENT_ID_PLAYER, Route201_Movement_PlayerGrass3
	applymovement LOCALID_RIVAL, Route201_Movement_RivalGrass3
	waitmovement 0
	return

Route201_EventScript_RivalGrass4::
	applymovement OBJ_EVENT_ID_PLAYER, Route201_Movement_PlayerGrass4
	applymovement LOCALID_RIVAL, Route201_Movement_RivalGrass4
	waitmovement 0
	return

Route201_Movement_RivalGrass1:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_in_place_left
	step_end

Route201_Movement_RivalGrass2:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	walk_right
	walk_in_place_left
	step_end

Route201_Movement_RivalGrass3:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_right
	walk_in_place_left
	step_end

Route201_Movement_RivalGrass4:
	walk_up
	walk_up
	walk_right
	walk_up
	walk_right
	walk_in_place_left
	step_end

Route201_Movement_PlayerGrass1:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route201_Movement_PlayerGrass2:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	step_end

Route201_Movement_PlayerGrass3:
	walk_up
	walk_up
	walk_up
	walk_right
	walk_right
	step_end

Route201_Movement_PlayerGrass4:
	walk_up
	walk_up
	walk_up
	walk_right
	step_end

Route201_Movement_RunWatch1:
	delay_16
	walk_in_place_left
	step_end

Route201_Movement_RunWatch2:
	delay_16
	walk_in_place_up
	step_end

Route201_Movement_RunPrep:
	walk_left
	walk_left
	walk_left
	walk_in_place_right
	step_end

Route201_Movement_RunGrass:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end


Route201_EventScript_ProfessorMeet::
	addobject LOCALID_PROF
	applymovement LOCALID_PROF, Route201_Movement_ProfessorEnter
	waitmovement 0
	msgbox Route201_Text_DoNotSeem, MSGBOX_DEFAULT
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox Route201_Text_ThisOldGuy, MSGBOX_SIGN
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceLeft
	applymovement LOCALID_PROF, Route201_Movement_ProfessorWalkAway
	waitmovement 0
	msgbox Route201_Text_TheyTried, MSGBOX_SIGN
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PROF, Route201_Movement_ProfessorWalkBack
	waitmovement 0
	goto Route201_EventScript_TrulyLove

Route201_EventScript_TrulyLove::
	msgbox Route201_Text_TrulyLove, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route201_EventScript_TrulyFail
	goto Route201_EventScript_TrulyPass

Route201_EventScript_TrulyFail::
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	msgbox Route201_Text_HoldUp, MSGBOX_SIGN
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Route201_Text_DidNotCatch, MSGBOX_DEFAULT
	goto Route201_EventScript_TrulyLove

Route201_EventScript_TrulyPass::
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Route201_Text_MeToo, MSGBOX_DEFAULT
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	goto Route201_EventScript_HundredTimes

Route201_EventScript_HundredTimes::
	msgbox Route201_Text_HundredTimes, MSGBOX_DEFAULT
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox Route201_Text_RightPlayer, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route201_EventScript_HundredFail
	goto Route201_EventScript_HundredPass

Route201_EventScript_HundredFail::
	msgbox Route201_Text_OldJoke, MSGBOX_DEFAULT
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	goto Route201_EventScript_HundredTimes

Route201_EventScript_HundredPass::
	msgbox Route201_Text_RecklessKids, MSGBOX_DEFAULT
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Route201_Text_FriendHere, MSGBOX_SIGN
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement LOCALID_PROF, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceRight
	waitmovement 0
	applymovement LOCALID_PROF, Common_Movement_Delay48
	waitmovement 0
	addobject LOCALID_HELPER
	applymovement LOCALID_HELPER, Route201_Movement_HelperEnter
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route201_EventScript_LeftBriefcaseDawn
	call_if_eq VAR_RESULT, FEMALE, Route201_EventScript_LeftBriefcaseLucas
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	addobject LOCALID_BRIEFCASE
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route201_EventScript_SomethingWrongDawn
	call_if_eq VAR_RESULT, FEMALE, Route201_EventScript_SomethingWrongLucas
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox Route201_Text_ChooseYour, MSGBOX_DEFAULT
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Route201_Text_StraightFace, MSGBOX_DEFAULT
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox Route201_Text_SomeClass, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_Delay48
	waitmovement 0
	release
	end

Route201_EventScript_LeftBriefcaseDawn::
	msgbox Route201_Text_LeftBriefcaseDawn, MSGBOX_SIGN
	return

Route201_EventScript_LeftBriefcaseLucas::
	msgbox Route201_Text_LeftBriefcaseLucas, MSGBOX_SIGN
	return
	
Route201_EventScript_SomethingWrongDawn::
	msgbox Route201_Text_SomethingWrongDawn, MSGBOX_DEFAULT
	applymovement LOCALID_HELPER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox Route201_Text_HardReplaceDawn, MSGBOX_SIGN
	return
	
Route201_EventScript_SomethingWrongLucas::
	msgbox Route201_Text_SomethingWrongLucas, MSGBOX_DEFAULT
	applymovement LOCALID_HELPER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox Route201_Text_HardReplaceLucas, MSGBOX_SIGN
	return

Route201_Movement_ProfessorEnter:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route201_Movement_ProfessorWalkAway:
	walk_left
	walk_left
	walk_left
	step_end

Route201_Movement_ProfessorWalkBack:
	walk_right
	walk_right
	walk_right
	step_end

Route201_Movement_HelperEnter:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route201_EventScript_PickLeaveRight::
	lock
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox Route201_Text_WhatsUp, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	release
	end

Route201_EventScript_PickLeaveDown::
	lock
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox Route201_Text_WhatsUp, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	release
	end

Route201_EventScript_RowanChoose::
	msgbox Route201_Text_RowanChoose, MSGBOX_NPC
	end

Route201_EventScript_RivalChoose::
	goto_if_eq VAR_ROUTE201_STATE, 1, Route201_EventScript_RivalChooseMsg
	end

Route201_EventScript_RivalChooseMsg::
	msgbox Route201_Text_RivalChoose, MSGBOX_NPC
	end

Route201_EventScript_PickStarter::
	lock
	special ChooseStarter
	delay 30
	removeobject LOCALID_BRIEFCASE
	setflag FLAG_SYS_POKEMON_GET
	applymovement LOCALID_RIVAL, Common_Movement_FaceLeft
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	switch VAR_STARTER_MON
	case 0, Route201_EventScript_RivalPickTurtwig
	case 1, Route201_EventScript_RivalPickChimchar
	case 2, Route201_EventScript_RivalPickPiplup

Route201_EventScript_StarterPicked::
	msgbox Route201_Text_ChosenGood, MSGBOX_SIGN
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement LOCALID_PROF, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceRight
	applymovement LOCALID_PROF, Route201_Movement_ProfessorLeave
	waitmovement 0
	removeobject LOCALID_PROF
	checkplayergender
	call_if_eq VAR_RESULT, MALE, Route201_EventScript_HelperWaitDawn
	call_if_eq VAR_RESULT, FEMALE, Route201_EventScript_HelperWaitLucas
	applymovement LOCALID_HELPER, Common_Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	applymovement LOCALID_HELPER, Route201_Movement_ProfessorEnter
	waitmovement 0
	removeobject LOCALID_HELPER
	msgbox Route201_Text_ReallyNice, MSGBOX_SIGN
	delay 48
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 48
	applymovement LOCALID_RIVAL, Route201_Movement_RivalScurry
	waitmovement 0
	goto Route201_EventScript_RivalBattle

Route201_Movement_ProfessorLeave:
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route201_EventScript_RivalPickTurtwig::
	msgbox Route201_Text_RivalPickTurtwig, MSGBOX_DEFAULT
	goto Route201_EventScript_StarterPicked
	end

Route201_EventScript_RivalPickChimchar::
	msgbox Route201_Text_RivalPickChimchar, MSGBOX_DEFAULT
	goto Route201_EventScript_StarterPicked
	end

Route201_EventScript_RivalPickPiplup::
	msgbox Route201_Text_RivalPickPiplup, MSGBOX_DEFAULT
	goto Route201_EventScript_StarterPicked
	end

Route201_EventScript_HelperWaitDawn::
	msgbox Route201_Text_HelperWaitDawn, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	applymovement LOCALID_HELPER, Common_Movement_WalkRight
	waitmovement 0
	msgbox Route201_Text_HelperPassDawn, MSGBOX_SIGN
	return

Route201_EventScript_HelperWaitLucas::
	msgbox Route201_Text_HelperWaitLucas, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	applymovement LOCALID_HELPER, Common_Movement_WalkRight
	waitmovement 0
	msgbox Route201_Text_HelperPassLucas, MSGBOX_SIGN
	return

Route201_EventScript_RivalBattle::
	msgbox Route201_Text_OneThing, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route201_EventScript_BattleDecline
	goto Route201_EventScript_BattleAccept
	
Route201_EventScript_BattleDecline::
	msgbox Route201_Text_ThatAttitude, MSGBOX_DEFAULT
	goto Route201_EventScript_RivalBattle

Route201_EventScript_BattleAccept::
	msgbox Route201_Text_AlwaysWanted, MSGBOX_SIGN
	switch VAR_STARTER_MON
	@ // FODO: Prevent wiping out from resetting event
	@ // Remove 201 state call here and in Route201_EventScript_PostRivalBattle
	setvar VAR_ROUTE201_STATE, 0
	case 0, Route201_EventScript_RivalBattleTurtwig
	case 1, Route201_EventScript_RivalBattleChimchar
	case 2, Route201_EventScript_RivalBattlePiplup
	end

Route201_EventScript_RivalBattleTurtwig::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE_201_TURTWIG, Route201_Text_RivalDefeated
	goto Route201_EventScript_PostRivalBattle
	end

Route201_EventScript_RivalBattleChimchar::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE_201_CHIMCHAR, Route201_Text_RivalDefeated
	goto Route201_EventScript_PostRivalBattle
	end

Route201_EventScript_RivalBattlePiplup::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE_201_PIPLUP, Route201_Text_RivalDefeated
	goto Route201_EventScript_PostRivalBattle
	end

Route201_EventScript_PostRivalBattle::
	msgbox Route201_Text_GoHome, MSGBOX_SIGN
	setvar VAR_ROUTE201_STATE, 2
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
	setvar VAR_LITTLEROOT_INTRO_STATE, 6
	clearflag FLAG_HIDE_ROUTE_201_MAN
	delay 48
	warp MAP_LITTLEROOT_TOWN_BRENDANS_HOUSE_1F, 1, 5
	fadedefaultbgm
	fadescreen FADE_TO_BLACK
	release
	end

Route201_Movement_RivalScurry:
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_in_place_fast_down
	walk_fast_left
	walk_fast_down
	step_end

Route201_EventScript_RivalLake::
	setvar VAR_ROUTE201_STATE, 3
	msgbox Route201_Text_SickOfWaiting, MSGBOX_SIGN
	call_if_eq VAR_0x8004, 1, Route201_EventScript_RivalShift1
	call_if_eq VAR_0x8004, 2, Route201_EventScript_RivalShift2
	call_if_eq VAR_0x8004, 3, Route201_EventScript_RivalShift3
	call_if_eq VAR_0x8004, 4, Route201_EventScript_RivalShift4
	msgbox Route201_Text_NothingToFear, MSGBOX_SIGN
	loadword 0 Route201_EventScript_Rival
	setfollower LOCALID_RIVAL 0x100
	release
	end

Route201_EventScript_Rival::
	facefollower
	goto_if_eq VAR_FOLLOWER_TEXT, 0, Route201_EventScript_RivalTalk1
	goto_if_eq VAR_FOLLOWER_TEXT, 1, Route201_EventScript_RivalTalk2
	goto_if_eq VAR_FOLLOWER_TEXT, 2, Route201_EventScript_RivalTalk3
	goto_if_eq VAR_FOLLOWER_TEXT, 3, Route201_EventScript_RivalTalk4
	goto_if_eq VAR_FOLLOWER_TEXT, 4, Route201_EventScript_RivalTalk5
	goto Route201_EventScript_RivalTalk6


Route201_EventScript_RivalTalk1::
	setvar VAR_FOLLOWER_TEXT, 1
	msgbox Route201_Text_RivalTalk1, MSGBOX_SIGN
	end

Route201_EventScript_RivalTalk2::
	setvar VAR_FOLLOWER_TEXT, 2
	msgbox Route201_Text_RivalTalk2, MSGBOX_SIGN
	end

Route201_EventScript_RivalTalk3::
	setvar VAR_FOLLOWER_TEXT, 3
	msgbox Route201_Text_RivalTalk3, MSGBOX_SIGN
	end

Route201_EventScript_RivalTalk4::
	setvar VAR_FOLLOWER_TEXT, 4
	msgbox Route201_Text_RivalTalk4, MSGBOX_SIGN
	end

Route201_EventScript_RivalTalk5::
	setvar VAR_FOLLOWER_TEXT, 5
	msgbox Route201_Text_RivalTalk5, MSGBOX_SIGN
	end

Route201_EventScript_RivalTalk6::
	setvar VAR_FOLLOWER_TEXT, 6
	msgbox Route201_Text_RivalTalk6, MSGBOX_SIGN
	end

Route201_EventScript_FollowLeave::
	lock
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox Route201_Text_FollowLeave, MSGBOX_SIGN
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	release
	end

Route201_EventScript_FollowGrass::
	lock
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Route201_Text_FollowGrass, MSGBOX_SIGN
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 30
	release
	end

Route201_EventScript_FollowGrass2::
	lock
	goto_if_eq VAR_FACING, DIR_EAST, Route201_EventScript_FollowGrass
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox Route201_Text_FollowGrass, MSGBOX_SIGN
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	release
	end

Route201_EventScript_TipSign::
	msgbox Route201_Text_TipSign, MSGBOX_SIGN
	end

Route201_EventScript_NextRouteSign::
	msgbox Route201_Text_NextRouteSign, MSGBOX_SIGN
	end

Route201_EventScript_BoyTalk::
	msgbox Route201_Text_BoyTalk, MSGBOX_NPC
	end

Route201_EventScript_LassTalk::
	msgbox Route201_Text_LassTalk, MSGBOX_NPC
	end

Route201_EventScript_MartSample::
	goto_if_eq VAR_ROUTE201_STATE, 4, Route201_EventScript_MartSample1
	goto Route201_EventScript_MartSample2
	end

Route201_EventScript_MartSample1::
	lock
	msgbox Route201_Text_MartSample1, MSGBOX_NPC
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Route201_EventScript_BagIsFull
	setvar VAR_ROUTE201_STATE, 5
	release
	end

Route201_EventScript_MartSample2::
	msgbox Route201_Text_MartSample2, MSGBOX_NPC
	end

Route201_EventScript_BagIsFull::
	msgbox gText_TooBadBagIsFull, MSGBOX_DEFAULT
	release
	end

Route201_EventScript_SchoolKidTalk::
	msgbox Route201_Text_SchoolKidTalk, MSGBOX_NPC
	end

Route201_Text_RouteSign:
	.string "{DOWN_ARROW} R.201\n"
	.string "   Twinleaf Town$"

Route201_Text_TooSlow:
	.string "Too slow!$"

Route201_Text_GetMoving:
	.string "{RIVAL}: All right!\n"
	.string "Let's get moving to Prof. Rowan's lab.$"

Route201_Text_DoNotGo:
	.string "{RIVAL}: ...\n"
	.string "...\p"
	.string "What?\n"
	.string "Don't go into the grass, right?\l"
	.string "No worries! No problem!\p"
	.string "It doesn't matter that we don't have\n"
	.string "any Pokémon.\p"
	.string "Trust me on this one.\n"
	.string "I've got an idea!\p"
	.string "Now listen. You know how wild Pokémon\n"
	.string "jump out when you go into tall grass?$"

Route201_Text_ScootOver:
	.string "So, what you do is, you scoot over to\n"
	.string "the next patch of grass before any\l"
	.string "wild Pokémon can appear!\p"
	.string "If we just keep dashing, we can get to\n"
	.string "Sandgem Town without running into\l"
	.string "wild Pokémon!\p"
	.string "OK, stick with me!$"

Route201_Text_HereGoes:
	.string "OK, here goes!\p"
	.string "On your marks...$"

Route201_Text_HoldIt:
	.string "Hold it!$"

Route201_Text_DoNotSeem:
	.string "Professor: You two don't seem to have\n"
	.string "any Pokémon between you?\p"
	.string "Then, what is the meaning of going into\n"
	.string "the tall grass?!\p"
	.string "{RIVAL}: ...\n"
	.string "...\p"
	.string "Professor: ...\n"
	.string "...\p"
	.string "...\n"
	.string "...$"

Route201_Text_ThisOldGuy:
	.string "{RIVAL}: Hey, {PLAYER}.\n"
	.string "This old guy...\p"
	.string "It's Prof. Rowan, isn't it?\n"
	.string "What's he doing here...?$"

Route201_Text_TheyTried:
	.string "Professor: ...\n"
	.string "...\p"
	.string "They tried to go into the tall grass\n"
	.string "because they wanted Pokémon...\p"
	.string "Hmm...\n"
	.string "What to do...?\p"
	.string "Their world would surely change if\n"
	.string "they were to meet Pokémon...\p"
	.string "Is it right for me to put them on that\n"
	.string "path...?\p"
	.string "...\n"
	.string "...$"

Route201_Text_TrulyLove:
	.string "You two.\n"
	.string "You truly love Pokémon, do you?$"

Route201_Text_HoldUp:
	.string "{RIVAL}: Whoa, hold up!\n"
	.string "You're not making any sense here!$"

Route201_Text_DidNotCatch:
	.string "Professor: Er-hem!\p"
	.string "I didn't quite catch that, so I will\n"
	.string "ask you again.$"

Route201_Text_MeToo:
	.string "{RIVAL}: Me, too!\n"
	.string "I love Pokémon, too!\p"
	.string "Professor: I will ask you once again.\p"
	.string "You two.\n"
	.string "You truly love Pokémon, do you?$"

Route201_Text_HundredTimes:
	.string "{RIVAL}: What?!\n"
	.string "You can ask a hundred times!\l"
	.string "The answer will never change!\p"
	.string "We'll both answer a hundred times,\n"
	.string "we love Pokémon!$"

Route201_Text_RightPlayer:
	.string "Right, {PLAYER}?$"

Route201_Text_OldJoke:
	.string "{RIVAL}: ...\n"
	.string "That joke's getting old!$"

Route201_Text_RecklessKids:
	.string "Professor: ...A pair of reckless kids\n"
	.string "who foolishly try to enter tall grass\l"
	.string "without Pokémon of their own...?\p"
	.string "It worries me what people like that\n"
	.string "would do with Pokémon.$"

Route201_Text_FriendHere:
	.string "{RIVAL}: ...Uh..\n"
	.string "Well, I, uh...\p"
	.string "...\n"
	.string "...\p"
	.string "Well, then forget about me, but give\n"
	.string "a Pokémon to my friend here!\p"
	.string "I mean, it was me who tried to go into\n"
	.string "the tall grass and all...\p"
	.string "Professor: !\p"
	.string "How big of you...\p"
	.string "Ver well, then!\n"
	.string "I will entrust you two with Pokémon!\p"
	.string "I apologize for putting you through\n"
	.string "that exercise.\p"
	.string "However!\p"
	.string "You must promise me that you will never\n"
	.string "recklessly endanger yourselves again.\p"
	.string "Now, then...\p"
	.string "Hm?\n"
	.string "Now, where...?$"

Route201_Text_LeftBriefcaseDawn:
	.string "Dawn: Professor Rowan.\p"
	.string "You left your briefcase at the lake!$"

Route201_Text_LeftBriefcaseLucas:
	.string "Lucas: Professor Rowan!\p"
	.string "You left your briefcase behind at\n"
	.string "the lake.$"

Route201_Text_SomethingWrongDawn:
	.string "Is something wrong here?\p"
	.string "Rowan: Ah! There it is!\n"
	.string "Dawn, nice work.\p"
	.string "What I was about to do was to entrust\n"
	.string "these two with their own Pokémon.$"

Route201_Text_SomethingWrongLucas:
	.string "Oh?\n"
	.string "Is something wrong here?\p"
	.string "Rowan: Ah! There it is!\n"
	.string "Lucas, nice work.\p"
	.string "What I was about to do was to entrust\n"
	.string "these two with their own Pokémon.$"

Route201_Text_HardReplaceDawn:
	.string "Dawn: Pardon?!\p"
	.string "Those Pokémon are hard to replace.\n"
	.string "Are you sure about giving them away?\p"
	.string "Rowan: Hm!\p"
	.string "We exist side by side with Pokémon.\p"
	.string "There comes a time when people should\n"
	.string "meet Pokémon.\p"
	.string "There is a world that should be\n"
	.string "explored together.\p"
	.string "For them, today is that time.\n"
	.string "The place, right here.$"

Route201_Text_HardReplaceLucas:
	.string "Lucas: Pardon?!\p"
	.string "Those Pokémon are crucial.\n"
	.string "You're giving them away?\p"
	.string "Rowan: Hm!\p"
	.string "We exist side by side with Pokémon.\p"
	.string "There comes a time when people should\n"
	.string "meet Pokémon.\p"
	.string "There is a world that should be\n"
	.string "explored together.\p"
	.string "For them, today is that time.\n"
	.string "The place, right here.$"

Route201_Text_ChooseYour:
	.string "Go on! Open the briefcase and choose\n"
	.string "a Pokémon!$"

Route201_Text_StraightFace:
	.string "{RIVAL}: Really?!\n"
	.string "Prof. Rowan!\p"
	.string "I can't believe it! I'm so happy now\n"
	.string "that I can't keep a straight face!$"

Route201_Text_SomeClass:
	.string "Hey, {PLAYER}.\n"
	.string "You can choose first.\p"
	.string "Hey, I'm practically a grown-up.\n"
	.string "I have to show some class here.$"

Route201_Text_WhatsUp:
	.string "{RIVAL}: What's up with you?\n"
	.string "Open the briefcase and pick a Pokémon!$"

Route201_Text_RowanChoose:
	.string "Rowan: Go on! Open the briefcase and\n"
	.string "choose a Pokémon!$"

Route201_Text_RivalChoose:
	.string "Hey, {PLAYER}.\n"
	.string "You can choose first. Go ahead.\p"
	.string "You know, like, I'm gonna be a man\n"
	.string "about it. Yeah, I'm slick.$"

Route201_Text_RivalPickTurtwig:
	.string "{RIVAL}: Then, I choose you!\n"
	.string "I'm picking this CHIMCHAR!$"

Route201_Text_RivalPickChimchar:
	.string "{RIVAL}: Then, I choose you!\n"
	.string "I'm picking this PIPLUP!$"

Route201_Text_RivalPickPiplup:
	.string "{RIVAL}: Then, I choose you!\n"
	.string "I'm picking this TURTWIG!$"

Route201_Text_ChosenGood:
	.string "Rowan: Very well! Both of you have\n"
	.string "chosen a good Pokémon, it seems.\p"
	.string "Now, listen well!\p"
	.string "The Pokémon you have been entrusted\n"
	.string "with are unfamiliar with the world.\p"
	.string "In that regard, they're much\n"
	.string "like you.\p"
	.string "As fellow newcomers to the world,\n"
	.string "I hope you'll do well together.\p"
	.string "If you have any trouble, come see me\n"
	.string "at my lab in Sandgem Town.\p"
	.string "And now, we'll be on our way.$"

Route201_Text_HelperWaitDawn:
	.string "Dawn: Professor!\n"
	.string "Wait for me, please!$"

Route201_Text_HelperWaitLucas:
	.string "Lucas: Professor!\n"
	.string "Wait for me!$"

Route201_Text_HelperPassDawn:
	.string "I'm sorry...\n"
	.string "Please let me pass.$"

Route201_Text_HelperPassLucas:
	.string "Uh, sorry folks.$"

Route201_Text_ReallyNice:
	.string "{RIVAL}: How do you like that?\n"
	.string "Prof. Rowan's really nice.\p"
	.string "On TV, he seems so stern and scary.$"

Route201_Text_OneThing:
	.string "Heheh, {PLAYER}!\n"
	.string "We've both got Pokémon now.\p"
	.string "There's only one thing to do, right\n"
	.string "Are you up for this?$"

Route201_Text_ThatAttitude:
	.string "{RIVAL}: What's with that attitude?\n"
	.string "Don't be that way!$"

Route201_Text_AlwaysWanted:
	.string "{RIVAL}: I've always wanted to\n"
	.string "say this...\p"
	.string "The time has finally come!\p"
	.string "{PLAYER}!\n"
	.string "I challenge you to a battle!$"

Route201_Text_RivalDefeated:
	.string "What are you saying?!\n"
	.string "We ended up losing?!$"

Route201_Text_GoHome:
	.string "{RIVAL}: Whew!\n"
	.string "Let's go home.\p"
	.string "I'm beat after that battle.\n"
	.string "My Pokémon needs rest, too.\p"
	.string "See ya, {PLAYER}!$"

Route201_Text_SickOfWaiting:
	.string "{RIVAL}: Too slow!\n"
	.string "{PLAYER}, I'm sick of waiting!\p"
	.string "I'm going to see Prof. Rowan so I\n"
	.string "can thank him properly.\p"
	.string "So, I had this great idea.\n"
	.string "Listen up, OK?\p"
	.string "You know that lake where we always\n"
	.string "play at?\p"
	.string "You know how they say a legendary\n"
	.string "Pokémon lives there?\p"
	.string "You guessed it!\n"
	.string "Let's catch that Pokémon.\p"
	.string "That'll make Prof. Rowan happy.\n"
	.string "I'm sure of that!$"

Route201_Text_NothingToFear:
	.string "{RIVAL}: Me and you together,\n"
	.string "we've got nothing to fear!$"

Route201_Text_RivalTalk1:
	.string "{RIVAL}: That Pokémon battle...\p"
	.string "Wasn't that wickedly fun or what?\p"
	.string "I mean, I'd pick the moves, and my\n"
	.string "Pokémon would use them!\p"
	.string "Yeah, I'm going to battle tons and get\n"
	.string "real close with Pokémon.$"

Route201_Text_RivalTalk2:
	.string "{RIVAL}: Pokémon all have\n"
	.string "different moves, huh?\p"
	.string "A Trainer makes his Pokémon battle\n"
	.string "by ordering them to use moves.\p"
	.string "That's so awesomely cool.$"
	
Route201_Text_RivalTalk3:
	.string "{RIVAL}: Do you believe it?\n"
	.string "I can hardly believe it.\p"
	.string "You and me, we're Pokémon Trainers all\n"
	.string "of a sudden.\p"
	.string "Man, we've got tons to learn about\n"
	.string "being a Trainer.\p"
	.string "But seeing this Poké Ball with this\n"
	.string "CHIMCHAR inside...\p"
	.string "It makes me feel like I can do anything!\n"
	.string "Nothing's impossible!$"
	
Route201_Text_RivalTalk4:
	.string "{RIVAL}: That lake has a mirage\n"
	.string "Pokémon living in it.\p"
	.string "Everyone says it's just a legend, but\n"
	.string "I know I'm right.$"
	
Route201_Text_RivalTalk5:
	.string "{RIVAL}: Hey, do you know about\n"
	.string "the Champion?\p"
	.string "There's this out-of-this-world tough\n"
	.string "Trainer who gets called that.\p"
	.string "Well, I'm gonna get so tough, the Champ\n"
	.string "has to battle me. You watch!\p"
	.string "With this little guy here, I'm sure I can\n"
	.string "get that tough.$"
	
Route201_Text_RivalTalk6:
	.string "{RIVAL}: Hey, that's enough\n"
	.string "talking already.\p"
	.string "I'm itching to get going to the  lake.\n"
	.string "Come on, come on!$"

Route201_Text_FollowLeave:
	.string "{RIVAL}: Heheh, {PLAYER}.\n"
	.string "The lake's not that way!$"

Route201_Text_FollowGrass:
	.string "{RIVAL}: Hey, {PLAYER}!\n"
	.string "I said, the lake's not that way!$"

Route201_Text_TipSign:
	.string "Trainer Tips!\p"
	.string "Don't be shy! Talk to anyone and\n"
	.string "everyone you happen to see.\p"
	.string "By talking to people, you will get\n"
	.string "invaluable information and advice.$"

Route201_Text_NextRouteSign:
	.string "{RIGHT_ARROW} Rt.201\n"
	.string "   Sandgem Town$"

Route201_Text_BoyTalk:
	.string "Wild Pokémon lurk in tall grass. They\n"
	.string "can come bursting out at any time.\p"
	.string "So, if you're wanting to battle wild\n"
	.string "Pokémon, just walk in tall grass.\p"
	.string "If you want to avoid wild Pokémon,\n"
	.string "then stay out of the tall grass.$"
	
Route201_Text_LassTalk:
	.string "If your Pokémon's health--that's its\n"
	.string "HP--is getting low, you should go\l"
	.string "home and get some rest.$"

Route201_Text_MartSample1:
	.string "Hi!\n"
	.string "I work at a Pokémon Mart.\p"
	.string "Did you know that a Pokémon's health\n"
	.string "is measured by Hit Pointer (HP)?\p"
	.string "If a Pokémon runs out of HP, it\n"
	.string "faints and can't battle anymore.\p"
	.string "If a Pokémon's HP gets low, you\n"
	.string "should heal it with a Potion.\p"
	.string "Here, let me give you a Potion as\n"
	.string "a free sample. First one's free!\p"
	.string "It will automatically go in the\n"
	.string "Medicine Pocket of your Bag.$"

Route201_Text_MartSample2:
	.string "You can find a Pokémon Mart in\n"
	.string "cities and most major towns.$"

Route201_Text_SchoolKidTalk:
	.string "That ledge is one way. Jump down\n"
	.string "for a shortcut to Twinleaf Town!$"
