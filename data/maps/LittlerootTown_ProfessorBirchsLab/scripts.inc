.set LOCALID_PROF, 1
.set LOCALID_HELPER, 2
.set LOCALID_AIDE, 3

LittlerootTown_ProfessorBirchsLab_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_ProfessorBirchsLab_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_ProfessorBirchsLab_OnFrame
	.byte 0

	@ State descriptions for VAR_BIRCH_LAB_STATE
	@ 1: Received pokedex

LittlerootTown_ProfessorBirchsLab_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

LittlerootTown_ProfessorBirchsLab_OnFrame:
	map_script_2 VAR_BIRCH_LAB_STATE, 0, LittlerootTown_ProfessorBirchsLab_EventScript_ShowStarter
	.2byte 0

LittlerootTown_ProfessorBirchsLab_EventScript_ShowStarter::
	lockall
	setvar VAR_BIRCH_LAB_STATE, 1
	delay 48
	special SpawnCameraObject
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_Player1
	applymovement OBJ_EVENT_ID_CAMERA, LittlerootTown_ProfessorBirchsLab_Movement_Player1
	applymovement LOCALID_HELPER, LittlerootTown_ProfessorBirchsLab_Movement_Helper1
	waitmovement 0
	special RemoveCameraObject
	msgbox LittlerootTown_ProfessorBirchsLab_Text_LetMeSee, MSGBOX_DEFAULT
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 48
	delay 48
	bufferleadmonspeciesname STR_VAR_1
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SeemsHappy, MSGBOX_DEFAULT
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GiveNickname, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter
	bufferleadmonspeciesname STR_VAR_1
	msgbox LittlerootTown_ProfessorBirchsLab_Text_EntrustYou, MSGBOX_SIGN
	applymovement LOCALID_HELPER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_KindDawn
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_KindLucas
	applymovement LOCALID_HELPER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 48
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 16
	msgbox LittlerootTown_ProfessorBirchsLab_Text_CollectData, MSGBOX_DEFAULT
	goto LittlerootTown_ProfessorBirchsLab_EventScript_AskHelp

LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter::
	setvar VAR_0x8004, 0
	call Common_EventScript_NameReceivedPartyMon
	msgbox LittlerootTown_ProfessorBirchsLab_Text_HappyNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_NicknameStarter
	return

LittlerootTown_ProfessorBirchsLab_EventScript_AskHelp::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_RecordData, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, LittlerootTown_ProfessorBirchsLab_EventScript_DenyHelp
	goto LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex

LittlerootTown_ProfessorBirchsLab_EventScript_DenyHelp::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_PatientMan, MSGBOX_DEFAULT
	goto LittlerootTown_ProfessorBirchsLab_EventScript_AskHelp

LittlerootTown_ProfessorBirchsLab_EventScript_GivePokedex::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GoodAnswer, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex
	waitfanfare
	setflag FLAG_SYS_POKEDEX_GET
	setflag FLAG_RECEIVED_POKEDEX_FROM_BIRCH
	setflag FLAG_ADVENTURE_STARTED
	special SetUnlockedPokedexFlags
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex, MSGBOX_DEFAULT
	applymovement LOCALID_HELPER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 16
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_GotOneDawn
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_GotOneLucas
	msgbox LittlerootTown_ProfessorBirchsLab_Text_SixtyYears, MSGBOX_SIGN
	applymovement LOCALID_HELPER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LittlerootTown_ProfessorBirchsLab_EventScript_Helper_DawnMany
	call_if_eq VAR_RESULT, FEMALE, LittlerootTown_ProfessorBirchsLab_EventScript_ComradesLucas
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_ProfessorBirchsLab_Movement_Player2
	applymovement LOCALID_HELPER, LittlerootTown_ProfessorBirchsLab_Movement_Helper2
	waitmovement 0
	removeobject LOCALID_HELPER
	setvar VAR_LITTLEROOT_TOWN_STATE, 4
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	releaseall
	end
	
LittlerootTown_ProfessorBirchsLab_EventScript_KindDawn::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_KindDawn, MSGBOX_SIGN
	return
	
LittlerootTown_ProfessorBirchsLab_EventScript_GotOneDawn::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GotOneDawn, MSGBOX_DEFAULT
	return

LittlerootTown_ProfessorBirchsLab_EventScript_Helper_DawnMany::
	switch VAR_STARTER_MON
	case 0, LittlerootTown_ProfessorBirchsLab_EventScript_Helper_Dawn3
	case 1, LittlerootTown_ProfessorBirchsLab_EventScript_Helper_Dawn4
	case 2, LittlerootTown_ProfessorBirchsLab_EventScript_Helper_Dawn5
	return
	
