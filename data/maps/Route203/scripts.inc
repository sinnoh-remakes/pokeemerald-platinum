Route203_MapScripts::
	.byte 0

Route203_EventScript_Michael::
	trainerbattle_single TRAINER_MICHAEL, Route202_Text_MichaelIntro, Route202_Text_MichaelDefeated
	msgbox Route202_Text_MichaelPostBattle, MSGBOX_AUTOCLOSE
	end

Route203_EventScript_Lass1::
	msgbox Route202_Text_FavoriteParty, MSGBOX_NPC
	end
