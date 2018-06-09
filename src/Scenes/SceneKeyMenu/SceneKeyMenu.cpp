//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// SceneLauncher.cpp
//

#include "SceneKeyMenu.hpp"

bomb::scene::SceneKeyMenu::SceneKeyMenu(bomb::PersistentInfo &_infos)
	: AScene(_infos) {}

bomb::scene::SceneStatus bomb::scene::SceneKeyMenu::start(
	IAssetManager &loader)
{
	_running = true;
	_menu.createMenu(loader);
	_menu.addImage(loader.loadTexture("images/menuBack.png"), {.5, .5}, 5);
	_menu.setElementSize(5, {1, 1});
	_menu.addText((wchar_t *)L"SUPER\nBOMBERMARIO\nBROS.", {.5, .15}, 0);
	_menu.setElementFont(0, menu::TITLE);
	_menu.addButton(L"Back", {.5, .75}, 3);
	_menu.setButtonEvent(3, [this](){
		_nextScene = "option_scene";
		_running = false;
	});
	_menu.updateButtons(loader, true);
	return BEGIN;
}

bomb::scene::SceneStatus bomb::scene::SceneKeyMenu::loop(
	bomb::IAssetManager &loader)
{
	_menu.updateButtons(loader, true);
	return _running ? CONTINUE : END;
}

void bomb::scene::SceneKeyMenu::save()
{
}

void bomb::scene::SceneKeyMenu::reset(bomb::IAssetManager &loader)
{
	(void) loader;
}

void bomb::scene::SceneKeyMenu::clean(IAssetManager &loader)
{
	_menu.clean();
	(void) loader;
}

std::string bomb::scene::SceneKeyMenu::nextScene()
{
	return _nextScene;
}

bool bomb::scene::SceneKeyMenu::onEvent(const irr::SEvent &event)
{
	if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
		return false;
	_menu.handleEvent(event);
	return true;
}
