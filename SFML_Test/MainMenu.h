#pragma once
#include "Game.h"
#include "Button.h"
#include "GameObject.h"
#include "Callbacks.h"
#include "Gameplay.h"

class MainMenu
{
private:
	GameObject* gameplayButton;
	GameObject* creditsButton;
	GameObject* exitButton;
	sf::Font fontType;
	GameObject* CreateButton(std::string text, CallbackBase* callback, sf::Vector2f pos);
	bool changeToGameplay;
public:
	MainMenu();
	~MainMenu();
	Game* game;
	Game** mainScene;
	void ShowPlay();
};

