//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// BomberMap.hpp
//

#ifndef CPP_INDIE_STUDIO_MAP_HPP
	#define CPP_INDIE_STUDIO_MAP_HPP

	#include "Map.hpp"

namespace bomb {
	class BomberMap : public bomb::Map {
	public:
		BomberMap(const std::vector<std::shared_ptr<AMapBlock>> &_blocks,
		    std::vector<BlockType> &cells);

		void clean(IAssetManager &loader);
		bool blockAt(const irr::core::vector2di &coord);
		void updateFromCells(IAssetManager &loader);
	private:
		std::vector<std::shared_ptr<bomb::AMapBlock>> _blocks;
	};
}

#endif /* CPP_INDIE_STUDIO_MAP_HPP */
