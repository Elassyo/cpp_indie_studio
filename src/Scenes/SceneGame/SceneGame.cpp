
//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// SceneLauncher.cpp
//

#include "SceneGame.hpp"

bomb::scene::SceneGame::SceneGame(bomb::PersistentInfo &_infos) :
	AScene(_infos), _game(_infos), _running(true)
{
}

bomb::scene::SceneStatus bomb::scene::SceneGame::start(IAssetManager &loader)
{
	_charLoader.loadImages(loader);
	_menu.createMenu(loader);
	_menu.addText(L"", {.5f, .45f}, 1);
	_menu.setElementFont(1, menu::TITLE);
	_menu.addImage(loader.loadTexture("images/empty.png"), {.5f, .55f}, 2);
	_menu.setElementSize(2, {.1f, .1f});
	_menu.setElementRenderMode(2, menu::GraphicElement::HEIGHT_BASED);
	auto plane = loader.createPlaneObject({0, 0, 0}, {100, 100, 100});
	plane->setTexture(0, loader.loadTexture("images/grass.png"));
	_playing = true;
	_camera = loader.getCamera();
	createGame(loader);
	float mid = (float)(_game.getMapSize() - 1) / 2;
	_camera->setPos({mid, (float)_game.getMapSize() * 0.8f,
		(float)_game.getMapSize() * 0.8f});
	_camera->setTarget({mid, 0, mid + 1});
	loadSounds(loader);
	_menu.updateButtons(loader, true);
	return BEGIN;
}

void bomb::scene::SceneGame::createGame(IAssetManager &loader)
{
	if(_infos.generateMap())
		_game.createGame(loader);
	else
		_game.createGame(loader, _infos.getFileName());
	_infos.setGenerateMap(true);

}

bomb::scene::SceneStatus bomb::scene::SceneGame::loop(
	bomb::IAssetManager &loader)
{
	_menu.updateButtons(loader, true);
	explodeBombs(loader);
	_game.execute(loader);
	if (_playing)
		checkVictory();
	if (_running)
		return CONTINUE;
	return END;
}

void bomb::scene::SceneGame::loadSounds(IAssetManager &loader)
{
	_charLoader.loadSounds(loader);
	loader.loadAudioFile("sfx/boom.ogg");
	loader.loadAudioFile("sfx/ploop.ogg");
	loader.loadAudioFile("music/mario64-bobomb-battlefield.ogg");
	loader.playMusic("music/mario64-bobomb-battlefield.ogg");
}

void bomb::scene::SceneGame::explodeBombs(bomb::IAssetManager &loader)
{
	for (auto &bomb : _bombs)
		bomb.get()->tryToActivate(*_game.getMap(),
		_game.getPlayers(), loader);
	(void) loader;
}

void bomb::scene::SceneGame::checkVictory()
{
	int alive = 0;
	auto &players = _game.getPlayers();
	for (auto &player : players)
		alive += player.isAlive();
	if (alive > 1)
		return;
	_playing = false;
	for (unsigned int i = 0; i < players.size(); ++i)
		if (players[i].isAlive()) {
			_menu.setElementText(
				1, players[i].isAI() ? L"GAME OVER" :
				   std::wstring(
					   L"PLAYER " + std::to_wstring(i + 1))
					   .append(L"\nVICTORY").c_str());
			_menu.setElementTexture(
				2, _charLoader.getCharacterTexture(_infos.
					getPlayerInfos(i).getCharacter()));
		}
	if (!alive)
		_menu.setElementText(1, L"IT'S A DRAW");
}

void bomb::scene::SceneGame::save()
{
	xml::XmlWriter xmlWriter(_infos.getFileName());

	xmlWriter.mapToSection(_game.getMap());
	for (size_t i = 0; i < _game.getPlayers().size(); i++) {
		xmlWriter.playerToSection(_game.getPlayers()[i],
		_infos.getPlayerInfos(i));
	}
}

void bomb::scene::SceneGame::reset(bomb::IAssetManager &loader)
{
	(void) loader;
}

void bomb::scene::SceneGame::clean(IAssetManager &loader)
{
	_menu.clean();
	_game.clean(loader);
	loader.stopAll();
	_game.getMap()->clean(loader);
	auto &p = _game.getPlayers();
	for (unsigned int i = 0; i < _game.getPlayers().size(); ++i) {
		p[i].setAlive(false, loader);
	}
	_camera.reset(nullptr);
	_running = true;
}

std::string bomb::scene::SceneGame::nextScene()
{
	return "home_scene";
}

bool bomb::scene::SceneGame::onEvent(const irr::SEvent &event)
{
	if (event.EventType == irr::EET_KEY_INPUT_EVENT) {
		_game.handleEvent(event);
		if (event.KeyInput.Key == irr::KEY_ESCAPE)
			_running = false;
		if (event.KeyInput.Key == irr::KEY_RETURN)
			this->save();
		move_camera(event);
	}

	return true;
}

void bomb::scene::SceneGame::move_camera(const irr::SEvent &event)
{
	auto pos = _camera->getPos();
	switch (event.KeyInput.Key) {
	case irr::KEY_BACK:
		_camera->setPos({pos.X + 0.1f, pos.Y, pos.Z});
		break;
	case irr::KEY_HOME:
		_camera->setPos({pos.X - 0.1f, pos.Y, pos.Z});
		break;
	case irr::KEY_PRIOR:
		_camera->setPos({pos.X, pos.Y + 0.1f, pos.Z});
		break;
	case irr::KEY_NEXT:
		_camera->setPos({pos.X, pos.Y - 0.1f, pos.Z});
		break;
	case irr::KEY_F1:
		_camera->setPos(pos + 1);
		break;
	case irr::KEY_F2:
		_camera->setPos(pos - 1);
		break;
	default:
		break;
	}
}
