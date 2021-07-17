#pragma once
#include "IGameComponent.h"
namespace poke 
{
	class TextComponent : public IGameComponent
	{
	private:
		sf::Text text;
		sf::Color textColor = sf::Color::White;
		bool center;
	public:
		TextComponent(std::string text, sf::Font& fontType, int fontSize, bool center = true);
		void SetPosition(sf::Vector2f pos);
		void Render(sf::RenderWindow* window);
		virtual std::string GetClassName();
	};
}
