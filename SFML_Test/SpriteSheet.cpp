#include "pch.h"
#include "SpriteSheet.h"
#include "rapidjson/document.h"
#include "rapidjson/prettywriter.h" // for stringify JSON
#include <cstdio>

SpriteSheet::SpriteSheet(sf::Texture* texture, const char* json)
{
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

	}
}


SpriteSheet::~SpriteSheet()
{
}

std::map<std::string, std::string> mapForAttributeThatMatchesName(const rapidjson::Value& attributes, const std::string& findMemberName, const std::string& findMemberValue, const std::vector<std::string>& keysToRetrieve) {

    std::map<std::string, std::string> result;
    for (rapidjson::Value::ConstValueIterator itr = attributes.Begin(); itr != attributes.End(); ++itr) {

        const rapidjson::Value::ConstMemberIterator currentAttribute = itr->FindMember(findMemberName.c_str());
        if (currentAttribute != itr->MemberEnd() && currentAttribute->value.IsString()) {

            if (currentAttribute->value == findMemberValue.c_str()) {

                for (auto &keyToRetrieve : keysToRetrieve) {

                    const rapidjson::Value::ConstMemberIterator currentAttributeToReturn = itr->FindMember(keyToRetrieve.c_str());
                    if (currentAttributeToReturn != itr->MemberEnd() && currentAttributeToReturn->value.IsString()) {

                        result[keyToRetrieve] = currentAttributeToReturn->value.GetString();
                    }
                }
                return result;
            }
        }
    }
    return result;
}