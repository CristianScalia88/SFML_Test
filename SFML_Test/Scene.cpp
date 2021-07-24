#include "pch.h"
#include "Scene.h"

Scene::Scene()
{
	gameObjects = new vector<GameObject*>();
	gameObjectsToAdd = new vector<GameObject*>();
}

Scene::~Scene()
{
	for (auto i = gameObjects->begin(); i != gameObjects->end(); ++i)
	{
		delete *i;
	}
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

void Scene::AddDynamicGameObjects()
{
	for (auto i = gameObjectsToAdd->begin(); i != gameObjectsToAdd->end(); ++i)
		gameObjects->push_back(*i);
	gameObjectsToAdd->clear();
}

