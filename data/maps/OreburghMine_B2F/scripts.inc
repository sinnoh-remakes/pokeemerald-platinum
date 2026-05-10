OreburghMine_B2F_MapScripts::
	.byte 0

OreburghMine_B2F_EventScript_Roark::


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
