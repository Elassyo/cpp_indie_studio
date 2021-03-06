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

const std::unordered_map<bomb::BomberMap::BlockType,
	std::shared_ptr<bomb::AMapBlock>> bomb::MapConstructor::Blocks = {
	{ BomberMap::UNBREAKABLE, std::make_shared<bomb::MapBlockUnbreakable>() },
	{ BomberMap::BREAKABLE, std::make_shared<bomb::MapBlockBreakable>() }
};

bomb::MapConstructor::MapConstructor(unsigned int mapSize) :
	_mapSize(mapSize)
{
}

void bomb::MapConstructor::addBlock(const irr::core::vector2di &pos,
					BomberMap::BlockType type)
{
	_mapBlocks[pos] = type;
}

void bomb::MapConstructor::rmBlock(const irr::core::vector2di &pos)
{
	auto it = _mapBlocks.find(pos);
	if (it != _mapBlocks.end())
		_mapBlocks.erase(it);
}

std::unique_ptr<bomb::BomberMap> bomb::MapConstructor::construct(
	bomb::IAssetManager &loader,
	const irr::core::vector3df &pos,
	const irr::core::vector3df &size,
	const irr::core::vector3df &rotation)
{
	std::vector<std::shared_ptr<bomb::AMapBlock>> _blocks;
	std::vector<BomberMap::BlockType> cells(_mapSize * _mapSize, BomberMap::EMPTY);

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
		cells[block.first.X + block.first.Y * _mapSize] = block.second;
	}
	return std::make_unique<bomb::BomberMap>(_blocks, cells);
}

void bomb::MapConstructor::dumpMap()
{
	bool isPrint;

	for (unsigned int x = 0; x < _mapSize; x++) {
		for (unsigned int y = 0; y < _mapSize; y++) {
			isPrint = false;
			for (auto &e : _mapBlocks) {
				if (e.first == irr::core::vector2di(x, y)) {
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

void bomb::MapConstructor::setSize(unsigned int size)
{
	_mapSize = size;
}

int bomb::MapConstructor::getSize()
{
	return _mapSize;
}
