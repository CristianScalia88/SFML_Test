#pragma once
#include "GameObject.h"

class Scene
{
private:
	vector<GameObject*>* gameObjects;
	vector<GameObject*>* gameObjectsToAdd;
	vector<GameObject*>* gameObjectsToRemove;
public:
	bool running;
	Scene();
	~Scene();
	void CheckInput(sf::Event);
	void Update(float deltaTime);
	void Render(sf::RenderWindow*);
	void AddGameObject(GameObject*);
	void DestroyGameObject(GameObject*);
	void DestroyAllGameObject();
	void AddDynamicGameObjects();
};

