//
// EPITECH PROJECT, 2018
// cpp_test_studio - Menu.cpp
// File description:
// Created by Gregory EPLE
//

#include <iostream>
#include "Menu.hpp"

bomb::menu::Menu::Menu(irr::video::IVideoDriver *driver,
		 irr::gui::IGUIEnvironment *gui) :
	_driver(driver), _gui(gui), _size(0),
	_buttonRatio(irr::core::vector2df(.125, .1)),
	_buttonBack(driver->getTexture("assets/images/buttonBack.png")),
	_buttonPressed(driver->getTexture("assets/images/buttonPressed.png")),
	_font(_gui->getFont("assets/fonts/mario16.xml")),
	_titleFont(_gui->getFont("assets/fonts/marioColor36.xml")),
	_title(createTitle(L"SUPER\nBOMBERMAN\nBROS."))
{
	std::cout << "Create Scene" << std::endl;
	_gui->getSkin()->setFont(_font);
	_gui->getSkin()->setColor(irr::gui::EGDC_BUTTON_TEXT,
				  irr::video::SColor(255, 255, 255, 255));
	updateButtons(true);
}

void bomb::menu::Menu::addButton(std::function <void ()> event,
				 const wchar_t *text,
				irr::core::vector2df pos)
{
	irr::gui::IGUIButton * irrButton = createButton(
		{0, 0}, getButtonSize(), text);
	GraphicButton button(GraphicButton(irrButton, pos));
	button.setEvent(event);
	button.setTexture(_buttonBack, _buttonPressed);
	_buttons.emplace_back(button);
	updateButtons(true);
}

bomb::menu::GraphicText bomb::menu::Menu::createTitle(const wchar_t *title)
{
	GraphicText text(_gui->addStaticText(title, {0, 0, 1, 1}), {0.5, 0.15});
	text.setFont(_titleFont);
	return text;
}

irr::gui::IGUIButton *bomb::menu::Menu::createButton(
	irr::core::vector2di pos, irr::core::vector2di size,
	const wchar_t *text)
{
	return _gui->addButton({pos.X, pos.Y, pos.X + size.X, pos.Y + size.Y},
			       nullptr, -1, text);
}

void bomb::menu::Menu::handleEvent()
{
	for (auto &button : _buttons)
		if (button.isPressed() && button.getEvent())
			button.getEvent()();
}

void bomb::menu::Menu::updateButtons(bool areVisible)
{
	const irr::core::vector2di buttonSize = getButtonSize();
	const irr::core::vector2di screenSize =
		{(int)_driver->getScreenSize().Width,
		 (int)_driver->getScreenSize().Height};

	_title.update({1, 1}, screenSize);
	_title.setVisibility(areVisible);
	for (auto &button : _buttons) {
		button.setVisibility(areVisible);
		button.update(buttonSize, screenSize);
	}
	handleEvent();
}

irr::core::vector2di bomb::menu::Menu::getButtonSize() const
{
	const irr::core::dimension2du &screenSize = _driver->getScreenSize();

	return {(int)(_buttonRatio.X * screenSize.Width),
		(int)(_buttonRatio.Y * screenSize.Height)};
}