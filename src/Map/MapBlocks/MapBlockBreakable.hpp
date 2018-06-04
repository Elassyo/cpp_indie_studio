//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapBlockBreakable.hpp
//

#ifndef CPP_INDIE_STUDIO_MAPBLOCKBREAKABLE_HPP
#define CPP_INDIE_STUDIO_MAPBLOCKBREAKABLE_HPP

#include "src/Interface/IAssetLoader.hpp"
#include "AMapBlock.hpp"


namespace bomb {
	class MapBlockBreakable : public AMapBlock {
	public:
		MapBlockBreakable(
			IAssetLoader &loader,
			const irr::core::vector3df &pos,
			const irr::core::vector3df &size,
			const irr::core::vector3df &rotation,
			const irr::core::vector3di &mapPos
		);

		bool explode(size_t dammage) override;
	};
}

#endif /* CPP_INDIE_STUDIO_MAPBLOCKBREAKABLE_HPP */