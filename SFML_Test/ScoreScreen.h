#pragma once

#include "Scene.h"
#include "TextComponent.h"
#include "Callbacks.h"
#include "Button.h"
#include "MainMenu.h"

class ScoreScreen : public Scene
{
private:
	sf::Font fontType;
	GameObject* CreateText(std::string labelText, sf::Vector2f pos, int fontSize);
	GameObject* CreateButton(std::string text, CallbackBase* callback, sf::Vector2f pos);
public:
	ScoreScreen(sf::View* view);
	~ScoreScreen();
};