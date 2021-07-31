#include "pch.h"
#include "PlayerAnimation.h"

poke::PlayerAnimation::PlayerAnimation(TextureComponent* _textureComponent, poke::SpriteSheet* _spriteSheet, MovementComponent* _moveComponent) : AnimationComponent(_textureComponent, _spriteSheet)
{
	idleFrameIds = new int[6]{ 0, 1, 2, 3, 4, 5 };
	runFrameIds = new int[8]{ 6,7,8,9,10,11,12,13 };
	walkFrameIds = new int[6]{ 14,15,16,17,18,19 };
	attackFrameIds = new int[3]{ 20,21,22 };
	moveComponent = _moveComponent;
	RunIdle();
	left = new sf::Vector2f(-1, 1);
	right = new sf::Vector2f(1, 1);
}

poke::PlayerAnimation::~PlayerAnimation()
{
	delete[] idleFrameIds;
	delete[] runFrameIds;
	delete[] walkFrameIds;
	delete[] attackFrameIds;
}

void poke::PlayerAnimation::RunIdle()
{
	ChangeAnimation(idleFrameIds, 6);
}

void poke::PlayerAnimation::RunRun()
{
	ChangeAnimation(runFrameIds, 8);
}

void poke::PlayerAnimation::RunWalk()
{
	ChangeAnimation(walkFrameIds, 6);
}

void poke::PlayerAnimation::RunAttack(float _cooldown)
{
	cooldown = _cooldown;
	ChangeAnimation(attackFrameIds, 3);
	OnFinish->AddCallback(make_callback(this, &PlayerAnimation::RunIdle));
}

void poke::PlayerAnimation::UpdateHorizontalTexture()
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

void poke::PlayerAnimation::UpdateCurrentAnimation()
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

void poke::PlayerAnimation::Update(float deltaTime)
{
	AnimationComponent::Update(deltaTime);
	if (cooldown > 0) 
	{
		cooldown -= deltaTime;
		if (cooldown <= 0) {
			cout << "Cooldown Finished " << endl;
		}
		return;
	}

	UpdateHorizontalTexture();
	UpdateCurrentAnimation();
}

std::string poke::PlayerAnimation::GetClassName()
{
	return "PlayerAnimation";
}
