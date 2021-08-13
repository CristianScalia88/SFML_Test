#include "pch.h"
#include "PlayerHud.h"
#include "Gameplay.h"

void PlayerHud::OnPlayerDamageHandler()
{
	string hp = GetPlayHP();
	hpText->SetText(hp);
}

void PlayerHud::OnSpecialShootHandler()
{
	specialAttackText->SetText("Special Attack: " + std::to_string(weapon->specialAttack));
}

string PlayerHud::GetPlayHP()
{
	string currentHP = std::to_string(HPComponent->GetCurrentHP());
	string maxHP = std::to_string(HPComponent->GetMaxHP());
	return  currentHP + " / " + maxHP;
}


PlayerHud::PlayerHud(Player* _player, GameObject * _owner, Weapon* _weapon)
{
	fontType.loadFromFile("Assets/Rubric Regular.ttf");

	player = _player;
	HPComponent = player->GetHPComponent();
	HPComponent->OnDamage->AddCallback(make_callback(this, &PlayerHud::OnPlayerDamageHandler));

	hpText = new poke::TextComponent(GetPlayHP(), fontType, 20,false);
	_owner->AddComponent(hpText);
	weapon = _weapon;

	GameObject* weaponGo = new GameObject();
	specialAttackText = new poke::TextComponent("Special Attack: " + std::to_string(weapon->specialAttack), fontType, 20, false);
	weaponGo->AddComponent(specialAttackText);
	specialAttackText->SetPosition({ 0, 30 });
	Gameplay::instance->AddGameObjectHUD(weaponGo);

	_weapon->OnSpecialShoot->AddCallback(make_callback(this, &PlayerHud::OnSpecialShootHandler));
}

void PlayerHud::Update(float deltaTime)
{
}

void PlayerHud::Render(sf::RenderWindow*)
{
}

std::string PlayerHud::GetClassName()
{
	return "PlayerHud";
}
