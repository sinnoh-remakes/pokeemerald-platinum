Route203_MapScripts::
	.byte 0

Route203_EventScript_Michael::
	trainerbattle_single TRAINER_MICHAEL, Route203_Text_MichaelIntro, Route203_Text_MichaelDefeated
	msgbox Route203_Text_MichaelPostBattle, MSGBOX_AUTOCLOSE
	end

Route203_EventScript_Lass1::
	msgbox Route203_Text_FavoriteParty, MSGBOX_NPC
	end

Route203_EventScript_Dallas::
	end

Route203_EventScript_Kaitlin::
	end

Route203_EventScript_Madeline::
	end

Route203_EventScript_Sebastian::
	end

Route203_EventScript_RouteSignJubilife::
	end

Route203_EventScript_RouteSignOreburgh::
	end

Route203_EventScript_Sign1::
	end

Route203_EventScript_Sign2::
	end

Route203_Text_FavoriteParty:
	.string "Your favorite Pokémon should be placed\n"
	.string "at the top left of your party list.\p"
	.string "That way, it will be the first to go out\n"
	.string "in a battle.$"
