OreburghMine_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, OreburghMine_B1F_OnResume
	.byte 0

OreburghMine_B1F_OnResume:
	setescapewarp MAP_OREBURGH_CITY_SOUTH, 39, 32
	end

OreburghMine_B1F_EventScript_Worker::
	msgbox OreburghMine_B1F_Text_EveryoneThatWorks, MSGBOX_NPC
	end

OreburghMine_B1F_EventScript_Twin::
	msgbox OreburghMine_B1F_Text_ThoughtWereRocks, MSGBOX_NPC
	end

OreburghMine_B1F_Text_EveryoneThatWorks:
	.string "Everyone that works in the coal mine\n"
	.string "keeps their own Pokémon with them.\p"
	.string "You may be challenged to battles!\n"
	.string "Hahaha!$"

OreburghMine_B1F_Text_ThoughtWereRocks:
	.string "I found what I thought were some\n"
	.string "rocks, then they started moving!\p"
	.string "They were Pokémon that looked just\n"
	.string "like rocks!$"
