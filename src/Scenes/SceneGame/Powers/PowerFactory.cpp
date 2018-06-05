//
// EPITECH PROJECT, 2018
// cpp_indie_studio - PowerFactory.cpp
// File description:
// Created by Gregory EPLE
//

#include "PowerFactory.hpp"

bomb::object::PowerFactory::PowerFactory() :
	_powers({{&bomb::object::PowerFactory::createPtr<BombUp>, 10},
		 {&bomb::object::PowerFactory::createPtr<SpeedUp>, 10},
		 {&bomb::object::PowerFactory::createPtr<FireUp>, 10},
		 {&bomb::object::PowerFactory::createPtr<BombDown>, 5},
		 {&bomb::object::PowerFactory::createPtr<SpeedDown>, 5},
		 {&bomb::object::PowerFactory::createPtr<FireDown>, 5},
		 {&bomb::object::PowerFactory::createPtr<WallPass>, 1},
		 {&bomb::object::PowerFactory::createPtr<BombPass>, 1}}),
	_total(0)
{
	for (std::pair<std::unique_ptr<Power>(bomb::object::PowerFactory::*)
			(bomb::IAssetLoader &,
			 const irr::core::vector3df &), int> power : _powers)
		_total += power.second;
}

std::unique_ptr<bomb::object::Power>
bomb::object::PowerFactory::getRandomPower(bomb::IAssetLoader &loader,
					   const irr::core::vector3df &pos)
{
	int item = (int)((float)random() / RAND_MAX * _total);
	int actual = 0;

	if (_total == 0)
		return nullptr;
	for (std::pair<std::unique_ptr<Power>(bomb::object::PowerFactory::*)
			(bomb::IAssetLoader &,
			 const irr::core::vector3df &), int> power : _powers) {
		if (item >= actual && item < actual + power.second)
			return (this->*power.first)(loader, pos);
	}
	return (this->*_powers[_powers.size() - 1].first)(loader, pos);
}

template<class T> std::unique_ptr<bomb::object::Power>
bomb::object::PowerFactory::createPtr(bomb::IAssetLoader &loader,
				      const irr::core::vector3df &pos)
{
	return std::make_unique<T>(loader, pos);
}