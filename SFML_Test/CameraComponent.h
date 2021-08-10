#pragma once
#include "IGameComponent.h"
#include "GameObject.h"
#include "Input.h"

class CameraComponent : public IGameComponent
{
private:
	const float minX = 410.0f;
	const float maxX = 1195.0f;
	const float y = 320.0f;

	sf::View* view;
	bool update;
	TransformComponent* target;
public:
	CameraComponent(sf::View* view, TransformComponent* target, bool _update);
	void Update(float deltaTime);
	std::string GetClassName();
};

