JubilifeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, JubilifeCity_OnTransition
	.byte 0

@ State descriptions For VAR_JUBILIFE_CITY_STATE
@ 1: Encountered helper

JubilifeCity_OnTransition:
	setflag FLAG_VISITED_JUBILIFE_CITY
	call Common_EventScript_SetupRivalGfxId
	end

JubilifeCity_EventScript_HelperEncounter_1::
	lockall
	special SpawnCameraObject
	setvar VAR_JUBILIFE_CITY_STATE, 1
	setobjectxy LOCALID_JUBILIFE_HELPER, 54, 54
	call JubilifeCity_EventScript_HelperWalkDown
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_WalkRight
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_WalkUp
	applymovement LOCALID_CAMERA, Common_Movement_WalkRight
	applymovement LOCALID_PLAYER, Common_Movement_WalkRight
	waitmovement 0
	goto JubilifeCity_EventScript_HelperWalkUp
	end

JubilifeCity_EventScript_HelperEncounter_2::
	lockall
	special SpawnCameraObject
	setvar VAR_JUBILIFE_CITY_STATE, 1
	call JubilifeCity_EventScript_HelperWalkDown
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_WalkUp
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	goto JubilifeCity_EventScript_HelperWalkUp
	end

JubilifeCity_EventScript_HelperEncounter_3::
	lockall
	special SpawnCameraObject
	setvar VAR_JUBILIFE_CITY_STATE, 1
	setobjectxy LOCALID_JUBILIFE_HELPER, 56, 54
	call JubilifeCity_EventScript_HelperWalkDown
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_WalkLeft
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp
	applymovement LOCALID_PLAYER, Common_Movement_WalkUp
	waitmovement 0
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_WalkUp
	applymovement LOCALID_CAMERA, Common_Movement_WalkLeft
	applymovement LOCALID_PLAYER, Common_Movement_WalkLeft
	waitmovement 0
	goto JubilifeCity_EventScript_HelperWalkUp
	end

JubilifeCity_EventScript_HelperWalkDown::
	applymovement LOCALID_CAMERA, Common_Movement_WalkUp
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_WalkDown2
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	applymovement LOCALID_CAMERA, Common_Movement_WalkDown
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_WalkDown3
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, JubilifeCity_EventScript_DawnCountParty
	call_if_eq VAR_RESULT, FEMALE, JubilifeCity_EventScript_LucasCountParty
	return

JubilifeCity_EventScript_DawnCountParty::
	msgbox JubilifeCity_Text_AreYouCatching, MSGBOX_DEFAULT
	specialvar VAR_0x8004, CalculatePlayerPartyCount
	call_if_le VAR_0x8004, 3, JubilifeCity_EventScript_DawnFew
	call_if_eq VAR_0x8004, 4, JubilifeCity_EventScript_Dawn4
	call_if_eq VAR_0x8004, 5, JubilifeCity_EventScript_Dawn5
	call_if_eq VAR_0x8004, 6, JubilifeCity_EventScript_Dawn6
	msgbox JubilifeCity_Text_DawnKnowMore, MSGBOX_DEFAULT
	closemessage
	return

JubilifeCity_EventScript_LucasCountParty::
	msgbox JubilifeCity_Text_HowManyCaught, MSGBOX_DEFAULT
	specialvar VAR_0x8004, CalculatePlayerPartyCount
	call_if_le VAR_0x8004, 3, JubilifeCity_EventScript_LucasFew
	call_if_eq VAR_0x8004, 4, JubilifeCity_EventScript_Lucas4
	call_if_eq VAR_0x8004, 5, JubilifeCity_EventScript_Lucas5
	call_if_eq VAR_0x8004, 6, JubilifeCity_EventScript_Lucas6
	msgbox JubilifeCity_Text_LucasKnowMore, MSGBOX_DEFAULT
	closemessage
	return

JubilifeCity_EventScript_DawnFew::
	msgbox JubilifeCity_Text_FeelSafer, MSGBOX_DEFAULT
	return

JubilifeCity_EventScript_LucasFew::
	msgbox JubilifeCity_Text_CatchMore, MSGBOX_DEFAULT
	return

