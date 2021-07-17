#pragma once
#include "AnimationComponent.h"
#include "MovementComponent.h"

namespace poke 
{
	class PlayerAnimation : public AnimationComponent
	{
	private:
		int* idleFrameIds;
		int* runFrameIds;
		int* walkFrameIds;
		int* attackFrameIds;
		MovementComponent* moveComponent;
		sf::Vector2f* left;
		sf::Vector2f* right;
	public:
		PlayerAnimation(TextureComponent* _textureComponent, poke::SpriteSheet* _spriteSheet, MovementComponent* moveComponent);
		void RunIdle();
		void RunRun();
		void RunWalk();
		void RunAttack();
		void UpdateHorizontalTexture();
		void UpdateCurrentAnimation();
		void Update(float deltaTime);
	};
}
