#pragma once
#include "IGameComponent.h"
#include "Callbacks.h"
#include <functional>

namespace poke 
{
	class Button : public IGameComponent
	{
	private:
		sf::Text text;
		sf::RectangleShape buttonBoundaries;
		sf::Vector2f mousePos;
		sf::Color normalColor;
		sf::Color overColor;
		bool clicked;
	public:
		Button(std::string buttonLabel, sf::Font& font, int fontSize, sf::Vector2f size, sf::Color _normalColor, sf::Color _overColor, sf::Color textColor);
		void SetButtonBackgroundColor(sf::Color color);
		void SetPosition(sf::Vector2f pos);
		void CenterText();
		void Update(float deltaTime);
		void Render(sf::RenderWindow* window);
		virtual std::string GetClassName();
		CallbackBase* callback;
	};
}