//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Map.cpp
//

#include "Map.hpp"

bomb::Map::Map(int _size) : _size(_size)
{
	setSize(_size);
}

void bomb::Map::addWalls()
{
	for (unsigned int i = 0; i < _size; ++i) {
		(*this)[irr::core::vector2di(0, i)] = UNBREAKABLE;
		(*this)[irr::core::vector2di(i, 0)] = UNBREAKABLE;
		(*this)[irr::core::vector2di(_size - 1, i)] = UNBREAKABLE;
		(*this)[irr::core::vector2di(i, _size - 1)] = UNBREAKABLE;
	}
}

int bomb::Map::getSize() const
{
	return _size;
}

void bomb::Map::setSize(int size)
{
	Map::_size = size;
	_cells.resize(static_cast<unsigned long>(pow(_size, 2)), EMPTY);
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
		bomb::Exception("Map",
		std::string("Invalid index : ") + std::to_string(pos.X)
		+ " , " + std::to_string(pos.Z));
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

void bomb::Map::clean()
{
	fill(_cells.begin(), _cells.end(), Map::EMPTY);
}

std::ostream &operator<<(std::ostream &os, const bomb::Map &map)
{
	int  i = 0;
	for (auto cell : map.getCells()) {
		os << " " << cell;
		++i;
		if (i % map.getSize() == 0)
			os << "\n";
	}
	return os;
}
