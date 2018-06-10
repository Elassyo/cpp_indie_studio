//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Map.cpp
//

#include "Map.hpp"

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

bomb::Map::BlockType &bomb::Map::operator[](irr::core::vector3di pos)
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

bomb::Map::BlockType &bomb::Map::operator[](irr::core::vector2di pos)
{
	auto idx = pos.X + pos.Y * _size;
	if ((unsigned int)idx < _cells.size())
		return _cells[idx];
	throw
		bomb::Exception("Map", "Invalid index");
}

bomb::Map::BlockType &bomb::Map::operator[](irr::core::vector2df pos)
{
	auto idx = static_cast<unsigned int>(pos.X + pos.Y * _size);
	if (idx < _cells.size())
		return _cells[idx];
	throw
		bomb::Exception("Map", "Invalid index");
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

void bomb::Map::clean()
{
	fill(_cells.begin(), _cells.end(), Map::EMPTY);
}
