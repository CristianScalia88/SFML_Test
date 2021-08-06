#include "pch.h"
#include "EnemyManager.h"
#include "Random.h"
#include "RangeAIInput.h"
#include "../../Cpp/Clase2/HighScore/ScoreManager.h"

void EnemyManager::CreateEnemy()
{
	GameObject* enemyGo = new GameObject();
	enemyGo->name = "Enemy-" + std::to_string(enemies->size());
	string texture = Player::PATH_TEXTURE;
	string atlas = Player::PATH_JSON;
	CharacterInput* charInput = new AIInput(enemyGo->transform, player->transform);
	float speed = 50;

	Enemy* enemy = new Enemy(enemyGo, charInput, 50, ColliderManager::ENEMY);
	bool isRangeEnemy = Random::Range(0, 100) > 50;
	int* idleFrameIds;
	int* walk;
	int* attackFrameIds;
	if(isRangeEnemy)
	{
		isRangeEnemy = true;
		texture = "Assets/enemy2.png";
		atlas = "Assets/enemy2Atlas.json";
		charInput = new RangeAIInput(enemyGo->transform, player->transform);
		speed = 70;
		idleFrameIds = new int[6]{ 0, 1, 2, 3, 4, 5 };
		walk = new int[6]{ 6,7,8,9,10,11 };
		attackFrameIds = new int[3]{ 12,13,14 };
	}
	else 
	{
		idleFrameIds = new int[6]{ 0, 1, 2, 3, 4, 5 };
		walk = new int[6]{ 14,15,16,17,18,19 };
		attackFrameIds = new int[3]{ 20,21,22 };
	}

	enemy->SetupSprite(enemyGo, atlas, texture);
	
	enemy->SetupAnimation(enemyGo, new PlayerAnimation(enemy->textureComponent, enemy->spriteSheet, enemy->movementComponent, idleFrameIds, walk, attackFrameIds));

	enemyGo->AddComponent(enemy);
	game->AddGameObject(enemyGo);
	enemy->GetHPComponent()->OnDead->AddCallback(make_callback(this, &EnemyManager::OnEnemyDead));
	enemies->push_back(enemyGo);

	if (isRangeEnemy) 
	{
		enemy->SetRangeCombat(enemyGo, player);

	}
	else 
	{
		enemy->SetMeeleCombat(enemyGo, player);
		enemy->textureComponent->Tint(sf::Color::Magenta);
		enemy->tint->colorAux = sf::Color::Magenta;
	}
	
	//bool left = Random::RandomSign() < 0;
	int x = 0;
	/*if (left) 
	{
		x = Random::Range(500, 1100);
	}
	else {*/
		x = Random::Range(500, 1557);
	//}
	int y = Random::Range(380, 620);

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
	extraScoreMultiplier = std::max(extraScoreMultiplier - deltaTime, (float)0);
	if (currentTime > cadency && enemiesCreated < maxEnemies) 
	{
		currentTime = 0;
		enemiesCreated++;
		CreateEnemy();
	}

	if (endGameInSeconds != 0)
	{
		endGameInSeconds -= deltaTime;
		if (endGameInSeconds <= 0) 
		{
			GameScenes::instance->ChangeToMainMenu();
		}
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
		float calcualtedScore = (enemiesDead *32) *  (1 + (extraScoreMultiplier / MAX_EXTRA_SCORE));
		ScoreManager::instance->AddScore(new Score("UserName", calcualtedScore));
		endGameInSeconds = 2;
	}
}
