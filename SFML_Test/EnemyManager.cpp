#include "pch.h"
#include "EnemyManager.h"

void EnemyManager::CreateEnemy()
{
	GameObject* enemyGo = new GameObject();
	enemyGo->name = "Enemy-" + enemies->size();
	Enemy* enemy = new Enemy(enemyGo, new AIInput(enemyGo->transform, player->transform), 80, player, ColliderManager::ENEMY);
	enemyGo->AddComponent(enemy);
	game->AddGameObject(enemyGo);
	enemy->GetHPComponent()->OnDead->AddCallback(make_callback(this, &EnemyManager::OnEnemyDead));
	enemies->push_back(enemyGo);

	bool left = Random::RandomSign() < 0;
	int x = 0;
	if (left) 
	{
		x = Random::Range(500, 1100);
	}
	else {
		x = Random::Range(500, 1100);
	}
	int y = Random::Range(370, 250);

	enemyGo->transform->Translate(sf::Vector2f(x, y));
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
	if (currentTime > cadency && enemiesCreated < maxEnemies) 
	{
		currentTime = 0;
		enemiesCreated++;
		CreateEnemy();
	}
}

std::string EnemyManager::GetClassName()
{
	return "EnemyManager";
}

void EnemyManager::OnEnemyDead()
{
	enemiesDead++;
	if (enemiesDead == maxEnemies)
	{
		GameScenes::instance->ChangeToMainMenu();
	}
}