LittlerootTown_ProfessorBirchsLab_EventScript_Helper_Dawn3::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_PiplupDawn, MSGBOX_DEFAULT
	msgbox LittlerootTown_ProfessorBirchsLab_Text_LikeYouDawn, MSGBOX_SIGN
	return
	
LittlerootTown_ProfessorBirchsLab_EventScript_Helper_Dawn4::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_TurtwigDawn, MSGBOX_DEFAULT
	msgbox LittlerootTown_ProfessorBirchsLab_Text_LikeYouDawn, MSGBOX_SIGN
	return
	
LittlerootTown_ProfessorBirchsLab_EventScript_Helper_Dawn5::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ChimcharDawn, MSGBOX_DEFAULT
	msgbox LittlerootTown_ProfessorBirchsLab_Text_LikeYouDawn, MSGBOX_SIGN
	return
	
LittlerootTown_ProfessorBirchsLab_EventScript_KindLucas::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_KindLucas, MSGBOX_SIGN
	return
	
LittlerootTown_ProfessorBirchsLab_EventScript_GotOneLucas::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GotOneLucas, MSGBOX_DEFAULT
	return
	
LittlerootTown_ProfessorBirchsLab_EventScript_ComradesLucas::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_ComradesLucas, MSGBOX_SIGN
	return

LittlerootTown_ProfessorBirchsLab_Movement_Player1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LittlerootTown_ProfessorBirchsLab_Movement_Player2:
	delay_16
	walk_in_place_down
	step_end

LittlerootTown_ProfessorBirchsLab_Movement_Helper1:
	walk_up
	walk_up
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

LittlerootTown_ProfessorBirchsLab_Movement_Helper2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

EventScript_RegisterProfBirch::
	msgbox MatchCall_Text_BirchRegisterCall, MSGBOX_DEFAULT
	closemessage
	delay 30
	playfanfare MUS_REGISTER_MATCH_CALL
	msgbox MatchCall_Text_RegisteredBirch, MSGBOX_DEFAULT
	waitfanfare
	closemessage
	delay 30
	@ TODO: Check vars below
	setflag FLAG_ENABLE_PROF_BIRCH_MATCH_CALL
	setvar VAR_REGISTER_BIRCH_STATE, 2
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Birch::
	lock
	faceplayer
	msgbox LittlerootTown_ProfessorBirchsLab_Text_GrandAdventure, MSGBOX_NPC
	@ goto_if_unset FLAG_HAS_MATCH_CALL, LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	@ goto_if_unset FLAG_ENABLE_PROF_BIRCH_MATCH_CALL, EventScript_RegisterProfBirch
	@ goto LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister
	end

@ LittlerootTown_ProfessorBirchsLab_EventScript_TryRatePokedexOrRegister::
@ 	@ TODO: Check var below
@ 	goto_if_unset FLAG_HIDE_LITTLEROOT_TOWN_BIRCHS_LAB_UNKNOWN_0x380, ProfBirch_EventScript_RatePokedexOrRegister
@ 	release
@ 	end

LittlerootTown_ProfessorBirchsLab_EventScript_ScottAboardSSTidalCall::
	lockall
	pokenavcall LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall
	waitmessage
	clearflag FLAG_SCOTT_CALL_BATTLE_FRONTIER
	releaseall
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Aide::
	lock
	faceplayer
	release
	end

LittlerootTown_ProfessorBirchsLab_EventScript_PC::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_PC, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf1::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Bookshelf1, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf2::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Bookshelf2, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf3::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Bookshelf3, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Bookshelf4::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Bookshelf4, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_Fridge::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_Fridge, MSGBOX_SIGN
	end

LittlerootTown_ProfessorBirchsLab_EventScript_DawnsFather::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_DawnsFather, MSGBOX_NPC
	end

LittlerootTown_ProfessorBirchsLab_EventScript_OtherAide::
	msgbox LittlerootTown_ProfessorBirchsLab_Text_OtherAide, MSGBOX_NPC
	end

LittlerootTown_ProfessorBirchsLab_Text_LetMeSee:
	.string "Professor: ...\p"
	.string "Finally, you've come.\n"
	.string "{PLAYER}, was it?\p"
	.string "Let me see your Pokémon again.$"

LittlerootTown_ProfessorBirchsLab_Text_SeemsHappy:
	.string "...\p"
	.string "Hmm...\n"
	.string "I see...\p"
	.string "This Pokémon seems to be rather\n"
	.string "happy.\p"
	.string "All righty then!\p"
	.string "I'll give that {STR_VAR_1} to you as\n"
	.string "a gift.$"

