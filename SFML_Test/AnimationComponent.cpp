#include "pch.h"
#include "AnimationComponent.h"
#include "SpriteSheet.h"

AnimationComponent::AnimationComponent(TextureComponent * _textureComponent, poke::SpriteSheet * _spriteSheet)
{
	textureComponent = _textureComponent;
	spriteSheet = _spriteSheet;
	totalTime = FPS;
	OnFinish = new Action();
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
		currentFrameIndex++;
		currentFrameIndex = currentFrameIndex % frames ;
		if (currentFrameIndex == frames -1) {
			OnFinish->Invoke();
			OnFinish->Clear();
		}
	}
	totalTime += deltaTime;
}

std::string AnimationComponent::GetClassName()
{
	return "AnimationComponent";
}

void AnimationComponent::ChangeAnimation(int* _framesIDs, int frameCount)
{
	if (framesIDs == _framesIDs) 
	{
		return;
	}
	framesIDs = _framesIDs;
	frames = frameCount;
	currentFrameIndex = 0;
	totalTime = 0;
}


