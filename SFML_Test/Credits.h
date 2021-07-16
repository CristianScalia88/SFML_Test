#pragma once
#include "Game.h"
#include "TextComponent.h"
#include "Callbacks.h"
#include "Button.h"
#include "MainMenu.h"

class Credits : public Game
{
private:
	GameObject* creditLabelName;
	sf::Font fontType;
	GameObject* CreateText(std::string labelText, sf::Vector2f pos, int fontSize);
	GameObject* CreateButton(std::string text, CallbackBase* callback, sf::Vector2f pos);
	void GoToMainMenu();
public:
	CallbackBase* goToMainMenu;
	Credits();
	~Credits();
	Game** mainScene;
};

