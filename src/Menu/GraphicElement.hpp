//
// EPITECH PROJECT, 2018
// cpp_test_studio - GraphicElement.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_TEST_STUDIO_GraphicElement_HPP
	#define CPP_TEST_STUDIO_GraphicElement_HPP

	#include <irrlicht/irrlicht.h>

namespace bomb {
	namespace menu {
		class GraphicElement {
		public:
			GraphicElement(irr::gui::IGUIElement *element,
				irr::core::vector2df pos);
			void setVisibility(bool visibility);
			void update(irr::core::vector2di size,
				irr::core::vector2di screenSize);
			void remove();
		protected:
			irr::gui::IGUIElement *_element;

		private:
			irr::core::vector2df _pos;
		};
	}
}

#endif //CPP_TEST_STUDIO_GraphicElement_HPP
