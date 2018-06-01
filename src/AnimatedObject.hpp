//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AnimatedObject.hpp
//

#ifndef CPP_INDIE_STUDIO_ANIMATEDOBJECT_HPP
#define CPP_INDIE_STUDIO_ANIMATEDOBJECT_HPP

#include <irrlicht/irrlicht.h>
#include "IObject.hpp"

namespace bomb {
	class AnimatedObject : public virtual IObject {
	public:
		explicit AnimatedObject(irr::scene::IAnimatedMeshSceneNode *);
		irr::core::vector3df getPos() const override;
		void setPos(const irr::core::vector3df &) override;
		irr::core::vector3df getRot() const override;
		void setRot(const irr::core::vector3df &) override;
		irr::core::vector3df getScale() const override;
		void setScale(const irr::core::vector3df &) override;
		irr::scene::ISceneNode *getSceneNode() const override;
		void setTexture(uint32_t layer, irr::video::ITexture *texture) override;

		std::string toString() override;

	private:
		irr::scene::IAnimatedMeshSceneNode *_inode;
	};
}

#endif /* CPP_INDIE_STUDIO_ANIMATEDOBJECT_HPP */