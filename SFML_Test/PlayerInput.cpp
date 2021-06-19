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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		movementVector += sf::Vector2f(-1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		movementVector += sf::Vector2f(1, 0);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		movementVector += sf::Vector2f(0, -1);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		movementVector += sf::Vector2f(0, 1);
	}
	return movementVector;
}

bool PlayerInput::Attack()
{
	return false;
}
