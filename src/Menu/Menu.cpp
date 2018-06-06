//
// EPITECH PROJECT, 2018
// cpp_test_studio - Menu.cpp
// File description:
// Created by Gregory EPLE
//

#include "Menu.hpp"

bomb::menu::Menu::Menu(IAssetLoader &loader) :
	_loader(loader), _gui(loader.getGui()), _size(0),
	_buttonRatio(irr::core::vector2df(0.125f, 0.1f)),
	_buttonBack(loader.loadTexture("images/buttonBack.png")),
	_buttonPressed(loader.loadTexture("images/buttonPressed.png")),
	_font(loader.loadFont("fonts/mario16.xml")),
	_titleFont(loader.loadFont("fonts/marioColor36.xml")),
	_title(createTitle(L"SUPER\nBOMBERMARIO\nBROS."))
{
	_gui->getSkin()->setFont(_font);
	_gui->getSkin()->setColor(irr::gui::EGDC_BUTTON_TEXT,
		irr::video::SColor(255, 255, 255, 255));
	updateButtons(true);
}

void bomb::menu::Menu::addButton(std::function <void()> event,
	const wchar_t *text, irr::core::vector2df pos)
{
	irr::gui::IGUIButton * irrButton = createButton({ 0, 0 },
		getButtonSize(), text);
	GraphicButton button(GraphicButton(irrButton, pos));
	button.setEvent(event);
	button.setTexture(_buttonBack, _buttonPressed);
	_buttons.emplace_back(button);
	updateButtons(true);
}

bomb::menu::GraphicText bomb::menu::Menu::createTitle(const wchar_t *title)
{
	GraphicText text(_gui->addStaticText(title, { 0, 0, 1, 1 }),
		{ 0.5f, 0.15f });
	text.setFont(_titleFont);
	return text;
}

irr::gui::IGUIButton *bomb::menu::Menu::createButton(
	irr::core::vector2di pos, irr::core::vector2di size,
	const wchar_t *text)
{
	return _gui->addButton({ pos.X, pos.Y, pos.X + size.X, pos.Y + size.Y },
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
	{ (int)_loader.getScreenSize().Width,
		(int)_loader.getScreenSize().Height };

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
	const irr::core::dimension2du &screenSize = _loader.getScreenSize();

	return { (int)(_buttonRatio.X * screenSize.Width),
		(int)(_buttonRatio.Y * screenSize.Height) };
}
