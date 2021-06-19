#include "pch.h"
#include "ColliderManager.h"


ColliderManager::ColliderManager()
{
	colliders = new vector<ColliderComponent*>();
}


ColliderManager::~ColliderManager()
{
}
static int iss;
void ColliderManager::CheckCollisions(float deltaTime)
{
	totalTime += deltaTime;
	if (totalTime >= .05f) {
		totalTime -= .05f;
		for (size_t i = 0; i < colliders->size(); i++)
		{
			for (size_t j = i + 1; j < colliders->size(); j++)
			{
				ColliderComponent * a = colliders->at(i);
				ColliderComponent * b = colliders->at(j);
				if (Intersecting(a->GetRectangleShape(), b->GetRectangleShape())) {
					a->OnCollisionEnter(b);
					b->OnCollisionEnter(a);
					
					cout << "OnCollider With " << iss++ << endl;
				}
			}
		}
	}
}

bool ColliderManager::Intersecting(const sf::RectangleShape * a, const sf::RectangleShape * b)
{
	return a->getGlobalBounds().intersects(b->getGlobalBounds());
}

ColliderComponent * ColliderManager::CreateCollider(float width, float height)
{
	sf::RectangleShape* rectangleShape = new sf::RectangleShape(sf::Vector2f(width, height));
	rectangleShape->setOutlineColor(sf::Color::Red);
	rectangleShape->setFillColor(sf::Color::Red);

	ColliderComponent* colliderComponent = new ColliderComponent(width, height, rectangleShape);
	colliders->push_back(colliderComponent);

	return colliderComponent;
}
