#pragma once
#include "CharacterInput.h"
#include <list>

class PlayerInput : public CharacterInput
{
public:
	PlayerInput();
	~PlayerInput();
	sf::Vector2f GetDirection();
	bool Attack();
};

