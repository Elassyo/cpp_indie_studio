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
			      irr::core::vector2df pos,
			      MenuPage page = UNDEFINED);
		bool isPressed() const;
		bool isOnPage(MenuPage page) const;
		void setVisibility(bool visibility);
		void setFont(irr::gui::IGUIFont *font);
		void setTexture(irr::video::ITexture *texture);
		void setPage(MenuPage page);
		MenuPage getPage() const;
		void update(irr::core::vector2di size,
			    irr::core::vector2di screenSize);

	private:
		irr::gui::IGUIButton *_button;
		irr::core::vector2df _pos;
		MenuPage _page;
	};
}

#endif //CPP_TEST_STUDIO_GRAPHICBUTTON_HPP
