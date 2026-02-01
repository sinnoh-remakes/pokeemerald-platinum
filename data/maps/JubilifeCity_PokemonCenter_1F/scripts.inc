JubilifeCity_PokemonCenter_1F_MapScripts::
	.byte 0


JubilifeCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_JUBILIFE_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

JubilifeCity_PokemonCenter_1F_EventScript_Schoolkid::
	msgbox JubilifeCity_PokemonCenter_1F_Text_UnionRoom, MSGBOX_DEFAULT
	release
	end

JubilifeCity_PokemonCenter_1F_EventScript_Twin::
	msgbox JubilifeCity_PokemonCenter_1F_Text_AllTypes, MSGBOX_DEFAULT
	release
	end

JubilifeCity_PokemonCenter_1F_EventScript_AceTrainerF::
	msgbox JubilifeCity_PokemonCenter_1F_Text_SixTraveling, MSGBOX_DEFAULT
	release
	end

JubilifeCity_PokemonCenter_1F_EventScript_Attendant::
	msgbox JubilifeCity_PokemonCenter_1F_Text_WorkingUnderground, MSGBOX_DEFAULT
	release
	end

JubilifeCity_PokemonCenter_1F_Text_UnionRoom::
	.string "In the Union Room upstairs, you can\n"
	.string "chat and trade with other people.\p"
	.string "And that's not all you can do.\n"
	.string "Check it out!$"

JubilifeCity_PokemonCenter_1F_Text_AllTypes::
	.string "You know how Pokémon have types like\n"
	.string "Water, Fire, and Grass?\p"
	.string "Well, all types have strenghts and\n"
	.string "weaknesses against other types.$"

JubilifeCity_PokemonCenter_1F_Text_SixTraveling::
	.string "You can still catch a Pokémon if you\n"
	.string "have six traveling with you.\p"
	.string "It automatically gets sent to the PC\n"
	.string "network in Pokémon Centers.$"

JubilifeCity_PokemonCenter_1F_Text_WorkingUnderground::
	.string "I'm very sorry.\p"
	.string "We are working underground right now.\n"
	.string "It's off-limits to the public.\p"
	.string "Please try later on.$"
