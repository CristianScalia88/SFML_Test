#include "pch.h"
#include "AnimationComponent.h"
#include "SpriteSheet.h"

AnimationComponent::AnimationComponent(TextureComponent * _textureComponent, poke::SpriteSheet * _spriteSheet, int* _framesIDs, int frameCount)
{
	textureComponent = _textureComponent;
	spriteSheet = _spriteSheet;
	framesIDs = _framesIDs;
	frames = frameCount;
}

AnimationComponent::~AnimationComponent()
{
}

void AnimationComponent::Update(float deltaTime)
{
	if (totalTime > .1f) 
	{
		totalTime -= .1f;
		currentFrameIndex = (currentFrameIndex + 1) % frames;
	}
	totalTime += deltaTime;
	poke::Rect* rect = spriteSheet->GetSpriteRect(framesIDs[currentFrameIndex]);
	poke::Pivot * pivot = spriteSheet->GetPivot(0);
	textureComponent->SetRectangle(rect, pivot);
}

std::string AnimationComponent::GetClassName()
{
	return "AnimationComponent";
}


