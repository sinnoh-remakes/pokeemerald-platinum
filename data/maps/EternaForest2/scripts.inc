EternaForest2_MapScripts::
	.byte 0

EternaForest2_EventScript_CherylLeave::
	lock
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 32
	applymovement LOCALID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	msgbox EternaForest2_Text_TheresTheExit, MSGBOX_DEFAULT
	giveitem ITEM_SOOTHE_BELL
	closemessage
	return

EternaForest2_EventScript_CherylBye:
	msgbox EternaForest2_Text_ByeForNow, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	destroyfollowernpc
	setflag FLAG_HIDE_ETERNA_FOREST_CHERYL
	setvar VAR_ETERNA_FOREST_STATE, 2
	delay 48
	release
	end

EternaForest2_EventScript_CherylLeave1::
	call EternaForest2_EventScript_CherylLeave
	applymovement LOCALID_PLAYER, EternaForest2_Movement_PlayerTurnSouth
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, EternaForest2_Movement_CherylLeave1
	waitmovement 0
	goto EternaForest2_EventScript_CherylBye

EternaForest2_EventScript_CherylLeave2::
	call EternaForest2_EventScript_CherylLeave
	applymovement LOCALID_PLAYER, EternaForest2_Movement_PlayerTurnSouth
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, EternaForest2_Movement_CherylLeave2
	waitmovement 0
	goto EternaForest2_EventScript_CherylBye

EternaForest2_EventScript_CherylLeave3::
	call EternaForest2_EventScript_CherylLeave
	applymovement LOCALID_PLAYER, EternaForest2_Movement_PlayerTurnNorth
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, EternaForest2_Movement_CherylLeave3
	waitmovement 0
	goto EternaForest2_EventScript_CherylBye

EternaForest2_EventScript_CherylLeave4::
	call EternaForest2_EventScript_CherylLeave
	applymovement LOCALID_PLAYER, EternaForest2_Movement_PlayerTurnNorth
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, EternaForest2_Movement_CherylLeave4
	waitmovement 0
	goto EternaForest2_EventScript_CherylBye

EternaForest2_Movement_CherylLeave1:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_left
	step_end

EternaForest2_Movement_CherylLeave2:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_left
	step_end

EternaForest2_Movement_CherylLeave3:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_left
	step_end

EternaForest2_Movement_CherylLeave4:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_left
	step_end

EternaForest2_Movement_PlayerTurnNorth:
	delay_16
	walk_in_place_up
	delay_16
	walk_in_place_right
	step_end

EternaForest2_Movement_PlayerTurnSouth:
	delay_16
	walk_in_place_down
	delay_16
	walk_in_place_right
	step_end

EternaForest2_Text_TheresTheExit:
	.string "Cheryl: Oh! There’s the exit!\n"
	.string "I’m so relieved... We finally got here.\p"
	.string "I would’ve never been able to get\n"
	.string "through this by myself.\p"
	.string "Thank you so much, {PLAYER}!\p"
	.string "This is my token of appreciation.\n"
	.string "Please accept it!$"

EternaForest2_Text_ByeForNow:
	.string "I’m sure we’ll meet again somewhere!\n"
	.string "Bye for now!$"
