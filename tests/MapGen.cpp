/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** MapGen.cpp
*/

#include <iostream>
#include "../src/Map/MapGenerator.hpp"

int main()
{
	srand(time(nullptr));
	int x = (unsigned int)rand();
	std::cout << "SEED: " << x << std::endl;
	int mapSize = 15;
	bomb::MapGenerator generator(x, mapSize, bomb::MapGenerator::BASIC);
	auto e = generator.generate();
	e.dumpMap(mapSize);
}