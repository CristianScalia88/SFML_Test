#pragma once
#include "Player.h"

class Enemy : public Player
{
public:
	Enemy(ColliderManager* colliderManager, GameObject* owner, CharacterInput* charInput, float speed);
	void OnTriggerEnter(GameObject* go);

};

