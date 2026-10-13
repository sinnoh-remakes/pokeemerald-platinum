EternaCity_PokemonCenter_1F_MapScripts::
	.byte 0

EternaCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_ETERNA_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

EternaCity_PokemonCenter_1F_EventScript_Attendant::
	msgbox EternaCity_PokemonCenter_1F_Text_WorkingUnderground, MSGBOX_NPC
	release
	end

EternaCity_PokemonCenter_1F_Text_WorkingUnderground::
	.string "I'm very sorry.\p"
	.string "We are working underground right now.\n"
	.string "It's off-limits to the public.\p"
	.string "Please try later on.$"
