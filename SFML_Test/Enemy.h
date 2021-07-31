#pragma once
#include "Player.h"

class Enemy : public Player
{
public:
	TransformComponent* target;

	Enemy(ColliderManager* colliderManager, GameObject* owner, CharacterInput* charInput, float speed, GameObject * target);
	void OnTriggerEnter(GameObject* go);

};

