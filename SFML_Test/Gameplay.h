#pragma once

#include "Game.h"
#include "GameObject.h"
#include "ColliderManager.h"
#include "SpriteSheet.h"
#include "File.h"
#include "RectangleComponent.h"
#include "TextureComponent.h"
#include "AnimationComponent.h"
#include "MovementComponent.h"
#include "PlayerInput.h"
#include "ColliderComponent.h"

class Gameplay : public Game
{
private:
	GameObject* player;
	ColliderManager* colliderManager;
	sf::Texture* texture;
	poke::SpriteSheet* spriteSheet;
public:
	Gameplay();
	~Gameplay();
};

