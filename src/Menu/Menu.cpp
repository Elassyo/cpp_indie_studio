//
// EPITECH PROJECT, 2018
// cpp_test_studio - Menu.cpp
// File description:
// Created by Gregory EPLE
//

#include "Menu.hpp"

bomb::Menu::Menu(irr::gui::IGUIEnvironment *gui, MenuPage page) :
	_gui(gui), _page(page)
{
	_buttons.emplace_back(createButton({100, 75}, {100, 50},
		L"PLAY"), MAIN);
	_buttons.emplace_back(createButton({100, 150}, {100, 50},
		L"OPTION"), MAIN);
	_buttons.emplace_back(createButton({100, 225}, {100, 50},
		L"EXIT"), MAIN);
	_buttons.emplace_back(createButton({75, 125}, {150, 100},
		L"Back to main"), OPTION);
	_buttons.emplace_back(createButton({0, 0}, {50, 50},
		L"MENU"), CLOSE);
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
	for (GraphicButton &button : _buttons)
		button.setVisibility(button.isOnPage(_page));
}
