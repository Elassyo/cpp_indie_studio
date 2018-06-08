//
// EPITECH PROJECT, 2018
// cpp_test_studio - Menu.cpp
// File description:
// Created by Gregory EPLE
//

#include "Menu.hpp"

bomb::menu::Menu::Menu() :
	_buttonRatio(irr::core::vector2df(0.125f, 0.1f))
{
}

void bomb::menu::Menu::createMenu(IAssetLoader &loader)
{
	_gui = loader.getGui();
	_buttonBack = loader.loadTexture("images/buttonBack.png");
	_buttonPressed = loader.loadTexture("images/buttonPressed.png");
	_fonts[BASIC] = loader.loadFont("fonts/mario16.xml");
	_fonts[TITLE] = loader.loadFont("fonts/marioColor36.xml");
	_gui->getSkin()->setFont(_fonts[BASIC]);
	_gui->getSkin()->setColor(irr::gui::EGDC_BUTTON_TEXT,
				  irr::video::SColor(255, 255, 255, 255));
}

void bomb::menu::Menu::addButton(IAssetLoader &loader,
				 irr::core::vector2df pos, int id)
{
	irr::gui::IGUIButton * irrButton = createButton({ 0, 0 },
							getButtonSize(loader), id);
	GraphicButton button(GraphicButton(irrButton, pos, id));
	button.setTextures(_buttonBack, _buttonPressed);
	_buttons.emplace_back(button);
}

void bomb::menu::Menu::addText(wchar_t *text, irr::core::vector2df pos, int id)
{
	irr::gui::IGUIStaticText *irrText = createText(text, id);
	GraphicText gText(GraphicText(irrText, pos, id));
	_texts.emplace_back(gText);
}

irr::gui::IGUIStaticText *bomb::menu::Menu::createText(
	const wchar_t *text, int id)
{
	return _gui->addStaticText(text, {1, 1, 1, 1},
				   false, true, nullptr, id);
}

irr::gui::IGUIButton *bomb::menu::Menu::createButton(
	irr::core::vector2di pos, irr::core::vector2di size,
	int id)
{
	return _gui->addButton({ pos.X, pos.Y, pos.X + size.X, pos.Y + size.Y },
			       nullptr, id);
}

void bomb::menu::Menu::updateButtons(IAssetLoader &loader, bool areVisible)
{
	const irr::core::vector2di buttonSize = getButtonSize(loader);
	const irr::core::vector2di screenSize = {
		(int)loader.getScreenSize().Width,
		(int)loader.getScreenSize().Height};
	for (auto &text : _texts) {
		text.update({1, 1}, screenSize);
		text.setVisibility(areVisible);
	}
	for (auto &button : _buttons) {
		button.setVisibility(areVisible);
		button.update(buttonSize, screenSize);
	}
}

bool bomb::menu::Menu::handleEvent(const irr::SEvent &event) {
	for (auto &button : _buttons) {
		if (button.isPressed(event) && button.getEvent()) {
			button.getEvent()();
			return true;
		}
	}
	return false;
}

irr::core::vector2di bomb::menu::Menu::getButtonSize(IAssetLoader &loader) const
{
	const irr::core::dimension2du &screenSize = loader.getScreenSize();
	return { (int)(_buttonRatio.X * screenSize.Width),
		 (int)(_buttonRatio.Y * screenSize.Height) };
}

long long bomb::menu::Menu::getButtonById(int buttonId)
{
	auto it = std::find_if(_buttons.begin(),_buttons.end(), [buttonId]
		(const GraphicButton &button) {
		return button.getId() == buttonId;
	});
	if (it == _buttons.end())
		return -1;
	return it - _buttons.begin();
}

long long bomb::menu::Menu::getTextById(int textId)
{
	auto it = std::find_if(_texts.begin(),_texts.end(), [textId]
		(const GraphicText &text) {
		return text.getId() == textId;
	});
	if (it == _texts.end())
		return -1;
	return it - _texts.begin();
}

void bomb::menu::Menu::setButtonPos(int buttonId, irr::core::vector2df pos)
{
	long long idx = getButtonById(buttonId);

	if (idx == -1)
		return;
	_buttons.at(static_cast<unsigned long>(idx)).setPos(pos);
}

void bomb::menu::Menu::setButtonText(int buttonId, const wchar_t *text)
{
	long long idx = getButtonById(buttonId);

	if (idx == -1)
		return;
	_buttons.at(static_cast<unsigned long>(idx)).setText(text);
}

void bomb::menu::Menu::setButtonFont(int buttonId, bomb::menu::MenuFonts font)
{
	long long idx = getButtonById(buttonId);

	if (idx == -1)
		return;
	_buttons.at(static_cast<unsigned long>(idx)).setFont(_fonts[font]);
}

void bomb::menu::Menu::setButtonTextures(int buttonId,
					 irr::video::ITexture *texture,
					 irr::video::ITexture *pressed)
{
	long long idx = getButtonById(buttonId);

	if (idx == -1)
		return;
	_buttons.at(static_cast<unsigned long>(idx)).setTexture(texture);
	_buttons.at(static_cast<unsigned long>(idx)).setPressedTexture(pressed);
}

void bomb::menu::Menu::setButtonTexture(int buttonId,
					irr::video::ITexture *texture)
{
	long long idx = getButtonById(buttonId);

	if (idx == -1)
		return;
	_buttons.at(static_cast<unsigned long>(idx)).setTexture(texture);
}
void bomb::menu::Menu::setButtonPressedTexture(int buttonId,
					       irr::video::ITexture *pressed)
{
	long long idx = getButtonById(buttonId);

	if (idx == -1)
		return;
	_buttons.at(static_cast<unsigned long>(idx)).setPressedTexture(pressed);
}

void bomb::menu::Menu::setButtonEvent(int buttonId, std::function<void()> event)
{
	long long idx = getButtonById(buttonId);

	if (idx == -1)
		return;
	_buttons.at(static_cast<unsigned long>(idx)).setEvent(event);
}

void bomb::menu::Menu::setTextPos(int textId, irr::core::vector2df pos)
{
	long long idx = getTextById(textId);

	if (idx == -1)
		return;
	_texts.at(static_cast<unsigned long>(idx)).setPos(pos);
}

void bomb::menu::Menu::setTextText(int textId, const wchar_t *text)
{
	long long idx = getTextById(textId);

	if (idx == -1)
		return;
	_texts.at(static_cast<unsigned long>(idx)).setText(text);
}

void bomb::menu::Menu::setTextFont(int textId, bomb::menu::MenuFonts font)
{
	long long idx = getTextById(textId);

	if (idx == -1)
		return;
	_texts.at(static_cast<unsigned long>(idx)).setFont(_fonts[font]);
}

void bomb::menu::Menu::clean()
{
	for (auto btn : _buttons)
		btn.remove();
	_buttons.clear();
	for (auto title : _texts)
		title.remove();
	_texts.clear();
}