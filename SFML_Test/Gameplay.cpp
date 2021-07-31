#include "pch.h"
#include "Gameplay.h"
#include "PlayerHud.h"
#include "AIInput.h"
#include "Enemy.h"
#include "Weapon.h"
#include "CameraComponent.h"
#include "GameScenes.h"

Gameplay* Gameplay::instance = nullptr;

Gameplay::Gameplay(sf::View* view)
{
	///Create a colliderManager
	colliderManager = new ColliderManager();

	playerGo = new GameObject();
	playerGo->name = "Player";
	Player* player = new Player(playerGo, new PlayerInput(), 150, ColliderManager::PLAYER);
	playerGo->AddComponent(player);

	player->GetHPComponent()->OnDead->AddCallback(make_callback(this, &Gameplay::GoToMainMenu));

	Weapon* weapon = new Weapon({ 0, -25});
	playerGo->AddComponent(weapon);

	AddGameObject(playerGo);
	playerGo->transform->Translate(sf::Vector2f(380, 350));

	CameraComponent* cc = new CameraComponent(view, playerGo->transform, true);
	playerGo->AddComponent(cc);

	GameObject* enemyManagerGo = new GameObject();
	enemyManagerGo->name = "EnemyManager";
	EnemyManager * enemyManager = new EnemyManager(this, 5, playerGo, 1);
	enemyManagerGo->AddComponent(enemyManager);
	AddGameObject(enemyManagerGo);

	//Add The colliderManager
	GameObject* colliderManagerGo = new GameObject();
	colliderManagerGo->name = "colliderManager";

	colliderManagerGo->AddComponent(colliderManager);
	AddGameObject(colliderManagerGo);

	GameObject* playerHud = new GameObject();
	playerHud->name = "Player Hud";
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

void Gameplay::GoToMainMenu()
{
	GameScenes::instance->ChangeToMainMenu();
}
