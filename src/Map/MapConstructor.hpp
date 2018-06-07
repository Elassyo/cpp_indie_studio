//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapConstructor.hpp
//

#ifndef CPP_INDIE_STUDIO_MAPCONSTRUCTOR_HPP
	#define CPP_INDIE_STUDIO_MAPCONSTRUCTOR_HPP

	#include <map>
	#include <unordered_map>

	#include "../Interface/IAssetLoader.hpp"
	#include "Map.hpp"

namespace bomb {
	class MapConstructor {
	public:
		enum BlockType {
			UNBREAKABLE,
			BOMB,
			BREAKABLE,
			EMPTY
		};

		explicit MapConstructor(unsigned int mapSize);

		void addBlock(const irr::core::vector3di &, BlockType type);
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
		std::map<irr::core::vector3di, BlockType> _mapBlocks;

		static const std::unordered_map<bomb::MapConstructor::BlockType,
			std::shared_ptr<bomb::AMapBlock>> Blocks;
	};
}

#endif /* CPP_INDIE_STUDIO_MAPCONSTRUCTOR_HPP */
