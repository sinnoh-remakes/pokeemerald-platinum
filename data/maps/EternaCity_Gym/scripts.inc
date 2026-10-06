EternaCity_Gym_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EternaCity_Gym_OnTransition
	map_script MAP_SCRIPT_ON_WARP_INTO_MAP_TABLE, EternaCity_Gym_OnWarpIntoMap
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EternaCity_Gym_OnFrame
	.byte 0

@ State descriptions For VAR_ETERNA_GYM_STATE
@ 1: Defeated Caroline
@ 2: Defeated Jenna
@ 3: Defeated Angela
@ 4: Defeated Gardenia
@ 11-14: Same as 1-4 (state + 10), but the layout swap's camera pan back is still pending

EternaCity_Gym_OnTransition:
	switch VAR_ETERNA_GYM_STATE
	case 1, EternaCity_Gym_EventScript_SetLayout2
	case 11, EternaCity_Gym_EventScript_SetLayout2
	case 2, EternaCity_Gym_EventScript_SetLayout3
	case 12, EternaCity_Gym_EventScript_SetLayout3
	case 3, EternaCity_Gym_EventScript_SetLayout4
	case 13, EternaCity_Gym_EventScript_SetLayout4
	case 4, EternaCity_Gym_EventScript_SetLayout5
	case 14, EternaCity_Gym_EventScript_SetLayout5
	end

EternaCity_Gym_OnFrame:
	map_script_2 VAR_ETERNA_GYM_STATE, 11, EternaCity_Gym_EventScript_PanCameraBack
	map_script_2 VAR_ETERNA_GYM_STATE, 12, EternaCity_Gym_EventScript_PanCameraBack
	map_script_2 VAR_ETERNA_GYM_STATE, 13, EternaCity_Gym_EventScript_PanCameraBack
	map_script_2 VAR_ETERNA_GYM_STATE, 14, EternaCity_Gym_EventScript_PanCameraBack
	.2byte 0

EternaCity_Gym_OnWarpIntoMap:
	map_script_2 VAR_ETERNA_GYM_STATE, 11, EternaCity_Gym_EventScript_RestoreFacing
	map_script_2 VAR_ETERNA_GYM_STATE, 12, EternaCity_Gym_EventScript_RestoreFacing
	map_script_2 VAR_ETERNA_GYM_STATE, 13, EternaCity_Gym_EventScript_RestoreFacing
	map_script_2 VAR_ETERNA_GYM_STATE, 14, EternaCity_Gym_EventScript_RestoreFacing
	.2byte 0

@ The self-warp resets the player's and the fought NPC's facing direction. SwapLayout stashes them in
@ VAR_0x8004 (player) and VAR_0x8005 (NPC); VAR_LAST_TALKED still holds the NPC's local id.
@ The warp lands on the camera's end point (so the map fades in centered there), so this also moves
@ the player back to their real tile, stashed in VAR_0x8002/3. Runs after objects load but before the
@ fade in.
EternaCity_Gym_EventScript_RestoreFacing::
	setobjectxy LOCALID_PLAYER, VAR_0x8002, VAR_0x8003
	switch VAR_0x8004
	case DIR_SOUTH, EternaCity_Gym_EventScript_PlayerFaceSouth
	case DIR_NORTH, EternaCity_Gym_EventScript_PlayerFaceNorth
	case DIR_WEST, EternaCity_Gym_EventScript_PlayerFaceWest
	case DIR_EAST, EternaCity_Gym_EventScript_PlayerFaceEast
	end

EternaCity_Gym_EventScript_PlayerFaceSouth::
	turnobject LOCALID_PLAYER, DIR_SOUTH
	goto EternaCity_Gym_EventScript_RestoreNpcFacing

EternaCity_Gym_EventScript_PlayerFaceNorth::
	turnobject LOCALID_PLAYER, DIR_NORTH
	goto EternaCity_Gym_EventScript_RestoreNpcFacing

EternaCity_Gym_EventScript_PlayerFaceWest::
	turnobject LOCALID_PLAYER, DIR_WEST
	goto EternaCity_Gym_EventScript_RestoreNpcFacing

