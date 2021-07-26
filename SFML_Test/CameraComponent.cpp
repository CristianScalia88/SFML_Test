#include "pch.h"
#include "CameraComponent.h"

CameraComponent::CameraComponent(sf::View* _view)
{
	view = _view;
}

void CameraComponent::Update(float deltaTime)
{
	view->setCenter(GetOwner()->transform->position);
}

std::string CameraComponent::GetClassName()
{
	return "CameraComponent";
}
