//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapGenerator.hpp
//

#ifndef CPP_INDIE_STUDIO_MAPGENERATOR_HPP
#define CPP_INDIE_STUDIO_MAPGENERATOR_HPP

#include <unordered_map>
#include <time.h>
#include "Map.hpp"
#include "MapConstructor.hpp"

#define GEN_BASIC_PROBA (90)

namespace bomb {
	class MapGenerator {
	public:
		enum Type {
			RANDOM,
			BASIC,
			END_VALUE
		};

		MapGenerator(unsigned int size,
			unsigned int seed = time(nullptr),
			bomb::MapGenerator::Type = RANDOM);
		MapConstructor generate();

	private:
		static const std::unordered_map<bomb::MapGenerator::Type, MapConstructor (bomb::MapGenerator::*)()> typeGenerator;
		MapConstructor generateRandom();
		MapConstructor generateBasic();

		void addBorder(MapConstructor &build);
		void fillSpawn(MapConstructor &build,
			unsigned int x, unsigned int y);
		void fillCornerSpawn(bomb::MapConstructor &build);

		unsigned int _seed;
		unsigned int _size;
		Type _type;
	};
}

#endif /* CPP_INDIE_STUDIO_MAPGENERATOR_HPP */
