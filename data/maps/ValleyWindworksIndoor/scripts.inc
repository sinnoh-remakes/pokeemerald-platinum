ValleyWindworksIndoor_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, ValleyWindworksIndoor_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, ValleyWindworksIndoor_OnFrame
	.byte 0

@ State descriptions for VAR_ROUTE205_SOUTH_2_STATE
@ 1: Talked to the girl
@ 2: Entered Windworks Valley Indoors
@ 3: Defeated Mars

ValleyWindworksIndoor_OnTransition::
	call_if_unset FLAG_DEFEATED_MARS, ValleyWindworksIndoor_EventScript_Set_Event_Position
	end

ValleyWindworksIndoor_EventScript_Set_Event_Position:
	setobjectxyperm LOCALID_VALLEYWINDWORKS_SCIENTIST, 20, 2
	return

ValleyWindworksIndoor_OnFrame::
	map_script_2 VAR_ROUTE205_SOUTH_2_STATE, 1, ValleyWindworksIndoor_1F_EventScript_Grunt_Intro
	.2byte 0

ValleyWindworksIndoor_1F_EventScript_Grunt_Intro::
	lock
	setvar VAR_ROUTE205_SOUTH_2_STATE, 2
	delay 8
	applymovement LOCALID_VALLEYWINDWORKS_GRUNT_INTRO, Common_Movement_ExclamationMark
	playse SE_PIN
	delay 48
	msgbox ValleyWindworksIndoor_Text_Grunt_Intro, MSGBOX_AUTOCLOSE
	applymovement LOCALID_VALLEYWINDWORKS_GRUNT_INTRO, ValleyWindworksIndoor_Movement_Grunt_Intro
	waitmovement 0
	setflag FLAG_HIDE_WINDWORKSVALLEY_GRUNT
	removeobject LOCALID_VALLEYWINDWORKS_GRUNT_INTRO
	release
	end

ValleyWindworksIndoor_EventScript_Grunt1::
	trainerbattle_single TRAINER_VALLEY_WINDWORKS_GRUNT_1, ValleyWindworksIndoor_Text_Grunt1Intro, ValleyWindworksIndoor_Text_Grunt1Defeated
	msgbox ValleyWindworksIndoor_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

ValleyWindworksIndoor_EventScript_Grunt2::
	trainerbattle_single TRAINER_VALLEY_WINDWORKS_GRUNT_2, ValleyWindworksIndoor_Text_Grunt2Intro, ValleyWindworksIndoor_Text_Grunt2Defeated
	msgbox ValleyWindworksIndoor_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

ValleyWindworksIndoor_EventScript_Grunt3::
	msgbox ValleyWindworksIndoor_Text_SmooshYou, MSGBOX_NPC
	end

ValleyWindworksIndoor_EventScript_Mars_Bottom::
	lock
	setvar VAR_0x800A, TRUE
	applymovement LOCALID_VALLEYWINDWORKS_MARS, Common_Movement_ExclamationMark
	playse SE_PIN
	delay 64
	goto ValleyWindworksIndoor_EventScript_Mars

ValleyWindworksIndoor_EventScript_Mars_Top::
	lock
	setvar VAR_0x800A, FALSE
	applymovement LOCALID_VALLEYWINDWORKS_MARS, Common_Movement_ExclamationMark
	playse SE_PIN
	delay 64
	applymovement LOCALID_VALLEYWINDWORKS_MARS, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_VALLEYWINDWORKS_MARS, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	goto ValleyWindworksIndoor_EventScript_Mars

ValleyWindworksIndoor_EventScript_Mars::
	msgbox ValleyWindworksIndoor_Text_Mars, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_VALLEYWINDWORKS_INDOOR_MARS, ValleyWindworksIndoor_Text_Mars_Defeat
	setflag FLAG_DEFEATED_MARS
	setvar VAR_ROUTE205_SOUTH_2_STATE, 3
	msgbox ValleyWindworksIndoor_Text_Mars_Post_Battle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VALLEYWINDWORKS_CHARON, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 32
	msgbox ValleyWindworksIndoor_Text_Charon, MSGBOX_DEFAULT
	applymovement LOCALID_VALLEYWINDWORKS_MARS, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox ValleyWindworksIndoor_Text_Mars_End, MSGBOX_DEFAULT
	applymovement LOCALID_VALLEYWINDWORKS_MARS, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox ValleyWindworksIndoor_Text_Mars_Goodbye, MSGBOX_DEFAULT
	closemessage
	fadescreen 1
	removeobject LOCALID_VALLEYWINDWORKS_CHARON
	removeobject LOCALID_VALLEYWINDWORKS_MARS
	removeobject LOCALID_VALLEYWINDWORKS_GRUNT_3
	removeobject LOCALID_VALLEYWINDWORKS_GRUNT_2
	removeobject LOCALID_VALLEYWINDWORKS_GRUNT_1
	fadescreen 0
	compare VAR_0x800A, TRUE
	goto_if_eq ValleyWindworksIndoor_EventScript_Mars_Outro_Top
	goto ValleyWindworksIndoor_EventScript_Mars_Outro_Bottom

