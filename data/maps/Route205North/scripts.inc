Route205North_MapScripts::
	.byte 0

Route205North_EventScript_RouteSign1::
	msgbox Route205North_Text_RouteSign1, MSGBOX_SIGN
	end

Route205North_EventScript_RouteSign2::
	msgbox Route205North_Text_RouteSign2, MSGBOX_SIGN
	end

Route205North_Text_RouteSign1:
	.string "    Rt.205\n"
	.string "{LEFT_ARROW} Eterna Forest$"

Route205North_Text_RouteSign2:
	.string "    Rt.205\n"
	.string "{RIGHT_ARROW} Eterna City$"
