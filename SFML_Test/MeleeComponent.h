#pragma once
#include "IGameComponent.h"
#include "TransformComponent.h"
#include "VectorUtils.h"
#include "PlayerAnimation.h"
#include "HPComponent.h"

class MeleeComponent : public IGameComponent
{
private:
	float attackDistance;
	float cooldown;
	float currentCooldown;
	poke::PlayerAnimation* animation;
	poke::HPComponent* hp;
	TransformComponent* target;
	TransformComponent* meTransform;
	MovementComponent* movement;
	int damage;
public:
	MeleeComponent(float attackDistance, float cooldown);
	void Setup(int damage, GameObject* target, TransformComponent* meTransform, poke::PlayerAnimation* animation, MovementComponent* movement);
	void Update(float deltaTime);
	bool IsInRange(float distance);
	bool IsOnCooldown();
	std::string GetClassName();
};

