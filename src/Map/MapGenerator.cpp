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
	if (Generators.find(type) == Generators.end())
		throw bomb::Exception("MapGenerator", "Invalid type");
}

bomb::MapConstructor bomb::MapGenerator::generate()
{
	_rng.seed(_seed);
	return (this->*(Generators.at(_type)))();
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

	for (int x = 0; x < _size; x++) {
		for (int y = 0; y < _size; y++) {
			if (isCorner(x, y))
				continue;
			if (x % 2 == 1 && y % 2 == 1 &&
				x != _size - 1 && y != _size - 1)
				map.addBlock({ x, y, 0 },
					bomb::MapConstructor::UNBREAKABLE);
			else if (_rng() % 100 <= GEN_BASIC_PROB)
				map.addBlock({ x, y, 0 },
					bomb::MapConstructor::BREAKABLE);
		}
	}
	return map;
}

bool bomb::MapGenerator::isCorner(int x, int y)
{
	x = std::min(x, (int)_size - x - 1);
	y = std::min(y, (int)_size - y - 1);
	return (x <= 1 && y <= 1 && !(x == 1 && y == 1));
}
