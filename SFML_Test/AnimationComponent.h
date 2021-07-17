#pragma once

#include "IGameComponent.h"
#include "TextureComponent.h"
#include "SpriteSheet.h"

class AnimationComponent : public IGameComponent
{
private :
		const float FPS = .1f;
		poke::SpriteSheet * spriteSheet;
		int currentFrameIndex;
		float totalTime;
		void UpdateSprite();
		int* framesIDs;
		int frames;
protected:
	TextureComponent* textureComponent;
public:
	AnimationComponent(TextureComponent * textureComponent, poke::SpriteSheet * spriteSheet);
	~AnimationComponent();
	void Update(float deltaTime);
	std::string GetClassName();
	void ChangeAnimation(int* framesIDs, int frameCount);
};

