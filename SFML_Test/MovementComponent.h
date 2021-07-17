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
	bool IsMoving();
	MovementComponent(CharacterInput* characterInput, float speed);
	~MovementComponent();
	virtual std::string GetClassName();
	void Update(float deltaTime);
};

