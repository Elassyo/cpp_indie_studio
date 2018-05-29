//
// EPITECH PROJECT, 2018
// cpp_test_studio - GraphicButton.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_TEST_STUDIO_GRAPHICBUTTON_HPP
#define CPP_TEST_STUDIO_GRAPHICBUTTON_HPP

#include <irrlicht/irrlicht.h>

namespace bomb {
	enum MenuPage {
		UNDEFINED,
		CLOSE,
		MAIN,
		OPTION
	};
	class GraphicButton {
	public:
		GraphicButton(irr::gui::IGUIButton *button,
			      MenuPage page = UNDEFINED);
		bool isPressed() const;
		bool isOnPage(MenuPage page) const;
		void setVisibility(bool visibility);
		void setPage(MenuPage page);
		MenuPage getPage() const;
	private:
		irr::gui::IGUIButton *_button;
		MenuPage _page;
	};
}

#endif //CPP_TEST_STUDIO_GRAPHICBUTTON_HPP
