//
// EPITECH PROJECT, 2018
// cpp_test_studio - Menu.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_TEST_STUDIO_MENU_HPP
	#define CPP_TEST_STUDIO_MENU_HPP

	#include <vector>

	#include <array>

	#include "GraphicButton.hpp"

namespace bomb {
	class Menu {
	public:
		Menu(irr::video::IVideoDriver *driver,
		     irr::gui::IGUIEnvironment *gui, MenuPage page = MAIN);
		void changePage(MenuPage page = UNDEFINED);
		void handleEvent();
		void updateButtons();

	private:
		std::array<ButtonInfos, 6> getButtonsInfos() const;
		irr::gui::IGUIButton *createButton(irr::core::vector2di pos,
						   irr::core::vector2di size,
						   const wchar_t *text = L"");
		irr::core::vector2di getButtonSize() const;
		void goToMain();
		void goToOption();
		void closeMenu();
		irr::video::IVideoDriver *_driver;
		irr::gui::IGUIEnvironment *_gui;
		MenuPage _page;
		std::vector<GraphicButton> _buttons;
		irr::core::vector2df _buttonRatio;
		irr::video::ITexture *_buttonBack;
		irr::video::ITexture *_buttonPressed;
		irr::gui::IGUIFont *_font;
	};
}

#endif //CPP_TEST_STUDIO_MENU_HPP
