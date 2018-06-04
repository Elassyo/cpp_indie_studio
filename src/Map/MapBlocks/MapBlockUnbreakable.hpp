//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapBlockUnbreakable.hpp
//

#ifndef CPP_INDIE_STUDIO_MAPBLOCKUNBREAKABLE_HPP
#define CPP_INDIE_STUDIO_MAPBLOCKUNBREAKABLE_HPP

#include "src/Interface/IAssetLoader.hpp"
#include "AMapBlock.hpp"

namespace bomb {
	class MapBlockUnbreakable : public AMapBlock {
	public:
		MapBlockUnbreakable(
			IAssetLoader &loader,
			const irr::core::vector3df &pos,
			const irr::core::vector3df &size,
			const irr::core::vector3df &rotation,
			const irr::core::vector3di &mapPos
		);

		bool explode(size_t dammage) override;
	};
}

#endif /* CPP_INDIE_STUDIO_MAPBLOCKUNBREAKABLE_HPP */