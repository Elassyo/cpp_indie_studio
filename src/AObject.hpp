//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AObject.hpp
//

#ifndef CPP_INDIE_STUDIO_AOBJECT_HPP
	#define CPP_INDIE_STUDIO_AOBJECT_HPP

	#include <irrlicht/vector3d.h>

	#include "Interface/ISerializable.hpp"
	#include "Interface/IRenderable.hpp"

namespace bomb {
	class AObject :
		virtual public ISerializable,
		virtual public IRenderable
	{
	public:
		explicit AObject(
			const irr::core::vector3df &pos = {0, 0, 0},
			const irr::core::vector3df &scale = {0, 0, 0},
			const irr::core::vector3df &rotation = {0, 0, 0}
		);
		AObject(const AObject &ex);
		~AObject() override = default;

		const irr::core::vector3df &getPos() const;
		irr::core::vector3df &getRPos();
		void setPos(const irr::core::vector3df &pos);
		const irr::core::vector3df &getScale() const;
		irr::core::vector3df &getRScale();
		void setScale(const irr::core::vector3df &scale);
		const irr::core::vector3df &getRotation() const;
		irr::core::vector3df &getRRotation();
		void setRotation(const irr::core::vector3df &rotation);

	protected:
		irr::core::vector3df _pos;
		irr::core::vector3df _scale;
		irr::core::vector3df _rotation;
	};
}

#endif /* CPP_INDIE_STUDIO_AOBJECT_HPP */
