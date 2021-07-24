#pragma once
#include "IGameComponent.h"
#include "GameObject.h"

class Bullet : public IGameComponent
{
	sf::Vector2f* direction;
	float speed;
public:
	Bullet(sf::Vector2f* _direction,float _speed);
	void Update(float deltaTime);
};

