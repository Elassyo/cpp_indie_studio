//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapBlockBreakable.hpp
//

#ifndef CPP_INDIE_STUDIO_MAPBLOCKBREAKABLE_HPP
	#define CPP_INDIE_STUDIO_MAPBLOCKBREAKABLE_HPP

	#include "../../Interface/IAssetLoader.hpp"
	#include "AMapBlock.hpp"

namespace bomb {
	class MapBlockBreakable : public AMapBlock {
	public:
		MapBlockBreakable(
			IAssetLoader &loader,
			const irr::core::vector3df &pos,
			const irr::core::vector3df &scale,
			const irr::core::vector3df &rotation,
			const irr::core::vector2di &mapPos
		);
		MapBlockBreakable();

		bool explode(size_t damage) override;

		std::unique_ptr<bomb::AMapBlock> clone(
			IAssetLoader &loader,
			const irr::core::vector3df &pos,
			const irr::core::vector3df &scale,
			const irr::core::vector3df &rotation,
			const irr::core::vector2di &mapPos) const override;
	};
}

#endif /* CPP_INDIE_STUDIO_MAPBLOCKBREAKABLE_HPP */
