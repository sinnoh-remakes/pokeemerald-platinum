EternaCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EternaCity_Gym_OnTransition
	map_script_2 VAR_ETERNA_GYM_STATE, 11, EternaCity_Gym_EventScript_PanCameraBack
	map_script_2 VAR_ETERNA_GYM_STATE, 12, EternaCity_Gym_EventScript_PanCameraBack
	map_script_2 VAR_ETERNA_GYM_STATE, 13, EternaCity_Gym_EventScript_PanCameraBack
	.byte 0

@ VAR_ETERNA_GYM_STATE: 0 = nothing beaten, 1 = Caroline, 2 = Jenna, 3 = Angela.
@ Adding 10 marks a layout swap whose camera pan back is still pending.

EternaCity_Gym_OnTransition:
	switch VAR_ETERNA_GYM_STATE
	case 1, EternaCity_Gym_EventScript_SetLayout2
	case 11, EternaCity_Gym_EventScript_SetLayout2
	case 2, EternaCity_Gym_EventScript_SetLayout3
	case 12, EternaCity_Gym_EventScript_SetLayout3
	case 3, EternaCity_Gym_EventScript_SetLayout4
	case 13, EternaCity_Gym_EventScript_SetLayout4
	end

EternaCity_Gym_EventScript_SetLayout2::
	setmaplayoutindex LAYOUT_ETERNA_CITY_GYM_2
	end

EternaCity_Gym_EventScript_SetLayout3::
	setmaplayoutindex LAYOUT_ETERNA_CITY_GYM_3
	end

EternaCity_Gym_EventScript_SetLayout4::
	setmaplayoutindex LAYOUT_ETERNA_CITY_GYM_4
	end

@ Pans the camera to the room center (dummy movement for now), self-warps so ON_TRANSITION
@ swaps the layout, then pans back in PanCameraBack (the warp resets the script context).
EternaCity_Gym_EventScript_SwapLayout::
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, EternaCity_Gym_Movement_Dummy
	waitmovement 0
	delay 30
	addvar VAR_ETERNA_GYM_STATE, 10
	getplayerxy VAR_0x8000, VAR_0x8001
	warp MAP_ETERNA_CITY_GYM, VAR_0x8000, VAR_0x8001
	waitstate
	end

EternaCity_Gym_EventScript_PanCameraBack::
	lockall
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, EternaCity_Gym_Movement_Dummy
	waitmovement 0
	special RemoveCameraObject
	subvar VAR_ETERNA_GYM_STATE, 10
	releaseall
	end

EternaCity_Gym_Movement_Dummy:
	step_end

EternaCity_Gym_EventScript_Caroline::
	trainerbattle_single TRAINER_PT_CAROLINE, EternaCity_Gym_Text_CarolineIntro, EternaCity_Gym_Text_CarolineDefeated, EternaCity_Gym_EventScript_CarolineAfterBattle
	end

EternaCity_Gym_EventScript_CarolineAfterBattle::
	msgbox EternaCity_Gym_Text_CarolinePostBattle, MSGBOX_DEFAULT
	closemessage
	goto_if_ge VAR_ETERNA_GYM_STATE, 1, EternaCity_Gym_EventScript_EndTrainer
	setvar VAR_ETERNA_GYM_STATE, 1
	goto EternaCity_Gym_EventScript_SwapLayout
	end

EternaCity_Gym_EventScript_Jenna::
	trainerbattle_single TRAINER_PT_JENNA, EternaCity_Gym_Text_JennaIntro, EternaCity_Gym_Text_JennaDefeated, EternaCity_Gym_EventScript_JennaAfterBattle
	end

EternaCity_Gym_EventScript_JennaAfterBattle::
	msgbox EternaCity_Gym_Text_JennaPostBattle, MSGBOX_DEFAULT
	closemessage
	goto_if_ge VAR_ETERNA_GYM_STATE, 2, EternaCity_Gym_EventScript_EndTrainer
	setvar VAR_ETERNA_GYM_STATE, 2
	goto EternaCity_Gym_EventScript_SwapLayout
	end

EternaCity_Gym_EventScript_Angela::
	trainerbattle_single TRAINER_PT_ANGELA, EternaCity_Gym_Text_AngelaIntro, EternaCity_Gym_Text_AngelaDefeated, EternaCity_Gym_EventScript_AngelaAfterBattle
	end

EternaCity_Gym_EventScript_AngelaAfterBattle::
	msgbox EternaCity_Gym_Text_AngelaPostBattle, MSGBOX_DEFAULT
	closemessage
	goto_if_ge VAR_ETERNA_GYM_STATE, 3, EternaCity_Gym_EventScript_EndTrainer
	setvar VAR_ETERNA_GYM_STATE, 3
	goto EternaCity_Gym_EventScript_SwapLayout
	end

EternaCity_Gym_EventScript_EndTrainer::
	releaseall
	end
