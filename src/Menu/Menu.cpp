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
	_buttonPressed(driver->getTexture("assets/images/buttonPressed.png")),
	_font(_gui->getFont("assets/fonts/mario16.xml"))
{
	const irr::core::vector2di buttonSize = getButtonSize();
	std::array<ButtonInfos, 6> buttonsInfos = getButtonsInfos();

	for (ButtonInfos infos : buttonsInfos) {
		GraphicButton button(GraphicButton(
			createButton({0, 0}, buttonSize, infos.text),
			infos.pos, infos.page));
		button.setEvent(infos.event);
		button.setFont(_font);
		button.setTexture(_buttonBack, _buttonPressed);
		_buttons.emplace_back(button);
	}
	updateButtons();
}

std::array<bomb::ButtonInfos, 6> bomb::Menu::getButtonsInfos() const
{
	return std::array<ButtonInfos, 6>
		{{{(wchar_t *)L"PLAY", {0.5, 0.33}, MAIN, nullptr},
			 {(wchar_t *)L"OPTION", {0.5, 0.5}, MAIN,
				 &bomb::Menu::goToOption},
			 {(wchar_t *)L"EXIT", {0.5, 0.66}, MAIN,
				 &bomb::Menu::closeMenu},
			 {(wchar_t *)L"Test", {0.5, 0.5}, OPTION, nullptr},
			 {(wchar_t *)L"Back to main", {0.5, 0.66}, OPTION,
				 &bomb::Menu::goToMain},
			 {(wchar_t *)L"MENU", {0.5, 0.9}, CLOSE,
				 &bomb::Menu::goToMain}}};

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
	for (GraphicButton button : _buttons)
		if (button.isPressed() && button.getEvent())
			(*this.*button.getEvent())();
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

void bomb::Menu::goToMain()
{
	changePage(MAIN);
}

void bomb::Menu::goToOption()
{
	changePage(OPTION);
}

void bomb::Menu::closeMenu()
{
	changePage(CLOSE);
}
