//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// StaticObject.hpp
//

#ifndef CPP_INDIE_STUDIO_STATICOBJECT_HPP
#define CPP_INDIE_STUDIO_STATICOBJECT_HPP

#include "IObject.hpp"

namespace bomb {
	class StaticObject : virtual public IObject {
	public:
		explicit StaticObject(irr::scene::IMeshSceneNode *);
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
		irr::scene::IMeshSceneNode *_inode;
	};
}

#endif /* CPP_INDIE_STUDIO_STATICOBJECT_HPP */