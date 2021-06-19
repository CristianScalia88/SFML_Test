#pragma once
#include "CharacterInput.h"
class PlayerInput : public CharacterInput
{
public:
	PlayerInput();
	~PlayerInput();
	sf::Vector2f GetDirection();
	bool Attack();
};

