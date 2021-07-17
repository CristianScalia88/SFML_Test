#include "pch.h"
#include "HPComponent.h"

bool HPComponent::IsDead()
{
    return currentHP == 0;
}

void HPComponent::TakeDamage(int amount)
{
    currentHP -= amount;
    OnDamage->Invoke();
    if (currentHP <= 0) 
    {
        currentHP = 0;
        OnDead->Invoke();
    }
}

void HPComponent::Heal(int amount)
{
    currentHP += amount;
    OnHeal->Invoke();
    if (currentHP >= maxHP) 
    {
        currentHP = maxHP;
    }
}

void HPComponent::Update(float deltaTime)
{
}

void HPComponent::Render(sf::RenderWindow*)
{
}

std::string HPComponent::GetClassName()
{
    return "HPComponent";
}
