FloaromaTown_HouseA_MapScripts::
	.byte 0

FloaromaTown_HouseA_EventScript_Twin::
	goto_if_set FLAG_ITEM_FLOAROMA_TOWN_TM_PLUCK, FloaromaTown_HouseA_EventScript_TwinReceived
	lock
	faceplayer
	msgbox FloaromaTown_HouseA_Text_ItsCute, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, FloaromaTown_HouseA_EventScript_TwinRejected
	msgbox FloaromaTown_HouseA_Text_Agreed, MSGBOX_DEFAULT
	giveitem ITEM_TM88
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_ITEM_FLOAROMA_TOWN_TM_PLUCK
	release
	end

FloaromaTown_HouseA_EventScript_TwinReceived::
	msgbox FloaromaTown_HouseA_Text_ItEats, MSGBOX_NPC
	end

FloaromaTown_HouseA_EventScript_TwinRejected::
	msgbox FloaromaTown_HouseA_Text_WeirdThings, MSGBOX_NPC
	end

FloaromaTown_HouseA_EventScript_Clefairy::
	msgbox FloaromaTown_HouseA_Text_Clefairy, MSGBOX_NPC
	end

FloaromaTown_HouseA_EventScript_AromaLady::
	msgbox FloaromaTown_HouseA_Text_BarrenDesolate, MSGBOX_NPC
	end

FloaromaTown_HouseA_Text_ItsCute:
	.string "Do you think it’s cute how\n"
	.string "Pokémon pluck Berries?$"

FloaromaTown_HouseA_Text_Agreed:
	.string "Yes! You agreed!\n"
	.string "Here’s the TM for the move Pluck!$"

FloaromaTown_HouseA_Text_WeirdThings:
	.string "Oh...\nI guess I just like weird things...$"

FloaromaTown_HouseA_Text_ItEats:
	.string "When a Pokémon uses Pluck, it eats\n"
	.string "a Berry held by its foe in battle.\p"
	.string "I like how it steals a Berry.\n"
	.string "It’s so cute!$"

FloaromaTown_HouseA_Text_Clefairy:
	.string "CLEFAIRY: Rii?$"

FloaromaTown_HouseA_Text_BarrenDesolate:
	.string "Floaroma Town was a barren, desolate\n"
	.string "hill long ago, avoided even by Pokémon.\p"
	.string "People started planting flowers on it\n"
	.string "because it was such a sad place.\p"
	.string "But nothing would grow...\n"
	.string "People didn’t know what to do...\p"
	.string "And then one day, someone expressed\n"
	.string "thanks for the blessings of nature.\p"
	.string "Then, the whole hill burst into bloom.$"
