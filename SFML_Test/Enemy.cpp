#include "pch.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Gameplay.h"

Enemy::Enemy(ColliderManager* colliderManager, GameObject* owner, CharacterInput* charInput, float speed) : Player(colliderManager, owner, charInput, speed)
{
	textureComponent->Tint(sf::Color::Magenta);
}

void Enemy::OnTriggerEnter(GameObject* go)
{
	Bullet* b = (Bullet*)go->GetComponent("Bullet");
	if (b != nullptr) 
	{
		HPComponent->TakeDamage(50);
		if (HPComponent->IsDead()) 
		{
			Gameplay::instance->DestroyGameObject(GetOwner());
		}
	}
}
