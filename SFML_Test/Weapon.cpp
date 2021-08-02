#include "pch.h"
#include "Weapon.h"
#include "SoundManager.h"

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

		GameObject* bulletGo = new GameObject();
		bulletGo->name = "Bullet";
		bulletGo->transform->Translate(bulletSpawnPoint);
		Bullet* b = new Bullet(shootDirection, 450, bulletGo);
		bulletGo->AddComponent(b);
		bulletGo->AddComponent(ColliderManager::instance->CreateCollider(15, 15, ColliderManager::PLAYER_BULLETS));
		Gameplay::instance->AddGameObject(bulletGo);

		SoundManager::instance->Play("fireBall");
	}
}

std::string Weapon::GetClassName()
{
	return "Weapon";
}
