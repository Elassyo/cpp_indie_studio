//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AObject.hpp
//

#ifndef CPP_INDIE_STUDIO_AOBJECT_HPP
	#define CPP_INDIE_STUDIO_AOBJECT_HPP

	#include <irrlicht/irrlicht.h>
	#include "Interface/ISerializable.hpp"

namespace bomb {
	class IObject :
		virtual public ISerializable
	{
	public:
		virtual ~IObject() = default;
		virtual irr::scene::ISceneNode *getSceneNode() const = 0;
		virtual irr::core::vector3df getPos() const = 0;
		virtual void setPos(const irr::core::vector3df &) = 0;
		virtual irr::core::vector3df getRot() const = 0;
		virtual void setRot(const irr::core::vector3df &) = 0;
		virtual irr::core::vector3df getScale() const = 0;
		virtual void setScale(const irr::core::vector3df &) = 0;
		virtual void
		setTexture(uint32_t layer, irr::video::ITexture *) = 0;
	};
}

#endif /* CPP_INDIE_STUDIO_AOBJECT_HPP */
