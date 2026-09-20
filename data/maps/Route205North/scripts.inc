Route205North_MapScripts::
	.byte 0

Route205North_EventScript_Joseph::
	trainerbattle_single TRAINER_PT_JOSEPH_1, Route205North_Text_JosephIntro, Route205North_Text_JosephDefeated
	msgbox Route205North_Text_JosephPostBattle, MSGBOX_AUTOCLOSE
	end

Route205North_EventScript_Andrew::
	trainerbattle_single TRAINER_PT_ANDREW, Route205North_Text_AndrewIntro, Route205North_Text_AndrewDefeated
	msgbox Route205North_Text_AndrewPostBattle, MSGBOX_AUTOCLOSE
	end

Route205North_EventScript_Zachary::
	trainerbattle_single TRAINER_PT_ZACHARY, Route205North_Text_ZacharyIntro, Route205North_Text_ZacharyDefeated
	msgbox Route205North_Text_ZacharyPostBattle, MSGBOX_AUTOCLOSE
	end

Route205North_EventScript_Fisherman::
	msgbox Route205North_Text_Fisherman, MSGBOX_NPC
	end

Route205North_EventScript_RouteSign1::
	msgbox Route205North_Text_RouteSign1, MSGBOX_SIGN
	end

Route205North_EventScript_RouteSign2::
	msgbox Route205North_Text_RouteSign2, MSGBOX_SIGN
	end

Route205North_Text_Fisherman:
	.string "To sit back and fish casually...\n"
	.string "It’s a grown-up’s hobby.$"

Route205North_Text_RouteSign1:
	.string "    Rt.205\n"
	.string "{LEFT_ARROW} Eterna Forest$"

Route205North_Text_RouteSign2:
	.string "    Rt.205\n"
	.string "{RIGHT_ARROW} Eterna City$"
