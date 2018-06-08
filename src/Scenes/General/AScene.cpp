//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// AScene.cpp
//

#include "AScene.hpp"

bomb::scene::AScene::AScene(bomb::PersistentInfo &_infos) : _infos(_infos)
{}

bomb::scene::SceneStatus bomb::scene::AScene::start(IAssetLoader &loader)
{
	return END;
}

bomb::scene::SceneStatus bomb::scene::AScene::loop(IAssetLoader &loader)
{
	return END;
}

void bomb::scene::AScene::save()
{

}

void bomb::scene::AScene::reset(IAssetLoader &loader)
{

}

void bomb::scene::AScene::clean()
{

}

std::string bomb::scene::AScene::nextScene()
{
	return std::__cxx11::string();
}