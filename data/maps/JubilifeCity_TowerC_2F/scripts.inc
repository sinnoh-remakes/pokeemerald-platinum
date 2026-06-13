JubilifeCity_TowerC_2F_MapScripts::
	.byte 0

JubilifeCity_TowerC_2F_EventScript_Breeder::
	msgbox JubilifeCity_TowerC_2F_Text_DidYouBuy, MSGBOX_NPC
	end

JubilifeCity_TowerC_2F_EventScript_BugCatcher::
	msgbox JubilifeCity_TowerC_2F_Text_CanUseAttacks, MSGBOX_NPC
	end

JubilifeCity_TowerC_2F_Text_DidYouBuy:
	.string "Did you buy some Heal Balls at the\n"
	.string "Poké Mart?\p"
	.string "A Heal Ball completely heals the\n"
	.string "Pokémon it captures on the spot.\p"
	.string "That means you can catch a Pokémon\n"
	.string "and have it battle-ready right away.\p"
	.string "Of course, if your team has six\n"
	.string "Pokémon in it, it won’t do any good.$"

JubilifeCity_TowerC_2F_Text_CanUseAttacks:
	.string "I like how Pokémon can use attacks.\n"
	.string "That makes things fun and different.\p"
	.string "Sometimes, when they get stronger,\n"
	.string "Pokémon learn new moves.\p"
	.string "That keeps things fresh and fun when\n"
	.string "using moves.$"
