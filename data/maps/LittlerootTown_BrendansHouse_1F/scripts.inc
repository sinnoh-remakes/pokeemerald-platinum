.set LOCALID_MOM, 1
.set LOCALID_RIVALMOM, 2

LittlerootTown_BrendansHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_BrendansHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, LittlerootTown_BrendansHouse_1F_OnWarp
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_BrendansHouse_1F_OnFrame
	.byte 0

LittlerootTown_BrendansHouse_1F_OnTransition:
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MoveMom
	end

LittlerootTown_BrendansHouse_1F_OnFrame:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 0, LittlerootTown_BrendansHouse_1F_EventScript_MomMessage
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_LakeReturn
	.2byte 0

LittlerootTown_BrendansHouse_1F_OnWarp:
	map_script_2 VAR_LITTLEROOT_INTRO_STATE, 5, LittlerootTown_BrendansHouse_1F_TurnPlayerNorth
	.2byte 0

LittlerootTown_BrendansHouse_1F_EventScript_MomMessage::
	lock
	setvar VAR_LITTLEROOT_INTRO_STATE, 1
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 10
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_MomTalk_1
	waitmovement 0
	delay 10
	msgbox LittlerootTown_BrendansHouse_1F_Text_Emergency, MSGBOX_DEFAULT
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
	msgbox LittlerootTown_BrendansHouse_1F_Text_TallGrass, MSGBOX_DEFAULT
	release
	return

LittlerootTown_BrendansHouse_1F_EventScript_MoveMom::
	setobjectxyperm LOCALID_MOM, 1, 3
	setobjectmovementtype LOCALID_MOM, MOVEMENT_TYPE_FACE_UP
	return

LittlerootTown_BrendansHouse_1F_TurnPlayerNorth::
	turnobject OBJ_EVENT_ID_PLAYER, DIR_NORTH
	end

LittlerootTown_BrendansHouse_1F_EventScript_LakeReturn::
	lock
	setvar VAR_LITTLEROOT_INTRO_STATE, 6
	delay 48
	delay 48
	applymovement LOCALID_MOM, LittlerootTown_BrendansHouse_1F_Movement_MomKitchen
	applymovement OBJ_EVENT_ID_PLAYER, LittlerootTown_BrendansHouse_1F_Movement_PlayerKitchen
	waitmovement 0
	delay 48
	delay 48
	msgbox LittlerootTown_BrendansHouse_1F_Text_Unharmed, MSGBOX_SIGN
	delay 48
	msgbox LittlerootTown_BrendansHouse_1F_Text_PutOn, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_BrendansHouse_1F_Text_ReceivedShoes
	waitfanfare
	setflag FLAG_RECEIVED_RUNNING_SHOES
	setflag FLAG_SYS_B_DASH
	delay 48
	msgbox LittlerootTown_BrendansHouse_1F_Text_GoingSandGem, MSGBOX_DEFAULT
	msgbox LittlerootTown_BrendansHouse_1F_Text_ShoesManual, MSGBOX_SIGN
	release
	end

LittlerootTown_BrendansHouse_1F_Movement_MomKitchen:
	walk_left
	face_up
	delay_16
	walk_right
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	walk_right
	walk_down
	walk_down
	walk_in_place_left
	step_end

LittlerootTown_BrendansHouse_1F_Movement_PlayerKitchen:
	delay_16
	delay_16
	delay_16
	delay_16
	walk_in_place_right
	delay_16
	delay_16
	walk_right
	walk_right
	walk_right
	walk_down
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_Mom::
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 1, LittlerootTown_BrendansHouse_1F_EventScript_Impatient
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 0, LittlerootTown_BrendansHouse_1F_EventScript_MomAlternate
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 2, LittlerootTown_BrendansHouse_1F_EventScript_RunningShoesManual
	goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 4, LittlerootTown_BrendansHouse_1F_EventScript_MomByeCheck
	@ goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 5, LittlerootTown_BrendansHouse_1F_EventScript_MomHealsParty
	goto LittlerootTown_BrendansHouse_1F_EventScript_MomHealsParty
	end

