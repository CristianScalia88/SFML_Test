#include "pch.h"
#include "GameObject.h"

GameObject::GameObject()
{
	components = new map<string, IGameComponent*>();
	transform = new TransformComponent();
}

GameObject::~GameObject()
{
	for (auto i = components->begin(); i != components->end(); ++i)
	{
		delete i->second;
	}
	delete components;
	delete transform;
}

void GameObject::AddComponent(IGameComponent* component)
{
	components->insert(pair<string, IGameComponent*>(component->GetClassName(), component));
	component->SetOwner(this);
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

void GameObject::Update(float deltaTime)
{
	for (auto i = components->begin(); i != components->end(); ++i)
		i->second->Update(deltaTime);
}

void GameObject::Render(sf::RenderWindow * window)
{
	for (auto i = components->begin(); i != components->end(); ++i)
		i->second->Render(window);
}

void GameObject::OnTriggerEnter(GameObject* collider)
{
	for (auto i = components->begin(); i != components->end(); ++i)
		i->second->OnTriggerEnter(collider);
}

sf::Vector2f GameObject::GetPosition()
{
	return transform->position;
}
