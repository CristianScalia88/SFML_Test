#pragma once
#include "Game.h"
#include "Gameplay.h"
#include "Credits.h"
#include "MainMenu.h"

class GameScenes
{
private:
	Game ** game;

public:

	GameScenes(Game** game_) {
		game = game_;
		ChangeToMainMenu();
	}

	void ChangeGame(Game* newGame)
	{
		*game = newGame;
	}

	void ChangeToGameplay()
	{
		ChangeGame(new Gameplay());
	}

	void ChangeToCredtis()
	{
		Credits* credits = new Credits();
		credits->goToMainMenu = make_callback(this, &GameScenes::ChangeToMainMenu);
		ChangeGame(credits);
	}

	void ChangeToMainMenu()
	{
		MainMenu* mainMenu = new MainMenu();
		mainMenu->goToGameplay = make_callback(this, &GameScenes::ChangeToGameplay);
		mainMenu->goToCredits = make_callback(this, &GameScenes::ChangeToCredtis);
		ChangeGame(mainMenu);
	}

};

