SandgemTown_ProfessorRowansLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SandgemTown_ProfessorRowansLab_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, SandgemTown_ProfessorRowansLab_OnFrame
	.byte 0

	@ State descriptions for VAR_SANDGEM_LAB_STATE
	@ 1: Received pokedex

SandgemTown_ProfessorRowansLab_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

SandgemTown_ProfessorRowansLab_OnFrame:
	map_script_2 VAR_SANDGEM_LAB_STATE, 0, SandgemTown_ProfessorRowansLab_EventScript_ShowStarter
	.2byte 0

SandgemTown_ProfessorRowansLab_EventScript_ShowStarter::
	lockall
	setvar VAR_SANDGEM_LAB_STATE, 1
	delay 48
	special SpawnCameraObject
	applymovement LOCALID_PLAYER, SandgemTown_ProfessorRowansLab_Movement_Player1
	applymovement LOCALID_CAMERA, SandgemTown_ProfessorRowansLab_Movement_Player1
	applymovement LOCALID_SANDGEM_LAB_HELPER, SandgemTown_ProfessorRowansLab_Movement_Helper1
	waitmovement 0
	special RemoveCameraObject
	msgbox SandgemTown_ProfessorRowansLab_Text_LetMeSee, MSGBOX_DEFAULT
  @ // FODO: Add animation of giving item
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 48
	delay 48
	msgbox SandgemTown_ProfessorRowansLab_Text_SeemsHappy, MSGBOX_SIGN
  @ // FODO: Add animation of taking item back
	bufferleadmonspeciesname STR_VAR_1
	msgbox SandgemTown_ProfessorRowansLab_Text_GiveGift, MSGBOX_DEFAULT
	msgbox SandgemTown_ProfessorRowansLab_Text_GiveNickname, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, SandgemTown_ProfessorRowansLab_EventScript_NicknameStarter
	bufferleadmonspeciesname STR_VAR_1
	msgbox SandgemTown_ProfessorRowansLab_Text_EntrustYou, MSGBOX_SIGN
	applymovement LOCALID_SANDGEM_LAB_HELPER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, SandgemTown_ProfessorRowansLab_EventScript_KindDawn
	call_if_eq VAR_RESULT, FEMALE, SandgemTown_ProfessorRowansLab_EventScript_KindLucas
	applymovement LOCALID_SANDGEM_LAB_HELPER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 48
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	applymovement LOCALID_SANDGEM_LAB_PROF, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 16
	msgbox SandgemTown_ProfessorRowansLab_Text_CollectData, MSGBOX_DEFAULT
	goto SandgemTown_ProfessorRowansLab_EventScript_AskHelp

SandgemTown_ProfessorRowansLab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	msgbox SandgemTown_ProfessorRowansLab_Text_HappyNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SandgemTown_ProfessorRowansLab_EventScript_NicknameStarter
	return

SandgemTown_ProfessorRowansLab_EventScript_AskHelp::
	msgbox SandgemTown_ProfessorRowansLab_Text_RecordData, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, SandgemTown_ProfessorRowansLab_EventScript_DenyHelp
	goto SandgemTown_ProfessorRowansLab_EventScript_GivePokedex

SandgemTown_ProfessorRowansLab_EventScript_DenyHelp::
	msgbox SandgemTown_ProfessorRowansLab_Text_PatientMan, MSGBOX_DEFAULT
	goto SandgemTown_ProfessorRowansLab_EventScript_AskHelp

SandgemTown_ProfessorRowansLab_EventScript_GivePokedex::
	msgbox SandgemTown_ProfessorRowansLab_Text_GoodAnswer, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message SandgemTown_ProfessorRowansLab_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_ADVENTURE_STARTED
	special SetUnlockedPokedexFlags
	msgbox SandgemTown_ProfessorRowansLab_Text_ExplainPokedex, MSGBOX_DEFAULT
	applymovement LOCALID_SANDGEM_LAB_HELPER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 16
	checkplayergender
	call_if_eq VAR_RESULT, MALE, SandgemTown_ProfessorRowansLab_EventScript_GotOneDawn
	call_if_eq VAR_RESULT, FEMALE, SandgemTown_ProfessorRowansLab_EventScript_GotOneLucas
	msgbox SandgemTown_ProfessorRowansLab_Text_SixtyYears, MSGBOX_SIGN
	applymovement LOCALID_SANDGEM_LAB_HELPER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, SandgemTown_ProfessorRowansLab_EventScript_Helper_DawnMany
	call_if_eq VAR_RESULT, FEMALE, SandgemTown_ProfessorRowansLab_EventScript_ComradesLucas
	applymovement LOCALID_PLAYER, SandgemTown_ProfessorRowansLab_Movement_Player2
	applymovement LOCALID_SANDGEM_LAB_HELPER, SandgemTown_ProfessorRowansLab_Movement_Helper2
	waitmovement 0
	removeobject LOCALID_SANDGEM_LAB_HELPER
	setflag FLAG_HIDE_SANDGEM_LAB_HELPER
	setvar VAR_TWINLEAF_TOWN_STATE, 4
	setvar VAR_TWINLEAF_INTRO_STATE, 8
	releaseall
	end
	
