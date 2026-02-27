JubilifeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, JubilifeCity_OnTransition
	.byte 0

@ State descriptions For VAR_JUBILIFE_CITY_STATE
@ 1: Encountered helper
@ 2: Received Town Map
@ 3: Talked to Poketch Man
@ 3: Received Poketch
@ 4: Received Coal Badge

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
	msgbox JubilifeCity_Text_Um, MSGBOX_DEFAULT
	applymovement LOCALID_JUBILIFE_LOOKER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_JUBILIFE_LOOKER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	msgbox JubilifeCity_Text_HowDidYouKnow, MSGBOX_SIGN
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox JubilifeCity_Text_BegYourPardon, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, JubilifeCity_EventScript_LookerYes
	call_if_eq VAR_RESULT, NO, JubilifeCity_EventScript_LookerNo
	msgbox JubilifeCity_Text_DoNotHeed, MSGBOX_DEFAULT
	@ FODO: Implement and give Vs. Recorder item
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox JubilifeCity_Text_NiftyDevice, MSGBOX_SIGN
	applymovement LOCALID_JUBILIFE_LOOKER, JubilifeCity_Movement_LookAround
	waitmovement 0
	msgbox JubilifeCity_Text_HaveRequest, MSGBOX_SIGN
	applymovement LOCALID_JUBILIFE_HELPER, JubilifeCity_Movement_HelperWatchLooker
	applymovement LOCALID_PLAYER, JubilifeCity_Movement_PlayerWatchLooker
	applymovement LOCALID_JUBILIFE_LOOKER, JubilifeCity_Movement_LookerScurry3
	waitmovement 0
	closemessage
	delay 48
	msgbox JubilifeCity_Text_WorkingInternational, MSGBOX_SIGN
	delay 48
	applymovement LOCALID_PLAYER, JubilifeCity_Movement_PlayerSeeSchool
	applymovement LOCALID_JUBILIFE_HELPER, JubilifeCity_Movement_HelperSeeSchool
	waitmovement 0
	msgbox JubilifeCity_Text_HereItIs, MSGBOX_SIGN
	applymovement LOCALID_JUBILIFE_HELPER, JubilifeCity_Movement_HelperLeaveSchool
	waitmovement 0
	msgbox JubilifeCity_Text_SawYourFriend, MSGBOX_SIGN
	applymovement LOCALID_PLAYER, JubilifeCity_Movement_PlayerWatchHelper
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_WalkDown6
	waitmovement 0
	setflag FLAG_HIDE_JUBILIFE_LOOKER
	setflag FLAG_HIDE_JUBILIFE_HELPER
	removeobject LOCALID_JUBILIFE_LOOKER
	removeobject LOCALID_JUBILIFE_HELPER
	special RemoveCameraObject
	end

JubilifeCity_EventScript_LookerYes::
	msgbox JubilifeCity_Text_ThatIsCorrect, MSGBOX_DEFAULT
	return

JubilifeCity_EventScript_LookerNo::
	msgbox JubilifeCity_Text_ClaimNotKnow, MSGBOX_DEFAULT
	return
	
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

JubilifeCity_Movement_LookerScurry3:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_in_place_left
	delay_16
	delay_16
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

JubilifeCity_Movement_LookAround:
	walk_in_place_left
	delay_16
	walk_in_place_right
	delay_16
	delay_16
	walk_in_place_down
	step_end

JubilifeCity_Movement_PlayerMeetLooker:
	walk_up
	walk_up
	walk_right
	walk_up
	step_end

JubilifeCity_Movement_PlayerWatchLooker:
	delay_16
	walk_in_place_right
	delay_16
	delay_16
	walk_in_place_up
	step_end

JubilifeCity_Movement_HelperWatchLooker:
	walk_in_place_right
	delay_16
	delay_16
	delay_16
	walk_in_place_up
	step_end

JubilifeCity_Movement_PlayerSeeSchool:
	delay_16
	walk_in_place_left
	step_end

JubilifeCity_Movement_HelperSeeSchool:
	walk_down
	walk_left
	walk_left
	step_end

JubilifeCity_Movement_HelperLeaveSchool:
	walk_up
	walk_right
	walk_right
	step_end

JubilifeCity_Movement_PlayerWatchHelper:
	delay_16
	walk_in_place_down
	step_end

JubilifeCity_EventScript_Looker::
	goto_if_eq VAR_JUBILIFE_CITY_STATE, 2, JubilifeCity_EventScript_Looker2
	msgbox JubilifeCity_Text_HaveNoFearSchool, MSGBOX_NPC
	end

JubilifeCity_EventScript_Looker2::
	msgbox JubilifeCity_Text_HaveNoFearPoketch, MSGBOX_NPC
	end

JubilifeCity_EventScript_LookerBlockApproach::
	playse SE_PIN
	applymovement LOCALID_JUBILIFE_LOOKER_2, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

JubilifeCity_EventScript_LookerBlockExplainSchool::
	msgbox JubilifeCity_Text_HelloMyFriend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	applymovement LOCALID_JUBILIFE_LOOKER_2, JubilifeCity_Movement_LookerWalkBack
	waitmovement 0
	delay 16
	return

JubilifeCity_EventScript_LookerBlockExplainSchoolPanLeft::
	msgbox JubilifeCity_Text_HelloMyFriend, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAMERA, Common_Movement_WalkLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	applymovement LOCALID_JUBILIFE_LOOKER_2, JubilifeCity_Movement_LookerWalkBack
	waitmovement 0
	delay 16
	return

