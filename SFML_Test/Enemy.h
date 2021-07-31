#pragma once
#include "Player.h"

class Enemy : public Player
{
public:
	TransformComponent* target;

	Enemy(ColliderManager* colliderManager, GameObject* owner, CharacterInput* charInput, float speed, TransformComponent * target);
	~Enemy();
	void OnTriggerEnter(GameObject* go);

};