JubilifeCity_EventScript_Dawn4::
	msgbox JubilifeCity_Text_AlreadyGot4, MSGBOX_DEFAULT
	return

JubilifeCity_EventScript_Dawn5::
	msgbox JubilifeCity_Text_AlreadyGot5, MSGBOX_DEFAULT
	return

JubilifeCity_EventScript_Dawn6::
	msgbox JubilifeCity_Text_AlreadyGot6, MSGBOX_DEFAULT
	return

JubilifeCity_EventScript_Lucas4::
	msgbox JubilifeCity_Text_AlreadyHave4, MSGBOX_DEFAULT
	return

JubilifeCity_EventScript_Lucas5::
	msgbox JubilifeCity_Text_AlreadyHave5, MSGBOX_DEFAULT
	return

JubilifeCity_EventScript_Lucas6::
	msgbox JubilifeCity_Text_AlreadyHave6, MSGBOX_DEFAULT
	return

JubilifeCity_EventScript_HelperWalkUp::
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_Walk_Up17
	applymovement LOCALID_CAMERA, Common_Movement_Walk_Up17
	applymovement LOCALID_PLAYER, Common_Movement_Walk_Up17
	waitmovement 0
	msgbox JubilifeCity_Text_ThatMan, MSGBOX_SIGN
	applymovement LOCALID_JUBILIFE_LOOKER, JubilifeCity_Movement_LookerScurry1
	waitmovement 0
	applymovement LOCALID_JUBILIFE_LOOKER, JubilifeCity_Movement_LookerScurry2
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_WalkUp2
	applymovement LOCALID_CAMERA, JubilifeCity_Movement_PlayerMeetLooker
	applymovement LOCALID_PLAYER, JubilifeCity_Movement_PlayerMeetLooker
	waitmovement 0
	msgbox JubilifeCity_Text_Um, MSGBOX_DEFAULT
	applymovement LOCALID_JUBILIFE_LOOKER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement LOCALID_JUBILIFE_LOOKER, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	msgbox JubilifeCity_Text_HowDidYouKnow, MSGBOX_SIGN
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	msgbox JubilifeCity_Text_BegYourPardon, MSGBOX_YESNO
	call_if_eq VAR_RESULT, YES, JubilifeCity_EventScript_LookerYes
	call_if_eq VAR_RESULT, NO, JubilifeCity_EventScript_LookerNo
	msgbox JubilifeCity_Text_DoNotHeed, MSGBOX_DEFAULT
	@ FODO: Implement and give Vs. Recorder item
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox JubilifeCity_Text_NiftyDevice, MSGBOX_SIGN
	applymovement LOCALID_JUBILIFE_LOOKER, JubilifeCity_Movement_LookAround
	waitmovement 0
	msgbox JubilifeCity_Text_HaveRequest, MSGBOX_SIGN
	applymovement LOCALID_JUBILIFE_HELPER, JubilifeCity_Movement_HelperWatchLooker
	applymovement LOCALID_PLAYER, JubilifeCity_Movement_PlayerWatchLooker
	applymovement LOCALID_JUBILIFE_LOOKER, JubilifeCity_Movement_LookerScurry3
	waitmovement 0
	closemessage
	delay 48
	delay 48
	msgbox JubilifeCity_Text_WorkingInternational, MSGBOX_SIGN
	delay 48
	delay 48
	applymovement LOCALID_JUBILIFE_HELPER, JubilifeCity_Movement_HelperSeeSchool
	applymovement LOCALID_PLAYER, JubilifeCity_Movement_PlayerSeeSchool
	waitmovement 0
	msgbox JubilifeCity_Text_HereItIs, MSGBOX_SIGN
	applymovement LOCALID_JUBILIFE_HELPER, JubilifeCity_Movement_HelperLeaveSchool
	waitmovement 0
	msgbox JubilifeCity_Text_SawYourFriend, MSGBOX_SIGN
	applymovement LOCALID_JUBILIFE_HELPER, Common_Movement_WalkDown6
	waitmovement 0
	setflag FLAG_HIDE_JUBILIFE_LOOKER
	setflag FLAG_HIDE_JUBILIFE_HELPER
	removeobject LOCALID_JUBILIFE_LOOKER
	removeobject LOCALID_JUBILIFE_HELPER
	special RemoveCameraObject
	end

