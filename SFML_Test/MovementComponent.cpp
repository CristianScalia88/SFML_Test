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

MovementComponent::MovementComponent(CharacterInput* _characterInput, float _speed, ColliderComponent* _realCollider, TransformComponent* _me)
{
	characterInput = _characterInput;
	speed = _speed;
	realCollider = _realCollider;
	placeHolderCollider = new ColliderComponent(realCollider->width, realCollider->height);
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
	sf::Vector2f newPos = realCollider->GetPosition() + characterInput->GetDirection() * speed * deltaTime;
	GetOwner()->transform->Translate(characterInput->GetDirection() * speed * deltaTime);
}
