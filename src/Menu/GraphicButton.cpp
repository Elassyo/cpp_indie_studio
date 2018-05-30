//
// EPITECH PROJECT, 2018
// cpp_test_studio - GraphicButton.cpp
// File description:
// Created by Gregory EPLE
//

#include "GraphicButton.hpp"

bomb::GraphicButton::GraphicButton(irr::gui::IGUIButton *button,
				   irr::core::vector2df pos,
				   MenuPage page) :
	_button(button), _pos(pos), _page(page)
{
	_button->setDrawBorder(false);
}

bool bomb::GraphicButton::isPressed() const
{
	return _button->isPressed();
}

bool bomb::GraphicButton::isOnPage(MenuPage page) const
{
	return _page == page;
}

void bomb::GraphicButton::setVisibility(bool visibility)
{
	_button->setVisible(visibility);
}

void bomb::GraphicButton::setFont(irr::gui::IGUIFont *font)
{
	_button->setOverrideFont(font);
}

void bomb::GraphicButton::setTexture(irr::video::ITexture *texture)
{
	_button->setImage(texture);
}

void bomb::GraphicButton::update(irr::core::vector2di size,
				 irr::core::vector2di screenSize)
{
	_button->setMinSize({(unsigned int)size.X, (unsigned int)size.Y});
	_button->setMaxSize({(unsigned int)size.X, (unsigned int)size.Y});
	_button->setRelativePosition({(int)(screenSize.X * _pos.X - size.X / 2),
				      (int)(screenSize.Y
					    * _pos.Y - size.Y / 2)});
}

void bomb::GraphicButton::setPage(MenuPage page)
{
	_page = page;
}

bomb::MenuPage bomb::GraphicButton::getPage() const
{
	return _page;
}

