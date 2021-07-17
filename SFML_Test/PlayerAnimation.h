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
	public:
		PlayerAnimation(TextureComponent* _textureComponent, poke::SpriteSheet* _spriteSheet, MovementComponent* moveComponent);
		void RunIdle();
		void RunRun();
		void RunWalk();
		void RunAttack();
		void Update(float deltaTime);
	};
}
