//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Bomb.cpp
//

#include "Bomb.hpp"

bomb::object::Bomb::Bomb(bomb::IAssetManager &loader,
			 bomb::game::Player &player,
			int playerIdx) :
	_loader(loader),
	_model(loader.createAnimatedObject(
	"models/bob-bomb.x", player.getExactPos(), {.5, .5, .5})),
	_timer(2000), _playerIdx(playerIdx)
{
}

bool bomb::object::Bomb::deleteBlock(bomb::Map &map, irr::core::vector3di pos)
{
	auto last = map[pos];
	if (map[pos] == Map::BREAKABLE)
		map[pos] = Map::EMPTY;
	if (map[pos] == Map::UNBREAKABLE || map[pos] == Map::BOMB)
		return false;
	_blast.emplace_back(irr::core::vector2di(pos.X, pos.Z), last);
	return last == Map::EMPTY;
}

bool bomb::object::Bomb::blastLine(bomb::Map &map, irr::core::vector3di pos,
				   irr::core::vector2di iterator, int max)
{
	for (auto i = 0; i < max; ++i) {
		pos.X += iterator.X;
		pos.Z += iterator.Y;
		if (!deleteBlock(map, pos))
			return true;
	}
	return true;
}

bool bomb::object::Bomb::activate(bomb::Map &map, bomb::game::Player &player,
				  IAssetManager &loader)
{
	irr::core::vector3di pos = {static_cast<irr::s32>(_model->getPos().X),
				    static_cast<irr::s32>(_model->getPos().Y),
				    static_cast<irr::s32>(_model->getPos().Z)};
	map[pos] = Map::EMPTY;
	deleteBlock(map, pos);
	_loader.deleteObject(std::move(_model));
	player.setNbBombs(static_cast<uint8_t>(player.getNbBombs() + 1));
	blastLine(map, pos, {1, 0}, player.getBombRange());
	blastLine(map, pos, {0, 1}, player.getBombRange());
	blastLine(map, pos, {0, -1}, player.getBombRange());
	blastLine(map, pos, {-1, 0}, player.getBombRange());
	return true;
	(void) loader;
}

int bomb::object::Bomb::isActivable(bomb::Map &map,
	std::vector<std::pair<bomb::game::Player,
		bomb::PlayerActionner>> &player)
{
	if (_timer.isReady())
		return _playerIdx;
	return -1;
	(void) map;
	(void) player;
}

const std::vector<std::pair<irr::core::vector2di, bomb::Map::BlockType>>
&bomb::object::Bomb::getBlast() const
{
	return _blast;
}