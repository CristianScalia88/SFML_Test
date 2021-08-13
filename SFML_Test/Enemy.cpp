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
		CreateBloodFX();
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

void Enemy::CreateBloodFX()
{
	GameObject* bloodGO = new GameObject();
	SetupSprite(bloodGO, "Assets/blood.json", "Assets/blood.png", { 0,-50 });
	sf::Vector2f pos = (GetOwner()->GetPosition() + sf::Vector2f(0,10));
	bloodGO->transform->Translate(pos);
	Gameplay::instance->AddGameObject(bloodGO);
}

void Enemy::SetupSprite(GameObject* owner, string jsonName, string textureName, sf::Vector2f offset)
{
	sf::Texture * texture = new sf::Texture();

	if (!texture->loadFromFile(textureName))
	{
		cout << "Texture Load from File Error" << endl;
	}

	std::string spriteSheetJson = poke::File::ReadAllText(jsonName); //str holds the content of the file
	poke::SpriteSheet* spriteSheet = new poke::SpriteSheet(texture, spriteSheetJson.c_str());

	TextureComponent* textureComponent = new TextureComponent(texture);
	textureComponent->Scale(new sf::Vector2f(0.2f, 0.2f));

	textureComponent->offset->x = offset.x;
	textureComponent->offset->y = offset.y;
	textureComponent->SetRectangle(spriteSheet->GetSpriteRect(0), spriteSheet->GetPivot(0));
	owner->AddComponent(textureComponent);

	AnimationComponent* anim = new AnimationComponent(textureComponent, spriteSheet);
	anim->ChangeAnimation(new int[] {0, 1, 2, 3, 4}, 5);
	anim->OnFinish->AddCallback(make_callback(anim, &AnimationComponent::RemoveFromScene));
	anim->time = 0.08f;
	owner->AddComponent(anim);

}
