EternaForest1_MapScripts::
	.byte 0

@ State descriptions For VAR_ETERNA_FOREST_STATE
@ 1: Cheryl teams up with player
@ 2: Cheryl leaves the player

EternaForest1_EventScript_CherylTeamUp1::
	lock
	applymovement LOCALID_ETERNA_FOREST_CHERYL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 10
	playse SE_PIN
	applymovement LOCALID_ETERNA_FOREST_CHERYL, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	applymovement LOCALID_ETERNA_FOREST_CHERYL, Common_Movement_WalkDown
	waitmovement 0
	goto EternaForest1_EventScript_CherylTeamUp

EternaForest1_EventScript_CherylTeamUp2::
	lock
	applymovement LOCALID_ETERNA_FOREST_CHERYL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	delay 10
	playse SE_PIN
	applymovement LOCALID_ETERNA_FOREST_CHERYL, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	applymovement LOCALID_ETERNA_FOREST_CHERYL, EternaForest1_Movement_CherylGreetAlternate
	waitmovement 0
	goto EternaForest1_EventScript_CherylTeamUp

EternaForest1_EventScript_CherylTeamUp::
	call EternaForest1_EventScript_CherylGreet
	playfanfare MUS_DP_LETS_GO_TOGETHER
	msgbox EternaForest1_Text_DecidedToGo, MSGBOX_DEFAULT
	waitfanfare
	msgbox EternaForest1_Text_PerfectHealth, MSGBOX_DEFAULT
	setfollowernpc LOCALID_ETERNA_FOREST_CHERYL, 0, EternaForest1_EventScript_Cheryl
	call_if_ge VAR_TEXT_FOLLOWER, 7, EternaForest1_EventScript_CherylResetTalk
	setvar VAR_ETERNA_FOREST_STATE, 1
	release
	end

EternaForest1_EventScript_CherylResetTalk::
	setvar VAR_TEXT_FOLLOWER, 7
	return

EternaForest1_EventScript_CherylGreet::
	goto_if_lt VAR_TEXT_ALTERNATE, 4, EternaForest1_EventScript_CherylGreetFirst
	msgbox EternaForest1_Text_BeenWaiting, MSGBOX_DEFAULT
	return

EternaForest1_EventScript_CherylGreetFirst::
	setvar VAR_TEXT_ALTERNATE, 4
	msgbox EternaForest1_Text_HelloMyName, MSGBOX_DEFAULT
	return

EternaForest1_EventScript_Cheryl::
	facefollowernpc
	goto_if_eq VAR_TEXT_FOLLOWER, 7, EternaForest1_EventScript_CherylTalk1
	goto_if_eq VAR_TEXT_FOLLOWER, 8, EternaForest1_EventScript_CherylTalk2
	goto EternaForest1_EventScript_CherylTalk3

EternaForest1_EventScript_CherylTalk1::
	setvar VAR_TEXT_FOLLOWER, 8
	msgbox EternaForest1_Text_CherylTalk1, MSGBOX_SIGN
	end

EternaForest1_EventScript_CherylTalk2::
	setvar VAR_TEXT_FOLLOWER, 9
	msgbox EternaForest1_Text_CherylTalk2, MSGBOX_SIGN
	end

EternaForest1_EventScript_CherylTalk3::
	msgbox EternaForest1_Text_CherylTalk3, MSGBOX_SIGN
	end

EternaForest1_EventScript_CherylLeave1::
	lock
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_WalkInPlaceDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox EternaForest1_Text_GoingBack, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_WalkUp2
	waitmovement 0
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	destroyfollowernpc
	clearflag FLAG_HIDE_ETERNA_FOREST_CHERYL
	addobject LOCALID_ETERNA_FOREST_CHERYL
	setvar VAR_ETERNA_FOREST_STATE, 0
	delay 48
	release
	end

EternaForest1_EventScript_CherylLeave2::
	lock
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_WalkInPlaceDown
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox EternaForest1_Text_GoingBack, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, EternaForest1_Movement_CherylLeaveAlternate
	waitmovement 0
	applymovement OBJ_EVENT_ID_NPC_FOLLOWER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	destroyfollowernpc
	clearflag FLAG_HIDE_ETERNA_FOREST_CHERYL
	addobject LOCALID_ETERNA_FOREST_CHERYL
	setvar VAR_ETERNA_FOREST_STATE, 0
	delay 48
	release
	end

EternaForest1_Movement_CherylGreetAlternate:
	walk_down
	walk_right
	walk_in_place_down
	step_end

EternaForest1_Movement_CherylLeaveAlternate:
	walk_up
	walk_up
	walk_left
	step_end

