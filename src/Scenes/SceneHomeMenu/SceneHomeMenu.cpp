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
	running = true;
	_menu.createMenu(loader);
	_menu.addButton(loader, {.5, .35}, 1);
	_menu.addButtonText(1, L"Play");
	_menu.addButtonEvent(1, [this](){
		_nextScene = "game_scene";
	});
	_menu.addButton(loader, {.5, .5}, 2);
	_menu.addButtonText(2, L"Options");
	_menu.addButtonEvent(2, [](){});
	_menu.addButton(loader, {.5, .65}, 3);
	_menu.addButtonText(3, L"Quit");
	_menu.addButtonEvent(3, [](){});
	_menu.updateButtons(loader, true);
	loader.getCamera({10,0,10}, {0,0,0});
	return BEGIN;
}

bomb::scene::SceneStatus bomb::scene::SceneHomeMenu::loop(
	bomb::IAssetLoader &loader)
{
	_menu.updateButtons(loader, true);
	return running ? CONTINUE : END;
}

void bomb::scene::SceneHomeMenu::save()
{
}

void bomb::scene::SceneHomeMenu::reset(bomb::IAssetLoader &loader)
{
	(void) loader;
}

void bomb::scene::SceneHomeMenu::clean()
{
	_menu.clean();
}

std::string bomb::scene::SceneHomeMenu::nextScene()
{
	return _nextScene;
}

bool bomb::scene::SceneHomeMenu::onEvent(const irr::SEvent &event)
{
	if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
		return false;
	if (_menu.handleEvent(event))
		running = false;
	return true;
}
