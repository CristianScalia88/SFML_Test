#pragma once
#include "Sprite.h"
#include "Rect.h"

namespace poke {

	class SpriteSheet
	{
	private:
		sf::Texture* texture;
		std::vector<Sprite*>* sprites;
	public:
		SpriteSheet(sf::Texture* texture,const char* json);
		~SpriteSheet();
		Rect* GetSpriteRect(int frameId);
	};


}