#pragma once
#include "IGameComponent.h"
#include "Callbacks.h"
class HPComponent : public IGameComponent
{
private:
	int currentHP;
	int maxHP;
public :
	bool IsDead();
	CallbackBase* OnDamage;
	CallbackBase* OnHeal;
	CallbackBase* OnDead;
	void TakeDamage(int amount);
	void Heal(int amount);
	void Update(float deltaTime);
	void Render(sf::RenderWindow*);
	std::string GetClassName();
};

