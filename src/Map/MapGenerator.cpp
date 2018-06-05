//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapGenerator.cpp
//

#include <iostream>
#include "../Exception/Exception.hpp"
#include "MapGenerator.hpp"

const std::unordered_map<bomb::MapGenerator::Type,
	bomb::MapConstructor (bomb::MapGenerator::*)()>
	bomb::MapGenerator::typeGenerator = {
	{bomb::MapGenerator::RANDOM, &bomb::MapGenerator::generateRandom},
	{bomb::MapGenerator::BASIC, &bomb::MapGenerator::generateBasic},
};

bomb::MapGenerator::MapGenerator(unsigned int size, unsigned int seed,
	bomb::MapGenerator::Type type) :
	_seed(seed), _size(size), _type(type)
{
	if (size < 7)
		throw bomb::Exception("Genereator", "Invalide Map Size");
	if (_type == END_VALUE)
		throw bomb::Exception("Genereator", "Invalide Type");
}

bomb::MapConstructor bomb::MapGenerator::generate()
{
	srandom(_seed);
	auto map = (this->*(bomb::MapGenerator::typeGenerator.at(_type)))();
	fillCornerSpawn(map);
	addBorder(map);
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
	MapConstructor build(_size);

	for (unsigned int x = 0; x < _size; x++) {
		for (unsigned int y = 0; y < _size; y++) {
			if (x % 2 == 0 && y % 2 == 0)
				build.addBlock({(int)x, (int)y, 0},
					bomb::MapConstructor::UNBREAKABLE);
			else if (random() % 100 <= GEN_BASIC_PROBA)
				build.addBlock({(int)x, (int)y, 0},
					bomb::MapConstructor::BREAKABLE);
		}
	}
	return build;
}

void bomb::MapGenerator::addBorder(MapConstructor &build)
{
	for (unsigned int x = 0; x < _size; x++) {
		build.addBlock({(int)x, 0, 0},
			bomb::MapConstructor::UNBREAKABLE);
		build.addBlock({(int)x, (int)_size - 1, 0},
			bomb::MapConstructor::UNBREAKABLE);
	}
	for (unsigned int y = 0; y < _size; y++) {
		build.addBlock({0, (int)y, 0},
			bomb::MapConstructor::UNBREAKABLE);
		build.addBlock({(int)_size - 1, (int)y, 0},
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