JubilifeCity_EventScript_LookerBlockExplainPoketch::
	msgbox JubilifeCity_Text_TellMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	applymovement LOCALID_JUBILIFE_LOOKER_2, JubilifeCity_Movement_LookerWalkBack
	waitmovement 0
	delay 16
	return

JubilifeCity_EventScript_LookerBlockExplainPoketchPanLeft::
	msgbox JubilifeCity_Text_TellMe, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_CAMERA, Common_Movement_WalkLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	applymovement LOCALID_JUBILIFE_LOOKER_2, JubilifeCity_Movement_LookerWalkBack
	waitmovement 0
	delay 16
	return

JubilifeCity_EventScript_LookerBlockSchool1::
	lock
	call JubilifeCity_EventScript_LookerBlockApproach
	applymovement LOCALID_JUBILIFE_LOOKER_2, JubilifeCity_Movement_LookerApproach1
	waitmovement 0
	call JubilifeCity_EventScript_LookerBlockExplainSchool
	applymovement LOCALID_JUBILIFE_LOOKER_2, JubilifeCity_Movement_LookerReturn1
	waitmovement 0
	release
	end

JubilifeCity_EventScript_LookerBlockSchool2::
	lock
	call JubilifeCity_EventScript_LookerBlockApproach
	applymovement LOCALID_JUBILIFE_LOOKER_2, JubilifeCity_Movement_LookerApproach2
	waitmovement 0
	call JubilifeCity_EventScript_LookerBlockExplainSchool
	applymovement LOCALID_JUBILIFE_LOOKER_2, JubilifeCity_Movement_LookerReturn2
	waitmovement 0
	release
	end

JubilifeCity_EventScript_LookerBlockSchool3::
	lock
	call JubilifeCity_EventScript_LookerBlockApproach
	applymovement LOCALID_JUBILIFE_LOOKER_2, JubilifeCity_Movement_LookerApproach3
	waitmovement 0
	call JubilifeCity_EventScript_LookerBlockExplainSchool
	applymovement LOCALID_JUBILIFE_LOOKER_2, JubilifeCity_Movement_LookerReturn3
	waitmovement 0
	release
	end

JubilifeCity_EventScript_LookerBlockSchool4::
	lock
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp
	waitmovement 0
	call JubilifeCity_EventScript_LookerBlockApproach
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown
	applymovement LOCALID_JUBILIFE_LOOKER_2, JubilifeCity_Movement_LookerApproach4
	waitmovement 0
	call JubilifeCity_EventScript_LookerBlockExplainSchoolPanLeft
	applymovement LOCALID_JUBILIFE_LOOKER_2, JubilifeCity_Movement_LookerReturn4
	waitmovement 0
	special RemoveCameraObject
	release
	end

JubilifeCity_EventScript_LookerBlockPoketch1::
	lock
	call JubilifeCity_EventScript_LookerBlockApproach
	applymovement LOCALID_JUBILIFE_LOOKER_2, JubilifeCity_Movement_LookerApproach1
	waitmovement 0
	call JubilifeCity_EventScript_LookerBlockExplainPoketch
	applymovement LOCALID_JUBILIFE_LOOKER_2, JubilifeCity_Movement_LookerReturn1
	waitmovement 0
	release
	end

JubilifeCity_EventScript_LookerBlockPoketch2::
	lock
	call JubilifeCity_EventScript_LookerBlockApproach
	applymovement LOCALID_JUBILIFE_LOOKER_2, JubilifeCity_Movement_LookerApproach2
	waitmovement 0
	call JubilifeCity_EventScript_LookerBlockExplainPoketch
	applymovement LOCALID_JUBILIFE_LOOKER_2, JubilifeCity_Movement_LookerReturn2
	waitmovement 0
	release
	end

JubilifeCity_EventScript_LookerBlockPoketch3::
	lock
	call JubilifeCity_EventScript_LookerBlockApproach
	applymovement LOCALID_JUBILIFE_LOOKER_2, JubilifeCity_Movement_LookerApproach3
	waitmovement 0
	call JubilifeCity_EventScript_LookerBlockExplainPoketch
	applymovement LOCALID_JUBILIFE_LOOKER_2, JubilifeCity_Movement_LookerReturn3
	waitmovement 0
	release
	end

JubilifeCity_EventScript_LookerBlockPoketch4::
	lock
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp
	waitmovement 0
	call JubilifeCity_EventScript_LookerBlockApproach
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown
	applymovement LOCALID_JUBILIFE_LOOKER_2, JubilifeCity_Movement_LookerApproach4
	waitmovement 0
	call JubilifeCity_EventScript_LookerBlockExplainPoketchPanLeft
	applymovement LOCALID_JUBILIFE_LOOKER_2, JubilifeCity_Movement_LookerReturn4
	waitmovement 0
	special RemoveCameraObject
	release
	end

JubilifeCity_Movement_LookerWalkBack:
	lock_facing_direction
	walk_left
	unlock_facing_direction
	step_end

JubilifeCity_Movement_LookerApproach1:
	walk_down
	walk_right
	step_end

JubilifeCity_Movement_LookerApproach2:
	walk_down
	walk_down
	walk_right
	step_end

JubilifeCity_Movement_LookerApproach3:
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

JubilifeCity_Movement_LookerApproach4:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	step_end

JubilifeCity_Movement_LookerReturn1:
	walk_up
	walk_in_place_down
	step_end

JubilifeCity_Movement_LookerReturn2:
	walk_up
	walk_up
	walk_in_place_down
	step_end

JubilifeCity_Movement_LookerReturn3:
	walk_up
	walk_up
	walk_up
	walk_in_place_down
	step_end

JubilifeCity_Movement_LookerReturn4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_down
	step_end

