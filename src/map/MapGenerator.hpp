//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapGenerator.hpp
//

#ifndef CPP_INDIE_STUDIO_MAPGENERATOR_HPP
#define CPP_INDIE_STUDIO_MAPGENERATOR_HPP

#include "Map.hpp"

namespace bomb {
	class MapGenerator {
	public:
		enum Pattern {
			RANDOM
		};

		static Map &generator(size_t size, Pattern pattern = RANDOM);
	};
}

#endif /* CPP_INDIE_STUDIO_MAPGENERATOR_HPP */