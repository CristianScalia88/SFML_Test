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

std::string MovementComponent::GetClassName()
{
	return "MovementComponent";
}

void MovementComponent::Update(float deltaTime)
{
	GetOwner()->transform->Translate(characterInput->GetDirection() * speed * deltaTime);
}
