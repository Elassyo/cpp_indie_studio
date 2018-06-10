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
	_player = 0;
	_ctrl = IPlayerController::NONE;
	_keys = _infos.getPlayerInfos(0).getKeys();
	_menu.createMenu(loader);
	_menu.addImage(loader.loadTexture("images/menuBack.png"), {.5, .5}, 5);
	_menu.setElementSize(5, {1, 1});
	_menu.addText((wchar_t *)L"SUPER\nBOMBERMARIO\nBROS.", {.5, .15}, 0);
	_menu.setElementFont(0, menu::TITLE);
	_menu.addButton(L"Player 1", {.5, .35}, 1);
	_menu.setButtonEvent(1, [this](){
		changePlayer();
	});
	_menu.addButton(L"Back", {.5, .75}, 3);
	_menu.setButtonEvent(3, [this](){
		_nextScene = "option_scene";
		_running = false;
	});
	createKeyButtons();
	updateKeys();
	_menu.updateButtons(loader, true);
	return BEGIN;
}

void bomb::scene::SceneKeyMenu::createKeyButtons()
{
	_menu.addButton(L"Key UP", {.33, .45}, 6);
	_menu.setButtonEvent(6, [this](){
		_ctrl = IPlayerController::MV_UP;
	});
	_menu.addButton(L"Key DOWN", {.33, .65}, 7);
	_menu.setButtonEvent(7, [this](){
		_ctrl = IPlayerController::MV_DOWN;
	});
	_menu.addButton(L"Key LEFT", {.66, .45}, 8);
	_menu.setButtonEvent(8, [this](){
		_ctrl = IPlayerController::MV_LEFT;
	});
	_menu.addButton(L"Ley RIGHT", {.66, .65}, 9);
	_menu.setButtonEvent(9, [this](){
		_ctrl = IPlayerController::MV_RIGHT;
	});
	_menu.addButton(L"Key BOMB", {.5, .55}, 10);
	_menu.setButtonEvent(10, [this](){
		_ctrl = IPlayerController::PUT_BOMB;
	});
}

void bomb::scene::SceneKeyMenu::changePlayer()
{
	_ctrl = IPlayerController::NONE;
	_player = _player >= 3 ? 0 : _player + 1;
	_keys = _infos.getPlayerInfos(_player).getKeys();
	_menu.setElementText(1, std::wstring(
		L"Player " + std::to_wstring(_player + 1)).c_str());
	updateKeys();
}

void bomb::scene::SceneKeyMenu::setActionKey(const irr::SEvent &event)
{
	PlayerInfo player = _infos.getPlayerInfos(_player);
	for (auto &key : _keys)
		if (key.second == _ctrl)
			_keys.erase(key.first);
	_keys[event.KeyInput.Key] = _ctrl;
	player.setKeys(_keys);
	_infos.setPlayerInfos(_player, player);
	updateKey(_ctrl);
	_ctrl = IPlayerController::NONE;
}

void bomb::scene::SceneKeyMenu::updateKey(IPlayerController::Actions action)
{
	if (action == IPlayerController::MV_UP)
		_menu.setElementText(6, std::wstring(L"Key UP\n   ").append(
			_keyToStr[getKeyByAction(action)]).c_str());
	if (action == IPlayerController::MV_DOWN)
		_menu.setElementText(7, std::wstring(L"Key DOWN\n   ").append(
			_keyToStr[getKeyByAction(action)]).c_str());
	if (action == IPlayerController::MV_LEFT)
		_menu.setElementText(8, std::wstring(L"Key LEFT\n   ").append(
			_keyToStr[getKeyByAction(action)]).c_str());
	if (action == IPlayerController::MV_RIGHT)
		_menu.setElementText(9, std::wstring(L"Key RIGHT\n   ").append(
			_keyToStr[getKeyByAction(action)]).c_str());
	if (action == IPlayerController::PUT_BOMB)
		_menu.setElementText(10, std::wstring(L"Key BOMB\n   ").append(
			_keyToStr[getKeyByAction(action)]).c_str());
}

void bomb::scene::SceneKeyMenu::updateKeys()
{
	_menu.setElementText(6, std::wstring(L"Key UP\n   ").append(
			_keyToStr[getKeyByAction(IPlayerController::MV_UP)])
		.c_str());
	_menu.setElementText(7, std::wstring(L"Key DOWN\n   ").append(
			_keyToStr[getKeyByAction(IPlayerController::MV_DOWN)])
		.c_str());
	_menu.setElementText(8, std::wstring(L"Key LEFT\n   ").append(
			_keyToStr[getKeyByAction(IPlayerController::MV_LEFT)])
		.c_str());
	_menu.setElementText(9, std::wstring(L"Key RIGHT\n   ").append(
			_keyToStr[getKeyByAction(IPlayerController::MV_RIGHT)])
		.c_str());
	_menu.setElementText(10, std::wstring(L"Key BOMB\n   ").append(
			_keyToStr[getKeyByAction(IPlayerController::PUT_BOMB)])
		.c_str());
}

irr::EKEY_CODE bomb::scene::SceneKeyMenu::getKeyByAction(
	bomb::IPlayerController::Actions action)
{
	for (auto &key : _keys)
		if (key.second == action)
			return key.first;
	return irr::EKEY_CODE::KEY_KEY_CODES_COUNT;
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
	if (_ctrl != IPlayerController::NONE
	    && event.EventType == irr::EET_KEY_INPUT_EVENT)
		setActionKey(event);
	if (event.EventType == irr::EET_MOUSE_INPUT_EVENT)
		return false;
	_menu.handleEvent(event);
	return true;
}
