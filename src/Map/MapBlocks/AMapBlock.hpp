//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AMapBlock.hpp
//

#ifndef CPP_INDIE_STUDIO_AMAPBLOCK_HPP
	#define CPP_INDIE_STUDIO_AMAPBLOCK_HPP

	#include <memory>
	#include <irrlicht/vector3d.h>

	#include "../../Interface/IAssetLoader.hpp"

#define BLOCK_OBJ_SIZE 2

class unique_ptr;
namespace bomb {
	class AMapBlock {
	public:
		AMapBlock(IAssetLoader &loader,
			const irr::core::vector3df &pos,
			const irr::core::vector3df &scale,
			const irr::core::vector3df &rotation,
			const irr::core::vector2di &mapPos,
			const std::string &path,
			size_t hp);
		AMapBlock();

		virtual bool explode(size_t dammage) = 0;
		virtual std::unique_ptr<AMapBlock> clone(
			IAssetLoader &loader,
			const irr::core::vector3df &pos,
			const irr::core::vector3df &scale,
			const irr::core::vector3df &rotation,
			const irr::core::vector2di &mapPos) const = 0;

		const irr::core::vector2di &getMapPos() const;
		size_t getHp() const;
		void setTextures(irr::video::ITexture *texture);

	protected:
		irr::core::vector2di _mapPos;
		size_t _hp;

	private:
		std::unique_ptr<StaticObject> _block;
	};
}

#endif /* CPP_INDIE_STUDIO_AMAPBLOCK_HPP */
