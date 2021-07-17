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

	std::string spriteSheetJson = poke::File::ReadAllText(PATH_JSON); //str holds the content of the file
	spriteSheet = new poke::SpriteSheet(texture, spriteSheetJson.c_str());

	TextureComponent* textureComponent = new TextureComponent(texture);
	textureComponent->SetRectangle(spriteSheet->GetSpriteRect(0), spriteSheet->GetPivot(0));
	AddComponent(textureComponent);

	int* idleFrameIds = new int[6]{ 0, 1, 2, 3, 4, 5 };
	int* runFrameIds = new int[8]{ 6,7,8,9,10,11,12,13 };
	int* walkFrameIds = new int[6]{ 14,15,16,17,18,19 };
	int* attackFrameIds = new int[3]{ 20,21,22 };

	AnimationComponent* animationComponent = new AnimationComponent(textureComponent, spriteSheet, walkFrameIds, 6);
	AddComponent(animationComponent);

	PlayerInput* playerInput = new PlayerInput();
	MovementComponent* movementComponent = new MovementComponent(playerInput, 500);
	AddComponent(movementComponent);


	AddComponent(colliderManager->CreateCollider(30, 30));

	transform->Translate(sf::Vector2f(40, 80));
}

Player::~Player()
{
	delete texture;
	delete spriteSheet;
}
