#include "pch.h"
#include "TextComponent.h"

poke::TextComponent::TextComponent(std::string labelText, sf::Font& fontType, int fontSize, bool center_)
{
	text = sf::Text();
	text.setString(labelText);
	text.setFillColor(textColor);
	text.setCharacterSize(fontSize);
	text.setFont(fontType);
	center = center_;
}

void poke::TextComponent::SetPosition(sf::Vector2f pos)
{
	float xOffset = 0;
	float yOffset = 0;
	if (center) 
	{
		xOffset = text.getLocalBounds().width / 2;
		yOffset = text.getLocalBounds().height / 2;
	}
	text.setPosition(pos.x + xOffset, pos.y + yOffset);
}

void poke::TextComponent::Render(sf::RenderWindow* window)
{
	window->draw(text);
}
