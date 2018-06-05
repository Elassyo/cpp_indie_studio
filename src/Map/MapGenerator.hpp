//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapGenerator.hpp
//

#ifndef CPP_INDIE_STUDIO_MAPGENERATOR_HPP
	#define CPP_INDIE_STUDIO_MAPGENERATOR_HPP

	#include <ctime>
	#include <map>
	#include <random>
	#include "Map.hpp"
	#include "MapConstructor.hpp"

namespace bomb {
	constexpr int GEN_BASIC_PROB = 60;

	class MapGenerator {
	public:
		enum GeneratorType {
			RANDOM,
			TYPES_BEG,
			BASIC,
			TYPES_END
		};

		MapGenerator(unsigned int size,
			unsigned int seed = std::time(nullptr),
			GeneratorType type = RANDOM);
		MapConstructor generate();

	private:
		static const std::map<GeneratorType,
			MapConstructor (bomb::MapGenerator::*)()> Generators;

		MapConstructor generateRandom();
		MapConstructor generateBasic();

		void addBorder(MapConstructor &build);
		void fillSpawn(MapConstructor &build,
			unsigned int x, unsigned int y);
		void fillCornerSpawn(bomb::MapConstructor &build);

		unsigned int _seed;
		unsigned int _size;
		GeneratorType _type;

		std::default_random_engine _rng;
	};
}

#endif /* CPP_INDIE_STUDIO_MAPGENERATOR_HPP */
