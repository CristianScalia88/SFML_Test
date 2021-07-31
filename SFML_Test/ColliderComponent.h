#pragma once
#include "IGameComponent.h"
#include "GameObject.h"

class ColliderComponent : public IGameComponent
{
private:
	sf::RectangleShape* collider;
	sf::Vector2f* offset;
public:
	int layer;
	ColliderComponent(float width, float height, sf::RectangleShape* collider);
	void Update(float deltaTime);
	void Render(sf::RenderWindow * window);
	void OnCollisionEnter(ColliderComponent* otherCollider);
	const sf::RectangleShape * GetRectangleShape();
	std::string GetClassName();
	void Destroy();
};

