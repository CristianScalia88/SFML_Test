#pragma once
#include "IGameComponent.h"
#include "GameObject.h"

class ColliderComponent : public IGameComponent
{
private:
	sf::RectangleShape* collider;
	sf::Vector2f* offset;
public:
	ColliderComponent(float width, float height, sf::RectangleShape* collider);
	~ColliderComponent();
	void Update(float deltaTime);
	void Render(sf::RenderWindow * window);
	void OnCollisionEnter(ColliderComponent* otherCollider);
	const sf::RectangleShape * GetRectangleShape();
	std::string GetClassName();
};