LittlerootTown_BrendansHouse_1F_EventScript_Impatient::
	msgbox LittlerootTown_BrendansHouse_1F_Text_Impatient, MSGBOX_NPC
	end

LittlerootTown_BrendansHouse_1F_EventScript_MomAlternate::
	goto_if_lt VAR_ALTERNATE_TEXT, 1, LittlerootTown_BrendansHouse_1F_EventScript_TakeCare
	msgbox LittlerootTown_BrendansHouse_1F_Text_RivalWaiting, MSGBOX_NPC
	end

LittlerootTown_BrendansHouse_1F_EventScript_TakeCare::
	setvar VAR_ALTERNATE_TEXT, 1
	msgbox LittlerootTown_BrendansHouse_1F_Text_TakeCare, MSGBOX_NPC
	end

LittlerootTown_BrendansHouse_1F_EventScript_RunningShoesManual::
	faceplayer
	msgbox LittlerootTown_BrendansHouse_1F_Text_ReadInfo, MSGBOX_DEFAULT
	msgbox LittlerootTown_BrendansHouse_1F_Text_ShoesManual, MSGBOX_SIGN
	end

LittlerootTown_BrendansHouse_1F_EventScript_MomByeCheck::
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 8, LittlerootTown_BrendansHouse_1F_EventScript_MomBye
	goto LittlerootTown_BrendansHouse_1F_EventScript_MomHealsParty
	return

LittlerootTown_BrendansHouse_1F_EventScript_MomHealsParty::
	lock
	faceplayer
	msgbox LittlerootTown_BrendansHouse_1F_WelcomeHome, MSGBOX_DEFAULT
	closemessage
	call Common_EventScript_OutOfCenterPartyHeal
	incrementgamestat GAME_STAT_RESTED_AT_HOME
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 7, LittlerootTown_BrendansHouse_1F_EventScript_MomAdventure
	release
	end

LittlerootTown_BrendansHouse_1F_EventScript_MomAdventure::
	msgbox LittlerootTown_BrendansHouse_1F_Text_MomGotBack
	call_if_eq VAR_FACING, DIR_NORTH, LittlerootTown_BrendansHouse_1F_EventScript_MomTurnNorth
	call_if_eq VAR_FACING, DIR_WEST, LittlerootTown_BrendansHouse_1F_EventScript_MomTurnNorth
	call_if_eq VAR_FACING, DIR_SOUTH, LittlerootTown_BrendansHouse_1F_EventScript_MomTurnSouth
	call_if_eq VAR_FACING, DIR_EAST, LittlerootTown_BrendansHouse_1F_EventScript_MomTurnNorth
	msgbox LittlerootTown_BrendansHouse_1F_Text_EnvyKiddo, MSGBOX_DEFAULT
	faceplayer
	msgbox LittlerootTown_BrendansHouse_1F_Text_JustJoking, MSGBOX_SIGN
	@ TODO: Play door open sound
	addobject LOCALID_RIVALMOM
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_MOM, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_MOM, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_RIVALMOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomEnter
	waitmovement 0
	call_if_eq VAR_FACING, DIR_NORTH, LittlerootTown_BrendansHouse_1F_EventScript_PlayerTurnWest
	msgbox LittlerootTown_BrendansHouse_1F_Text_MyLittle, MSGBOX_DEFAULT
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceDown
	msgbox LittlerootTown_BrendansHouse_1F_Text_Headstrong, MSGBOX_DEFAULT
	call_if_eq VAR_FACING, DIR_NORTH, LittlerootTown_BrendansHouse_1F_EventScript_FaceMomSouth
	call_if_eq VAR_FACING, DIR_WEST, LittlerootTown_BrendansHouse_1F_EventScript_FaceMomEast
	call_if_eq VAR_FACING, DIR_SOUTH, LittlerootTown_BrendansHouse_1F_EventScript_FaceMomNorth
	call_if_eq VAR_FACING, DIR_EAST, LittlerootTown_BrendansHouse_1F_EventScript_FaceMomWest
	msgbox LittlerootTown_BrendansHouse_1F_Text_WontYou, MSGBOX_SIGN
	call_if_eq VAR_FACING, DIR_NORTH, LittlerootTown_BrendansHouse_1F_EventScript_FaceRivalMomEast
	call_if_eq VAR_FACING, DIR_WEST, LittlerootTown_BrendansHouse_1F_EventScript_RivalMomRight2
	call_if_eq VAR_FACING, DIR_SOUTH, LittlerootTown_BrendansHouse_1F_EventScript_RivalMomUp2
	call_if_eq VAR_FACING, DIR_EAST, LittlerootTown_BrendansHouse_1F_EventScript_FaceRivalMomNorth
	msgbox LittlerootTown_BrendansHouse_1F_Text_TakeThis, MSGBOX_DEFAULT
	playfanfare MUS_OBTAIN_ITEM
	message LittlerootTown_BrendansHouse_1F_Text_ReceivedParcel
	waitfanfare
	msgbox LittlerootTown_BrendansHouse_1F_Text_KnowingMyBoy, MSGBOX_SIGN
	call_if_eq VAR_FACING, DIR_NORTH, LittlerootTown_BrendansHouse_1F_EventScript_RivalMomWestSouthLeave
	call_if_eq VAR_FACING, DIR_WEST, LittlerootTown_BrendansHouse_1F_EventScript_RivalMomEastLeave
	call_if_eq VAR_FACING, DIR_SOUTH, LittlerootTown_BrendansHouse_1F_EventScript_RivalMomNorthLeave
	call_if_eq VAR_FACING, DIR_EAST, LittlerootTown_BrendansHouse_1F_EventScript_RivalMomWestSouthLeave
	removeobject LOCALID_RIVALMOM
	setvar VAR_LITTLEROOT_INTRO_STATE, 8
	return

