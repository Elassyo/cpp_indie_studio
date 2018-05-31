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
	class Menu;

	enum MenuPage {
		UNDEFINED,
		CLOSE,
		MAIN,
		OPTION
	};

	struct ButtonInfos {
		wchar_t *text;
		irr::core::vector2df pos;
		MenuPage page;
		void (bomb::Menu::*event)();
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
		void setTexture(irr::video::ITexture *texture,
				irr::video::ITexture *pressed);
		void setPage(MenuPage page);
		MenuPage getPage() const;
		void update(irr::core::vector2di size,
			    irr::core::vector2di screenSize);
		void (bomb::Menu::*getEvent() const)();
		void setEvent(void (bomb::Menu::*_event)());

	private:
		irr::gui::IGUIButton *_button;
		irr::core::vector2df _pos;
		void (bomb::Menu::*_event)();
		MenuPage _page;
	};
}

#endif //CPP_TEST_STUDIO_GRAPHICBUTTON_HPP