EternaCity_Gym_EventScript_PlayerFaceEast::
	turnobject LOCALID_PLAYER, DIR_EAST
	goto EternaCity_Gym_EventScript_RestoreNpcFacing

EternaCity_Gym_EventScript_RestoreNpcFacing::
	switch VAR_0x8005
	case DIR_SOUTH, EternaCity_Gym_EventScript_NpcFaceSouth
	case DIR_NORTH, EternaCity_Gym_EventScript_NpcFaceNorth
	case DIR_WEST, EternaCity_Gym_EventScript_NpcFaceWest
	case DIR_EAST, EternaCity_Gym_EventScript_NpcFaceEast
	end

EternaCity_Gym_EventScript_NpcFaceSouth::
	turnobject VAR_LAST_TALKED, DIR_SOUTH
	end

EternaCity_Gym_EventScript_NpcFaceNorth::
	turnobject VAR_LAST_TALKED, DIR_NORTH
	end

EternaCity_Gym_EventScript_NpcFaceWest::
	turnobject VAR_LAST_TALKED, DIR_WEST
	end

EternaCity_Gym_EventScript_NpcFaceEast::
	turnobject VAR_LAST_TALKED, DIR_EAST
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

EternaCity_Gym_EventScript_SetLayout5::
	setmaplayoutindex LAYOUT_ETERNA_CITY_GYM_5
	end

@ Shared by all three trainers. A trainer can be fought from 4 sides and the player/NPC always face
@ each other, so the side determines the facings to restore after the warp, and (together with
@ VAR_ETERNA_GYM_STATE, which identifies the trainer) the camera path to the room center.
EternaCity_Gym_EventScript_SwapLayout::
	getplayerxy VAR_0x8002, VAR_0x8003
	special SpawnCameraObject
	specialvar VAR_RESULT, GetPlayerFacingDirection
	switch VAR_RESULT
	case DIR_SOUTH, EternaCity_Gym_EventScript_SwapLayoutFromTop
	case DIR_EAST, EternaCity_Gym_EventScript_SwapLayoutFromLeft
	case DIR_WEST, EternaCity_Gym_EventScript_SwapLayoutFromRight
	case DIR_NORTH, EternaCity_Gym_EventScript_SwapLayoutFromBottom
	end

EternaCity_Gym_EventScript_SwapLayoutFromTop::
	setvar VAR_0x8004, DIR_SOUTH
	setvar VAR_0x8005, DIR_NORTH
	switch VAR_ETERNA_GYM_STATE
	case 1, EternaCity_Gym_EventScript_CarolineFromTop
	case 2, EternaCity_Gym_EventScript_JennaFromTop
	case 3, EternaCity_Gym_EventScript_AngelaFromTop
	case 4, EternaCity_Gym_EventScript_GardeniaFromTop
	end

EternaCity_Gym_EventScript_SwapLayoutFromLeft::
	setvar VAR_0x8004, DIR_EAST
	setvar VAR_0x8005, DIR_WEST
	switch VAR_ETERNA_GYM_STATE
	case 1, EternaCity_Gym_EventScript_CarolineFromLeft
	case 2, EternaCity_Gym_EventScript_JennaFromLeft
	case 3, EternaCity_Gym_EventScript_AngelaFromLeft
	case 4, EternaCity_Gym_EventScript_GardeniaFromLeft
	end

EternaCity_Gym_EventScript_SwapLayoutFromRight::
	setvar VAR_0x8004, DIR_WEST
	setvar VAR_0x8005, DIR_EAST
	switch VAR_ETERNA_GYM_STATE
	case 1, EternaCity_Gym_EventScript_CarolineFromRight
	case 2, EternaCity_Gym_EventScript_JennaFromRight
	case 3, EternaCity_Gym_EventScript_AngelaFromRight
	case 4, EternaCity_Gym_EventScript_GardeniaFromRight
	end

