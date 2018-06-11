/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** Game.cpp
*/

#include "Game.hpp"

bomb::game::Game::Game(bomb::PersistentInfo &infos) :
	_infos(infos), _charLoader(),
	_strBlk({{L"Bomb", BomberMap::BlockType::BOMB},
		 {L"Breakable",
			   BomberMap::BlockType::BREAKABLE},
		 {L"Unbreakable",
			   BomberMap::BlockType::UNBREAKABLE},
		 {L"Empty", BomberMap::BlockType::EMPTY}})
{
}

void bomb::game::Game::createGame(bomb::IAssetManager &loader,
				  const std::string &fileName)
{
	xml::XmlReader xmlReader(fileName);
	unsigned int i = 0;

	while (xmlReader.read()) {
		if (xmlReader.getActualSection() == L"BomberMap")
			createMap(loader, xmlReader);
		if (xmlReader.getNodeName() == L"PlayerInfo") {
			PlayerInfo player = _infos.getPlayerInfos(i);
			player.setCharacter(
				(Character)xmlReader.getIntValue(L"character"));
			player.setIsAI((bool)xmlReader.getIntValue(L"isAI"));
			_infos.setPlayerInfos(i, player);
			createPlayer(loader, _charLoader.getCharacterPath(
				_infos.getPlayerInfos(i).getCharacter()),
					{xmlReader.getIntValue(L"x"), 0,
					xmlReader.getIntValue(L"z")}, i);
			setPlayerAttributes(loader, xmlReader, i);
			i++;
		}
	}
}

void bomb::game::Game::setPlayerAttributes(bomb::IAssetManager &loader,
					   xml::XmlReader &xmlReader, int i)
{
	_players[i].setAlive((bool)xmlReader.getIntValue(L"isAlive"), loader);
	_players[i].setAI((bool)xmlReader.getIntValue(L"isAI"));
	_players[i].setGhostMode((bool)xmlReader.getIntValue(L"isGhost"));
	_players[i].setGhostMode((bool)xmlReader.getIntValue(L"isBombGhost"));
	_players[i].setSpeed(xmlReader.getFloatValue(L"speed"));
	_players[i].setBombRange((uint8_t)xmlReader.getIntValue(L"range"));
	_players[i].setNbBombs((uint8_t)xmlReader.getIntValue(L"nbBombs"));
}

void bomb::game::Game::createMap(bomb::IAssetManager &loader,
				 bomb::xml::XmlReader &xmlReader)
{
	MapConstructor mapConstructor((unsigned)xmlReader.getIntValue(L"size"));
	irr::core::vector2di pos;

	while (xmlReader.read()) {
		if (xmlReader.getActualSection() != L"BomberMap")
			break;
		if (_strBlk.find(xmlReader.getNodeName()) != _strBlk.end()
		    && xmlReader.getNodeName() != L"Empty") {
			pos.X = xmlReader.getIntValue(L"x");
			pos.Y = xmlReader.getIntValue(L"y");
			mapConstructor.addBlock(
				pos, _strBlk[xmlReader.getNodeName()]);
		}
	}
	_mapSize = mapConstructor.getSize();
	_infos.setMapSize(mapConstructor.getSize());
	_map = mapConstructor.construct(loader, {0, 0, 0}, {1, 1, 1}, {0, 0, 0});
	loader.createLightObject({(float)_mapSize / 2,
				  (float)_mapSize, (float)_mapSize / 2},
				 {1.0f, 1.0f, 1.0f}, (float)_mapSize);
}

void bomb::game::Game::createGame(IAssetManager &loader)
{
	createMap(loader, _infos.getMapSize());
	for (unsigned int i = 0; i < 4; ++i) {
		createPlayer(loader, _charLoader.getCharacterPath(
			_infos.getPlayerInfos(i).getCharacter()),
			     {i % 2 ? 1 : _infos.getMapSize() - 2, 0,
			      i > 1 ? _infos.getMapSize() - 2 : 1}, i);
	}
}

void bomb::game::Game::createMap(
	bomb::IAssetManager &loader, unsigned int size)
{
	bomb::MapConstructor pattern = MapGenerator(size).generate();

	_mapSize = pattern.getSize();
	_map = std::move(pattern.construct(loader, {0, 0, 0},
		{1, 1, 1}, {0, 0, 0}));
	auto light = loader.createLightObject(
		{(float)pattern.getSize() / 2,
		 (float)pattern.getSize(), (float)pattern.getSize() / 2},
		{1.0f, 1.0f, 1.0f}, (float)pattern.getSize());
}

void bomb::game::Game::createPlayer(IAssetLoader &loader,
			const std::string &path,
			const irr::core::vector3di &spawn,
			unsigned int index)
{
	if (index >= NB_PLAYERS)
		throw bomb::Exception("GameCreation", "Too much players");
	auto &pInfos = _infos.getPlayerInfos()[index];
	_players[index] = bomb::game::Player(
		loader, path, {(float)spawn.X, (float)spawn.Y, (float)spawn.Z},
		{.5, .5, .5}, {0, 0, 0}, pInfos);
	_players[index].setKeys(_infos.getPlayerInfos(index).getKeys());
	_playersActionners[index] = bomb::PlayerActionner(!pInfos.isAI());
}

void bomb::game::Game::reset()
{
}


int bomb::game::Game::getMapSize() const
{
	return _mapSize;
}

void bomb::game::Game::execute(bomb::IAssetManager &loader)
{
	executePlayers(loader);
	executePowers(loader);
	executeBombs(loader);
	executeBlast(loader);
}

