#include "pch.h"
#include "TextureComponent.h"
#include <math.h> 

#define PI 3.14159265

TextureComponent::TextureComponent(sf::Texture* texture)
{
	sprite = new sf::Sprite();
	sprite->setTexture(*texture);
	sprite->setOrigin((*texture).getSize().x /2, (*texture).getSize().y / 2);
}

TextureComponent::~TextureComponent()
{
	delete texture;
	delete sprite;
}

void TextureComponent::Render(sf::RenderWindow * window)
{
	sprite->setPosition(GetOwner()->transform->position);
	window->draw(*sprite);
}

void TextureComponent::SetRectangle(poke::Rect * rect, poke::Pivot * pivot)
{
	sf::IntRect intRect;
	intRect.left = rect->x;
	intRect.top = rect->y;
	intRect.width = rect->width;
	intRect.height = rect->height;
	sprite->setTextureRect(intRect);
	sprite->setOrigin(pivot->x * rect->width, rect->height - pivot->y * rect->height);
}

std::string TextureComponent::GetClassName()
{
	return "TextureComponent";
}

void TextureComponent::Scale(sf::Vector2f* v2f)
{
	if (currentScale == v2f)return;
	currentScale = v2f;
	sprite->setScale(*v2f);
}

void TextureComponent::Tint(sf::Color color)
{
	sprite->setColor(color);
}

void TextureComponent::LookAt(sf::Vector2f direction)
{
	float result = ((double)atan2(direction.y, direction.x) * (double)180) / PI;
	sprite->setRotation(result);
}

sf::Color TextureComponent::GetColor()
{
	return sprite->getColor();
}
