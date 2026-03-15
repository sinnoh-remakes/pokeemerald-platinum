Route203_MapScripts::
	.byte 0

	@ State descriptions for VAR_ROUTE203_STATE
	@ 1: Defeated Rival

Route203_EventScript_RivalMeet1::
	call Route203_EventScript_RivalApproach
	applymovement LOCALID_ROUTE203_RIVAL, Route203_Movement_RivalApproach1
	waitmovement 0
	goto Route203_EventScript_Rival
	end

Route203_EventScript_RivalMeet2::
	call Route203_EventScript_RivalApproach
	applymovement LOCALID_ROUTE203_RIVAL, Route203_Movement_RivalApproach2
	waitmovement 0
	goto Route203_EventScript_Rival
	end

Route203_EventScript_RivalMeet3::
	call Route203_EventScript_RivalApproach
	applymovement LOCALID_ROUTE203_RIVAL, Route203_Movement_RivalApproach3
	waitmovement 0
	goto Route203_EventScript_Rival
	end

Route203_EventScript_RivalMeet4::
	call Route203_EventScript_RivalApproach
	applymovement LOCALID_ROUTE203_RIVAL, Route203_Movement_RivalApproach4
	waitmovement 0
	goto Route203_EventScript_Rival
	end

Route203_EventScript_RivalApproach::
	lockall
	delay 10
	playse SE_PIN
	applymovement LOCALID_ROUTE203_RIVAL, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE203_RIVAL, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_ROUTE203_RIVAL, Common_Movement_Delay48
	waitmovement 0
	return

Route203_EventScript_Rival::
	switch VAR_STARTER_MON
	msgbox Route203_Text_RivalIntro, MSGBOX_DEFAULT
	case 0, Route203_EventScript_RivalBattleTurtwig
	case 1, Route203_EventScript_RivalBattleChimchar
	case 2, Route203_EventScript_RivalBattlePiplup
	end

Route203_EventScript_RivalBattleTurtwig::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE_203_CHIMCHAR, Route203_Text_RivalDefeated
	goto Route203_EventScript_PostRivalBattle
	end

Route203_EventScript_RivalBattleChimchar::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE_203_PIPLUP, Route203_Text_RivalDefeated
	goto Route203_EventScript_PostRivalBattle
	end

Route203_EventScript_RivalBattlePiplup::
	trainerbattle_no_intro TRAINER_RIVAL_ROUTE_203_TURTWIG, Route203_Text_RivalDefeated
	goto Route203_EventScript_PostRivalBattle
	end

Route203_EventScript_PostRivalBattle::
	setvar VAR_ROUTE203_STATE, 1
	msgbox Route203_Text_RivalPostBattle, MSGBOX_SIGN
	applymovement LOCALID_ROUTE203_RIVAL, Common_Movement_WalkFastRight8
	waitmovement 0
	setflag FLAG_HIDE_ROUTE_203_RIVAL
	removeobject LOCALID_ROUTE203_RIVAL
	end

Route203_Movement_RivalApproach1:
	walk_fast_left
	walk_fast_left
	walk_fast_left
	walk_fast_left
	step_end

Route203_Movement_RivalApproach2:
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

Route203_Movement_RivalApproach3:
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

Route203_Movement_RivalApproach4:
	walk_fast_left
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_left
	walk_fast_left
	step_end

Route203_EventScript_Michael::
	trainerbattle_single TRAINER_PT_MICHAEL, Route203_Text_MichaelIntro, Route203_Text_MichaelDefeated
	msgbox Route203_Text_MichaelPostBattle, MSGBOX_AUTOCLOSE
	end

Route203_EventScript_Dallas::
	trainerbattle_single TRAINER_PT_DALLAS_1, Route203_Text_DallasIntro, Route203_Text_DallasDefeated
	msgbox Route203_Text_DallasPostBattle, MSGBOX_AUTOCLOSE
	end

Route203_EventScript_Sebastian::
	trainerbattle_single TRAINER_PT_SEBASTIAN, Route203_Text_SebastianIntro, Route203_Text_SebastianDefeated
	msgbox Route203_Text_SebastianPostBattle, MSGBOX_AUTOCLOSE
	end

Route203_EventScript_Kaitlin::
	trainerbattle_single TRAINER_PT_KAITLIN, Route203_Text_KaitlinIntro, Route203_Text_KaitlinDefeated
	msgbox Route203_Text_KaitlinPostBattle, MSGBOX_AUTOCLOSE
	end

Route203_EventScript_Madeline::
	trainerbattle_single TRAINER_PT_MADELINE_1 Route203_Text_MadelineIntro, Route203_Text_MadelineDefeated
	msgbox Route203_Text_MadelinePostBattle, MSGBOX_AUTOCLOSE
	end

Route203_EventScript_Lass::
	msgbox Route203_Text_FavoriteParty, MSGBOX_NPC
	end

Route203_EventScript_RouteSignJubilife::
	msgbox Route203_Text_RouteSignJubilife, MSGBOX_SIGN
	end

Route203_EventScript_RouteSignOreburgh::
	msgbox Route203_Text_RouteSignOreburgh, MSGBOX_SIGN
	end

Route203_EventScript_TrainerTips1::
	msgbox Route203_Text_TrainerTips1, MSGBOX_SIGN
	end

Route203_EventScript_TrainerTips2::
	msgbox Route203_Text_TrainerTips2, MSGBOX_SIGN
	end

Route203_Text_FavoriteParty:
	.string "Your favorite Pokémon should be placed\n"
	.string "at the top left of your party list.\p"
	.string "That way, it will be the first to go out\n"
	.string "in a battle.$"

Route203_Text_RouteSignJubilife:
	.string "    Rt.203\n"
	.string "{LEFT_ARROW} Jubilife City$"

Route203_Text_RouteSignOreburgh:
	.string "    Rt.203\n"
	.string "{RIGHT_ARROW} Oreburgh City$"

Route203_Text_TrainerTips1:
	.string "Trainer Tips!\p"
	.string "If a Pokémon is about to evolve,\n"
	.string "it can be instantly stopped.\p"
	.string "Press the B Button during evolution\n"
	.string "to startle the Pokémon into stopping.\p"
	.string "That is how evolution can be\n"
	.string "canceled.$"

Route203_Text_TrainerTips2:
	.string "Trainer Tips!\p"
	.string "Pokémon moves use energy called\n"
	.string "Power Points, or PP for short.\p"
	.string "If the PP of moves runs low, head for\n"
	.string "any Pokémon Center.$"
