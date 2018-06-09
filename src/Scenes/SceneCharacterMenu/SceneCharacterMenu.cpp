//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// SceneLauncher.cpp
//

#include "SceneCharacterMenu.hpp"

bomb::scene::SceneCharacterMenu::SceneCharacterMenu(
	bomb::PersistentInfo &infos) : AScene(infos) {}

bomb::scene::SceneStatus bomb::scene::SceneCharacterMenu::start(
	IAssetLoader &loader)
{
	_running = true;
	_menu.createMenu(loader);
	_menu.addImage(loader.loadTexture("images/menuBack.png"), {.5, .5}, 5);
	_menu.setElementSize(5, {1, 1});
	_menu.addText((wchar_t *)L"SUPER\nBOMBERMARIO\nBROS.", {.5, .15}, 0);
	_menu.setElementFont(0, menu::TITLE);
	addGameButtons();
	addPlayerButtons();
	initModelPaths();
	_menu.updateButtons(loader, true);
	return BEGIN;
}

void bomb::scene::SceneCharacterMenu::initModelPaths()
{
	auto playerInfos = _infos.getPlayerInfos();
	playerInfos[0].setModelPath((wchar_t *)L"models/characters/shyGuy/shyGuyWhite.mtl");
	playerInfos[1].setModelPath((wchar_t *)L"models/characters/shyGuy/shyGuyBlack.mtl");
	playerInfos[2].setModelPath((wchar_t *)L"models/characters/shyGuy/shyGuyBlue.mtl");
	playerInfos[3].setModelPath((wchar_t *)L"models/characters/shyGuy/shyGuyRed.mtl");
}

void bomb::scene::SceneCharacterMenu::addPlayerButtons()
{
	_menu.addButton(L"1 : AI", {.20, .33}, 1);
	_menu.setButtonEvent(1, [this](){
		changePlayerType(1, (wchar_t *)L"models/characters/shyGuy/shyGuyWhite.mtl");
	});
	_menu.addButton(L"2 : AI", {.40, .33}, 2);
	_menu.setButtonEvent(2, [this](){
		changePlayerType(2, (wchar_t *)L"models/characters/shyGuy/shyGuyBlack.mtl");
	});
	_menu.addButton(L"3 : AI", {.60, .33}, 3);
	_menu.setButtonEvent(3, [this](){
		changePlayerType(3, (wchar_t *)L"models/characters/shyGuy/shyGuyBlue.mtl");
	});
	_menu.addButton(L"4 : AI", {.80, .33}, 4);
	_menu.setButtonEvent(4, [this](){
		changePlayerType(4, (wchar_t *)L"models/characters/shyGuy/shyGuyRed.mtl");
	});
}

void bomb::scene::SceneCharacterMenu::changePlayerType(int idx, wchar_t *model)
{
	PlayerInfo player = _infos.getPlayerInfos(idx - 1);
	_menu.setElementText(idx, std::wstring(
		std::to_wstring(idx ) + L" : "
		+ (player.isAI() ? L"Player" : L"AI")).c_str());
	player.setModelPath(player.isAI() ? (wchar_t *)L"models/characters/skelerex/skelerex.mtl" : model);
	player.setIsAI(!player.isAI());
	_infos.setPlayerInfos(idx - 1, player);
}

void bomb::scene::SceneCharacterMenu::addGameButtons()
{
	_menu.addButton(L"New Game", {.25, .75}, 6);
	_menu.setButtonEvent(6, [this](){
		_nextScene = "game_scene";
		_running = false;
	});
	_menu.addButton(L"Load Game", {.5, .75}, 7);
	_menu.setButtonEvent(7, [this](){
		_nextScene = "game_scene";
		_running = false;
	});
	_menu.addButton(L"Back", {.75, .75}, 8);
	_menu.setButtonEvent(8, [this](){
		_nextScene = "home_scene";
		_running = false;
	});
}

bomb::scene::SceneStatus bomb::scene::SceneCharacterMenu::loop(
	bomb::IAssetLoader &loader)
{
	_menu.updateButtons(loader, true);
	return _running ? CONTINUE : END;
}

void bomb::scene::SceneCharacterMenu::save()
{
}

void bomb::scene::SceneCharacterMenu::reset(bomb::IAssetLoader &loader)
{
	(void) loader;
}

void bomb::scene::SceneCharacterMenu::clean()
{
	_menu.clean();
}

std::string bomb::scene::SceneCharacterMenu::nextScene()
{
	return _nextScene;
}

bool bomb::scene::SceneCharacterMenu::onEvent(const irr::SEvent &event)
{
	if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
		return false;
	_menu.handleEvent(event);
	return true;
}
