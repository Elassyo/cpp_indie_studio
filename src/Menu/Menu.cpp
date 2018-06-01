//
// EPITECH PROJECT, 2018
// cpp_test_studio - Menu.cpp
// File description:
// Created by Gregory EPLE
//

#include "Menu.hpp"

bomb::menu::Menu::Menu(irr::video::IVideoDriver *driver,
		 irr::gui::IGUIEnvironment *gui, MenuPage page) :
	_driver(driver), _gui(gui), _page(page),
	_buttonRatio(irr::core::vector2df(.125, .1)),
	_buttonBack(driver->getTexture("assets/images/buttonBack.png")),
	_buttonPressed(driver->getTexture("assets/images/buttonPressed.png")),
	_font(_gui->getFont("assets/fonts/mario16.xml")),
	_titleFont(_gui->getFont("assets/fonts/marioColor36.xml")),
	_title(createTitle(L"SUPER\nBOMBERMAN\nBROS."))
{
	const irr::core::vector2di buttonSize = getButtonSize();
	std::array<ButtonInfos, 6> buttonsInfos = getButtonsInfos();

	_gui->getSkin()->setFont(_font);
	_gui->getSkin()->setColor(irr::gui::EGDC_BUTTON_TEXT,
				  irr::video::SColor(255, 255, 255, 255));
	for (ButtonInfos infos : buttonsInfos) {
		GraphicButton button(GraphicButton(
			createButton({0, 0}, buttonSize, infos.text),
			infos.pos, infos.page));
		button.setEvent(infos.event);
		button.setTexture(_buttonBack, _buttonPressed);
		_buttons.emplace_back(button);
	}
	updateButtons();
}

std::array<bomb::menu::ButtonInfos, 6> bomb::menu::Menu::getButtonsInfos() const
{
	return std::array<ButtonInfos, 6>
		{{{(wchar_t *)L"PLAY", {0.5, 0.35}, MAIN, nullptr},
			 {(wchar_t *)L"OPTION", {0.5, 0.55}, MAIN,
				 &bomb::menu::Menu::goToOption},
			 {(wchar_t *)L"EXIT", {0.5, 0.75}, MAIN,
				 &bomb::menu::Menu::closeMenu},
			 {(wchar_t *)L"Test", {0.5, 0.55}, OPTION, nullptr},
			 {(wchar_t *)L"Back to main", {0.5, 0.75}, OPTION,
				 &bomb::menu::Menu::goToMain},
			 {(wchar_t *)L"MENU", {0.5, 0.9}, CLOSE,
				 &bomb::menu::Menu::goToMain}}};

}

bomb::menu::GraphicText bomb::menu::Menu::createTitle(const wchar_t *title)
{
	GraphicText text(_gui->addStaticText(title,
					     irr::core::rect<irr::s32>(0, 0,
								       1, 1)),
			 {0.5, 0.15});
	text.setFont(_titleFont);
	return text;
}

irr::gui::IGUIButton *bomb::menu::Menu::createButton(irr::core::vector2di pos,
					       irr::core::vector2di size,
					       const wchar_t *text)
{
	return _gui->addButton(irr::core::rect<irr::s32>(pos.X, pos.Y,
							 pos.X + size.X,
							 pos.Y + size.Y),
			       nullptr, -1, text);
}

void bomb::menu::Menu::changePage(MenuPage page)
{
	if (page == UNDEFINED)
		_page = _page == CLOSE ? MAIN : CLOSE;
	else
		_page = page;
	updateButtons();
}

void bomb::menu::Menu::handleEvent()
{
	for (GraphicButton button : _buttons)
		if (button.isPressed() && button.getEvent())
			(*this.*button.getEvent())();
}

void bomb::menu::Menu::updateButtons()
{
	const irr::core::vector2di buttonSize = getButtonSize();
	const irr::core::vector2di screenSize =
		{(int)_driver->getScreenSize().Width,
		 (int)_driver->getScreenSize().Height};

	_title.update({1, 1}, screenSize);
	_title.setVisibility(_title.isOnPage(_page));
	for (GraphicButton &button : _buttons) {
		button.setVisibility(button.isOnPage(_page));
		button.update(buttonSize, screenSize);
	}
}

irr::core::vector2di bomb::menu::Menu::getButtonSize() const
{
	const irr::core::dimension2du &screenSize = _driver->getScreenSize();

	return {(int)(_buttonRatio.X * screenSize.Width),
		(int)(_buttonRatio.Y *screenSize.Height)};
}

void bomb::menu::Menu::goToMain()
{
	changePage(MAIN);
}

void bomb::menu::Menu::goToOption()
{
	changePage(OPTION);
}

void bomb::menu::Menu::closeMenu()
{
	changePage(CLOSE);
}
