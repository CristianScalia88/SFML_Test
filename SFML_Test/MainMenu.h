#pragma once
#include "Scene.h"
#include "Button.h"
#include "GameObject.h"
#include "Callbacks.h"
#include "Gameplay.h"

class MainMenu : public Scene
{
private:
	GameObject* gameplayButton;
	GameObject* creditsButton;
	GameObject* exitButton;
	sf::Font fontType;
	GameObject* CreateButton(std::string text, CallbackBase* callback, sf::Vector2f pos);
	void GoToGameplay();
	void GoToCredits();
	void CloseGame();
public:
	CallbackBase* goToGameplay;
	CallbackBase* goToCredits;
	CallbackBase* closeGame;
	MainMenu(sf::View* view);
	~MainMenu();
	Scene** mainScene;
};

