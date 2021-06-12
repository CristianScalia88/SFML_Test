#include "pch.h"
#include "GameObject.h"

GameObject::GameObject()
{
	components = new map<string, IGameComponent*>();
}

GameObject::~GameObject()
{
}

void GameObject::AddComponent(IGameComponent* component)
{
	components->insert(pair<string, IGameComponent*>(typeid(component).name(), component));
}

IGameComponent* GameObject::GetComponent(string type)
{
	std::map<string, IGameComponent*>::iterator it;

	it = components->find(type);
	if (it != components->end())
	{
		return components->at(type);
	}
	return nullptr;
}

void GameObject::Start()
{
}

void GameObject::Update()
{
}

void GameObject::Render(sf::RenderWindow * window)
{
	for (auto i = components->begin(); i != components->end(); ++i)
		i->second->Render(window);
}
