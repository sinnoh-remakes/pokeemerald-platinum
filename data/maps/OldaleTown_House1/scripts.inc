OldaleTown_House1_MapScripts::
	.byte 0

OldaleTown_House1_EventScript_Aroma::
	msgbox OldaleTown_House1_Text_Aroma, MSGBOX_NPC
	end

OldaleTown_House1_EventScript_Boy::
	msgbox OldaleTown_House1_Text_Boy, MSGBOX_NPC

OldaleTown_House1_Text_Aroma:
	.string "A good Trainer is one that takes care\n"
	.string "not to let their Pokémon faint from\l"
	.string "losing HP.$"

OldaleTown_House1_Text_Boy:
	.string "Pokémon grow steadily stronger from\n"
	.string "battling against other Pokémon.\p"
	.string "At first, you should heal your\n"
	.string "Pokémon regularly at Poké Centers\l"
	.string "while you're leveling them up.$"
