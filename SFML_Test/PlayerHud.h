#pragma once
#include "IGameComponent.h"
#include "HPComponent.h"
#include "TextComponent.h"
#include "GameObject.h"

class PlayerHud : public IGameComponent
{
private:
	poke::HPComponent * HPComponent;
	poke::TextComponent* textComponent;
	void OnPlayerDamageHandler();
	string GetPlayHP();
	sf::Font fontType;
public:
	PlayerHud(poke::HPComponent* player, GameObject * owner);
	void Update(float deltaTime);
	void Render(sf::RenderWindow*);
};

