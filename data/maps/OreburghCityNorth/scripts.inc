OreburghCityNorth_MapScripts::
	.byte 0

@ State descriptions For VAR_OREBURGH_CITY_STATE
@ 1: Received HM Rock Smash

OreburghCityNorth_EventScript_Guitarist::
	msgbox OreburghCityNorth_Text_SeenTheVents, MSGBOX_NPC
	end

OreburghCityNorth_EventScript_Worker::
	msgbox OreburghCityNorth_Text_ExchangeHotAir, MSGBOX_NPC
	end

OreburghCityNorth_EventScript_SchoolKidF::
	msgbox OreburghCityNorth_Text_WentOff, MSGBOX_NPC
	end

OreburghCityNorth_EventScript_Camper::
	msgbox OreburghCityNorth_Text_RunAround, MSGBOX_NPC
	end

OreburghCityNorth_EventScript_BattleGirl1::
	msgbox OreburghCityNorth_Text_SingleUse, MSGBOX_NPC
	end

OreburghCityNorth_EventScript_BattleGirl2::
	msgbox OreburghCityNorth_Text_TimeCapsules, MSGBOX_NPC
	end

OreburghCityNorth_EventScript_Hiker::
	msgbox OreburghCityNorth_Text_HugeMountain, MSGBOX_NPC
	end

OreburghCityNorth_Text_SeenTheVents:
	.string "Have you seen the vents?\n"
	.string "They release steam from down below.$"

OreburghCityNorth_Text_ExchangeHotAir:
	.string "These vents exchange the hot air\n"
	.string "down below with the fresh air outside.\p"
	.string "Looking down them gives me the urge\n"
	.string "to start yelling into ’em! Hello!$"

OreburghCityNorth_Text_WentOff:
	.string "The Gym Leader went off to work in\n"
	.string "the mine.$"

OreburghCityNorth_Text_RunAround:
	.string "When I run around with my Running\n"
	.string "Shoes on, I’m the center of attention!\p"
	.string "...At least that’s what it feels like.\n"
	.string "There’s always someone looking at me.$"

OreburghCityNorth_Text_SingleUse:
	.string "TMs are single use only, but HMs\n"
	.string "can be used over and over.\p"
	.string "It’s tricky trying to decide which\n"
	.string "Pokémon should learn what moves.$"

OreburghCityNorth_Text_TimeCapsules:
	.string "Natural time capsules buried many,\n"
	.string "many years ago...\p"
	.string "That’s what Fossils are.$"

OreburghCityNorth_Text_HugeMountain:
	.string "Up ahead there’s a huge mountain\n"
	.string "that towers above everything.\p"
	.string "It divides Sinnoh into two distinct\n"
	.string "halves.$"
