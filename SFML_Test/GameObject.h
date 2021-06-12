#pragma once
#include "IGameComponent.h"

class GameObject
{

private:
	map<string, IGameComponent*>* components;

public:
	GameObject();
	~GameObject();

	void AddComponent(IGameComponent* component);
	IGameComponent* GetComponent(string type);

	void Start();
	void Update();
	void Render(sf::RenderWindow* );
};

