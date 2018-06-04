//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapGenerator.cpp
//

#include <iostream>
#include "../Exception/Exception.hpp"
#include "MapGenerator.hpp"

const std::unordered_map<bomb::MapGenerator::Type, bomb::MapConstructor (bomb::MapGenerator::*)()>
	bomb::MapGenerator::typeGenerator = {
	{bomb::MapGenerator::RANDOM, &bomb::MapGenerator::generateRandom},
	{bomb::MapGenerator::BASIC, &bomb::MapGenerator::generateBasic},
};

bomb::MapGenerator::MapGenerator(unsigned int seed,
	unsigned int size,
	bomb::MapGenerator::Type type) :
	_seed(seed), _size(size), _type(type)
{
	if (_type == END_VALUE)
		throw bomb::Exception("Genereator", "Invalide Type");
}

bomb::MapConstructor bomb::MapGenerator::generate()
{
	srandom(_seed);
	auto map = (this->*(bomb::MapGenerator::typeGenerator.at(_type)))();
	return map;
}

bomb::MapConstructor bomb::MapGenerator::generateRandom()
{
	auto i = (MapGenerator::Type)(random() % (END_VALUE - 1) + 1);
	std::cout << i << " " << RANDOM << BASIC << END_VALUE << std::endl;
	return (this->*(bomb::MapGenerator::typeGenerator.at(i)))();
}

bomb::MapConstructor bomb::MapGenerator::generateBasic()
{
	MapConstructor build;

	for (unsigned int x = 0; x < _size; x++) {
		for (unsigned int y = 0; y < _size; y++) {
			if (isCorner(x, y))
				continue;
			if (x % 2 == 1 && y % 2 == 1 && x != _size - 1
				&& y != _size - 1)
				build.addBlock({(int)x, (int)y, 0},
					bomb::MapConstructor::UNBREAKABLE);
			else if (random() % 100 <= GEN_BASIC_PROBA)
				build.addBlock({(int)x, (int)y, 0},
					bomb::MapConstructor::BREAKABLE);
		}
	}
	return build;
}

bool bomb::MapGenerator::isCorner(unsigned int x, unsigned int y)
{
	return (((x == 0 && (y == 0 || y == 1)) || (y == 0 && x == 1))
			|| ((x == _size - 1 && (y == 0 || y == 1))
			|| (y == 0 && x == _size - 2))
			|| ((x == 0 && (y == _size - 1 || y == _size - 2))
			|| (y == _size - 1 && x == 1))
			|| ((x == _size - 1 && (y == _size - 1
			|| y == _size - 2))
			|| (y == _size - 1 && x == _size - 2))
	);
}
