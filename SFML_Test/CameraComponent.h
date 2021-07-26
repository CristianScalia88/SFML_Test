#pragma once
#include "IGameComponent.h"
#include "GameObject.h"
#include "Input.h"

class CameraComponent : public IGameComponent
{
private:
	sf::View* view;
public:
	CameraComponent(sf::View* view);
	void Update(float deltaTime);
	std::string GetClassName();
};

