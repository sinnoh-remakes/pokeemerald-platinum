FloaromaTown_PokemonCenter_1F_MapScripts::
	.byte 0

FloaromaTown_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_FLOAROMA_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

FloaromaTown_PokemonCenter_1F_EventScript_Teala::
	msgbox FloaromaTown_PokemonCenter_1F_Text_WorkingUnderground, MSGBOX_NPC
	end

FloaromaTown_PokemonCenter_1F_Text_WorkingUnderground::
	.string "I'm very sorry.\p"
	.string "We are working underground right now.\n"
	.string "It's off-limits to the public.\p"
	.string "Please try later on.$"

FloaromaTown_PokemonCenter_1F_EventScript_PokeFanM::
	msgbox FloaromaTown_PokemonCenter_1F_Text_TravelingAlone, MSGBOX_NPC
	end

FloaromaTown_PokemonCenter_1F_EventScript_AceTrainerF::
	msgbox FloaromaTown_PokemonCenter_1F_Text_ElectricPower, MSGBOX_NPC
	end

FloaromaTown_PokemonCenter_1F_EventScript_BattleGirl::
	msgbox FloaromaTown_PokemonCenter_1F_Text_OtherDay, MSGBOX_NPC
	end

FloaromaTown_PokemonCenter_1F_Text_TravelingAlone:
	.string "If you’ve got Pokémon with you,\n"
	.string "it’s safe for even a kid like you\l"
	.string "to go off traveling alone.$"

FloaromaTown_PokemonCenter_1F_Text_ElectricPower:
	.string "There’ve been problems with the\n"
	.string "electric power lately.\p"
	.string "Is there some trouble at the Valley\n"
	.string "Windworks?$"
@ FODO: Add logic to change NPC text after Valley Windwork event
@ 	  .string "It’s a long way from here to Eterna\n"
@ 	  .string "City.\p"
@ 	  .string "You should be prepared for a long\n"
@ 	  .string "journey.$"

FloaromaTown_PokemonCenter_1F_Text_OtherDay:
	.string "I had a battle the other day, and my\n"
	.string "Pokémon’s HP got low.\p"
	.string "I thought we were done for.\p"
	.string "And then, all of a sudden, my Pokémon\n"
	.string "ate the Berry it was holding! Whew!$"
