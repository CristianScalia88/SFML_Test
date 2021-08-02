#include "pch.h"
#include "ColliderComponent.h"
#include "ColliderManager.h"

ColliderComponent::ColliderComponent(float _width, float _height)
{
	width = _width;
	height = _height;
	collider = new sf::RectangleShape(sf::Vector2f(width, height));
	offset = new sf::Vector2f(width / 2, height);
}

ColliderComponent::~ColliderComponent()
{
	delete offset;
	delete collider;
}

void ColliderComponent::Update(float deltaTime)
{
	collider->setPosition(GetOwner()->transform->position - *offset);
}

void ColliderComponent::Render(sf::RenderWindow * window)
{
	//window->draw(*collider);
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

sf::Vector2f ColliderComponent::GetPosition()
{
	return collider->getPosition();
}

void ColliderComponent::SetPosition(sf::Vector2f pos)
{
	collider->setPosition(pos);

}

void ColliderComponent::Destroy()
{
	ColliderManager::instance->RemoveCollider(this);
}