SandgemTown_ProfessorRowansLab_EventScript_KindDawn::
	msgbox SandgemTown_ProfessorRowansLab_Text_KindDawn, MSGBOX_SIGN
	return
	
SandgemTown_ProfessorRowansLab_EventScript_GotOneDawn::
	msgbox SandgemTown_ProfessorRowansLab_Text_GotOneDawn, MSGBOX_DEFAULT
	return

SandgemTown_ProfessorRowansLab_EventScript_Helper_DawnMany::
	switch VAR_STARTER_MON
	case 0, SandgemTown_ProfessorRowansLab_EventScript_Helper_Dawn3
	case 1, SandgemTown_ProfessorRowansLab_EventScript_Helper_Dawn4
	case 2, SandgemTown_ProfessorRowansLab_EventScript_Helper_Dawn5
	return
	
SandgemTown_ProfessorRowansLab_EventScript_Helper_Dawn3::
	msgbox SandgemTown_ProfessorRowansLab_Text_PiplupDawn, MSGBOX_DEFAULT
	msgbox SandgemTown_ProfessorRowansLab_Text_LikeYouDawn, MSGBOX_SIGN
	return
	
SandgemTown_ProfessorRowansLab_EventScript_Helper_Dawn4::
	msgbox SandgemTown_ProfessorRowansLab_Text_TurtwigDawn, MSGBOX_DEFAULT
	msgbox SandgemTown_ProfessorRowansLab_Text_LikeYouDawn, MSGBOX_SIGN
	return
	
SandgemTown_ProfessorRowansLab_EventScript_Helper_Dawn5::
	msgbox SandgemTown_ProfessorRowansLab_Text_ChimcharDawn, MSGBOX_DEFAULT
	msgbox SandgemTown_ProfessorRowansLab_Text_LikeYouDawn, MSGBOX_SIGN
	return
	
SandgemTown_ProfessorRowansLab_EventScript_KindLucas::
	msgbox SandgemTown_ProfessorRowansLab_Text_KindLucas, MSGBOX_SIGN
	return
	
SandgemTown_ProfessorRowansLab_EventScript_GotOneLucas::
	msgbox SandgemTown_ProfessorRowansLab_Text_GotOneLucas, MSGBOX_DEFAULT
	return
	
SandgemTown_ProfessorRowansLab_EventScript_ComradesLucas::
	msgbox SandgemTown_ProfessorRowansLab_Text_ComradesLucas, MSGBOX_SIGN
	return

SandgemTown_ProfessorRowansLab_Movement_Player1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

SandgemTown_ProfessorRowansLab_Movement_Player2:
	delay_16
	walk_in_place_down
	step_end

SandgemTown_ProfessorRowansLab_Movement_Helper1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_in_place_left
	step_end

SandgemTown_ProfessorRowansLab_Movement_Helper2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

SandgemTown_ProfessorRowansLab_EventScript_Birch::
	lock
	faceplayer
	msgbox SandgemTown_ProfessorRowansLab_Text_GrandAdventure, MSGBOX_NPC
	@ goto_if_unset FLAG_HAS_MATCH_CALL, SandgemTown_ProfessorRowansLab_EventScript_TryRatePokedexOrRegister
	@ goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
	@ goto SandgemTown_ProfessorRowansLab_EventScript_TryRatePokedexOrRegister
	end

@ SandgemTown_ProfessorRowansLab_EventScript_TryRatePokedexOrRegister::
@ 	@ TODO: Check var below
@ 	goto_if_unset FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380, ProfBirch_EventScript_RatePokedexOrRegister
@ 	release
@ 	end

SandgemTown_ProfessorRowansLab_EventScript_Aide::
	lock
	faceplayer
	release
	end

SandgemTown_ProfessorRowansLab_EventScript_PC::
	msgbox SandgemTown_ProfessorRowansLab_Text_PC, MSGBOX_SIGN
	end

SandgemTown_ProfessorRowansLab_EventScript_Bookshelf1::
	msgbox SandgemTown_ProfessorRowansLab_Text_Bookshelf1, MSGBOX_SIGN
	end

SandgemTown_ProfessorRowansLab_EventScript_Bookshelf2::
	msgbox SandgemTown_ProfessorRowansLab_Text_Bookshelf2, MSGBOX_SIGN
	end

SandgemTown_ProfessorRowansLab_EventScript_Bookshelf3::
	msgbox SandgemTown_ProfessorRowansLab_Text_Bookshelf3, MSGBOX_SIGN
	end

