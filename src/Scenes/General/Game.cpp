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
				  irr::video::ITexture *pTexture,
				  const std::string &fileName)
{
	xml::XmlReader xmlReader(fileName);
	int i = 0;

	while (xmlReader.read()) {
		if (xmlReader.getActualSection() == L"BomberMap")
			createMap(loader, xmlReader);
		if (xmlReader.getNodeName() == L"PlayerInfo") {
			createPlayer(loader, _charLoader.getCharacterPath(
				_infos.getPlayerInfos(i).getCharacter()),
				     std::make_unique<bomb::player::AIController>(_map),
				     {xmlReader.getIntValue(L"x"), 0,
				      xmlReader.getIntValue(L"y")});
			_players.end()->first.setAlive((bool) xmlReader.getIntValue(L"isAlive"), loader);
			_players.end()->first.setAI((bool) xmlReader
				.getIntValue(L"isAI"));
			i++;
		}
	}
}

void
bomb::game::Game::createMap(bomb::IAssetManager &loader,
			    bomb::xml::XmlReader &xmlReader)
{
	MapConstructor mapConstructor(0);
	irr::core::vector2di pos;
	int size = 0;

	while (xmlReader.read()) {
		if (xmlReader.getActualSection() != L"BomberMap")
			return;
		if (_strBlk.find(xmlReader.getNodeName()) != _strBlk.end()) {
			pos.X = xmlReader.getIntValue(L"x");
			pos.Y = xmlReader.getIntValue(L"y");
			mapConstructor.addBlock(
				pos, _strBlk[xmlReader.getNodeName()]);
			++size;
		}
	}
	_mapSize = size;
	_map = mapConstructor.construct(loader, {0, 0, 0}, {1, 1, 1},
					{0, 0, 0});
	loader.createLightObject({(float)_mapSize / 2,
				  (float)_mapSize, (float)_mapSize / 2},
				 {1, 1, 1}, _mapSize);
}

void bomb::game::Game::createGame(IAssetManager &loader,
				  irr::video::ITexture *texture)
{
	createMap(loader, _infos.getMapSize());
	for (int i = 0; i < 4; ++i)
		createPlayer(loader, _charLoader.getCharacterPath(
			_infos.getPlayerInfos(i).getCharacter()),
			     std::make_unique<bomb::player::AIController>(_map),
			     {i % 2 ? 1 : _infos.getMapSize() - 2, 0,
			      i > 1 ? _infos.getMapSize() - 2 : 1});
	reset();
	(void) texture;
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
		{1, 1, 1}, pattern.getSize());
}

void bomb::game::Game::createPlayer(IAssetLoader &loader,
			const std::string &path,
			std::unique_ptr<bomb::IPlayerController> controller,
			const irr::core::vector3di &spawn)
{
	if (_players.size() >= NB_PLAYERS)
		throw bomb::Exception("GameCreation", "Too much players");
	_players.push_back(std::make_pair<Player,PlayerActionner>(
		Player(loader, path, controller,
			{(float)spawn.X, (float)spawn.Y, (float)spawn.Z},
			{.5, .5, .5}, {0, 0, 0},
			_infos.getPlayerInfos()[_players.size()]), {true}));
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
	executeBombs(loader);
	executePowers(loader);
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
		if (!_players[i].first.isAlive())
			continue;
		_players[i].second.actionnate(*_map, _players[i].first);
		if (_players[i].first.isBombReady()) {
			_bombs.emplace_back(new bomb::object::Bomb
				(loader, _players[i].first, i));
			_players[i].first.setBombReady(false);
		}
	}

}

void bomb::game::Game::executeBombs(bomb::IAssetManager &loader)
{
	auto bomb = _bombs.begin();
	while (bomb != _bombs.end()) {
		unsigned int idx = (unsigned int)(*bomb)->getPlayerIdx();
		(*bomb)->addBlastToMap(*_map, _players.at(idx).first);
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
		if (!_players[i].first.isAlive())
			continue;
		irr::core::vector2di playerPos(
			static_cast<irr::s32>(
				_players[i].first.getExactPos().X),
			static_cast<irr::s32>(
				_players[i].first.getExactPos().Z));
		if (playerPos == pos) {
			_players[i].first.getModel()->playSound(
				_charLoader.getHitSfxPath(
					_infos.getPlayerInfos(i)
						.getCharacter()));
			_players[i].first.setAlive(false, loader);
		}
	}
}

bool bomb::game::Game::handleEvent(const irr::SEvent &event)
{
	for (auto &p : _players) {
		if (p.first.isAI() || !p.first.isAlive())
			continue;
		auto action = p.first.getActionFromEvent(event);
		if (action != IPlayerController::UNDEFINED) {
			if (event.KeyInput.PressedDown)
				p.second.sendAction(*_map, p.first, action);
			else
				p.second.removeAction(action);
		}
	}
	return true;
}

std::vector<std::pair<bomb::game::Player, bomb::PlayerActionner>> &
bomb::game::Game::getPlayers()
{
	return _players;
}

std::shared_ptr<bomb::BomberMap> &bomb::game::Game::getMap()
{
	return _map;
}
