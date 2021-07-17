#include "pch.h"
#include "Gameplay.h"

Gameplay::Gameplay()
{
	///Create a colliderManager
	colliderManager = new ColliderManager();

	player = new Player(colliderManager);
	AddGameObject(player);

	//Add The colliderManager
	GameObject* colliderManagerGo = new GameObject();
	colliderManagerGo->AddComponent(colliderManager);
	AddGameObject(colliderManagerGo);
}

Gameplay::~Gameplay()
{
	delete player;
}
