.set LOCALID_RIVAL, 1
.set LOCALID_PROF, 2
.set LOCALID_HELPER, 3
.set LOCALID_WILDA, 4
.set LOCALID_WILDB, 5
.set LOCALID_BRIEFCASE, 6

LakeVerity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LakeVerity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LakeVerity_OnFrame
	.byte 0

	@ State descriptions for VAR_VERITY_STATE
	@ 1: After First Lake Scene

LakeVerity_OnTransition:
	call Common_EventScript_SetupRivalGfxId
	end

LakeVerity_OnFrame:
	map_script_2 VAR_VERITY_STATE, 0, LakeVerity_EventScript_IntroScene
	.2byte 0

LakeVerity_EventScript_IntroScene::
	lock
	special SpawnCameraObject
	setvar VAR_VERITY_STATE, 1
	msgbox LakeVerity_Text_Rival1, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_CAMERA, LakeVerity_Movement_CameraPan1
	waitmovement 0
	delay 30
	msgbox LakeVerity_Text_Professor1, MSGBOX_SIGN
	applymovement LOCALID_PROF, Common_Movement_FaceRight
	waitmovement 0
	delay 10
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LakeVerity_EventScript_ProfessorSay1
	call_if_eq VAR_RESULT, FEMALE, LakeVerity_EventScript_ProfessorSay2
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement LOCALID_HELPER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 30
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceRight
	waitmovement 0
	call_if_eq VAR_RESULT, MALE, LakeVerity_EventScript_HelperSay1
	call_if_eq VAR_RESULT, FEMALE, LakeVerity_EventScript_HelperSay2
	delay 30
	delay 30
	addobject LOCALID_BRIEFCASE
	applymovement OBJ_EVENT_ID_CAMERA, LakeVerity_Movement_CameraPan2
	applymovement LOCALID_PROF, LakeVerity_Movement_ProfessorLeave1
	applymovement LOCALID_HELPER, LakeVerity_Movement_HelperLeave1
	waitmovement 0
	delay 10
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceRight
	applymovement LOCALID_RIVAL, Common_Movement_WalkRight
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_FaceLeft
	waitmovement 0
	msgbox LakeVerity_Text_Professor2, MSGBOX_SIGN
	applymovement LOCALID_PROF, LakeVerity_Movement_ProfessorLeave2
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_PROF
	applymovement LOCALID_HELPER, LakeVerity_Movement_HelperLeave2
	waitmovement 0
	call_if_eq VAR_RESULT, MALE, LakeVerity_EventScript_HelperSay3
	call_if_eq VAR_RESULT, FEMALE, LakeVerity_EventScript_HelperSay4
	applymovement LOCALID_HELPER, LakeVerity_Movement_ProfessorLeave2
	waitmovement 0
	playse SE_EXIT
	removeobject LOCALID_HELPER
	delay 48
	applymovement LOCALID_RIVAL, Common_Movement_WalkLeft
	waitmovement 0
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox LakeVerity_Text_Rival2, MSGBOX_SIGN
	delay 30
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 30
	msgbox LakeVerity_Text_Rival3, MSGBOX_SIGN
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 30
	msgbox LakeVerity_Text_Rival4, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_CAMERA, LakeVerity_Movement_Player1
	applymovement OBJ_EVENT_ID_PLAYER, LakeVerity_Movement_Player1
	applymovement LOCALID_RIVAL, LakeVerity_Movement_Rival1
	waitmovement 0
	addobject LOCALID_BRIEFCASE
	applymovement OBJ_EVENT_ID_CAMERA, LakeVerity_Movement_Player2
	applymovement OBJ_EVENT_ID_PLAYER, LakeVerity_Movement_Player2
	applymovement LOCALID_RIVAL, LakeVerity_Movement_Rival2
	waitmovement 0
	msgbox LakeVerity_Text_Rival5, MSGBOX_SIGN
	addobject LOCALID_WILDA
	addobject LOCALID_WILDB
	applymovement LOCALID_WILDA, LakeVerity_Movement_WildLeft
	applymovement LOCALID_WILDB, LakeVerity_Movement_WildUp
	waitmovement 0
	delay 10
	applymovement LOCALID_RIVAL, Common_Movement_FaceRight
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	msgbox LakeVerity_Text_Rival6, MSGBOX_SIGN
	applymovement LOCALID_RIVAL, Common_Movement_FaceDown
	waitmovement 0
	msgbox LakeVerity_Text_Rival7, MSGBOX_SIGN
	special ChooseStarter
	removeobject LOCALID_WILDA
	removeobject LOCALID_WILDB
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	switch VAR_STARTER_MON
	case 0, LakeVerity_EventScript_RivalSayA
	case 1, LakeVerity_EventScript_RivalSayB
	case 2, LakeVerity_EventScript_RivalSayC
	end

