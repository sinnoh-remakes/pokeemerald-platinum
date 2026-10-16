EternaCitySouth_MapScripts::
	.byte 0

EternaCitySouth_EventScript_GalacticGrunt::
	msgbox EternaCitySouth_Text_YouThereKid, MSGBOX_NPC
	end

EternaCitySouth_EventScript_BugCatcher::
	msgbox EternaCitySouth_Text_MyFriendSaid, MSGBOX_NPC
	end

EternaCitySouth_EventScript_Veteran::
	msgbox EternaCitySouth_Text_NotAnythingLike, MSGBOX_NPC
	end

EternaCitySouth_EventScript_AceTrainerF::
	msgbox EternaCitySouth_Text_AnOldCity, MSGBOX_NPC
	end

EternaCitySouth_EventScript_AromaLady1::
	msgbox EternaCitySouth_Text_BuildingWentUp, MSGBOX_NPC
	end

EternaCitySouth_EventScript_Breeder::
	msgbox EternaCitySouth_Text_VisitingEterna, MSGBOX_NPC
	end

EternaCitySouth_EventScript_AromaLady2::
	msgbox EternaCitySouth_Text_YouDontHave, MSGBOX_NPC
	end

EternaCitySouth_EventScript_Gardenia::
	lock
	faceplayer
	msgbox EternaCitySouth_Text_GardeniaIntro, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_ETERNA_CITY_GARDENIA, Common_Movement_WalkInPlaceUp
	waitmovement 0
	delay 16
	removeobject LOCALID_ETERNA_CITY_GARDENIA
	setflag FLAG_HIDE_ETERNA_CITY_GARDENIA
	delay 16
	release
	end

EternaCitySouth_EventScript_BikeShopSign::
	msgbox EternaCitySouth_Text_BikeShopSign, MSGBOX_SIGN
	end

EternaCitySouth_EventScript_CondominiumSign::
	msgbox EternaCitySouth_Text_CondominiumSign, MSGBOX_SIGN
	end

EternaCitySouth_EventScript_GymSign::
	msgbox EternaCitySouth_Text_GymSign, MSGBOX_SIGN
	end

EternaCitySouth_Text_YouThereKid:
	.string "Hey! You there, kid!\n"
	.string "Stay away from that Pokémon statue!\p"
	.string "Team Galactic is conducting an\n"
	.string "official investigation here!$"

EternaCitySouth_Text_MyFriendSaid:
	.string "My friend said Team Galactic took his\n"
	.string "favorite Pokémon away.\p"
	.string "I don’t think he’s telling the truth.\n"
	.string "Team Galactic looks so cool.\l"
	.string "They don’t look like common thugs.$"

EternaCitySouth_Text_NotAnythingLike:
	.string "Eterna City’s not anything like it\n"
	.string "was before, way back in the day.$"

EternaCitySouth_Text_AnOldCity:
	.string "They say this is an old city.\p"
	.string "It doesn’t look it, though.\n"
	.string "Not with all these tall buildings.$"

EternaCitySouth_Text_BuildingWentUp:
	.string "Since that Team Galactic building went\n"
	.string "up, the city’s atmosphere has gotten\l"
	.string "all creepy and tense.\p"
	.string "I don’t know what those people are\n"
	.string "doing up in that place...$"

EternaCitySouth_Text_VisitingEterna:
	.string "If you’re visiting Eterna, you need to\n"
	.string "get yourself a Bicycle and take a\l"
	.string "ride down the Cycling Road.$"

EternaCitySouth_Text_YouDontHave:
	.string "Oh, don’t tell me you don’t have\n"
	.string "an Explorer Kit?\p"
	.string "You should have a word with the man\n"
	.string "next door to the Pokémon Center.\p$"

EternaCitySouth_Text_GardeniaIntro:
	.string "Hi! I’m Gardenia!\n"
	.string "I’m this town’s Gym Leader!\p"
	.string "My last challenger was this awfully\n"
	.string "speedy young guy.\p"
	.string "...Actually, his name was {RIVAL}.\n"
	.string "He told me about you.\p"
	.string "He said that another challenger’s on\n"
	.string "the way, so that made me antsy!\p"
	.string "At my Gym, no one gets to battle with\n"
	.string "the Gym Leader, me, until the end.\p"
	.string "The challenger has to beat all the\n"
	.string "other Gym Trainers first.\p"
	.string "I’ll be waiting for you in the back,\n"
	.string "Trainer. Don’t disappoint me!$"

EternaCitySouth_Text_BikeShopSign:
	.string "Rad Rickshaw’s Cycle Shop\n"
	.string "Get On and Ride!$"

EternaCitySouth_Text_CondominiumSign:
	.string "Eterna Condominiums\n"
	.string "Name-Rating Services Available$"

EternaCitySouth_Text_GymSign:
	.string "Eterna City Pokémon Gym\n"
	.string "Leader: Gardenia\l"
	.string "Master of Vivid Plant Pokémon!$"
