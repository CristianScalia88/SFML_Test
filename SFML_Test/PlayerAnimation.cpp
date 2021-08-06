#include "pch.h"
#include "PlayerAnimation.h"

PlayerAnimation::PlayerAnimation(TextureComponent* _textureComponent, poke::SpriteSheet* _spriteSheet, MovementComponent* _moveComponent, int* _idle, int* _walk, int* _attack) : AnimationComponent(_textureComponent, _spriteSheet)
{
	idleFrameIds = _idle;
	runFrameIds = new int[8]{ 6,7,8,9,10,11,12,13 };
	walkFrameIds = _walk;
	attackFrameIds = _attack;
	moveComponent = _moveComponent;
	RunIdle();
	left = new sf::Vector2f(-1, 1);
	right = new sf::Vector2f(1, 1);
}

PlayerAnimation::~PlayerAnimation()
{
	delete[] idleFrameIds;
	delete[] runFrameIds;
	delete[] walkFrameIds;
	delete[] attackFrameIds;
}

void PlayerAnimation::RunIdle()
{
	ChangeAnimation(idleFrameIds, 6);
}

void PlayerAnimation::RunRun()
{
	ChangeAnimation(runFrameIds, 8);
}

void PlayerAnimation::RunWalk()
{
	ChangeAnimation(walkFrameIds, 6);
}

void PlayerAnimation::RunAttack(float _cooldown)
{
	cooldown = _cooldown;
	ChangeAnimation(attackFrameIds, 3);
	OnFinish->AddCallback(make_callback(this, &PlayerAnimation::RunIdle));
}

void PlayerAnimation::UpdateHorizontalTexture()
{
	if (moveComponent->IsMovingLeft())
	{
		textureComponent->Scale(left);
	}
	else if(moveComponent->IsMovingRight())
	{
		textureComponent->Scale(right);
	}
}

void PlayerAnimation::UpdateCurrentAnimation()
{
	if (moveComponent->IsMoving())
	{
		RunWalk();
	}
	else 
	{
		RunIdle();
	}
}

void PlayerAnimation::Update(float deltaTime)
{
	AnimationComponent::Update(deltaTime);
	if (cooldown > 0) 
	{
		cooldown -= deltaTime;
		return;
	}

	UpdateHorizontalTexture();
	UpdateCurrentAnimation();
}

std::string PlayerAnimation::GetClassName()
{
	return "PlayerAnimation";
}
