EternaCitySouth_MapScripts::
	.byte 0

EternaCitySouth_EventScript_BikeShopSign::
	msgbox EternaCitySouth_Text_BikeShopSign, MSGBOX_SIGN
	end

EternaCitySouth_EventScript_CondominiumSign::
	msgbox EternaCitySouth_Text_CondominiumSign, MSGBOX_SIGN
	end

EternaCitySouth_EventScript_GymSign::
	msgbox EternaCitySouth_Text_GymSign, MSGBOX_SIGN
	end

EternaCitySouth_Text_BikeShopSign:
	.string "Rad Rickshaw’s Cycle Shop\n"
	.string "Get On and Ride!$"

EternaCitySouth_Text_CondominiumSign:
	.string "Eterna Condominiums\n"
	.string "Name-Rating Services Available$"

EternaCitySouth_TextGymSign:
	.string "Eterna City Pokémon Gym\n"
	.string "Leader: Gardenia\l"
	.string "Master of Vivid Plant Pokémon!$"
