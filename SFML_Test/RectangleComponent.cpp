#include "pch.h"
#include "RectangleComponent.h"

RectangleComponent::RectangleComponent()
{
	rectangle = new sf::RectangleShape(sf::Vector2f(10, 10));
}


RectangleComponent::~RectangleComponent()
{
}


void RectangleComponent::Render(sf::RenderWindow* window)
{
	window->draw(*rectangle);
}

string RectangleComponent::GetClassName()
{
	return "RectangleComponent";
}
