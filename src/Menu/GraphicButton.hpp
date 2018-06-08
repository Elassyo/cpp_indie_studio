//
// EPITECH PROJECT, 2018
// cpp_test_studio - GraphicButton.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_TEST_STUDIO_GRAPHICBUTTON_HPP
#define CPP_TEST_STUDIO_GRAPHICBUTTON_HPP

#include <functional>

#include "../Scenes/General/Clock.hpp"
#include "GraphicElement.hpp"

namespace bomb {
	namespace menu {
		class GraphicButton : public GraphicElement {
		public:
			GraphicButton(irr::gui::IGUIButton *button,
				      irr::core::vector2df pos, int id);
			bool isPressed(const irr::SEvent &event);
			const std::function<void()> &getEvent() const;
			void setFont(irr::gui::IGUIFont *font);
			void setTextures(irr::video::ITexture *texture,
					 irr::video::ITexture *pressed);
			void setTexture(irr::video::ITexture *texture);
			void setPressedTexture(irr::video::ITexture *pressed);
			void setEvent(std::function <void()> &);
		private:
			irr::gui::IGUIButton * _element;
			std::function <void()> _event;
			bomb::utils::Clock _latence;
		};
	}
}

#endif //CPP_TEST_STUDIO_GRAPHICBUTTON_HPP
