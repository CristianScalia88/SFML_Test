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
	game = new Game();
	
	fontType.loadFromFile("Assets/Rubric Regular.ttf");

	gameplayButton = CreateButton("Play", make_callback(this, &MainMenu::ShowPlay), {300, 300});
	game->AddGameObject(gameplayButton);

	creditsButton = CreateButton("Credits", make_callback(this, &MainMenu::ShowPlay), { 300, 340 });
	game->AddGameObject(creditsButton);

	exitButton = CreateButton("Exit", make_callback(this, &MainMenu::ShowPlay), { 300, 380 });
	game->AddGameObject(exitButton);
}


MainMenu::~MainMenu()
{
	delete game;
	delete exitButton;
	delete gameplayButton;
	delete creditsButton;
}

void MainMenu::ShowPlay()
{
	if (changeToGameplay) 
	{
		return;
	}
	changeToGameplay = true;
	Gameplay* gameplay = new Gameplay();
	*mainScene = gameplay->game;
}
