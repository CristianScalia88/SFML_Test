#include "pch.h"
#include "Player.h"

const string PATH_JSON = "Assets/filteredSpriteSheet.json";
const string PATH_TEXTURE = "Assets/Animation.png";

Player::Player(ColliderManager* colliderManager) : GameObject()
{
	texture = new sf::Texture();
	if (!texture->loadFromFile(PATH_TEXTURE))
	{
		cout << "Texture Load from File Error" << endl;
	}

	PlayerInput* playerInput = new PlayerInput();
	MovementComponent* movementComponent = new MovementComponent(playerInput, 150);
	AddComponent(movementComponent);

	std::string spriteSheetJson = poke::File::ReadAllText(PATH_JSON); //str holds the content of the file
	spriteSheet = new poke::SpriteSheet(texture, spriteSheetJson.c_str());

	TextureComponent* textureComponent = new TextureComponent(texture);
	textureComponent->SetRectangle(spriteSheet->GetSpriteRect(0), spriteSheet->GetPivot(0));
	AddComponent(textureComponent);

	HPComponent = new poke::HPComponent(100);
	playerAnimation = new poke::PlayerAnimation(textureComponent, spriteSheet, movementComponent);
	AddComponent(playerAnimation);

	AddComponent(colliderManager->CreateCollider(30, 30));

	transform->Translate(sf::Vector2f(40, 80));
}

Player::~Player()
{
	delete texture;
	delete spriteSheet;
}
