#pragma once
#include "IGameComponent.h"
namespace poke 
{
	class TextComponent : public IGameComponent
	{
	private:
		sf::Text text;
		sf::Color textColor = sf::Color::White;
	public:
		TextComponent(std::string text, sf::Font& fontType, int fontSize);
		void SetPosition(sf::Vector2f pos);
		void Render(sf::RenderWindow* window);
	};
}
