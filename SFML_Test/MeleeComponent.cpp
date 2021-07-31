#include "pch.h"
#include "MeleeComponent.h"

MeleeComponent::MeleeComponent(float _attackDistance, float _cooldown)
{
	attackDistance = _attackDistance;
	cooldown = _cooldown;
}

void MeleeComponent::Setup(TransformComponent* _target, TransformComponent* _meTransform, poke::PlayerAnimation* _animation, MovementComponent* _movement)
{
	target = _target;
	meTransform = _meTransform;
	animation = _animation;
	movement = _movement;
}

void MeleeComponent::Update(float deltaTime)
{
	sf::Vector2f delta = target->position - meTransform->position;
	float magnitude = VectorUtils::Magnitude(delta);
	
	currentCooldown -= deltaTime;
	if (IsInRange(magnitude) && !IsOnCooldown() )
	{
		movement->BlockByTime(cooldown);
		animation->RunAttack(cooldown);
		currentCooldown = cooldown;
	}
}

bool MeleeComponent::IsInRange(float distance)
{
	return distance < attackDistance;
}

bool MeleeComponent::IsOnCooldown()
{
	return currentCooldown > 0;
}

std::string MeleeComponent::GetClassName()
{
	return "MeleeComponent";
}
