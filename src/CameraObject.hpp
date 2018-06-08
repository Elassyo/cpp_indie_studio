//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// CameraObject.hpp
//

#ifndef CPP_INDIE_STUDIO_CAMERAOBJECT_HPP
	#define CPP_INDIE_STUDIO_CAMERAOBJECT_HPP

	#include "AObject.hpp"
	#include "Audio/AudioManager.hpp"

namespace bomb {
	class CameraObject : public AObject {
	public:
		explicit CameraObject(irr::scene::ICameraSceneNode *,
		AudioManager &);
		void setTexture(uint32_t layer,
				irr::video::ITexture *texture) override;

		std::string toString() override;
		void setPos(const irr::core::vector3df &v) override;
		void setRot(const irr::core::vector3df &v) override;
		void setTarget(const irr::core::vector3df &v);
	private:
		irr::scene::ICameraSceneNode *_inode;
		IAudioListener &_audioListener;
	};
}

#endif /* CPP_INDIE_STUDIO_CAMERAOBJECT_HPP */