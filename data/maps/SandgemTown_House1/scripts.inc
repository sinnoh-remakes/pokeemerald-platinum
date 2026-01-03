SandgemTown_House1_MapScripts::
	.byte 0

SandgemTown_House1_EventScript_Aroma::
	msgbox SandgemTown_House1_Text_Aroma, MSGBOX_NPC
	end

SandgemTown_House1_EventScript_Boy::
	msgbox SandgemTown_House1_Text_Boy, MSGBOX_NPC

SandgemTown_House1_Text_Aroma:
	.string "A good Trainer is one that takes care\n"
	.string "not to let their Pokémon faint from\l"
	.string "losing HP.$"

SandgemTown_House1_Text_Boy:
	.string "Pokémon grow steadily stronger from\n"
	.string "battling against other Pokémon.\p"
	.string "At first, you should heal your\n"
	.string "Pokémon regularly at Poké Centers\l"
	.string "while you're leveling them up.$"
