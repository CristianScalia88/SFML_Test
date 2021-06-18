#include "pch.h"
#include "TransformComponent.h"


TransformComponent::TransformComponent()
{
}


TransformComponent::~TransformComponent()
{
}

void TransformComponent::Translate(sf::Vector2f movement)
{
	position += movement;
}

std::string TransformComponent::GetClassName()
{
	return "TransformComponent";
}
