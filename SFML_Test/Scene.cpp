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
	int i = 0;
	int j = 0;
	for (i = gameObjectsToRemove->size()-1; i >=0; i--)
	{
		GameObject* toRemove = gameObjectsToRemove->at(i);
		for (j = gameObjects->size() - 1; j >= 0; j--)
		{
			GameObject* activeGo = gameObjects->at(j);
			if (activeGo == toRemove) 
			{
				gameObjects->erase(gameObjects->begin() + j);
				delete activeGo;
			}
		}
	}

	gameObjectsToRemove->clear();
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

void Scene::OnLoopEnd()
{
}

