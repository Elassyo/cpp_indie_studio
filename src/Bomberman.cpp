//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// Bomberman.cpp
//

#include "Scene/GameScene.hpp"

int main()
{
	bomb::GameEngine ge(L"caca", 600, 600, irr::video::EDT_OPENGL);
	bomb::scene::GameScene scene(ge);

	scene.gameLoop();
}
