#include "pch.h"
#include "Credits.h"

const sf::Color gray = sf::Color(40, 40, 40, 0);
const sf::Color grayOver = sf::Color(30, 30, 30, 200);

GameObject* Credits::CreateText(std::string labelText, sf::Vector2f pos, int fontSize)
{
	GameObject* textGameObject = new GameObject();
	poke::TextComponent* textComponent = new poke::TextComponent(labelText, fontType, fontSize);
	textComponent->SetPosition(pos);
	textGameObject->AddComponent(textComponent);
	return textGameObject;
}

GameObject* Credits::CreateButton(std::string text, CallbackBase* callback, sf::Vector2f pos)
{
	GameObject* goButton = new GameObject();
	poke::Button* buttonComponent = new poke::Button(text, fontType, 20, { 100,30 }, gray, grayOver, sf::Color::White);
	buttonComponent->SetPosition(pos);
	buttonComponent->callback = callback;
	goButton->AddComponent(buttonComponent);
	return goButton;
}

void Credits::GoToMainMenu()
{
	goToMainMenu->Invoke();
}

Credits::Credits()
{
	fontType.loadFromFile("Assets/Rubric Regular.ttf");

	GameObject* textName = CreateText("Cristian Scalia", { 200,300 }, 33);
	AddGameObject(textName);

	GameObject* buttonExit = CreateButton("Exit", make_callback(this, &Credits::GoToMainMenu), { 0,0 });
	AddGameObject(buttonExit);
}

Credits::~Credits()
{
}
