//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AnimatedObject.hpp
//

#ifndef CPP_INDIE_STUDIO_ANIMATEDOBJECT_HPP
	#define CPP_INDIE_STUDIO_ANIMATEDOBJECT_HPP

	#include <irrlicht/irrlicht.h>
	#include "AObject.hpp"

namespace bomb {
	class AnimatedObject : public AObject {
	public:
		explicit AnimatedObject
			(irr::scene::IAnimatedMeshSceneNode *node);
		void setTexture(uint32_t layer,
			irr::video::ITexture *texture) override;

		std::string toString() override;

	private:
		irr::scene::IAnimatedMeshSceneNode *_node;
	};
}

#endif /* CPP_INDIE_STUDIO_ANIMATEDOBJECT_HPP */
