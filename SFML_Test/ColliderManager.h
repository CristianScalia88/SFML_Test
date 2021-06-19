#pragma once
#include "ColliderComponent.h"

class ColliderManager
{
private:
	vector<ColliderComponent*>* colliders;
	float totalTime;
	bool Intersecting(const sf::RectangleShape* a, const sf::RectangleShape* b);
public:
	ColliderComponent * CreateCollider(float width, float height);

	ColliderManager();
	~ColliderManager();

	void CheckCollisions(float deltaTime);
};

