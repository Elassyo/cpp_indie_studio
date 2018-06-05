//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapGenerator.cpp
//

#include <iostream>
#include <random>

#include "../Exception/Exception.hpp"
#include "MapGenerator.hpp"

const std::map<bomb::MapGenerator::GeneratorType,
	bomb::MapConstructor (bomb::MapGenerator::*)()>
	bomb::MapGenerator::Generators = {
	{ bomb::MapGenerator::RANDOM, &bomb::MapGenerator::generateRandom },
	{ bomb::MapGenerator::BASIC, &bomb::MapGenerator::generateBasic },
};

bomb::MapGenerator::MapGenerator(unsigned int size, unsigned int seed,
		bomb::MapGenerator::GeneratorType type) :
	_seed(seed), _size(size), _type(type)
{
	if (size < 7)
		throw bomb::Exception("Generator",
			"Requested map size is too small");
	if (Generators.find(type) == Generators.end())
		throw bomb::Exception("MapGenerator", "Invalid type");
}

bomb::MapConstructor bomb::MapGenerator::generate()
{
	_rng.seed(_seed);
	MapConstructor map = (this->*(Generators.at(_type)))();
	fillCornerSpawn(map);
	addBorder(map);
	return map;
}

bomb::MapConstructor bomb::MapGenerator::generateRandom()
{
	GeneratorType type = (GeneratorType)(
		TYPES_BEG + 1 + _rng() % (TYPES_END - TYPES_BEG - 1));
	return (this->*(Generators.at(_type)))();
}

bomb::MapConstructor bomb::MapGenerator::generateBasic()
{
	MapConstructor map(_size);

	for (unsigned int x = 0; x < _size; x++) {
		for (unsigned int y = 0; y < _size; y++) {
			if (x % 2 == 0 && y % 2 == 0)
				map.addBlock({ (int)x, (int)y, 0 },
					bomb::MapConstructor::UNBREAKABLE);
			else if (_rng() % 100 <= GEN_BASIC_PROB)
				map.addBlock({ (int)x, (int)y, 0 },
					bomb::MapConstructor::BREAKABLE);
		}
	}
	return map;
}

void bomb::MapGenerator::addBorder(MapConstructor &build)
{
	for (unsigned int x = 0; x < _size; x++) {
		build.addBlock({ (int)x, 0, 0 },
			bomb::MapConstructor::UNBREAKABLE);
		build.addBlock({ (int)x, (int)_size - 1, 0 },
			bomb::MapConstructor::UNBREAKABLE);
	}
	for (unsigned int y = 0; y < _size; y++) {
		build.addBlock({ 0, (int)y, 0 },
			bomb::MapConstructor::UNBREAKABLE);
		build.addBlock({ (int)_size - 1, (int)y, 0 },
			bomb::MapConstructor::UNBREAKABLE);
	}
}

void bomb::MapGenerator::fillSpawn(MapConstructor &build,
	unsigned int x, unsigned int y)
{
	build.rmBlock({(int)x - 1, (int)y, 0});
	build.rmBlock({(int)x + 1, (int)y, 0});
	build.rmBlock({(int)x, (int)y - 1, 0});
	build.rmBlock({(int)x, (int)y + 1, 0});
	build.rmBlock({(int)x, (int)y, 0});
}

void
bomb::MapGenerator::fillCornerSpawn(bomb::MapConstructor &build)
{
	fillSpawn(build, 1, 1);
	fillSpawn(build, _size - 2, 1);
	fillSpawn(build, 1, _size - 2);
	fillSpawn(build, _size - 2, _size - 2);
}
