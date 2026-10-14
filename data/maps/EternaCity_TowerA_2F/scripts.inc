EternaCity_TowerA_2F_MapScripts::
	.byte 0

EternaCity_TowerA_3F_EventScript_Twin::
	msgbox EternaCity_TowerA_2F_Text_OurGymLeader, MSGBOX_NPC
	end

EternaCity_TowerA_3F_EventScript_Veteran::
	msgbox EternaCity_TowerA_2F_TheMoveRecycle, MSGBOX_NPC
	end

EternaCity_TowerA_2F_EventScript_Expert::
	goto_if_set FLAG_ITEM_ETERNA_CITY_TM_RECYCLE, EternaCity_TowerA_2F_EventScript_ExpertReceived
	lock
	faceplayer
	msgbox EternaCity_TowerA_2F_Text_HadThisTM, MSGBOX_DEFAULT
	giveitem ITEM_TM67
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_ITEM_ETERNA_CITY_TM_RECYCLE
	release
	end

EternaCity_TowerA_2F_EventScript_ExpertReceived::
	msgbox EternaCity_TowerA_2F_Text_LongHistory, MSGBOX_NPC
	end

EternaCity_TowerA_2F_Text_OurGymLeader:
	.string "Gardenia, our Gym Leader, goes out\n"
	.string "to Eterna Forest every so often.\p"
	.string "I always wonder what she does there.$"

EternaCity_TowerA_2F_TheMoveRecycle:
	.string "The move Recycle is to be used during\n"
	.string "battle.\p"
	.string "When you use Recycle, a Pokémon can\n"
	.string "use its item once again.$"

EternaCity_TowerA_2F_Text_HadThisTM:
	.string "I’ve had this TM Recycle for such\n"
	.string "a long time now.\p"
	.string "It’s not anything that I have much\n"
	.string "use for these days.\p"
	.string "I do hope you’ll put it to good\n"
	.string "use, young Trainer.\p"

EternaCity_TowerA_2F_Text_LongHistory:
	.string "Folks like me have a long history\n"
	.string "we can look back on.\p"
	.string "Young people like you have only the\n"
	.string "future to look forward to.$"
