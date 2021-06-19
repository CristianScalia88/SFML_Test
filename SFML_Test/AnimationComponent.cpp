#include "pch.h"
#include "AnimationComponent.h"
#include "SpriteSheet.h"

AnimationComponent::AnimationComponent(TextureComponent * _textureComponent, poke::SpriteSheet * _spriteSheet, int* _framesIDs, int frameCount)
{
	textureComponent = _textureComponent;
	spriteSheet = _spriteSheet;
	framesIDs = _framesIDs;
	frames = frameCount;
	dirty = true;
}

AnimationComponent::~AnimationComponent()
{
}

void AnimationComponent::Update(float deltaTime)
{
	if (totalTime > .8f) 
	{
		dirty = true;
		totalTime -= .8f;
		currentFrameIndex = (currentFrameIndex + 1) % frames;
	}
	totalTime += deltaTime;

	if (dirty) 
	{
		dirty = false;
		poke::Rect* rect = spriteSheet->GetSpriteRect(framesIDs[currentFrameIndex]);
		poke::Pivot * pivot = spriteSheet->GetPivot(framesIDs[currentFrameIndex]);
		textureComponent->SetRectangle(rect, pivot);
	}
	
}

std::string AnimationComponent::GetClassName()
{
	return "AnimationComponent";
}


