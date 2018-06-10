//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// BomberMap.cpp
//

#include "BomberMap.hpp"
#include "../Exception/Exception.hpp"

bomb::BomberMap::BomberMap(const std::vector<std::shared_ptr<bomb::AMapBlock>> &_blocks,
	std::vector<BomberMap::BlockType> &cells) :
	_blocks(_blocks)
{
	_cells = cells;
	setSize(static_cast<int>(sqrt(cells.size())));
}

bool bomb::BomberMap::blockAt(const irr::core::vector2di &coord)
{
	return _cells[coord.X + coord.Y * _size] != BlockType::EMPTY;
}

void bomb::BomberMap::updateFromCells(bomb::IAssetManager &loader)
{
	auto b = _blocks.begin();
	while (b != _blocks.end()) {
		if (_cells[b->get()->getMapPos().X
			+ b->get()->getMapPos().Y * _size] == EMPTY) {
			b->get()->explode(b->get()->getHp(), loader);
			b = _blocks.erase(b);
		} else
			b++;
	}
}

void bomb::BomberMap::clean(bomb::IAssetManager &loader)
{
	fill(_cells.begin(), _cells.end(), BomberMap::EMPTY);
	updateFromCells(loader);
}
