//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapConstructor.hpp
//

#ifndef CPP_INDIE_STUDIO_MAPCONSTRUCTOR_HPP
#define CPP_INDIE_STUDIO_MAPCONSTRUCTOR_HPP

#include "Map.hpp"

namespace bomb {
	class MapConstructor {
	public:
		enum Block {
			UNBREAKABLE,
			BREAKABLE
		};
		MapConstructor();

		void addBlock(const irr::core::vector3di &, Block map);
//		Map &construct();
		void dumpMap(size_t size);

	private:
		std::vector<std::pair<irr::core::vector3di, Block>> _mapBlocks;
		//static const std::unordered_map<unsigned int, /* BLOCK */> _materials;
	};
}

#endif /* CPP_INDIE_STUDIO_MAPCONSTRUCTOR_HPP */