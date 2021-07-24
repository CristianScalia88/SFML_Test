#pragma once
#include "Enemy.h"
#include "Scene.h"
#include "TransformComponent.h"
#include "AIInput.h"
#include "Random.h"

class EnemyManager : public IGameComponent
{
private:
	Scene* game;
	ColliderManager* colliderManager;
	TransformComponent* playerTransform;

	float currentTime = 0;
	int maxEnemies = 10;
	int enemiesKilled = 0;
	float cadency = 5;

	void CreateEnemy();
public:
	EnemyManager(Scene* game, ColliderManager* colliderManager, int maxEnemies, TransformComponent * playerTransform, float cadency);
	void Update(float deltaTime);
	std::string GetClassName();
};

