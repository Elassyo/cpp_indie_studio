//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Bomb.cpp
//

#include "Bomb.hpp"

bomb::object::Bomb::Bomb(bomb::IAssetManager &loader,
			 bomb::game::Player &player, int playerIdx) :
	_model(loader.createAnimatedObject("models/bob-bomb.x",
		player.getExactPos(), {.5, .5, .5})),
	_timer(2000), _playerIdx(playerIdx)
{
}

bool bomb::object::Bomb::deleteBlock(bomb::BomberMap &map,
				irr::core::vector3di pos)
{
	if (map[pos] == BomberMap::BREAKABLE) {
		map[pos] = BomberMap::EMPTY;
		return true;
	}
	return true;
}

bool bomb::object::Bomb::isEnd(bomb::BomberMap &map,
			const irr::core::vector3di &pos)
{
	if (map[pos] == BomberMap::UNBREAKABLE)
		return false;
	_blast.emplace_back(irr::core::vector2di(pos.X, pos.Z), map[pos]);
	return map[pos] == BomberMap::EMPTY;
}

bool bomb::object::Bomb::blastLine(bomb::BomberMap &map,
				irr::core::vector3di pos,
				irr::core::vector2di iterator,
				int max, bool blast)
{
	for (auto i = 0; i < max; ++i) {
		pos.X += iterator.X;
		pos.Z += iterator.Y;
		if (!isEnd(map, pos))
			return !blast || deleteBlock(map, pos);
	}
	return true;
}

bool bomb::object::Bomb::activate(bomb::BomberMap &map,
				bomb::game::Player &player,
				IAssetManager &loader)
{
	_model->playSound("sfx/boom.ogg");
	player.setNbBombs(static_cast<uint8_t>(player.getNbBombs() + 1));
	simulateBlast(map, player, true);
	loader.deleteObject(std::move(_model));
	return true;
}

int bomb::object::Bomb::isActivable(bomb::BomberMap &map,
				std::array<bomb::game::Player, 4> &player)
{
	if (_timer.isReady())
		return _playerIdx;
	return -1;
	(void) map;
	(void) player;
};

const std::vector<std::pair<irr::core::vector2di, bomb::BomberMap::BlockType>>
&bomb::object::Bomb::getBlast() const
{
	return _blast;
}

irr::core::position2di bomb::object::Bomb::getPos()
{
	if (_model == nullptr)
		return {-1, -1};
	return {static_cast<irr::s32>(_model->getPos().X),
		static_cast<irr::s32>(_model->getPos().Z)};
}

void bomb::object::Bomb::fuse()
{
	_timer.setTimerInterval(100);
	_timer.reset();
}

void bomb::object::Bomb::addBlastToMap(bomb::BomberMap &map,
				bomb::game::Player &player)
{
	simulateBlast(map, player, false);
	map.addBlast(_blast);
	_blast.clear();
};

void bomb::object::Bomb::simulateBlast(bomb::BomberMap &map,
				bomb::game::Player &player, bool destroy)
{
	irr::core::vector3di pos = {static_cast<irr::s32>(_model->getPos().X),
				    static_cast<irr::s32>(_model->getPos().Y),
				    static_cast<irr::s32>(_model->getPos().Z)};
	if (pos.X == 0 && pos.Y == 0 && pos.Z == 0)
		return;
	map[pos] = BomberMap::EMPTY;
	if (!isEnd(map, pos) && destroy)
		deleteBlock(map, pos);
	blastLine(map, pos, {1, 0}, player.getBombRange(), destroy);
	blastLine(map, pos, {0, 1}, player.getBombRange(), destroy);
	blastLine(map, pos, {0, -1}, player.getBombRange(), destroy);
	blastLine(map, pos, {-1, 0}, player.getBombRange(), destroy);
}

int bomb::object::Bomb::getPlayerIdx() const
{
	return _playerIdx;
}