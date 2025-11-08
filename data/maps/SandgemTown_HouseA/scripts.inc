SandgemTown_HouseA_MapScripts::
	.byte 0

SandgemTown_HouseA_EventScript_Aroma::
	msgbox SandgemTown_HouseA_Text_Aroma, MSGBOX_NPC
	end

SandgemTown_HouseA_EventScript_Boy::
	msgbox SandgemTown_HouseA_Text_Boy, MSGBOX_NPC

SandgemTown_HouseA_Text_Aroma:
	.string "A good Trainer is one that takes care\n"
	.string "not to let their Pokémon faint from\l"
	.string "losing HP.$"

SandgemTown_HouseA_Text_Boy:
	.string "Pokémon grow steadily stronger from\n"
	.string "battling against other Pokémon.\p"
	.string "At first, you should heal your\n"
	.string "Pokémon regularly at Poké Centers\l"
	.string "while you're leveling them up.$"
