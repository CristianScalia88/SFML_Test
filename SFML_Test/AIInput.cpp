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
	delta = VectorUtils::Normalize(delta);
	return delta;
}

bool AIInput::Attack()
{
	return VectorUtils::Magnitude(delta) < 100;
}

