#pragma once
#include "CharacterInput.h"
#include "TransformComponent.h"

class AIInput : public CharacterInput
{
private:
	float Magnitude(const sf::Vector2f& vector);
	sf::Vector2f Normalize(const sf::Vector2f& source);
protected:
	TransformComponent* target;
	TransformComponent* owner;
	sf::Vector2f delta;
public:
	AIInput(TransformComponent * _owner, TransformComponent* _target);
	sf::Vector2f GetDirection();
	bool Attack();
};

