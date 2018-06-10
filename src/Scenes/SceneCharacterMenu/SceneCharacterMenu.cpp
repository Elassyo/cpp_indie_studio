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
	IAssetManager &loader)
{
	_running = true;
	initModelPaths();
	_menu.createMenu(loader);
	_menu.addImage(loader.loadTexture("images/menuBack.png"),
		{.5f, .5f}, 5);
	_menu.setElementSize(5, {1, 1});
	_menu.addText(L"SUPER\nBOMBERMARIO\nBROS.", {.5f, .15f}, 0);
	_menu.setElementFont(0, menu::TITLE);
	addGameButtons();
	addPlayerButtons();
	addCharacterButtons(loader);
	_menu.updateButtons(loader, true);
	_charLoader.loadImages(loader);
	for (int i = 0; i < 4; ++i)
		updateCharacter(i + 1, _infos.getPlayerInfos().at(i));
	return BEGIN;
}

void bomb::scene::SceneCharacterMenu::initModelPaths()
{
	auto players = _infos.getPlayerInfos();
	if (players[1].getCharacter() == game::SHYGUY_WHITE)
		players[1].setCharacter(bomb::game::SHYGUY_BLACK);
	if (players[2].getCharacter() == game::SHYGUY_WHITE)
		players[2].setCharacter(bomb::game::SHYGUY_BLUE);
	if (players[3].getCharacter() == game::SHYGUY_WHITE)
		players[3].setCharacter(bomb::game::SHYGUY_RED);
	_infos.setPlayerInfos(players);
}

void bomb::scene::SceneCharacterMenu::addPlayerButtons()
{
	_menu.addButton(_infos.getPlayerInfos(0).isAI() ?
			L"1 : AI" : L"1: Player", {.20f, .33f}, 1);
	_menu.setButtonEvent(1, [this](){
		changePlayerType(1, bomb::game::SHYGUY_WHITE);
	});
	_menu.addButton(_infos.getPlayerInfos(1).isAI() ?
			L"2 : AI" : L"2: Player", {.40f, .33f}, 2);
	_menu.setButtonEvent(2, [this](){
		changePlayerType(2, bomb::game::SHYGUY_BLACK);
	});
	_menu.addButton(_infos.getPlayerInfos(2).isAI() ?
			L"3 : AI" : L"3: Player", {.60f, .33f}, 3);
	_menu.setButtonEvent(3, [this](){
		changePlayerType(3, bomb::game::SHYGUY_BLUE);
	});
	_menu.addButton(_infos.getPlayerInfos(3).isAI() ?
			L"4 : AI" : L"4: Player", {.80f, .33f}, 4);
	_menu.setButtonEvent(4, [this](){
		changePlayerType(4, bomb::game::SHYGUY_RED);
	});
}

void bomb::scene::SceneCharacterMenu::addCharacterButtons(
	IAssetManager &manager)
{
	for (int i = 0; i < 4; ++i) {
		_menu.addButton(_charLoader.getCharacterName(
			_infos.getPlayerInfos(i).getCharacter()),
				{.20f * (i + 1), .5f}, 10 + i + 1);
		_menu.setElementSize(10 + i + 1, {.15f, .15f});
		_menu.setElementRenderMode(10 + i + 1,
			bomb::menu::GraphicElement::HEIGHT_BASED);
		_menu.setButtonPushable(
			10 + i + 1, !_infos.getPlayerInfos(i).isAI());
	}
	_menu.setButtonEvent(11, [this](){
		changeCharacter(1);
	});
	_menu.setButtonEvent(12, [this](){
		changeCharacter(2);
	});
	_menu.setButtonEvent(13, [this](){
		changeCharacter(3);
	});
	_menu.setButtonEvent(14, [this](){
		changeCharacter(4);
	});
	(void)manager;
}

void bomb::scene::SceneCharacterMenu::changePlayerType(
	int idx, game::Character character)
{
	PlayerInfo player = _infos.getPlayerInfos(idx - 1);

	_menu.setElementText(idx, std::wstring(
		std::to_wstring(idx) + L" : "
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
	_menu.setButtonTextures(10 + idx,
		_charLoader.getCharacterTexture(player.getCharacter()),
		_charLoader.getCharacterTexture(player.getCharacter()));
}

void bomb::scene::SceneCharacterMenu::addGameButtons()
{
	_menu.addButton(L"New Game", {.25f, .75f}, 6);
	_menu.setButtonEvent(6, [this](){
		_nextScene = "game_scene";
		_running = false;
	});
	_menu.addButton(L"Load Game", {.5f, .75f}, 7);
	_menu.setButtonEvent(7, [this](){
		_nextScene = "game_scene";
		_running = false;
	});
	_menu.addButton(L"Back", {.75f, .75f}, 8);
	_menu.setButtonEvent(8, [this](){
		_nextScene = "home_scene";
		_running = false;
	});
}

bomb::scene::SceneStatus bomb::scene::SceneCharacterMenu::loop(
	bomb::IAssetManager &loader)
{
	_menu.updateButtons(loader, true);
	return _running ? CONTINUE : END;
}

void bomb::scene::SceneCharacterMenu::save()
{
}

void bomb::scene::SceneCharacterMenu::reset(bomb::IAssetManager &loader)
{
	(void) loader;
}

void bomb::scene::SceneCharacterMenu::clean(IAssetManager &loader)
{
	if (_nextScene == "game_scene") {
		loader.stopAll();
		_infos.setMainMusic(false);
	}
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
