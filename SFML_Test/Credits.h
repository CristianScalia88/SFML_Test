#pragma once
#include "Game.h"
#include "TextComponent.h"

class Credits
{
private:
	GameObject* creditLabelName;
	sf::Font fontType;
	GameObject* CreateText(std::string labelText, sf::Vector2f pos, int fontSize);
public:
	Credits();
	~Credits();
	Game* game;
	Game** mainScene;
};

