OreburghCityNorth_MapScripts::
	.byte 0

@ State descriptions For VAR_OREBURGH_CITY_STATE
@ 1: Received HM Rock Smash
@ 2: Talked to Youngster
@ 3: Talked to Barry
@ 4: Talked to Roark
@ 5: Obtained Coal Badge
@ 6: Rival left Oreburgh

OreburghCityNorth_EventScript_RivalLeaving::
	setvar VAR_OREBURGH_CITY_STATE, 6

	lock

	clearflag FLAG_HIDE_OREBURGH_CITY_RIVAL
	getplayerxy VAR_0x8000, VAR_0x8001
	addvar VAR_0x8000, 8
	addvar VAR_0x8001, 2
	addobject LOCALID_RIVAL_EVENT
	setobjectxy LOCALID_RIVAL_EVENT, VAR_0x8000, VAR_0x8001

	applymovement LOCALID_RIVAL_EVENT, OreburghCityNorth_Movement_RivalLeaving
	waitmovement LOCALID_RIVAL_EVENT
	playse SE_WALL_HIT
	applymovement OBJ_EVENT_ID_PLAYER, OreburghCityNorth_Movement_PlayerLeft
	waitmovement 0
	playbgm MUS_DP_RIVAL, FALSE
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox OreburghCityNorth_Text_RivalLeaving, MSGBOX_DEFAULT
	applymovement LOCALID_RIVAL_EVENT, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox OreburghCityNorth_Text_RivalLeavingSection2, MSGBOX_DEFAULT
	applymovement LOCALID_RIVAL_EVENT, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox OreburghCityNorth_Text_RivalLeavingSection3, MSGBOX_DEFAULT

	compare VAR_0x8001, 15
	call_if_eq OreburghCityNorth_EventScript_RivalLeaving_Section1

	compare VAR_0x8001, 16
	call_if_eq OreburghCityNorth_EventScript_RivalLeaving_Section2

	compare VAR_0x8001, 17
	call_if_eq OreburghCityNorth_EventScript_RivalLeaving_Section3

	compare VAR_0x8001, 18
	call_if_eq OreburghCityNorth_EventScript_RivalLeaving_Section4

	removeobject LOCALID_RIVAL_EVENT
	playse SE_EXIT
	setflag FLAG_HIDE_OREBURGH_CITY_RIVAL
	fadedefaultbgm
	release
	end

OreburghCityNorth_EventScript_RivalLeaving_Section1:
	closemessage
	applymovement LOCALID_RIVAL_EVENT, OreburghCityNorth_Movement_RivalLeavingY13
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	delay 32
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement LOCALID_RIVAL_EVENT
	return

OreburghCityNorth_EventScript_RivalLeaving_Section2:
	closemessage
	applymovement LOCALID_RIVAL_EVENT, OreburghCityNorth_Movement_RivalLeavingY14
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceDown
	delay 32
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement LOCALID_RIVAL_EVENT
	return

OreburghCityNorth_EventScript_RivalLeaving_Section3:
	closemessage
	applymovement LOCALID_RIVAL_EVENT, OreburghCityNorth_Movement_RivalLeavingY15
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	delay 32
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement LOCALID_RIVAL_EVENT
	return

OreburghCityNorth_EventScript_RivalLeaving_Section4:
	closemessage
	applymovement LOCALID_RIVAL_EVENT, OreburghCityNorth_Movement_RivalLeavingY16
	delay 16
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	delay 64
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceLeft
	waitmovement LOCALID_RIVAL_EVENT
	return

OreburghCityNorth_EventScript_Youngster::
	lock
	special SpawnCameraObject
	playse SE_PIN
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceDown
	applymovement LOCALID_OREBURGH_CITY_YOUNGSTER, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_OREBURGH_CITY_YOUNGSTER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 48
	return
	