JubilifeCity_EventScript_TerminalGuard1::
	lock
	call JubilifeCity_EventScript_TerminalGuardExclaim
	applymovement LOCALID_TERMINAL_GUARD, JubilifeCity_Movement_TerminalGuard_Enter1
	waitmovement 0
	msgbox JubilifeCity_Text_GlobalTerminalClosed, MSGBOX_SIGN
	call JubilifeCity_EventScript_TerminalGuardPush
	applymovement LOCALID_TERMINAL_GUARD, JubilifeCity_Movement_TerminalGuard_Leave1
	waitmovement 0
	delay 48
	release
	end

JubilifeCity_EventScript_TerminalGuard2::
	lock
	call JubilifeCity_EventScript_TerminalGuardExclaim
	applymovement LOCALID_TERMINAL_GUARD, JubilifeCity_Movement_TerminalGuard_Enter2
	waitmovement 0
	msgbox JubilifeCity_Text_GlobalTerminalClosed, MSGBOX_SIGN
	call JubilifeCity_EventScript_TerminalGuardPush
	applymovement LOCALID_TERMINAL_GUARD, JubilifeCity_Movement_TerminalGuard_Leave2
	waitmovement 0
	delay 48
	release
	end

JubilifeCity_EventScript_TerminalGuard3::
	lock
	call JubilifeCity_EventScript_TerminalGuardExclaim
	applymovement LOCALID_TERMINAL_GUARD, JubilifeCity_Movement_TerminalGuard_Enter3
	waitmovement 0
	msgbox JubilifeCity_Text_GlobalTerminalClosed, MSGBOX_SIGN
	call JubilifeCity_EventScript_TerminalGuardPush
	applymovement LOCALID_TERMINAL_GUARD, JubilifeCity_Movement_TerminalGuard_Leave3
	waitmovement 0
	delay 48
	release
	end

JubilifeCity_EventScript_TerminalGuard4::
	lock
	call JubilifeCity_EventScript_TerminalGuardExclaim
	applymovement LOCALID_TERMINAL_GUARD, JubilifeCity_Movement_TerminalGuard_Enter4
	waitmovement 0
	msgbox JubilifeCity_Text_GlobalTerminalClosed, MSGBOX_SIGN
	call JubilifeCity_EventScript_TerminalGuardPush
	applymovement LOCALID_TERMINAL_GUARD, JubilifeCity_Movement_TerminalGuard_Leave4
	waitmovement 0
	delay 48
	release
	end
	
JubilifeCity_EventScript_TerminalGuardExclaim::
	playse SE_PIN
	applymovement LOCALID_TERMINAL_GUARD, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	return

JubilifeCity_EventScript_TerminalGuardPush::
	applymovement LOCALID_TERMINAL_GUARD, Common_Movement_WalkRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	delay 48
	return

JubilifeCity_EventScript_TerminalGuardOpen::
	msgbox JubilifeCity_Text_GlobalTerminalOpen, MSGBOX_NPC
	end

JubilifeCity_Movement_TerminalGuard_Enter1:
	walk_down
	walk_in_place_right
	step_end
	
JubilifeCity_Movement_TerminalGuard_Enter2:
	walk_down
	walk_down
	walk_in_place_right
	step_end
	
JubilifeCity_Movement_TerminalGuard_Enter3:
	walk_down
	walk_down
	walk_down
	walk_in_place_right
	step_end
	
JubilifeCity_Movement_TerminalGuard_Enter4:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_in_place_right
	step_end

JubilifeCity_Movement_TerminalGuard_Leave1:
	walk_up
	walk_in_place_down
	step_end
	
JubilifeCity_Movement_TerminalGuard_Leave2:
	walk_up
	walk_up
	walk_in_place_down
	step_end
	
JubilifeCity_Movement_TerminalGuard_Leave3:
	walk_up
	walk_up
	walk_up
	walk_in_place_down
	step_end
	
JubilifeCity_Movement_TerminalGuard_Leave4:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_in_place_down
	step_end

JubilifeCity_EventScript_ClownStickAround::
	msgbox JubilifeCity_Text_ClownStickAround, MSGBOX_DEFAULT
	release
	end

JubilifeCity_EventScript_WrongAnswer::
	msgbox JubilifeCity_Text_ClownWrongAnswer, MSGBOX_DEFAULT
	release
	end

JubilifeCity_EventScript_ClownGrow::
	lock
	faceplayer
	goto_if_eq VAR_JUBILIFE_CITY_STATE, 1, JubilifeCity_EventScript_ClownStickAround
	goto_if_set FLAG_JUBILIFE_CLOWN_GROW, JubilifeCity_EventScript_ClownGrowDone
	msgbox JubilifeCity_Text_ClownGrowQuestion, MSGBOX_YESNO
	@ FODO: Play incorrect answer sound
	goto_if_eq VAR_RESULT, NO, JubilifeCity_EventScript_WrongAnswer
	@ FODO: Play correct answer sound
	msgbox JubilifeCity_Text_ClownGrowExplain, MSGBOX_DEFAULT
	@ FODO: Implement Poketch ticket system
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_JUBILIFE_CLOWN_GROW
	release
	end

JubilifeCity_EventScript_ClownGrowDone::
	msgbox JubilifeCity_Text_ClownGrowDone, MSGBOX_DEFAULT
	release
	end

