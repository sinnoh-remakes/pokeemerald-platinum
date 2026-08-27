Route205South1_MapScripts::
	.byte 0

Route205South2_EventScript_Daniel::
	trainerbattle_single TRAINER_PT_DANIEL, Route205South_Text_DanielIntro, Route205South_Text_DanielDefeated
	msgbox Route205South_Text_DanielPostBattle, MSGBOX_AUTOCLOSE
	end

Route205South2_EventScript_Elizabeth::
	trainerbattle_single TRAINER_PT_ELIZABETH_1, Route205South_Text_ElizabethIntro, Route205South_Text_ElizabethDefeated
	msgbox Route205South_Text_ElizabethPostBattle, MSGBOX_AUTOCLOSE
	end

Route205South2_EventScript_Zackary::
	trainerbattle_single TRAINER_PT_ZACKARY_1, Route205South_Text_ZackaryIntro, Route205South_Text_ZackaryDefeated
	msgbox Route205South_Text_ZackaryPostBattle, MSGBOX_AUTOCLOSE
	end

Route205South2_EventScript_Siena::
	trainerbattle_single TRAINER_PT_SIENA, Route205South_Text_SienaIntro, Route205South_Text_SienaDefeated
	msgbox Route205South_Text_SienaPostBattle, MSGBOX_AUTOCLOSE
	end

Route205South2_EventScript_Nicholas::
	trainerbattle_single TRAINER_PT_NICHOLAS, Route205South_Text_NicholasIntro, Route205South_Text_NicholasDefeated
	msgbox Route205South_Text_NicholasPostBattle, MSGBOX_AUTOCLOSE
	end

Route205South2_EventScript_Kelsey::
	trainerbattle_single TRAINER_PT_KELSEY, Route205South_Text_KelseyIntro, Route205South_Text_KelseyDefeated
	msgbox Route205South_Text_KelseyPostBattle, MSGBOX_AUTOCLOSE
	end

Route205South2_EventScript_Karina::
	trainerbattle_single TRAINER_PT_KARINA_1, Route205South_Text_KarinaIntro, Route205South_Text_KarinaDefeated
	msgbox Route205South_Text_KarinaPostBattle, MSGBOX_AUTOCLOSE
	end

Route205South1_EventScript_RouteSign::
	msgbox Route205South1_Text_RouteSign, MSGBOX_SIGN
	end

Route205South1_EventScript_AirVent::
	msgbox Route205South1_Text_AirVent, MSGBOX_SIGN
	end

Route205South1_EventScript_TrainerTips::
	msgbox Route205South1_Text_TrainerTips, MSGBOX_SIGN
	end

Route205South1_Text_RouteSign:
	.string "{UP_ARROW} Rt.205\n"
	.string "   Eterna Forest$"

Route205South1_Text_AirVent:
	.string "It's an air vent that exchanges\n"
	.string "the underground tunnels' air.$"

Route205South1_Text_TrainerTips:
	.string "Trainer Tips!\p"
	.string "The items placed in your Bag are\n"
	.string "automatically sorted to the\l"
	.string "appropriate pockets.\p"
	.string "It’s very convenient!\n"
	.string "It’s a Trainer’s best friend!$"
