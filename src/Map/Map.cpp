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

bool bomb::Map::blockAt(const irr::core::vector2di &coord)
{
	if (coord.X < 0 || coord.X > _size - 1
		|| coord.Y < 0 || coord.Y > _size - 1)
		return false;
	for (auto &e : _blocks) {
		if (e->getMapPos() == coord)
			return true;
	}
	return false;
}
