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
		cout << shootDirection.x << " " << shootDirection.y << endl;
		Bullet* b = new Bullet(shootDirection, 450, go);
		go->AddComponent(b);
		Gameplay::instance->AddGameObject(go);
	}
}

std::string Weapon::GetClassName()
{
	return "Weapon";
}
