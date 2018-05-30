//
// EPITECH PROJECT, 2018
// cpp_test_studio - Menu.cpp
// File description:
// Created by Gregory EPLE
//

#include "Menu.hpp"

bomb::Menu::Menu(irr::video::IVideoDriver *driver,
		 irr::gui::IGUIEnvironment *gui, MenuPage page) :
	_driver(driver), _gui(gui), _page(page),
	_buttonRatio(irr::core::vector2df(.2, .1)),
	_buttonBack(driver->getTexture("assets/images/buttonBack.png")),
	_font(_gui->getFont("assets/fonts/mario16.xml"))
{
	const irr::core::vector2di buttonSize = getButtonSize();

	_buttons.emplace_back(GraphicButton(createButton(
		{0, 0}, buttonSize, L"PLAY"), {0.5, 0.33}, MAIN));
	_buttons.emplace_back(GraphicButton(createButton(
		{0, 0}, buttonSize, L"OPTION"), {0.5, 0.5}, MAIN));
	_buttons.emplace_back(GraphicButton(createButton(
		{0, 0}, buttonSize, L"EXIT"), {0.5, 0.66}, MAIN));
	_buttons.emplace_back(GraphicButton(createButton(
		{0, 0}, buttonSize, L"Back to main"), {0.5, 0.5}, OPTION));
	_buttons.emplace_back(GraphicButton(createButton(
		{0, 0}, buttonSize, L"MENU"), {0.5, 0.9}, CLOSE));
	for (GraphicButton &button : _buttons) {
		button.setFont(_font);
		button.setTexture(_buttonBack);
	}
	updateButtons();
}

irr::gui::IGUIButton *bomb::Menu::createButton(irr::core::vector2di pos,
					       irr::core::vector2di size,
					       const wchar_t *text)
{
	return _gui->addButton(irr::core::rect<irr::s32>(pos.X, pos.Y,
							 pos.X + size.X,
							 pos.Y + size.Y),
		nullptr, -1, text);
}

void bomb::Menu::changePage(MenuPage page)
{
	if (page == UNDEFINED)
		_page = _page == CLOSE ? MAIN : CLOSE;
	else
		_page = page;
	updateButtons();
}

void bomb::Menu::handleEvent()
{
	if (_buttons[0].isPressed() || _buttons[2].isPressed())
		changePage(CLOSE);
	else if (_buttons[1].isPressed())
		changePage(OPTION);
	else if (_buttons[3].isPressed() || _buttons[4].isPressed())
		changePage(MAIN);
}

void bomb::Menu::updateButtons()
{
	const irr::core::vector2di buttonSize = getButtonSize();
	const irr::core::vector2di screenSize =
		{(int)_driver->getScreenSize().Width,
		 (int)_driver->getScreenSize().Height};

	for (GraphicButton &button : _buttons) {
		button.setVisibility(button.isOnPage(_page));
		button.update(buttonSize, screenSize);
	}
}

irr::core::vector2di bomb::Menu::getButtonSize() const
{
	const irr::core::dimension2du &screenSize = _driver->getScreenSize();

	return {(int)(_buttonRatio.X * screenSize.Width),
		(int)(_buttonRatio.Y *screenSize.Height)};
}
