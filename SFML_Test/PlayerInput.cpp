#include "pch.h"
#include "PlayerInput.h"


PlayerInput::PlayerInput()
{
}


PlayerInput::~PlayerInput()
{
}

sf::Vector2f PlayerInput::GetDirection()
{
	return sf::Vector2f(1, 0);
}

bool PlayerInput::Attack()
{
	return false;
}
