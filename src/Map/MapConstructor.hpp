//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapConstructor.hpp
//

#ifndef CPP_INDIE_STUDIO_MAPCONSTRUCTOR_HPP
#define CPP_INDIE_STUDIO_MAPCONSTRUCTOR_HPP

#include <unordered_map>
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
		void rmBlock(const irr::core::vector3di &);

		std::unique_ptr<bomb::Map> construct(
			IAssetLoader &loader,
			const irr::core::vector3df &pos,
			const irr::core::vector3df &size,
			const irr::core::vector3df &rotation);
		void dumpMap();
		int getSize();
	private:
		unsigned int _mapSize;
		std::vector<std::pair<irr::core::vector3di, Block>> _mapBlocks;

		static const std::unordered_map<bomb::MapConstructor::Block,
			std::shared_ptr<bomb::AMapBlock>> blockBuilder;
	};
}

#endif /* CPP_INDIE_STUDIO_MAPCONSTRUCTOR_HPP */