JubilifeCity_EventScript_ClownItem::
	lock
	faceplayer
	goto_if_eq VAR_JUBILIFE_CITY_STATE, 1, JubilifeCity_EventScript_ClownStickAround
	goto_if_set FLAG_JUBILIFE_CLOWN_ITEM, JubilifeCity_EventScript_ClownItemDone
	msgbox JubilifeCity_Text_ClownItemQuestion, MSGBOX_YESNO
	@ FODO: Play incorrect answer sound
	goto_if_eq VAR_RESULT, NO, JubilifeCity_EventScript_WrongAnswer
	@ FODO: Play correct answer sound
	msgbox JubilifeCity_Text_ClownItemExplain, MSGBOX_DEFAULT
	@ FODO: Implement Poketch ticket system
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_JUBILIFE_CLOWN_ITEM
	release
	end

JubilifeCity_EventScript_ClownItemDone::
	msgbox JubilifeCity_Text_ClownItemDone, MSGBOX_DEFAULT
	release
	end

JubilifeCity_EventScript_ClownType::
	lock
	faceplayer
	goto_if_eq VAR_JUBILIFE_CITY_STATE, 1, JubilifeCity_EventScript_ClownStickAround
	goto_if_set FLAG_JUBILIFE_CLOWN_TYPE, JubilifeCity_EventScript_ClownTypeDone
	msgbox JubilifeCity_Text_ClownTypeQuestion, MSGBOX_YESNO
	@ FODO: Play incorrect answer sound
	goto_if_eq VAR_RESULT, NO, JubilifeCity_EventScript_WrongAnswer
	@ FODO: Play correct answer sound
	msgbox JubilifeCity_Text_ClownTypeExplain, MSGBOX_DEFAULT
	@ FODO: Implement Poketch ticket system
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_JUBILIFE_CLOWN_TYPE
	release
	end

JubilifeCity_EventScript_ClownTypeDone::
	msgbox JubilifeCity_Text_ClownTypeDone, MSGBOX_DEFAULT
	release
	end

JubilifeCity_EventScript_PoketchGreet::
	lock
	faceplayer
	setvar VAR_JUBILIFE_CITY_STATE, 3
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp2
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	applymovement LOCALID_POKETCH_NPC, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_POKETCH_NPC, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	return

JubilifeCity_EventScript_PoketchPromote::
	msgbox JubilifeCity_Text_Poketch_Promotion, MSGBOX_DEFAULT
	release
	special RemoveCameraObject
	end

JubilifeCity_EventScript_PoketchMeet1::
	call JubilifeCity_EventScript_PoketchGreet
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
	applymovement LOCALID_POKETCH_NPC, JubilifeCity_Movement_PoketchMan_Approach1
	waitmovement 0
	call JubilifeCity_EventScript_PoketchPromote
	end

JubilifeCity_EventScript_PoketchMeet2::
	call JubilifeCity_EventScript_PoketchGreet
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
	applymovement LOCALID_POKETCH_NPC, JubilifeCity_Movement_PoketchMan_Approach2
	waitmovement 0
	call JubilifeCity_EventScript_PoketchPromote
	end

JubilifeCity_EventScript_PoketchMeet3::
	call JubilifeCity_EventScript_PoketchGreet
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
	applymovement LOCALID_POKETCH_NPC, JubilifeCity_Movement_PoketchMan_Approach3
	waitmovement 0
	call JubilifeCity_EventScript_PoketchPromote
	end

JubilifeCity_EventScript_PoketchMeet4::
	call JubilifeCity_EventScript_PoketchGreet
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
	applymovement LOCALID_POKETCH_NPC, JubilifeCity_Movement_PoketchMan_Approach4
	waitmovement 0
	call JubilifeCity_EventScript_PoketchPromote
	end

JubilifeCity_EventScript_PoketchMeet5::
	call JubilifeCity_EventScript_PoketchGreet
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown2
	applymovement LOCALID_POKETCH_NPC, JubilifeCity_Movement_PoketchMan_Approach5
	waitmovement 0
	call JubilifeCity_EventScript_PoketchPromote
	end

JubilifeCity_EventScript_PoketchExplain::
	goto_if_set FLAG_JUBILIFE_CLOWN_GROW, JubilifeCity_EventScript_PoketchCheck1
	msgbox JubilifeCity_Text_Poketch_Explain, MSGBOX_NPC
	end

JubilifeCity_EventScript_PoketchCheck1::
	goto_if_set FLAG_JUBILIFE_CLOWN_ITEM, JubilifeCity_EventScript_PoketchCheck2
	msgbox JubilifeCity_Text_Poketch_Explain, MSGBOX_NPC
	end

JubilifeCity_EventScript_PoketchCheck2::
	goto_if_set FLAG_JUBILIFE_CLOWN_TYPE, JubilifeCity_EventScript_PoketchCheck3
	msgbox JubilifeCity_Text_Poketch_Explain, MSGBOX_NPC
	end

JubilifeCity_EventScript_PoketchCheck3::
	lock
	faceplayer
	msgbox JubilifeCity_Text_Poketch_Count, MSGBOX_DEFAULT
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox JubilifeCity_Text_Poketch_Leave, MSGBOX_DEFAULT
	closemessage
	goto_if_eq VAR_FACING, DIR_NORTH, JubilifeCity_EventScript_PoketchLeaveNorth
	goto_if_eq VAR_FACING, DIR_SOUTH, JubilifeCity_EventScript_PoketchLeaveSouth
	applymovement LOCALID_PLAYER, JubilifeCity_Movement_Player_WatchPoketchMan
	applymovement LOCALID_POKETCH_NPC, Common_Movement_Walk_Up6
	waitmovement 0
	setflag FLAG_HIDE_JUBILIFE_POKETCH
	setflag FLAG_HIDE_JUBILIFE_LOOKER_2
	removeobject LOCALID_POKETCH_NPC
	release
	end

