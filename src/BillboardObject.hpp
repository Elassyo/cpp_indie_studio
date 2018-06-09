//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// BillboardObject.hpp
//

#ifndef CPP_INDIE_STUDIO_BILLBOARDOBJECT_HPP
	#define CPP_INDIE_STUDIO_BILLBOARDOBJECT_HPP

	#include "AObject.hpp"

namespace bomb {
	class BillboardObject : public AObject {
	public:
		explicit BillboardObject(irr::scene::IBillboardSceneNode *,
					 IAudioPlayer &);
		void setTexture(uint32_t layer,
				irr::video::ITexture *texture) override;
		std::string toString() override;

	private:
		irr::scene::IBillboardSceneNode *_inode;
	};
}

#endif /* CPP_INDIE_STUDIO_BILLBOARDOBJECT_HPP */