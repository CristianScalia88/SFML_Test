#include "pch.h"
#include "AIInput.h"

AIInput::AIInput(TransformComponent* _owner, TransformComponent * _target)
{
	target = _target;
	owner = _owner;
}

sf::Vector2f AIInput::GetDirection()
{
	delta = target->position - owner->position;
	delta = Normalize(delta);
	return delta;
}

bool AIInput::Attack()
{
	return Magnitude(delta) < 100;
}

float AIInput::Magnitude(const sf::Vector2f& vector)
{
	return sqrt((vector.x * vector.x) + (vector.y * vector.y));
}

sf::Vector2f AIInput::Normalize(const sf::Vector2f& source)
{
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0)
		return sf::Vector2f(source.x / length, source.y / length);
	else
		return source;
}
