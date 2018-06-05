//
// EPITECH PROJECT, 2018
// cpp_test_studio - GraphicText.cpp
// File description:
// Created by Gregory EPLE
//

#include "GraphicText.hpp"

bomb::menu::GraphicText::GraphicText(irr::gui::IGUIStaticText *text,
	irr::core::vector2df pos) :
	GraphicElement(text, pos)
{
	text->setTextAlignment(irr::gui::EGUIA_CENTER, irr::gui::EGUIA_CENTER);
	text->setTextRestrainedInside(false);
}

void bomb::menu::GraphicText::setFont(irr::gui::IGUIFont *font)
{
	((irr::gui::IGUIStaticText *)_element)->setOverrideFont(font);
}
