OreburghCity_HouseB_MapScripts::
	.byte 0

OreburghCity_HouseB_EventScript_Hiker::
	msgbox OreburghCity_HouseB_Text_HeMayBeYoung, MSGBOX_NPC
	end

OreburghCity_HouseB_EventScript_SchoolKidF::
	msgbox OreburghCity_HouseB_Text_UserOfRockType, MSGBOX_NPC
	end

OreburghCity_HouseB_Text_HeMayBeYoung:
	.string "Roark is our town’s Gym Leader.\p"
	.string "He may be young, but he keeps the\n"
	.string "mine running safely and efficiently.$"

OreburghCity_HouseB_Text_UserOfRockType:
	.string "Roark is a user of Rock-type Pokémon.\p"
	.string "Don’t you think Rock-type Pokémon are\n"
	.string "nice? I like how lumpy they are!$"
