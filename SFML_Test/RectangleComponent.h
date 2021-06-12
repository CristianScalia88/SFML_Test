#pragma once
#include "IGameComponent.h"

class RectangleComponent : public IGameComponent
{
private:
	sf::RectangleShape* rectangle;
public:
	RectangleComponent();
	~RectangleComponent();
	void Render(sf::RenderWindow* window);
};

