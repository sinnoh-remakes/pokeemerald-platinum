.set LOCALID_RIVAL, 1

Route101_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route101_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, Route101_OnFrame
	.byte 0

Route101_OnTransition:
	end

Route101_OnFrame:
	map_script_2 VAR_ROUTE101_STATE, 0, Route101_EventScript_HideMapNamePopup
	.2byte 0

Route101_EventScript_RivalSee1::
	setvar VAR_0x8004, 1
	goto Route101_EventScript_RivalSee

Route101_EventScript_RivalSee2::
	setvar VAR_0x8004, 2
	goto Route101_EventScript_RivalSee

Route101_EventScript_RivalSee3::
	setvar VAR_0x8004, 3
	goto Route101_EventScript_RivalSee

Route101_EventScript_RivalSee4::
	setvar VAR_0x8004, 4
	goto Route101_EventScript_RivalSee

Route101_EventScript_RivalSee::
	lock
	setvar VAR_LITTLEROOT_TOWN_STATE, 2
	setvar VAR_ROUTE101_STATE, 1
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 10
	applymovement LOCALID_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_0x8004, 1, Route101_EventScript_RivalShift1
	call_if_eq VAR_0x8004, 2, Route101_EventScript_RivalShift2
	call_if_eq VAR_0x8004, 4, Route101_EventScript_RivalShift4
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	waitmovement 0
	msgbox Route101_Text_RivalMeet, MSGBOX_SIGN
	loadword 0 Route101_EventScript_Rival
	setfollower LOCALID_RIVAL 0x100
	release
	end

Route101_EventScript_RivalShift1::
	applymovement LOCALID_RIVAL, Route101_Movement_RivalLeft
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	waitmovement 0
	return

Route101_Movement_RivalLeft:
	walk_left
	walk_left
	step_end

Route101_EventScript_RivalShift2::
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	waitmovement 0
	return

Route101_EventScript_RivalShift4::
	applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	waitmovement 0
	return

Route101_EventScript_Youngster::
	msgbox Route101_Text_TakeTiredPokemonToPokeCenter, MSGBOX_NPC
	end

Route101_EventScript_Boy::
	msgbox Route101_Text_WildPokemonInTallGrass, MSGBOX_NPC
	end

Route101_EventScript_RouteSign::
	msgbox Route101_Text_RouteSign, MSGBOX_SIGN
	end

Route101_EventScript_Rival::
	faceplayer
	goto_if_eq VAR_FOLLOWER_TEXT, 0, Route101_EventScript_RivalTalk1
	goto_if_eq VAR_FOLLOWER_TEXT, 1, Route101_EventScript_RivalTalk2
	goto_if_eq VAR_FOLLOWER_TEXT, 2, Route101_EventScript_RivalTalk3
	goto_if_eq VAR_FOLLOWER_TEXT, 3, Route101_EventScript_RivalTalk4
	goto_if_eq VAR_FOLLOWER_TEXT, 4, Route101_EventScript_RivalTalk5
	goto_if_eq VAR_FOLLOWER_TEXT, 5, Route101_EventScript_RivalTalk6

Route101_EventScript_RivalTalk1::
	setvar VAR_FOLLOWER_TEXT, 1
	msgbox Route101_Text_RivalTalk1, MSGBOX_SIGN
	end

Route101_EventScript_RivalTalk2::
	setvar VAR_FOLLOWER_TEXT, 2
	msgbox Route101_Text_RivalTalk2, MSGBOX_SIGN
	end

Route101_EventScript_RivalTalk3::
	setvar VAR_FOLLOWER_TEXT, 3
	msgbox Route101_Text_RivalTalk3, MSGBOX_SIGN
	end

Route101_EventScript_RivalTalk4::
	setvar VAR_FOLLOWER_TEXT, 4
	msgbox Route101_Text_RivalTalk4, MSGBOX_SIGN
	end

Route101_EventScript_RivalTalk5::
	setvar VAR_FOLLOWER_TEXT, 5
	msgbox Route101_Text_RivalTalk5, MSGBOX_SIGN
	end

