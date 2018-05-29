//
// EPITECH PROJECT, 2018
// cpp_test_studio - GraphicButton.cpp
// File description:
// Created by Gregory EPLE
//

#include "GraphicButton.hpp"

bomb::GraphicButton::GraphicButton(irr::gui::IGUIButton *button,
				   MenuPage page) :
	_button(button), _page(page)
{
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

void bomb::GraphicButton::setPage(MenuPage page)
{
	_page = page;
}

bomb::MenuPage bomb::GraphicButton::getPage() const
{
	return _page;
}

