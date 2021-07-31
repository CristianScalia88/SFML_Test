#pragma once
#include "IGameComponent.h"
#include "TransformComponent.h"
#include "VectorUtils.h"
#include "PlayerAnimation.h"

class MeleeComponent : public IGameComponent
{
private:
	float attackDistance;
	float cooldown;
	float currentCooldown;
	poke::PlayerAnimation* animation;
	TransformComponent* target;
	TransformComponent* meTransform;
	MovementComponent* movement;

public:
	MeleeComponent(float attackDistance, float cooldown);
	void Setup(TransformComponent* target, TransformComponent* meTransform, poke::PlayerAnimation* animation, MovementComponent* movement);
	void Update(float deltaTime);
	bool IsInRange(float distance);
	bool IsOnCooldown();
	std::string GetClassName();
};