OreburghCityNorth_EventScript_YoungsterConfused::
	applymovement LOCALID_CAMERA, OreburghCityNorth_Movement_IntroPlayerLong
	applymovement LOCALID_PLAYER, OreburghCityNorth_Movement_IntroPlayerLong
	applymovement LOCALID_OREBURGH_CITY_YOUNGSTER, OreburghCityNorth_Movement_IntroYoungsterLong
	waitmovement 0
	@ Someone there
	msgbox OreburghCityNorth_Text_SomeoneThere, MSGBOX_DEFAULT
	setvar VAR_OREBURGH_CITY_STATE, 2
	fadedefaultbgm
	special RemoveCameraObject
	release
	end

OreburghCityNorth_EventScript_Youngster1::
	call OreburghCityNorth_EventScript_Youngster
	applymovement LOCALID_OREBURGH_CITY_YOUNGSTER, Common_Movement_WalkUp3
	waitmovement 0
	msgbox OreburghCityNorth_Text_HowdyTrainer, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_DP_FOLLOW_ME, FALSE
	applymovement LOCALID_CAMERA, OreburghCityNorth_Movement_IntroPlayer1
	applymovement LOCALID_PLAYER, OreburghCityNorth_Movement_IntroPlayer1
	applymovement LOCALID_OREBURGH_CITY_YOUNGSTER, OreburghCityNorth_Movement_IntroYoungster1
	waitmovement 0
	goto OreburghCityNorth_EventScript_YoungsterConfused
	end

OreburghCityNorth_EventScript_Youngster2::
	call OreburghCityNorth_EventScript_Youngster
	applymovement LOCALID_OREBURGH_CITY_YOUNGSTER, Common_Movement_WalkUp2
	waitmovement 0
	msgbox OreburghCityNorth_Text_HowdyTrainer, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_DP_FOLLOW_ME, FALSE
	applymovement LOCALID_CAMERA, OreburghCityNorth_Movement_IntroPlayer2
	applymovement LOCALID_PLAYER, OreburghCityNorth_Movement_IntroPlayer2
	applymovement LOCALID_OREBURGH_CITY_YOUNGSTER, OreburghCityNorth_Movement_IntroYoungster2
	waitmovement 0
	goto OreburghCityNorth_EventScript_YoungsterConfused
	end

OreburghCityNorth_EventScript_Youngster3::
	call OreburghCityNorth_EventScript_Youngster
	applymovement LOCALID_OREBURGH_CITY_YOUNGSTER, Common_Movement_WalkUp
	waitmovement 0
	msgbox OreburghCityNorth_Text_HowdyTrainer, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_DP_FOLLOW_ME, FALSE
	applymovement LOCALID_CAMERA, OreburghCityNorth_Movement_IntroPlayer3
	applymovement LOCALID_PLAYER, OreburghCityNorth_Movement_IntroPlayer3
	applymovement LOCALID_OREBURGH_CITY_YOUNGSTER, OreburghCityNorth_Movement_IntroYoungster3
	waitmovement 0
	goto OreburghCityNorth_EventScript_YoungsterConfused
	end

OreburghCityNorth_EventScript_Youngster4::
	call OreburghCityNorth_EventScript_Youngster
	msgbox OreburghCityNorth_Text_HowdyTrainer, MSGBOX_DEFAULT
	closemessage
	playbgm MUS_DP_FOLLOW_ME, FALSE
	applymovement LOCALID_CAMERA, OreburghCityNorth_Movement_IntroPlayer4
	applymovement LOCALID_PLAYER, OreburghCityNorth_Movement_IntroPlayer4
	applymovement LOCALID_OREBURGH_CITY_YOUNGSTER, OreburghCityNorth_Movement_IntroYoungster4
	waitmovement 0
	goto OreburghCityNorth_EventScript_YoungsterConfused
	end

OreburghCityNorth_EventScript_YoungsterTalk::
	msgbox OreburghCityNorth_Text_ThatGuy, MSGBOX_NPC
	end

OreburghCityNorth_Movement_IntroPlayer1:
	walk_down
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

OreburghCityNorth_Movement_IntroYoungster1:
	walk_right
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

OreburghCityNorth_Movement_IntroPlayer2:
	walk_down
	walk_right
	walk_down
	walk_down
	step_end