JubilifeCity_EventScript_PoketchLeaveNorth::
	applymovement LOCALID_POKETCH_NPC, Common_Movement_Walk_Up5
	waitmovement 0
	setflag FLAG_HIDE_JUBILIFE_POKETCH
	setflag FLAG_HIDE_JUBILIFE_LOOKER_2
	removeobject LOCALID_POKETCH_NPC
	release
	end

JubilifeCity_EventScript_PoketchLeaveSouth::
	applymovement LOCALID_PLAYER, JubilifeCity_Movement_Player_WatchPoketchMan2
	applymovement LOCALID_POKETCH_NPC, JubilifeCity_Movement_PoketchMan_LeaveSouth
	waitmovement 0
	setflag FLAG_HIDE_JUBILIFE_POKETCH
	setflag FLAG_HIDE_JUBILIFE_LOOKER_2
	removeobject LOCALID_POKETCH_NPC
	release
	end

JubilifeCity_Movement_PoketchMan_Approach1:
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	step_end

JubilifeCity_Movement_PoketchMan_Approach2:
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	step_end

JubilifeCity_Movement_PoketchMan_Approach3:
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

JubilifeCity_Movement_PoketchMan_Approach4:
	walk_down
	walk_down
	walk_right
	walk_down
	walk_down
	step_end

JubilifeCity_Movement_PoketchMan_Approach5:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	step_end

JubilifeCity_Movement_PoketchMan_LeaveSouth:
	walk_left
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

JubilifeCity_Movement_Player_WatchPoketchMan:
	delay_16
	walk_in_place_up
	step_end

JubilifeCity_Movement_Player_WatchPoketchMan2:
	delay_16
	walk_in_place_left
	delay_16
	walk_in_place_up
	step_end

JubilifeCity_EventScript_BoyTradingLeft::
	msgbox JubilifeCity_Text_TradingWithBuddy, MSGBOX_NPC
	end

JubilifeCity_EventScript_BoyTradingRight::
	msgbox JubilifeCity_Text_HoldAnItem, MSGBOX_NPC
	end

JubilifeCity_EventScript_OldManSchool::
	lock
	faceplayer
	msgbox JubilifeCity_Text_HelloTrainer, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, JubilifeCity_EventScript_OldManSchoolYes
	call_if_eq VAR_RESULT, NO, JubilifeCity_EventScript_OldManSchoolNo
	end

JubilifeCity_EventScript_OldManSchoolYes::
	msgbox JubilifeCity_Text_YouAreKnowledgeable, MSGBOX_SIGN
	return

JubilifeCity_EventScript_OldManSchoolNo::
	msgbox JubilifeCity_Text_NotToWorry, MSGBOX_SIGN
	return

JubilifeCity_EventScript_SchoolKid::
	msgbox JubilifeCity_Text_SixBalls, MSGBOX_NPC
	end

JubilifeCity_EventScript_OldManFountain::
	msgbox JubilifeCity_Text_CarvedOfMountain, MSGBOX_NPC
	end

JubilifeCity_EventScript_AceTrainer1::
	msgbox JubilifeCity_Text_WhereComeFrom, MSGBOX_NPC
	end

JubilifeCity_EventScript_AceTrainerGroup::
	lock
	faceplayer
	msgbox JubilifeCity_Text_JoinGroup, MSGBOX_DEFAULT
	goto JubilifeCity_EventScript_AceTrainerGroupPrompt
	end

JubilifeCity_EventScript_AceTrainerGroupPrompt::
	multichoice 0, 0, MULTI_JUBILIFE_CITY_GROUP, FALSE
	switch VAR_RESULT
	case 0, JubilifeCity_EventScript_JoinGroupYes
	case 1, JubilifeCity_EventScript_JoinGroupInfo
	case 2, JubilifeCity_EventScript_JoinGroupNo
	goto JubilifeCity_EventScript_JoinGroupNo
	end

JubilifeCity_EventScript_JoinGroupYes::
	@ FODO: Add text input for group name
	msgbox JubilifeCity_Text_NameYourGroup, MSGBOX_SIGN
	end

JubilifeCity_EventScript_JoinGroupInfo::
	msgbox JubilifeCity_Text_WhenYouForm, MSGBOX_DEFAULT
	goto JubilifeCity_EventScript_AceTrainerGroupPrompt
	return

JubilifeCity_EventScript_JoinGroupNo::
	msgbox JubilifeCity_Text_ThatsTooBad, MSGBOX_SIGN
	return

JubilifeCity_EventScript_Twin::
	msgbox JubilifeCity_Text_SeeMeOnTV, MSGBOX_NPC
	end

JubilifeCity_EventScript_AceTrainer2::
	msgbox JubilifeCity_Text_WalkWithPokemon, MSGBOX_NPC
	end

JubilifeCity_EventScript_TownSign::
	msgbox JubilifeCity_Text_TownSign, MSGBOX_SIGN
	end

JubilifeCity_EventScript_TrainerSchoolSign::
	msgbox JubilifeCity_Text_TrainerSchoolSign, MSGBOX_SIGN
	end

JubilifeCity_EventScript_CondominiumSign::
	msgbox JubilifeCity_Text_CondominiumSign, MSGBOX_SIGN
	end

JubilifeCity_EventScript_JubilifeTVSign::
	msgbox JubilifeCity_Text_JubilifeTVSign, MSGBOX_SIGN
	end

JubilifeCity_EventScript_PoketchCompanySign::
	msgbox JubilifeCity_Text_PoketchCompanySign, MSGBOX_SIGN
	end

