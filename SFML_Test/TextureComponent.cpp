#include "pch.h"
#include "TextureComponent.h"


TextureComponent::TextureComponent(sf::Texture* texture)
{
	sprite = new sf::Sprite();
	sprite->setTexture(*texture);
}


TextureComponent::~TextureComponent()
{
	delete texture;
	delete sprite;
}

void TextureComponent::Render(sf::RenderWindow * window)
{
	window->draw(*sprite);
}

void TextureComponent::SetRectangle(poke::Rect * rect)
{
	sf::IntRect intRect;
	intRect.left = rect->x;
	intRect.top = 512 - rect->height - rect->y;
	intRect.width = rect->width;
	intRect.height = rect->height;
	sprite->setTextureRect(intRect);
}
