//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// GameEngine.cpp
//

#include "GameEngine.hpp"

bomb::GameEngine::GameEngine(const std::wstring &winName, uint x, uint y,
			     irr::video::E_DRIVER_TYPE driver_type)
{
	_device.reset(irr::createDevice(driver_type, irr::core::dimension2d
		(x, y)));
	_sceneManager.reset(_device->getSceneManager());
	_videoDriver.reset(_device->getVideoDriver());
	_device->setWindowCaption(winName.c_str());
}

bomb::GameEngine::~GameEngine()
{
	_device->drop();
	_videoDriver->drop();
	_sceneManager->drop();
}

void bomb::GameEngine::refresh()
{
	_videoDriver->beginScene(true, true, irr::video::SColor(255,0,0,255));
	_sceneManager->drawAll();
	_videoDriver->endScene();
}

irr::gui::IGUIEnvironment *bomb::GameEngine::loadGui()
{
	return _device->getGUIEnvironment();
}

irr::video::ITexture *bomb::GameEngine::loadTexture(const std::string &path)
{
	return _videoDriver->getTexture(path.c_str());
}

std::unique_ptr<bomb::AnimatedObject>
bomb::GameEngine::getAnimatedObject(const std::string &path,
				    irr::core::vector3df pos,
				    irr::core::vector3df rot,
				    irr::core::vector3df scale)
{
	auto ptr = std::make_unique<bomb::AnimatedObject>(
		_sceneManager->addAnimatedMeshSceneNode(
			_sceneManager->getMesh(path.c_str())));
	ptr->setPos(pos);
	ptr->setRot(rot);
	ptr->setScale(scale);
	return ptr;
}

std::unique_ptr<bomb::StaticObject>
bomb::GameEngine::getStaticObject(const std::string &path,
				    irr::core::vector3df pos,
				    irr::core::vector3df rot,
				    irr::core::vector3df scale)
{
	auto ptr = std::make_unique<bomb::StaticObject>(
		_sceneManager->addMeshSceneNode(
			_sceneManager->getMesh(path.c_str())));
	ptr->setPos(pos);
	ptr->setRot(rot);
	ptr->setScale(scale);
	return ptr;
}
