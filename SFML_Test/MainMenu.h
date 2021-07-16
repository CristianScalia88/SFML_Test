#pragma once
#include "Game.h"
#include "Button.h"
#include "GameObject.h"
#include "Callbacks.h"
#include "Gameplay.h"

class MainMenu : public Game
{
private:
	GameObject* gameplayButton;
	GameObject* creditsButton;
	GameObject* exitButton;
	sf::Font fontType;
	GameObject* CreateButton(std::string text, CallbackBase* callback, sf::Vector2f pos);
	void GoToGameplay();
	void GoToCredits();
public:
	CallbackBase* goToGameplay;
	CallbackBase* goToCredits;
	MainMenu();
	~MainMenu();
	Game** mainScene;
};

