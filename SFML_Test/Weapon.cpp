#include "pch.h"
#include "Weapon.h"

void Weapon::Update(float deltaTime)
{
	if (Input::GetKeyDown(Input::Mouse0)) 
	{
		sf::Vector2f mousePos = Input::GetMousePosition();
		sf::Vector2f ownerPos = GetOwner()->transform->position;
		sf::Vector2f shootDirection = mousePos - ownerPos;
		shootDirection = VectorUtils::Normalize(shootDirection);

		GameObject* go = new GameObject();
		go->transform->Translate(ownerPos);
		Bullet* b = new Bullet(shootDirection, 1, go);
		go->AddComponent(b);
		Gameplay::instance->AddGameObject(go);
	}
}
