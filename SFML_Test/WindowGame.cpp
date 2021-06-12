#include "pch.h"
#include "WindowGame.h"

WindowGame::WindowGame(int width, int height, string title, sf::Color _backgroundColor)
{
	window = new sf::RenderWindow(sf::VideoMode(800, 600), "Test");
	backgroundColor = _backgroundColor;
}

void WindowGame::CheckInput()
{
	while (window->isOpen()) {

	}
}

void WindowGame::PreRender()
{
	window->clear(backgroundColor);
}

void WindowGame::PostRender()
{
}

sf::RenderWindow * WindowGame::GetWindow()
{
	return window;
}

sf::Event WindowGame::GetEvent()
{
	return event;
}

WindowGame::~WindowGame()
{
	delete window;
}
