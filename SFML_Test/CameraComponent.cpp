#include "pch.h"
#include "CameraComponent.h"

CameraComponent::CameraComponent(sf::View* _view, TransformComponent* _target, bool _update)
{
	view = _view;
	view->setCenter(_target->position);
	update = _update;
	target = _target;

}


void CameraComponent::Update(float deltaTime)
{
	if (update) 
	{
		sf::Vector2f delta = target->position - view->getCenter();
		sf::Vector2f newPos = view->getCenter() + delta * (deltaTime * 3);
		newPos.y = y;
		newPos.x = std::max(minX, newPos.x);
		newPos.x = std::min(maxX, newPos.x);
		view->setCenter(newPos);
	}
}

std::string CameraComponent::GetClassName()
{
	return "CameraComponent";
}
