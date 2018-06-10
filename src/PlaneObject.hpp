//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// PLANEOBJECT.hpp
//

#ifndef CPP_INDIE_STUDIO_PLANEOBJECT_HPP
	#define CPP_INDIE_STUDIO_PLANEOBJECT_HPP

	#include "AObject.hpp"

namespace bomb {
	class PlaneObject : public AObject {
	public:
		explicit PlaneObject(
			irr::scene::IMeshSceneNode *,
			bomb::IAudioPlayer &);

		void setTexture(uint32_t layer,
				irr::video::ITexture *texture) override;

		std::string toString() override;

	private:
		irr::scene::IMeshSceneNode *_iNode;
	};
}

#endif /* CPP_INDIE_STUDIO_PLANEOBJECT_HPP */