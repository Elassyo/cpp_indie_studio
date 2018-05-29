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
	typedef std::vector<std::pair<irr::core::vector3di, size_t>> MapPattern;

	class MapGenerator {
	public:
		enum Pattern {
			RANDOM,
			BASIC
		};

		static Map &generate(size_t size, Pattern idPattern = RANDOM);

	private:
		static Map &paternToMap(const MapPattern &pattern);
		static MapPattern genBasic(int size);
	};
}

#endif /* CPP_INDIE_STUDIO_MAPGENERATOR_HPP */