JubilifeCity_Text_AreYouCatching:
	.string "Dawn: Hi, {PLAYER}!\n"
	.string "Are you catching Pokémon?$"

JubilifeCity_Text_HowManyCaught:
	.string "Lucas: Hey, {PLAYER}!\n"
	.string "How many Pokémon have you caught?$"
	
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
	.string "raising a lot of Pokémon...\p"
	.string "But it's worth it. The more Pokémon\n"
	.string "you have, the happier you'll be.$"

JubilifeCity_Text_AlreadyGot4:
	.string "Wow! You've already got 4 Pokémon\n"
	.string "with you!\p"
	.string "At that pace, your Pokédex should\n"
	.string "be full in non time at all!$"

JubilifeCity_Text_AlreadyGot5:
	.string "Wow! You've already got 5 Pokémon\n"
	.string "with you!\p"
	.string "At that pace, your Pokédex should\n"
	.string "be full in non time at all!$"

JubilifeCity_Text_AlreadyGot6:
	.string "Wow! You've already got 6 Pokémon\n"
	.string "with you!\p"
	.string "At that pace, your Pokédex should\n"
	.string "be full in non time at all!$"

JubilifeCity_Text_AlreadyHave4:
	.string "Whoa! You already have 4 Pokémon\n"
	.string "with you!$"

JubilifeCity_Text_AlreadyHave5:
	.string "Whoa! You already have 5 Pokémon\n"
	.string "with you!$"

JubilifeCity_Text_AlreadyHave6:
	.string "Whoa! You already have 6 Pokémon\n"
	.string "with you!$"

JubilifeCity_Text_DawnKnowMore:
	.string "Oh, I know! Don't you think it's\n"
	.string "better to know more about Pokémon?\p"
	.string "Sure it is!\n"
	.string "I know just the place.\p"
	.string "Come on!\n"
	.string "Don't be shy. Follow me!$"

JubilifeCity_Text_LucasKnowMore:
	.string "Hey, that's right! Don't you think it's\n"
	.string "better to know more about Pokémon?\p"
	.string "Sure it is!\n"
	.string "There's this great place for that.\p"
	.string "Come on! It's all right.\n"
	.string "Follow me.$"

JubilifeCity_Text_ThatMan:
	.string "Dawn: That man...\n"
	.string "What is he doing?$"

JubilifeCity_Text_Um:
	.string "Dawn: Um...$"

JubilifeCity_Text_HowDidYouKnow:
	.string "WHAAAT?!\p"
	.string "Mysterious man: ...How did you know?\p"
	.string "How did you unmask me as a member of\n"
	.string "the International Police?!$"

JubilifeCity_Text_BegYourPardon:
	.string "Dawn: Huh? What? I beg your pardon?\n"
	.string "I was just making conversation...\p"
	.string "Shady man: ...Heh. You claim you were\n"
	.string "only making conversation, do you?\p"
	.string "But I know better not to believe that.\n"
	.string "No, no, no.\p"
	.string "You recognized right away that I was\n"
	.string "someone extraordinary.\p"
	.string "That is why you spoke to me, is it not?\n"
	.string "Your power of observation is fearsome!\p"
	.string "Quite admirable, you are!\p"
	.string "Now that my cover has been blown, let\n"
	.string "me introduce myself.\p"
	.string "I am a globe-trotting elite of the\n"
	.string "International Police.\p"
	.string "My name... Ah, no, I shall inform you\n"
	.string "only of my code name.\p"
	.string "My code name, it is Looker.\n"
	.string "It is what they all call me.\p"
	.string "Incidentally, is the saying, “Don't be\n"
	.string "a thief!” familar to you?$"

JubilifeCity_Text_ThatIsCorrect:
	.string "Looker: Yes, that is correct.\n"
	.string "taking what belongs to others is wrong.$"

JubilifeCity_Text_ClaimNotKnow:
	.string "Looker: No? You claim to not know it?\n"
	.string "How could that be?\p"
	.string "Perhaps your mama has said it, but you\n"
	.string "have forgotten it, like usual?\p"
	.string "Now listen my friends. It is wrong to\n"
	.string "take what belongs to others.$"

JubilifeCity_Text_DoNotHeed:
	.string "Unfortunately, there are apparently\n"
	.string "those who do not heed those words.\p"
	.string "In Sinnoh, in fact, there are criminals\n"
	.string "stealing the Pokémon of others.\p"
	.string "I have, therefore, been on the lookout\n"
	.string "for characters arousing my suspicion.\p"
	.string "Incidentally, you are Trainers, yes?\n"
	.string "Perhaps you can make use of this?$"

JubilifeCity_Text_NiftyDevice:
	.string "That Vs. Recorder, it is a nifty device\n"
	.string "for recording a match.\p"
	.string "I obtained it because it is quite popular\n"
	.string "these days.\p"
	.string "But myself, I do not do Pokémon\n"
	.string "battling very often.\p"
	.string "It will be in better hands with you.$"

JubilifeCity_Text_HaveRequest:
	.string "Looker: Also, I have a request.\p"
	.string "If you were to see me again, I ask that\n"
	.string "you not talk to me, for I am on duty.\p"
	.string "...Actually, yes, yes, you may speak to\n"
	.string "me. You must.\p"
	.string "Not because I am lonely, no no!\n"
	.string "You must inform me of bad guys!\l"
	.string "You must inform me of any happenings!$"

JubilifeCity_Text_WorkingInternational:
	.string "Dawn: ...Working for the International\n"
	.string "Police must be hard.$"

JubilifeCity_Text_HereItIs:
	.string "{PLAYER}, here it is.\n"
	.string "It's the Trainers' School.\l"
	.string "The name says it all!$"