SandgemTown_ProfessorRowansLab_EventScript_Bookshelf4::
	msgbox SandgemTown_ProfessorRowansLab_Text_Bookshelf4, MSGBOX_SIGN
	end

SandgemTown_ProfessorRowansLab_EventScript_Fridge::
	msgbox SandgemTown_ProfessorRowansLab_Text_Fridge, MSGBOX_SIGN
	end

SandgemTown_ProfessorRowansLab_EventScript_DawnsFather::
	msgbox SandgemTown_ProfessorRowansLab_Text_DawnsFather, MSGBOX_NPC
	end

SandgemTown_ProfessorRowansLab_EventScript_OtherAide::
	msgbox SandgemTown_ProfessorRowansLab_Text_OtherAide, MSGBOX_NPC
	end

SandgemTown_ProfessorRowansLab_Text_LetMeSee:
	.string "Professor: Well, well, look who's here.\p"
	.string "{PLAYER}, was it?\p"
	.string "Let's have a look at your Pokémon.$"

SandgemTown_ProfessorRowansLab_Text_SeemsHappy:
	.string "...\p"
	.string "Hmm...\n"
	.string "I see...\p"
	.string "This Pokémon seems to be rather\n"
	.string "happy.$"

SandgemTown_ProfessorRowansLab_Text_GiveGift:
	.string "Hm!\p"
	.string "Entrusting you with that {STR_VAR_1}\n"
	.string "was no mistake, it seems!$"

SandgemTown_ProfessorRowansLab_Text_GiveNickname:
	.string "Professor: Well, would you like to give\n"
	.string "it a nickname?$"

SandgemTown_ProfessorRowansLab_Text_HappyNickname:
	.string "Professor: Hmm, OK, I see...\n"
	.string "And you're happy with that nickname?$"
	
SandgemTown_ProfessorRowansLab_Text_EntrustYou:
	.string "Professor: When I first saw you two\n"
	.string "about to step into the tall grass\l"
	.string "without Pokémon, I was shocked.\p"
	.string "I was astounded by these foolhardy\n"
	.string "children.\p"
	.string "But now, you've astounded me in an\n"
	.string "entirely different way.\p"
	.string "Already, there is a bond growing\n"
	.string "between you and that Pokémon.\p"
	.string "I feel privileged to have met you.\p"
	.string "I'm sure {STR_VAR_1} feels the same\n"
	.string "way about you.\p"
	.string "That's why I'll ask you to cherish that\n"
	.string "{STR_VAR_1} of yours.$"

SandgemTown_ProfessorRowansLab_Text_CollectData:
	.string "Professor: Er-hem!\n"
	.string "Let's move on to the main topic.\p"
	.string "There is something I want you to do\n"
	.string "for me.\p"
	.string "Allow me to properly introduce myself\n"
	.string "first.\p"
	.string "My name, as you know, is Rowan.\n"
	.string "I study Pokémon.\p"
	.string "First of all, I want to know exactly\n"
	.string "what kinds of Pokémon live in the\l"
	.string "Sinnoh region.\p"
	.string "To do so, it is necessary to collect\n"
	.string "data using the Pokédex.\p"
	.string "This is what I wish to ask of you.$"

SandgemTown_ProfessorRowansLab_Text_RecordData:
	.string "I want to entrust you with this\n"
	.string "Pokédex.\p"
	.string "Will you use it to record data on all\n"
	.string "the Pokémon in Sinnoh for me?$"

SandgemTown_ProfessorRowansLab_Text_PatientMan:
	.string "Rowan: ...\p"
	.string "...\p"
	.string "...\p"
	.string "...\p"
	.string "I can stand here without speaking for\n"
	.string "hours. I'm a very patient man.\p"
	.string "Let me ask you again, {PLAYER}.$"

SandgemTown_ProfessorRowansLab_Text_GoodAnswer:
	.string "Rowan: Hm!\p"
	.string "Good answer!$"

SandgemTown_ProfessorRowansLab_Text_ReceivedPokedex:
	.string "{PLAYER} obtained\n"
	.string "the Pokédex!$"

SandgemTown_ProfessorRowansLab_Text_ExplainPokedex:
	.string "Rowan: That Pokédex is a very\n"
	.string "high-tech device\p"
	.string "It will automatically record data on\n"
	.string "every kind of Pokémon you encounter.\p"
	.string "{PLAYER}, I ask that you go\n"
	.string "everywhere and meet every kind of\l"
	.string "Pokémon in this region!$"

