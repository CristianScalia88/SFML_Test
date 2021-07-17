#include "pch.h"
#include "Scene.h"
#include "GameScenes.h"

using namespace sf;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 700;

int main()
{
	sf::Color gray = sf::Color(40, 40, 40);

	Scene* game;
	GameScenes gameScenes = GameScenes(&game);

	RenderWindow* window = new RenderWindow(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game");
	Event e;

	window->pollEvent(e);

	float deltaTime = 0.0f;
	sf::Clock clock;
	window->clear(gray);

	while (window->isOpen()) 
	{
		deltaTime = clock.restart().asSeconds();

		while (window->pollEvent(e))
			if (e.type == sf::Event::EventType::Closed)
				window->close();

		game->CheckInput(e);
		game->Update(deltaTime);
		
		window->clear(gray);

		game->Render(window);
		window->display();
	}

	delete window;
}