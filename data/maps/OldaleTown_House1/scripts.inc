OldaleTown_House1_MapScripts::
	.byte 0

OldaleTown_House1_EventScript_Aroma::
	msgbox OldaleTown_House1_Text_Aroma, MSGBOX_NPC
	end

OldaleTown_House1_EventScript_Boy::
	msgbox OldaleTown_House1_Text_Boy, MSGBOX_NPC

OldaleTown_House1_Text_Aroma:
	.string "A good Trainer is one that takes care\n"
	.string "not to let their Pokemon faint from\l"
	.string "losing HP.$"

OldaleTown_House1_Text_Boy:
	.string "Pokemon grow steadily stronger from\n"
	.string "battling against other Pokemon.\p"
	.string "At first, you should heal your\n"
	.string "Pokemon regularly at Poke Centers\l"
	.string "while you're leveling them up.$"
