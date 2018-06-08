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
				irr::core::vector2df pos, int id);
			void setVisibility(bool visibility);
			void update(irr::core::vector2di size,
				irr::core::vector2di screenSize);
			void setPos(irr::core::vector2df pos);
			void setText(const wchar_t *text);
			int getId() const;
			void remove();

		protected:
			const int _id;

		private:
			irr::gui::IGUIElement *_element;
			irr::core::vector2df _pos;
		};
	}
}

#endif //CPP_TEST_STUDIO_GraphicElement_HPP
