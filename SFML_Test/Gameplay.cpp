#include "pch.h"
#include "Gameplay.h"
#include "PlayerHud.h"

Gameplay::Gameplay()
{
	///Create a colliderManager
	colliderManager = new ColliderManager();

	playerGo = new GameObject();
	Player* player = new Player(colliderManager, playerGo);
	playerGo->AddComponent(player);
	AddGameObject(playerGo);

	//Add The colliderManager
	GameObject* colliderManagerGo = new GameObject();
	colliderManagerGo->AddComponent(colliderManager);
	AddGameObject(colliderManagerGo);

	GameObject* playerHud = new GameObject();
	PlayerHud* playerHudComponent = new PlayerHud(player->GetHPComponent(), playerHud);
	playerHud->AddComponent(playerHudComponent);
	AddGameObject(playerHud);
}

Gameplay::~Gameplay()
{
	delete playerGo;
}
