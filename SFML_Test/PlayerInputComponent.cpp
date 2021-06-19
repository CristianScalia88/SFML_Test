#include "pch.h"
#include "PlayerInputComponent.h"

PlayerInputComponent::PlayerInputComponent()
{
}

PlayerInputComponent::~PlayerInputComponent()
{
}

std::string PlayerInputComponent::GetClassName()
{
	return "PlayerInput";
}

void PlayerInputComponent::Update(float deltaTime)
{
	GetOwner()->transform->position += sf::Vector2f(10, 0) * deltaTime;
}
