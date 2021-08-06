#include "pch.h"
#include "MainMenu.h"
#include "CameraComponent.h"

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

MainMenu::MainMenu(sf::View* view)
{
	fontType.loadFromFile("Assets/Rubric Regular.ttf");

	gameplayButton = CreateButton("Play", make_callback(this, &MainMenu::GoToGameplay), {300, 300});
	AddGameObject(gameplayButton);

	creditsButton = CreateButton("Credits", make_callback(this, &MainMenu::GoToCredits), { 300, 340 });
	AddGameObject(creditsButton);

	GameObject* go = new GameObject();
	go->transform->Translate({ 400, 350 });
	CameraComponent* cc = new CameraComponent(view, go->transform, false);
	go->AddComponent(cc);
	AddGameObject(go);


	exitButton = CreateButton("Exit", make_callback(this, &MainMenu::CloseGame), { 300, 380 });
	AddGameObject(exitButton);

	GameObject* scoreButton = CreateButton("Score", make_callback(GameScenes::instance, &GameScenes::ChangeToScoreScreen), { 300, 420 });
	AddGameObject(scoreButton);
}

void MainMenu::GoToGameplay() 
{
	goToGameplay->Invoke();
}

void MainMenu::GoToCredits()
{
	goToCredits->Invoke();
}

void MainMenu::CloseGame()
{
	closeGame->Invoke();
}

MainMenu::~MainMenu()
{
	delete exitButton;
	delete gameplayButton;
	delete creditsButton;
	delete goToGameplay;
	delete goToCredits;
}
