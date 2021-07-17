#include "pch.h"
#include "HPComponent.h"

poke::HPComponent::HPComponent(int maxHP)
{
    currentHP = maxHP;
    maxHP = maxHP;
}

bool poke::HPComponent::IsDead()
{
    return currentHP == 0;
}

void poke::HPComponent::TakeDamage(int amount)
{
    currentHP -= amount;
    OnDamage->Invoke();
    if (currentHP <= 0) 
    {
        currentHP = 0;
        OnDead->Invoke();
    }
}

void poke::HPComponent::Heal(int amount)
{
    currentHP += amount;
    OnHeal->Invoke();
    if (currentHP >= maxHP) 
    {
        currentHP = maxHP;
    }
}

void poke::HPComponent::Update(float deltaTime)
{
}

void poke::HPComponent::Render(sf::RenderWindow*)
{
}

std::string poke::HPComponent::GetClassName()
{
    return "HPComponent";
}
