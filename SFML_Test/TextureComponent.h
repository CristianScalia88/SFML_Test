#pragma once
#include "IGameComponent.h"
#include "Rect.h"
#include "Pivot.h"
#include "GameObject.h"

class TextureComponent : public IGameComponent
{
private:
	sf::Texture* texture = nullptr;
	sf::Sprite* sprite = nullptr;
	sf::Vector2f* currentScale;
public:
	sf::Vector2f* offset = new sf::Vector2f(0, 0);
	TextureComponent(sf::Texture* texture);
	TextureComponent(sf::Texture* texture, float x, float y);
	~TextureComponent();
	void Render(sf::RenderWindow* window);
	void SetRectangle(poke::Rect* rect, poke::Pivot* pivot);
	std::string GetClassName();
	void Scale(sf::Vector2f* v2f);
	sf::Vector2f GetScale();
	void Tint(sf::Color color);
	void LookAt(sf::Vector2f color);
	sf::Color GetColor();
};

