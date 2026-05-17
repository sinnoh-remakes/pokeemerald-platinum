OreburghCity_HouseA_MapScripts::
	.byte 0

OreburghCity_HouseA_EventScript_PokefanF::
	msgbox OreburghCity_HouseA_Text_DifferentNatures, MSGBOX_NPC
	end

OreburghCity_HouseA_EventScript_Youngster::
	msgbox OreburghCity_HouseA_Text_DifferentlyColored, MSGBOX_NPC
	end

OreburghCity_HouseA_EventScript_Pikachu::
	msgbox OreburghCity_HouseA_Text_Pikachu, MSGBOX_NPC
	end

OreburghCity_HouseA_Text_DifferentNatures:
	.string "You know how Pokémon have different\n"
	.string "natures like we have personalities?\p"
	.string "I don’t think it’s surprising to see\n"
	.string "Pokémon in different colors$."

OreburghCity_HouseA_Text_DifferentlyColored:
	.string "Have you ever seen or heard about\n"
	.string "differently colored Pokémon?\p"
	.string "For instance, a regular PIKACHU has\n"
	.string "a yellow body, correct?\p"
	.string "Well, the different-colored PIKACHU\n"
	.string "has a sort of orange body.$"

OreburghCity_HouseA_Text_Pikachu:
	@ FODO: Play Pikachu sound
	.string "PIKACHU: Pikaaah!$"
