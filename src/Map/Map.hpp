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

#include "../Interface/IRenderable.hpp"
#include "../Interface/ISerializable.hpp"
#include "../Map/MapBlocks/AMapBlock.hpp"

namespace bomb {
	class Map {
	public:
		Map(const std::vector<std::shared_ptr<AMapBlock>> &_blocks);

		void explode(irr::core::vector3di pos,
			size_t range, size_t damage);
		void setTextures(irr::video::ITexture *texture);

	private:
		std::vector<std::shared_ptr<bomb::AMapBlock>> _blocks;
	};
}

#endif /* CPP_INDIE_STUDIO_MAP_HPP */
