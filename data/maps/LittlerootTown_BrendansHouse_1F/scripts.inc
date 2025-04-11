.set LOCALID_MOM, 1

LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_BrendansHouse_1F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMom
	end

LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 0, LittlerootTown_BrendansHouse_1F_EventScript_MomMessage
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_LakeReturn
	.2byte 0

LittlerootTown_BrendansHouse_1F_OnWarp:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_TurnPlayerNorth
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_MomMessage::
	lock
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 10
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_MomTalk_1
	waitmovement 0
	delay 10
	msgbox LittlerootTown_BrendansHouse_1F_Text_Emergency, MSGBOX_DEFAULT
	closemessage
	delay 60
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_MomTalk_2
	waitmovement 0
	delay 10
	release
	return

LittlerootTown_BrendansHouse_1F_Movement_MomTalk_1:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_MomTalk_2:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_down
	face_up
	walk_in_place_up
	step_end

LittlerootTown_BrendansHouse_1F_Trigger_Exit::
	lock
	setvar VAR_LITTLEROOT_INTRO_STATE, 2
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	msgbox LittlerootTown_BrendansHouse_1F_Text_LeaveHouse, MSGBOX_DEFAULT
	release
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMom::
	setobjectxyperm LOCALID_MOM, 1, 3
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

LittlerootTown_BrendansHouse_1F_EventScript_LakeReturn::
	lock
	setvar VAR_LITTLEROOT_INTRO_STATE, 6
	delay 48
	delay 48
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_MomKitchen
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerKitchen
	waitmovement 0
	delay 48
	delay 48
	msgbox LittlerootTown_BrendansHouse_1F_Text_MomKitchen1, MSGBOX_SIGN
	delay 48
	msgbox LittlerootTown_BrendansHouse_1F_Text_MomKitchen2, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_BrendansHouse_1F_Text_RunningShoesGet
	waitfanfare
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	delay 48
	msgbox LittlerootTown_BrendansHouse_1F_Text_MomKitchen3, MSGBOX_DEFAULT
	msgbox LittlerootTown_BrendansHouse_1F_Text_RunningShoesManual, MSGBOX_SIGN
	release
	end

LittlerootTown_BrendansHouse_1F_Movement_MomKitchen:
	walk_left
	face_up
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_in_place_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerKitchen:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_right
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_Mom::
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_BrendansHouse_1F_EventScript_MomTalk1
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_BrendansHouse_1F_EventScript_MomDiff
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 2, LittlerootTown_BrendansHouse_1F_EventScript_RunningShoesManual
	@ goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 3, LittlerootTown_BrendansHouse_1F_EventScript_MomHealsParty
	goto LittlerootTown_BrendansHouse_1F_EventScript_MomHealsParty
	end

LittlerootTown_BrendansHouse_1F_EventScript_MomTalk1::
	msgbox LittlerootTown_BrendansHouse_1F_Text_MomTalk1, MSGBOX_NPC
	end

LittlerootTown_BrendansHouse_1F_EventScript_MomDiff::
	goto_if_eq VAR_ALTERNATE_TEXT, 0, LittlerootTown_BrendansHouse_1F_EventScript_MomBye1
	goto_if_eq VAR_ALTERNATE_TEXT, 1, LittlerootTown_BrendansHouse_1F_EventScript_MomBye2
	end

LittlerootTown_BrendansHouse_1F_EventScript_MomBye1::
	setvar VAR_ALTERNATE_TEXT, 1
	msgbox LittlerootTown_BrendansHouse_1F_Text_MomBye1, MSGBOX_NPC
	end

LittlerootTown_BrendansHouse_1F_EventScript_MomBye2::
	msgbox LittlerootTown_BrendansHouse_1F_Text_MomBye2, MSGBOX_NPC
	end

LittlerootTown_BrendansHouse_1F_EventScript_RunningShoesManual::
	msgbox LittlerootTown_BrendansHouse_1F_Text_MomRead, MSGBOX_DEFAULT
	msgbox LittlerootTown_BrendansHouse_1F_Text_RunningShoesManual, MSGBOX_SIGN
	end

LittlerootTown_BrendansHouse_1F_EventScript_MomHealsParty::
	lock
	faceplayer
	msgbox LittlerootTown_BrendansHouse_1F_Text_TakeQuickRest, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_Kitchen::
	msgbox LittlerootTown_BrendansHouse_1F_Text_Kitchen, MSGBOX_SIGN
	end

