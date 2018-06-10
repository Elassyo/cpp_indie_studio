//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Map.hpp
//

#ifndef CPP_INDIE_STUDIO_AMAP_HPP
	#define CPP_INDIE_STUDIO_AMAP_HPP

	#include <memory>
	#include <vector>
	#include <ostream>

	#include "../Exception/Exception.hpp"
	#include "../Interface/IRenderable.hpp"
	#include "../Interface/ISerializable.hpp"
	#include "../Map/MapBlocks/AMapBlock.hpp"

namespace bomb {
	class AMap {
	public:
		enum BlockType {
			UNBREAKABLE,
			BOMB,
			BREAKABLE,
			EMPTY,
			PLAYER
		};

		void clean();

		void setSize(int size);
		int getSize() const;
		const std::vector<BlockType> &getCells() const;

		BlockType &operator[](std::size_t idx);
		BlockType &operator[](irr::core::vector3di pos);
		BlockType &operator[](irr::core::vector3df pos);
		BlockType &operator[](irr::core::vector2di pos);
		BlockType &operator[](irr::core::vector2df pos);
		friend std::ostream &
		operator<<(std::ostream &os, const AMap &map);
	protected:
		std::vector<BlockType> _cells;
		int _size;
	};
}

#endif /* CPP_INDIE_STUDIO_AMAP_HPP */
