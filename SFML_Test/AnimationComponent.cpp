#include "pch.h"
#include "AnimationComponent.h"
#include "SpriteSheet.h"

AnimationComponent::AnimationComponent(TextureComponent * _textureComponent, poke::SpriteSheet * _spriteSheet, int* _framesIDs, int frameCount)
{
	textureComponent = _textureComponent;
	spriteSheet = _spriteSheet;
	framesIDs = _framesIDs;
	frames = frameCount;
	totalTime = FPS;
}

AnimationComponent::~AnimationComponent()
{
}

void AnimationComponent::UpdateSprite()
{
	poke::Rect* rect = spriteSheet->GetSpriteRect(framesIDs[currentFrameIndex]);
	poke::Pivot * pivot = spriteSheet->GetPivot(framesIDs[currentFrameIndex]);
	textureComponent->SetRectangle(rect, pivot);
}

void AnimationComponent::Update(float deltaTime)
{
	if (totalTime >= FPS)
	{
		UpdateSprite();

		totalTime -= FPS;
		currentFrameIndex = (currentFrameIndex + 1) % frames;
	}
	totalTime += deltaTime;
}

std::string AnimationComponent::GetClassName()
{
	return "AnimationComponent";
}


