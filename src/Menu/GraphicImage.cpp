//
// EPITECH PROJECT, 2018
// cpp_test_studio - GraphicImage.cpp
// File description:
// Created by Gregory EPLE
//

#include "GraphicImage.hpp"

bomb::menu::GraphicImage::GraphicImage(irr::gui::IGUIImage *image,
				     irr::core::vector2df pos, int id) :
	GraphicElement(image, pos, id), _element(image)
{
	image->setScaleImage(true);
}

void bomb::menu::GraphicImage::setTexture(irr::video::ITexture *texture)
{
	_element->setImage(texture);
}

void bomb::menu::GraphicImage::setFont(irr::gui::IGUIFont *font)
{
	font = font;
}
