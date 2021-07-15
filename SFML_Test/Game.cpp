#include "pch.h"
#include "Game.h"

Game::Game()
{
	gameObjects = new vector<GameObject*>();
}

Game::~Game()
{
}

void Game::CheckInput(sf::Event evv)
{
	switch (evv.type)
	{

		default:
			break;
	}
}

void Game::Update(float deltaTime)
{
	for (auto i = gameObjects->begin(); i != gameObjects->end(); ++i)
		(*i)->Update(deltaTime);
}

void Game::Render(sf::RenderWindow* window)
{
	for (auto i = gameObjects->begin(); i != gameObjects->end(); ++i)
		(*i)->Render(window);
}

void Game::AddGameObject(GameObject * go)
{
	gameObjects->push_back(go);
}

