//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapConstructor.cpp
//

#include <iostream>
#include <src/Exception/Exception.hpp>
#include "src/Map/MapBlocks/MapBlockBreakable.hpp"
#include "src/Map/MapBlocks/MapBlockUnbreakable.hpp"
#include "MapConstructor.hpp"

const std::unordered_map<bomb::MapConstructor::Block,
	std::shared_ptr<bomb::AMapBlock>> bomb::MapConstructor::blockBuilder = {
	{bomb::MapConstructor::UNBREAKABLE,
		std::make_shared<bomb::MapBlockUnbreakable>()},
	{bomb::MapConstructor::BREAKABLE,
		std::make_shared<bomb::MapBlockBreakable>()}
};


bomb::MapConstructor::MapConstructor(unsigned int mapSize):
	_mapSize(mapSize)
{
}

void bomb::MapConstructor::addBlock(
	const irr::core::vector3di &pos, Block block)
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
	irr::core::vector3df blockSize = {size.X / _mapSize,
		size.Y / _mapSize, size.Z};
	for (auto &block : _mapBlocks) {
		irr::core::vector3df blockPos =
			{pos.X + block.first.X * blockSize.X, pos.Z,
			 pos.Y + block.first.Y * blockSize.Y};
		if (blockBuilder.find(block.second) == blockBuilder.end())
			throw bomb::Exception(
				"Block Builder", "Invalid Block ID");
		_blocks.emplace_back(blockBuilder.at(block.second)->clone(
			loader, blockPos, blockSize, rotation, block.first));
	}
	std::cout << _blocks.size() << std::endl;
	return std::make_unique<bomb::Map>(_blocks);
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

int bomb::MapConstructor::getSize()
{
	return _mapSize;
}
