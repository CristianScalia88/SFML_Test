#include "pch.h"
#include "IGameComponent.h"
#include "GameObject.h"

void IGameComponent::Start()
{
}

void IGameComponent::Update(float deltaTime)
{
}

void IGameComponent::Render(sf::RenderWindow *)
{
}

std::string IGameComponent::GetClassName()
{
	return std::string();
}

GameObject * IGameComponent::GetOwner()
{
	return owner;
}

void IGameComponent::SetOwner(GameObject * go)
{
	owner = go;
}

void IGameComponent::Destroy()
{
}

void IGameComponent::OnTriggerEnter(GameObject* go)
{
}
