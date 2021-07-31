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
	TextureComponent(sf::Texture* texture);
	~TextureComponent();
	void Render(sf::RenderWindow* window);
	void SetRectangle(poke::Rect* rect, poke::Pivot* pivot);
	std::string GetClassName();
	void Scale(sf::Vector2f* v2f);
	void Tint(sf::Color color);
	void LookAt(sf::Vector2f color);
	sf::Color GetColor();
};

