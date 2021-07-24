#include "pch.h"
#include "Bullet.h"

Bullet::Bullet(sf::Vector2f* _direction, float _speed)
{
	direction = _direction;
	speed = _speed;
}

void Bullet::Update(float deltaTime)
{
	sf::Vector2f newPos = GetOwner()->transform->position + (*direction * speed * deltaTime);
	GetOwner()->transform->Translate(newPos);
}