JubilifeCity_Text_SawYourFriend:
	.string "I saw your friend {RIVAL} go in\n"
	.string "earlier.\p"
	.string "He could still be in there studying.\n"
	.string "OK, bye now!$"

JubilifeCity_Text_HaveNoFearSchool:
	.string "Ah, it is you! Have no fear.\n"
	.string "There are no shady characters about.\p"
	.string "Incidentally, have you visited the\n"
	.string "Trainers’ School?\p"
	.string "Did your friend not guide you there\n"
	.string "earlier?$"

JubilifeCity_Text_HelloMyFriend:
	.string "Looker: Hello, my friend.\n"
	.string "Have you visited the Trainers’ School?\p"
	.string "Did your friend not guide you there\n"
	.string "earlier?$"

JubilifeCity_Text_HaveNoFearPoketch:
	.string "Ah, it is you! Have no fear.\n"
	.string "There are no shady characters about.\p"
	.string "Incidentally, have you not obtained\n"
	.string "a Pokétch?\p"
	.string "I believe a Pokétch is now free in\n"
	.string "exchange for some Coupons?$"

JubilifeCity_Text_TellMe:
	.string "Looker: Tell me, have you not obtained\n"
	.string "a Pokétch?\p"
	.string "I believe a Pokétch is now free in\n"
	.string "exchange for some Coupons?$"

JubilifeCity_Text_GlobalTerminalClosed:
	.string "Past here is the Global Terminal, your\n"
	.string "gateway to the world!\p"
	.string "Oh, I’m sorry, you don’t have\n"
	.string "any Gym Badges.\p"
	.string "The Global Terminal is off-limits if you\n"
	.string "don’t have a Gym Badge. Sorry!$"

JubilifeCity_Text_GlobalTerminalOpen:
	.string "Past here is the Global Terminal.\n"
	.string "It lets you trade with the whole world!\p"
	.string "Trading Pokémon means connecting\n"
	.string "with friends, both old and new.\p"
	.string "That’s awesome!$"

JubilifeCity_Text_ClownStickAround:
	.string "Hi, there. You should stick around.\n"
	.string "We’re doing a Pokétch campaign soon.\p"
	.string "Before it starts, I think you should\n"
	.string "brush up at the Trainers’ School.$"

JubilifeCity_Text_ClownWrongAnswer:
	.string "Bzzzzt!\n"
	.string "That’s the wrong answer...$"

JubilifeCity_Text_ClownGrowQuestion:
	.string "Hi! I’m a Pokétch campaign clown!\n"
	.string "Let’s roll out my question!\p"
	.string "Does a Pokémon grow by defeating\n"
	.string "others and gaining Exp. Points?$"

JubilifeCity_Text_ClownGrowExplain:
	.string "Ding-ding!\n"
	.string "You’re absolutely correct!\p"
	.string "Pokémon grow stronger by defeating\n"
	.string "other Pokémon in battle.\p"
	.string "Some Pokémon even grow into an\n"
	.string "entirely different form in a process\l"
	.string "known as evolution.\p"
	.string "Here you go!\n"
	.string "Your Pokétch Coupon!$"

JubilifeCity_Text_ClownGrowDone:
	.string "Pokémon grow stronger by defeating\n"
	.string "other Pokémon in battle.\p"
	.string "Some Pokémon even grow into an\n"
	.string "entirely different form in a process\l"
	.string "known as evolution.$"

JubilifeCity_Text_ClownItemQuestion:
	.string "Hi! I’m a Pokétch campaign clown!\n"
	.string "Let’s roll out my question!\p"
	.string "Can a Pokémon hold an item?$"

JubilifeCity_Text_ClownItemExplain:
	.string "Ding-ding!\n"
	.string "You’re absolutely correct!\p"
	.string "A Pokémon may hold a single item.\p"
	.string "Some items become effective as soon\n"
	.string "as they are held by Pokémon.\p"
	.string "Berries are eaten by Pokémon as\n"
	.string "necessary during battle.\p"
	.string "Here you go!\n"
	.string "Your Pokétch Coupon!$"

JubilifeCity_Text_ClownItemDone:
	.string "You’re absolutely correct!\p"
	.string "A Pokémon may hold a single item.\p"
	.string "Some items become effective as soon\n"
	.string "as they are held by Pokémon.\p"
	.string "Berries are eaten by Pokémon as\n"
	.string "necessary during battle.$"

JubilifeCity_Text_ClownTypeQuestion:
	.string "Hi! I’m a Pokétch campaign clown!\n"
	.string "Let’s roll out my question!\p"
	.string "Just like Pokémon types, the moves\n"
	.string "of Pokémon also have types?$"

JubilifeCity_Text_ClownTypeExplain:
	.string "Ding-ding!\n"
	.string "You’re absolutely correct!\p"
	.string "If the Pokémon’s type matches its\n"
	.string "move’s type, that move is made much\l"
	.string "more powerful!\p"
	.string "Here you go!\n"
	.string "Your Pokétch Coupon!$"

JubilifeCity_Text_ClownTypeDone:
	.string "If the Pokémon’s type matches its\n"
	.string "move’s type, that move is made much\l"
	.string "more powerful!$"

JubilifeCity_Text_Poketch_Promotion:
	.string "Oh, oh, oh?\p"
	.string "You call yourself a Pokémon Trainer?\n"
	.string "And yet you have no Pokétch?\p"
	.string "That is, Pokémon Watch, or Pokétch\n"
	.string "for short!\p"
	.string "Oh my, you are a rare case\n"
	.string "indeed!\p"
	.string "You see, I invented, and now\n"
	.string "manufacture, Pokétches.\p"
	.string "Not only that, I’m now conducting\n"
	.string "the Pokétch promotional campaign!\p"
	.string "All you have to do is find three\n"
	.string "clowns in Jubilife City.\p"
	.string "If you can find them...\n"
	.string "I will gift you with a Pokétch!$"

