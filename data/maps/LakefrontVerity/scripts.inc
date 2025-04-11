.set LOCALID_RIVAL, 1

LakefrontVerity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LakefrontVerity_OnFrame
	.byte 0

LakefrontVerity_OnFrame:
	map_script_2 VAR_ROUTE101_STATE, 2, LakefrontVerity_EventScript_ExitLake
	.2byte 0

LakefrontVerity_EventScript_EnterLake::
	lock
	setvar VAR_ROUTE101_STATE, 2
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox LakefrontVerity_Text_EnterLake, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_PLAYER, LakefrontVerity_Movement_WalkUp
	applymovement OBJ_EVENT_ID_FOLLOWER, LakefrontVerity_Movement_WalkUp
	waitmovement 0
	destroyfollower
	warp MAP_LAKE_VERITY, 0
	waitstate
	release
	end

LakefrontVerity_EventScript_ExitLake::
	lock
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, LakefrontVerity_Movement_WalkDown
	applymovement LOCALID_RIVAL, LakefrontVerity_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox LakefrontVerity_Text_ExitLake, MSGBOX_SIGN
	applymovement LOCALID_RIVAL, LakefrontVerity_Movement_WalkUpRight
	waitmovement 0
	setvar VAR_FOLLOWER_TEXT, 0
	setvar VAR_ROUTE101_STATE, 3
	setflag FLAG_HIDE_VERITY_LAKEFRONT_RIVAL
	clearflag FLAG_HIDE_ROUTE_101_PROF
	loadword 0 LakefrontVerity_EventScript_Rival
	setfollower LOCALID_RIVAL 0x100
	release
	end

LakefrontVerity_EventScript_ReturnLake::
	lock
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox LakefrontVerity_Text_RivalLeave, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_FOLLOWER, Common_Movement_WalkDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	release
	end

LakefrontVerity_EventScript_RouteSign::
	msgbox LakefrontVerity_Text_RouteSign, MSGBOX_SIGN
	end

LakefrontVerity_Movement_WalkUp:
	walk_up
	walk_up
	step_end

LakefrontVerity_Movement_WalkDown:
	walk_down
	walk_down
	step_end

LakefrontVerity_Movement_WalkUpRight:
	walk_up
	walk_in_place_right
	step_end

LakefrontVerity_EventScript_Rival::
	facefollower
	goto_if_eq VAR_FOLLOWER_TEXT, 0, LakefrontVerity_EventScript_RivalTalk1
	goto_if_eq VAR_FOLLOWER_TEXT, 1, LakefrontVerity_EventScript_RivalTalk2
	goto_if_eq VAR_FOLLOWER_TEXT, 2, LakefrontVerity_EventScript_RivalTalk3

LakefrontVerity_EventScript_RivalTalk1::
	setvar VAR_FOLLOWER_TEXT, 1
	msgbox LakefrontVerity_Text_RivalTalk1, MSGBOX_SIGN
	end

LakefrontVerity_EventScript_RivalTalk2::
	setvar VAR_FOLLOWER_TEXT, 2
	msgbox LakefrontVerity_Text_RivalTalk2, MSGBOX_SIGN
	end

LakefrontVerity_EventScript_RivalTalk3::
	msgbox LakefrontVerity_Text_RivalTalk3, MSGBOX_SIGN
	end

LakefrontVerity_Text_EnterLake:
	.string "{RIVAL}: All right! To the lake!\n"
	.string "Let's find us a red GYARADOS!$"

LakefrontVerity_Text_RouteSign:
	.string "{UP_ARROW} Lake Verity Ahead\n"
	.string "   The Lake of Emotions$"

LakefrontVerity_Text_ExitLake:
	.string "{RIVAL}: You go ahead...\p"
	.string "...I know we have to go return these\n"
	.string "Pokémon. They're not ours.\p"
	.string "But I want to spend just a little\n"
	.string "more time with this little guy...$"

LakefrontVerity_Text_RivalLeave:
	.string "{RIVAL}: Hey, hey!\n"
	.string "Where do you think you're going?\p"
	.string "We have to go return these\n"
	.string "Pokémon...$"

LakefrontVerity_Text_RivalTalk1:
	.string "{RIVAL}: We didn't have any\n"
	.string "choice in using those people's\l"
	.string "Pokémon, right?\p"
	.string "But these Pokémon belong to them...\n"
	.string "They'll want them back, won't they?\p"
	.string "But this is the first Pokémon I've\n"
	.string "ever battled with...$"

LakefrontVerity_Text_RivalTalk2:
	.string "{RIVAL}: I wish I could grow\n"
	.string "tougher with this little guy...$"

LakefrontVerity_Text_RivalTalk3:
	.string "{RIVAL}: I don't feel like\n"
	.string "talking... Let's go.\p"
	.string "...Are we maybe walking slower than\n"
	.string "when we went to the lake?$"
