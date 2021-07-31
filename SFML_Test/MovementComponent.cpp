#include "pch.h"
#include "MovementComponent.h"
#include "ColliderManager.h"

MovementComponent::MovementComponent(CharacterInput* _characterInput, float _speed, ColliderComponent* _realCollider, TransformComponent* _me)
{
	characterInput = _characterInput;
	speed = _speed;
	realCollider = _realCollider;
}

MovementComponent::~MovementComponent()
{
}

bool MovementComponent::IsMoving()
{
	if (cooldown > 0) 
	{
		return false;
	}
	sf::Vector2f direction = characterInput->GetDirection();
	return direction.x != 0 || direction.y != 0;
}

bool MovementComponent::IsMovingLeft()
{
	sf::Vector2f direction = characterInput->GetDirection();
	return direction.x < 0;
}

bool MovementComponent::IsMovingRight()
{
	sf::Vector2f direction = characterInput->GetDirection();
	return direction.x > 0;
}

void MovementComponent::BlockByTime(float time)
{
	cooldown = time;
}

std::string MovementComponent::GetClassName()
{
	return "MovementComponent";
}

void MovementComponent::Update(float deltaTime)
{
	if (cooldown > 0) {
		cooldown -= deltaTime;
		return;
	}
	sf::Vector2f movement = characterInput->GetDirection() * speed * deltaTime;
	
	movement = ColliderManager::instance->CheckMovement(realCollider, movement);
	GetOwner()->transform->Translate(movement);
}
