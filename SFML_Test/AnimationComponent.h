#pragma once

#include "IGameComponent.h"
#include "TextureComponent.h"
#include "SpriteSheet.h"

class AnimationComponent : public IGameComponent
{
private :
		const float FPS = .1f;
		TextureComponent * textureComponent;
		poke::SpriteSheet * spriteSheet;
		int* framesIDs;
		int frames;
		int currentFrameIndex;
		float totalTime;

		void UpdateSprite();
public:
	AnimationComponent(TextureComponent * textureComponent, poke::SpriteSheet * spriteSheet, int* framesIDs, int frameCount);
	~AnimationComponent();
	void Update(float deltaTime);
	std::string GetClassName();
};

