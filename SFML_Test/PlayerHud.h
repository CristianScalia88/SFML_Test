#pragma once
#include "IGameComponent.h"
#include "HPComponent.h"
#include "TextComponent.h"
#include "GameObject.h"
#include "Player.h"
#include "Weapon.h"

class PlayerHud : public IGameComponent
{
private:
	poke::HPComponent * HPComponent;
	poke::TextComponent* hpText;
	poke::TextComponent* specialAttackText;
	void OnPlayerDamageHandler();
	void OnSpecialShootHandler();
	string GetPlayHP();
	sf::Font fontType;
	Player* player;
	Weapon* weapon;

public:
	PlayerHud(Player* player, GameObject * owner, Weapon* weapon);
	void Update(float deltaTime);
	void Render(sf::RenderWindow*);
	std::string GetClassName();
};

