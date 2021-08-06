#pragma once
#include "AnimationComponent.h"
#include "MovementComponent.h"

class PlayerAnimation : public AnimationComponent
{
private:
	MovementComponent* moveComponent;
	sf::Vector2f* left;
	sf::Vector2f* right;
	float cooldown;
protected:
	int* idleFrameIds;
	int* runFrameIds;
	int* walkFrameIds;
	int* attackFrameIds;
public:
	PlayerAnimation(TextureComponent* _textureComponent, poke::SpriteSheet* _spriteSheet, MovementComponent* moveComponent,int* idle, int* walk, int* attack);
	~PlayerAnimation();
	void RunIdle();
	void RunRun();
	void RunWalk();
	void RunAttack(float _cooldown);
	void UpdateHorizontalTexture();
	void UpdateCurrentAnimation();
	void Update(float deltaTime);
	std::string GetClassName();
};