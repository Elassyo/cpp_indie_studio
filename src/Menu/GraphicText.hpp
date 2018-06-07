//
// EPITECH PROJECT, 2018
// cpp_test_studio - GraphicText.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_TEST_STUDIO_GraphicText_HPP
	#define CPP_TEST_STUDIO_GraphicText_HPP

	#include "GraphicElement.hpp"

namespace bomb {
	namespace menu {
		class GraphicText : public GraphicElement {
		public:
			GraphicText(irr::gui::IGUIStaticText *text,
				irr::core::vector2df pos);
			void setFont(irr::gui::IGUIFont *font);

		private:
			irr::gui::IGUIStaticText * _element;
		};
	}
}

#endif //CPP_TEST_STUDIO_GraphicText_HPP