void bomb::game::Game::executeBlast(bomb::IAssetManager &manager)
{
	auto blast = _explosionBlasts.begin();
	for (;blast != _explosionBlasts.end();) {
		if (blast->isFinished()) {
			manager.deleteObject(blast->releasePtr());
			blast = _explosionBlasts.erase(blast);
		} else {
			blast->scaleDown();
			blast++;
		}
	}
}

void bomb::game::Game::executePowers(bomb::IAssetManager &loader)
{
	auto p = _powers.begin();
	while (p != _powers.end()) {
		if ((*p)->tryToActivate(*_map, _players, loader)) {
			p = _powers.erase(p);
		} else
			p++;
	}
}

void bomb::game::Game::executePlayers(bomb::IAssetManager &loader)
{
	for (auto i = 0; i < NB_PLAYERS; ++i) {
		if (!_players[i].isAlive())
			continue;
		if (_players[i].isAI() && _players[i].isAlive())
			_controller.executeAI(
				_playersActionners[i], _players, *_map, i);
		_playersActionners[i].actionnate(*_map, _players[i]);
		if (_players[i].isBombReady()) {
			_bombs.emplace_back(new bomb::object::Bomb
				(loader, _players[i], i));
			_players[i].setBombReady(false);
		}
	}

}

void bomb::game::Game::executeBombs(bomb::IAssetManager &loader)
{
	auto bomb = _bombs.begin();
	_map->getBombRanges().clean();
	while (bomb != _bombs.end()) {
		unsigned int idx = (unsigned int)(*bomb)->getPlayerIdx();
		(*bomb)->addBlastToMap(*_map, _players.at(idx));
		if ((*bomb)->tryToActivate(*_map, _players, loader)) {
			auto blast = (*bomb)->getBlast();
			_map->updateFromCells(loader);
			blastObjects(blast, loader);
			spawnPowers(blast, loader);
			bomb = _bombs.erase(bomb);
		} else
			bomb++;
	}
}

void bomb::game::Game::spawnPowers(
	std::vector<std::pair<irr::core::vector2di,
		bomb::BomberMap::BlockType>> &blast,
	IAssetManager &loader)
{
	for (auto b : blast) {
		if (b.second == BomberMap::BREAKABLE &&
		    rand() % 100 <= RATIO_POWERS)
			_powers.emplace_back(_factory.getRandomPower(loader,
				{static_cast<irr::f32>(b.first.X), 0,
				static_cast<irr::f32>(b.first.Y)}));
	}
}

void bomb::game::Game::blastObjects(
	std::vector<std::pair<irr::core::vector2di,
	bomb::BomberMap::BlockType>> blast,
	bomb::IAssetManager &manager)
{
	for (auto &b : blast) {
		auto p = manager.createBillboardObject(
			{(float) b.first.X, 0.5f, (float) b.first.Y},
			{3.f, 3.f});
		p->setTexture(0, manager.loadTexture("images/explosion.png"));
		_explosionBlasts.emplace_back(object::ExplosionBlast(
			std::move(p)));
		killPlayersInBlast(b.first, manager);
		killPowersInBlast(b.first, manager);
		fuseBombInBlast(b.first);
	}
}

void bomb::game::Game::killPowersInBlast(irr::core::vector2di pos,
	bomb::IAssetManager &manager)
{
	auto p = _powers.begin();
	while (p != _powers.end()) {
		auto powerPos = p->get()->getPos();
		if (powerPos == pos) {
			p->get()->destroy(manager);
			p = _powers.erase(p);
		} else
			++p;
	}
}

void bomb::game::Game::fuseBombInBlast(irr::core::vector2di pos)
{
	for (auto &b : _bombs)
		if (b->getPos() == pos)
			b->fuse();
}

void bomb::game::Game::killPlayersInBlast(irr::core::vector2di pos,
	bomb::IAssetManager &loader)
{
	for (unsigned int i = 0; i < _players.size(); ++i) {
		if (!_players.at(i).isAlive())
			continue;
		irr::core::vector2di playerPos(
			static_cast<irr::s32>(_players[i].getExactPos().X),
			static_cast<irr::s32>(_players[i].getExactPos().Z));
		if (playerPos == pos) {
			_players[i].getModel()->playSound(
				_charLoader.getHitSfxPath(
					_infos.getPlayerInfos(i)
						.getCharacter()));
			_players[i].setAlive(false, loader);
		}
	}
}

bool bomb::game::Game::handleEvent(const irr::SEvent &event)
{
	for (unsigned int i = 0; i < NB_PLAYERS; ++i) {
		if (_players[i].isAI() || !_players[i].isAlive())
			continue;
		auto action = _players[i].getActionFromEvent(event);
		if (action != IPlayerController::UNDEFINED) {
			if (event.KeyInput.PressedDown)
				_playersActionners[i]
					.sendAction(*_map, _players[i], action);
			else
				_playersActionners[i].removeAction(action);
		}
	}
	return true;
}

std::array<bomb::game::Player, 4> &bomb::game::Game::getPlayers()
{
	return _players;
}

std::shared_ptr<bomb::BomberMap> &bomb::game::Game::getMap()
{
	return _map;
}

void bomb::game::Game::clean(IAssetManager &loader)
{
	for (auto &power : _powers)
		power->destroy(loader);
	for (auto &bomb : _bombs)
		bomb->destroy(loader);
	_powers.clear();
	_bombs.clear();
}