LittlerootTown_ProfessorBirchsLab_Text_GiveNickname:
	.string "Professor: Now that it's yours, would\n"
	.string "you like to give it a nickname?$"

LittlerootTown_ProfessorBirchsLab_Text_HappyNickname:
	.string "Professor: Hmm, OK, I see...\n"
	.string "And you're happy with that nickname?$"
	
LittlerootTown_ProfessorBirchsLab_Text_EntrustYou:
	.string "Professor: Your friend {RIVAL}\n"
	.string "told me what happened at the lake.\p"
	.string "I heard you battled very well,\n"
	.string "despite it being your first time.\p"
	.string "And, from what I can see, there is\n"
	.string "a growing bond between you and that\l"
	.string "Pokémon, though it is still young.\p"
	.string "That's why I would like to entrust\n"
	.string "you with {STR_VAR_1}.$"

LittlerootTown_ProfessorBirchsLab_Text_CollectData:
	.string "Professor: Er-hem!\n"
	.string "Let's move on to the main topic.\p"
	.string "There is something I want you\n"
	.string "to do for me.\p"
	.string "My name is Rowan.\n"
	.string "I study Pokémon.\p"
	.string "First of all, I want to know exactly\n"
	.string "what kinds of Pokémon live in the\l"
	.string "Sinnoh region.\p"
	.string "To do so, it is necessary to collect\n"
	.string "data using the Pokédex.\p"
	.string "This is what I wish to ask of you.$"

LittlerootTown_ProfessorBirchsLab_Text_RecordData:
	.string "I want to entrust you with this\n"
	.string "Pokédex.\p"
	.string "Will you use it to record data on all\n"
	.string "the Pokémon in Sinnoh for me?$"

LittlerootTown_ProfessorBirchsLab_Text_PatientMan:
	.string "Rowan: ...\p"
	.string "...\p"
	.string "...\p"
	.string "...\p"
	.string "I can stand here without speaking for\n"
	.string "hours. I'm a very patient man.\p"
	.string "Let me ask you again, {PLAYER}.$"

LittlerootTown_ProfessorBirchsLab_Text_GoodAnswer:
	.string "Rowan: Hm!\p"
	.string "Good answer!$"

LittlerootTown_ProfessorBirchsLab_Text_ReceivedPokedex:
	.string "{PLAYER} obtained\n"
	.string "the Pokédex!$"

LittlerootTown_ProfessorBirchsLab_Text_ExplainPokedex:
	.string "Rowan: That Pokédex is a very\n"
	.string "high-tech device\p"
	.string "It will automatically record data on\n"
	.string "every kind of Pokémon you encounter.\p"
	.string "{PLAYER}, I ask that you go\n"
	.string "everywhere and meet every kind of\l"
	.string "Pokémon in this region!$"

LittlerootTown_ProfessorBirchsLab_Text_SixtyYears:
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

LittlerootTown_ProfessorBirchsLab_Text_GrandAdventure:
	.string "Rowan: Go on!\p"
	.string "{PLAYER}, your grand adventure\n"
	.string "awaits you!$"

LittlerootTown_ProfessorBirchsLab_Text_KindDawn:
	.string "Dawn: I'm so glad that you're kind\n"
	.string "toward Pokémon!\p"
	.string "If you weren't, I'd have to...\n"
	.string "Oh, I just can't say it...$"

LittlerootTown_ProfessorBirchsLab_Text_GotOneDawn:
	.string "Dawn: I've got one, too!$"

LittlerootTown_ProfessorBirchsLab_Text_PiplupDawn:
	.string "Dawn: The Pokémon that I used for\n"
	.string "the first time was a PIPLUP!\p"
	.string "If you would have chosen\n"
	.string "a PIPLUP at the lake, we'd\l"
	.string "have the same Pokémon now!$"

LittlerootTown_ProfessorBirchsLab_Text_TurtwigDawn:
	.string "Dawn: The Pokémon that I used for\n"
	.string "the first time was a TURTWIG!\p"
	.string "If you would have chosen\n"
	.string "a TURTWIG at the lake, we'd\l"
	.string "have the same Pokémon now!$"

LittlerootTown_ProfessorBirchsLab_Text_ChimcharDawn:
	.string "Dawn: The Pokémon that I used for\n"
	.string "the first time was a CHIMCHAR!\p"
	.string "If you would have chosen\n"
	.string "a CHIMCHAR at the lake, we'd\l"
	.string "have the same Pokémon now!$"