OreburghCityNorth_Movement_IntroYoungster2:
	walk_right
	walk_down
	walk_down
	walk_down
	step_end

OreburghCityNorth_Movement_IntroPlayer3:
	walk_down
	walk_right
	walk_down
	step_end

OreburghCityNorth_Movement_IntroYoungster3:
	walk_right
	walk_down
	walk_down
	step_end

OreburghCityNorth_Movement_IntroPlayer4:
	walk_down
	walk_right
	step_end

OreburghCityNorth_Movement_IntroYoungster4:
	walk_right
	walk_down
	step_end

OreburghCityNorth_Movement_IntroPlayerLong:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

OreburghCityNorth_Movement_RivalLeaving:
    walk_left
    walk_left
    walk_left
    walk_left
	walk_left
    walk_left
	walk_left
    walk_left
    step_end

OreburghCityNorth_Movement_RivalLeavingY13:
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

OreburghCityNorth_Movement_RivalLeavingY14:
	walk_down
	walk_left
	walk_left
	walk_up
	walk_left
	walk_left
	step_end

OreburghCityNorth_Movement_RivalLeavingY15:
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

OreburghCityNorth_Movement_RivalLeavingY16:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	step_end

OreburghCityNorth_Movement_PlayerLeft:
	walk_left
	step_end

OreburghCityNorth_Movement_IntroYoungsterLong:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_in_place_left
	step_end

OreburghCityNorth_EventScript_Barry::
	goto_if_eq VAR_OREBURGH_CITY_STATE, 3, OreburghCityNorth_EventScript_BarryAlternate
	msgbox OreburghCityNorth_Text_FinallyGotHere, MSGBOX_NPC
	setvar VAR_OREBURGH_CITY_STATE, 3
	end

OreburghCityNorth_EventScript_BarryAlternate::
	msgbox OreburghCityNorth_Text_ToldYou, MSGBOX_NPC
	end

OreburghCityNorth_EventScript_Guitarist::
	msgbox OreburghCityNorth_Text_SeenTheVents, MSGBOX_NPC
	end

OreburghCityNorth_EventScript_Worker::
	msgbox OreburghCityNorth_Text_ExchangeHotAir, MSGBOX_NPC
	end

OreburghCityNorth_EventScript_SchoolKidF::
	msgbox OreburghCityNorth_Text_WentOff, MSGBOX_NPC
	end

OreburghCityNorth_EventScript_Camper::
	msgbox OreburghCityNorth_Text_RunAround, MSGBOX_NPC
	end

OreburghCityNorth_EventScript_BattleGirl1::
	msgbox OreburghCityNorth_Text_SingleUse, MSGBOX_NPC
	end

OreburghCityNorth_EventScript_BattleGirl2::
	msgbox OreburghCityNorth_Text_TimeCapsules, MSGBOX_NPC
	end

OreburghCityNorth_EventScript_Hiker::
	msgbox OreburghCityNorth_Text_HugeMountain, MSGBOX_NPC
	end

OreburghCityNorth_EventScript_TownSign::
	msgbox OreburghCityNorth_Text_TownSign, MSGBOX_SIGN
	end

OreburghCityNorth_EventScript_GymSign::
	msgbox OreburghCityNorth_Text_GymSign, MSGBOX_SIGN
	end

OreburghCityNorth_EventScript_MuseumSign::
	msgbox OreburghCityNorth_Text_MuseumSign, MSGBOX_SIGN
	end

OreburghCityNorth_EventScript_MuseumBlock::
	msgbox OreburghCityNorth_Text_MuseumBlock, MSGBOX_NPC
	end

OreburghCityNorth_Text_HowdyTrainer:
	.string "Howdy, Trainer!\p"
	.string "Huh? Uh-oh!\n"
	.string "You don’t have a single Gym Badge?\p"
	.string "You’d better do something about that!\n"
	.string "I’ll take you to the Pokémon Gym.$"

OreburghCityNorth_Text_SomeoneThere:
	.string "Huh?\n"
	.string "There’s someone there.$"

