LakefrontVerity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LakefrontVerity_OnFrame
	.byte 0

LakefrontVerity_OnFrame:
	.2byte 0

LakefrontVerity_EventScript_EnterLake::
	lock
	setvar VAR_ROUTE201_STATE, 3
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER , Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox LakefrontVerity_Text_EnterLake, MSGBOX_SIGN
	applymovement LOCALID_PLAYER, LakefrontVerity_Movement_WalkUp
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER , LakefrontVerity_Movement_WalkUp
	waitmovement 0
	hideobjectat LOCALID_PLAYER, MAP_LAKEFRONT_VERITY
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER , Common_Movement_WalkUp
	waitmovement 0
	warp MAP_LAKE_VERITY, 12, 23
	waitstate
	destroyfollowernpc
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
	.string "{RIVAL}: All right!\n"
	.string "We're at the lake!\p"
	.string "Get ready, because we're capturing\n"
	.string "that legendary Pokémon.\p"
	.string "Trust me on this one. It's here.\n"
	.string "It even says so on the sign!$"

LakefrontVerity_Text_RouteSign:
	.string "Lake Verity Ahead\p"
	.string "According to legend, this lake is home\n"
	.string "to the Pokémon said to be 'The Being of\l"
	.string "Emotion.'\p"
	.string "It is because of this Pokémon that\n"
	.string "people can experience sorrow and joy.$"
