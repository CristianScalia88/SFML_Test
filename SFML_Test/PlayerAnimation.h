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
		float cooldown;
	public:
		PlayerAnimation(TextureComponent* _textureComponent, poke::SpriteSheet* _spriteSheet, MovementComponent* moveComponent);
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
}
