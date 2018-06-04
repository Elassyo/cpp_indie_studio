/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** GameInfo.cpp
*/

#include "GameInfo.hpp"

bomb::game::GameInfo::GameInfo(bomb::IAssetLoader &loader) :
	_loader(loader)
{
	_characters.resize(5);
	_characters[SHYGUY_BLACK] = loader.createAnimatedObject(
		"assets/models/characters/shyGuy/shyGuyBlack.obj");
	_characters[SHYGUY_BLUE] = loader.createAnimatedObject(
		"assets/models/characters/shyGuy/shyGuyBlue.obj");
	_characters[SHYGUY_RED] = loader.createAnimatedObject(
		"assets/models/characters/shyGuy/shyGuyRed.obj");
	_characters[SHYGUY_WHITE] = loader.createAnimatedObject(
		"assets/models/characters/shyGuy/shyGuyWhite.obj");
	_characters[SKELEREX] = loader.createAnimatedObject(
		"assets/models/characters/skelerex/skelerex.obj");
	reset();
}

void bomb::game::GameInfo::reset()
{
	_players[0].setCharacterIndex(SHYGUY_BLACK);
	_players[1].setCharacterIndex(SHYGUY_BLUE);
	_players[2].setCharacterIndex(SHYGUY_RED);
	_players[3].setCharacterIndex(SHYGUY_WHITE);
}
