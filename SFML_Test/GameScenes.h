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
	static GameScenes* instance;
	GameScenes(Scene** game_, sf::View* _view);
	void RequestChangeGame(Scene* newGame);
	void ChangeScene();
	void ChangeToGameplay();
	void ChangeToCredtis();
	void CloseGame();
	void ChangeToMainMenu();
};
