//
// EPITECH PROJECT, 2018
// cpp_test_studio - GraphicElement.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_TEST_STUDIO_GRAPHICELEMENT_HPP
	#define CPP_TEST_STUDIO_GRAPHICELEMENT_HPP

	#include <irrlicht/irrlicht.h>

namespace bomb {
	namespace menu {
		class GraphicElement {
		public:
			GraphicElement(irr::gui::IGUIElement *element,
				irr::core::vector2df pos, int id);
			void setVisibility(bool visibility);
			void update(const irr::core::vector2di &screenSize);
			void setPos(irr::core::vector2df pos);
			void setSize(irr::core::vector2df pos);
			void setText(const wchar_t *text);
			void setToolTipText(const wchar_t *text);
			virtual void setFont(irr::gui::IGUIFont *font) = 0;
			virtual void setTexture(
				irr::video::ITexture *texture) = 0;
			int getId() const;

		protected:
			const int _id;

		private:
			irr::gui::IGUIElement *_element;
			irr::core::vector2df _pos;
			irr::core::vector2df _size;
		};
	}
}

#endif //CPP_TEST_STUDIO_GRAPHICELEMENT_HPP
