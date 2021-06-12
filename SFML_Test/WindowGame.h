#pragma once
#include "IGameUpdate.h"

class WindowGame
{
private:
	sf::RenderWindow* window;
	sf::Event event;
	sf::Color backgroundColor;
public:
	WindowGame(int width, int height, string title, sf::Color backgroundColor);
	~WindowGame();
	void CheckInput();
	void PreRender();
	void PostRender();
	sf::Event GetEvent();
	sf::RenderWindow* GetWindow();
};