ValleyWindworksIndoor_EventScript_Mars_Outro_Bottom::
	applymovement LOCALID_VALLEYWINDWORKS_SCIENTIST, ValleyWindworksIndoor_Movement_Scientist
	waitmovement 0
	goto ValleyWindworksIndoor_EventScript_Mars_Outro

ValleyWindworksIndoor_EventScript_Mars_Outro_Top::
	applymovement LOCALID_VALLEYWINDWORKS_SCIENTIST, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_VALLEYWINDWORKS_SCIENTIST, ValleyWindworksIndoor_Movement_Scientist
	waitmovement 0
	goto ValleyWindworksIndoor_EventScript_Mars_Outro

ValleyWindworksIndoor_EventScript_Mars_Outro::
	msgbox ValleyWindworksIndoor_Text_Scientist, MSGBOX_DEFAULT
	closemessage
	clearflag FLAG_HIDE_WINDWORKSVALLEY_INDOORS_GIRL
	addobject LOCALID_VALLEYWINDWORKS_GIRL
	setobjectxy LOCALID_VALLEYWINDWORKS_GIRL, 9, 7
	applymovement LOCALID_VALLEYWINDWORKS_GIRL, ValleyWindworksIndoor_Movement_Girl_1
	waitmovement 0
	compare VAR_0x800A, FALSE
	call_if_ne ValleyWindworksIndoor_EventScript_Girl_Walk_Up
	applymovement LOCALID_VALLEYWINDWORKS_GIRL, Common_Movement_WalkUpFast
	waitmovement 0
	applymovement LOCALID_VALLEYWINDWORKS_GIRL, ValleyWindworksIndoor_Movement_Girl_2
	waitmovement 0
	call_if_ne ValleyWindworksIndoor_EventScript_Girl_Face_Down
	call_if_eq ValleyWindworksIndoor_EventScript_Girl_Face_Up
	delay 8
	call_if_eq ValleyWindworksIndoor_EventScript_Scientist_WalkInPlace_Down
	call_if_ne ValleyWindworksIndoor_EventScript_Scientist_WalkInPlace_Up
	waitmovement 0
	msgbox ValleyWindworksIndoor_Text_Girl, MSGBOX_AUTOCLOSE
	applymovement LOCALID_VALLEYWINDWORKS_SCIENTIST, Common_Movement_FaceRight
	delay 32
	applymovement LOCALID_VALLEYWINDWORKS_SCIENTIST, Common_Movement_FaceLeft
	delay 32
	call_if_eq ValleyWindworksIndoor_EventScript_Scientist_Face_Down
	call_if_ne ValleyWindworksIndoor_EventScript_Scientist_Face_Up
	msgbox ValleyWindworksIndoor_Text_Scientist_End, MSGBOX_DEFAULT
	msgbox ValleyWindworksIndoor_Text_Balloon_Pokemon, MSGBOX_DEFAULT
	applymovement LOCALID_VALLEYWINDWORKS_GIRL, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	release
	end

ValleyWindworksIndoor_EventScript_Scientist_WalkInPlace_Down:
	applymovement LOCALID_VALLEYWINDWORKS_SCIENTIST, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

ValleyWindworksIndoor_EventScript_Scientist_WalkInPlace_Up:
	applymovement LOCALID_VALLEYWINDWORKS_SCIENTIST, Common_Movement_WalkInPlaceUp
	waitmovement 0
	return

ValleyWindworksIndoor_EventScript_Scientist_Face_Down:
	applymovement LOCALID_VALLEYWINDWORKS_SCIENTIST, Common_Movement_FaceDown
	return

ValleyWindworksIndoor_EventScript_Scientist_Face_Up:
	applymovement LOCALID_VALLEYWINDWORKS_SCIENTIST, Common_Movement_FaceUp
	return

ValleyWindworksIndoor_EventScript_Girl_Face_Down:
	applymovement LOCALID_VALLEYWINDWORKS_GIRL, Common_Movement_FaceDown
	return

ValleyWindworksIndoor_EventScript_Girl_Face_Up:
	applymovement LOCALID_VALLEYWINDWORKS_GIRL, Common_Movement_FaceUp
	return

ValleyWindworksIndoor_EventScript_Girl_Walk_Up:
	applymovement LOCALID_VALLEYWINDWORKS_GIRL, Common_Movement_WalkUpFast
	waitmovement 0
	return

ValleyWindworksIndoor_EventScript_Girl::
	lock
	faceplayer
	msgbox ValleyWindworksIndoor_Text_Balloon_Pokemon, MSGBOX_DEFAULT
	release
	end

