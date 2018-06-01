//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapConstructor.cpp
//

#include <iostream>
#include "MapConstructor.hpp"

bomb::MapConstructor::MapConstructor()
{
}

void bomb::MapConstructor::addBlock(const irr::core::vector3di &pos, Block block)
{
	_mapBlocks.emplace_back(std::make_pair(pos, block));
}

/* To delete */
void bomb::MapConstructor::dumpMap(size_t size)
{
	bool aled;

	for (unsigned int x = 0; x < size; x++) {
		for (unsigned int y = 0; y < size; y++) {
			aled = false;
			for (auto &e : _mapBlocks) {
				if (e.first == irr::core::vector3di(x, y, 0)) {
					std::cout << e.second;
					aled = true;
					break;
				}
			}
			if (!aled)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}
