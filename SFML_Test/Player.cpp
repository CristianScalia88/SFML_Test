#include "pch.h"
#include "Player.h"

const string PATH_JSON = "Assets/filteredSpriteSheet.json";
const string PATH_TEXTURE = "Assets/Animation.png";

Player::Player(GameObject* owner, CharacterInput* charInput, float speed, int layer)
{
	texture = new sf::Texture();
	if (!texture->loadFromFile(PATH_TEXTURE))
	{
		cout << "Texture Load from File Error" << endl;
	}


	//TODO CRETE COLLIDER HERE;
	ColliderComponent* cc = ColliderManager::instance->CreateCollider(30, 30, layer);
	owner->AddComponent(cc);

	movementComponent = new MovementComponent(charInput, speed, cc, owner->transform);
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

	tint = new TintOnDamageComponent(textureComponent, HPComponent);
	tint->colorAux = sf::Color::White;
	owner->AddComponent(tint);
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
	/*if (Input::GetKeyDown(Input::Mouse1) && GetOwner()->name == "Player") {
		cout << GetOwner()->GetPosition().x << " " << GetOwner()->GetPosition().y << " " << endl;
	}*/
}

float tintDamageCooldown;
bool tint;

std::string Player::GetClassName()
{
	return "Player";
}