LittlerootTown_BrendansHouse_1F_Movement_RivalMomEnter:
	walk_up
	walk_in_place_right
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_PlayerTurnWest::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_MomTurnSouth::
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_MomTurnNorth::
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceUp
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_FaceMomNorth::
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_FaceMomWest::
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceLeft
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_FaceMomSouth::
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceDown
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_FaceMomEast::
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_FaceRivalMomNorth::
	applymovement LOCALID_RIVALMOM, Common_Movement_WalkInPlaceUp
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_FaceRivalMomEast::
	applymovement LOCALID_RIVALMOM, Common_Movement_WalkInPlaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_RivalMomUp2::
	applymovement LOCALID_RIVALMOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomUp2
	waitmovement 0
	call LittlerootTown_BrendansHouse_1F_EventScript_FaceRivalMomEast
	return

LittlerootTown_BrendansHouse_1F_EventScript_RivalMomRight2::
	applymovement LOCALID_RIVALMOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomLeft2
	waitmovement 0
	call LittlerootTown_BrendansHouse_1F_EventScript_FaceRivalMomNorth
	return

LittlerootTown_BrendansHouse_1F_EventScript_RivalMomNorthLeave::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceDown
	applymovement LOCALID_RIVALMOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomNorthLeave
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_RivalMomWestSouthLeave::
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	applymovement LOCALID_RIVALMOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomWestSouthLeave
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_EventScript_RivalMomEastLeave::
	applymovement LOCALID_MOM, Common_Movement_WalkInPlaceDown
	applymovement LOCALID_RIVALMOM, LittlerootTown_BrendansHouse_1F_Movement_RivalMomEastLeave
	waitmovement 0
	return

LittlerootTown_BrendansHouse_1F_Movement_RivalMomLeft2:
	walk_right
	walk_right
	step_end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomUp2:
	walk_up
	walk_up
	step_end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomNorthLeave:
	walk_down
	walk_down
	walk_down
	walk_in_place_down
	step_end

LittlerootTown_BrendansHouse_1F_Movement_RivalMomWestSouthLeave:
	walk_down
	walk_in_place_down
	step_end
	
LittlerootTown_BrendansHouse_1F_Movement_RivalMomEastLeave:
	walk_left
	walk_left
	walk_down
	walk_in_place_down
	step_end

LittlerootTown_BrendansHouse_1F_EventScript_MomBye::
	msgbox LittlerootTown_BrendansHouse_1F_Text_MomBye, MSGBOX_NPC
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

