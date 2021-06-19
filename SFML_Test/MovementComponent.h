#pragma once
#include "IGameComponent.h"
#include "GameObject.h"
#include "CharacterInput.h"

class MovementComponent :
	public IGameComponent
{
private:
	float speed;
	CharacterInput* characterInput;
public:
	MovementComponent(CharacterInput* characterInput, float speed);
	~MovementComponent();
	void Update(float deltaTime);
};

