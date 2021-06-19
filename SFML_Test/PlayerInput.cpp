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
	sf::Vector2f movementVector;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		movementVector += sf::Vector2f(-1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		movementVector += sf::Vector2f(1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		movementVector += sf::Vector2f(0, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		movementVector += sf::Vector2f(0, 1);
	}
	return movementVector;
}

bool PlayerInput::Attack()
{
	return false;
}
