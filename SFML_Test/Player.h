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
	Player(ColliderManager* colliderManager, GameObject* owner, CharacterInput* charInput, float speed);
	~Player();
	poke::HPComponent* GetHPComponent();
	void Update(float deltaTime);
	void OnTakeDamage();
	std::string GetClassName();
};

