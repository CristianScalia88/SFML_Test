#include "pch.h"
#include "Enemy.h"

Enemy::Enemy(ColliderManager* colliderManager, GameObject* owner, CharacterInput* charInput, float speed) : Player(colliderManager, owner, charInput, speed)
{
	textureComponent->Tint(sf::Color::Magenta);
}
