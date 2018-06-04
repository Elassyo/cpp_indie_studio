//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// StaticObject.hpp
//

#ifndef CPP_INDIE_STUDIO_STATICOBJECT_HPP
#define CPP_INDIE_STUDIO_STATICOBJECT_HPP

#include "AObject.hpp"

namespace bomb {
	class StaticObject : public AObject<irr::scene::IMeshSceneNode> {
	public:
		explicit StaticObject(irr::scene::IMeshSceneNode *);
		void setTexture(uint32_t layer, irr::video::ITexture *texture) override;

		std::string toString() override;
	};
}

#endif /* CPP_INDIE_STUDIO_STATICOBJECT_HPP */