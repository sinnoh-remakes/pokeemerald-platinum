EternaCity_PokemonCenter_1F_MapScripts::
	.byte 0

EternaCity_PokemonCenter_1F_EventScript_Nurse::
	setvar VAR_0x800B, LOCALID_ETERNA_NURSE
	call Common_EventScript_PkmnCenterNurse
	waitmessage
	waitbuttonpress
	release
	end

@ FODO: Implement event specific text (post-galactic)
EternaCity_PokemonCenter_1F_EventScript_SchoolKidM::
	msgbox EternaCity_PokemonCenter_1F_Text_TookMyPokemon, MSGBOX_NPC
	end

@ FODO: Implement Poketch app
EternaCity_PokemonCenter_1F_EventScript_AromaLady::
	msgbox EternaCity_PokemonCenter_1F_Text_SpendEnoughTime, MSGBOX_NPC
	end

EternaCity_PokemonCenter_1F_EventScript_BattleGirl::
	msgbox EternaCity_PokemonCenter_1F_Text_PokemonFaints, MSGBOX_NPC
	end

EternaCity_PokemonCenter_1F_Text_TookMyPokemon:
	.string "Team Galactic took my Pokémon away.\n"
	.string "They took other people’s, too.\p"
	.string "Something should be done, but Team\n"
	.string "Galactic creeps everyone out...\p"
	.string "What are they doing to my Pokémon?$"

EternaCity_PokemonCenter_1F_Text_SpendEnoughTime:
	.string "If you spend enough time with them,\n"
	.string "all Pokémon will open up to you.$"

EternaCity_PokemonCenter_1F_Text_PokemonFaints:
	.string "When a Pokémon faints, it just means\n"
	.string "it doesn’t have the power to battle.\p"
	.string "But it can still use hidden moves\n"
	.string "outside of battle!$"
