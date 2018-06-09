//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapBlockUnbreakable.hpp
//

#ifndef CPP_INDIE_STUDIO_MAPBLOCKUNBREAKABLE_HPP
	#define CPP_INDIE_STUDIO_MAPBLOCKUNBREAKABLE_HPP

	#include "../../Interface/IAssetManager.hpp"
	#include "AMapBlock.hpp"

namespace bomb {
	class MapBlockUnbreakable : public AMapBlock {
	public:
		MapBlockUnbreakable(
			IAssetManager &loader,
			const irr::core::vector3df &pos,
			const irr::core::vector3df &scale,
			const irr::core::vector3df &rotation,
			const irr::core::vector2di &mapPos
		);
		MapBlockUnbreakable();

		bool explode(size_t damage, IAssetManager &loader) override;

		std::unique_ptr<bomb::AMapBlock> clone(
			IAssetManager &loader,
			const irr::core::vector3df &pos,
			const irr::core::vector3df &scale,
			const irr::core::vector3df &rotation,
			const irr::core::vector2di &mapPos) const override;

		std::string toString() override;
	};
}

#endif /* CPP_INDIE_STUDIO_MAPBLOCKUNBREAKABLE_HPP */
