Common_EventScript_HoneyTree::
	lock
	faceplayer
	msgbox Common_Text_SweetScentInTheAir, MSGBOX_DEFAULT
	checkitem ITEM_HONEY
	compare VAR_RESULT, TRUE
	goto_if_eq Common_EventScript_HoneyTree_HasHoney
	release
	end

Common_EventScript_HoneyTree_HasHoney::
	msgbox Common_Text_SlatherBarkWithHoney, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Common_EventScript_HoneyTree_Decline
	removeitem ITEM_HONEY
	msgbox Common_Text_SlatheredBarkWithHoney, MSGBOX_DEFAULT
	special HoneyTreeWildEncounter
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_HoneyTree_Nothing
	waitstate
	release
	end

Common_EventScript_HoneyTree_Nothing::
	msgbox Common_Text_HoneyTreeNothingHappened, MSGBOX_DEFAULT
	release
	end

Common_EventScript_HoneyTree_Decline::
	release
	end

Common_Text_SweetScentInTheAir:
	.string "There is a sweet scent in the air...$"

Common_Text_SlatherBarkWithHoney:
	.string "Slather the bark with honey?$"

Common_Text_SlatheredBarkWithHoney:
	.string "{PLAYER} slathered honey on the\n"
	.string "tree's bark.$"

Common_Text_HoneyTreeNothingHappened:
	.string "Nothing seems to have happened…$"
