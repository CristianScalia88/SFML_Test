#include "pch.h"
#include "ScoreScreen.h"
#include "ScoreManager.h"

const sf::Color gray = sf::Color(40, 40, 40, 0);
const sf::Color grayOver = sf::Color(30, 30, 30, 200);

GameObject* ScoreScreen::CreateText(std::string labelText, sf::Vector2f pos, int fontSize)
{
	GameObject* textGameObject = new GameObject();
	poke::TextComponent* textComponent = new poke::TextComponent(labelText, fontType, fontSize,false);
	textComponent->SetPosition(pos);
	textGameObject->AddComponent(textComponent);
	return textGameObject;
}

GameObject* ScoreScreen::CreateButton(std::string text, CallbackBase* callback, sf::Vector2f pos)
{
	GameObject* goButton = new GameObject();
	poke::Button* buttonComponent = new poke::Button(text, fontType, 20, { 200,30 }, gray, grayOver, sf::Color::White);
	buttonComponent->SetPosition(pos);
	buttonComponent->callback = callback;
	goButton->AddComponent(buttonComponent);
	return goButton;
}

ScoreScreen::ScoreScreen(sf::View* view)
{
	fontType.loadFromFile("Assets/Rubric Regular.ttf");

	CallbackBase* goToMainMenu = make_callback(GameScenes::instance, &GameScenes::ChangeToMainMenu);

	std::vector<Score*>::iterator bgn = ScoreManager::instance->scores->begin();
	std::vector<Score*>::iterator end = ScoreManager::instance->scores->end();
	int pos= 0;
	
	for (auto i = bgn; i != end; i++)
	{
		float y = 100 + (pos * 30);
		AddGameObject(CreateText((*i)->name, { 200, y }, 20));
		AddGameObject(CreateText(std::to_string((*i)->points), {500, y}, 20));
		pos++;
	}

	GameObject* exit = CreateButton("Exit", goToMainMenu, { 300, 500 });
	AddGameObject(exit);
}

ScoreScreen::~ScoreScreen()
{
}
