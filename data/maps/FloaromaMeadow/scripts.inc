@ State descriptions for VAR_FLOAROMA_MEADOW_STATE
@ 1: Player recieved the Works Key

FloaromaMeadow_MapScripts::
	.byte 0

FloaromaMeadow_EventScript_Galactic_Right::
	setvar VAR_0x8007, TRUE
	goto FloaromaMeadow_EventScript_Galactic

FloaromaMeadow_EventScript_Galactic_Left::
	setvar VAR_0x8007, FALSE
	goto FloaromaMeadow_EventScript_Galactic

FloaromaMeadow_EventScript_Galactic::
	lock
	msgbox FloaromaMeadow_Text_Galactic_Intro, MSGBOX_DEFAULT
	applymovement LOCALID_GRUNT_1, Common_Movement_WalkInPlaceDown
	applymovement LOCALID_GRUNT_2, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement LOCALID_GRUNT_1, Common_Movement_ExclamationMark
	applymovement LOCALID_GRUNT_2, Common_Movement_ExclamationMark
	playse SE_PIN
	delay 48
	msgbox FloaromaMeadow_Text_Galactic_PreBattle, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_FLOAROMA_MEADOW_GRUNT, FloaromaMeadow_Text_Galactic_Grunt1_Defeat
	msgbox FloaromaMeadow_Text_Galactic_Grunt1_AfterBattle, MSGBOX_AUTOCLOSE
	trainerbattle_no_intro TRAINER_FLOAROMA_MEADOW_GRUNT_2, FloaromaMeadow_Text_Galactic_Grunt2_Defeat
	msgbox FloaromaMeadow_Text_Galactic_Grunt2_AfterBattle, MSGBOX_AUTOCLOSE
	fadescreen 1
	setflag FLAG_HIDE_FLOAROMA_MEADOW_GALACTIC_EVENT
	clearflag FLAG_HIDE_FLOAROMA_MEADOW_WORKS_KEY_EVENT
	removeobject LOCALID_GRUNT_1
	removeobject LOCALID_GRUNT_2
	addobject LOCALID_WORKS_KEY_BALL
	fadescreen 0
	applymovement LOCALID_MAN, Common_Movement_WalkDown
	waitmovement 0
	applymovement LOCALID_MAN, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 32
	setflag FLAG_HIDE_FLOAROMA_MEADOW_WORKS_KEY_EVENT
	addvar VAR_FLOAROMA_MEADOW_STATE, 1
	removeobject LOCALID_WORKS_KEY_BALL
	compare VAR_0x8007, TRUE
	goto_if_eq FloaromaMeadow_EventScript_Galactic_Outro_Right
	goto FloaromaMeadow_EventScript_Galactic_Outro_Left

FloaromaMeadow_EventScript_Galactic_Outro_Right::
	applymovement LOCALID_MAN, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_MAN, Common_Movement_WalkInPlaceDown
	waitmovement 0
	goto FloaromaMeadow_EventScript_Galactic_Outro

FloaromaMeadow_EventScript_Galactic_Outro_Left::
	applymovement LOCALID_MAN, Common_Movement_WalkInPlaceDown
	waitmovement 0
	goto FloaromaMeadow_EventScript_Galactic_Outro

FloaromaMeadow_EventScript_Galactic_Outro::
	msgbox FloaromaMeadow_Text_Galactic_Man, MSGBOX_DEFAULT
	giveitem ITEM_WORKS_KEY, 1
	msgbox FloaromaMeadow_Text_Galactic_Outro, MSGBOX_DEFAULT
	giveitem ITEM_HONEY, 1
	msgbox FloaromaMeadow_Text_Galactic_Outro2, MSGBOX_DEFAULT
	release
	end

FloaromaMeadow_Text_Galactic_Intro:
	.string "Grunt 1: Enough arguing!\n"
	.string "Hand over that sweet Honey!\p"
	.string "Grunt 2: Do as we say!\n"
	.string "Team Galactic will have that Honey!\p"
	.string "We must have it to attract Pokémon\n"
	.string "in great numbers!$"

FloaromaMeadow_Text_Galactic_PreBattle:
	.string "Grunt 1: Hey! This kid is a witness!\n"
	.string "What'll we do?\p"
	.string "Grunt 2: We don't need the brat\n"
	.string "running off to get help...\p"
	.string "The solution's simple!\n"
	.string "We ensure the brat stays quiet!$"

FloaromaMeadow_Text_Galactic_Grunt1_Defeat:
	.string "...This is why I'm gonna be stuck as\n"
	.string "a grunt forever...$"

FloaromaMeadow_Text_Galactic_Grunt1_AfterBattle:
	.string "Grunt 1: This is so lame...\n"
	.string "They're going to dock my pay!\p"
	.string "Grunt 2: I'm up next!\n"
	.string "Heheheh...\p"
	.string "Battling you right after my cohort\n"
	.string "weakened you gives me the edge!$"

FloaromaMeadow_Text_Galactic_Grunt2_Defeat:
	.string "...I want a promotion so I can get some\n"
	.string "tougher Pokémon...$"

FloaromaMeadow_Text_Galactic_Grunt2_AfterBattle:
	.string "Grunt 1: This brat's tough!\n"
	.string "Like, really, really, really tough!\p"
	.string "Tougher than I can put into words,\n"
	.string "and I know a lot of words!\p"
	.string "We're done for here... Let's get back\n"
	.string "to the Valley Windworks.$"

FloaromaMeadow_Text_Galactic_Man:
	.string "Oh, what's this thing?\n"
	.string "They seem to have forgotten it...\p"
	.string "It's a Works Key...\n"
	.string "It must be for the Valley Windworks!\p"
	.string "It's of no use to me.\n"
	.string "You may as well have it.$"

FloaromaMeadow_Text_Galactic_Outro:
	.string "Thank you!\n"
	.string "You surely saved me.\p"
	.string "Those goons were trying to rob me\n"
	.string "of my sweet, sweet Honey.\p"
	.string "They sure were weird, though.\n"
	.string "You saw how they were dressed.\p"
	.string "What they were saying didn't make\n"
	.string "a whole lot of sense, either.\p"
	.string "Oh! I need to thank you!\n"
	.string "This sweet, sweet Honey!\l"
	.string "Go on, take a whole lot!$"

FloaromaMeadow_Text_Galactic_Outro2:
	.string "Slather that Honey on a sweet-smell\n"
	.string "tree. It might attract Pokémon.$"
