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
	class GraphicText : public GraphicElement {
	public:
		GraphicText(irr::gui::IGUIStaticText *text,
			      irr::core::vector2df pos,
			      MenuPage page = UNDEFINED);
		void setFont(irr::gui::IGUIFont *font);

	};
}

#endif //CPP_TEST_STUDIO_GraphicText_HPP
