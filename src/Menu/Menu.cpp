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
	_font = loader.loadFont("fonts/mario16.xml");
	_titleFont = loader.loadFont("fonts/marioColor36.xml");
	_gui->getSkin()->setFont(_font);
	_gui->getSkin()->setColor(irr::gui::EGDC_BUTTON_TEXT,
				  irr::video::SColor(255, 255, 255, 255));
	createTitle(L"SUPER\nBOMBERMARIO\nBROS.");
}
//std::function <void()> event
void bomb::menu::Menu::addButton(IAssetLoader &loader,
				irr::core::vector2df pos, int id)
{
	irr::gui::IGUIButton * irrButton = createButton({ 0, 0 },
		getButtonSize(loader), id);
	GraphicButton button(GraphicButton(irrButton, pos, id));
	button.setTexture(_buttonBack, _buttonPressed);
	_buttons.emplace_back(button);
}

void bomb::menu::Menu::createTitle(const wchar_t *title)
{
	_title = std::make_unique<bomb::menu::GraphicText>(
		_gui->addStaticText(title, { 0, 0, 1, 1	}),
		irr::core::vector2df(0.5f, 0.15f));
	_title->setFont(_titleFont);
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
	_title->update({1, 1}, screenSize);
	_title->setVisibility(areVisible);
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

void bomb::menu::Menu::addButtonText(int buttonId, const wchar_t *text)
{
	long long idx = getButtonById(buttonId);

	if (idx == -1)
		return;
	_buttons.at(static_cast<unsigned long>(idx)).setText(text);
}

void bomb::menu::Menu::addButtonEvent(int buttonId, std::function<void()> event)
{
	long long idx = getButtonById(buttonId);

	if (idx == -1)
		return;
	_buttons.at(static_cast<unsigned long>(idx)).setEvent(event);
}

void bomb::menu::Menu::clean()
{
	for (auto btn : _buttons)
		btn.remove();
	_buttons.clear();
	_title->remove();
	_title.reset(nullptr);
}