#include "pch.h"
#include "TintOnDamageComponent.h"

TintOnDamageComponent::TintOnDamageComponent(TextureComponent* _texture, poke::HPComponent* _hp)
{
	texture = _texture;
	hp = _hp;
	hp->OnDamage->AddCallback(make_callback(this, &TintOnDamageComponent::OnTakeDamage));
}

void TintOnDamageComponent::Update(float deltaTime)
{
	if (tintDamageCooldown > 0)
	{
		cout << GetOwner()->name << endl;
		if (!tint)
		{
			tint = true;
			texture->Tint(sf::Color::Red);
		}
		tintDamageCooldown -= deltaTime;
	}
	else if (tint)
	{
		texture->Tint(sf::Color::White);
		tint = false;
	}
}

void TintOnDamageComponent::OnTakeDamage()
{
	tintDamageCooldown = .3f;
}

std::string TintOnDamageComponent::GetClassName()
{
	return "TintOnDamageComponent";
}
