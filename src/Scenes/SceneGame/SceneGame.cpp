
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
	_charLoader.loadSounds(loader);
	_menu.createMenu(loader);
	_menu.addText(L"", {.5, .45}, 1);
	_menu.setElementFont(1, menu::TITLE);
	_menu.addImage(loader.loadTexture("images/empty.png"), {.5, .55}, 2);
	_menu.setElementSize(2, {.1, .1});
	_menu.setElementRenderMode(2, menu::GraphicElement::HEIGHT_BASED);
	_playing = true;
	_blocksTextures = loader.loadTexture("models/blocks/spritesheet.png");
	_game.createGame(loader, _blocksTextures);
	auto cam = loader.getCamera();
	float mid = (float)(_game.getMapSize() - 1) / 2;
	cam->setPos({mid, (float)_game.getMapSize() * 0.8f,
		(float)_game.getMapSize() * 0.8f});
	cam->setTarget({mid, 0, mid + 1});
	loader.loadAudioFile("sfx/boom.ogg");
	loader.loadAudioFile("music/mario64-bobomb-battlefield.ogg");
	loader.playMusic("music/mario64-bobomb-battlefield.ogg");
	_menu.updateButtons(loader, true);
	return BEGIN;
}

bomb::scene::SceneStatus bomb::scene::SceneGame::loop(
	bomb::IAssetManager &loader)
{
	explodeBombs(loader);
	_game.execute(loader);
	if (_playing)
		checkVictory();
	if (_running)
		return CONTINUE;
	loader.stopAll();
	return END;
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
		alive += player.first.isAlive();
	if (alive > 1)
		return;
	_playing = false;
	for (unsigned int i = 0; i < players.size(); ++i)
		if (players[i].first.isAlive()) {
			_menu.setElementText(
				1, players[i].first.isAI() ? L"GAME OVER" :
				   std::wstring(
					   L"PLAYER " + std::to_wstring(i + 1))
					   .append(L"\nVICTORY").c_str());
			_menu.setElementTexture(
				2, _charLoader.getCharacterTexture(_infos.
					getPlayerInfos(i).getCharacter()));
		}
	if (!alive)
		_menu.setElementText(1, L"EGALITY");
}

void bomb::scene::SceneGame::save()
{
	xml::XmlWriter xmlWriter("test.xml");

	xmlWriter.mapToSection(_game.getMap());
	for (size_t i = 0; i < _game.getPlayers().size(); i++) {
		xmlWriter.playerToSection(_game.getPlayers()[i].first);
	}
}

void bomb::scene::SceneGame::reset(bomb::IAssetManager &loader)
{
	(void) loader;
}

void bomb::scene::SceneGame::clean(IAssetManager &loader)
{
	_menu.clean();
	loader.stopAll();
	_charLoader.unloadSounds(loader);
	loader.unloadAudioFile("sfx/boom.ogg");
	loader.unloadAudioFile("music/mario64-bobomb-battlefield.ogg");
	_game.getMap()->clean(loader);
	auto &p = _game.getPlayers();
	for (unsigned int i = 0; i < _game.getPlayers().size(); ++i) {
		p[i].first.setAlive(false, loader);
	}
	p.clear();
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
		if (event.KeyInput.Key == irr::KEY_KEY_S)
			this->save();
	}

	return true;
}
