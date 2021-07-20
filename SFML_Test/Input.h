#pragma once

const int DOWN = -1;
const int PRESSED = 1;
const int UP = 2;
const int NONE = 0;

class Input
{
private:
	map<int, int>* inputState;
	static Input instance;
public:
	enum Key
	{
		W = sf::Keyboard::W,
		A = sf::Keyboard::A,
		S = sf::Keyboard::S,
		D = sf::Keyboard::D,
		Mouse0 = 102
	};

	Input();
	static Input& Instance() 
	{
		return instance;
	}
	static bool GetKeyDown(int keyId);
	static bool GetKey(int keyId);
	static void SetState(int keyId, bool pressed);
	static void Update();
	static void UpdateKeyPressed(Input::Key key);
	static void UpdateMousePressed();
};



