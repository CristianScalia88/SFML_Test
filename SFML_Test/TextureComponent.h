#pragma once
#include "IGameComponent.h"

class TextureComponent : public IGameComponent
{
private:
	sf::Sprite sprite;
public:
	TextureComponent(std::string path);
	~TextureComponent();
	void Render(sf::RenderWindow* window);
};

