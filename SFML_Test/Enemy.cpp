#include "pch.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Gameplay.h"
#include "MeleeComponent.h"
#include "RangeAttackComponent.h"
#include "ScaleUpComponent.h"
#include "ScaleData.h"

Enemy::Enemy(GameObject* owner, CharacterInput* charInput, float speed, int layer) : Player(owner, charInput, speed, layer)
{
	target = target;
}

void Enemy::OnTriggerEnter(GameObject* go)
{
	if (HPComponent->IsDead())
		return;
	Bullet* b = (Bullet*)go->GetComponent("Bullet");
	if (b != nullptr) 
	{
		HPComponent->TakeDamage(b->damage);
		if (HPComponent->IsDead()) 
		{
			ScaleUpComponent* anim = (ScaleUpComponent*)GetOwner()->GetComponent("ScaleUpComponent");
			ScaleData* sd = new ScaleData(1, 0, .15f);
			sd->cb = make_callback(this, &Enemy::Destroy);
			anim->Add(sd);
		}
		Gameplay::instance->DestroyGameObject(b->GetOwner());
	}
}

void Enemy::SetupSprite(GameObject* owner, string jsonName, string textureName)
{
	Player::SetupSprite(owner, jsonName, textureName);
}

void Enemy::SetMeeleCombat(GameObject* owner, GameObject* player)
{
	MeleeComponent* melee = new MeleeComponent(40, 1);
	PlayerAnimation* anim = (PlayerAnimation*)owner->GetComponent("PlayerAnimation");
	melee->Setup(1, player, owner->transform, anim, (MovementComponent*)owner->GetComponent("MovementComponent"));
	owner->AddComponent(melee);
}

void Enemy::SetRangeCombat(GameObject* owner, GameObject* player)
{
	RangeAttackComponent* attack = new RangeAttackComponent(300, 3);
	PlayerAnimation* anim = (PlayerAnimation*)owner->GetComponent("PlayerAnimation");
	attack->Setup(owner, 1, player, owner->transform, anim, (MovementComponent*)owner->GetComponent("MovementComponent"));
	owner->AddComponent(attack);
}

void Enemy::Update(float deltaTime)
{
}

void Enemy::Destroy()
{
	Gameplay::instance->DestroyGameObject(GetOwner());
}