LakeVerity_EventScript_IntroScenePost::
	addobject LOCALID_HELPER
	setobjectxy LOCALID_HELPER, 11, 15
	applymovement LOCALID_HELPER, Common_Movement_FaceUp
	waitmovement 0
	applymovement LOCALID_RIVAL, LakeVerity_Movement_Rival3
	applymovement OBJ_EVENT_ID_PLAYER, LakeVerity_Movement_Player3
	applymovement LOCALID_HELPER, LakeVerity_Movement_HelperArrive1
	waitmovement 0
	checkplayergender
	call_if_eq VAR_RESULT, MALE, LakeVerity_EventScript_HelperSay5
	call_if_eq VAR_RESULT, FEMALE, LakeVerity_EventScript_HelperSay6
	applymovement LOCALID_HELPER, LakeVerity_Movement_HelperShift1
	waitmovement 0
	call_if_eq VAR_RESULT, MALE, LakeVerity_EventScript_HelperSay7
	call_if_eq VAR_RESULT, FEMALE, LakeVerity_EventScript_HelperSay8
	applymovement LOCALID_HELPER, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 16
	removeobject LOCALID_BRIEFCASE
	delay 16
	applymovement LOCALID_RIVAL, LakeVerity_Movement_Rival4
	applymovement OBJ_EVENT_ID_PLAYER, LakeVerity_Movement_Rival4
	applymovement LOCALID_HELPER, LakeVerity_Movement_HelperLeave3
	waitmovement 0
	removeobject LOCALID_HELPER
	delay 16
	msgbox LakeVerity_Text_Rival8, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_PLAYER, LakeVerity_Movement_Player4
	applymovement LOCALID_RIVAL, LakeVerity_Movement_Rival5
	waitmovement 0
	msgbox LakeVerity_Text_Rival9, MSGBOX_SIGN
	applymovement OBJ_EVENT_ID_CAMERA, LakeVerity_Movement_Player5
	applymovement OBJ_EVENT_ID_PLAYER, LakeVerity_Movement_Player5
	applymovement LOCALID_RIVAL, LakeVerity_Movement_Rival6
	waitmovement 0
	removeobject LOCALID_RIVAL
	delay_16
	special RemoveCameraObject
	warp MAP_LAKEFRONT_VERITY, 1
	clearflag FLAG_HIDE_VERITY_LAKEFRONT_RIVAL
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_HIDE_VERITY_INTRO_OTHER
	setflag FLAG_HIDE_VERITY_INTRO_HELPER
	release
	end

LakeVerity_EventScript_ProfessorSay1::
	msgbox LakeVerity_Text_Professor3, MSGBOX_SIGN
	return

LakeVerity_EventScript_ProfessorSay2::
	msgbox LakeVerity_Text_Professor4, MSGBOX_SIGN
	return

LakeVerity_EventScript_HelperSay1::
	msgbox LakeVerity_Text_Helper1, MSGBOX_SIGN
	return

LakeVerity_EventScript_HelperSay2::
	msgbox LakeVerity_Text_Helper2, MSGBOX_SIGN
	return

LakeVerity_EventScript_HelperSay3::
	msgbox LakeVerity_Text_Helper3, MSGBOX_SIGN
	return

LakeVerity_EventScript_HelperSay4::
	msgbox LakeVerity_Text_Helper4, MSGBOX_SIGN
	return

LakeVerity_EventScript_HelperSay5::
	msgbox LakeVerity_Text_Helper5, MSGBOX_SIGN
	return

LakeVerity_EventScript_HelperSay6::
	msgbox LakeVerity_Text_Helper6, MSGBOX_SIGN
	return

LakeVerity_EventScript_HelperSay7::
	msgbox LakeVerity_Text_Helper7, MSGBOX_SIGN
	return

