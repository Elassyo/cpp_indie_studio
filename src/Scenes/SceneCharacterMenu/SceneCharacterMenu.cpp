//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// SceneLauncher.cpp
//

#include "SceneCharacterMenu.hpp"

bomb::scene::SceneCharacterMenu::SceneCharacterMenu(
	bomb::PersistentInfo &infos) : AScene(infos), _charLoader() {}

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
	addCharacterButtons();
	initModelPaths();
	_menu.updateButtons(loader, true);
	return BEGIN;
}

void bomb::scene::SceneCharacterMenu::initModelPaths()
{
	auto playerInfos = _infos.getPlayerInfos();
	playerInfos[0].setCharacter(bomb::game::SHYGUY_WHITE);
	playerInfos[1].setCharacter(bomb::game::SHYGUY_BLACK);
	playerInfos[2].setCharacter(bomb::game::SHYGUY_BLUE);
	playerInfos[3].setCharacter(bomb::game::SHYGUY_RED);
	_infos.setPlayerInfos(playerInfos);
}

void bomb::scene::SceneCharacterMenu::addPlayerButtons()
{
	_menu.addButton(L"1 : AI", {.20, .33}, 1);
	_menu.setButtonEvent(1, [this](){
		changePlayerType(1, bomb::game::SHYGUY_WHITE);
	});
	_menu.addButton(L"2 : AI", {.40, .33}, 2);
	_menu.setButtonEvent(2, [this](){
		changePlayerType(2, bomb::game::SHYGUY_BLACK);
	});
	_menu.addButton(L"3 : AI", {.60, .33}, 3);
	_menu.setButtonEvent(3, [this](){
		changePlayerType(3, bomb::game::SHYGUY_BLUE);
	});
	_menu.addButton(L"4 : AI", {.80, .33}, 4);
	_menu.setButtonEvent(4, [this](){
		changePlayerType(4, bomb::game::SHYGUY_RED);
	});
}

void bomb::scene::SceneCharacterMenu::addCharacterButtons()
{
	_menu.addButton(L"Shy Guy", {.20, .5}, 11);
	_menu.setButtonPushable(11, false);
	_menu.setButtonEvent(11, [this](){
		changeCharacter(1);
	});
	_menu.addButton(L"Shy Guy", {.40, .5}, 12);
	_menu.setButtonPushable(12, false);
	_menu.setButtonEvent(12, [this](){
		changeCharacter(2);
	});
	_menu.addButton(L"Shy Guy", {.60, .5}, 13);
	_menu.setButtonPushable(13, false);
	_menu.setButtonEvent(13, [this](){
		changeCharacter(3);
	});
	_menu.addButton(L"Shy Guy", {.80, .5}, 14);
	_menu.setButtonPushable(14, false);
	_menu.setButtonEvent(14, [this](){
		changeCharacter(4);
	});
}

void bomb::scene::SceneCharacterMenu::changePlayerType(
	int idx, game::Character character)
{
	PlayerInfo player = _infos.getPlayerInfos(idx - 1);

	_menu.setElementText(idx, std::wstring(
		std::to_wstring(idx ) + L" : "
		+ (player.isAI() ? L"Player" : L"AI")).c_str());
	player.setCharacter(!player.isAI() ? character :
			    _charLoader.getNextCharacter(game::SELECT_BEGIN));
	_menu.setButtonPushable(10 + idx, player.isAI());
	player.setIsAI(!player.isAI());
	_infos.setPlayerInfos(idx - 1, player);
	updateCharacter(idx, player);
}

void bomb::scene::SceneCharacterMenu::changeCharacter(int idx)
{
	PlayerInfo player = _infos.getPlayerInfos(idx - 1);

	if (!player.isAI()) {
		player.setCharacter(_charLoader.getNextCharacter(
			player.getCharacter()));
		_infos.setPlayerInfos(idx - 1, player);
		updateCharacter(idx, player);
	}
}

void bomb::scene::SceneCharacterMenu::updateCharacter(int idx,
						      PlayerInfo player)
{
	_menu.setElementText(10 + idx, _charLoader.getCharacterName(
		player.getCharacter()));
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

void bomb::scene::SceneCharacterMenu::clean(IAssetLoader &loader)
{
	_menu.clean();
	(void) loader;
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