LittlerootTown_ProfessorBirchsLab_Text_LikeYouDawn:
	.string "Not that it matters, but...\p"
	.string "Anyways, I'm Dawn.\p"
	.string "I also help the professor add pages\n"
	.string "to the Pokédex.\p"
	.string "So, in a sense, I'm just like you.\p"
	.string "I just got a little head start on\n"
	.string "you, that's all.\p"
	.string "I'll be happy to teach you things.\n"
	.string "Glad to meet you, {PLAYER}!$"

LittlerootTown_ProfessorBirchsLab_Text_KindLucas:
	.string "Lucas: Boy, am I glad you're kind\n"
	.string "toward Pokémon.\p"
	.string "If you weren't, well...\n"
	.string "I don't even want to think about it.$"

LittlerootTown_ProfessorBirchsLab_Text_GotOneLucas:
	.string "Lucas: I've got the same kind of\n"
	.string "Pokédex as you.$"

LittlerootTown_ProfessorBirchsLab_Text_ComradesLucas:
	.string "Lucas: The professor asked me to\n"
	.string "help, so I'm going to go out and fill\l"
	.string "the Pokédex pages, too.\p"
	.string "That makes us comrades working\n"
	.string "toward the same goal.\p"
	.string "I'll teach you stuff later, OK?$"

LittlerootTown_ProfessorBirchsLab_Text_PC:
	.string "{PLAYER} checked the PC.\p"
	.string "The screen is filled with special terms\n"
	.string "and academic writing that is impossible\l"
	.string "to figure out.$"

LittlerootTown_ProfessorBirchsLab_Text_Bookshelf1:
	.string "Adventure Rule No. 1\n"
	.string "The X Button opens the menu.$"

LittlerootTown_ProfessorBirchsLab_Text_Bookshelf2:
	.string "Adventure Rule No. 2\n"
	.string "Record your progress with SAVE.$"

LittlerootTown_ProfessorBirchsLab_Text_Bookshelf3:
	.string "It's crammed full of books with all\n"
	.string "sorts of Pokémon information.$"

LittlerootTown_ProfessorBirchsLab_Text_Bookshelf4:
	.string "There's a lot of reference material\n"
	.string "and research reports on Pokémon.$"

LittlerootTown_ProfessorBirchsLab_Text_Fridge:
	.string "The refrigerator is filled with\n"
	.string "tasty sweet! Hmm...$"

LittlerootTown_ProfessorBirchsLab_Text_DawnsFather:
	.string "I'm Dawn's father.\p"
	.string "I'll be happy to assist you on your\n"
	.string "quest for the professor.\p"
	.string "Hahaha. Eh...\n"
	.string "I'm sure we can count on you!$"

LittlerootTown_ProfessorBirchsLab_Text_OtherAide:
	.string "Professor Rowan invented a new\n"
	.string "Pokédex while working alongside a\l"
	.string "professor from the Kanto region!$"

@ LittlerootTown_ProfessorBirchsLab_EventScript_CheckReadyForJohtoStarter::
@ 	specialvar VAR_RESULT, HasAllHoennMons
@ 	goto_if_eq VAR_RESULT, TRUE, LittlerootTown_ProfessorBirchsLab_EventScript_SetReadyForJohtoStarter
@ 	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
@ 	setobjectxyperm LOCALID_RIVAL, 5, 10
@ 	end

@ LittlerootTown_ProfessorBirchsLab_EventScript_SetAfterJohtoStarterLayout::
@ 	setmaplayoutindex LAYOUT_LITTLEROOT_TOWN_PROFESSOR_BIRCHS_LAB_WITH_TABLE
@ 	setobjectmovementtype LOCALID_RIVAL, MOVEMENT_TYPE_WANDER_UP_AND_DOWN
@ 	setobjectxyperm LOCALID_RIVAL, 5, 10
@ 	end

LittlerootTown_ProfessorBirchsLab_Text_ScottAboardSSTidalCall:
	.string "… … … … … …\n"
	.string "… … … … … Beep!\p"
	.string "SCOTT: Hi, hi, {PLAYER}!\n"
	.string "It's me, SCOTT.\p"
	.string "I'm aboard the S.S. TIDAL now.\n"
	.string "It feels great to be on the sea!\p"
	.string "By the way…\p"
	.string "There's this place that I'd like to\n"
	.string "invite you to for a visit.\p"
	.string "If you're interested, board a ferry\n"
	.string "at either SLATEPORT or LILYCOVE.\p"
	.string "I'll fill you in on the details when\n"
	.string "we meet. I'll be waiting!\p"
	.string "… … … … … …\n"
	.string "… … … … … Click!$"