JubilifeCity_Text_Poketch_Explain:
	.string "The three clowns will each ask you\n"
	.string "a skill-testing question.\p"
	.string "The questions will all have to do\n"
	.string "with Pokémon.\p"
	.string "After all, a Pokétch is a tool for\n"
	.string "Pokémon Trainers.\p"
	.string "Collect a Coupon from each clown,\n"
	.string "then come see me, OK?$"

JubilifeCity_Text_Poketch_Count:
	.string "OK, let me count your Coupons!\n"
	.string "I’ll use the Pokétch here...\p"
	.string "One, two, three!\n"
	.string "Bravo! I say, bravo!\p"
	.string "In return for these Coupons,\n"
	.string "I present you this Pokémon Watch,\l"
	.string "or Pokétch for short!$"

JubilifeCity_Text_Poketch_Receive:
	.string "{PLAYER} received a Pokétch!$"

JubilifeCity_Text_Poketch_Leave:
	.string "You can add apps to your Pokétch\n"
	.string "to make it even more versatile!\p"
	.string "Touch the Pokétch screen and find the\n"
	.string "apps that are right for you!$"

JubilifeCity_Text_TradingWithBuddy:
	.string "I’m trading Pokémon with my buddy!$"

JubilifeCity_Text_HoldAnItem:
	.string "I made my Pokémon hold an item before\n"
	.string "trading it.\p"
	.string "That will make the other Trainer\n"
	.string "double happy!$"

JubilifeCity_Text_HelloTrainer:
	.string "Hello, Trainer!\n"
	.string "Do you know much about Pokémon?$"

JubilifeCity_Text_YouAreKnowledgeable:
	.string "Ah, I see!\n"
	.string "You are knowledgeable!\p"
	.string "I imagine you wouldn’t see the need\n"
	.string "to visit the Trainers’ School, then.\p"
	.string "But do visit if you have the time.\n"
	.string "You may discover something new!$"

JubilifeCity_Text_NotToWorry:
	.string "Oh, you’re not knowledgeable...\n"
	.string "But not to worry!\l"
	.string "There’s the Trainers’ School.\p"
	.string "The school will teach you the\n"
	.string "basics of Pokémon.$"

JubilifeCity_Text_SixBalls:
	.string "OK, set six Poké Balls in my\n"
	.string "belt...\p"
	.string "Yeah, that’ll do it. At most, you\n"
	.string "can have six Pokémon with you.$"

JubilifeCity_Text_CarvedOfMountain:
	.string "Jubilife City’s built on land they\n"
	.string "carved out of a mountain.\p"
	.string "The people and Pokémon of Oreburgh\n"
	.string "City helped out with that undertaking.$"

JubilifeCity_Text_WhereComeFrom:
	.string "Hiya, where’d you come from?\p"
	.string "...\p"
	.string "Twinleaf Town, huh...\n"
	.string "It’s a nice place. Quiet and all.\p"
	.string "Jubilife City is a big place, so it\n"
	.string "might be a bit of a shock to you.$"

JubilifeCity_Text_JoinGroup:
	.string "Hi, I know it's a little sudden, but\n"
	.string "would you like to join a group?\p"
	.string "If you join a group, you can compete\n"
	.string "or cooperate with fellow members.\p"
	.string "It's a lot of fun.\n"
	.string "Want to join?$"

JubilifeCity_Text_NameYourGroup:
	.string "Yay, cool! What do you want to name\n"
	.string "your group?\p"
	.string "The Untitled group, huh?\n"
	.string "That's a great name!\p"
	.string "The leader is {RIVAL}.\n"
	.string "I hope the group gets more members.$"

JubilifeCity_Text_WhenYouForm:
	.string "When you form or join a new group,\n"
	.string "be sure to visit any Union Room.\p"
	.string "Mix your records with group members,\n"
	.string "and you'll become integrated.\p"
	.string "When you're in the same group,\n"
	.string "events can happen simultaneously.\p"
	.string "It makes things a lot more fun\n"
	.string "playing in a group!\p"
	.string "Anyone can make a group, and anyone\n"
	.string "can join.\p"
	.string "I hope you recruit lots of friends\n"
	.string "so everyone can have fun!$"

JubilifeCity_Text_ThatsTooBad:
	.string "Oh.\n"
	.string "That's too bad.$"

JubilifeCity_Text_SeeMeOnTV:
	.string "Did you see me on TV?\n"
	.string "I was in an interview!$"

JubilifeCity_Text_WalkWithPokemon:
	.string "When you walk with your Pokémon,\n"
	.string "they gradually grow friendlier.$"

JubilifeCity_Text_TownSign:
	.string "Jubilife City\n"
	.string "City of Joy$"

JubilifeCity_Text_TrainerSchoolSign:
	.string "Trainers' School\n"
	.string "The First Step for Trainers!$"

JubilifeCity_Text_CondominiumSign:
	.string "Jubilife Condominiums\n"
	.string "Tenants Wanted!$"

JubilifeCity_Text_JubilifeTVSign:
	.string "Jubilife TV\n"
	.string "The Fun-and-Games TV Station!$"

JubilifeCity_Text_PoketchCompanySign:
	.string "The Pokétch Company\n"
	.string "Pokémon Watches for the World!$"