OreburghCityNorth_Text_RivalLeaving:
    .string "Thud!\p"
	.string "{RIVAL}: Whoops! {PLAYER}!\n"
	.string "You got the Gym Badge, huh?\p"
	.string "Eterna City is the next place with\n"
	.string "a Gym that gives away Badges, right?$"

OreburghCityNorth_Text_RivalLeavingSection2:
	.string "So, yeah, I went to Route 207, but\n"
	.string "you can't go there without a Bicycle.$"

OreburghCityNorth_Text_RivalLeavingSection3:
	.string "I made my team battle and toughened\n"
	.string "them up, so it wasn't a waste.\p"
	.string "So, I'm going back to Jubilife City.\n"
	.string "Next stop, the Eterna Gym Badge!\p"
	.string "Ten seconds before I dash!\p"
	.string "Nine...\p"
	.string "Bah! Who's got time to count?!$"

OreburghCityNorth_Text_FinallyGotHere:
	.string "{RIVAL}: Hunh?\p"
	.string "Oh, it’s you, {PLAYER}!\n"
	.string "You finally got here?\l"
	.string "You’re slow like always.\p"
	.string "But anyway, the Gym Leader’s tough!\n"
	.string "Like, seriously serious!\p"
	.string "If the Gym Leader’s this tough,\n"
	.string "I wonder how he compares to my dad...\p"
	.string "Huh?\n"
	.string "I just drifted there.\p"
	.string "Anyway, the Gym Leader’s gone off\n"
	.string "to the coal mine.\p"
	.string "If you want to take on the Gym Leader,\n"
	.string "you’d better go off to the mine!$"

OreburghCityNorth_Text_ToldYou:
	.string "{RIVAL}: I told you, the Gym\n"
	.string "Leader went down to the Oreburgh Mine.\p"
	.string "If you want to take the Gym challenge,\n"
	.string "you have to go down to the mine.$"

OreburghCityNorth_Text_ThatGuy:
	.string "Is that guy in front of the Gym\n"
	.string "your friend?\p"
	.string "He’s sort of twitchy and impatient.$"

OreburghCityNorth_Text_SeenTheVents:
	.string "Have you seen the vents?\n"
	.string "They release steam from down below.$"

OreburghCityNorth_Text_ExchangeHotAir:
	.string "These vents exchange the hot air\n"
	.string "down below with the fresh air outside.\p"
	.string "Looking down them gives me the urge\n"
	.string "to start yelling into ’em! Hello!$"

OreburghCityNorth_Text_WentOff:
	.string "The Gym Leader went off to work in\n"
	.string "the mine.$"

OreburghCityNorth_Text_RunAround:
	.string "When I run around with my Running\n"
	.string "Shoes on, I’m the center of attention!\p"
	.string "...At least that’s what it feels like.\n"
	.string "There’s always someone looking at me.$"

OreburghCityNorth_Text_SingleUse:
	.string "TMs are single use only, but HMs\n"
	.string "can be used over and over.\p"
	.string "It’s tricky trying to decide which\n"
	.string "Pokémon should learn what moves.$"

OreburghCityNorth_Text_TimeCapsules:
	.string "Natural time capsules buried many,\n"
	.string "many years ago...\p"
	.string "That’s what Fossils are.$"

OreburghCityNorth_Text_HugeMountain:
	.string "Up ahead there’s a huge mountain\n"
	.string "that towers above everything.\p"
	.string "It divides Sinnoh into two distinct\n"
	.string "halves.$"

OreburghCityNorth_Text_TownSign: 
	.string "Oreburgh City\n"
	.string "City of Energy$"

OreburghCityNorth_Text_GymSign:
	.string "Oreburgh City Pokémon Gym\n"
	.string "Leader: Roark\l"
	.string "“Call me Roark the Rock!”$"

OreburghCityNorth_Text_MuseumSign:
	.string "Oreburgh Mining Museum\n"
	.string "“Coal Mining and You!”$"

OreburghCityNorth_Text_MuseumBlock:
	.string "This building is closed for\n"
	.string "maintenance.\p"
	.string "Please come back later.$"
