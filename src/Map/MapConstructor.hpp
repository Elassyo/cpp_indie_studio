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

	#include "../Interface/IAssetManager.hpp"
	#include "BomberMap.hpp"

namespace bomb {
	class MapConstructor {
	public:
		explicit MapConstructor(unsigned int mapSize);

		void addBlock(const irr::core::vector2di &, BomberMap::BlockType
		type);
		void rmBlock(const irr::core::vector2di &);

		std::unique_ptr<bomb::BomberMap> construct(
			IAssetManager &loader,
			const irr::core::vector3df &pos,
			const irr::core::vector3df &size,
			const irr::core::vector3df &rotation);
		void dumpMap();
		int getSize();
	private:
		unsigned int _mapSize;
		std::map<irr::core::vector2di, BomberMap::BlockType> _mapBlocks;

		static const std::unordered_map<bomb::BomberMap::BlockType,
			std::shared_ptr<bomb::AMapBlock>> Blocks;
	};
}

#endif /* CPP_INDIE_STUDIO_MAPCONSTRUCTOR_HPP */
