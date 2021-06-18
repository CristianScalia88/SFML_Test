#pragma once
#include "IGameComponent.h"
#include "TransformComponent.h"

class GameObject
{
private:
	map<string, IGameComponent*>* components;
public:
	TransformComponent * transform;

	GameObject();
	~GameObject();

	void AddComponent(IGameComponent* component);
	IGameComponent* GetComponent(string type);

	void Start();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* );
	sf::Vector2f GetPosition();
};

