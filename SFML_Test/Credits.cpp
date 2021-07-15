#include "pch.h"
#include "Credits.h"

GameObject* Credits::CreateText(std::string labelText, sf::Vector2f pos, int fontSize)
{
	GameObject* textGameObject = new GameObject();
	poke::TextComponent* textComponent = new poke::TextComponent(labelText, fontType, fontSize);
	textComponent->SetPosition(pos);
	textGameObject->AddComponent(textComponent);
	return textGameObject;
}

Credits::Credits()
{
	game = new Game();

	fontType.loadFromFile("Assets/Rubric Regular.ttf");

	GameObject* textName = CreateText("Cristian Scalia", { 200,300 }, 33);
	game->AddGameObject(textName);
}

Credits::~Credits()
{
}
