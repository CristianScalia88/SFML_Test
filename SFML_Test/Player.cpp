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
	owner->AddComponent(HPComponent);

	playerAnimation = new poke::PlayerAnimation(textureComponent, spriteSheet, movementComponent);
	owner->AddComponent(playerAnimation);

	owner->AddComponent(new TintOnDamageComponent(textureComponent, HPComponent));
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

void Player::Update(float dt)
{
	if (Input::GetKeyDown(Input::Mouse1)) {
		HPComponent->TakeDamage(101);
	}
}

float tintDamageCooldown;
bool tint;

std::string Player::GetClassName()
{
	return "Player";
}
