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
		enum MenuFonts {
			BASIC,
			TITLE
		};
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
			void addText(wchar_t *text,
				     irr::core::vector2df pos, int id);
			void setButtonPos(int buttonId,
					  irr::core::vector2df pos);
			void setButtonText(int buttonId, const wchar_t *text);
			void setButtonFont(int buttonId, MenuFonts font);
			void setButtonTextures(int buttonId,
					       irr::video::ITexture *texture,
					       irr::video::ITexture *pressed);
			void setButtonTexture(int buttonId,
					      irr::video::ITexture *texture);
			void setButtonPressedTexture(int buttonId,
						irr::video::ITexture *pressed);
			void setButtonEvent(int buttonId, std::function<void()>
			event);
			void setTextPos(int textId, irr::core::vector2df pos);
			void setTextText(int textId, const wchar_t *text);
			void setTextFont(int textId, MenuFonts font);
			bool handleEvent(const irr::SEvent &event);
			void clean();
		private:
			long long getButtonById(int buttonId);
			long long getTextById(int textId);
			irr::gui::IGUIButton *createButton(
				irr::core::vector2di pos,
				irr::core::vector2di size,
				int id);
			irr::gui::IGUIStaticText *createText(
				const wchar_t *title, int id);
			irr::gui::IGUIEnvironment *_gui;
			irr::core::vector2df _buttonRatio;
			irr::video::ITexture *_buttonBack;
			irr::video::ITexture *_buttonPressed;
			std::map<MenuFonts, irr::gui::IGUIFont *> _fonts;
			std::vector<GraphicButton> _buttons;
			std::vector<GraphicText> _texts;
			irr::core::vector2df pos;
		};
	}
}

#endif //CPP_TEST_STUDIO_MENU_HPP
