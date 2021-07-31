#pragma once
#include "Player.h"

class Enemy : public Player
{
public:
	TransformComponent* target;

	Enemy(GameObject* owner, CharacterInput* charInput, float speed, GameObject * target, int layer);
	void OnTriggerEnter(GameObject* go);

};

