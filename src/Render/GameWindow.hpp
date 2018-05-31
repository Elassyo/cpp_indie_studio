//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// GameWindow.hpp
//

#ifndef CPP_INDIE_STUDIO_GAMEWINDOW_HPP
#define CPP_INDIE_STUDIO_GAMEWINDOW_HPP

#include <irrlicht/irrlicht.h>
#include "src/Interface/IAssetLoader.hpp"

namespace bomb {
	class GameWindow : public IAssetLoader {
	public:
		GameWindow(const std::wstring &winName, uint x, uint y,
			   irr::video::E_DRIVER_TYPE);
		void refresh();
		std::unique_ptr<irr::gui::IGUIEnvironment> loadGui() override;
		std::unique_ptr<irr::video::ITexture> loadTexture
			(const std::string &) override;
		~GameWindow();
	private:
		std::unique_ptr<irr::IrrlichtDevice> _device;
		std::unique_ptr<irr::video::IVideoDriver> _videoDriver;
		std::unique_ptr<irr::scene::ISceneManager> _sceneManager;
	};

}
#endif /* CPP_INDIE_STUDIO_GAMEWINDOW_HPP */