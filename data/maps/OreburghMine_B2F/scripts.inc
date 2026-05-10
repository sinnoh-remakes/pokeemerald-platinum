OreburghMine_B2F_MapScripts::
	.byte 0

OreburghMine_B2F_EventScript_Roark::
	lock
	applymovement LOCALID_OREBURGH_MINE_ROARK, Common_Movement_FaceDown
	waitmovement 0
	delay 16
	applymovement LOCALID_OREBURGH_MINE_ROARK, Common_Movement_WalkInPlaceRight
	waitmovement 0
	delay 48
	msgbox OreburghMine_B2F_Text_StandBack, MSGBOX_DEFAULT
	closemessage
	removeobject LOCALID_OREBURGH_MINE_ROCK
	delay 48
	applymovement LOCALID_OREBURGH_MINE_ROARK, Common_Movement_FaceDown
	waitmovement 0
	msgbox OreburghMine_B2F_Text_FallenBoulders, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_OREBURGH_MINE_ROARK, Common_Movement_WalkRight7
	waitmovement 0
	setvar VAR_OREBURGH_CITY_STATE, 4
	setflag FLAG_HIDE_OREBURGH_CITY_RIVAL
	removeobject LOCALID_OREBURGH_MINE_ROARK
	release
	end

OreburghMine_EventScript_Mason::
	trainerbattle_single TRAINER_PT_MASON, OreburghMine_Text_MasonIntro, OreburghMine_Text_MasonDefeat
	msgbox OreburghMine_Text_MasonPostBattle, MSGBOX_AUTOCLOSE
	end

OreburghMine_EventScript_Colin::
	trainerbattle_single TRAINER_PT_COLIN, OreburghMine_Text_ColinIntro, OreburghMine_Text_ColinDefeat
	msgbox OreburghMine_Text_ColinPostBattle, MSGBOX_AUTOCLOSE
	end

OreburghMine_B2F_EventScript_Machop1::
	msgbox OreburghMine_B2F_Text_Machop1, MSGBOX_NPC
	end

OreburghMine_B2F_EventScript_Machop2::
	msgbox OreburghMine_B2F_Text_Machop2, MSGBOX_NPC
	end

OreburghMine_B2F_EventScript_Machop3::
	msgbox OreburghMine_B2F_Text_Machop3, MSGBOX_NPC
	end

OreburghMine_B2F_EventScript_Worker::
	msgbox OreburghMine_B2F_Text_MetTheseMachop, MSGBOX_NPC
	end

OreburghMine_B2F_Text_StandBack:
	.string "OK, stand back and watch this.\p"
	.string "Using the hidden move Rock Smash,\n"
	.string "a boulder blocking your way...$"

OreburghMine_B2F_Text_FallenBoulders:
	.string "Fallen boulders need to be smashed\n"
	.string "so they’re out of the way.\p"
	.string "If you could get the Badge from\n"
	.string "the Gym in town, you’d be able\l"
	.string "to do this too.\p"
	.string "Of course, you’d have to beat the\n"
	.string "Gym Leader first. That’d be me!$\p"

OreburghMine_B2F_Text_Machop1:
	.string "MACHOP: Chopmacho!$"

OreburghMine_B2F_Text_Machop2:
	.string "MACHOP: Chopchop!$"

OreburghMine_B2F_Text_Machop3:
	.string "MACHOP: Maaacho!$"

OreburghMine_B2F_Text_MetTheseMachop:
	.string "I met these MACHOP on Route 207.\p"
	.string "They’ve now become my most trusted\n"
	.string "partners!$"
