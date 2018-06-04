//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Map.cpp
//

#include "Map.hpp"

void bomb::Map::explode(irr::core::vector3di pos, size_t range, size_t dammage)
{
	for (auto &e : _blocks) {
		/* Verifier la position */
		if (e->explode(dammage)) {
			/* Detruit le block */
		}
	}
}

bomb::Map::Map(const std::vector<std::shared_ptr<bomb::AMapBlock>> &_blocks)
	: _blocks(_blocks)
{
}