Route101_EventScript_RivalTalk6::
	msgbox Route101_Text_RivalTalk6, MSGBOX_SIGN
	end

Route101_EventScript_FollowLeave::
	lock
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox Route101_Text_FollowLeave, MSGBOX_SIGN
	applymovement LOCALID_RIVAL, Common_Movement_WalkUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	release
	end

Route101_EventScript_FollowGrass::
	lock
	msgbox Route101_Text_FollowGrass, MSGBOX_SIGN
	goto_if_eq VAR_FACING, DIR_NORTH, Route101_EventScript_FollowGrassSpecial
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceRight
	waitmovement 0
	delay 30
	release
	end

Route101_EventScript_FollowGrassSpecial::
	applymovement LOCALID_RIVAL, Common_Movement_WalkDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	release
	end

Route101_Text_RouteSign:
	.string "{DOWN_ARROW} R.201\n"
	.string "     Twinleaf Town$"

@ TODO: Figure out how to add delimited quotes to string
Route101_Text_RivalMeet:
	.string "{RIVAL}: Hey you saw that news\n"
	.string "report that was on TV, right?\p"
	.string "You know, 'Search for the Red\n"
	.string "GYARADOS! The mysterious appearance\l"
	.string "of the furious Pokemon in a lake!'\p"
	.string "That show got me to thinking.\p"
	.string "I'll bet our local lake has a Pokemon\n"
	.string "like that in it, too!\p"
	.string "So that's what we're gonna do.\n"
	.string "We'll go find a Pokemon like that!$"

Route101_Text_RivalTalk1:
	.string "{RIVAL}: Hey, if we run into a\n"
	.string "Pokemon, I'm gonna catch it somehow.\p"
	.string "Because I'm gonne be a Pokemon\n"
	.string "Trainer.\p"
	.string "You know what a Trainer does, right?\n"
	.string "Makes Pokemon battle and all that?$"

Route101_Text_RivalTalk2:
	.string "{RIVAL}: Pokemon all have\n"
	.string "different moves, huh?\p"
	.string "A Trainer makes his Pokemon battle\n"
	.string "by ordering them to use moves.\p"
	.string "That's so awesomely cool.$"
	
Route101_Text_RivalTalk3:
	.string "{RIVAL}: I want Pokemon of my\n"
	.string "own, and not too soon, either.\p"
	.string "I'd be able to go everywhere with my\n"
	.string "Pokemon that way.$"
	
Route101_Text_RivalTalk4:
	.string "{RIVAL}: That lake has a mirage\n"
	.string "Pokemon living in it.\p"
	.string "Everyone says nothing lives there,\n"
	.string "but I know I'm right.$"
	
Route101_Text_RivalTalk5:
	.string "{RIVAL}: I'm gonna become\n"
	.string "a Pokemon Trainer for sure.\p"
	.string "Not just any trainer either.\n"
	.string "I'm going to be the greatest ever.\l"
	.string "That's my dream.$"
	
Route101_Text_RivalTalk6:
	.string "{RIVAL}: Hey, that's enough\n"
	.string "talking already.\p"
	.string "I'm itching to get going to the lake.\n"
	.string "Come on, come on!$"

Route101_Text_FollowLeave:
	.string "{RIVAL}: Hey!\n"
	.string "Where are you wandering off to?!\p"
	.string "That mystery Pokemon on TV!\n"
	.string "It's calling out to me!\p"
	.string "Forget about going back home!$"

@ TODO: Figure out how to add delimited quotes to string
Route101_Text_FollowGrass:
	.string "Remember what your mother said?\p"
	.string "Mom: '{PLAYER}!\n"
	.string "Don't go into the tall grass!\p"
	.string "'Remember, wild Pokemon may attack\n"
	.string "you if you're walking in the tall grass.\p"
	.string "'It would be OK if you had your\n"
	.string "own Pokemon, but...'$"
