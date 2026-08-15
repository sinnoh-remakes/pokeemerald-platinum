Route205South2_MapScripts::
	.byte 0

@ State descriptions for VAR_ROUTE205_SOUTH_2_STATE
@ 1: Talked to the girl
@ 2: Defeated Mars

Route205South2_EventScript_Galactic_Roadblock::
	lock
	applymovement LOCALID_ROUTE205_GRUNT_LEFT, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox Route205South2_Text_Galactic_Roadblock_Left, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ROUTE205_GRUNT_RIGHT, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox Route205South2_Text_Galactic_Roadblock_Right, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	applymovement LOCALID_ROUTE205_GRUNT_LEFT, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	applymovement LOCALID_ROUTE205_GRUNT_LEFT, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 32
	applymovement LOCALID_ROUTE205_GRUNT_LEFT, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_ROUTE205_GRUNT_LEFT, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 12
	applymovement LOCALID_ROUTE205_GRUNT_RIGHT, Common_Movement_WalkInPlaceDown
	waitmovement 0
	release
	end

Route205South2_EventScript_Girl_Notice_Top::
	lock
	addvar VAR_ROUTE205_SOUTH_2_STATE, 1
	applymovement LOCALID_ROUTE205_GIRL, Common_Movement_WalkInPlaceUp
	waitmovement 0
	applymovement LOCALID_ROUTE205_GIRL, Common_Movement_ExclamationMark
	playse SE_PIN
	delay 96
	applymovement LOCALID_ROUTE205_GIRL, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox Route205South2_Text_Girl, MSGBOX_AUTOCLOSE
	release
	end

Route205South2_EventScript_Girl_Notice_Top_Middle::
	lock
	addvar VAR_ROUTE205_SOUTH_2_STATE, 1
	applymovement LOCALID_ROUTE205_GIRL, Common_Movement_WalkInPlaceUp
	waitmovement 0
	applymovement LOCALID_ROUTE205_GIRL, Common_Movement_ExclamationMark
	playse SE_PIN
	delay 96
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox Route205South2_Text_Girl, MSGBOX_AUTOCLOSE
	release
	end

Route205South2_EventScript_Girl_Notice_Bottom_Middle::
	lock
	addvar VAR_ROUTE205_SOUTH_2_STATE, 1
	applymovement LOCALID_ROUTE205_GIRL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement LOCALID_ROUTE205_GIRL, Common_Movement_ExclamationMark
	playse SE_PIN
	delay 96
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox Route205South2_Text_Girl, MSGBOX_AUTOCLOSE
	release
	end

Route205South2_EventScript_Girl_Notice_Bottom::
	lock
	addvar VAR_ROUTE205_SOUTH_2_STATE, 1
	applymovement LOCALID_ROUTE205_GIRL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement LOCALID_ROUTE205_GIRL, Common_Movement_ExclamationMark
	playse SE_PIN
	delay 96
	applymovement LOCALID_ROUTE205_GIRL, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox Route205South2_Text_Girl, MSGBOX_AUTOCLOSE
	release
	end

Route205South2_EventScript_Girl::
	lock
	faceplayer
	compare VAR_ROUTE205_SOUTH_2_STATE, 1
	goto_if_eq Route205South2_EventScript_Girl_Second_Dialog
	compare VAR_ROUTE205_SOUTH_2_STATE, 0
	call_if_eq Route205South2_EventScript_Girl_AddVar
	msgbox Route205South2_Text_Girl, MSGBOX_AUTOCLOSE
	release
	end

Route205South2_EventScript_Girl_Second_Dialog::
	msgbox Route205South2_Text_Girl_Second_Dialog, MSGBOX_AUTOCLOSE
	release
	end

Route205South2_EventScript_Girl_AddVar:
	addvar VAR_ROUTE205_SOUTH_2_STATE, 1
	return

Route205South2_EventScript_Galactic_Dialog_Left::
	lock
	msgbox Route205South2_Text_Galactic_Roadblock_Left, MSGBOX_DEFAULT
	release
	end

Route205South2_EventScript_Galactic_Dialog_Right::
	lock
	msgbox Route205South2_Text_Galactic_Roadblock_Right, MSGBOX_DEFAULT
	release
	end

Route205South2_Text_Galactic_Roadblock_Left:
	.string "We, Team Galactic, are conducting\n"
	.string "research in the Eterna Forest!\p"
	.string "This is as far as you will go!$"

Route205South2_Text_Galactic_Roadblock_Right:
	.string "Our research involves catching Pokémon\n"
	.string "in the flowery meadows of Floaroma.\p"
	.string "We are also covertly stealing the\n"
	.string "energy of the Valley Windworks.\p"
	.string "But that is of no concern to you!$"

Route205South2_Text_Girl:
	.string "Help, help, Trainer!\n"
	.string "Please, I want to see my papa.\p"
	.string "My papa and I lived at the Valley\n"
	.string "Windworks.\p"
	.string "But then a whole bunch of people\n"
	.string "dressed like spacemen came...\p"
	.string "They kicked me out, and they’re making\n"
	.string "my papa do something.\p"
	.string "Please, Trainer!\n"
	.string "I miss my papa!$"

Route205South2_Text_Girl_Second_Dialog:
	.string "Please, Trainer! I want to see my papa.\n"
	.string "He’s at the Valley Windworks...$"
