LakefrontVerity_MapScripts::
	.byte 0

LakefrontVerity_EventScript_EnterLake::
	lock
	setvar VAR_ROUTE101_STATE, 2
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox LakefrontVerity_Text_EnterLake, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_PLAYER, LakefrontVerity_Movement_WalkUp
	applymovement OBJ_EVENT_ID_FOLLOWER, LakefrontVerity_Movement_WalkUp
	waitmovement 0
	warp MAP_LAKE_VERITY, 0
	destroyfollower
	release
	end

LakefrontVerity_EventScript_RouteSign::
	msgbox LakefrontVerity_Text_RouteSign, MSGBOX_SIGN
	end

LakefrontVerity_Movement_WalkUp:
	walk_up
	walk_up
	step_end

LakefrontVerity_Text_EnterLake:
	.string "{RIVAL}: All right! To the lake!\n"
	.string "Let's find us a red GYARADOS!$"

LakefrontVerity_Text_RouteSign:
	.string "{UP_ARROW} Lake Verity Ahead\n"
	.string "     The Lake of Emotions$"
