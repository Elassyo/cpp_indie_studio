//
// EPITECH PROJECT, 2018
// cpp_test_studio - GraphicButton.cpp
// File description:
// Created by Gregory EPLE
//

#include "GraphicButton.hpp"

bomb::menu::GraphicButton::GraphicButton(irr::gui::IGUIButton *button,
	irr::core::vector2df pos) :
	GraphicElement(button, pos), _event(nullptr)
{
	button->setScaleImage(true);
	button->setDrawBorder(false);
	button->setUseAlphaChannel(true);
	_latence.setTimerInterval(250);
	_latence.reset();
}

bool bomb::menu::GraphicButton::isPressed()
{
	if (_latence.isReady() &&
		((irr::gui::IGUIButton *) _element)->isPressed()) {
		_latence.reset();
		return true;
	}
	return false;
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

const std::function<void()> &bomb::menu::GraphicButton::getEvent() const
{
	return _event;
}

void bomb::menu::GraphicButton::setEvent(std::function <void ()> &event)
{
	_event = event;
}