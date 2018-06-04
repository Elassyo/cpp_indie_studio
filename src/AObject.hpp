//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AObject.hpp
//

#ifndef CPP_INDIE_STUDIO_AOBJECT_HPP
	#define CPP_INDIE_STUDIO_AOBJECT_HPP

	#include "Interface/IObject.hpp"

namespace bomb {
	class AObject : virtual public bomb::IObject {
	public:
		explicit AObject(irr::scene::ISceneNode *);
		irr::core::vector3df getPos() const override;
		void setPos(const irr::core::vector3df &) override;
		irr::core::vector3df getRot() const override;
		void setRot(const irr::core::vector3df &) override;
		irr::core::vector3df getScale() const override;
		void setScale(const irr::core::vector3df &) override;

		irr::scene::ISceneNode *getSceneNode() const override;

	private:
		irr::scene::ISceneNode *_node;
	};
}

#endif /* CPP_INDIE_STUDIO_AOBJECT_HPP */