EternaForest1_EventScript_Jack::
	trainerbattle_single TRAINER_PT_JACK, EternaForest1_Text_JackIntro, EternaForest1_Text_JackDefeated
	msgbox EternaForest1_Text_JackPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest1_EventScript_Briana::
	trainerbattle_single TRAINER_PT_BRIANA, EternaForest1_Text_BrianaIntro, EternaForest1_Text_BrianaDefeated
	msgbox EternaForest1_Text_BrianaPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest1_EventScript_Lindsey::
	trainerbattle_single TRAINER_PT_LINDSEY, EternaForest1_Text_LindseyIntro, EternaForest1_Text_LindseyDefeated
	msgbox EternaForest1_Text_LindseyPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest1_EventScript_Elijah::
	trainerbattle_single TRAINER_PT_ELIJAH, EternaForest1_Text_ElijahIntro, EternaForest1_Text_ElijahDefeated
	msgbox EternaForest1_Text_ElijahPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest1_EventScript_Phillip::
	trainerbattle_single TRAINER_PT_PHILLIP, EternaForest1_Text_PhillipIntro, EternaForest1_Text_PhillipDefeated
	msgbox EternaForest1_Text_PhillipPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest1_EventScript_Donald::
	trainerbattle_single TRAINER_PT_DONALD, EternaForest1_Text_DonaldIntro, EternaForest1_Text_DonaldDefeated
	msgbox EternaForest1_Text_DonaldPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest1_EventScript_Kody::
	trainerbattle_single TRAINER_PT_KODY, EternaForest1_Text_KodyIntro, EternaForest1_Text_KodyDefeated
	msgbox EternaForest1_Text_KodyPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest1_EventScript_Rachael::
	trainerbattle_single TRAINER_PT_RACHAEL, EternaForest1_Text_RachaelIntro, EternaForest1_Text_RachaelDefeated
	msgbox EternaForest1_Text_RachaelPostBattle, MSGBOX_AUTOCLOSE
	end

EternaForest1_EventScript_BugCatcher::
	msgbox EternaForest1_Text_BugPokemon, MSGBOX_NPC
	end

EternaForest1_EventScript_MossyRock::
	msgbox EternaForest1_Text_MossyRock, MSGBOX_SIGN
	end

EternaForest1_EventScript_RouteSign::
	msgbox EternaForest1_Text_RouteSign, MSGBOX_SIGN
	end

EternaForest1_EventScript_TrainerTips::
	msgbox EternaForest1_Text_TrainerTips, MSGBOX_SIGN
	end

EternaForest1_Text_HelloMyName:
	.string "Hello, my name’s Cheryl.\n"
	.string "And you are...?\p"
	.string "OK, so your name is {PLAYER}.\n"
	.string "I’m sincerely glad to meet you.\p"
	.string "{PLAYER}, may I ask a big favor\n"
	.string "of you?\p"
	.string "I want to get through this forest,\n"
	.string "but I’m afraid of doing it alone.\p"
	.string "I’ve heard that there is a sinister\n"
	.string "group of people called Team Galactic\l"
	.string "about.\p"
	.string "I think there’d be safety in numbers.\n"
	.string "Please, may I go through with you?$"

EternaForest1_Text_BeenWaiting:
	.string "Cheryl: Oh, hi, {PLAYER}!\n"
	.string "I’ve been waiting like I said.\p"
	.string "Let’s get through this forest\n"
	.string "together.$"

EternaForest1_Text_DecidedToGo:
	.string "{PLAYER} decided to go with\n"
	.string "Cheryl!$"

EternaForest1_Text_PerfectHealth:
	.string "Cheryl: I’ll keep your Pokémon\n"
	.string "in perfect health.$"

EternaForest1_Text_GoingBack:
	.string "Cheryl: Oh? Are you going back?\n"
	.string "I’ll wait here for you, then.$"

EternaForest1_Text_CherylTalk1:
	.string "Cheryl: It’s startling to see two wild\n"
	.string "Pokémon appearing at the same time.$"

EternaForest1_Text_CherylTalk2:
	.string "Cheryl: My Pokémon is an excellent\n"
	.string "healer.\l"
	.string "But attacking isn’t its strong point.$"

EternaForest1_Text_CherylTalk3:
	.string "Cheryl: {PLAYER}, battling with\n"
	.string "you makes me feel elated.\p"
	.string "If I could predict what you’re about\n"
	.string "to do, we would make a fierce combo!$"

EternaForest1_Text_BugPokemon:
	.string "I’m searching for bug Pokémon so I can\n"
	.string "win at the Eterna Gym.\p"
	.string "Bug Pokémon are great, you know?\n"
	.string "They grow really fast!$"

EternaForest1_Text_MossyRock::
	.string "The rock is covered in moss.\n"
	.string "It feels pleasantly cool.$"

EternaForest1_Text_RouteSign:
	.string "The Eterna Forest\n"
	.string "Where Time Flows Eternally$"

EternaForest1_Text_TrainerTips:
	.string "Trainer Tips!\p"
	.string "In forests and caves, there are many\n"
	.string "items on the ground that cannot be\l"
	.string "seen in the murky darkness.\p"
	.string "Take the time to search carefully!$"