LittlerootTown_BrendansHouse_1F_Text_Emergency:
	.string "Mom: {PLAYER}!\p"
	.string "{RIVAL} came calling for you a little\n"
	.string "while ago.\p"
	.string "I don't know what it was about, but he\n"
	.string "said it was an emergency.$"

LittlerootTown_BrendansHouse_1F_Text_TallGrass:
	.string "Mom: Oh yes! {PLAYER}!\p"
	.string "Don't go into the tall grass. Wild\n"
	.string "Pokémon might attack you.\p"
	.string "It would be OK if you had your own\n"
	.string "Pokémon, but you don't so...$"

LittlerootTown_BrendansHouse_1F_Text_Impatient:
	.string "Mom: You know how impatient\n"
	.string "{RIVAL} is.\p"
	.string "He took off before I could even\n"
	.string "ask what it was about.$"

LittlerootTown_BrendansHouse_1F_Text_TakeCare:
	.string "Mom: Bye-bye, {PLAYER}!\n"
	.string "You take care now!$"

LittlerootTown_BrendansHouse_1F_Text_RivalWaiting:
	.string "Mom: What is it, dear?\n"
	.string "Isn't {RIVAL} waiting for you?$"

LittlerootTown_BrendansHouse_1F_Text_Unharmed:
	.string "Mom: What's up, dear?\p"
	.string "...\p"
	.string "Wow.\n"
	.string "I can't believe that happened to you.\p"
	.string "Am I ever glad that both you and\n"
	.string "{RIVAL} are unharmed.\p"
	.string "The professor you mentioned is\n"
	.string "most likely Professor Rowan of\l"
	.string "Sandgem Town.\p"
	.string "I've heard that he is well known for\n"
	.string "his studies on Pokémon.\p"
	.string "I hear he's also quite intimidating...\p"
	.string "{PLAYER}, I think you need to\n"
	.string "visit him in Sandgem Town.\p"
	.string "You need to properly explain why you\n"
	.string "had no choice but to use his Pokémon.\p"
	.string "Don't worry!\n"
	.string "I'm sure he will understand.$"

LittlerootTown_BrendansHouse_1F_Text_PutOn:
	.string "Oh, I know!\n"
	.string "{PLAYER}, put these on.$"

LittlerootTown_BrendansHouse_1F_Text_GoingSandGem:
	.string "Going to Sandgem Town is like an\n"
	.string "adventure in itself, right?\p"
	.string "With those Running Shoes, you can\n"
	.string "get to faraway places much faster.\p"
	.string "OK...\n"
	.string "Let me read the instructions...$"

LittlerootTown_BrendansHouse_1F_Text_ReadInfo:
	.string "Mom: I'll read you the instructions\n"
	.string "for the Running Shoes...$"

LittlerootTown_BrendansHouse_1F_Text_ReceivedShoes:
	.string "{PLAYER} received a pair of\n"
	.string "Running Shoes!$"

LittlerootTown_BrendansHouse_1F_Text_ShoesManual:
	.string "“Press the B Button and dash\n"
	.string "about faster than ever before!\p"
	.string "“Put on the Running Shoes and\n"
	.string "blaze new trails of adventure!“\p"
	.string "Well, isn't that just nifty!$"

LittlerootTown_BrendansHouse_1F_WelcomeHome:
	.string "Mom: Welcome home, {PLAYER}.\n"
	.string "Are you and your Pokémon healthy?\p"
	@ TODO: Does this change from time of day?
	.string "I just made dinner.\n"
	.string "Take a quick rest, dear.$"

LittlerootTown_BrendansHouse_1F_Text_MomGotBack:
	.string "Mom: What's up, {PLAYER}?\p"
	.string "...\p"
	.string "Wow. Professor Rowan asked you\n"
	.string "to do something that big.\p"
	.string "OK, dear, go for it!\n"
	.string "Your mom's got your back!$"

