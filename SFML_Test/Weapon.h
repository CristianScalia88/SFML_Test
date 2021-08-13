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
	bool isPlayer; //ITs Sucks...i now xD
	float damage;
public:
	Action* OnSpecialShoot;
	int specialAttack = 3;
	Weapon(sf::Vector2f _offset, float damage, bool player);
	void Update(float deltaTime);
	void Shoot(sf::Vector2f origin, sf::Vector2f direction);
	std::string GetClassName();
	sf::Vector2f GetBulletSpawnPoint();
};

