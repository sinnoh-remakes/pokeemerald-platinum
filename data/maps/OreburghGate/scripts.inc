OreburghGate_MapScripts::
	.byte 0

OreburghGate_EventScript_Hiker::
	lock
	faceplayer
	goto_if_eq VAR_OREBURGH_CITY_STATE, 0, OreburghGate_EventScript_HikerGive
	msgbox OrebrughGate_Text_HiddenMachine, MSGBOX_NPC
	end

OreburghGate_EventScript_HikerGive::
	msgbox OreburghGate_Text_SparkingNew, MSGBOX_DEFAULT
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setvar VAR_OREBURGH_CITY_STATE, 1
	msgbox OrebrughGate_Text_HiddenMachine, MSGBOX_DEFAULT
	release
	end

OreburghGate_EventScript_HikerAlert::
	applymovement LOCALID_OREBURGH_GATE_HIKER, Common_Movement_WalkInPlaceDown
	waitmovement 0
	playse SE_PIN
	applymovement LOCALID_OREBURGH_GATE_HIKER, Common_Movement_ExclamationMark
	applymovement LOCALID_PLAYER, Common_Movement_WalkInPlaceUp
	waitmovement 0
	applymovement LOCALID_OREBURGH_GATE_HIKER, Common_Movement_Delay48
	waitmovement 0
	applymovement LOCALID_OREBURGH_GATE_HIKER, Common_Movement_Delay48
	waitmovement 0
	return

OreburghGate_EventScript_HikerAlert1::
	lock
	call OreburghGate_EventScript_HikerAlert
	goto OreburghGate_EventScript_HikerGive
	end

OreburghGate_EventScript_HikerAlert2::
	lock
	call OreburghGate_EventScript_HikerAlert
	applymovement LOCALID_OREBURGH_GATE_HIKER, Common_Movement_WalkDown
	waitmovement 0
	goto OreburghGate_EventScript_HikerGive
	end

OreburghGate_EventScript_Curtis::
	trainerbattle_single TRAINER_PT_CURTIS, OreburghGate_Text_CurtisIntro, OreburghGate_Text_CurtisDefeated
	msgbox OreburghGate_Text_CurtisPostBattle, MSGBOX_AUTOCLOSE
	end

OreburghGate_EventScript_Diana::
	trainerbattle_single TRAINER_PT_DIANA, OreburghGate_Text_DianaIntro, OreburghGate_Text_DianaDefeated
	msgbox OreburghGate_Text_DianaPostBattle, MSGBOX_AUTOCLOSE
	end

OreburghGate_Text_SparkingNew:
	.string "That sparkling new Pokétch!\n"
	.string "Your awkwardness as a traveler!\p"
	.string "Hmm... You're still a pretty new\n"
	.string "Trainer, aren't you?\p"
	.string "But it's all good! You're a new fellow\n"
	.string "friend of Pokémon!\p"
	.string "So, let me make a gift of this Hidden\n"
	.string "Machine to you!$"

OrebrughGate_Text_HiddenMachine:
	.string "That Hidden Machine, or HM for short,\n"
	.string "contains the hidden move Rock Smash.\p"
	.string "A Pokémon learning Rock Smash can\n"
	.string "smash small boulders in the field.\p"
	.string "But the trainer has to have\n"
	.string "the Gym Badge from Oreburgh City.\p"
	.string "If you don't have that Badge, you\n"
	.string "can't make a Pokémon use the hidden\l"
	.string "move Rock Smash outside of battle.$"
