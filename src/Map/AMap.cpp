//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AMap.cpp
//

#include "AMap.hpp"

int bomb::AMap::getSize() const {
	return _size;
}

void bomb::AMap::setSize(int size) {
	AMap::_size = size;
}

bomb::AMap::BlockType &bomb::AMap::operator[](std::size_t idx)
{
	return _cells[idx];
}

bomb::AMap::BlockType &bomb::AMap::operator[](irr::core::vector3di pos)
{
	auto idx = pos.X + pos.Z * _size;
	if ((unsigned int)idx < _cells.size())
		return _cells[idx];
	throw
		bomb::Exception("AMap", "Invalid index");
}

bomb::AMap::BlockType &bomb::AMap::operator[](irr::core::vector3df pos)
{
	auto idx = static_cast<unsigned int>(pos.X + pos.Z * _size);
	if (idx < _cells.size())
		return _cells[idx];
	throw
		bomb::Exception("AMap", "Invalid index");
}

bomb::AMap::BlockType &bomb::AMap::operator[](irr::core::vector2di pos)
{
	auto idx = pos.X + pos.Y * _size;
	if ((unsigned int)idx < _cells.size())
		return _cells[idx];
	throw
		bomb::Exception("AMap", "Invalid index");
}

bomb::AMap::BlockType &bomb::AMap::operator[](irr::core::vector2df pos)
{
	auto idx = static_cast<unsigned int>(pos.X + pos.Y * _size);
	if (idx < _cells.size())
		return _cells[idx];
	throw
		bomb::Exception("AMap", "Invalid index");
}

const std::vector<bomb::AMap::BlockType> &bomb::AMap::getCells() const
{
	return _cells;
}

std::ostream &operator<<(std::ostream &os, const bomb::AMap &map) {
	int  i = 0;
	for (auto cell : map.getCells()) {
		os << " " << cell;
		++i;
		if (i % map.getSize() == 0)
			os << "\n";
	}
	return os;
}

void bomb::AMap::clean()
{
	fill(_cells.begin(), _cells.end(), AMap::EMPTY);
}
