#pragma once
#include "Enemy.h"
#include "Scene.h"
#include "TransformComponent.h"
#include "AIInput.h"
#include "GameScenes.h"
#include "Random.h"

class EnemyManager : public IGameComponent
{
private:
	Scene* game;
	ColliderManager* colliderManager;
	GameObject* player;

	float currentTime = 0;
	int maxEnemies = 10;
	int enemiesKilled = 0;
	float cadency = 5;

	vector<GameObject*>* enemies;

	int enemiesDead;
	int enemiesCreated;

	void CreateEnemy();

	float endGameInSeconds;

	const float MAX_EXTRA_SCORE = 60;
	float extraScoreMultiplier = MAX_EXTRA_SCORE;
public:
	EnemyManager(Scene* game, int maxEnemies, GameObject * player, float cadency);
	void Update(float deltaTime);
	std::string GetClassName();
	void OnEnemyDead();
};

