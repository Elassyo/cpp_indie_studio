//
// EPITECH PROJECT, 2018
// cpp_test_studio - GraphicElement.cpp
// File description:
// Created by Gregory EPLE
//

#include "GraphicElement.hpp"

bomb::GraphicElement::GraphicElement(irr::gui::IGUIElement *element,
				   irr::core::vector2df pos,
				   MenuPage page) :
	_element(element), _pos(pos), _page(page)
{
}

bool bomb::GraphicElement::isOnPage(MenuPage page) const
{
	return _page == UNDEFINED && page != CLOSE ? true : _page == page;
}

void bomb::GraphicElement::setVisibility(bool visibility)
{
	_element->setVisible(visibility);
}

void bomb::GraphicElement::update(irr::core::vector2di size,
				 irr::core::vector2di screenSize)
{
	_element->setMinSize({(unsigned int)size.X, (unsigned int)size.Y});
	_element->setMaxSize({(unsigned int)size.X, (unsigned int)size.Y});
	_element->setRelativePosition({(int)(screenSize.X * _pos.X - size.X / 2),
				      (int)(screenSize.Y
					    * _pos.Y - size.Y / 2)});
}

void bomb::GraphicElement::setPage(MenuPage page)
{
	_page = page;
}

bomb::MenuPage bomb::GraphicElement::getPage() const
{
	return _page;
}

