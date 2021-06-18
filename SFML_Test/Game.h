#pragma once
#include "GameObject.h"

class Game
{
private:
	vector<GameObject*>* gameObjects;

public:
	Game();
	~Game();
	void CheckInput(sf::Event);
	void Update(float deltaTime);
	void Render(sf::RenderWindow*);
	void AddGameObject(GameObject*);
};

