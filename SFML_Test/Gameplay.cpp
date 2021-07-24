#include "pch.h"
#include "Gameplay.h"
#include "PlayerHud.h"
#include "AIInput.h"
#include "Enemy.h"
#include "Weapon.h"

Gameplay* Gameplay::instance = nullptr;

Gameplay::Gameplay()
{
	///Create a colliderManager
	colliderManager = new ColliderManager();

	playerGo = new GameObject();
	Player* player = new Player(colliderManager, playerGo, new PlayerInput(), 150);
	playerGo->AddComponent(player);
	Weapon* weapon = new Weapon();
	playerGo->AddComponent(weapon);
	AddGameObject(playerGo);
	playerGo->transform->Translate(sf::Vector2f(380, 350));

	GameObject* enemyManagerGo = new GameObject();
	EnemyManager * enemyManager = new EnemyManager(this, colliderManager, 5, playerGo->transform, 5);
	enemyManagerGo->AddComponent(enemyManager);
	AddGameObject(enemyManagerGo);

	//Add The colliderManager
	GameObject* colliderManagerGo = new GameObject();
	colliderManagerGo->AddComponent(colliderManager);
	AddGameObject(colliderManagerGo);

	GameObject* playerHud = new GameObject();
	PlayerHud* playerHudComponent = new PlayerHud(player->GetHPComponent(), playerHud);
	playerHud->AddComponent(playerHudComponent);
	AddGameObject(playerHud);
	running = true;
	instance = this;
}

Gameplay::~Gameplay()
{
	delete playerGo;
}
