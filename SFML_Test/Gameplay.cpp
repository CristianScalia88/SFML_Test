#include "pch.h"
#include "Gameplay.h"
#include "PlayerHud.h"
#include "AIInput.h"
#include "Enemy.h"
#include "Weapon.h"
#include "CameraComponent.h"
#include "GameScenes.h"

Gameplay* Gameplay::instance = nullptr;

const string LEVEL_PATH = "Assets/level.png";

Gameplay::Gameplay(sf::View* view)
{
	///Create a colliderManager
	colliderManager = new ColliderManager();

	sf::Texture* backgroundTexture = new sf::Texture();
	if (!backgroundTexture->loadFromFile(LEVEL_PATH)) 
	{
		cout << " FILE NOT FOUND! ";
	}

	GameObject * backgroundGO = new GameObject();
	TextureComponent* texture = new TextureComponent(backgroundTexture,0,0);
	backgroundGO->AddComponent(texture);
	AddGameObject(backgroundGO);

	playerGo = new GameObject();
	playerGo->name = "Player";
	Player* player = new Player(playerGo, new PlayerInput(), 150, ColliderManager::PLAYER);
	playerGo->AddComponent(player);

	player->GetHPComponent()->OnDead->AddCallback(make_callback(this, &Gameplay::GoToMainMenu));

	Weapon* weapon = new Weapon({ 0, -25});
	playerGo->AddComponent(weapon);

	AddGameObject(playerGo);
	playerGo->transform->Translate(sf::Vector2f(380, 520));

	CameraComponent* cc = new CameraComponent(view, playerGo->transform, true);
	playerGo->AddComponent(cc);

	GameObject* enemyManagerGo = new GameObject();
	enemyManagerGo->name = "EnemyManager";
	EnemyManager * enemyManager = new EnemyManager(this, 8, playerGo, 2);
	enemyManagerGo->AddComponent(enemyManager);
	AddGameObject(enemyManagerGo);

	//Add The colliderManager
	GameObject* colliderManagerGo = new GameObject();
	colliderManagerGo->name = "colliderManager";
	colliderManagerGo->transform->Translate({ 0,9999 });
	colliderManagerGo->AddComponent(colliderManager);
	AddGameObject(colliderManagerGo);

	GameObject* playerHud = new GameObject();
	playerHud->name = "Player Hud";
	PlayerHud* playerHudComponent = new PlayerHud(player->GetHPComponent(), playerHud);
	playerHud->AddComponent(playerHudComponent);
	AddGameObjectHUD(playerHud);
	running = true;
	instance = this;

	CreateLevelColliders();
}

Gameplay::~Gameplay()
{
	delete playerGo;
}

void Gameplay::GoToMainMenu()
{
	GameScenes::instance->ChangeToMainMenu();
}

void Gameplay::OnLoopEnd()
{
	std::sort(gameObjects->begin(), gameObjects->end(), [](GameObject* a, GameObject* b) { return a->transform->position.y < b->transform->position.y; } );
}

void Gameplay::CreateLevelColliders()
{

	GameObject* topCollider = new GameObject();
	topCollider->AddComponent(ColliderManager::instance->CreateCollider(1285, 54, ColliderManager::BLOCK));
	topCollider->transform->Translate({ 920, 350 });
	AddGameObject(topCollider);

	GameObject* bottomCollider = new GameObject();
	bottomCollider->AddComponent(ColliderManager::instance->CreateCollider(1285, 54, ColliderManager::BLOCK));
	bottomCollider->transform->Translate({ 920, 675 });
	AddGameObject(bottomCollider);

	GameObject* rightCollider = new GameObject();
	rightCollider->AddComponent(ColliderManager::instance->CreateCollider(54, 500, ColliderManager::BLOCK));
	rightCollider->transform->Translate({ 1600, 650 });
	AddGameObject(rightCollider);

	GameObject* leftCollider = new GameObject();
	leftCollider->AddComponent(ColliderManager::instance->CreateCollider(54, 500, ColliderManager::BLOCK));
	leftCollider->transform->Translate({ 300, 650 });
	AddGameObject(leftCollider);
}
