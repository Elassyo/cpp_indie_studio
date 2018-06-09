//
// EPITECH PROJECT, 2018
// cpp_indie_studio - CharacterLoader.cpp
// File description:
// Created by Gregory EPLE
//

#include "CharacterLoader.hpp"

bomb::game::CharacterLoader::CharacterLoader() :
	_characters({{SHYGUY_WHITE, {L"Shy Guy",
				"models/characters/shyGuy/shyGuyWhite.obj"}},
		     {SHYGUY_BLACK, {L"Shy Guy",
				"models/characters/shyGuy/shyGuyBlack.obj"}},
		     {SHYGUY_BLUE, {L"Shy Guy",
				"models/characters/shyGuy/shyGuyBlue.obj"}},
		     {SHYGUY_RED, {L"Shy Guy",
				"models/characters/shyGuy/shyGuyRed.obj"}},
		     {DRYBONES, {L"Dry Bones",
				"models/characters/dryBones/dryBones.obj"}},
		     {KOOPA, {L"Koopa", "models/characters/koopa/koopa.obj"}},
		     {LAKITU, {L"Lakitu",
				"models/characters/lakitu/lakitu.obj"}},
		     {LUIGI, {L"Luigi", "models/characters/luigi/luigi.obj"}},
		     {MARIO, {L"Mario", "models/characters/mario/mario.obj"}},
		     {YOSHI, {L"Yoshi", "models/characters/yoshi/yoshi.obj"}}})
{}

std::string bomb::game::CharacterLoader::getCharacterPath(Character character)
{
	if (_characters.find(character) != _characters.end())
		return _characters[character].second;
	return "";
}

const wchar_t *bomb::game::CharacterLoader::getCharacterName(
	Character character)
{
	if (_characters.find(character) != _characters.end())
		return _characters[character].first;
	return L"";
}

bomb::game::Character bomb::game::CharacterLoader::getNextCharacter(
	Character character)
{
	if (character == SELECT_END || character + 1 == SELECT_END)
		return (Character)(SELECT_BEGIN + 1);
	return (Character)(character + 1);
}

bomb::game::Character bomb::game::CharacterLoader::getPrevCharacter(
	Character character)
{
	if (character == SELECT_BEGIN || character - 1 == SELECT_BEGIN)
		return (Character)(SELECT_END - 1);
	return (Character)(character - 1);
}
