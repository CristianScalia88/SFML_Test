#pragma once
#include "IGameComponent.h"
#include "TextureComponent.h"
#include "ScaleData.h"

class ScaleUpComponent : public IGameComponent
{
private:
	vector<ScaleData*>* queue;

public:
	ScaleUpComponent(ScaleData* scaleData, TextureComponent* _textureComponent);
	void Update(float dt);
	TextureComponent* textureComponent;
	string GetClassName();
	float currentTime = 0;
	float time = 0;
	float from = 0;
	float to = 0;
	void Add(ScaleData* scale);
};

