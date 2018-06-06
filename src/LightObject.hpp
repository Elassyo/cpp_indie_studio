//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// LightObject.hpp
//

#ifndef CPP_INDIE_STUDIO_LIGHTOBJECT_HPP
	#define CPP_INDIE_STUDIO_LIGHTOBJECT_HPP

	#include "AObject.hpp"

namespace bomb {
	class LightObject : public AObject {
	public:
		explicit LightObject(irr::scene::ILightSceneNode *node);
		void setTexture(uint32_t layer,
				irr::video::ITexture *texture) override;
		std::string toString() override;

	private:
		irr::scene::ILightSceneNode *_node;
	};
}

#endif /* CPP_INDIE_STUDIO_LIGHTOBJECT_HPP */
