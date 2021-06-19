#include "pch.h"
#include "MovementComponent.h"

MovementComponent::MovementComponent(CharacterInput* _characterInput, float _speed)
{
	characterInput = _characterInput;
	speed = _speed;
}

MovementComponent::~MovementComponent()
{
}

void MovementComponent::Update(float deltaTime)
{
	GetOwner()->transform->Translate(characterInput->GetDirection() * speed * deltaTime);
}
