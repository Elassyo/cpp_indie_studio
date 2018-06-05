//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// BomberMario.cpp
//

#include "Exception/Exception.hpp"
#include "Render/GameEngine.hpp"
#include "Scenes/SceneLauncher.hpp"

int main()
{
	bomb::GameEngine engine(L"BomberMario", 600, 600,
		irr::video::EDT_OPENGL);
	bomb::scene::SceneLauncher launcher(engine);

	try {
		launcher.launchScene("game_scene");
	} catch (bomb::Exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
