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

	#include "GraphicImage.hpp"

	#include "../Interface/IAssetManager.hpp"

namespace bomb {
	namespace menu {
		enum MenuFonts {
			BASIC,
			TITLE
		};
		class Menu {
		public:
			Menu();

			void createMenu(IAssetManager &loader);
			void updateButtons(IAssetManager &loader,
						bool areVisible);
			void addButton(const wchar_t *text,
				       irr::core::vector2df pos, int id);
			void addText(const wchar_t *text,
				     irr::core::vector2df pos, int id);
			void addImage(irr::video::ITexture *texture,
				     irr::core::vector2df pos, int id);
			void setButtonTextures(int buttonId,
					       irr::video::ITexture *texture,
					       irr::video::ITexture *pressed);
			void setButtonPressedTexture(int buttonId,
						     irr::video::ITexture *);
			void setButtonEvent(int buttonId,
					    std::function<void()> event);
			void setButtonPushable(int buttonId, bool isPushable);
			void setElementPos(int elementId,
					   irr::core::vector2df pos);
			void setElementSize(int elementId,
					    irr::core::vector2df size);
			void setElementText(int elementId, const wchar_t *text);
			void setElementFont(int elementId, MenuFonts font);
			void setElementTexture(int elementId,
					       irr::video::ITexture *texture);
			void setElementVisibility(int elementId,
						  bool visibility);
			void setElementRenderMode(int id, GraphicElement::RenderMode rMode);
			bool handleEvent(const irr::SEvent &event);
			void clean();

		private:
			long long getButtonById(int buttonId);
			long long getElementById(int elementId);
			irr::gui::IGUIButton *createButton(int id);
			irr::gui::IGUIStaticText *createText(
				const wchar_t *title, int id);
			irr::gui::IGUIImage *createImage(
				irr::video::ITexture *texture, int id);
			irr::gui::IGUIEnvironment *_gui;
			irr::core::vector2df _buttonRatio;
			irr::video::ITexture *_buttonBack;
			irr::video::ITexture *_buttonPressed;
			std::map<MenuFonts, irr::gui::IGUIFont *> _fonts;
			std::vector<std::unique_ptr<GraphicButton>> _buttons;
			std::vector<std::unique_ptr<GraphicElement>> _elements;
			irr::core::vector2df pos;
		};
	}
}

#endif //CPP_TEST_STUDIO_MENU_HPP
