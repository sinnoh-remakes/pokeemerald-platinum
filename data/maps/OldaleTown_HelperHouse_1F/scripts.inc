OldaleTown_HelperHouse_1F_MapScripts::
	.byte 0

OldaleTown_HelperHouse_1F_EventScript_Girl::
	msgbox OldaleTown_HelperHouse_1F_Text_Girl, MSGBOX_NPC
	end

OldaleTown_HelperHouse_1F_EventScript_Man::
	msgbox OldaleTown_HelperHouse_1F_Text_Man, MSGBOX_NPC
	end

OldaleTown_HelperHouse_1F_Text_Girl:
	.string "Who are you?\p"
	.string "...\p"
	.string "Oh...\n"
	.string "You're {PLAYER}?\p"
	.string "You're doing that Pokédex thingy\n"
	.string "for the professor!\p"
	.string "Wow! That's the same as my big\n"
	.string "brother! Go for it!$"

OldaleTown_HelperHouse_1F_Text_Man:
	.string "Ah, so that Rowan fellow is back?\n"
	.string "He's quite the remarkable man.\p"
	.string "He's been studying Pokémon since way,\n"
	.string "way back.\p"
	.string "My son and grandchild help Rowan\n"
	.string "with his studies now.$"
