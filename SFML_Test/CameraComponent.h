#pragma once
#include "IGameComponent.h"
#include "GameObject.h"
#include "Input.h"

class CameraComponent : public IGameComponent
{
private:
	sf::View* view;
	bool update;
	TransformComponent* target;
public:
	CameraComponent(sf::View* view, TransformComponent* target, bool _update);
	void Update(float deltaTime);
	std::string GetClassName();
};

