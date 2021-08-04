#pragma once
#include "CharacterInput.h"
#include "TransformComponent.h"
#include "VectorUtils.h"

class AIInput : public CharacterInput
{
protected:
	TransformComponent* owner;
	sf::Vector2f delta;
public:
	TransformComponent* target;
	AIInput(TransformComponent * _owner, TransformComponent* _target);
	virtual sf::Vector2f GetDirection();
	bool Attack();
};

