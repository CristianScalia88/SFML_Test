#include "pch.h"
#include "Weapon.h"

Weapon::Weapon(sf::Vector2f _offset)
{
	offset = _offset;
}

void Weapon::Update(float deltaTime)
{
	if (Input::GetKeyDown(Input::Mouse0)) 
	{
		sf::Vector2f mousePos = Input::GetMousePosition();
		sf::Vector2f bulletSpawnPoint = GetOwner()->transform->position + offset;
		sf::Vector2f shootDirection = mousePos - bulletSpawnPoint;
		shootDirection = VectorUtils::Normalize(shootDirection);

		GameObject* go = new GameObject();
		go->transform->Translate(bulletSpawnPoint);

		Bullet* b = new Bullet(shootDirection, 450, go);
		go->AddComponent(b);
		Gameplay::instance->AddGameObject(go);
	}
}

std::string Weapon::GetClassName()
{
	return "Weapon";
}
