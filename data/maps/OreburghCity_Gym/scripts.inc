OreburghCity_Gym_MapScripts::
	.byte 0

OreburghCity_Gym_EventScript_Roark::
	trainerbattle_single TRAINER_PT_ROARK, OreburghCity_Gym_Text_RoarkIntro, OreburghCity_Gym_Text_RoarkDefeat, OreburghCity_Gym_EventScript_RoarkDefeated, NO_MUSIC
	msgbox OreburghCity_Gym_Text_RoarkPostBattle, MSGBOX_DEFAULT
	release
	end

OreburghCity_Gym_EventScript_RoarkDefeated::
	msgbox OreburghCity_Gym_Text_RoarkDefeated, MSGBOX_DEFAULT
	message OreburghCity_Gym_Text_ReceivedCoalBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox OreburghCity_Gym_Text_CoalBadgeInfoTakeThis, MSGBOX_DEFAULT
	setflag FLAG_DEFEATED_OREBURGH_GYM
	setflag FLAG_BADGE01_GET
	@ setvar VAR_RUSTBORO_CITY_STATE, 1
	@ setvar VAR_0x8008, 1
	@ call Common_EventScript_SetGymTrainers
	goto OreburghCity_Gym_EventScript_GiveStealthRock
	end

OreburghCity_Gym_EventScript_GiveStealthRock::
	giveitem ITEM_TM76
	goto_if_eq VAR_RESULT, FALSE, Common_EventScript_ShowBagIsFull
	setflag FLAG_RECEIVED_TM_STEALTH_ROCK
	msgbox OreburghCity_Gym_Text_ExplainStealthRock, MSGBOX_DEFAULT
	release
	end

OreburghCity_Gym_EventScript_Jonathon::
	trainerbattle_single TRAINER_PT_JONATHON, OreburghCity_Gym_Text_JonathonIntro, OreburghCity_Gym_Text_JonathonDefeat
	msgbox OreburghCity_Gym_Text_JonathonPostBattle, MSGBOX_AUTOCLOSE
	end

OreburghCity_Gym_EventScript_Darius::
	trainerbattle_single TRAINER_PT_DARIUS, OreburghCity_Gym_Text_DariusIntro, OreburghCity_Gym_Text_DariusDefeat
	msgbox OreburghCity_Gym_Text_DariusPostBattle, MSGBOX_AUTOCLOSE
	end

OreburghCity_Gym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_OREBURGH_GYM, OreburghCity_Gym_EventScript_GymGuidePostVictory
	msgbox OreburghCity_Gym_Text_GymGuideAdvice, MSGBOX_DEFAULT
	release
	end

OreburghCity_Gym_EventScript_GymGuidePostVictory::
	msgbox OreburghCity_Gym_Text_GymGuidePostVictory, MSGBOX_DEFAULT
	release
	end

OreburghCity_Gym_EventScript_LeftGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, OreburghCity_Gym_EventScript_GymStatueCertified
	goto OreburghCity_Gym_EventScript_GymStatue
	end

OreburghCity_Gym_EventScript_RightGymStatue::
	lockall
	goto_if_set FLAG_BADGE01_GET, OreburghCity_Gym_EventScript_GymStatueCertified
	goto OreburghCity_Gym_EventScript_GymStatue
	end

OreburghCity_Gym_EventScript_GymStatueCertified::
	msgbox OreburghCity_Gym_Text_GymStatueCertified, MSGBOX_DEFAULT
	releaseall
	end

OreburghCity_Gym_EventScript_GymStatue::
	msgbox OreburghCity_Gym_Text_GymStatue, MSGBOX_DEFAULT
	releaseall
	end

