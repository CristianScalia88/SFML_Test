#pragma once
#include "IGameComponent.h"
#include "TextureComponent.h"
#include "HPComponent.h"

class TintOnDamageComponent : public IGameComponent
{
private:
	float tintDamageCooldown;
	bool tint;
	TextureComponent* texture;
	poke::HPComponent* hp;
public:
	TintOnDamageComponent(TextureComponent* texture, poke::HPComponent* _hp);
	void Update(float deltaTime);
	void OnTakeDamage();
	std::string GetClassName();

};

