#pragma once
#include "IGameComponent.h"
#include "Rect.h"

class TextureComponent : public IGameComponent
{
private:
	sf::Texture* texture;
	sf::Sprite* sprite;
public:
	TextureComponent(sf::Texture* texture);
	~TextureComponent();
	void Render(sf::RenderWindow* window);
	void SetRectangle(poke::Rect* rect);
};

