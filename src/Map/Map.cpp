//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Map.cpp
//

#include "Map.hpp"
#include "../Exception/Exception.hpp"

bomb::Map::Map(const std::vector<std::shared_ptr<bomb::AMapBlock>> &_blocks,
	std::vector<Map::BlockType> &cells) :
	_blocks(_blocks), _cells(cells),
	_size(static_cast<int>(sqrt(cells.size())))
{
}

void bomb::Map::setTextures(irr::video::ITexture *texture)
{
	for (auto &blocks : _blocks) {
		blocks->setTextures(texture);
	}
}

int bomb::Map::getSize() const {
	return _size;
}

void bomb::Map::setSize(int size) {
	Map::_size = size;
}

bomb::Map::BlockType &bomb::Map::operator[](std::size_t idx)
{
	return _cells[idx];
}

bomb::Map::BlockType &bomb::Map::operator[](irr::core::vector3di &pos)
{
	auto idx = pos.X + pos.Z * _size;
	if ((unsigned int)idx < _cells.size())
		return _cells[idx];
	throw
		bomb::Exception("Map", "Invalid index");
}

bomb::Map::BlockType &bomb::Map::operator[](irr::core::vector3df pos)
{
	auto idx = static_cast<unsigned int>(pos.X + pos.Z * _size);
	if (idx < _cells.size())
		return _cells[idx];
	throw
		bomb::Exception("Map", "Invalid index");
}

bool bomb::Map::blockAt(const irr::core::vector2di &coord)
{
	return _cells[coord.X + coord.Y * _size] != BlockType::EMPTY;
}

const std::vector<bomb::Map::BlockType> &bomb::Map::getCells() const
{
	return _cells;
}

std::ostream &operator<<(std::ostream &os, const bomb::Map &map) {
	int  i = 0;
	for (auto cell : map.getCells()) {
		os << " " << cell;
		++i;
		if (i % map.getSize() == 0)
			os << "\n";
	}
	return os;
}

void bomb::Map::updateFromCells(bomb::IAssetLoader &loader)
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
