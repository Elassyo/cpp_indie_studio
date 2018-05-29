//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// MapWall.cpp
//

#include "MapWall.hpp"

bomb::MapWall::MapWall(
	const irr::core::vector3df &pos,
	const irr::core::vector3df &scale,
	const irr::core::vector3df &rotation,
	bomb::MapWall::Status status,
	size_t hp):
	AObject(pos, scale, rotation), _status(status), _hp(hp)
{
}

bomb::MapWall::MapWall(const bomb::MapWall &ex):
	AObject(ex)
{
}

bool bomb::MapWall::bomb(size_t dammage)
{
	switch (_status) {
	case BREAKABLE:
		_hp -= dammage;
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
