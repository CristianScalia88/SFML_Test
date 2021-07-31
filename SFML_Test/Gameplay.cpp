#include "pch.h"
#include "Gameplay.h"
#include "PlayerHud.h"
#include "AIInput.h"
#include "Enemy.h"
#include "Weapon.h"
#include "CameraComponent.h"

Gameplay* Gameplay::instance = nullptr;

Gameplay::Gameplay(sf::View* view)
{
	///Create a colliderManager
	colliderManager = new ColliderManager();

	playerGo = new GameObject();
	playerGo->name = "Player";
	Player* player = new Player(colliderManager, playerGo, new PlayerInput(), 150);
	playerGo->AddComponent(player);
	playerGo->AddComponent(colliderManager->CreateCollider(30, 30, ColliderManager::PLAYER));
	CameraComponent * cc = new CameraComponent(view);
	playerGo->AddComponent(cc);

	Weapon* weapon = new Weapon({ 0, -25});
	playerGo->AddComponent(weapon);

	AddGameObject(playerGo);
	playerGo->transform->Translate(sf::Vector2f(380, 350));

	GameObject* enemyManagerGo = new GameObject();
	EnemyManager * enemyManager = new EnemyManager(this, colliderManager, 5, playerGo, 1);
	enemyManagerGo->AddComponent(enemyManager);
	AddGameObject(enemyManagerGo);

	//Add The colliderManager
	GameObject* colliderManagerGo = new GameObject();
	colliderManagerGo->AddComponent(colliderManager);
	AddGameObject(colliderManagerGo);

	GameObject* playerHud = new GameObject();
	PlayerHud* playerHudComponent = new PlayerHud(player->GetHPComponent(), playerHud);
	playerHud->AddComponent(playerHudComponent);
	AddGameObjectHUD(playerHud);
	running = true;
	instance = this;
}

Gameplay::~Gameplay()
{
	delete playerGo;
}