@ LittlerootTown_BrendansHouse_1F_Text_MomGiveJournal:
@ 	.string "Oh, I know! {PLAYER}, I've got\n"
@ 	.string "something that you'll find useful.\p"
@ 	.string "{PLAYER} obtained\n"
@ 	.string "the Journal!\p"
@ 	.string "{PLAYER} put the Journal\n"
@ 	.string "in the KEY ITEMS Pocket.\p"
@ 	.string "That's a Journal. It keeps a record\n"
@ 	.string "of your daily events.\p"
@ 	.string "Check it, and you'll be able to\n"
@ 	.string "remember what you did last.\p"

LittlerootTown_BrendansHouse_1F_Text_EnvyKiddo:
	.string "Gee, a journey full of adventure...\n"
	.string "I envy you, kiddo.\p"
	.string "Plus, you're not alone.\n"
	.string "You have your Pokémon with you.\l"
	.string "I wish I could go instead!$"

LittlerootTown_BrendansHouse_1F_Text_JustJoking:
	.string "I'm just joking, dear!\n"
	.string "Yup, {PLAYER}!\p"
	.string "I'll be all right by myself, so you\n"
	.string "go and enjoy your adventure!\p"
	.string "When you're exposed to new things,\n"
	.string "and experience new sensations...\l"
	.string "It makes your mother happy too.\p"
	.string "...But come back sometimes.\p"
	.string "I would like to see the kinds of\n"
	.string "Pokémon you've caught, dear.$"

LittlerootTown_BrendansHouse_1F_Text_MomBye:
	.string "Mom: Bye-bye, {PLAYER}!\n"
	.string "Enjoy your adventure!$"
	
LittlerootTown_BrendansHouse_1F_Text_MyLittle:
	.string "{RIVAL}'s mom: Excuse me.\n"
	.string "Is my little {RIVAL} here?$"

LittlerootTown_BrendansHouse_1F_Text_Headstrong:
	.string "Mom: Oh?\n"
	.string "No, he's not...\p"
	.string "{RIVAL}'s mom: Oh...\n"
	.string "Then, he must have left already...\l"
	.string "What to do...\p"
	.string "That boy shouted about going on an\n"
	.string "adventure, then he bolted.\p"
	.string "He's so headstrong and reckless...\n"
	.string "I at least wanted him to take this...\p"
	.string "Mom: Not to worry, {PLAYER} will\n"
	.string "deliver that to him.$"

LittlerootTown_BrendansHouse_1F_Text_WontYou:
	.string "Won't you, {PLAYER}?$"

LittlerootTown_BrendansHouse_1F_Text_TakeThis:
	.string "{RIVAL}'s mom: Oh, really?\n"
	.string "You'd do that for me?\p"
	.string "{PLAYER}, please take this to\n"
	.string "{RIVAL} for me.$"

LittlerootTown_BrendansHouse_1F_Text_ReceivedParcel:
	.string "{PLAYER} obtained\n"
	.string "the Parcel!$"
	.string ""

LittlerootTown_BrendansHouse_1F_Text_KnowingMyBoy:
	.string "{PLAYER} put the Parcel\n"
	.string "in the KEY ITEMS Pocket.\p"
	.string "Mom: Bye-bye, {PLAYER}!\n"
	.string "Enjoy your adventure!\p"
	.string "{RIVAL}'s mom: Let me think...\p"
	.string "Knowing my boy, he would probably\n"
	.string "head straight to Jubilife City...\p"
	.string "OK, please take that to my\n"
	.string "{RIVAL}.$"

LittlerootTown_BrendansHouse_1F_Text_Kitchen:
	.string "Mom's kitchen is spotless!\n"
	.string "You can see your face on the floor!$"

LittlerootTown_BrendansHouse_1F_Text_Counter:
	.string "This is where Mom does all her\n"
	.string "delicious cooking.$"

LittlerootTown_BrendansHouse_1F_Text_Fridge:
	.string "Mom's favorite dessert is in\n"
	.string "the refrigerator.$"

LittlerootTown_BrendansHouse_1F_Text_MovieOnTV:
	.string "There is a movie on TV.\p"
	.string "Two men are dancing on a big piano\n"
	.string "keyboard.\p"
	.string "Better get going!$"
