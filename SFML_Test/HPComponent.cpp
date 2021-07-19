#include "pch.h"
#include "HPComponent.h"

poke::HPComponent::HPComponent(int _maxHP)
{
    currentHP = _maxHP;
    maxHP = _maxHP;
    OnDamage = new Action();
    OnHeal = new Action();
    OnDead = new Action();
}

poke::HPComponent::~HPComponent()
{
    delete OnDamage;
    delete OnHeal;
    delete OnDead;
}

bool poke::HPComponent::IsDead()
{
    return currentHP == 0;
}

int poke::HPComponent::GetCurrentHP()
{
    return currentHP;
}

int poke::HPComponent::GetMaxHP()
{
    return maxHP;
}

void poke::HPComponent::TakeDamage(int amount)
{
    currentHP -= amount;
    if (currentHP <= 0) 
    {
        currentHP = 0;
        OnDamage->Invoke();
        OnDead->Invoke();
    }
    else
    {
        OnDamage->Invoke();
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
