#include "pch.h"
#include "Gameplay.h"
#include "PlayerHud.h"
#include "AIInput.h"
#include "Enemy.h"

Gameplay::Gameplay()
{
	///Create a colliderManager
	colliderManager = new ColliderManager();

	playerGo = new GameObject();
	Player* player = new Player(colliderManager, playerGo, new PlayerInput(), 150);
	playerGo->AddComponent(player);
	AddGameObject(playerGo);
	playerGo->transform->Translate(sf::Vector2f(40, 80));

	enemyGo = new GameObject();
	Enemy* enemy = new Enemy(colliderManager, enemyGo, new AIInput(enemyGo->transform, playerGo->transform), 50);
	enemyGo->AddComponent(enemy);
	AddGameObject(enemyGo);
	enemyGo->transform->Translate(sf::Vector2f(400, 600));

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