JubilifeCity_EventScript_LookerYes::
	msgbox JubilifeCity_Text_ThatIsCorrect, MSGBOX_DEFAULT
	return

JubilifeCity_EventScript_LookerNo::
	msgbox JubilifeCity_Text_ClaimNotKnow, MSGBOX_DEFAULT
	return
	
JubilifeCity_Movement_LookerScurry1:
	walk_in_place_left
	delay_16
	delay_16
	walk_in_place_down
	delay_16
	delay_16
	walk_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_in_place_right
	delay_16
	delay_16
	walk_in_place_up
	delay_16
	delay_16
	step_end

JubilifeCity_Movement_LookerScurry2:
	walk_right
	walk_fast_right
	walk_fast_right
	step_end

JubilifeCity_Movement_LookerScurry3:
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_in_place_left
	delay_16
	walk_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	walk_fast_up
	step_end

JubilifeCity_Movement_LookAround:
	walk_in_place_left
	delay_16
	walk_in_place_right
	delay_16
	delay_16
	walk_in_place_down
	step_end

JubilifeCity_Movement_PlayerMeetLooker:
	walk_up
	walk_up
	walk_right
	walk_up
	step_end

JubilifeCity_Movement_PlayerWatchLooker:
	delay_16
	walk_in_place_right
	delay_16
	delay_16
	walk_in_place_up
	step_end

JubilifeCity_Movement_HelperWatchLooker:
	walk_in_place_right
	delay_16
	delay_16
	delay_16
	walk_in_place_up
	step_end

JubilifeCity_Movement_PlayerSeeSchool:
	delay_16
	walk_in_place_right
	step_end

JubilifeCity_Movement_HelperSeeSchool:
	walk_down
	walk_left
	walk_left
	step_end

JubilifeCity_Movement_HelperLeaveSchool:
	walk_up
	walk_right
	walk_right
	step_end

JubilifeCity_Text_AreYouCatching:
	.string "Dawn: Hi, {PLAYER}!\n"
	.string "Are you catching Pokemon?$"

JubilifeCity_Text_HowManyCaught:
	.string "Lucas: Hey, {PLAYER}!\n"
	.string "How many Pokemon have you caught?$"
	
JubilifeCity_Text_FeelSafer:
	.string "...Um...\p"
	.string "I think you'd feel a lot safer if you\n"
	.string "were to catch some more.\p"
	.string "You know, like when you need to travel\n"
	.string "to faraway places.$"

JubilifeCity_Text_CatchMore:
	.string "Huh?\n"
	.string "I think you should catch some more.\p"
	.string "It might be more of a challenge\n"
	.string "raising a lot of Pokemon...\p"
	.string "But it's worth it. The more Pokemon\n"
	.string "you have, the happier you'll be.$"

JubilifeCity_Text_AlreadyGot4:
	.string "Wow! You've already got 4 Pokemon\n"
	.string "with you!\p"
	.string "At that pace, your Pokedex should\n"
	.string "be full in non time at all!$"

JubilifeCity_Text_AlreadyGot5:
	.string "Wow! You've already got 5 Pokemon\n"
	.string "with you!\p"
	.string "At that pace, your Pokedex should\n"
	.string "be full in non time at all!$"

JubilifeCity_Text_AlreadyGot6:
	.string "Wow! You've already got 6 Pokemon\n"
	.string "with you!\p"
	.string "At that pace, your Pokedex should\n"
	.string "be full in non time at all!$"

JubilifeCity_Text_AlreadyHave4:
	.string "Whoa! You already have 4 Pokemon\n"
	.string "with you!$"

JubilifeCity_Text_AlreadyHave5:
	.string "Whoa! You already have 5 Pokemon\n"
	.string "with you!$"

JubilifeCity_Text_AlreadyHave6:
	.string "Whoa! You already have 6 Pokemon\n"
	.string "with you!$"

JubilifeCity_Text_DawnKnowMore:
	.string "Oh, I know! Don't you think it's\n"
	.string "better to know more about Pokemon?\p"
	.string "Sure it is!\n"
	.string "I know just the place.\p"
	.string "Come on!\n"
	.string "Don't be shy. Follow me!$"

