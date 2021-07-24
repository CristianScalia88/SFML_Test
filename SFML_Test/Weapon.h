#pragma once
#include "IGameComponent.h"
#include "Input.h"
#include "GameObject.h"
#include "VectorUtils.h"
#include "Bullet.h"
#include "Gameplay.h"

class Weapon : public IGameComponent
{
public:
	void Update(float deltaTime);
	std::string GetClassName();
};

