JubilifeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, JubilifeCity_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, JubilifeCity_OnFrame
	.byte 0

JubilifeCity_OnTransition:
	setflag FLAG_VISITED_Jubilife_CITY
	@ setvar VAR_CONTEST_HALL_STATE, 0
	end

JubilifeCity_OnFrame:
	.2byte 0
