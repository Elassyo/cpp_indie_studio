//
// EPITECH PROJECT, 2018
// cpp_test_studio - GraphicButton.cpp
// File description:
// Created by Gregory EPLE
//

#include "GraphicButton.hpp"

bomb::menu::GraphicButton::GraphicButton(irr::gui::IGUIButton *button,
	irr::core::vector2df pos, int id) :
	GraphicElement(button, pos, id), _element(button), _event(nullptr)
{
	button->setScaleImage(true);
	button->setDrawBorder(false);
	button->setUseAlphaChannel(true);
	_latence.setTimerInterval(250);
	_latence.reset();
}

bool bomb::menu::GraphicButton::isPressed(const irr::SEvent &event)
{
	if (irr::gui::EGET_BUTTON_CLICKED != event.GUIEvent.EventType)
		return false;
	irr::s32 id = event.GUIEvent.Caller->getID();
	if (_latence.isReady() && _id == id) {
		_latence.reset();
		return true;
	}
	return false;
}

void bomb::menu::GraphicButton::setFont(irr::gui::IGUIFont *font)
{
	_element->setOverrideFont(font);
}

void bomb::menu::GraphicButton::setTextures(irr::video::ITexture *texture,
					    irr::video::ITexture *pressed)
{
	setTexture(texture);
	setPressedTexture(pressed);
}

void bomb::menu::GraphicButton::setTexture(irr::video::ITexture *texture)
{
	_element->setImage(texture);
}

void bomb::menu::GraphicButton::setPressedTexture(irr::video::ITexture *pressed)
{
	_element->setPressedImage(pressed);
}

const std::function<void()> &bomb::menu::GraphicButton::getEvent() const
{
	return _event;
}

void bomb::menu::GraphicButton::setEvent(std::function <void ()> &event)
{
	_event = event;
}