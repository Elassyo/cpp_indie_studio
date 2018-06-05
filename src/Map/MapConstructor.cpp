//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapConstructor.cpp
//

#include <iostream>
#include "../Exception/Exception.hpp"
#include "../Map/MapBlocks/MapBlockBreakable.hpp"
#include "../Map/MapBlocks/MapBlockUnbreakable.hpp"
#include "MapConstructor.hpp"

const std::unordered_map<bomb::MapConstructor::BlockType,
	std::shared_ptr<bomb::AMapBlock>> bomb::MapConstructor::Blocks = {
	{ UNBREAKABLE, std::make_shared<bomb::MapBlockUnbreakable>() },
	{ BREAKABLE, std::make_shared<bomb::MapBlockBreakable>() }
};

bomb::MapConstructor::MapConstructor(unsigned int mapSize) :
	_mapSize(mapSize)
{
}

void bomb::MapConstructor::addBlock(const irr::core::vector3di &pos,
	BlockType type)
{
	_mapBlocks[pos] = type;
}

void bomb::MapConstructor::rmBlock(const irr::core::vector3di &pos)
{
	auto it = _mapBlocks.find(pos);
	if (it != _mapBlocks.end())
		_mapBlocks.erase(it);
}

std::unique_ptr<bomb::Map> bomb::MapConstructor::construct(
	bomb::IAssetLoader &loader,
	const irr::core::vector3df &pos,
	const irr::core::vector3df &size,
	const irr::core::vector3df &rotation)
{
	std::vector<std::shared_ptr<bomb::AMapBlock>> _blocks;

	for (auto &block : _mapBlocks) {
		irr::core::vector3df blockPos = {
			pos.X + block.first.X * size.X,
			pos.Z,
			pos.Y + block.first.Y * size.Z };
		auto it = Blocks.find(block.second);
		if (it == Blocks.end())
			throw bomb::Exception("Block Builder",
				"Invalid Block type");
		_blocks.emplace_back(it->second->clone(
			loader, blockPos, size, rotation, block.first));
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
