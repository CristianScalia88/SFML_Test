#pragma once
#include "GameObject.h"

class Scene
{
private:
	vector<GameObject*>* gameObjects;

public:
	Scene();
	~Scene();
	void CheckInput(sf::Event);
	void Update(float deltaTime);
	void Render(sf::RenderWindow*);
	void AddGameObject(GameObject*);
};

