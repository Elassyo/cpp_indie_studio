/*
** EPITECH PROJECT, 2018
** cpp_indie_studio
** File description:
** IAssetManager.hpp
*/

#ifndef CPP_INDIE_STUDIO_IASSETMANAGER_HPP
	#define CPP_INDIE_STUDIO_IASSETMANAGER_HPP

	#include "IAssetLoader.hpp"

namespace bomb {
	namespace menu {
		class Menu;
	}
	class IAssetManager : public virtual IAssetLoader {
	public:
		virtual void deleteObject(std::unique_ptr<IObject> obj) = 0;
		virtual void unloadAudioFile(const std::string &) = 0;

		virtual const irr::core::dimension2d<irr::u32> &
			getScreenSize() = 0;

		virtual void playMusic(const std::string &) = 0;
		virtual void setVolume(float gain) = 0;
		virtual void pauseAll() = 0;
		virtual void stopAll() = 0;
	};
}

#endif /* CPP_INDIE_STUDIO_IASSETMANAGER_HPP */
