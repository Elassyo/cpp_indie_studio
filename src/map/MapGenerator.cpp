//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapGenerator.cpp
//

#include <src/exception/Exception.hpp>
#include "MapGenerator.hpp"

const size_t nbPattern = 1;

bomb::Map &bomb::MapGenerator::paternToMap(const bomb::MapPattern &pattern)
{
	/* TO DO */
	/*bomb::Map x =  bomb::Map();
	return x;*/
}

bomb::Map &
bomb::MapGenerator::generate(size_t size, bomb::MapGenerator::Pattern idPattern)
{
	bomb::MapPattern pattern;

	if (idPattern == RANDOM)
		idPattern = (Pattern)(random() % nbPattern + 1);
	switch (idPattern) {
	case BASIC:
		pattern = genBasic((int)size);
		break;
	case RANDOM:
	default:
		throw bomb::Exception("Generator", "Pattern not found");
	}
	return paternToMap(pattern);
}

const long GenBasicProba = 90;
bomb::MapPattern bomb::MapGenerator::genBasic(int size)
{
	bomb::MapPattern pattern;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if ((i == 0 || i == 1 || i == size || i == size - 1)
				&& (j == 0 || j == 1 || j == size || j == size - 1))
				continue;
			else if (i % 2 == 1 && j % 2 == 1)
				pattern.push_back(std::make_pair<irr::core::vector3di, size_t>({i, j, 0}, 0));
			else if (random() % 100 <= GenBasicProba)
				pattern.push_back(std::make_pair<irr::core::vector3di, size_t>({i, j, 0}, 1));
		}
	}
	return pattern;
}