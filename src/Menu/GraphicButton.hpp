//
// EPITECH PROJECT, 2018
// cpp_test_studio - GraphicButton.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_TEST_STUDIO_GRAPHICBUTTON_HPP
	#define CPP_TEST_STUDIO_GRAPHICBUTTON_HPP

	#include "GraphicElement.hpp"

namespace bomb {
	namespace menu {
		class Menu;

		struct ButtonInfos {
			wchar_t *text;
			irr::core::vector2df pos;
			MenuPage page;
			void (bomb::menu::Menu::*event)();
		};

		class GraphicButton : public GraphicElement {
		public:
			GraphicButton(irr::gui::IGUIButton *button,
				      irr::core::vector2df pos,
				      MenuPage page = UNDEFINED);
			bool isPressed() const;
			void setFont(irr::gui::IGUIFont *font);
			void setTexture(irr::video::ITexture *texture,
					irr::video::ITexture *pressed);
			void (bomb::menu::Menu::*getEvent() const )();
			void setEvent(void (bomb::menu::Menu::*_event)());

		private:
			void (bomb::menu::Menu::*_event)();
		};
	}
}

#endif //CPP_TEST_STUDIO_GRAPHICBUTTON_HPP
