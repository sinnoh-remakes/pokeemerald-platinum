.set LOCALID_RIVAL, 1
.set LOCALID_PROF, 2
.set LOCALID_DAWN, 3
.set LOCALID_LUCAS, 4
.set LOCALID_WILDA, 5
.set LOCALID_WILDB, 6
.set LOCALID_BRIEFCASE, 7

LakeVerity_MapScripts::
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LakeVerity_OnFrame
	.byte 0

	@ State descriptions for VAR_VERITY_STATE
	@ 0: Prior to First Lake Scene
	@ 1: After First Lake Scene

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
	@ TODO: Add prof helper gender logic to whole function
	msgbox LakeVerity_Text_HelperDawn1, MSGBOX_SIGN
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceDown
	waitmovement 0
	applymovement LOCALID_DAWN, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	delay 30
	applymovement LOCALID_PROF, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox LakeVerity_Text_HelperDawn2, MSGBOX_SIGN
	delay 30
	delay 30
	addobject LOCALID_BRIEFCASE
	applymovement OBJ_EVENT_ID_CAMERA, LakeVerity_Movement_CameraPan2
	applymovement LOCALID_PROF, LakeVerity_Movement_ProfessorLeave1
	applymovement LOCALID_DAWN, LakeVerity_Movement_HelperLeave1
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
	removeobject LOCALID_PROF
	applymovement LOCALID_DAWN, LakeVerity_Movement_HelperLeave2
	waitmovement 0
	msgbox LakeVerity_Text_HelperDawn3, MSGBOX_SIGN
	applymovement LOCALID_DAWN, LakeVerity_Movement_ProfessorLeave2
	waitmovement 0
	removeobject LOCALID_DAWN
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
	@ Add post battle content
	delay 30
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_WalkInPlaceUp
	applymovement LOCALID_RIVAL, Common_Movement_WalkInPlaceDown
	waitmovement 0
	msgbox LakeVerity_Text_Rival8, MSGBOX_SIGN
	
	special RemoveCameraObject
	setflag FLAG_HIDE_VERITY_INTRO_OTHER
	setflag FLAG_HIDE_VERITY_INTRO_MAY
	setflag FLAG_HIDE_VERITY_INTRO_BRENDAN
	release
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

@ TODO: Add custom string based on starter selected
LakeVerity_Text_Rival8:
	.string "{RIVAL}: Fwaaah!\n"
	.string "Your CHIMCHAR totally rocked!\p"
	.string "But my PIPLUP was way toughter\n"
	.string "than yours!\p"
	.string "...They were other people's\n"
	.string "Pokemon, though...\p"
	.string "But we had to use them...\n"
	.string "They won't mind, will they?$"

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

LakeVerity_Text_HelperDawn1:
	.string "Dawn, we're leaving.$"

LakeVerity_Text_HelperDawn2:
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

LakeVerity_Text_HelperDawn3:
	.string "Dawn: I beg your pardon...\n"
	.string "We'll be on our way.$"
