ValleyWindworks_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ValleyWindworks_OnFrame
	.byte 0

@ State descriptions for VAR_ROUTE205_SOUTH_2_STATE
@ 1: Talked to the girl
@ 2: Entered Windworks Valley Indoors
@ 3: Defeated Mars
@ 4: Met Looker in Valley Windworks

ValleyWindworks_OnFrame::
	map_script_2 VAR_ROUTE205_SOUTH_2_STATE, 3, ValleyWindworks_EventScript_Looker
	.2byte 0

ValleyWindworks_EventScript_Looker::
	lock
	addobject LOCALID_VALLEY_WINDWORKS_LOOKER
	delay 8
	applymovement LOCALID_VALLEY_WINDWORKS_LOOKER, Common_Movement_ExclamationMark
	playse SE_PIN
	delay 64
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	applymovement LOCALID_VALLEY_WINDWORKS_LOOKER, ValleyWindworks_Movement_Looker
	waitmovement 0
	msgbox ValleyWindworks_Text_Looker, MSGBOX_AUTOCLOSE
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_VALLEY_WINDWORKS_LOOKER, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_VALLEY_WINDWORKS_LOOKER, Common_Movement_FaceUp
	waitmovement 0
	delay 8
	removeobject LOCALID_VALLEY_WINDWORKS_LOOKER
	playse SE_DOOR
	delay 210
	clearflag FLAG_HIDE_VALLEY_WINDWORKS_LOOKER
	addobject LOCALID_VALLEY_WINDWORKS_LOOKER
	setobjectxy LOCALID_VALLEY_WINDWORKS_LOOKER, 19, 13
	applymovement LOCALID_VALLEY_WINDWORKS_LOOKER, Common_Movement_FaceDown
	playse SE_DOOR
	delay 8
	msgbox ValleyWindworks_Text_Looker_2, MSGBOX_AUTOCLOSE
	applymovement LOCALID_VALLEY_WINDWORKS_LOOKER, ValleyWindworks_Movement_Looker_2
	delay 16
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceLeft
	delay 8
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement LOCALID_VALLEY_WINDWORKS_LOOKER
	removeobject LOCALID_VALLEY_WINDWORKS_LOOKER
	setflag FLAG_HIDE_VALLEY_WINDWORKS_LOOKER
	setvar VAR_ROUTE205_SOUTH_2_STATE, 4
	release
	end

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
	setflag FLAG_HIDE_VALLEYWINDWORKS_DOOR_LOCK
	removeitem ITEM_WORKS_KEY
	release
	end

ValleyWindworks_Movement_Looker:
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	face_right
	step_end

ValleyWindworks_Movement_Looker_2:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	step_end

ValleyWindworks_Text_Looker:
	.string "Looker: Ah, yes.\n"
	.string "It is you, yes.\p"
	.string "I have heard that the Team Galactic\n"
	.string "appeared at this power plant.\p"
	.string "I have, therefore, come running.\n"
	.string "So, the Team Galactic. Where are they?\p"
	.string "...\p"
	.string "You have run them off, you say?\n"
	.string "You are a Trainer, but...?\p"
	.string "Very well!\n"
	.string "I shall go investigate inside!$"

ValleyWindworks_Text_Looker_2:
	.string "Looker: Magnificent! Yes, it is!\n"
	.string "What you have said, it is all true!\p"
	.string "Superb! Though you are young, you are\n"
	.string "a Trainer through and through!\p"
	.string "Very well!\n"
	.string "I shall pursue the culprits!\p"
	.string "I have received tips that the Team\n"
	.string "Galactic hideout is in Eterna City.\p"
	.string "To there, I must be off!$"

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

ValleyWindworks_Text_Kerchunk:
	.string "Ker-chunk!$"
