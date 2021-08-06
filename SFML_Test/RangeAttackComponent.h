#pragma once
#include "IGameComponent.h"
#include "PlayerAnimation.h"
#include "HPComponent.h"
#include "VectorUtils.h"
#include "GameObject.h"
#include "Weapon.h"

class RangeAttackComponent : public IGameComponent
{
private:
	float attackDistance;
	float cooldown;
	float currentCooldown;
	PlayerAnimation* animation;
	poke::HPComponent* hp;
	TransformComponent* target;
	TransformComponent* meTransform;
	MovementComponent* movement;
	Weapon* weapon;
	int damage;
public:
	RangeAttackComponent(float attackDistance, float cooldown);
	void Setup(GameObject* owner, int damage, GameObject* target, TransformComponent* meTransform, PlayerAnimation* animation, MovementComponent* movement);
	void Update(float deltaTime);
	bool IsInRange(float distance);
	bool IsOnCooldown();
	std::string GetClassName();
};
