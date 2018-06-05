#include <irrlicht/irrlicht.h>
#include <src/Menu/Menu.hpp>
#include <iostream>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

#ifdef _IRR_WINDOWS_
#pragma comment(lib, "Irrlicht.lib")
#pragma comment(linker, "/subsystem:windows /ENTRY:mainCRTStartup")
#endif

int main()
{
	IrrlichtDevice *device =
		createDevice( video::EDT_OPENGL, dimension2d<u32>(640, 480), 16,
			false, false, false, 0);
	if (!device)
		return 1;
	device->setWindowCaption(L"Hello World! - Irrlicht Engine Demo");
	IVideoDriver* driver = device->getVideoDriver();
	ISceneManager* smgr = device->getSceneManager();
	IGUIEnvironment* guienv = device->getGUIEnvironment();
	guienv->addStaticText(L"Hello World! This is the Irrlicht Software renderer!",
		rect<s32>(10,10,260,22), true);
	IAnimatedMesh* mesh = smgr->getMesh("assets/models/blocks/brick.obj");
	if (!mesh)
	{
		device->drop();
		return 1;
	}
	IAnimatedMeshSceneNode* node = smgr->addAnimatedMeshSceneNode( mesh );
	if (node)
	{
		node->setMaterialFlag(EMF_LIGHTING, false);
		node->setMD2Animation(scene::EMAT_STAND);
		node->setMaterialTexture( 0, driver->getTexture
			("assets/models/blocks/spritesheet.png") );
	}
	smgr->addCameraSceneNode(0, vector3df(0,30,-40), vector3df(0,5,0));
	bomb::menu::Menu menu(driver, guienv);
	menu.addButton([](){std::cout << "Oscour g vu du code de Greg" <<
				      std::endl;},
		       L"GREG", {0.5, 0.5});
	while(device->run())
	{
		driver->beginScene(true, true, SColor(255,100,101,140));
		smgr->drawAll();
		guienv->drawAll();
		driver->endScene();
		menu.updateButtons(true);
	}
	device->drop();
	return 0;
}