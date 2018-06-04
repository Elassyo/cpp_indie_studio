//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapConstructor.cpp
//

#include <iostream>
#include "src/Map/MapBlocks/MapBlockBreakable.hpp"
#include "MapConstructor.hpp"

bomb::MapConstructor::MapConstructor(unsigned int mapSize):
	_mapSize(mapSize)
{
}

void bomb::MapConstructor::addBlock(const irr::core::vector3di &pos, Block block)
{
	_mapBlocks.emplace_back(std::make_pair(pos, block));
}

std::unique_ptr<bomb::Map> bomb::MapConstructor::construct(
	bomb::IAssetLoader &loader,
	const irr::core::vector3df &pos,
	const irr::core::vector3df &size,
	const irr::core::vector3df &rotation)
{
	std::vector<std::shared_ptr<bomb::AMapBlock>> _blocks;
	irr::core::vector3df blockSize = {size.X / _mapSize, size.Y / _mapSize, size.Z};
	for (auto &block : _mapBlocks) {
		irr::core::vector3df blockPos = {pos.X + block.first.X * blockSize.X, pos.Y + block.first.Y * blockSize.Y, pos.Z};
		/* Manque la factory */
		std::shared_ptr<bomb::AMapBlock> a = std::make_shared<bomb::MapBlockBreakable>(loader, blockPos, blockSize, rotation, block.first);
		_blocks.emplace_back(a);
	}
	auto map = std::make_unique<bomb::Map>(_blocks);
	return map;
}

void bomb::MapConstructor::dumpMap()
{
	bool isPrint;

	for (unsigned int x = 0; x < _mapSize; x++) {
		for (unsigned int y = 0; y < _mapSize; y++) {
			isPrint = false;
			for (auto &e : _mapBlocks) {
				if (e.first == irr::core::vector3di(x, y, 0)) {
					std::cout << e.second;
					isPrint = true;
					break;
				}
			}
			if (!isPrint)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
}