LakeVerity_EventScript_HelperSay8::
	msgbox LakeVerity_Text_Helper8, MSGBOX_SIGN
	return

LakeVerity_EventScript_RivalSayA::
	msgbox LakeVerity_Text_RivalA, MSGBOX_SIGN
	goto LakeVerity_EventScript_IntroScenePost
	end

LakeVerity_EventScript_RivalSayB::
	msgbox LakeVerity_Text_RivalB, MSGBOX_SIGN
	goto LakeVerity_EventScript_IntroScenePost
	end

LakeVerity_EventScript_RivalSayC::
	msgbox LakeVerity_Text_RivalC, MSGBOX_SIGN
	goto LakeVerity_EventScript_IntroScenePost
	end

LakeVerity_Movement_CameraPan1:
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

LakeVerity_Movement_CameraPan2:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeVerity_Movement_ProfessorLeave1:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeVerity_Movement_ProfessorLeave2:
	walk_down
	walk_down
	step_end

LakeVerity_Movement_HelperLeave1:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	step_end

LakeVerity_Movement_HelperLeave2:
	walk_down
	walk_in_place_left
	delay_8
	walk_in_place_right
	delay_4
	walk_in_place_left
	delay_8
	walk_in_place_down
	delay_16
	step_end

LakeVerity_Movement_HelperLeave3:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeVerity_Movement_HelperArrive1:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	face_left
	step_end

LakeVerity_Movement_HelperShift1:
	walk_in_place_down
	delay_16
	walk_in_place_right
	delay_16
	walk_in_place_down
	delay_16
	step_end

LakeVerity_Movement_Rival1:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	step_end
	
LakeVerity_Movement_Rival2:
	walk_up
	walk_up
	walk_up
	walk_up
	walk_right
	walk_up
	face_left
	step_end

LakeVerity_Movement_Rival3:
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	delay_16
	walk_right
	walk_in_place_left
	step_end

LakeVerity_Movement_Rival4:
	delay_16
	walk_in_place_down
	step_end

LakeVerity_Movement_Rival5:
	walk_left
	walk_down
	walk_in_place_left
	step_end

LakeVerity_Movement_Rival6:
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeVerity_Movement_Player1:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LakeVerity_Movement_Player2:
	walk_right
	walk_up
	walk_up
	walk_up
	walk_up
	step_end

LakeVerity_Movement_Player3:
	delay_16
	delay_16
	delay_16
	delay_8
	face_down
	delay_16
	delay_8
	walk_in_place_right
	walk_in_place_up
	step_end

LakeVerity_Movement_Player4:
	delay_16
	walk_in_place_right
	step_end

LakeVerity_Movement_Player5:
	delay_16
	face_down
	delay_16
	walk_down
	walk_down
	walk_down
	walk_down
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end

LakeVerity_Movement_WildLeft:
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	walk_faster_left
	step_end

LakeVerity_Movement_WildUp:
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	walk_faster_up
	step_end

LakeVerity_Text_Rival1:
	.string "{RIVAL}: What's going on...?$"

LakeVerity_Text_Rival2:
	.string "{RIVAL}: What was that about?\n"
	.string "Those two...$"

LakeVerity_Text_Rival3:
	.string "Huh? {PLAYER}!\n"
	.string "Let's go check this out!$"

LakeVerity_Text_Rival4:
	.string "...\n"
	.string "...\p"
	.string "What's that?\n"
	.string "Don't go into the tall grass?\p"
	.string "No problem, no problem!\p"
	.string "We won't be in there long enough\n"
	.string "for a wild Pokemon to come out.$"
	
LakeVerity_Text_Rival5:
	.string "It's...\n"
	.string "A briefcase?\p"
	.string "Those people forgot it here.\n"
	.string "What are we supposed to do with it?\p"
	.string "We can try to deliver it, but who are\n"
	.string "they? I heard them say professor...$"

LakeVerity_Text_Rival6:
	.string "Waaah!\n"
	.string "Po-Pokemon?!$"
	
LakeVerity_Text_Rival7:
	.string "What's going on?!$"

LakeVerity_Text_RivalA:
	.string "{RIVAL}: Fwaaah!\n"
	.string "Your TURTWIG totally rocked!\p"
	.string "But my CHIMCHAR was way tougher\n"
	.string "than yours!\p"
	.string "...They were other people's\n"
	.string "Pokemon, though...\p"
	.string "But we had to use them...\n"
	.string "They won't mind, will they?$"

