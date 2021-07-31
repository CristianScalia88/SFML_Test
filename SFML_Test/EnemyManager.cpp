#include "pch.h"
#include "EnemyManager.h"

void EnemyManager::CreateEnemy()
{
	GameObject* enemyGo = new GameObject();
	enemyGo->name = "Enemy-" + enemies->size();
	Enemy* enemy = new Enemy(enemyGo, new AIInput(enemyGo->transform, player->transform), 10, player, ColliderManager::ENEMY);
	enemyGo->AddComponent(enemy);
	game->AddGameObject(enemyGo);

	enemies->push_back(enemyGo);

	bool left = Random::RandomSign() < 0;
	int x = 0;
	if (left) 
	{
		x = Random::Range(0, 300);
	}
	else {
		x = Random::Range(0, 300);
	}
	int y = Random::Range(0,500);

	enemyGo->transform->Translate(sf::Vector2f(x,y));
}

EnemyManager::EnemyManager(Scene* _game, int _maxEnemies, GameObject* _player, float _cadency)
{
	game = _game;
	colliderManager = ColliderManager::instance;
	player = _player;
	maxEnemies = _maxEnemies;
	cadency = _cadency;
	enemies = new vector<GameObject*>();
}

void EnemyManager::Update(float deltaTime)
{
	currentTime += deltaTime;
	if (currentTime > cadency) 
	{
		currentTime = -5555555;
		CreateEnemy();
	}
}

std::string EnemyManager::GetClassName()
{
	return "EnemyManager";
}
