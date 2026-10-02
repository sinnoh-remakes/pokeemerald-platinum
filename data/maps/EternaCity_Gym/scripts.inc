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
