//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// GameWindow.cpp
//

#include "GameWindow.hpp"

bomb::GameWindow::GameWindow(const std::wstring &winName, uint x, uint y,
			     irr::video::E_DRIVER_TYPE driver_type)
{
	_device.reset(irr::createDevice(driver_type, irr::core::dimension2d
		(x, y)));
	_sceneManager.reset(_device->getSceneManager());
	_videoDriver.reset(_device->getVideoDriver());
	_device->setWindowCaption(winName.c_str());
}

bomb::GameWindow::~GameWindow()
{
	_device->drop();
	_videoDriver->drop();
	_sceneManager->drop();
}

void bomb::GameWindow::refresh()
{
	_videoDriver->beginScene(true, true, irr::video::SColor(255,0,0,255));
	_sceneManager->drawAll();
	_videoDriver->endScene();
}

std::unique_ptr<irr::gui::IGUIEnvironment> bomb::GameWindow::loadGui()
{
	std::unique_ptr<irr::gui::IGUIEnvironment> ptr;

	ptr.reset(_device->getGUIEnvironment());
	return ptr;
}

std::unique_ptr<irr::video::ITexture>
bomb::GameWindow::loadTexture(const std::string &path)
{
	std::unique_ptr<irr::video::ITexture> ptr;

	ptr.reset(_videoDriver->getTexture(path.c_str()));
	return ptr;

}
