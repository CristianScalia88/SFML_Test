#include "pch.h"
#include "Player.h"

const string PATH_JSON = "Assets/filteredSpriteSheet.json";
const string PATH_TEXTURE = "Assets/Animation.png";

Player::Player(ColliderManager* colliderManager, GameObject* owner, CharacterInput* charInput, float speed)
{
	texture = new sf::Texture();
	if (!texture->loadFromFile(PATH_TEXTURE))
	{
		cout << "Texture Load from File Error" << endl;
	}

	movementComponent = new MovementComponent(charInput, speed);
	owner->AddComponent(movementComponent);

	std::string spriteSheetJson = poke::File::ReadAllText(PATH_JSON); //str holds the content of the file
	spriteSheet = new poke::SpriteSheet(texture, spriteSheetJson.c_str());

	textureComponent = new TextureComponent(texture);
	textureComponent->SetRectangle(spriteSheet->GetSpriteRect(0), spriteSheet->GetPivot(0));
	owner->AddComponent(textureComponent);

	HPComponent = new poke::HPComponent(100);
	HPComponent->OnDamage->AddCallback(make_callback(this, &Player::OnTakeDamage));

	playerAnimation = new poke::PlayerAnimation(textureComponent, spriteSheet, movementComponent);
	owner->AddComponent(playerAnimation);

	owner->AddComponent(colliderManager->CreateCollider(30, 30));
}

Player::~Player()
{
	delete texture;
	delete spriteSheet;
}

poke::HPComponent* Player::GetHPComponent()
{
	return HPComponent;
}

float tintDamageCooldown;
bool tint;
float t = 0;

void Player::Update(float deltaTime)
{
	t += deltaTime;
	if (t > 3) {
		t = 0;
		HPComponent->TakeDamage(4);
	}

	if (tintDamageCooldown > 0)
	{
		if (!tint) 
		{
			tint = true;
			textureComponent->Tint(sf::Color::Red);
		}
		tintDamageCooldown -= deltaTime;
	}
	else if(tint)
	{
		TextureComponent* t = (TextureComponent*)GetOwner()->GetComponent("TextureComponent");
		textureComponent->Tint(sf::Color::White);
		tint = false;
	}
}

void Player::OnTakeDamage()
{
	tintDamageCooldown = .25f;
}

std::string Player::GetClassName()
{
	return "Player";
}
