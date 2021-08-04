#pragma once
#include "AIInput.h"
#include "Random.h"

class RangeAIInput : public AIInput
{
private:
	sf::Vector2f targetPosition;
	float magnitude;
public:

	RangeAIInput(TransformComponent* _owner, TransformComponent* _target);
	sf::Vector2f GetDirection();
	sf::Vector2f GetRandomPositionInLevel();
	float Clamp(float v, float min, float max);
	float ShouldChangePosition();
};

