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

	#include "../Interface/IAssetLoader.hpp"

namespace bomb {
	namespace menu {
		class Menu {
		public:
			Menu();

			void createMenu(IAssetLoader &loader);
			irr::core::vector2di
				getButtonSize(IAssetLoader &loader) const;
			void updateButtons(IAssetLoader &loader,
						bool areVisible);
			void addButton(IAssetLoader &loader,
				irr::core::vector2df pos, int id);
			void addButtonText(int buttonId, const wchar_t *text);
			void addButtonEvent(int buttonId, std::function<void()>
				event);
			bool handleEvent(const irr::SEvent &event);
			void clean();
		private:
			long long getButtonById(int buttonId);
			void createTitle(const wchar_t *text = L"");
			irr::gui::IGUIButton *createButton(
				irr::core::vector2di pos,
				irr::core::vector2di size,
				int id);
			irr::gui::IGUIEnvironment *_gui;
			std::unique_ptr<GraphicText> _title;
			irr::core::vector2df _buttonRatio;
			irr::video::ITexture *_buttonBack;
			irr::video::ITexture *_buttonPressed;
			irr::gui::IGUIFont *_font;
			irr::gui::IGUIFont *_titleFont;
			std::vector<GraphicButton> _buttons;
			irr::core::vector2df pos;
		};
	}
}

#endif //CPP_TEST_STUDIO_MENU_HPP