LakeVerity_Text_RivalB:
	.string "{RIVAL}: Fwaaah!\n"
	.string "Your CHIMCHAR totally rocked!\p"
	.string "But my PIPLUP was way tougher\n"
	.string "than yours!\p"
	.string "...They were other people's\n"
	.string "Pokemon, though...\p"
	.string "But we had to use them...\n"
	.string "They won't mind, will they?$"

LakeVerity_Text_RivalC:
	.string "{RIVAL}: Fwaaah!\n"
	.string "Your PIPLUP totally rocked!\p"
	.string "But my TURTWIG was way tougher\n"
	.string "than yours!\p"
	.string "...They were other people's\n"
	.string "Pokemon, though...\p"
	.string "But we had to use them...\n"
	.string "They won't mind, will they?$"

LakeVerity_Text_Rival8:
	.string "{RIVAL}: What was that about?$"

LakeVerity_Text_Rival9:
	.string "I don't know what's going on.\n"
	.string "{PLAYER}, let's get out of here.\p"
	.string "My Pokemon got hurt from that\n"
	.string "battle.\p"
	.string "If we get attacked by another\n"
	.string "Pokemon, we might be in trouble.$"

LakeVerity_Text_Professor1:
	.string "Professor, there isn't anything out\n"
	.string "of the ordinary on the other side,\l"
	.string "either!\p"
	.string "Professor: Hmm...\n"
	.string "I may have been mistaken...\p"
	.string "Something appears to be different\n"
	.string "than it was before, but...\p"
	.string "Fine! It's enough that we have\n"
	.string "seen the lake.$"

LakeVerity_Text_Professor2:
	.string "Professor: Excuse me.\n"
	.string "Let us pass, please.$"

LakeVerity_Text_Professor3:
	.string "Dawn, we're leaving.$"

LakeVerity_Text_Professor4:
	.string "Lucas, we're leaving.$"

LakeVerity_Text_Helper1:
	.string "Dawn: Professor, how are you enjoying\n"
	.string "being back in Sinnoh?\p"
	.string "After being away for four years,\n"
	.string "it must be exciting again?\p"
	.string "Professor: ...Hm.\n"
	.string "There is one thing I can say.\p"
	.string "There are many rare kinds of Pokemon\n"
	.string "in Sinnoh.\p"
	.string "The region should serve us very well\n"
	.string "in regard to our studies.$"

LakeVerity_Text_Helper2:
	.string "Lucas: Professor, you've been gone\n"
	.string "for four years now.\p"
	.string "How are you enjoying being back in\n"
	.string "Sinnoh?\p"
	.string "Professor: ...Hm.\n"
	.string "There is one thing I can say.\p"
	.string "There are many rare kinds of Pokemon\n"
	.string "in Sinnoh.\p"
	.string "The region should serve us very well\n"
	.string "in regard to our studies.$"

LakeVerity_Text_Helper3:
	.string "Dawn: I beg your pardon...\n"
	.string "We'll be on our way.$"

LakeVerity_Text_Helper4:
	.string "Lucas: Sorry folks.$"

LakeVerity_Text_Helper5:
	.string "Dawn: Oh! There's the briefcase!\p"
	.string "The professor would have been furious\n"
	.string "if I'd lost it...$"

LakeVerity_Text_Helper6:
	.string "Lucas: Whew! You found the briefcase?\p"
	.string "The professor would've gone through'\n"
	.string "the roof if he knew I forgot it here.$"

LakeVerity_Text_Helper7:
	.string "Dawn: Huh?\n"
	.string "On, no!\p"
	.string "Did you...\n"
	.string "Did you use the Pokemon in here?\p"
	.string "You did?! Oh, my gosh!\n"
	.string "What's the professor going to say...?\p"
	.string "...This is so not good...\n"
	.string "I'll take this briefcase for now.$"

LakeVerity_Text_Helper8:
	.string "Lucas: Hunh?\n"
	.string "Whaaaat?!\p"
	.string "Did you guys...\n"
	.string "Did you use these Pokemon?!\p"
	.string "Oh, man... How am I gonna explain\n"
	.string "this to the professor?\p"
	.string "...This briefcase is the professor's,\n"
	.string "so I'll take it, OK?$"
