FloaromaTown_MapScripts::
	.byte 0

FloaromaTown_EventScript_GalacticGrunts::
	lock
	applymovement LOCALID_GALACTIC_GRUNT1, Common_Movement_WalkInPlaceRight
	waitmovement 0
	msgbox FloaromaTown_Text_GalacticGrunts1, MSGBOX_DEFAULT
	applymovement LOCALID_GALACTIC_GRUNT2, Common_Movement_WalkInPlaceLeft
	waitmovement 0
	msgbox FloaromaTown_Text_GalacticGrunts2, MSGBOX_DEFAULT
	release
	end

FloaromaTown_Text_GalacticGrunts1:
	.string "Grunt 1: Aren't we Team Galactic?\n"
	.string "And we're assigned here?\p"
	.string "Standing around among flowers...\n"
	.string "This doesn't seem all that cool.$"

FloaromaTown_Text_GalacticGrunts2:
	.string "Grunt 2: Hey now! Don't complain.\n"
	.string "This is a pretty decent assigment.\p"
	.string "But Bug- and Grass-type\n"
	.string "Pokémon so creep me out...\p"
	.string "I don't like being here either.$"

FloaromaTown_EventScript_Lass1::
	msgbox FloaromaTown_Text_LoveItHere, MSGBOX_NPC
	end

FloaromaTown_EventScript_Camper::
	msgbox FloaromaTown_Text_SweetScent, MSGBOX_NPC
	end

FloaromaTown_EventScript_Lass2::
	msgbox FloaromaTown_Text_TheBerries, MSGBOX_NPC
	end

FloaromaTown_EventScript_Beauty::
	msgbox FloaromaTown_Text_GracideaFlowers, MSGBOX_NPC
	end

FloaromaTown_EventScript_SchoolKidM::
	goto_if_set FLAG_DEFEATED_MARS, FloaromaTown_EventScript_SchoolKidM_PostEvent
	lock
	faceplayer
	msgbox FloaromaTown_Text_GetSomeFlowers, MSGBOX_DEFAULT
	applymovement LOCALID_SCHOOL_KID_M, Common_Movement_FaceUp
	waitmovement 0
	msgbox FloaromaTown_Text_GalacticGuys, MSGBOX_DEFAULT
	closemessage
	end

FloaromaTown_EventScript_SchoolKidM_PostEvent::
	msgbox FloaromaTown_Text_PleasantMood, MSGBOX_NPC
	end

FloaromaTown_EventScript_AromaLady::
	msgbox FloaromaTown_Text_Welcome, MSGBOX_NPC
	end

FloaromaTown_EventScript_ShopBlock::
	msgbox FloaromaTown_Text_ShopBlock, MSGBOX_NPC
	end

FloaromaTown_EventScript_TownSign::
	msgbox FloaromaTown_Text_TownSign, MSGBOX_SIGN
	end

FloaromaTown_EventScript_ShopSign::
	msgbox FloaromaTown_Text_ShopSign, MSGBOX_SIGN
	end

FloaromaTown_EventScript_MeadowSign::
	msgbox FloaromaTown_Text_MeadowSign, MSGBOX_SIGN
	end

FloaromaTown_Text_LoveItHere:
	.string "I simply love it here...\n"
	.string "The atmosphere is so uplifting.\p"
	.string "You came to get emotionally healed\n"
	.string "too, didn’t you?$"

FloaromaTown_Text_SweetScent:
	.string "I got drawn here by the sweet scent\n"
	.string "of Honey...\p"
	.string "Seriously, what’s that? What am I?\n"
	.string "A Pokémon or something? Mmm... Honey.$"

FloaromaTown_Text_TheBerries:
	.string "The Berries you pick can be used as\n"
	.string "food for Pokémon.\p"
	.string "You can also trade them in at the\n"
	.string "florist’s.\p"
	.string "They’ll exchange Berries for\n"
	.string "Accessories to dress up your Pokémon.$"

FloaromaTown_Text_GracideaFlowers:
	.string "Do you know about Gracidea flowers?\p"
	.string "They’re given as bouquets to express\n"
	.string "feelings of gratitude.\p"
	.string "It’s an enduring tradition around these\n"
	.string "parts.$"

FloaromaTown_Text_GetSomeFlowers:
	.string "I wanted to get some flowers from\n"
	.string "the Floaroma Meadow...\p"
	.string "But some Team Galactic guys in snazzy\n"
	.string "outfits came along...$"

FloaromaTown_Text_GalacticGuys:
	.string "Those Galactic guys went to the\n"
	.string "meadow past these flowers here...$"

FloaromaTown_Text_PleasantMood:
	.string "Being surrounded by flowers puts me\n"
	.string "in an oddly pleasant mood."

FloaromaTown_Text_Welcome:
	.string "Welcome to Floaroma, the town of\n"
	.string "flowers, flowers, and more flowers!\p"
	.string "You should plant some flowers of\n"
	.string "your own, too. Yay for flowers!$"
	
FloaromaTown_Text_ShopBlock:
	.string "This building is closed for\n"
	.string "maintenance.\p"
	.string "Please come back later.$"

FloaromaTown_Text_TownSign:
	.string "Floaroma Town\n"
	.string "Vivid & Scented$"

FloaromaTown_Text_ShopSign:
	.string "Pick a Peck of Colors Flower Shop\n"
	.string "Free Berries Available$"

FloaromaTown_Text_MeadowSign:
	.string "Floaroma Meadow Ahead\n"
	.string "Honey Available$"
