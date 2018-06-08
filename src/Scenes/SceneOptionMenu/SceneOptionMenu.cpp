//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// SceneLauncher.cpp
//

#include "SceneOptionMenu.hpp"

bomb::scene::SceneOptionMenu::SceneOptionMenu(bomb::PersistentInfo &_infos)
	: AScene(_infos) {}

bomb::scene::SceneStatus bomb::scene::SceneOptionMenu::start(
	IAssetLoader &loader)
{
	running = true;
	_menu.createMenu(loader);
	_menu.addImage(loader.loadTexture("images/menuBack.png"), {.5, .5}, 5);
	_menu.setElementSize(5, {1, 1});
	_menu.addText((wchar_t *)L"SUPER\nBOMBERMARIO\nBROS.", {.5, .15}, 0);
	_menu.setElementFont(0, menu::TITLE);
	_menu.addButton(L"Volume Up", {.5, .35}, 1);
	_menu.setButtonEvent(1, [](){});
	_menu.addButton(L"Volume Down", {.5, .5}, 2);
	_menu.setButtonEvent(2, [](){});
	_menu.addButton(L"Back", {.5, .65}, 3);
	_menu.setButtonEvent(3, [this](){
		_nextScene = "home_scene";
	});
	_menu.updateButtons(loader, true);
	loader.getCamera({10,0,10}, {0,0,0});
	return BEGIN;
}

bomb::scene::SceneStatus bomb::scene::SceneOptionMenu::loop(
	bomb::IAssetLoader &loader)
{
	_menu.updateButtons(loader, true);
	return running ? CONTINUE : END;
}

void bomb::scene::SceneOptionMenu::save()
{
}

void bomb::scene::SceneOptionMenu::reset(bomb::IAssetLoader &loader)
{
}

void bomb::scene::SceneOptionMenu::clean()
{
	_menu.clean();
}

std::string bomb::scene::SceneOptionMenu::nextScene()
{
	return _nextScene;
}

bool bomb::scene::SceneOptionMenu::onEvent(const irr::SEvent &event)
{
	if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
		return false;
	if (_menu.handleEvent(event))
		running = false;
	return true;
}
