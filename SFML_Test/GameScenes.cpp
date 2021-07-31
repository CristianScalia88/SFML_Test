#include "pch.h"
#include "GameScenes.h"

GameScenes* GameScenes::instance;


GameScenes::GameScenes(Scene** game_, sf::View* _view) {
	game = game_;
	view = _view;
	changeToScene = nullptr;
	ChangeToMainMenu();
	ChangeScene();
	instance = this;
}

void GameScenes::RequestChangeGame(Scene* newGame)
{
	changeToScene = newGame;
}

void GameScenes::ChangeScene()
{
	if (changeToScene == nullptr)
	{
		return;
	}

	if (*game != nullptr) {
		delete* game;
	}
	*game = changeToScene;
	changeToScene = nullptr;
}

void GameScenes::ChangeToGameplay()
{
	Gameplay* gameplay = new Gameplay(view);
	RequestChangeGame(gameplay);
}

void GameScenes::ChangeToCredtis()
{
	Credits* credits = new Credits(view);
	credits->goToMainMenu = make_callback(this, &GameScenes::ChangeToMainMenu);
	RequestChangeGame(credits);
}

void GameScenes::CloseGame()
{
	exit(0);
}

void GameScenes::ChangeToMainMenu()
{
	MainMenu* mainMenu = new MainMenu(view);
	mainMenu->goToGameplay = make_callback(this, &GameScenes::ChangeToGameplay);
	mainMenu->goToCredits = make_callback(this, &GameScenes::ChangeToCredtis);
	mainMenu->closeGame = make_callback(this, &GameScenes::CloseGame);
	RequestChangeGame(mainMenu);
}
