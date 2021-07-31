#pragma once
#include "Scene.h"
#include "TextComponent.h"
#include "Callbacks.h"
#include "Button.h"
#include "MainMenu.h"

class Credits : public Scene
{
private:
	GameObject* creditLabelName;
	sf::Font fontType;
	GameObject* CreateText(std::string labelText, sf::Vector2f pos, int fontSize);
	GameObject* CreateButton(std::string text, CallbackBase* callback, sf::Vector2f pos);
	void GoToMainMenu();
public:
	CallbackBase* goToMainMenu;
	Credits(sf::View* view);
	~Credits();
	Scene** mainScene;
};

