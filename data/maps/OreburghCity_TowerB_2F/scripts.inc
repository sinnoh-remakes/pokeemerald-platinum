OreburghCity_TowerB_2F_MapScripts::
	.byte 0

OreburghCity_TowerB_2F_EventScript_Guitarist::
	msgbox OreburghCity_TowerB_2F_Text_SpecialPower, MSGBOX_NPC
	end
	
OreburghCity_TowerB_2F_EventScript_AromaLady::
	msgbox OreburghCity_TowerB_2F_Text_FavoritePokemon, MSGBOX_NPC
	end
	
OreburghCity_TowerB_2F_EventScript_Collector::
	@ FODO: Add Geodude party detection and event
	msgbox OreburghCity_TowerB_2F_TheViewIsGood, MSGBOX_NPC
	end

OreburghCity_TowerB_2F_Text_SpecialPower:
	.string "All Pokémon have a special power\n"
	.string "called an ability.$"

OreburghCity_TowerB_2F_Text_FavoritePokemon:
	.string "My favorite Pokémon ability is my\n"
	.string "PACHIRISU's  Pickup.\p"
	.string "My darling picks up a lot of dropped\n"
	.string "items without me noticing!$"

OreburghCity_TowerB_2F_TheViewIsGood:
	.string "The view is good from the second floor,\n"
	.string "but it's a pain going outside.\p"
	.string "If you don't mind, how about showing me\n"
	.string "a Pokémon called GEODUDE?$"