OreburghCity_Gym_Text_GymGuideAdvice:
	.string "Howdy!\n"
	.string "How’s it going, Champ-to-be?\p"
	.string "That’s what I said to a really\n"
	.string "impatient boy earlier, too.\p"
	.string "The Gym Leader is a user of\n"
	.string "Rock-type Pokémon.\p"
	.string "Well, listen. Rock-type Pokémon\n"
	.string "really hate water, all right?\p"
	.string "They’re also weak to Grass-type\n"
	.string "moves.\p"
	.string "Gee, they sure have weaknesses!\p"
	.string "But don’t think it will be easy.\p"
	.string "You don’t get to be a Gym Leader\n"
	.string "without covering for weaknesses.\p"
	.string "Going after a Rock-type Pokémon\n"
	.string "with a Fire-type Pokémon won’t be\l"
	.string "easy, either.\p"
	.string "That’s all the advice I can give.\n"
	.string "Thanks for listening!$"

OreburghCity_Gym_Text_GymGuidePostVictory:
	.string "Oh! {PLAYER}!\n"
	.string "You’ve taken care of the Gym Leader!\p"
	.string "So, did my advice come in handy\n"
	.string "or what?\p"
	.string "If my advice was useful, it’d be\n"
	.string "great if you’d become my fan!$"

OreburghCity_Gym_Text_RoarkIntro:
	.string "Welcome!\n"
	.string "This is the Oreburgh Pokémon Gym!\p"
	.string "I’m Roark, the Gym Leader!\p"
	.string "I’m but one Trainer who decided to\n"
	.string "walk proudly with Rock-type Pokémon!\p"
	.string "As the Gym Leader, I need to see\n"
	.string "your potential as a Trainer.\p"
	.string "And, I’ll need to see the toughness\n"
	.string "of the Pokémon that battle with you!$"

OreburghCity_Gym_Text_RoarkDefeat:
	.string "W-what? That can't be!"
	.string "My buffed-up Pokémon!$"

OreburghCity_Gym_Text_RoarkDefeated:
	.string "This is embarrassing...\p"
	.string "I went and lost to a Trainer who\n"
	.string "didn’t have a single Gym Badge...\p"
	.string "But that’s tough. You were strong,\n"
	.string "and I was weak. That’s all there is.\p"
	.string "According to Pokémon League rules,\n"
	.string "I have to give you our Gym Badge\l"
	.string "since you’ve beaten me, the Leader.\p"
	.string "Here’s your official Pokémon League\n"
	.string "Coal Badge.$"

OreburghCity_Gym_Text_ReceivedCoalBadge:
	.string "{PLAYER} received\n"
	.string "the Coal Badge from Roark!$"

OreburghCity_Gym_Text_CoalBadgeInfoTakeThis:
	.string "Having that Coal Badge means your\n"
	.string "Pokémon can now use the hidden move\l"
	.string "Rock Smash outside of battle.\p"
	.string "You should also take this, too.$"

OreburghCity_Gym_Text_ExplainStealthRock:
	.string "That TM76 contains\n"
	.string "the move Stealth Rock.\p"
	.string "It’s a move that inflicts damage on\n"
	.string "foes that switch into battle.\p"
	.string "Incidentally, a TM will teach its move\n"
	.string "to a Pokémon instantly.\p"
	.string "But a TM will break when you use it,\n"
	.string "so make certain you want a Pokémon\l"
	.string "to learn that move.$"

OreburghCity_Gym_Text_RoarkPostBattle:
	.string "In this region of Sinnoh, there are\n"
	.string "seven other Gym Leaders.\p"
	.string "I should warn you--they’re a lot\n"
	.string "tougher than I am!$"

OreburghCity_Gym_Text_GymStatue:
	.string "Oreburgh City Pokémon Gym\n"
	.string "Leader: Roark\p"
	.string "Certified Trainers:\n"
	.string "{RIVAL}$"

OreburghCity_Gym_Text_GymStatueCertified:
	.string "Oreburgh City Pokémon Gym\n"
	.string "Leader: Roark\p"
	.string "Certified Trainers:\n"
	.string "{RIVAL}\l"
	.string "{PLAYER}$"
