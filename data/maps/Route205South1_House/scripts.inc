Route205South1_House_MapScripts::
	.byte 0

Route205South1_House_EventScript_BugCatcher::
	msgbox Route205South1_House_Text_RepelsAreUseful, MSGBOX_NPC
	end

Route205South1_House_EventScript_PokeFanF::
	lock
	faceplayer
	msgbox Route205South1_House_Text_Tired, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route205South1_House_EventScript_PokeFanFRejected
	special HealPlayerParty
	@ callnative UpdateFollowingPokemon
	msgbox Route205South1_House_Text_Refreshed, MSGBOX_DEFAULT
	release
	end

Route205South1_House_EventScript_PokeFanFRejected::
	msgbox Route205South1_House_Text_PushYourself, MSGBOX_DEFAULT
	release
	end

Route205South1_House_Text_RepelsAreUseful:
	.string "Repels are useful, don’t you think?\p"
	.string "When you use a Repel, weak Pokémon\n"
	.string "won’t come out.\p"
	.string "...But that also means there won’t be\n"
	.string "any Pokémon to capture.$"

Route205South1_House_Text_Tired:
	.string "You seem to be tired...\n"
	.string "Rest a while.$"

Route205South1_House_Text_Refreshed:
	.string "You and your Pokémon look\n"
	.string "completely refreshed!$"

Route205South1_House_Text_PushYourself:
	.string "Just because you’re young doesn’t\n"
	.string "mean you should push yourself.$"
