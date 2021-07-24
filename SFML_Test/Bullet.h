#pragma once
#include "IGameComponent.h"
#include "GameObject.h"
#include "TextureComponent.h"

class Bullet : public IGameComponent
{
	sf::Vector2f direction;
	float speed;
	sf::Texture* texture;

public:
	Bullet(sf::Vector2f _direction, float _speed, GameObject* owner);
	~Bullet();
	void Update(float deltaTime);
	std::string GetClassName();
};

