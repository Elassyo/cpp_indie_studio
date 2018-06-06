//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// SceneLauncher.cpp
//

#include <iostream>

#include "SceneHomeMenu.hpp"

bomb::scene::SceneStatus bomb::scene::SceneHomeMenu::start(
	IAssetLoader &loader)
{
	_menu = loader.createMenu();
	_menu->addButton([this]() {this->_nextScene = "game_scene";},
			 L"Game", {.5, .35});
	_menu->addButton([this]() {this->_nextScene = "";},
			 L"Option", {.5, .5});
	_menu->addButton([this]() {this->_nextScene = "";},
			 L"Quit", {.5, .65});
	_menu.get()->updateButtons(true);
	loader.addCamera({10,0,10}, {0,0,0});
	return BEGIN;
}

bomb::scene::SceneStatus bomb::scene::SceneHomeMenu::loop(
	bomb::IAssetLoader &loader)
{
	_menu.get()->updateButtons(true);
	return CONTINUE;
}

void bomb::scene::SceneHomeMenu::save()
{
}

void bomb::scene::SceneHomeMenu::reset(bomb::IAssetLoader &loader)
{
}

void bomb::scene::SceneHomeMenu::clean()
{
}

std::string bomb::scene::SceneHomeMenu::nextScene()
{
	return "";
}

bool bomb::scene::SceneHomeMenu::onEvent(const irr::SEvent &event)
{
	return true;
}
