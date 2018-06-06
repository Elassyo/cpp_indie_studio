#include <irrlicht/irrlicht.h>
#include <iostream>

#include "../src/Menu/Menu.hpp"

int main()
{
	irr::IrrlichtDevice *device =
		irr::createDevice( irr::video::EDT_OPENGL,
			irr::core::dimension2d<irr::u32>(640, 480), 16,
			false, false, false, 0);
	if (!device)
		return 1;
	device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");
	irr::video::IVideoDriver* driver = device->getVideoDriver();
	irr::scene::ISceneManager* smgr = device->getSceneManager();
	irr::gui::IGUIEnvironment* guienv = device->getGUIEnvironment();
	guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",
			      irr::core::rect<irr::s32>(10, 10, 260, 22), true);
	smgr->addCameraSceneNode(0, irr::core::vector3df(0, 30, -40),
				 irr::core::vector3df(0, 5, 0));
	bomb::menu::Menu menu(driver, guienv);
	menu.addButton([](){std::cout << "Oscour g vu du code de Greg" <<
				      std::endl;},
		       L"GREG", {0.5, 0.5});
	while(device->run())
	{
		driver->beginScene(true, true,
				irr::video::SColor(255, 100, 101, 140));
		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();
		menu.updateButtons(true);
	}
	device->drop();
	return 0;
}