#pragma once
#include "Player.h"

class Enemy : public Player
{
public:
	TransformComponent* target;

	Enemy(ColliderManager* colliderManager, GameObject* owner, CharacterInput* charInput, float speed, TransformComponent * target);
	void OnTriggerEnter(GameObject* go);

};

