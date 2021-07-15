#include "pch.h"
#include "TextComponent.h"

poke::TextComponent::TextComponent(std::string labelText, sf::Font& fontType, int fontSize)
{
	text = sf::Text();
	text.setString(labelText);
	text.setFillColor(textColor);
	text.setCharacterSize(fontSize);
	text.setFont(fontType);
}

void poke::TextComponent::SetPosition(sf::Vector2f pos)
{
	text.setPosition(pos.x, pos.y);
}

void poke::TextComponent::Render(sf::RenderWindow* window)
{
	window->draw(text);
}
