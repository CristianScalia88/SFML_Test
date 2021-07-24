#pragma once
#include "IGameComponent.h"
#include "Input.h"
#include "GameObject.h"
#include "VectorUtils.h"
#include "Bullet.h"
#include "Gameplay.h"

class Weapon : public IGameComponent
{
private:
	sf::Vector2f offset;
public:
	Weapon(sf::Vector2f _offset);
	void Update(float deltaTime);
	std::string GetClassName();
};

