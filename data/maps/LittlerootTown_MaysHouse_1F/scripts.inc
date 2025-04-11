.set LOCALID_MOM, 1
.set LOCALID_RIVAL, 7

LittlerootTown_MaysHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LittlerootTown_MaysHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, LittlerootTown_MaysHouse_1F_OnFrame
	.byte 0

LittlerootTown_MaysHouse_1F_OnTransition:
	end

LittlerootTown_MaysHouse_1F_OnFrame:
	.2byte 0

LittlerootTown_MaysHouse_1F_EventScript_Mom::
	call_if_lt VAR_LITTLEROOT_INTRO_STATE, 4, LittlerootTown_MaysHouse_1F_EventScript_Mom_Talk1
	call_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, LittlerootTown_MaysHouse_1F_EventScript_Mom_Talk2
	end

LittlerootTown_MaysHouse_1F_EventScript_Mom_Talk1::
	msgbox LittlerootTown_MaysHouse_1F_MomMessage1, MSGBOX_NPC
	end

LittlerootTown_MaysHouse_1F_EventScript_Mom_Talk2::
	msgbox LittlerootTown_MaysHouse_1F_MomMessage2, MSGBOX_NPC
	end

LittlerootTown_MaysHouse_1F_MomMessage1:
	.string "{RIVAL}'s mom: Oh, hi,\n"
	.string "{PLAYER}.\p"
	.string "Are you looking for {RIVAL}?\p"
	.string "He was gone for a second, but then\n"
	.string "he came running right back home.\p"
	.string "He just can't sit still, that boy.\n"
	.string "I wonder who he takes after?$"

LittlerootTown_MaysHouse_1F_MomMessage2:
	.string "Hiya, {PLAYER}.\n"
	.string "You're looking for {RIVAL}?\p"
	.string "He just went tearing off a little\n"
	.string "while ago.\p"
	.string "He's probably not gone too far.\n"
	.string "Why not go chase after him?$"
	.string "I wonder who he takes after?$"
