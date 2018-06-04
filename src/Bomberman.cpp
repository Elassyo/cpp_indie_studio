//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Bomberman.cpp
//

#include "Render/GameEngine.hpp"
#include "Scenes/SceneLauncher.hpp"
#include "Exception/Exception.hpp"

int main()
{
	bomb::GameEngine ge(L"BomberMario", 600, 600, irr::video::EDT_OPENGL);
	bomb::scene::SceneLauncher launcher(ge);

	try {
		launcher.launchScene("game_test");
	} catch (bomb::Exception &e) {
		std::cout << e.what() << std::endl;
	}
	return (0);
}
