//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AObject.hpp
//

#ifndef CPP_INDIE_STUDIO_AOBJECT_HPP
	#define CPP_INDIE_STUDIO_AOBJECT_HPP

	#include "Interface/IAudioPlayer.hpp"

namespace bomb {

	class AObject : virtual public IObject {
	public:
		explicit AObject(irr::scene::ISceneNode *, IAudioPlayer &);

		irr::core::vector3df getPos() const override;
		irr::core::vector3df getRot() const override;
		irr::core::vector3df getScale() const override;
		
		virtual void setPos(const irr::core::vector3df &v) override;
		virtual void setRot(const irr::core::vector3df &v) override;
		void setScale(const irr::core::vector3df &v) override;
		void setVisible(bool visibility);

		irr::scene::ISceneNode *getSceneNode() const override;

		void playSound(const std::string &);

	private:
		irr::scene::ISceneNode *_node;
		IAudioPlayer &_audioPlayer;
	};

}

#endif /* CPP_INDIE_STUDIO_AOBJECT_HPP */
