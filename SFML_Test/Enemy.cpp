#include "pch.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Gameplay.h"
#include "MeleeComponent.h"

Enemy::Enemy(ColliderManager* colliderManager, GameObject* owner, CharacterInput* charInput, float speed, TransformComponent* transformTarget) : Player(colliderManager, owner, charInput, speed)
{
	textureComponent->Tint(sf::Color::Magenta);
	target = target;

	MeleeComponent* melee = new MeleeComponent(40, 1);
	poke::PlayerAnimation* anim = (poke::PlayerAnimation*)owner->GetComponent("PlayerAnimation");
	melee->Setup(transformTarget, owner->transform, anim, (MovementComponent*)owner->GetComponent("MovementComponent"));
	owner->AddComponent(melee);
}

Enemy::~Enemy()
{
	cout << "ENEMY DESTROYED" << endl;
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