SandgemTown_ProfessorRowansLab_Text_SixtyYears:
	.string "Rowan: When you walked up Route 201\n"
	.string "with your Pokémon, what did you feel?\p"
	.string "I've lived for 60 long years.\n"
	.string "Even now, I get a thrill when\p"
	.string "I'm with a Pokémon.\p"
	.string "Now, you should know that there are\n"
	.string "countless Pokémon in this world.\p"
	.string "This mean there are just as many\n"
	.string "thrills waiting for you out there!\p"
	.string "Now go!\p"
	.string "{PLAYER}, your grand adventure\n"
	.string "begins right now!$"

SandgemTown_ProfessorRowansLab_Text_GrandAdventure:
	.string "Rowan: Go on!\p"
	.string "{PLAYER}, your grand adventure\n"
	.string "awaits you!$"

SandgemTown_ProfessorRowansLab_Text_KindDawn:
	.string "Dawn: I'm so glad that you're kind\n"
	.string "toward Pokémon!\p"
	.string "If you weren't, I'd have to...\n"
	.string "Oh, I just can't say it...$"

SandgemTown_ProfessorRowansLab_Text_GotOneDawn:
	.string "Dawn: I've got one, too!$"

SandgemTown_ProfessorRowansLab_Text_PiplupDawn:
	.string "Dawn: The Pokémon that I used for\n"
	.string "the first time was a PIPLUP!\p"
	.string "If you would have chosen\n"
	.string "a PIPLUP at the lake, we'd have the\l"
	.string "same Pokémon now!$"

SandgemTown_ProfessorRowansLab_Text_TurtwigDawn:
	.string "Dawn: The Pokémon that I used for\n"
	.string "the first time was a TURTWIG!\p"
	.string "If you would have chosen\n"
	.string "a TURTWIG at the lake, we'd have the\l"
	.string "same Pokémon now!$"

SandgemTown_ProfessorRowansLab_Text_ChimcharDawn:
	.string "Dawn: The Pokémon that I used for\n"
	.string "the first time was a CHIMCHAR!\p"
	.string "If you would have chosen\n"
	.string "a CHIMCHAR at the lake, we'd have the\l"
	.string "same Pokémon now!$"

SandgemTown_ProfessorRowansLab_Text_LikeYouDawn:
	.string "Not that it matters, but...\p"
	.string "Anyways, I'm Dawn.\p"
	.string "I also help the professor add pages\n"
	.string "to the Pokédex.\p"
	.string "So, in a sense, I'm just like you.\p"
	.string "I just got a little head start on you,\n"
	.string "that's all.\p"
	.string "I'll be happy to teach you things.\n"
	.string "Glad to meet you, {PLAYER}!$"

SandgemTown_ProfessorRowansLab_Text_KindLucas:
	.string "Lucas: Boy, am I glad you're kind\n"
	.string "toward Pokémon.\p"
	.string "If you weren't, well...\n"
	.string "I don't even want to think about it.$"

SandgemTown_ProfessorRowansLab_Text_GotOneLucas:
	.string "Lucas: I've got the same kind of\n"
	.string "Pokédex as you.$"

SandgemTown_ProfessorRowansLab_Text_ComradesLucas:
	.string "Lucas: The professor asked me to help,\n"
	.string "so I'm filling the Pokédex pages, too.\p"
	.string "That makes us comrades working\n"
	.string "toward the same goal.\p"
	.string "I'll teach you stuff later, OK?$"

SandgemTown_ProfessorRowansLab_Text_PC:
	.string "{PLAYER} checked the PC.\p"
	.string "The screen is filled with special terms\n"
	.string "and academic writing that is impossible\l"
	.string "to figure out.$"

SandgemTown_ProfessorRowansLab_Text_Bookshelf1:
	.string "Adventure Rule No. 1\n"
	.string "The X Button opens the menu.$"

SandgemTown_ProfessorRowansLab_Text_Bookshelf2:
	.string "Adventure Rule No. 2\n"
	.string "Record your progress with SAVE.$"

SandgemTown_ProfessorRowansLab_Text_Bookshelf3:
	.string "It's crammed full of books with all\n"
	.string "sorts of Pokémon information.$"

SandgemTown_ProfessorRowansLab_Text_Bookshelf4:
	.string "There's a lot of reference material\n"
	.string "and research reports on Pokémon.$"

SandgemTown_ProfessorRowansLab_Text_Fridge:
	.string "The refrigerator is filled with\n"
	.string "tasty sweet! Hmm...$"

SandgemTown_ProfessorRowansLab_Text_DawnsFather:
	.string "I'm Dawn's father.\p"
	.string "I'll be happy to assist you on your\n"
	.string "quest for the professor.\p"
	.string "Hahaha. Eh...\n"
	.string "I'm sure we can count on you!$"

SandgemTown_ProfessorRowansLab_Text_OtherAide:
	.string "Professor Rowan invented a new\n"
	.string "Pokédex while working alongside a\l"
	.string "professor from the Kanto region!$"
