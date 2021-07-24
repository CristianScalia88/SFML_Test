#include "pch.h"
#include "Bullet.h"

const string PATH_TEXTURE = "Assets/FireBullet.png";

Bullet::Bullet(sf::Vector2f _direction, float _speed, GameObject * owner)
{
	direction = _direction;
	speed = _speed;

	texture = new sf::Texture();
	if (!texture->loadFromFile(PATH_TEXTURE))
	{
		cout << "Texture Load from File Error" << endl;
	}

	TextureComponent* textureComponent = new TextureComponent(texture);
	owner->AddComponent(textureComponent);
	textureComponent->LookAt(direction);
}

Bullet::~Bullet()
{
	delete texture;
}

void Bullet::Update(float deltaTime)
{
	sf::Vector2f newPos = (direction * speed * deltaTime);
	//cout << newPos.x << " " << newPos.y << endl;
	GetOwner()->transform->Translate(newPos);
}

std::string Bullet::GetClassName()
{
	return "Bullet";
}
