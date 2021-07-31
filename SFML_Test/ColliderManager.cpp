#include "pch.h"
#include "ColliderManager.h"
#include <Algorithm>

ColliderManager* ColliderManager::instance = nullptr;

const float COLLISSION_PER_SECONDS = .035f;

ColliderManager::ColliderManager()
{
	collidersMap = new map<int, vector<ColliderComponent*>*>();
	collidersMap->insert(std::pair<int, vector<ColliderComponent*>*>(PLAYER, new vector<ColliderComponent*>()));
	collidersMap->insert(std::pair<int, vector<ColliderComponent*>*>(PLAYER_BULLETS, new vector<ColliderComponent*>()));
	collidersMap->insert(std::pair<int, vector<ColliderComponent*>*>(ENEMY, new vector<ColliderComponent*>()));
	collidersMap->insert(std::pair<int, vector<ColliderComponent*>*>(ENEMY_BULLETS, new vector<ColliderComponent*>()));
	instance = this;
}

ColliderManager::~ColliderManager()
{
	cout << " DESTRYPED COLLIDER MANAGER" << endl;
}

void ColliderManager::CheckCollisions(float deltaTime)
{
	totalTime += deltaTime;
	if (totalTime >= COLLISSION_PER_SECONDS) {
		totalTime -= COLLISSION_PER_SECONDS;

		vector<ColliderComponent*>* collidersA = collidersMap->find(PLAYER_BULLETS)->second;
		vector<ColliderComponent*>* collidersB = collidersMap->find(ENEMY)->second;
		CheckCollission(collidersA, collidersB);
	}
}

void ColliderManager::CheckCollission(vector<ColliderComponent*>* collidersA, vector<ColliderComponent*>* collidersB)
{
	for (size_t i = 0; i < collidersA->size(); i++)
	{
		for (size_t j = 0; j < collidersB->size(); j++)
		{
			ColliderComponent* a = collidersA->at(i);
			ColliderComponent* b = collidersB->at(j);
			if (Intersecting(a->GetRectangleShape(), b->GetRectangleShape())) {
				a->OnCollisionEnter(b);
				b->OnCollisionEnter(a);
			}
		}
	}
}

void ColliderManager::Update(float deltaTime)
{
	CheckCollisions(deltaTime);
}

void ColliderManager::RemoveCollider(ColliderComponent* collider)
{
	vector<ColliderComponent*>* collidersA = collidersMap->find(collider->layer)->second;
	auto begin = collidersA->begin();
	auto end = collidersA->end();
	vector<ColliderComponent*>::iterator it = std::remove(begin, end, collider);
	collidersA->erase(it, collidersA->end());
}

std::string ColliderManager::GetClassName()
{
	return "ColliderManager";
}

bool ColliderManager::Intersecting(const sf::RectangleShape * a, const sf::RectangleShape * b)
{
	return a->getGlobalBounds().intersects(b->getGlobalBounds());
}

ColliderComponent * ColliderManager::CreateCollider(float width, float height, int layer)
{
	sf::RectangleShape* rectangleShape = new sf::RectangleShape(sf::Vector2f(width, height));
	rectangleShape->setOutlineColor(sf::Color::Red);
	rectangleShape->setFillColor(sf::Color::Red);

	ColliderComponent* colliderComponent = new ColliderComponent(width, height, rectangleShape);
	collidersMap->find(layer)->second->push_back(colliderComponent);
	colliderComponent->layer = layer;
	return colliderComponent;
}
