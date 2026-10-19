EternaCity_HouseB_MapScripts::
	.byte 0

EternaCity_HouseB_EventScript_Veteran::
	msgbox EternaCity_HouseB_Text_CameToBe, MSGBOX_NPC
	end

EternaCity_HouseB_EventScript_Expert::
	msgbox EternaCity_HouseB_Text_HaveYouSeen, MSGBOX_NPC
	end

EternaCity_HouseB_EventScript_Breeder::
	lock
	faceplayer
	msgbox EternaCity_HouseB_Text_Sheesh, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EternaCity_HouseB_EventScript_NotInterested
	msgbox EternaCity_HouseB_Text_FirstInscription, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EternaCity_HouseB_EventScript_NotInterested
	msgbox EternaCity_HouseB_Text_SecondInscription, MSGBOX_DEFAULT
	release
	end

EternaCity_HouseB_EventScript_NotInterested::
	msgbox EternaCity_HouseB_Text_NotInterested, MSGBOX_DEFAULT
	release
	end

EternaCity_HouseB_Text_CameToBe:
	.string "Eterna came to be long ago in honor\n"
	.string "of ancient Pokémon.\p"
	.string "Though many things have changed,\n"
	.string "what is important has not.\p"
	.string "I hope it remains that way forever\n"
	.string "more...$"

EternaCity_HouseB_Text_HaveYouSeen:
	.string "Have you seen the Pokémon statue?\p"
	.string "When I was a wee child, it used to be\n"
	.string "the centerpiece of many festivals...$"

EternaCity_HouseB_Text_Sheesh:
	.string "Sheesh! \n"
	.string "What’s the world coming to?!\p"
	.string "Someone ripped off the descriptive\n"
	.string "plate from the Pokémon statue!\p"
	.string "Now no one can read the inscription!\n"
	.string "Why would someone do that?\l"
	.string "Actually, want to know what it said?$"

EternaCity_HouseB_Text_FirstInscription:
	.string "The first inscription went like this,\n"
	.string "sort of.\p"
	.string "“...creation of DIA...\n"
	.string "...giver of time...\p"
	.string "“In laughter, there is tears...\n"
	.string "And, likewise...\p"
	.string "“The same time flows...\n"
	.string "...the blessing of DIA...”\p"
	.string "Yikes...\n"
	.string "I’ve forgotten big chunks of it.\p"
	.string "Want to hear about the other\n"
	.string "inscription?$"

EternaCity_HouseB_Text_SecondInscription:
	.string "The second inscription went sort of\n"
	.string "like this.\p"
	.string "“...birth of PAL...\n"
	.string "...creator of parallel dimensions...\p"
	.string "“Alive, yet not alive...\n"
	.string "...rifts in space...\p"
	.string "“To arrive in the same univer...\n"
	.string "...the blessing of PAL...”\p"
	.string "I’ve heard some people talk about\n"
	.string "there once being a third inscription.\p"
	.string "I’m kind of skeptical, though.\n"
	.string "I mean, think about it.\p"
	.string "A third Pokémon alongside those that\n"
	.string "control time and space?\p"
	.string "There couldn’t possibly be a Pokémon\n"
	.string "that mighty.$"

EternaCity_HouseB_Text_NotInterested:
	.string "Well, if you’re not interested, don’t\n"
	.string "feel obligated or anything.$"
