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
#include "PlayerAnimation.h"
#include "IGameComponent.h"
#include "Input.h"
#include "TintOnDamageComponent.h"

class Player : public IGameComponent
{
protected:
	sf::Texture* texture;
	poke::SpriteSheet* spriteSheet;
	poke::HPComponent* HPComponent;
	poke::PlayerAnimation* playerAnimation;
	TextureComponent* textureComponent;
	MovementComponent* movementComponent;
public:
	TintOnDamageComponent* tint;
	Player(GameObject* owner, CharacterInput* charInput, float speed,int layer);
	~Player();
	poke::HPComponent* GetHPComponent();
	void Update(float dt);
	std::string GetClassName();
};

