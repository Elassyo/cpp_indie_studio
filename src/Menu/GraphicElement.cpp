//
// EPITECH PROJECT, 2018
// cpp_test_studio - GraphicElement.cpp
// File description:
// Created by Gregory EPLE
//

#include "GraphicElement.hpp"

bomb::menu::GraphicElement::GraphicElement(irr::gui::IGUIElement *element,
					   irr::core::vector2df pos, int id) :
	_id(id), _element(element), _pos(pos),
	_size(irr::core::vector2df(1, 1)), _renderMode(NORMAL)
{
}

void bomb::menu::GraphicElement::setVisibility(bool visibility)
{
	_element->setVisible(visibility);
}

void bomb::menu::GraphicElement::update(const irr::core::vector2di &screenSize)
{
	switch (_renderMode) {
		case HEIGHT_BASED:
			return updateFromRenderMode(screenSize,
				{screenSize.Y, screenSize.Y});
		case WIDTH_BASED:
			return updateFromRenderMode(screenSize,
				{screenSize.X, screenSize.X});
		default:
			return updateFromRenderMode(screenSize, screenSize);
	}
}

void bomb::menu::GraphicElement::setPos(irr::core::vector2df pos)
{
	_pos = pos;
}

void bomb::menu::GraphicElement::setSize(irr::core::vector2df size)
{
	_size = size;
}

void bomb::menu::GraphicElement::setText(const wchar_t *text)
{
	_element->setText(text);
}

void bomb::menu::GraphicElement::setToolTipText(const wchar_t *text)
{
	_element->setToolTipText(text);
}

int bomb::menu::GraphicElement::getId() const
{
	return _id;
}

void bomb::menu::GraphicElement::updateFromRenderMode(
	const irr::core::vector2di &screenSize,
	const irr::core::vector2di &ratio)
{
	irr::core::vector2df size = {(float)(ratio.X * _size.X),
				     (float)(ratio.Y * _size.Y)};

	_element->setMinSize({(unsigned int)size.X, (unsigned int)size.Y});
	_element->setMaxSize({(unsigned int)size.X, (unsigned int)size.Y});
	_element->setRelativePosition(
		{(int)(screenSize.X * _pos.X - size.X / 2),
		 (int)(screenSize.Y * _pos.Y - size.Y / 2)});
}

bomb::menu::GraphicElement::RenderMode
bomb::menu::GraphicElement::getRenderMode() const
{
	return _renderMode;
}

void bomb::menu::GraphicElement::setRenderMode(
	bomb::menu::GraphicElement::RenderMode renderMode)
{
	GraphicElement::_renderMode = renderMode;
}
