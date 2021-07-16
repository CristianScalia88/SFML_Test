#include "pch.h"
#include "game.h"
#include "GameScenes.h"

using namespace sf;


int main()
{
	sf::Color gray = sf::Color(40, 40, 40);

	Game* game;
	GameScenes gameScenes = GameScenes(&game);

	RenderWindow* window = new RenderWindow(VideoMode(800, 600), "Game");
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