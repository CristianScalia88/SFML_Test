#include "pch.h"
#include "Input.h"

Input Input::instance;

Input::Input()
{
	inputState = new map<int, int>();
}

bool Input::GetKeyDown(int keyId)
{
	bool keyExists = Input::Instance().inputState->find(keyId) != Input::Instance().inputState->end();
	return keyExists && (Input::Instance().inputState->find(keyId)->second) == 1;
}

bool Input::GetKey(int keyId)
{
	bool keyExists = Input::Instance().inputState->find(keyId) != Input::Instance().inputState->end();
	return keyExists && ((Input::Instance().inputState->find(keyId)->second) > 1);
}

void Input::SetState(int keyId, bool pressedState)
{
	if (pressedState)
	{
		auto const result = Input::Instance().inputState->insert(std::make_pair(keyId, 1));
		if (not result.second) { result.first->second = result.first->second + 1; }
	}
	else 
	{
		auto const result = Input::Instance().inputState->insert(std::make_pair(keyId, pressedState));
		if (not result.second) { result.first->second = 0; }
	}
}

void Input::Update()
{
	UpdateKeyPressed(Input::Key::W);
	UpdateKeyPressed(Input::Key::A);
	UpdateKeyPressed(Input::Key::S);
	UpdateKeyPressed(Input::Key::D);
	UpdateMousePressed();

}

void Input::UpdateKeyPressed(Input::Key key)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(key)))
	{
		SetState(key, true);
	}
}

void Input::UpdateMousePressed()
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))
	{
		SetState(Input::Mouse0, true);
	}
}
