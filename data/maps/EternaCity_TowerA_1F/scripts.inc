EternaCity_TowerA_1F_MapScripts::
	.byte 0

EternaCity_TowerA_1F_EventScript_NinjaBoy::
	lock
	faceplayer
	goto_if_set FLAG_ETERNA_NPC_TRADE_COMPLETED, EternaCity_TowerA_1F_EventScript_TradeCompleted
	setvar VAR_0x8008, INGAME_TRADE_CHATOT
	copyvar VAR_0x8004, VAR_0x8008
	specialvar VAR_RESULT, GetInGameTradeSpeciesInfo
	copyvar VAR_0x8009, VAR_RESULT
	msgbox EternaCity_TowerA_1F_Text_ExcuseMe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EternaCity_TowerA_1F_EventScript_DeclineTrade
	special ChoosePartyMon
	waitstate
	copyvar VAR_0x800A, VAR_0x8004
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EternaCity_TowerA_1F_EventScript_DeclineTrade
	copyvar VAR_0x8005, VAR_0x800A
	specialvar VAR_RESULT, GetTradeSpecies
	copyvar VAR_0x800B, VAR_RESULT
	goto_if_ne VAR_RESULT, VAR_0x8009, EternaCity_TowerA_1F_EventScript_NotRequestedMon
	copyvar VAR_0x8004, VAR_0x8008
	copyvar VAR_0x8005, VAR_0x800A
	special CreateInGameTradePokemon
	special DoInGameTradeScene
	waitstate
	lock
	faceplayer
	msgbox EternaCity_TowerA_1F_Text_SoAwesome, MSGBOX_DEFAULT
	setflag FLAG_ETERNA_NPC_TRADE_COMPLETED
	release
	end

EternaCity_TowerA_1F_EventScript_NotRequestedMon::
	lock
	faceplayer
	msgbox EternaCity_TowerA_1F_Text_NotBuizel, MSGBOX_DEFAULT
	release
	end

EternaCity_TowerA_1F_EventScript_DeclineTrade::
	msgbox EternaCity_TowerA_1F_Text_TotallyGotit, MSGBOX_DEFAULT
	release
	end

EternaCity_TowerA_1F_EventScript_TradeCompleted::
	msgbox EternaCity_TowerA_1F_Text_TryChatter, MSGBOX_DEFAULT
	release
	end

EternaCity_TowerA_1F_EventScript_Veteran::
	lock
	faceplayer
	msgbox EternaCity_TowerA_1F_Text_NameRater, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EternaCity_TowerA_1F_EventScript_ChooseMonToRate
	goto_if_eq VAR_RESULT, NO, EternaCity_TowerA_1F_EventScript_DeclineNameRate
	end

EternaCity_TowerA_1F_EventScript_ChooseMonToRate::
	msgbox EternaCity_TowerA_1F_Text_WhichPokemon, MSGBOX_DEFAULT
	special ChoosePartyMon
	waitstate
	goto_if_ne VAR_0x8004, PARTY_NOTHING_CHOSEN, EternaCity_TowerA_1F_EventScript_RateMonNickname
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, EternaCity_TowerA_1F_EventScript_DeclineNameRate
	end

EternaCity_TowerA_1F_EventScript_DeclineNameRate::
	msgbox EternaCity_TowerA_1F_Text_DoVisitAgain, MSGBOX_DEFAULT
	release
	end

EternaCity_TowerA_1F_EventScript_RateMonNickname::
	specialvar VAR_RESULT, ScriptGetPartyMonSpecies
	goto_if_eq VAR_RESULT, SPECIES_EGG, EternaCity_TowerA_1F_EventScript_CantRateEgg
	special BufferMonNickname
	special IsMonOTIDNotPlayers
	goto_if_eq VAR_RESULT, TRUE, EternaCity_TowerA_1F_EventScript_PlayerNotMonsOT
	specialvar VAR_RESULT, MonOTNameNotPlayer
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, EternaCity_TowerA_1F_EventScript_PlayerNotMonsOT
	msgbox EternaCity_TowerA_1F_Text_DecentNickname, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, EternaCity_TowerA_1F_EventScript_ChangeNickname
	goto_if_eq VAR_RESULT, NO, EternaCity_TowerA_1F_EventScript_DeclineNameRate
	end

EternaCity_TowerA_1F_EventScript_CantRateEgg::
	msgbox EternaCity_TowerA_1F_Text_OnlyAnEgg, MSGBOX_DEFAULT
	release
	end