LittlerootTown_BrendansHouse_1F_EventScript_Counter::
	msgbox LittlerootTown_BrendansHouse_1F_Text_Counter, MSGBOX_SIGN
	end

LittlerootTown_BrendansHouse_1F_EventScript_Fridge::
	msgbox LittlerootTown_BrendansHouse_1F_Text_Fridge, MSGBOX_SIGN
	end

LittlerootTown_BrendansHouse_1F_Text_Kitchen:
	.string "Mom's kitchen is spotless!\n"
	.string "You can see your face on the floor!$"

LittlerootTown_BrendansHouse_1F_Text_Counter:
	.string "This is where Mom does all her\n"
	.string "delicious cooking.$"

LittlerootTown_BrendansHouse_1F_Text_Fridge:
	.string "Mom's favorite dessert is in\n"
	.string "the refrigerator.$"

LittlerootTown_BrendansHouse_1F_Text_TheresAMovieOnTV:
	.string "There is a movie on TV.\p"
	.string "Two men are dancing on a big piano\n"
	.string "keyboard.\p"
	.string "Better get going!$"

LittlerootTown_BrendansHouse_1F_Text_Emergency:
	.string "Mom: {PLAYER}!\p"
	.string "{RIVAL} came calling for you a little\n"
	.string "while ago.\p"
	.string "I don't know what it was about, but he\n"
	.string "said it was an emergency.$"

LittlerootTown_BrendansHouse_1F_Text_LeaveHouse:
	.string "Mom: Oh yes! {PLAYER}!\p"
	.string "Don't go into the tall grass. Wild\n"
	.string "Pokémon might attack you.\p"
	.string "It would be OK if you had your own\n"
	.string "Pokémon, but you don't so...$"

LittlerootTown_BrendansHouse_1F_Text_MomTalk1:
	.string "Mom: You know how impatient\n"
	.string "{RIVAL} is.\p"
	.string "He took off before I could even\n"
	.string "ask what it was about.$"

LittlerootTown_BrendansHouse_1F_Text_MomBye1:
	.string "Mom: Bye-bye, {PLAYER}!\n"
	.string "You take care now!$"

LittlerootTown_BrendansHouse_1F_Text_MomBye2:
	.string "Mom: What is it, dear?\n"
	.string "Isn't {RIVAL} waiting for you?$"

LittlerootTown_BrendansHouse_1F_Text_MomKitchen1:
	.string "Mom: What's up, dear?\p"
	.string "...\p"
	.string "Wow.\n"
	.string "I can't believe that happened to you.\p"
	.string "Am I ever glad that both you and\n"
	.string "{RIVAL} are unharmed.\p"
	.string "The professor you mentioned is\n"
	.string "most likely Professor Rowan of\l"
	.string "Sandgem Town.\p"
	.string "I've heard that he is well known for\n"
	.string "his studies on Pokémon.\p"
	.string "I hear he's also quite intimidating...\p"
	.string "{PLAYER}, I think you need to\n"
	.string "visit him in Sandgem Town.\p"
	.string "You need to properly explain why you\n"
	.string "had no choice but to use his Pokémon.\p"
	.string "Don't worry!\n"
	.string "I'm sure he will understand.$"

LittlerootTown_BrendansHouse_1F_Text_MomKitchen2:
	.string "Oh, I know!\n"
	.string "{PLAYER}, put these on.$"

LittlerootTown_BrendansHouse_1F_Text_MomKitchen3:
	.string "Going to Sandgem Town is like an\n"
	.string "adventure in itself, right?\p"
	.string "With those Running Shoes, you can\n"
	.string "get to faraway places much faster.\p"
	.string "OK...\n"
	.string "Let me read the instructions...$"

LittlerootTown_BrendansHouse_1F_Text_MomRead:
	.string "Mom: I'll read you the instructions\n"
	.string "for the Running Shoes...$"

LittlerootTown_BrendansHouse_1F_Text_RunningShoesGet:
	.string "{PLAYER} received a pair of\n"
	.string "Running Shoes!$"

LittlerootTown_BrendansHouse_1F_Text_RunningShoesManual:
	.string "“Press the B Button and dash\n"
	.string "about faster than ever before!\p"
	.string "“Put on the Running Shoes and\n"
	.string "blaze new trails of adventure!“\p"
	.string "Well, isn't that just nifty!$"

LittlerootTown_BrendansHouse_1F_Text_TakeQuickRest:
	.string "Mom: Welcome home, {PLAYER}.\n"
	.string "Are you and your Pokémon healthy?\p"
	.string "I just made dinner.\n"
	.string "Take a quick rest, dear.$"
