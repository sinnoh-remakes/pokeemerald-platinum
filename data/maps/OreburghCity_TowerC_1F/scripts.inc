OreburghCity_TowerC_1F_MapScripts::
	.byte 0

OreburghCity_TowerC_1F_EventScript_AceTrainerM::
	msgbox OreburghCity_TowerC_1F_Text_YouRemindMe, MSGBOX_NPC
	end

OreburghCity_TowerC_1F_EventScript_Hiker::
	msgbox OreburghCity_TowerC_1F_Text_RottenTime, MSGBOX_NPC
	end

OreburghCity_TowerC_1F_EventScript_PokefanM::
	msgbox OreburghCity_TowerC_1F_Text_TougheningUp, MSGBOX_NPC
	end

OreburghCity_TowerC_1F_Text_YouRemindMe:
	.string "You remind me so much of the time\n"
	.string "I got my first Pokémon.$"

OreburghCity_TowerC_1F_Text_RottenTime:
	.string "I always have a rotten time trying\n"
	.string "to decide which moves my Pokémon\l"
	.string "should learn.$"

OreburghCity_TowerC_1F_Text_TougheningUp:
	.string "Hiya! Your Pokémon could use some\n"
	.string "toughening up.\p"
	.string "Why not try training in\n"
	.string "the Oreburgh Mine?$"
