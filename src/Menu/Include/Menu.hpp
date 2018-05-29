//
// EPITECH PROJECT, 2018
// cpp_test_studio - Menu.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_TEST_STUDIO_MENU_HPP
#define CPP_TEST_STUDIO_MENU_HPP

#include <vector>
#include "GraphicButton.hpp"

namespace bomb {
	class Menu {
	public:
		Menu(irr::gui::IGUIEnvironment *gui, MenuPage page = MAIN);
		void changePage(MenuPage page = UNDEFINED);
		void handleEvent();
	private:
		irr::gui::IGUIButton *createButton(irr::core::vector2di pos,
						   irr::core::vector2di size,
						   const wchar_t *text = L"");
		void updateButtons();
		irr::gui::IGUIEnvironment *_gui;
		MenuPage _page;
		std::vector<GraphicButton> _buttons;
	};
}

#endif //CPP_TEST_STUDIO_MENU_HPP
