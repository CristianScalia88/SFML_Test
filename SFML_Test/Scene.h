#pragma once
#include "GameObject.h"

class Scene
{
private:
	vector<GameObject*>* gameObjects;
	vector<GameObject*>* gameObjectsToAdd;
public:
	bool running;
	Scene();
	~Scene();
	void CheckInput(sf::Event);
	void Update(float deltaTime);
	void Render(sf::RenderWindow*);
	void AddGameObject(GameObject*);
	void AddDynamicGameObjects();
};

