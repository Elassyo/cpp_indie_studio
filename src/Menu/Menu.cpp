//
// EPITECH PROJECT, 2018
// cpp_test_studio - Menu.cpp
// File description:
// Created by Gregory EPLE
//

#include "Menu.hpp"

bomb::menu::Menu::Menu() :
	_buttonRatio(irr::core::vector2df(0.15f, 0.1f))
{
}

void bomb::menu::Menu::createMenu(IAssetManager &loader)
{
	_gui = loader.getGui();
	_buttonBack = loader.loadTexture("images/buttonBack.png");
	_buttonPressed = loader.loadTexture("images/buttonPressed.png");
	_fonts[BASIC] = loader.loadFont("fonts/mario24.xml");
	_fonts[TITLE] = loader.loadFont("fonts/marioColor36.xml");
	_gui->getSkin()->setFont(_fonts[BASIC]);
	_gui->getSkin()->setColor(irr::gui::EGDC_BUTTON_TEXT,
				  irr::video::SColor(255, 255, 255, 255));
}

void bomb::menu::Menu::addButton(const wchar_t *text,
				 irr::core::vector2df pos, int id)
{
	irr::gui::IGUIButton *irrButton = createButton(id);
	std::unique_ptr<GraphicButton> button =
		std::make_unique<GraphicButton>(irrButton, pos, id);
	button->setText(text);
	button->setSize(_buttonRatio);
	button->setTextures(_buttonBack, _buttonPressed);
	_buttons.emplace_back(std::move(button));
}

void bomb::menu::Menu::addText(const wchar_t *text,
			       irr::core::vector2df pos, int id)
{
	irr::gui::IGUIStaticText *irrText = createText(text, id);
	std::unique_ptr<GraphicText> gText =
		std::make_unique<GraphicText>(irrText, pos, id);
	_elements.emplace_back(std::move(gText));
}

void bomb::menu::Menu::addImage(irr::video::ITexture *texture,
				irr::core::vector2df pos, int id)
{
	irr::gui::IGUIImage *irrImg = createImage(texture, id);
	std::unique_ptr<GraphicImage> img =
		std::make_unique<GraphicImage>(irrImg, pos, id);
	_elements.emplace_back(std::move(img));
}

irr::gui::IGUIStaticText *bomb::menu::Menu::createText(
	const wchar_t *text, int id)
{
	return _gui->addStaticText(text, {1, 1, 1, 1},
				   false, true, nullptr, id);
}

irr::gui::IGUIImage *bomb::menu::Menu::createImage(
	irr::video::ITexture *texture, int id)
{
	return _gui->addImage(texture, {0, 0}, true, nullptr, id);
}

irr::gui::IGUIButton *bomb::menu::Menu::createButton(int id)
{
	return _gui->addButton({ 0, 0, 1, 1 }, nullptr, id);
}

void bomb::menu::Menu::updateButtons(IAssetManager &loader, bool areVisible)
{
	const irr::core::vector2di screenSize = {
		(int)loader.getScreenSize().Width,
		(int)loader.getScreenSize().Height };
	for (auto &button : _buttons) {
		button->update(screenSize);
		button->setVisibility(areVisible);
	}
	for (auto &element : _elements) {
		element->update(screenSize);
		element->setVisibility(areVisible);
	}
}

bool bomb::menu::Menu::handleEvent(const irr::SEvent &event) {
	for (auto &button : _buttons) {
		if (button->isPressed(event) && button->getEvent()) {
			button->getEvent()();
			return true;
		}
	}
	return false;
}

long long bomb::menu::Menu::getButtonById(int buttonId)
{
	auto it = std::find_if(_buttons.begin(),_buttons.end(), [buttonId]
		(const std::unique_ptr<GraphicButton> &button) {
		return button->getId() == buttonId;
	});
	if (it == _buttons.end())
		return -1;
	return it - _buttons.begin();
}

