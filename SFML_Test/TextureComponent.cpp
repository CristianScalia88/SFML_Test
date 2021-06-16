#include "pch.h"
#include "TextureComponent.h"


TextureComponent::TextureComponent(const std::string path)
{
	sf::Texture texture;
	if(!texture.loadFromFile(path))
	{
		cout << "Load Failed" << endl;
	}
	sprite.setTexture(texture);
}


TextureComponent::~TextureComponent()
{
}

void TextureComponent::Render(sf::RenderWindow * window)
{
	window->draw(sprite);
}