EternaCity_TowerA_1F_EventScript_PlayerNotMonsOT::
	msgbox EternaCity_TowerA_1F_Text_MagnificentName, MSGBOX_DEFAULT
	release
	end

EternaCity_TowerA_1F_EventScript_ChangeNickname::
	msgbox EternaCity_TowerA_1F_Text_NewNickname, MSGBOX_DEFAULT
	call Common_EventScript_NameReceivedPartyMon
	specialvar VAR_RESULT, TryPutNameRaterShowOnTheAir
	special BufferMonNickname
	goto_if_eq VAR_RESULT, TRUE, EternaCity_TowerA_1F_EventScript_NewNameDifferent
	msgbox EternaCity_TowerA_1F_Text_NameNoDifferent, MSGBOX_DEFAULT
	release
	end

EternaCity_TowerA_1F_EventScript_NewNameDifferent::
	msgbox EternaCity_TowerA_1F_Text_FromNowOn, MSGBOX_DEFAULT
	release
	end

EternaCity_TowerA_1F_EventScript_PokefanM::
	msgbox EternaCity_TowerA_1F_Text_Superintendent, MSGBOX_NPC
	end

EternaCity_TowerA_1F_Text_ExcuseMe:
	.string "Excuse me, but do you got that\n"
	.string "Pokémon named BUIZEL?\p"
	.string "Wanna trade it for my CHATOT?$"

EternaCity_TowerA_1F_Text_SoAwesome:
	.string "Yes! So awesome! A BUIZEL!\n"
	.string "I so promise I’ll be good to it!\p"
	.string "Oh yeah, CHATOT can learn some human\n"
	.string "speech pretty quickly.\p"
	.string "Try out its move Chatter.\n"
	.string "You’ll totally see what I mean.$"

EternaCity_TowerA_1F_Text_TotallyGotit:
	.string "Oh, OK. Totally got it.\n"
	.string "It’s all right if you don’t want to.\p"
	.string "But if you change your mind,\n"
	.string "let’s totally trade some Pokémon.$"

EternaCity_TowerA_1F_Text_NameRater:
	.string "Hello, hello!\n"
	.string "I am the official Name Rater!\p"
	.string "Want me to rate the nicknames of\n"
	.string "your Pokémon?$"

EternaCity_TowerA_1F_Text_WhichPokemon:
	.string "Which Pokémon’s nickname should\n"
	.string "I critique?$"

EternaCity_TowerA_1F_Text_DecentNickname:
	.string "{STR_VAR_1}, is it?\n"
	.string "That’s a decent nickname!\p"
	.string "But would you like to give it\n"
	.string "an even better name?\p"
	.string "How about it?$"

EternaCity_TowerA_1F_Text_NewNickname:
	.string "Ah, good. Then, what shall the new\n"
	.string "nickname be?$"

EternaCity_TowerA_1F_Text_FromNowOn:
	.string "Done! From now on, this Pokémon\n"
	.string "shall be known as {STR_VAR_1}!\p"
	.string "It is a better name than before!\n"
	.string "How fortunate for you!$"

EternaCity_TowerA_1F_Text_Superintendent:
	.string "Hi! I’m the building superintendent.\n"
	.string "I maintain a vigilant 24-hour watch!$"

EternaCity_TowerA_1F_Text_NotBuizel:
	.string "Huh? That’s not a BUIZEL.\n"
	.string "I’m looking for a BUIZEL, totally.$"

EternaCity_TowerA_1F_Text_TryChatter:
	.string "How’s CHATOT? Try out its move\n"
	.string "Chatter. It’s totally awesome!$"

EternaCity_TowerA_1F_Text_DoVisitAgain:
	.string "I see, I see.\n"
	.string "Do visit again!$"

EternaCity_TowerA_1F_Text_OnlyAnEgg:
	.string "Now, now. That is merely an EGG!$"

EternaCity_TowerA_1F_Text_MagnificentName:
	.string "{STR_VAR_1}, is it?\n"
	.string "That is a magnificent nickname!\p"
	.string "It is impeccably beyond reproach!\n"
	.string "You’ll do well to cherish it!$"

EternaCity_TowerA_1F_Text_NameNoDifferent:
	.string "Done! From now on, this Pokémon\n"
	.string "shall be known as {STR_VAR_1}!\p"
	.string "It looks no different from before,\n"
	.string "and yet, this is vastly superior!$"