long long bomb::menu::Menu::getElementById(int elementId)
{
	auto it = std::find_if(_elements.begin(),_elements.end(), [elementId]
		(const std::unique_ptr<GraphicElement> &element) {
		return element->getId() == elementId;
	});
	if (it == _elements.end())
		return -1;
	return it - _elements.begin();
}

void bomb::menu::Menu::setButtonTextures(int buttonId,
					 irr::video::ITexture *texture,
					 irr::video::ITexture *prssed)
{
	long long idx = getButtonById(buttonId);

	if (idx == -1)
		return;
	_buttons.at(static_cast<unsigned long>(idx))->setTexture(texture);
	_buttons.at(static_cast<unsigned long>(idx))->setPressedTexture(prssed);
}

void bomb::menu::Menu::setButtonPressedTexture(int buttonId,
					       irr::video::ITexture *prssed)
{
	long long idx = getButtonById(buttonId);

	if (idx == -1)
		return;
	_buttons.at(static_cast<unsigned long>(idx))->setPressedTexture(prssed);
}

void bomb::menu::Menu::setButtonEvent(int buttonId, std::function<void()> event)
{
	long long idx = getButtonById(buttonId);

	if (idx == -1)
		return;
	_buttons.at(static_cast<unsigned long>(idx))->setEvent(event);
}

void
bomb::menu::Menu::setButtonPushable(int buttonId, bool isPushable)
{
	long long idx = getButtonById(buttonId);

	if (idx == -1)
		return;
	_buttons.at(static_cast<unsigned long>(idx))->setIsPushable(isPushable);
	_buttons.at(static_cast<unsigned long>(idx))->setTexture(
		isPushable ? _buttonBack : _buttonPressed);
}

void bomb::menu::Menu::setElementPos(int elementId, irr::core::vector2df pos)
{
	long long idx = getElementById(elementId);

	if (idx == -1) {
		idx = getButtonById(elementId);
		if (idx != -1)
			_buttons.at(
				static_cast<unsigned long>(idx))->setPos(pos);
	}
	else
		_elements.at(static_cast<unsigned long>(idx))->setPos(pos);
}

void bomb::menu::Menu::setElementSize(int elementId, irr::core::vector2df size)
{
	long long idx = getElementById(elementId);

	if (idx == -1) {
		idx = getButtonById(elementId);
		if (idx != -1)
			_buttons.at(
				static_cast<unsigned long>(idx))->setSize(size);
	}
	else
		_elements.at(static_cast<unsigned long>(idx))->setSize(size);
}

void bomb::menu::Menu::setElementText(int elementId, const wchar_t *text)
{
	long long idx = getElementById(elementId);

	if (idx == -1) {
		idx = getButtonById(elementId);
		if (idx != -1)
			_buttons.at(
				static_cast<unsigned long>(idx))->setText(text);
	}
	else
		_elements.at(static_cast<unsigned long>(idx))->setText(text);
}

void bomb::menu::Menu::setElementFont(int elementId, bomb::menu::MenuFonts font)
{
	long long idx = getElementById(elementId);

	if (idx == -1) {
		idx = getButtonById(elementId);
		if (idx != -1)
			_buttons.at(
				static_cast<unsigned long>(idx))->setFont(
				_fonts[font]);
	}
	else
		_elements.at(
			static_cast<unsigned long>(idx))->setFont(_fonts[font]);
}

void bomb::menu::Menu::setElementTexture(int elementId,
					 irr::video::ITexture *texture)
{
	long long idx = getElementById(elementId);

	if (idx == -1) {
		idx = getButtonById(elementId);
		if (idx != -1)
			_buttons.at(
				static_cast<unsigned long>(idx))->setTexture(
				texture);
	}
	else
		_elements.at(static_cast<unsigned long>(idx))->setTexture(
			texture);
}

void bomb::menu::Menu::clean()
{
	_elements.clear();
	_buttons.clear();
	_gui->clear();
}