ValleyWindworksIndoor_EventScript_Scientist::
	lock
	faceplayer
	msgbox ValleyWindworksIndoor_Text_Balloon_Pokemon_Explanation, MSGBOX_DEFAULT
	release
	end

ValleyWindworksIndoor_Text_SmooshYou:
	.string "My Pokémon can’t battle anymore.\p"
	.string "They’re gonna take away my Pokémon\n"
	.string "for messing this one up...\p"
	.string "Humph! Just you wait!\n"
	.string "Our Commander will smoosh you!$"

ValleyWindworksIndoor_Text_Mars:
	.string "I’m one of Team Galactic’s three\n"
	.string "Commanders.\p"
	.string "...No, wait.\n"
	.string "That’s one of four Commanders.\l"
	.string "My name is Mars!\p"
	.string "We’ve been trying to create a new\n"
	.string "world that’s better than this one...\p"
	.string "But people have shown little\n"
	.string "understanding about what we do.\p"
	.string "You don’t understand either, do you?\n"
	.string "It’s a little saddening...\p"
	.string "So, let’s have a battle to decide\n"
	.string "what we should do next.\p"
	.string "If I win, you leave.\p"
	.string "If you win, we, Team Galactic, will\n"
	.string "leave!$"

ValleyWindworksIndoor_Text_Mars_Defeat:
	.string "This can't be?! I lost?!\n"
	.string "You...you uppity brat!$"

ValleyWindworksIndoor_Text_Mars_Post_Battle:
	.string "Mars: Oops!\n"
	.string "I messed that one up!\p"
	.string "That’s all right, though.\n"
	.string "I quite enjoyed our battle.$"

ValleyWindworksIndoor_Text_Charon:
	.string "Charon: My, my.\n"
	.string "Lose to a child, will you?\p"
	.string "But, no matter.\n"
	.string "We’ve collected plenty of electricity.\p"
	.string "With the power we obtained, we can\n"
	.string "do something quite spectacular.\p"
	.string "It seems quite obvious to me, Charon,\n"
	.string "the genius even the boss recognizes.\p"
	.string "Now, Mars, we should be going.$"

ValleyWindworksIndoor_Text_Mars_End:
	.string "Mars: Will you shut it!\p"
	.string "The boss is the only person in the world\n"
	.string "who’s allowed to order me around!\p"
	.string "You can keep quiet around me!\n"
	.string "You only joined us recently.\l"
	.string "Don’t think you’re important!$"

ValleyWindworksIndoor_Text_Mars_Goodbye:
	.string "I guess it’s time to say good-bye\n"
	.string "and leave for the time being!$"

ValleyWindworksIndoor_Text_Scientist:
	.string "Team Galactic...\p"
	.string "They were saying they had to gather\n"
	.string "Pokémon and energy no matter what.\p"
	.string "It was for creating a new universe,\n"
	.string "or so they claimed.\p"
	.string "Nothing they said made any sort of\n"
	.string "sense to me.\p"
	.string "I can’t tell you how grateful I am for\n"
	.string "you saving me.\p"
	.string "I can finally see my little daughter\n"
	.string "again!$"

ValleyWindworksIndoor_Text_Girl:
	.string "Little girl: Papa!\p"
	.string "Yuck! Papa, you’re stinky!\n"
	.string "Go shower now, stinky!$"

ValleyWindworksIndoor_Text_Scientist_End:
	.string "Papa: Oh, sorry! Ahaha!\n"
	.string "They had me working nonstop!$"

ValleyWindworksIndoor_Text_Balloon_Pokemon:
	.string "Little girl: Thank you, Trainer!\n"
	.string "You made those bad people go away!\p"
	.string "I think the balloon Pokémon will\n" 
	.string "come visiting again!$"

ValleyWindworksIndoor_Text_Balloon_Pokemon_Explanation:
	.string "Papa: Oh, yes, a balloon Pokémon\n"
	.string "appears in front of the windworks.\p"
	.string "It’s always a certain day of the week,\n"
	.string "but I’m not sure which day.\p"
	.string "Could its appearance have something\n"
	.string "to do with this windworks using\l"
	.string "wind-generated energy?$"

ValleyWindworksIndoor_Text_Grunt_Intro:
	.string "What?! No way!\n"
	.string "You have the key?\p"
	.string "Locking the door was meaningless!\n"
	.string "I am the loser in this after all!\p"
	.string "This is no time for self-pity!\n"
	.string "I’ve got to alert the Commander!$"

ValleyWindworksIndoor_Movement_Scientist:
	walk_down
	walk_down
	walk_down
	walk_left
	step_end

ValleyWindworksIndoor_Movement_Girl_1:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

ValleyWindworksIndoor_Movement_Girl_2:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end

ValleyWindworksIndoor_Movement_Grunt_Intro:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end
