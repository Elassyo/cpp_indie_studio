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
	enum MenuPage {
		UNDEFINED,
		CLOSE,
		MAIN,
		OPTION,
	};

	class GraphicElement {
	public:
		GraphicElement(irr::gui::IGUIElement *element,
			      irr::core::vector2df pos,
			      MenuPage page = UNDEFINED);
		bool isOnPage(MenuPage page) const;
		void setVisibility(bool visibility);
		void setPage(MenuPage page);
		MenuPage getPage() const;
		void update(irr::core::vector2di size,
			    irr::core::vector2di screenSize);

	protected:
		irr::gui::IGUIElement *_element;

	private:
		irr::core::vector2df _pos;
		MenuPage _page;
	};
}

#endif //CPP_TEST_STUDIO_GraphicElement_HPP
