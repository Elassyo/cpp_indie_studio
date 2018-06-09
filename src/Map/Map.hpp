//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Map.hpp
//

#ifndef CPP_INDIE_STUDIO_MAP_HPP
#define CPP_INDIE_STUDIO_MAP_HPP

#include <memory>
#include <vector>
#include <ostream>

#include "../Interface/IRenderable.hpp"
#include "../Interface/ISerializable.hpp"
#include "../Map/MapBlocks/AMapBlock.hpp"

namespace bomb {
	class Map {
	public:
		enum BlockType {
			UNBREAKABLE,
			BOMB,
			BREAKABLE,
			EMPTY
		};

		Map(const std::vector<std::shared_ptr<AMapBlock>> &_blocks,
		    std::vector<BlockType> &cells);

		void setTextures(irr::video::ITexture *texture);

		bool blockAt(const irr::core::vector2di &coord);

		int getSize() const;
		void setSize(int size);
		void updateFromCells(IAssetLoader &loader);
		BlockType &operator[](std::size_t idx);
		BlockType &operator[](irr::core::vector3di &pos);
		BlockType &operator[](irr::core::vector3df pos);

		friend std::ostream &
		operator<<(std::ostream &os, const Map &map);

		const std::vector<BlockType> &getCells() const;

	private:
		std::vector<std::shared_ptr<bomb::AMapBlock>> _blocks;
		std::vector<BlockType> _cells;
		int _size;
	};
}

#endif /* CPP_INDIE_STUDIO_MAP_HPP */
