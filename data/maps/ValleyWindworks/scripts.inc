ValleyWindworks_MapScripts::
	.byte 0

ValleyWindworks_EventScript_Sign::
	msgbox ValleyWindworks_Text_WindDrivenEnergy, MSGBOX_SIGN
	end

ValleyWindworks_Text_WindDrivenEnergy:
	.string "Valley Windworks\n"
	.string "Ecological, Wind-Driven Energy$"

ValleyWindworks_EventScript_Galactic_Grunt::
	lock
	faceplayer
	trainerbattle_single TRAINER_VALLEY_WINDWORKS_GRUNT_1, ValleyWindworks_Text_Galactic_Grunt1_Intro, ValleyWindworks_Text_Galactic_Grunt1_Defeated
	msgbox ValleyWindworks_Text_Galactic_Grunt1_PostBattle, MSGBOX_AUTOCLOSE
	closemessage
	applymovement LOCALID_GALACTIC_GRUNT, Common_Movement_WalkInPlaceUp
	waitmovement 0
	removeobject LOCALID_GALACTIC_GRUNT
	playse SE_DOOR
	setflag FLAG_HIDE_WINDWORKS_GALACTIC_GRUNT
	delay 12
	msgbox ValleyWindworks_Text_Kerchunk, MSGBOX_AUTOCLOSE
	release
	end

ValleyWindworks_EventScript_Locked::
	lock
	msgbox ValleyWindworks_Text_Locked, MSGBOX_DEFAULT
	checkitem ITEM_WORKS_KEY
	compare VAR_RESULT, TRUE
	goto_if_eq ValleyWindworks_EventScript_Use_Key
	release
	end

ValleyWindworks_EventScript_Use_Key::
    msgbox ValleyWindworks_Text_Key, MSGBOX_YESNO
    compare VAR_RESULT, 1
    goto_if_eq ValleyWindworks_EventScript_Unlock
	release
	end

ValleyWindworks_EventScript_Unlock::
	msgbox ValleyWindworks_Text_Unlocked, MSGBOX_AUTOCLOSE
	removeobject LOCALID_DOOR_LOCK
	setflag FLAG_HIDE_WINDWORKS_LOCK
	removeitem ITEM_WORKS_KEY
	release
	end

ValleyWindworks_Text_Locked:
	.string "It's locked from inside!$"

ValleyWindworks_Text_Key:
	.string "Use the Works Key?$"

ValleyWindworks_Text_Unlocked:
	.string "Ker-chunk!\p"
	.string "The door to Valley Windworks opened!$"

ValleyWindworks_Text_Kerchunk:
	.string "Ker-chunk!$"
