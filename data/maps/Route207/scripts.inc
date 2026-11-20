Route207_MapScripts::
	.byte 0

Route207_EventScript_Anthony::
	trainerbattle_single TRAINER_PT_ANTHONY, Route207_Text_AnthonyIntro, Route207_Text_AnthonyDefeated
	msgbox Route207_Text_AnthonyPostBattle, MSGBOX_AUTOCLOSE
	end

Route207_EventScript_Lauren::
	trainerbattle_single TRAINER_PT_LAUREN, Route207_Text_LaurenIntro, Route207_Text_LaurenDefeated
	msgbox Route207_Text_LaurenPostBattle, MSGBOX_AUTOCLOSE
	end

Route207_EventScript_Justin::
	trainerbattle_single TRAINER_PT_JUSTIN, Route207_Text_JustinIntro, Route207_Text_JustinDefeated
	msgbox Route207_Text_JustinPostBattle, MSGBOX_AUTOCLOSE
	end

Route207_EventScript_Austin::
	trainerbattle_single TRAINER_PT_AUSTIN, Route207_Text_AustinIntro, Route207_Text_AustinDefeated
	msgbox Route207_Text_AustinPostBattle, MSGBOX_AUTOCLOSE
	end

Route207_EventScript_Kevin::
	trainerbattle_single TRAINER_PT_KEVIN, Route207_Text_KevinIntro, Route207_Text_KevinDefeated
	msgbox Route207_Text_KevinPostBattle, MSGBOX_AUTOCLOSE
	end

Route207_EventScript_Helen::
	trainerbattle_single TRAINER_PT_HELEN_1, Route207_Text_HelenIntro, Route207_Text_HelenDefeated
	msgbox Route207_Text_HelenPostBattle, MSGBOX_AUTOCLOSE
	end

Route207_EventScript_RouteSignOreburgh::
	msgbox Route207_Text_RouteSignOreburgh, MSGBOX_SIGN
	end

Route207_Text_RouteSignOreburgh:
	.string "   Rt.207\n"
	.string "{DOWN_ARROW} Oreburgh City$"
