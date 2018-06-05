//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Map.cpp
//

#include "Map.hpp"

bomb::Map::Map(const std::vector<std::shared_ptr<bomb::AMapBlock>> &_blocks) :
	_blocks(_blocks)
{
}

void bomb::Map::explode(irr::core::vector3di pos, size_t range, size_t damage)
{
	for (auto &e : _blocks) {
		/* TODO: Verifier la position */
		if (e->explode(damage)) {
			/* Detruit le block */
		}
	}
}
