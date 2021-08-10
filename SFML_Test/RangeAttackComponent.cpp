#include "pch.h"
#include "RangeAttackComponent.h"

RangeAttackComponent::RangeAttackComponent(float _attackDistance, float _cooldown)
{
	attackDistance = _attackDistance;
	cooldown = _cooldown;
	currentCooldown = cooldown;
}


void RangeAttackComponent::Setup(GameObject* owner, int _damage, GameObject* player, TransformComponent* _meTransform, PlayerAnimation* _animation, MovementComponent* _movement)
{
	target = player->transform;
	meTransform = _meTransform;
	animation = _animation;
	movement = _movement;
	damage = _damage;
	IGameComponent* gcop = player->GetComponent("HPComponent");
	hp = (poke::HPComponent*)gcop;

	weapon = new Weapon({ 0, -35 }, 2, false);
	owner->AddComponent(weapon);
}

void RangeAttackComponent::Update(float deltaTime)
{
	sf::Vector2f delta = (target->position + sf::Vector2f{ 0,-20 }) - weapon->GetBulletSpawnPoint();
	float magnitude = VectorUtils::Magnitude(delta);

	currentCooldown -= deltaTime;
	if (IsInRange(magnitude) && !IsOnCooldown())
	{
		movement->BlockByTime(cooldown);
		animation->RunAttack(cooldown);
		weapon->Shoot(weapon->GetBulletSpawnPoint(), (delta / magnitude));
		currentCooldown = cooldown;
	}
}

bool RangeAttackComponent::IsInRange(float distance)
{
	return distance < attackDistance;
}

bool RangeAttackComponent::IsOnCooldown()
{
	return currentCooldown > 0;
}

std::string RangeAttackComponent::GetClassName()
{
	return "RangeAttackComponent";
}
