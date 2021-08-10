#pragma once
#include "Player.h"

class Enemy : public Player
{
public:
	TransformComponent* target;

	Enemy(GameObject* owner, CharacterInput* charInput, float speed, int layer);
	void OnTriggerEnter(GameObject* go);
	virtual void SetupSprite(GameObject* owner, string jsonName, string textureName);
	void SetMeeleCombat(GameObject* owner, GameObject* player);
	void SetRangeCombat(GameObject* owner, GameObject* player);
	void Update(float deltaTime);
	void Destroy();
};

