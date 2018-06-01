//
// EPITECH PROJECT, 2018
// cpp_test_studio - GraphicButton.cpp
// File description:
// Created by Gregory EPLE
//

#include "GraphicButton.hpp"

bomb::menu::GraphicButton::GraphicButton(irr::gui::IGUIButton *button,
					 irr::core::vector2df pos,
					 MenuPage page) :
	GraphicElement(button, pos, page), _event(nullptr)
{
	button->setScaleImage(true);
	button->setDrawBorder(false);
	button->setUseAlphaChannel(true);
}

bool bomb::menu::GraphicButton::isPressed() const
{
	return ((irr::gui::IGUIButton *)_element)->isPressed();
}

void bomb::menu::GraphicButton::setFont(irr::gui::IGUIFont *font)
{
	((irr::gui::IGUIButton *)_element)->setOverrideFont(font);
}

void bomb::menu::GraphicButton::setTexture(irr::video::ITexture *texture,
					   irr::video::ITexture *pressed)
{
	((irr::gui::IGUIButton *)_element)->setImage(texture);
	((irr::gui::IGUIButton *)_element)->setPressedImage(pressed);
}

void (bomb::menu::Menu::*bomb::menu::GraphicButton::getEvent() const)()
{
	return _event;
}

void bomb::menu::GraphicButton::setEvent(void (bomb::menu::Menu::*event)())
{
	_event = event;
}
