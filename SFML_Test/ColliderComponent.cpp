#include "pch.h"
#include "ColliderComponent.h"
#include "ColliderManager.h"

ColliderComponent::ColliderComponent(float width, float height, sf::RectangleShape* _collider)
{
	collider = _collider;
	collider->setOutlineColor(sf::Color::Red);
	collider->setFillColor(sf::Color::Red);
	offset = new sf::Vector2f(width / 2, height);
}

void ColliderComponent::Update(float deltaTime)
{
	collider->setPosition(GetOwner()->transform->position - *offset);
}

void ColliderComponent::Render(sf::RenderWindow * window)
{
	window->draw(*collider);
}

void ColliderComponent::OnCollisionEnter(ColliderComponent* otherCollider)
{
	GetOwner()->OnTriggerEnter(otherCollider->GetOwner());
}

const sf::RectangleShape * ColliderComponent::GetRectangleShape()
{
	return collider;
}

std::string ColliderComponent::GetClassName()
{
	return "ColliderComponent";
}

void ColliderComponent::Destroy()
{
	ColliderManager::instance->RemoveCollider(this);
	delete offset;
	delete collider;
}
