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
