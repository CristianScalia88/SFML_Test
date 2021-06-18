#include "pch.h"
#include "SpriteSheet.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h" // for stringify JSON
#include <cstdio>

poke::SpriteSheet::SpriteSheet(sf::Texture* _texture, const char* json)
{
	sprites = new vector<poke::Sprite*>();
	texture = texture;

	rapidjson::Document document;
	document.Parse(json);

	const rapidjson::Value& attributes = document["sprites"];

	for (rapidjson::Value::ConstValueIterator itr = attributes.Begin(); itr != attributes.End(); ++itr) 
	{
		//Get Name
		const char * animationName = itr->GetObj()["name"].GetString();

		//Get Rect
		Rect* rect = new Rect();
		rect->x = itr->GetObj()["rect"].GetObj()["x"].GetInt();
		rect->y = itr->GetObj()["rect"].GetObj()["y"].GetInt();
		rect->width = itr->GetObj()["rect"].GetObj()["width"].GetInt();
		rect->height = itr->GetObj()["rect"].GetObj()["height"].GetInt();

		//Get Pivot
		Pivot * pivot = new Pivot();
		pivot->x = itr->GetObj()["pivot"].GetObj()["x"].GetFloat();
		pivot->y = itr->GetObj()["pivot"].GetObj()["y"].GetFloat();

		Sprite * sprite = new Sprite();
		sprite->name = animationName;
		sprite->rect = rect;
		sprite->pivot = pivot;

		sprites->push_back(sprite);
	}
}

poke::SpriteSheet::~SpriteSheet()
{
	delete texture;
	//TODO Check memory leaks in sprites
	delete sprites;
}

poke::Rect * poke::SpriteSheet::GetSpriteRect(int frameId)
{
	return sprites->at(frameId)->rect;
}

poke::Pivot * poke::SpriteSheet::GetPivot(int frameId)
{
	return sprites->at(frameId)->pivot;
}