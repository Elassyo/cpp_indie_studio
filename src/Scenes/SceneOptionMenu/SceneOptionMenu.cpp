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
	IAssetManager &loader)
{
	_running = true;
	_menu.createMenu(loader);
	_menu.addImage(loader.loadTexture("images/menuBack.png"), {.5f, .5f}, 5);
	_menu.setElementSize(5, {1, 1});
	_menu.addText((wchar_t *)L"SUPER\nBOMBERMARIO\nBROS.", {.5f, .15f}, 0);
	_menu.setElementFont(0, menu::TITLE);
	_menu.addButton(L"Change Keys", {.5f, .6f}, 3);
	_menu.setButtonEvent(3, [this](){
		_nextScene = "key_scene";
		_running = false;
	});
	_menu.addButton(L"Back", {.5f, .75f}, 4);
	_menu.setButtonEvent(4, [this](){
		_nextScene = "home_scene";
		_running = false;
	});
	setPlusMinusButtons();
	_menu.updateButtons(loader, true);
	return BEGIN;
}

void bomb::scene::SceneOptionMenu::setPlusMinusButtons()
{
	_menu.addButton(L"Volume", {.5f, .3f}, 1);
	_menu.setButtonPushable(1, false);
	_menu.addButton(L"-", {.375f, .3f}, 10);
	_menu.addButton(L"+", {.625f, .3f}, 11);
	_menu.addButton(L"BomberMap Size", {.5f, .45f}, 2);
	_menu.setButtonPushable(2, false);
	_menu.addButton(L"-", {.375f, .45f}, 12);
	_menu.setButtonEvent(12, [this](){
		changeMapSize(-2);
	});
	_menu.addButton(L"+", {.625f, .45f}, 13);
	_menu.setButtonEvent(13, [this](){
		changeMapSize(2);
	});
	for (int id = 10; id <= 13; ++id) {
		_menu.setElementFont(id, menu::MenuFonts::TITLE);
		_menu.setElementSize(id, {.05f, .1f});
	}
	changeMapSize(0);
}

void bomb::scene::SceneOptionMenu::changeMapSize(int change)
{
 	int mapSize = _infos.getMapSize() + change;

	if (mapSize < 7)
		mapSize = 7;
	if (mapSize > 51)
		mapSize = 51;
	_infos.setMapSize(mapSize);
	_menu.setElementText(2, std::wstring(
		L"BomberMap Size\n       " + std::to_wstring(mapSize)).c_str());
}

bomb::scene::SceneStatus bomb::scene::SceneOptionMenu::loop(
	bomb::IAssetManager &loader)
{
	_menu.updateButtons(loader, true);
	return _running ? CONTINUE : END;
}

void bomb::scene::SceneOptionMenu::save()
{
}

void bomb::scene::SceneOptionMenu::reset(bomb::IAssetManager &loader)
{
	(void) loader;
}

void bomb::scene::SceneOptionMenu::clean(IAssetManager &loader)
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
