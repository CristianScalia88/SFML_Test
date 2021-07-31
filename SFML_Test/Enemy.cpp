#include "pch.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Gameplay.h"
#include "MeleeComponent.h"

Enemy::Enemy(GameObject* owner, CharacterInput* charInput, float speed, GameObject* player, int layer) : Player(owner, charInput, speed, layer)
{
	textureComponent->Tint(sf::Color::Magenta);
	tint->colorAux = sf::Color::Magenta;
	target = target;

	MeleeComponent* melee = new MeleeComponent(40, 1);
	poke::PlayerAnimation* anim = (poke::PlayerAnimation*)owner->GetComponent("PlayerAnimation");
	melee->Setup(1, player, owner->transform, anim, (MovementComponent*)owner->GetComponent("MovementComponent"));
	owner->AddComponent(melee);
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
		Gameplay::instance->DestroyGameObject(b->GetOwner());

	}
}
