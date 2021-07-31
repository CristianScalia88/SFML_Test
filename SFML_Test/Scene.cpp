#include "pch.h"
#include "Scene.h"
#include <algorithm>

Scene::Scene()
{
	gameObjects = new vector<GameObject*>();
	gameObjectsToAdd = new vector<GameObject*>();
	gameObjectsToRemove = new vector<GameObject*>();
	gameObjectsHUD = new vector<GameObject*>();
}

Scene::~Scene()
{
	for (auto i = gameObjects->begin(); i != gameObjects->end(); ++i)
	{
		delete *i;
	}
	gameObjects->clear();
	gameObjects->erase(gameObjects->begin(), gameObjects->end());
}

void Scene::CheckInput(sf::Event evv)
{
	switch (evv.type)
	{
		default:
			break;
	}
}

void Scene::Update(float deltaTime)
{
	for (auto i = gameObjects->begin(); i != gameObjects->end(); ++i)
		(*i)->Update(deltaTime);
}

void Scene::Render(sf::RenderWindow* window)
{
	for (auto i = gameObjects->begin(); i != gameObjects->end(); ++i)
		(*i)->Render(window);
}

void Scene::AddGameObject(GameObject * go)
{
	if (!running) 
	{
		gameObjects->push_back(go);
	}
	else {
		gameObjectsToAdd->push_back(go);
	}
}

void Scene::AddGameObjectHUD(GameObject* go)
{
	gameObjectsHUD->push_back(go);
}

void Scene::DestroyGameObject(GameObject* go)
{
	gameObjectsToRemove->push_back(go);
}

void Scene::DestroyAllGameObject()
{
	while (gameObjectsToRemove->size() > 0) 
	{
		GameObject* toRemove = gameObjectsToRemove->at(gameObjectsToRemove->size() - 1);
		gameObjectsToRemove->pop_back();
		auto begin = gameObjects->begin();
		auto end = gameObjects->end();
		vector<GameObject*>::iterator it = std::remove(begin, end, toRemove);
		gameObjects->erase(it);
		delete toRemove;
	}
}

void Scene::AddDynamicGameObjects()
{
	for (auto i = gameObjectsToAdd->begin(); i != gameObjectsToAdd->end(); ++i)
		gameObjects->insert(gameObjects->begin(), *i);
	gameObjectsToAdd->clear();
}

void Scene::RenderUI(sf::RenderWindow* window)
{
	for (auto i = gameObjectsHUD->begin(); i != gameObjectsHUD->end(); ++i)
		(*i)->Render(window);
}

