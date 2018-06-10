//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Map.hpp
//

#ifndef CPP_INDIE_STUDIO_MAP_HPP
	#define CPP_INDIE_STUDIO_MAP_HPP

	#include "AMap.hpp"

namespace bomb {
	class Map : public bomb::AMap {
	public:
		Map(const std::vector<std::shared_ptr<AMapBlock>> &_blocks,
		    std::vector<BlockType> &cells);

		void clean(IAssetManager &loader);
		bool blockAt(const irr::core::vector2di &coord);
		void updateFromCells(IAssetManager &loader);
	private:
		std::vector<std::shared_ptr<bomb::AMapBlock>> _blocks;
	};
}

#endif /* CPP_INDIE_STUDIO_MAP_HPP */
