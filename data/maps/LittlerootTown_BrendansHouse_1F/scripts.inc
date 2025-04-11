.set LOCALID_MOM, 1

LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor
	end

LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 0, LittlerootTown_BrendansHouse_1F_EventScript_MomMessage
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_MomMessage::
	lock
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 10
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_MomTalk_1
	waitmovement 0
	delay 10
	msgbox LittlerootTown_BrendansHouse_1F_EventScript_Mom_Text, MSGBOX_DEFAULT
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
	msgbox LittlerootTown_BrendansHouse_1F_Trigger_Mom_Text, MSGBOX_DEFAULT
	release
	return

@ TODO: Change to kitchen scene
LittlerootTown_BrendansHouse_1F_EventScript_MoveMomToDoor::
	setobjectxyperm LOCALID_MOM, 9, 8
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, LittlerootTown_BrendansHouse_1F_EventScript_RunningShoesManual
	goto LittlerootTown_BrendansHouse_1F_EventScript_MomHealsParty
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_MomHealsParty::
	msgbox LittlerootTown_BrendansHouse_1F_Text_DontPushYourselfTooHard, MSGBOX_DEFAULT
	msgbox LittlerootTown_BrendansHouse_1F_Text_YouShouldRestABit, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	msgbox LittlerootTown_BrendansHouse_1F_Text_TakeCareHoney, MSGBOX_DEFAULT
	release
	end

@ LittlerootTown_BrendansHouse_1F_EventScript_SeeYouHoney::
@ msgbox LittlerootTown_BrendansHouse_1F_Text_SeeYouHoney, MSGBOX_DEFAULT

LittlerootTown_BrendansHouse_1F_EventScript_RunningShoesManual::
	msgbox LittlerootTown_BrendansHouse_1F_Text_RunningShoesManual, MSGBOX_DEFAULT
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

LittlerootTown_BrendansHouse_1F_Text_SeeYouHoney:
	.string "MOM: See you, honey!$"

LittlerootTown_BrendansHouse_1F_Text_YouShouldRestABit:
	.string "MOM: How are you doing, {PLAYER}?\n"
	.string "You look a little tired.\p"
	.string "I think you should rest a bit.$"

LittlerootTown_BrendansHouse_1F_Text_TakeCareHoney:
	.string "MOM: Take care, honey!$"

LittlerootTown_BrendansHouse_1F_Text_DontPushYourselfTooHard:
	.string "Don't push yourself too hard, dear.\n"
	.string "You can always come home.\p"
	.string "Go for it, honey!$"

LittlerootTown_BrendansHouse_1F_Text_TheresAMovieOnTV:
	.string "There is a movie on TV.\p"
	.string "Two men are dancing on a big piano\n"
	.string "keyboard.\p"
	.string "Better get going!$"

LittlerootTown_BrendansHouse_1F_Text_RunningShoesManual:
	.string "It's the instruction booklet for the\n"
	.string "RUNNING SHOES.\p"
	.string "“Press the B Button to run while\n"
	.string "wearing your RUNNING SHOES.\p"
	.string "“Lace up your RUNNING SHOES and hit\n"
	.string "the road running!”$"

LittlerootTown_BrendansHouse_1F_EventScript_Mom_Text:
	.string "Mom: {PLAYER}!\p"
	.string "{RIVAL} came calling for you a little\n"
	.string "while ago.\p"
	.string "I don't know what it was about, but he\n"
	.string "said it was an emergency.$"

LittlerootTown_BrendansHouse_1F_Trigger_Mom_Text:
	.string "Mom: Oh yes! {PLAYER}!\p"
	.string "Don't go into the tall grass. Wild\n"
	.string "Pokemon might attack you.\p"
	.string "It would be OK if you had your own\n"
	.string "Pokemon, but you don't so...$"

LittlerootTown_Text_ExplainRunningShoes:
	.string "MOM: {PLAYER}, those shoes came with\n"
	.string "instructions.\p"
	.string "“Press the B Button while wearing these\n"
	.string "RUNNING SHOES to run extra-fast!\p"
	.string "“Slip on these RUNNING SHOES and race\n"
	.string "in the great outdoors!”$"

@ LittlerootTown_EventScript_SetReceivedRunningShoes::
@ 	setflag FLAG_SYS_B_DASH
@ 	setvar VAR_LITTLEROOT_TOWN_STATE, 4
@ 	release
@	end

LittlerootTown_BrendansHouse_1F_Text_Kitchen:
	.string "Mom's kitchen is spotless!\n"
	.string "You can see your face on the floor!$"

LittlerootTown_BrendansHouse_1F_Text_Counter:
	.string "This is where Mom does all her\n"
	.string "delicious cooking.$"

LittlerootTown_BrendansHouse_1F_Text_Fridge:
	.string "Mom's favorite dessert is in\n"
	.string "the refrigerator.$"
