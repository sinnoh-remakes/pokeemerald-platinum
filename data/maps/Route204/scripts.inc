Route204_MapScripts::
	.byte 0

Route204_EventScript_Sarah::
	trainerbattle_single TRAINER_PT_SARAH, Route204_Text_SarahIntro, Route204_Text_SarahDefeated
	msgbox Route204_Text_SarahPostBattle, MSGBOX_AUTOCLOSE
	end

Route204_EventScript_Tyler::
	trainerbattle_single TRAINER_PT_TYLER, Route204_Text_TylerIntro, Route204_Text_TylerDefeated
	msgbox Route204_Text_TylerPostBattle, MSGBOX_AUTOCLOSE
	end

Route204_EventScript_Samantha::
	trainerbattle_single TRAINER_PT_SAMANTHA_1, Route204_Text_SamanthaIntro, Route204_Text_SamanthaDefeated
	msgbox Route204_Text_SamanthaPostBattle, MSGBOX_AUTOCLOSE
	end

Route204_EventScript_Youngster::
	msgbox Route204_Text_BouldersBlocking, MSGBOX_NPC
	end

Route204_EventScript_RouteSignJubilife::
	msgbox Route204_Text_RouteSignJubilife, MSGBOX_SIGN
	end

Route204_EventScript_RouteSignRavagedPath::
	msgbox Route204_Text_RouteSignRavagedPath, MSGBOX_SIGN
	end

Route204_Text_BouldersBlocking:
	.string "There are boulders blocking the way\n"
	.string "inside the cavern...\p"
	.string "I think a Pokémon's hidden move will be\n"
	.string "able to smash those boulders, though.$"

Route204_Text_RouteSignJubilife:
	.string "   Rt. 204"
	.string "{DOWN_ARROW} Jubilife City$"

Route204_Text_RouteSignRavagedPath:
	.string "Ravaged Path"$
