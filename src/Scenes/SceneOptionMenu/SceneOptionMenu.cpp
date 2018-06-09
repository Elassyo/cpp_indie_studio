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
	_running = true;
	_menu.createMenu(loader);
	_menu.addImage(loader.loadTexture("images/menuBack.png"), {.5, .5}, 5);
	_menu.setElementSize(5, {1, 1});
	_menu.addText((wchar_t *)L"SUPER\nBOMBERMARIO\nBROS.", {.5, .15}, 0);
	_menu.setElementFont(0, menu::TITLE);
	_menu.addButton(L"Volume", {.5, .35}, 1);
	_menu.setButtonPushable(1, false);
	_menu.addButton(L"Map Size", {.5, .5}, 2);
	_menu.setButtonPushable(2, false);
	_menu.addButton(L"Back", {.5, .65}, 3);
	_menu.setButtonEvent(3, [this](){
		_nextScene = "home_scene";
		_running = false;
	});
	setPlusMinusButtons();
	_menu.updateButtons(loader, true);
	return BEGIN;
}

void bomb::scene::SceneOptionMenu::setPlusMinusButtons()
{
	_menu.addButton(L"-", {.4, .35}, 10);
	_menu.addButton(L"+", {.6, .35}, 11);
	_menu.addButton(L"-", {.4, .5}, 12);
	_menu.addButton(L"+", {.6, .5}, 13);
	for (int id = 10; id <= 13; ++id) {
		_menu.setElementFont(id, menu::MenuFonts::TITLE);
		_menu.setElementSize(id, {.05, .1});
	}
}

bomb::scene::SceneStatus bomb::scene::SceneOptionMenu::loop(
	bomb::IAssetLoader &loader)
{
	_menu.updateButtons(loader, true);
	return _running ? CONTINUE : END;
}

void bomb::scene::SceneOptionMenu::save()
{
}

void bomb::scene::SceneOptionMenu::reset(bomb::IAssetLoader &loader)
{
	(void) loader;
}

void bomb::scene::SceneOptionMenu::clean(IAssetLoader &loader)
{
	_menu.clean();
	(void) loader;
}

std::string bomb::scene::SceneOptionMenu::nextScene()
{
	return _nextScene;
}

bool bomb::scene::SceneOptionMenu::onEvent(const irr::SEvent &event)
{
	if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
		return false;
	_menu.handleEvent(event);
	return true;
}
