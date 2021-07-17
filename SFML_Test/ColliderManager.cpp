#include "pch.h"
#include "ColliderManager.h"

const float COLLISSION_PER_SECONDS = .035f;
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
	if (totalTime >= COLLISSION_PER_SECONDS) {
		totalTime -= COLLISSION_PER_SECONDS;
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

void ColliderManager::Update(float deltaTime)
{
	CheckCollisions(deltaTime);
}

std::string ColliderManager::GetClassName()
{
	return "ColliderManager";
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
