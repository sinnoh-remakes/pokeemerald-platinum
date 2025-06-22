TwinleafTown_RivalsHouse_1F_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TwinleafTown_RivalsHouse_1F_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, TwinleafTown_RivalsHouse_1F_OnFrame
	.byte 0

TwinleafTown_RivalsHouse_1F_OnTransition:
	end

TwinleafTown_RivalsHouse_1F_OnFrame:
	.2byte 0

TwinleafTown_RivalsHouse_1F_EventScript_Mom::

	goto_if_eq VAR_TWINLEAF_INTRO_STATE, 4, TwinleafTown_RivalsHouse_1F_EventScript_RunningBack
	goto_if_eq VAR_TWINLEAF_INTRO_STATE, 5, TwinleafTown_RivalsHouse_1F_EventScript_MomAlternate
	@ goto_if_eq VAR_TWINLEAF_TOWN_STATE, 5, TwinleafTown_RivalsHouse_1F_EventScript_BecomeFriends
	goto TwinleafTown_RivalsHouse_1F_EventScript_BecomeFriends
	end

TwinleafTown_RivalsHouse_1F_EventScript_RunningBack::
	msgbox TwinleafTown_RivalsHouse_1F_RunningBack, MSGBOX_NPC
	end

TwinleafTown_RivalsHouse_1F_EventScript_MomAlternate::
	goto_if_lt VAR_ALTERNATE_TEXT, 2, TwinleafTown_RivalsHouse_1F_EventScript_RocketedOff
	msgbox TwinleafTown_RivalsHouse_1F_TakesAfter, MSGBOX_NPC
	end

TwinleafTown_RivalsHouse_1F_EventScript_RocketedOff::
	setvar VAR_ALTERNATE_TEXT, 2
	msgbox TwinleafTown_RivalsHouse_1F_RocketedOff, MSGBOX_NPC
	end

TwinleafTown_RivalsHouse_1F_EventScript_BecomeFriends::
	msgbox TwinleafTown_RivalsHouse_1F_BecomeFriends, MSGBOX_NPC
	end

TwinleafTown_RivalsHouse_1F_RunningBack:
	.string "{RIVAL}'s mom: Oh, hi,\n"
	.string "{PLAYER}.\p"
	.string "Are you looking for {RIVAL}?\p"
	.string "He was gone for a second, but then\n"
	.string "he came running right back home.\p"
	.string "He just can't sit still, that boy.\n"
	.string "I wonder who he takes after?$"

TwinleafTown_RivalsHouse_1F_RocketedOff:
	.string "{RIVAL}'s mom: That kid rocketed\n"
	.string "off again like usual.\p"
	.string "I'd guess he would be out on\n"
	.string "Route 201 by now?\p"
	.string "He just can't sit still, that boy.\n"
	.string "I wonder who he takes after?$"

TwinleafTown_RivalsHouse_1F_TakesAfter:
	.string "{RIVAL}'s mom: My {RIVAL}\n"
	.string "should be out on Route 201 by now.\p"
	.string "He just can't sit still, that boy.\n"
	.string "I wonder who he takes after?$"

TwinleafTown_RivalsHouse_1F_BecomeFriends:
	.string "{RIVAL}'s mom: Oh, you've\n"
	.string "become friends with a Pokémon, too.$"
