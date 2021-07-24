#pragma once
#include "IGameComponent.h"
#include "TransformComponent.h"

class GameObject
{
private:
	map<string, IGameComponent*>* components;
public:
	string name;
	TransformComponent * transform;

	GameObject();
	~GameObject();

	void AddComponent(IGameComponent* component);
	IGameComponent* GetComponent(string type);

	void Start();
	void Update(float deltaTime);
	void Render(sf::RenderWindow* );
	void OnTriggerEnter(GameObject* collider);
	sf::Vector2f GetPosition();
};

