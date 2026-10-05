EternaCity_Gym_MapScripts::
	.byte 0

@ lock
@ special SpawnCameraObject
@ applymovement LOCALID_CAMERA, EternaCityGym_Movement_PanToRoomCenter
@ waitmovement 0
@ delay 30                                          @ optional beat before the cut
@ warp MAP_ETERNA_CITY_GYM, VAR_0x8000, VAR_0x8001  @ self-warp, same coords -> re-fires ON_TRANSITION, swaps layout
@ waitstate                                          @ blocks through the warp's own fade-out/reload/fade-in
@ special RemoveCameraObject                         @ camera snaps back onto player (position untouched throughout)
@ release

EternaCity_Gym_EventScript_Caroline::
	trainerbattle_single TRAINER_PT_CAROLINE, EternaCity_Gym_Text_CarolineIntro, EternaCity_Gym_Text_CarolineDefeated
	msgbox EternaCity_Gym_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

EternaCity_Gym_EventScript_Jenna::
	trainerbattle_single TRAINER_PT_JENNA, EternaCity_Gym_Text_JennaIntro, EternaCity_Gym_Text_JennaDefeated
	msgbox EternaCity_Gym_Text_JennaPostBattle, MSGBOX_AUTOCLOSE
	end

EternaCity_Gym_EventScript_Angela::
	trainerbattle_single TRAINER_PT_ANGELA, EternaCity_Gym_Text_AngelaIntro, EternaCity_Gym_Text_AngelaDefeated
	msgbox EternaCity_Gym_Text_AngelaPostBattle, MSGBOX_AUTOCLOSE
	end
