#pragma once
#include "IGameComponent.h"
#include "GameObject.h"
#include "CharacterInput.h"

class MovementComponent :
	public IGameComponent
{
private:
	CharacterInput* characterInput;
public:
	float speed;
	bool IsMoving();
	bool IsMovingLeft();
	bool IsMovingRight();
	MovementComponent(CharacterInput* characterInput, float speed);
	~MovementComponent();
	virtual std::string GetClassName();
	void Update(float deltaTime);
};

