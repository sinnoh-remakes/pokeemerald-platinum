ValleyWindworksIndoor_MapScripts::
	.byte 0

ValleyWindworksIndoor_EventScript_Grunt1::
	trainerbattle_single TRAINER_VALLEY_WINDWORKS_GRUNT_1, ValleyWindworksIndoor_Text_Grunt1Intro, ValleyWindworksIndoor_Text_Grunt1Defeated
	msgbox ValleyWindworksIndoor_Text_Grunt1PostBattle, MSGBOX_AUTOCLOSE
	end

ValleyWindworksIndoor_EventScript_Grunt2::
	trainerbattle_single TRAINER_VALLEY_WINDWORKS_GRUNT_2, ValleyWindworksIndoor_Text_Grunt2Intro, ValleyWindworksIndoor_Text_Grunt2Defeated
	msgbox ValleyWindworksIndoor_Text_Grunt2PostBattle, MSGBOX_AUTOCLOSE
	end

ValleyWindworksIndoor_EventScript_Grunt3::
	msgbox ValleyWindworksIndoor_Text_SmooshYou, MSGBOX_NPC

ValleyWindworksIndoor_Text_SmooshYou:
	.string "My Pokémon can’t battle anymore.\p"
	.string "They’re gonna take away my Pokémon\n"
	.string "for messing this one up...\p"
	.string "Humph! Just you wait!\n"
	.string "Our Commander will smoosh you!$"
