#pragma once
#include "IGameComponent.h"
#include "GameObject.h"
#include "CharacterInput.h"
#include "ColliderComponent.h"

class MovementComponent :
	public IGameComponent
{
private:
	CharacterInput* characterInput;
	float cooldown = 0;
	ColliderComponent* realCollider;
public:
	float speed;
	bool IsMoving();
	bool IsMovingLeft();
	bool IsMovingRight();
	MovementComponent(CharacterInput* characterInput, float speed, ColliderComponent* realCollider, TransformComponent* me);
	~MovementComponent();
	void BlockByTime(float time);
	virtual std::string GetClassName();
	void Update(float deltaTime);
};

