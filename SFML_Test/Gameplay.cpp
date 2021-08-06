#include "pch.h"
#include "Gameplay.h"
#include "PlayerHud.h"
#include "AIInput.h"
#include "Enemy.h"
#include "Weapon.h"
#include "CameraComponent.h"
#include "GameScenes.h"
#include "SoundManager.h"

Gameplay* Gameplay::instance = nullptr;

const string LEVEL_PATH = "Assets/level.png";

void Gameplay::OnPlayerGetDamaged()
{
	SoundManager::instance->Play("playerDamage");
}

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
	Player* player = new Player(playerGo, new PlayerInput(), 350, ColliderManager::PLAYER);
	player->SetupSprite(playerGo, Player::PATH_JSON, Player::PATH_TEXTURE);

	int * idleFrameIds = new int[6]{ 0, 1, 2, 3, 4, 5 };
	int * walk = new int[6]{ 14,15,16,17,18,19 };
	int * attackFrameIds = new int[3]{ 20,21,22 };

	player->SetupAnimation(playerGo, new PlayerAnimation(player->textureComponent, player->spriteSheet, player->movementComponent, idleFrameIds, walk, attackFrameIds));
	playerGo->AddComponent(player);

	player->GetHPComponent()->OnDead->AddCallback(make_callback(this, &Gameplay::GoToMainMenu));
	player->GetHPComponent()->OnDamage->AddCallback(make_callback(this, &Gameplay::OnPlayerGetDamaged));

	Weapon* weapon = new Weapon({ 0, -25}, 50, true);
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
