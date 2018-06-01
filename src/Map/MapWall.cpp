//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapWall.cpp
//

#include "MapWall.hpp"

bomb::MapWall::MapWall(
	StaticObject &obj,
	bomb::MapWall::Status status,
	size_t hp) :
	_status(status), _hp(hp), _obj(obj)
{
}

bool bomb::MapWall::bomb(size_t damage)
{
	switch (_status) {
	case BREAKABLE:
		_hp -= damage;
		break;
	case UNBREAKABLE:
		break;
	}
	return _hp > 0;
}

size_t bomb::MapWall::getHp() const
{
	return _hp;
}

void bomb::MapWall::setHp(size_t hp)
{
	MapWall::_hp = hp;
}
