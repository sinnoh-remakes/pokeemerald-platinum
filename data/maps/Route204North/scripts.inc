Route204North_MapScripts::
	.byte 0

Route204North_EventScript_Taylor::
	trainerbattle_single TRAINER_PT_TAYLOR, Route204North_Text_TaylorIntro, Route204North_Text_TaylorDefeated
	msgbox Route204North_Text_TaylorPostBattle, MSGBOX_AUTOCLOSE
	end

Route204North_EventScript_Brandon::
	trainerbattle_single TRAINER_PT_BRANDON_1, Route204North_Text_BrandonIntro, Route204North_Text_BrandonDefeated
	msgbox Route204North_Text_BrandonPostBattle, MSGBOX_AUTOCLOSE
	end

Route204North_EventScript_Liv::
	trainerbattle_double TRAINER_PT_LIV_AND_LIZ, Route204North_Text_LivIntro, Route204North_Text_LivDefeated, Route204North_Text_LivNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route204North_Text_LivPostBattle, MSGBOX_DEFAULT
	release
	end

Route204North_EventScript_Liz::
	trainerbattle_double TRAINER_PT_LIV_AND_LIZ, Route104_Text_MiaIntro, Route204North_Text_LizDefeated, Route204North_Text_LizNotEnoughMons
	special GetPlayerBigGuyGirlString
	msgbox Route204North_Text_LizPostBattle, MSGBOX_DEFAULT
	release
	end

Route204North_EventScript_Youngster::
	msgbox Route204_Text_RaisingDifferent, MSGBOX_NPC
	end

Route204North_EventScript_RouteSignFloaroma::
	msgbox Route204North_Text_RouteSignFloaroma, MSGBOX_SIGN
	end

Route204North_EventScript_TMCaptivate::
	lock
	faceplayer
	goto_if_set FLAG_ITEM_ROUTE_204_TM_CAPTIVATE, Route204North_EventScript_TMCaptivate2
	msgbox Route204North_Text_FlirtyType, MSGBOX_DEFAULT
	giveitem ITEM_TM78
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_ITEM_ROUTE_204_TM_CAPTIVATE
	msgbox Route204North_Text_Genders, MSGBOX_DEFAULT
	release
	end

Route204North_EventScript_TMCaptivate2::
	msgbox Route204North_Text_FlirtyType, MSGBOX_DEFAULT
	release
	end

Route204_Text_RaisingDifferent:
	.string "Are you raising different kinds of\n"
	.string "Pokémon?\p"
	.string "If you only have the same type of\n"
	.string "Pokémon, you'll have a hard time\p"
	.string "against types it's weak to.$"

Route204North_Text_RouteSignFloaroma: 
	.string "    Rt.204\n"
	.string "{LEFT_ARROW} Floaroma Town$"

Route204North_Text_FlirtyType:
	.string "Hi, are you the flirty type?\n"
	.string "I'm asking you this to make a point.\p"
	.string "I teach at the Trainers' School,\n"
	.string "and I'd like to give you a lesson.\p"
	.string "But before I do, I'd like you to\n"
	.string "have this TM.$"

Route204North_Text_Genders:
	.string "You know how Pokémon have genders?\n"
	.string "Like, there are males and females?\p"
	.string "Well, the move Captivate only works\n"
	.string "against the opposite gender.\p"
	.string "For example, it only works when used\n"
	.string "by a male Pokémon on a female.\p"
	.string "The move sharply lowers the target's\n"
	.string "Special Attack, or Sp. Atk for short.\p"
	.string "You also probably know this, but a\n"
	.string "TM is good for only one use.\p"
	.string "Choose the Pokémon wisely if you\n"
	.string "do decide to use it.$"
