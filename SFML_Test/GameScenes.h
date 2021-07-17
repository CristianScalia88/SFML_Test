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
public:

	GameScenes(Scene** game_) {
		game = game_;
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
		RequestChangeGame(new Gameplay());
	}

	void ChangeToCredtis()
	{
		Credits* credits = new Credits();
		credits->goToMainMenu = make_callback(this, &GameScenes::ChangeToMainMenu);
		RequestChangeGame(credits);
	}

	void ChangeToMainMenu()
	{
		MainMenu* mainMenu = new MainMenu();
		mainMenu->goToGameplay = make_callback(this, &GameScenes::ChangeToGameplay);
		mainMenu->goToCredits = make_callback(this, &GameScenes::ChangeToCredtis);
		RequestChangeGame(mainMenu);
	}

};

