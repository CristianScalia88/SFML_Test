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
	GameObject* player;

	float currentTime = 0;
	int maxEnemies = 10;
	int enemiesKilled = 0;
	float cadency = 5;

	vector<GameObject*>* enemies;

	void CreateEnemy();
public:
	EnemyManager(Scene* game, int maxEnemies, GameObject * player, float cadency);
	void Update(float deltaTime);
	std::string GetClassName();
};

