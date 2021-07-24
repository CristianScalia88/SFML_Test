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

void Player::Update(float deltaTime)
{
	if (Input::GetKeyDown(Input::Key::Mouse1))
	{
		HPComponent->TakeDamage(1);
	}

	if (tintDamageCooldown > 0)
	{
		if (!tint) 
		{
			tint = true;
			cout << this << endl;
			textureComponent->Tint(sf::Color::Red);
		}
		tintDamageCooldown -= deltaTime;
	}
	else if(tint)
	{
		textureComponent->Tint(sf::Color::White);
		tint = false;
	}
}

void Player::OnTakeDamage()
{
	tintDamageCooldown = .3f;
}

std::string Player::GetClassName()
{
	return "Player";
}