JubilifeCity_Text_LucasKnowMore:
	.string "Hey, that's right! Don't you think it's\n"
	.string "better to know more about Pokemon?\p"
	.string "Sure it is!\n"
	.string "There's this great place for that.\p"
	.string "Come on! It's all right.\n"
	.string "Follow me.$"

JubilifeCity_Text_ThatMan:
	.string "Dawn: That man...\n"
	.string "What is he doing?$"

JubilifeCity_Text_Um:
	.string "Dawn: Um...$"

JubilifeCity_Text_HowDidYouKnow:
	.string "WHAAAT?!\p"
	.string "Mysterious man: ...How did you know?\p"
	.string "How did you unmask me as a member of\n"
	.string "the International Police?!$"

JubilifeCity_Text_BegYourPardon:
	.string "Dawn: Huh? What? I beg your pardon?\n"
	.string "I was just making conversation...\p"
	.string "Shady man: ...Heh. You claim you were\n"
	.string "only making conversation, do you?\p"
	.string "But I know better not to believe that.\n"
	.string "No, no, no.\p"
	.string "You recognized right away that I was\n"
	.string "someone extraordinary.\p"
	.string "That is why you spoke to me, is it not?\n"
	.string "Your power of observation is fearsome!\p"
	.string "Quite admirable, you are!\p"
	.string "Now that my cover has been blown, let\n"
	.string "me introduce myself.\p"
	.string "I am a globe-trotting elote of the\n"
	.string "International Police.\p"
	.string "My name... Ah, no, I shall inform you\n"
	.string "only of my code name.\p"
	.string "My code name, it is Looker.\n"
	.string "It is what they all call me.\p"
	.string "Incidentally, is the saying, “Don't be\n"
	.string "a thief!” familar to you?$"

JubilifeCity_Text_ThatIsCorrect:
	.string "Looker: Yes, that is correct.\n"
	.string "aking what belongs to others is wrong.$"

JubilifeCity_Text_ClaimNotKnow:
	.string "Looker: No? You claim to not know it?\n"
	.string "How could that be?\p"
	.string "Perhaps your mama has said it, but you\n"
	.string "have forgotten it, like usual?\p"
	.string "Now listen my friends. It is wrong to\n"
	.string "take what belongs to others.$"

JubilifeCity_Text_DoNotHeed:
	.string "Unfortunately, there are apparently\n"
	.string "those who do not heed those words.\p"
	.string "In Sinnoh, in fact, there are criminals\n"
	.string "stealing the Pokemon of others.\p"
	.string "I have, therefore, been on the lookout\n"
	.string "for characters arousing my suspicion.\p"
	.string "Incidentally, you are Trainers, yes?\n"
	.string "Perhaps you can make use of this?$"

JubilifeCity_Text_NiftyDevice:
	.string "That Vs. Recorder, it is a nifty device\n"
	.string "for recording a match.\p"
	.string "I obtained it because it is quite popular\n"
	.string "these days.\p"
	.string "But myself, I do not do Pokemon\n"
	.string "battling very often.\p"
	.string "It will be in better hands with you.$"

JubilifeCity_Text_HaveRequest:
	.string "Looker: Also, I have a request.\p"
	.string "If you were to see me again, I ask that\n"
	.string "you not talk to me, for I am on duty.\p"
	.string "...Actually, yes, yes, you may speak to\n"
	.string "me. You must.\p"
	.string "Not because I am lonely, no no!\n"
	.string "You must inform me of bad guys!\l"
	.string "You must inform me of any happenings!$"

JubilifeCity_Text_WorkingInternational:
	.string "Dawn: ...Working for the International\p"
	.string "Police must be hard.$"

JubilifeCity_Text_HereItIs:
	.string "{PLAYER}, here it is.\n"
	.string "It's the Trainers' School.\l"
	.string "The name says it all!$"

JubilifeCity_Text_SawYourFriend:
	.string "I saw your friend {RIVAL} go in\n"
	.string "earlier.\p"
	.string "He could still be in there studying.\n"
	.string "OK, bye now!$"
