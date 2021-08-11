#include "pch.h"
#include "Player.h"
#include "Bullet.h"
#include "ScaleUpComponent.h"


const string Player::PATH_JSON = "Assets/player.json";
const string Player::PATH_TEXTURE = "Assets/player.png";

Player::Player(GameObject* owner, CharacterInput* charInput, float speed, int layer)
{
	texture = new sf::Texture();
	
	//TODO CRETE COLLIDER HERE;
	ColliderComponent* cc = ColliderManager::instance->CreateCollider(30, 30, layer);
	owner->AddComponent(cc);

	movementComponent = new MovementComponent(charInput, speed, cc, owner->transform);
	owner->AddComponent(movementComponent);


	HPComponent = new poke::HPComponent(100);
	owner->AddComponent(HPComponent);	
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

void Player::Update(float deltaTime)
{
	
}

void Player::SetupSprite(GameObject* owner, string jsonName, string textureName)
{
	if (!texture->loadFromFile(textureName))
	{
		cout << "Texture Load from File Error" << endl;
	}

	std::string spriteSheetJson = poke::File::ReadAllText(jsonName); //str holds the content of the file
	spriteSheet = new poke::SpriteSheet(texture, spriteSheetJson.c_str());

	textureComponent = new TextureComponent(texture);
	textureComponent->SetRectangle(spriteSheet->GetSpriteRect(0), spriteSheet->GetPivot(0));
	owner->AddComponent(textureComponent);

	tint = new TintOnDamageComponent(textureComponent, HPComponent);
	tint->colorAux = sf::Color::White;
	owner->AddComponent(tint);
	ScaleData* sd1 = new ScaleData(0, 1.2f, .5f);
	ScaleData* sd2 = new ScaleData(1.2f, 1, .2f);
	ScaleUpComponent* scaleUp = new ScaleUpComponent(sd1, textureComponent);
	scaleUp->Add(sd2);
	owner->AddComponent(scaleUp);
}

void Player::OnTriggerEnter(GameObject* go)
{
	Bullet* b = (Bullet*)go->GetComponent("Bullet");
	if (b != nullptr)
	{
		HPComponent->TakeDamage(b->damage);
	}
}

void Player::SetupAnimation(GameObject* owner, PlayerAnimation * pa)
{
	playerAnimation = pa;
	owner->AddComponent(playerAnimation);
}


std::string Player::GetClassName()
{
	return "Player";
}
