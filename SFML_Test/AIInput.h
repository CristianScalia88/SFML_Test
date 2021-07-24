#pragma once
#include "CharacterInput.h"
#include "TransformComponent.h"
#include "VectorUtils.h"

class AIInput : public CharacterInput
{
protected:
	TransformComponent* target;
	TransformComponent* owner;
	sf::Vector2f delta;
public:
	
	AIInput(TransformComponent * _owner, TransformComponent* _target);
	sf::Vector2f GetDirection();
	bool Attack();
};

