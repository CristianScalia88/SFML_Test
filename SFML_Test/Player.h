#pragma once
#include "GameObject.h"
#include "SpriteSheet.h"
#include "ColliderManager.h"
#include "File.h"
#include "RectangleComponent.h"
#include "TextureComponent.h"
#include "AnimationComponent.h"
#include "MovementComponent.h"
#include "PlayerInput.h"
#include "ColliderComponent.h"
#include "HPComponent.h"

class Player : public GameObject
{
private:
	GameObject* player;
	sf::Texture* texture;
	poke::SpriteSheet* spriteSheet;
	poke::HPComponent* HP;
public:
	Player(ColliderManager* colliderManager);
	~Player();
};

