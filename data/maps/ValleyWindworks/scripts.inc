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
	msgbox ValleyWindworks_Text_Galactic_Grunt, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WINDWORKS_VALLEY_GRUNT, ValleyWindworks_Text_Galactic_Grunt_Defeat
	msgbox ValleyWindworks_Text_Galactic_Grunt_PostBattle, MSGBOX_AUTOCLOSE
	closemessage
	applymovement LOCALID_GALACTIC_GRUNT, Common_Movement_WalkInPlaceUp
	waitmovement 0
	removeobject LOCALID_GALACTIC_GRUNT
	playse SE_DOOR
	setflag FLAG_HIDE_VALLEYWINDWORKS_GALACTIC_GRUNT
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
	setflag FLAG_HIDE_VALLEYWINDWORKS_DOOR_LOCK
	removeitem ITEM_WORKS_KEY
	release
	end

ValleyWindworks_Text_Galactic_Grunt:
	.string "Don't you dare go into the Valley\n"
	.string "Windworks.\p"
	.string "I got ordered to keep everyone out\n"
	.string "if they're not part of Team Galactic\p"
	.string "You're giving me a look that makes\n"
	.string "me think you're gonna try to get in.\p"
	.string "OK, then.\n"
	.string "You'll have to battle me for it!$"

ValleyWindworks_Text_Galactic_Grunt_Defeat:
	.string "Yeah, like I'm really supposed to\n"
	.string "win with a Pokémon like this...$"

ValleyWindworks_Text_Galactic_Grunt_PostBattle:
	.string "Isn't that just great.\n"
	.string "Getting defeated by some kid.\p"
	.string "But you can't do a thing if I lock\n"
	.string "myself in with my Works Key!\p"
	.string "That's right, the other Works Key's\n"
	.string "not here!\p"
	.string "My cohorts in the flower patch have\n"
	.string "the only other one!\p"
	.string "Hahaha! In that sense, I'm no longer\n"
	.string "the loser!$"

ValleyWindworks_Text_Locked:
	.string "It's locked from inside!$"

ValleyWindworks_Text_Key:
	.string "Use the Works Key?$"

ValleyWindworks_Text_Unlocked:
	.string "Ker-chunk!\p"
	.string "The door to Valley Windworks opened!$"
