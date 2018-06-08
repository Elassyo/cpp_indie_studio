//
// EPITECH PROJECT, 2018
// cpp_test_studio - GraphicText.cpp
// File description:
// Created by Gregory EPLE
//

#include "GraphicText.hpp"

bomb::menu::GraphicText::GraphicText(irr::gui::IGUIStaticText *text,
	irr::core::vector2df pos, int id) :
	GraphicElement(text, pos, id), _element(text)
{
	text->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);
	text->setTextRestrainedInside(false);
}

void bomb::menu::GraphicText::setFont(irr::gui::IGUIFont *font)
{
	_element->setOverrideFont(font);
}
