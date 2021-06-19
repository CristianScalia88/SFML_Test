#pragma once
#include "IGameComponent.h"
#include "GameObject.h"

class PlayerInputComponent : IGameComponent
{
public:
	PlayerInputComponent();
	~PlayerInputComponent();
	std::string GetClassName();
	void Update(float deltaTime);
};

