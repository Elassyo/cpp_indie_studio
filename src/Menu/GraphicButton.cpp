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
	GraphicElement(button, pos, page), _event(nullptr)
{
	button->setScaleImage(true);
	button->setDrawBorder(false);
	button->setUseAlphaChannel(true);
}

bool bomb::GraphicButton::isPressed() const
{
	return ((irr::gui::IGUIButton *)_element)->isPressed();
}

void bomb::GraphicButton::setFont(irr::gui::IGUIFont *font)
{
	((irr::gui::IGUIButton *)_element)->setOverrideFont(font);
}

void bomb::GraphicButton::setTexture(irr::video::ITexture *texture,
				     irr::video::ITexture *pressed)
{
	((irr::gui::IGUIButton *)_element)->setImage(texture);
	((irr::gui::IGUIButton *)_element)->setPressedImage(pressed);
}

void (bomb::Menu::*bomb::GraphicButton::getEvent() const)()
{
	return _event;
}

void bomb::GraphicButton::setEvent(void (bomb::Menu::*event)())
{
	_event = event;
}