EternaCity_Gym_EventScript_SwapLayoutFromBottom::
	setvar VAR_0x8004, DIR_NORTH
	setvar VAR_0x8005, DIR_SOUTH
	switch VAR_ETERNA_GYM_STATE
	case 1, EternaCity_Gym_EventScript_CarolineFromBottom
	case 2, EternaCity_Gym_EventScript_JennaFromBottom
	case 3, EternaCity_Gym_EventScript_AngelaFromBottom
	case 4, EternaCity_Gym_EventScript_GardeniaFromBottom
	end

@ Self-warps so ON_TRANSITION swaps the layout, then pans back in PanCameraBack
@ (the warp resets the script context). Expects VAR_0x8004/5 = player/NPC facing and
@ VAR_0x8002/3 = the player's tile and VAR_0x8006/7 = the camera's end point, which is where the
@ warp lands. (getplayerxy reads the map position, which follows the camera, so both are read at the
@ right moments: the player's before the pan and the camera's after it.)
EternaCity_Gym_EventScript_WarpSwapLayout::
	delay 30
	addvar VAR_ETERNA_GYM_STATE, 10
	warp MAP_ETERNA_CITY_GYM, VAR_0x8006, VAR_0x8007
	waitstate
	end

@ Runs after the fade in. The map faded in centered on the pan's end point, so respawn the camera
@ there (SpawnCameraObject uses the current map position) and pan it back to the player.
@ VAR_0x8004 (the player's facing) gives the side and VAR_ETERNA_GYM_STATE (11 to 13) the trainer.
EternaCity_Gym_EventScript_PanCameraBack::
	lockall
	special SpawnCameraObject
	switch VAR_0x8004
	case DIR_SOUTH, EternaCity_Gym_EventScript_PanCameraBackFromTop
	case DIR_EAST, EternaCity_Gym_EventScript_PanCameraBackFromLeft
	case DIR_WEST, EternaCity_Gym_EventScript_PanCameraBackFromRight
	case DIR_NORTH, EternaCity_Gym_EventScript_PanCameraBackFromBottom
	end

EternaCity_Gym_EventScript_PanCameraBackFromTop::
	switch VAR_ETERNA_GYM_STATE
	case 11, EternaCity_Gym_EventScript_CarolineBackFromTop
	case 12, EternaCity_Gym_EventScript_JennaBackFromTop
	case 13, EternaCity_Gym_EventScript_AngelaBackFromTop
	case 14, EternaCity_Gym_EventScript_GardeniaBackFromTop
	end

EternaCity_Gym_EventScript_PanCameraBackFromLeft::
	switch VAR_ETERNA_GYM_STATE
	case 11, EternaCity_Gym_EventScript_CarolineBackFromLeft
	case 12, EternaCity_Gym_EventScript_JennaBackFromLeft
	case 13, EternaCity_Gym_EventScript_AngelaBackFromLeft
	case 14, EternaCity_Gym_EventScript_GardeniaBackFromLeft
	end

EternaCity_Gym_EventScript_PanCameraBackFromRight::
	switch VAR_ETERNA_GYM_STATE
	case 11, EternaCity_Gym_EventScript_CarolineBackFromRight
	case 12, EternaCity_Gym_EventScript_JennaBackFromRight
	case 13, EternaCity_Gym_EventScript_AngelaBackFromRight
	case 14, EternaCity_Gym_EventScript_GardeniaBackFromRight
	end

EternaCity_Gym_EventScript_PanCameraBackFromBottom::
	switch VAR_ETERNA_GYM_STATE
	case 11, EternaCity_Gym_EventScript_CarolineBackFromBottom
	case 12, EternaCity_Gym_EventScript_JennaBackFromBottom
	case 13, EternaCity_Gym_EventScript_AngelaBackFromBottom
	case 14, EternaCity_Gym_EventScript_GardeniaBackFromBottom
	end

EternaCity_Gym_EventScript_PanCameraBackDone::
	special RemoveCameraObject
	subvar VAR_ETERNA_GYM_STATE, 10
	releaseall
	end

@ Defines the camera pan for one trainer approached from one side, given the camera's offset (dx, dy)
@ in tiles from the player to the room center: the movement there, the script that plays it and
@ then warps (saving the camera's end point, VAR_0x8006/7, for the warp), and the exact opposite movement
@ and script for panning back after the warp. By default the pan goes horizontal then vertical;
@ with vfirst=1 it goes vertical then horizontal (and back horizontal then vertical).
	.macro eterna_gym_pan_horizontal dx:req
	.if \dx < 0
	.rept (-(\dx))
	walk_left
	.endr
	.else
	.rept \dx
	walk_right
	.endr
	.endif
	.endm

	.macro eterna_gym_pan_vertical dy:req
	.if \dy < 0
	.rept (-(\dy))
	walk_up
	.endr
	.else
	.rept \dy
	walk_down
	.endr
	.endif
	.endm

	.macro eterna_gym_pan trainer:req, side:req, dx:req, dy:req, vfirst=0
	.global EternaCity_Gym_EventScript_\trainer\()From\side\()
EternaCity_Gym_EventScript_\trainer\()From\side\():
	applymovement LOCALID_CAMERA, EternaCity_Gym_Movement_\trainer\()From\side\()
	waitmovement 0
	getplayerxy VAR_0x8006, VAR_0x8007
	goto EternaCity_Gym_EventScript_WarpSwapLayout

	.global EternaCity_Gym_EventScript_\trainer\()BackFrom\side\()
EternaCity_Gym_EventScript_\trainer\()BackFrom\side\():
	applymovement LOCALID_CAMERA, EternaCity_Gym_Movement_\trainer\()BackFrom\side\()
	waitmovement 0
	goto EternaCity_Gym_EventScript_PanCameraBackDone

EternaCity_Gym_Movement_\trainer\()From\side\():
	.if \vfirst
	eterna_gym_pan_vertical \dy
	eterna_gym_pan_horizontal \dx
	.else
	eterna_gym_pan_horizontal \dx
	eterna_gym_pan_vertical \dy
	.endif
	step_end

EternaCity_Gym_Movement_\trainer\()BackFrom\side\():
	.if \vfirst
	eterna_gym_pan_horizontal (-(\dx))
	eterna_gym_pan_vertical (-(\dy))
	.else
	eterna_gym_pan_vertical (-(\dy))
	eterna_gym_pan_horizontal (-(\dx))
	.endif
	step_end

	.endm

@ Caroline: camera moves left then up.
	eterna_gym_pan Caroline, Top, -3, -8
	eterna_gym_pan Caroline, Left, -2, -9
	eterna_gym_pan Caroline, Right, -4, -9
	eterna_gym_pan Caroline, Bottom, -3, -10

@ Jenna: same as Caroline with the left/up counts swapped, moving up before left.
	eterna_gym_pan Jenna, Top, -9, -3, vfirst=1
	eterna_gym_pan Jenna, Left, -8, -4, vfirst=1
	eterna_gym_pan Jenna, Right, -10, -4, vfirst=1
	eterna_gym_pan Jenna, Bottom, -9, -5, vfirst=1

@ Angela: camera moves down then right.
	eterna_gym_pan Angela, Top, 9, 6, vfirst=1
	eterna_gym_pan Angela, Left, 10, 5, vfirst=1
	eterna_gym_pan Angela, Right, 8, 5, vfirst=1
	eterna_gym_pan Angela, Bottom, 9, 4, vfirst=1

@ Gardenia: camera moves right/left then down.
	eterna_gym_pan Gardenia, Top, 0, 10
	eterna_gym_pan Gardenia, Left, 1, 9
	eterna_gym_pan Gardenia, Right, -1, 9
	eterna_gym_pan Gardenia, Bottom, 0, 8

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

EternaCity_Gym_EventScript_Gardenia::
	trainerbattle_single TRAINER_PT_GARDENIA, EternaCity_Gym_Text_GardeniaIntro, EternaCity_Gym_Text_GardeniaDefeated, EternaCity_Gym_EventScript_GardeniaDefeated, NO_MUSIC
	msgbox EternaCity_Gym_Text_GardeniaPostBattle, MSGBOX_DEFAULT
	release
	end

EternaCity_Gym_EventScript_GardeniaDefeated::
	msgbox EternaCity_Gym_Text_ImpressedByYourPokemon, MSGBOX_DEFAULT
	message EternaCity_Gym_Text_ReceivedForestBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfarePt
	msgbox EternaCity_Gym_Text_HavingThatForestBadge, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_ETERNA_GYM
	setflag FLAG_BADGE02_GET
	setvar VAR_0x8008, 10
	call Common_EventScript_SetGymTrainers
	goto EternaCity_Gym_EventScript_GiveGrassKnot
	end

EternaCity_Gym_EventScript_GiveGrassKnot::
	giveitem ITEM_TM86
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	msgbox EternaCity_Gym_Text_TheMoveGrassKnot, MSGBOX_DEFAULT
	closemessage
	setvar VAR_ETERNA_GYM_STATE, 4
	goto EternaCity_Gym_EventScript_SwapLayout
	end

EternaCity_Gym_Text_ImpressedByYourPokemon:
	.string "I might’ve said it before, but you’re\n"
	.string "really tough!\p"
	.string "Wasn’t it hard for you to raise your\n"
	.string "Pokémon to be so good?\p"
	.string "I guess that’s a measure of how much\n"
	.string "you love your Pokémon.\p"
	.string "In recognition of that, I proudly\n"
	.string "grant you this!$"

EternaCity_Gym_Text_ReceivedForestBadge:
	.string "{PLAYER} received\n"
	.string "the Forest Badge from Gardenia!$"

EternaCity_Gym_Text_HavingThatForestBadge:
	.string "With the Forest Badge, your Pokémon\n"
	.string "can use the hidden move Cut outside\l"
	.string "of battle.\p"
	.string "Now that you have two Gym Badges,\n"
	.string "all Pokémon you received in trades\l"
	.string "will obey you up to Lv. 30.\p"
	.string "I’ve also got something else.\n"
	.string "It’s a gift from me!$"

EternaCity_Gym_Text_TheMoveGrassKnot:
	.string "That TM86 contains\n"
	.string "the move Grass Knot.\p"
	.string "It’s one of my favorite moves.\p"
	.string "The heavier the foe, the more\n"
	.string "damage this move will cause.$"

EternaCity_Gym_EventScript_GymGuide::
	msgbox EternaCity_Gym_Text_GymGuideAdvice, MSGBOX_NPC
	end

EternaCity_Gym_Text_GymGuideAdvice:
	.string "Hey, there!\n"
	.string "How’s it going, Champ-to-be?\p"
	.string "Actually, that’s what I said to some\n"
	.string "boy who zipped in here earlier, too!\p"
	.string "The Gym Leader, Gardenia, is a user\n"
	.string "of Grass-type Pokémon.\p"
	.string "It should be obvious, but Grass-type\n"
	.string "Pokémon really hate fire.\p"
	.string "They’re also at a huge disadvantage\n"
	.string "against the Flying type, too.\p"
	.string "Oh, wait a second. I should tell you\n"
	.string "about the Gym itself first.\p"
	.string "You can’t challenge the Gym Leader\n"
	.string "until you beat all the Gym’s Trainers.\p"
	.string "It’s a bit challenging, but just think\n"
	.string "of it as good training and go for it!$"

EternaCity_Gym_EventScript_GymStatue::
	lockall
	goto_if_set FLAG_BADGE02_GET, EternaCity_Gym_EventScript_GymStatueCertified
	goto EternaCity_Gym_EventScript_GymStatueDefault
	end

EternaCity_Gym_EventScript_GymStatueCertified::
	msgbox EternaCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

EternaCity_Gym_EventScript_GymStatueDefault::
	msgbox EternaCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

EternaCity_Gym_Text_GymStatue:
	.string "Eterna City Pokémon Gym\n"
	.string "Leader: Gardenia\p"
	.string "Certified Trainers:\n"
	.string "{RIVAL}$"

EternaCity_Gym_Text_GymStatueCertified:
	.string "Eterna City Pokémon Gym\n"
	.string "Leader: Gardenia\p"
	.string "Certified Trainers:\n"
	.string "{RIVAL}\l"
	.string "{PLAYER}$"
