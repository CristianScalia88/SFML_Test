#pragma once

#include "IGameComponent.h"
#include "TextureComponent.h"
#include "SpriteSheet.h"
#include "Callbacks.h"

class AnimationComponent : public IGameComponent
{
private :
		const float FPS = .1f;
		poke::SpriteSheet * spriteSheet;
		int currentFrameIndex = 0;
		float totalTime = 0;
		void UpdateSprite();
		int* framesIDs;
		int frames;
protected:
	Action* OnFinish;
	TextureComponent* textureComponent;
public:
	AnimationComponent(TextureComponent * textureComponent, poke::SpriteSheet * spriteSheet);
	~AnimationComponent();
	void Update(float deltaTime);
	virtual std::string GetClassName();
	void ChangeAnimation(int* framesIDs, int frameCount);
};

