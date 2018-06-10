//
// EPITECH PROJECT, 2018
// cpp_indie_studio - CharacterLoader.cpp
// File description:
// Created by Gregory EPLE
//

#include "CharacterLoader.hpp"

bomb::game::CharacterLoader::CharacterLoader() :
	_characters({{SHYGUY_WHITE, CharacterInfo(L"Shy Guy",
				"models/characters/shyGuy/shyGuyWhite.obj",
				"images/characters/ShyGuyWhite-MK8.png",
			    	"sfx/shy-guy-hit.ogg")},
		     {SHYGUY_BLACK, CharacterInfo(L"Shy Guy",
				"models/characters/shyGuy/shyGuyBlack.obj",
				"images/characters/ShyGuyBlack-MK8.png",
				"sfx/shy-guy-hit.ogg")},
		     {SHYGUY_BLUE, CharacterInfo(L"Shy Guy",
				"models/characters/shyGuy/shyGuyBlue.obj",
				"images/characters/ShyGuyBlue-MK8.png",
				"sfx/shy-guy-hit.ogg")},
		     {SHYGUY_RED, CharacterInfo(L"Shy Guy",
				"models/characters/shyGuy/shyGuyRed.obj",
				"images/characters/MK8_ShyGuy_Icon.png",
				"sfx/shy-guy-hit.ogg")},
		     {DRYBONES, CharacterInfo(L"Dry Bones",
				"models/characters/dryBones/dryBones.obj",
				"images/characters/MK8_Dry_Bones_Icon.png",
				"sfx/dry-bones-hit.ogg")},
		     {KOOPA, CharacterInfo(L"Koopa",
				"models/characters/koopa/koopa.obj",
				"images/characters/MK8_Koopa_Icon.png",
				"sfx/koopa-hit.ogg")},
		     {LAKITU, CharacterInfo(L"Lakitu",
				"models/characters/lakitu/lakitu.obj",
				"images/characters/MK8_Lakitu_Icon.png",
				"sfx/lakitu-hit.ogg")},
		     {LUIGI, CharacterInfo(L"Luigi",
				"models/characters/luigi/luigi.obj",
				"images/characters/MK8_Luigi_Icon.png",
		     		"sfx/luigi-hit.ogg")},
		     {MARIO, CharacterInfo(L"Mario",
				"models/characters/mario/mario.obj",
				"images/characters/MK8_Mario_Icon.png",
				"sfx/mario-hit.ogg")},
		     {YOSHI, CharacterInfo(L"Yoshi",
				"models/characters/yoshi/yoshi.obj",
				"images/characters/MK8_Yoshi_Icon.png",
				"sfx/yoshi-hit.ogg")}})
{}

std::string bomb::game::CharacterLoader::getCharacterPath(Character character)
{
	if (_characters.find(character) != _characters.end())
		return _characters.at(character).getModelPath();
	return "";
}

const wchar_t *bomb::game::CharacterLoader::getCharacterName(
	Character character)
{
	if (_characters.find(character) != _characters.end())
		return _characters.at(character).getName();
	return L"";
}

irr::video::ITexture *bomb::game::CharacterLoader::getCharacterTexture(
	Character character)
{
	if (_characters.find(character) != _characters.end())
		return _characters.at(character).getTexture();
	return nullptr;
}

std::string bomb::game::CharacterLoader::getHitSfxPath(
	bomb::game::Character character)
{
	if (_characters.find(character) != _characters.end())
		return _characters.at(character).getHitSfxPath();
	return nullptr;
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

std::string bomb::game::CharacterLoader::getCharacterImagePath(
	bomb::game::Character character)
{
	if (_characters.find(character) != _characters.end())
		return _characters.at(character).getIconPath();
	return "";
}

void bomb::game::CharacterLoader::loadImages(bomb::IAssetManager &manager)
{
	for (auto &c : _characters) {
		auto path = manager.loadTexture(c.second.getIconPath());
		c.second.setTexture(path);
	}
}

void bomb::game::CharacterLoader::loadSounds(bomb::IAssetManager &manager)
{
	for (auto &c : _characters) {
		manager.loadAudioFile(c.second.getHitSfxPath());
	}
}

void bomb::game::CharacterLoader::unloadSounds(bomb::IAssetManager &manager)
{
	for (auto &c : _characters) {
		manager.unloadAudioFile(c.second.getHitSfxPath());
	}
}
