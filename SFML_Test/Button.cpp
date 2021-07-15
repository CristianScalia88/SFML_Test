#include "pch.h"
#include "Button.h"

poke::Button::Button(std::string buttonLabel,sf::Font& fontType, int fontSize, sf::Vector2f size, sf::Color _normalColor, sf::Color _overColor, sf::Color textColor)
{
	buttonBoundaries.setSize(size);
	normalColor = _normalColor;
	overColor = _overColor;

	text = sf::Text();
	text.setString(buttonLabel);
	text.setFillColor(textColor);
	text.setCharacterSize(fontSize);
	text.setFont(fontType);
	CenterText();

}

void poke::Button::SetButtonBackgroundColor(sf::Color color)
{
	buttonBoundaries.setFillColor(color);

}

void poke::Button::SetPosition(sf::Vector2f pos)
{
	buttonBoundaries.setPosition(pos);
	CenterText();
}

void poke::Button::CenterText()
{
	sf::Vector2f pos = buttonBoundaries.getPosition();
	float posX = (pos.x + buttonBoundaries.getGlobalBounds().width / 2) - (text.getLocalBounds().width / 2);
	float posY = (pos.y + buttonBoundaries.getGlobalBounds().height / 2) - (text.getLocalBounds().height /1.2);
	text.setPosition(posX, posY);
}

void poke::Button::Update(float deltaTime)
{
	bool isOver = buttonBoundaries.getGlobalBounds().contains(mousePos);
	if (isOver) 
	{
		SetButtonBackgroundColor(overColor);
		//TODO this condition should change to a mouse button up event.
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !clicked) 
		{
			clicked = true;
			(*callback)();
		}
	}
	else 
	{
		SetButtonBackgroundColor(normalColor);
	}
}

void poke::Button::Render(sf::RenderWindow* window)
{
	mousePos.x = sf::Mouse::getPosition(*window).x;
	mousePos.y = sf::Mouse::getPosition(*window).y;
	window->draw(buttonBoundaries);
	window->draw(text);
}
