#pragma once
#include "Scene.h"
#include "Gameplay.h"
#include "Credits.h"
#include "MainMenu.h"

class GameScenes
{
private:
	Scene ** game;
	Scene* changeToScene;
	sf::View* view;
public:

	GameScenes(Scene** game_, sf::View* _view) {
		game = game_;
		view = _view;
		changeToScene = nullptr;
		ChangeToMainMenu();
		ChangeScene();
	}

	void RequestChangeGame(Scene* newGame)
	{
		changeToScene = newGame;
	}

	void ChangeScene() 
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

	void ChangeToGameplay()
	{
		Gameplay* gameplay = new Gameplay(view);
		RequestChangeGame(gameplay);
	}

	void ChangeToCredtis()
	{
		Credits* credits = new Credits();
		credits->goToMainMenu = make_callback(this, &GameScenes::ChangeToMainMenu);
		RequestChangeGame(credits);
	}

	void CloseGame()
	{
		exit(0);
	}

	void ChangeToMainMenu()
	{
		MainMenu* mainMenu = new MainMenu();
		mainMenu->goToGameplay = make_callback(this, &GameScenes::ChangeToGameplay);
		mainMenu->goToCredits = make_callback(this, &GameScenes::ChangeToCredtis);
		mainMenu->closeGame = make_callback(this, &GameScenes::CloseGame);
		RequestChangeGame(mainMenu);
	}

};

