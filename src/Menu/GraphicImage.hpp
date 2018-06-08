//
// EPITECH PROJECT, 2018
// cpp_test_studio - GraphicImage.hpp
// File description:
// Created by Gregory EPLE
//

#ifndef CPP_TEST_STUDIO_GRAPHICIMAGE_HPP
#define CPP_TEST_STUDIO_GRAPHICIMAGE_HPP

#include "GraphicElement.hpp"

namespace bomb {
	namespace menu {
		class GraphicImage : public GraphicElement {
		public:
			GraphicImage(irr::gui::IGUIImage *image,
				    irr::core::vector2df pos, int id);
			void setTexture(irr::video::ITexture *texture) override;
			void setFont(irr::gui::IGUIFont *font) override;

		private:
			irr::gui::IGUIImage *_element;
		};
	}
}

#endif //CPP_TEST_STUDIO_GRAPHICIMAGE_HPP
