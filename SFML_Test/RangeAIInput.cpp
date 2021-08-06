#include "pch.h"
#include "RangeAIInput.h"

RangeAIInput::RangeAIInput(TransformComponent* _owner, TransformComponent* _target) : AIInput(_owner, _target)
{
	targetPosition = GetRandomPositionInLevel();
}

sf::Vector2f RangeAIInput::GetDirection()
{
	delta = targetPosition - owner->position;
	magnitude = VectorUtils::Magnitude(delta);
	if (magnitude < 30 || ShouldChangePosition())
	{
		targetPosition = GetRandomPositionInLevel();
		cout << "Destination Reached" << endl;
	}
	delta = delta/magnitude;
	return delta;
}

sf::Vector2f RangeAIInput::GetRandomPositionInLevel()
{
	sf::Vector2f randomDir = Random::RandomDirection();
	targetPosition = target->position + (randomDir * (float)100);
	targetPosition.x = Clamp(targetPosition.x, 500, 1557);
	targetPosition.y = Clamp(targetPosition.y, 380, 620);
	return targetPosition;
}

float RangeAIInput::Clamp(float v, float min, float max)
{
	v = std::min(v, max);
	v = std::max(v, min);
	return v;
}

float RangeAIInput::ShouldChangePosition()
{
	sf::Vector2f delta = targetPosition - target->position;
	float mag = VectorUtils::Magnitude(delta);
	return mag > 400;
}
