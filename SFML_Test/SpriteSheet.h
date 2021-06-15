#pragma once
#include "Sprite.h"

class SpriteSheet
{
private:
	sf::Texture texture;
	std::vector<Sprite> sprites;
public:
	SpriteSheet(sf::Texture* texture,const char* json);
	~SpriteSheet();
};

