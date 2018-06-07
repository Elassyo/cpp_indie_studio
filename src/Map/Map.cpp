//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Map.cpp
//

#include "Map.hpp"

bomb::Map::Map(const std::vector<std::shared_ptr<bomb::AMapBlock>> &_blocks,
	std::vector<Map::BlockType> &cells) :
	_blocks(_blocks), _cells(cells),
	_size(static_cast<int>(cells.size() / cells.size()))
{
}

void bomb::Map::explode(irr::core::vector3di pos, size_t range, size_t damage)
{
	for (auto &e : _blocks) {
		/* TODO: Verifier la position */
		if (e->explode(damage)) {
			/* TODO: Supprimer le block */
		}
	}
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
	return _cells[pos.X + pos.Y * _size];
}

void bomb::Map::addBomb(std::size_t x, std::size_t y)
{
	auto idx = x + y * _size;
	if (_cells.at(idx) == EMPTY)
		_cells.at(idx) = BOMB;
}

bool bomb::Map::blockAt(const irr::core::vector2di &coord)
{
	return _cells[coord.X + coord.Y * _size] != BlockType::EMPTY;
}
