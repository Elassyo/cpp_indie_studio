//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapConstructor.hpp
//

#ifndef CPP_INDIE_STUDIO_MAPCONSTRUCTOR_HPP
#define CPP_INDIE_STUDIO_MAPCONSTRUCTOR_HPP

#include "src/Interface/IAssetLoader.hpp"
#include "Map.hpp"

namespace bomb {
	class MapConstructor {
	public:
		enum Block {
			UNBREAKABLE,
			BREAKABLE
		};
		explicit MapConstructor(unsigned int mapSize);

		void addBlock(const irr::core::vector3di &, Block map);
		std::unique_ptr<bomb::Map> construct(
			IAssetLoader &loader,
			const irr::core::vector3df &pos,
			const irr::core::vector3df &size,
			const irr::core::vector3df &rotation);
		void dumpMap();

	private:
		unsigned int _mapSize;
		std::vector<std::pair<irr::core::vector3di, Block>> _mapBlocks;
	};
}

#endif /* CPP_INDIE_STUDIO_MAPCONSTRUCTOR_HPP */