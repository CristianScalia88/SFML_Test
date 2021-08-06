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
	
	poke::HPComponent* HPComponent;
	PlayerAnimation* playerAnimation;
public:
	MovementComponent* movementComponent;
	poke::SpriteSheet* spriteSheet;
	TextureComponent* textureComponent;
	static const string PATH_JSON;
	static const string PATH_TEXTURE;
	TintOnDamageComponent* tint;
	Player(GameObject* owner, CharacterInput* charInput, float speed,int layer);
	~Player();
	poke::HPComponent* GetHPComponent();
	void SetupSprite(GameObject* owner, string jsonName, string textureName);
	virtual void SetupAnimation(GameObject* owner, PlayerAnimation* pa);
	void Update(float dt);
	std::string GetClassName();
	void OnTriggerEnter(GameObject* go);
};

