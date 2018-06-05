//
// EPITECH PROJECT, 2018
// cpp_test_studio - GraphicButton.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_TEST_STUDIO_GRAPHICBUTTON_HPP
	#define CPP_TEST_STUDIO_GRAPHICBUTTON_HPP

	#include <functional>
#include <src/Scenes/General/Clock.hpp>
#include "GraphicElement.hpp"

namespace bomb {
	namespace menu {
		class GraphicButton : public GraphicElement {
		public:
			GraphicButton(irr::gui::IGUIButton *button,
				      irr::core::vector2df pos);
			bool isPressed();
			void setFont(irr::gui::IGUIFont *font);
			void setTexture(irr::video::ITexture *texture,
					irr::video::ITexture *pressed);
			void setEvent(std::function <void ()> &);
			const std::function<void()> &getEvent() const;
		private:
			std::function <void ()> _event;
			bomb::utils::Clock _latence;
		};
	}
}

#endif //CPP_TEST_STUDIO_GRAPHICBUTTON_HPP
