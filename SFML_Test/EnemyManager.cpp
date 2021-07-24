#include "pch.h"
#include "EnemyManager.h"

void EnemyManager::CreateEnemy()
{
	GameObject* enemyGo = new GameObject();
	Enemy* enemy = new Enemy(colliderManager, enemyGo, new AIInput(enemyGo->transform, playerTransform), 50);
	enemyGo->AddComponent(enemy);
	game->AddGameObject(enemyGo);

	bool left = Random::RandomSign() < 0;
	int x = 0;
	if (left) 
	{
		x = -Random::Range(0, 300);
	}
	else {
		x = Random::Range(800, 800 + 300);
	}
	int y = Random::Range(0,500);

	enemyGo->transform->Translate(sf::Vector2f(x, y));
}

EnemyManager::EnemyManager(Scene* _game, ColliderManager* _colliderManager, int _maxEnemies, TransformComponent* _playerTransform, float _cadency)
{
	game = _game;
	colliderManager = _colliderManager;
	playerTransform = _playerTransform;
	maxEnemies = _maxEnemies;
	cadency = _cadency;
}

void EnemyManager::Update(float deltaTime)
{
	currentTime += deltaTime;
	if (currentTime > cadency) 
	{
		currentTime = 0;
		CreateEnemy();
	}
}
