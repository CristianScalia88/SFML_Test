#pragma once
#include "IGameComponent.h"

class TransformComponent : public IGameComponent
{
	
public:
	sf::Vector2f position;
	float rotation;

	TransformComponent();
	~TransformComponent();
	void Translate(sf::Vector2f movement);
	std::string GetClassName();
};

