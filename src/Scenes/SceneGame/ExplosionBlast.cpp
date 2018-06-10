//
// EPITECH PROJECT, 2018
// cpp_indie_studio
// File description:
// ExplosionBlast.cpp
//

#include "ExplosionBlast.hpp"

bomb::object::ExplosionBlast::ExplosionBlast(
	std::unique_ptr<bomb::BillboardObject> bo) :
		_billBoard(std::move(bo))
{
}

void bomb::object::ExplosionBlast::scaleDown()
{
	auto scale = _billBoard->getSize();
	_billBoard->setSize(scale / 1.1);
}

bool bomb::object::ExplosionBlast::isFinished() const
{
	if (_billBoard)
		return _billBoard->getSize().Height < 1.5f;
	return true;
}

std::unique_ptr<bomb::BillboardObject>
bomb::object::ExplosionBlast::releasePtr()
{
	return std::move(_billBoard);
}
