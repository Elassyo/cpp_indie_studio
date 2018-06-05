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
	#include "GraphicText.hpp"

namespace bomb {
	namespace menu {
		class Menu {
		public:
			Menu(irr::video::IVideoDriver *driver,
				irr::gui::IGUIEnvironment *gui);
			void addButton(std::function <void ()> event,
				const wchar_t *text, irr::core::vector2df pos);
			void updateButtons(bool areVisibles);
			void handleEvent();

		private:
			GraphicText createTitle(const wchar_t *text = L"");
			irr::gui::IGUIButton *createButton(
				irr::core::vector2di pos,
				irr::core::vector2di size,
				const wchar_t *text = L"");

			irr::core::vector2di getButtonSize() const;
			
			irr::video::IVideoDriver *_driver;
			irr::gui::IGUIEnvironment *_gui;
			const uint8_t _size;
			irr::core::vector2df _buttonRatio;
			irr::video::ITexture *_buttonBack;
			irr::video::ITexture *_buttonPressed;
			irr::gui::IGUIFont *_font;
			irr::gui::IGUIFont *_titleFont;
			GraphicText _title;
			std::vector<GraphicButton> _buttons;
			irr::core::vector2df pos;
		};
	}
}

#endif //CPP_TEST_STUDIO_MENU_HPP
