#include "pch.h"
#include "MovementComponent.h"

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

MovementComponent::MovementComponent(CharacterInput* _characterInput, float _speed)
{
	characterInput = _characterInput;
	speed = _speed;
}

MovementComponent::~MovementComponent()
{
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
	GetOwner()->transform->Translate(characterInput->GetDirection() * speed * deltaTime);
}
