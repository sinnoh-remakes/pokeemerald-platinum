Gate_Cycling_South_MapScripts::
	.byte 0

Gate_Cycling_South_EventScript_BlockWalking::
	lockall
	specialvar VAR_RESULT, GetPlayerAvatarBike
	goto_if_eq VAR_RESULT, 0, Gate_Cycling_South_EventScript_NoBike
	releaseall
	end

Gate_Cycling_South_EventScript_NoBike::
	playse SE_PIN
	applymovement LOCALID_CYCLING_CLERK_SOUTH, Common_Movement_ExclamationMark
	waitmovement 0
	delay 48
	delay 48
	msgbox Gate_Cycling_South_Text_GetOnBicycle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, Common_Movement_WalkDown
	waitmovement 0
	releaseall
	end

Gate_Cycling_South_EventScript_ShiftGears::
	msgbox Gate_Cycling_South_Text_ShiftGears, MSGBOX_NPC
	end

Gate_Cycling_South_EventScript_BattleGirl::
	goto_if_set FLAG_CYCLING_ROAD_FLAG, Gate_Cycling_South_EventScript_BattleGirlReceived
	lock
	faceplayer
	msgbox Gate_Cycling_South_Text_WithoutThis, MSGBOX_DEFAULT
	@ FODO: Implement Accessories
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_CYCLING_ROAD_FLAG
	release
	end

Gate_Cycling_South_EventScript_BattleGirlReceived::
	msgbox Gate_Cycling_South_Text_GoThrough, MSGBOX_NPC
	end

Gate_Cycling_South_Text_GetOnBicycle:
	.string "Cycling Road is only open to cyclists!\p"
	.string "You must be on a Bicycle!$"

Gate_Cycling_South_Text_ShiftGears:
	.string "Learn how to shift gears, and you’ll\n"
	.string "be able to ride anywhere.$"

Gate_Cycling_South_Text_WithoutThis:
	.string "What’s a Bicycle without this?\p"
	.string "You’ve got to have a Flag!\n"
	.string "It’s a Pokémon Accessory!$"

Gate_Cycling_South_Text_GoThrough:
	.string "Go through Mt. Coronet from here,\n"
	.string "and you can get to Hearthome City.\p"
	.string "Hearthome is where they hold Pokémon\nContests.\p"
	.string "You should dress up your Pokémon for\n"
	.string "Contests with your Accessories.$"
