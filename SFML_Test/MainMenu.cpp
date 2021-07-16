#include "pch.h"
#include "MainMenu.h"

const sf::Color gray = sf::Color(40, 40, 40, 0);
const sf::Color grayOver = sf::Color(30, 30, 30, 200);

GameObject* MainMenu::CreateButton(std::string text, CallbackBase* callback, sf::Vector2f pos)
{
	GameObject* goButton = new GameObject();
	poke::Button* buttonComponent = new poke::Button(text, fontType, 20, { 200,30 }, gray, grayOver, sf::Color::White);
	buttonComponent->SetPosition(pos);
	buttonComponent->callback = callback;
	goButton->AddComponent(buttonComponent);
	return goButton;
}

MainMenu::MainMenu()
{
	fontType.loadFromFile("Assets/Rubric Regular.ttf");

	gameplayButton = CreateButton("Play", make_callback(this, &MainMenu::GoToGameplay), {300, 300});
	AddGameObject(gameplayButton);

	creditsButton = CreateButton("Credits", make_callback(this, &MainMenu::GoToCredits), { 300, 340 });
	AddGameObject(creditsButton);

	//exitButton = CreateButton("Exit", make_callback(this, &MainMenu::ShowPlay), { 300, 380 });
	//AddGameObject(exitButton);
}

void MainMenu::GoToGameplay() 
{
	(*goToGameplay)();
}

void MainMenu::GoToCredits()
{
	(*goToCredits)();
}


MainMenu::~MainMenu()
{
	delete exitButton;
	delete gameplayButton;
	delete creditsButton;
}
