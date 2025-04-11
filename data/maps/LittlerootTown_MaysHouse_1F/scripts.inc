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

	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 3, LittlerootTown_MaysHouse_1F_EventScript_Mom_Talk1
	goto_if_eq VAR_LITTLEROOT_INTRO_STATE, 4, LittlerootTown_MaysHouse_1F_EventScript_Mom_TalkDiff
	@ goto_if_eq VAR_LITTLEROOT_TOWN_STATE, 2, LittlerootTown_MaysHouse_1F_EventScript_Mom_Talk4
	goto LittlerootTown_MaysHouse_1F_EventScript_Mom_Talk4
	end

LittlerootTown_MaysHouse_1F_EventScript_Mom_Talk1::
	msgbox LittlerootTown_MaysHouse_1F_MomMessage1, MSGBOX_NPC
	end

LittlerootTown_MaysHouse_1F_EventScript_Mom_TalkDiff::
	goto_if_lt VAR_ALTERNATE_TEXT, 2, LittlerootTown_MaysHouse_1F_EventScript_Mom_Talk2
	goto LittlerootTown_MaysHouse_1F_EventScript_Mom_Talk3
	end

LittlerootTown_MaysHouse_1F_EventScript_Mom_Talk2::
	setvar VAR_ALTERNATE_TEXT, 2
	msgbox LittlerootTown_MaysHouse_1F_MomMessage2, MSGBOX_NPC
	end

LittlerootTown_MaysHouse_1F_EventScript_Mom_Talk3::
	msgbox LittlerootTown_MaysHouse_1F_MomMessage3, MSGBOX_NPC
	end

LittlerootTown_MaysHouse_1F_EventScript_Mom_Talk4::
	msgbox LittlerootTown_MaysHouse_1F_MomMessage4, MSGBOX_NPC
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
	.string "{RIVAL}'s mom: That kid rocketed\n"
	.string "off again like usual.\p"
	.string "I'd guess he would be out on\n"
	.string "Route 201 by now?\p"
	.string "He just can't sit still, that boy.\n"
	.string "I wonder who he takes after?$"

LittlerootTown_MaysHouse_1F_MomMessage3:
	.string "{RIVAL}'s mom: {RIVAL}\n"
	.string "should be out on Route 201 by now.\p"
	.string "He just can't sit still, that boy.\n"
	.string "I wonder who he takes after?$"

LittlerootTown_MaysHouse_1F_MomMessage4:
	.string "{RIVAL}'s mom: Oh, you've\n"
	.string "become friends with a Pokemon, too$"
