#include "pch.h"
#include "game.h"
#include "RectangleComponent.h"

using namespace sf;

int main()
{
	RenderWindow* window = new RenderWindow(VideoMode(800, 600), "Test");
	Event e;

	Game* game = new Game();

	GameObject* go = new GameObject();
	RectangleComponent* rectangleComponent = new RectangleComponent();
	go->AddComponent(rectangleComponent);

	game->AddGameObject(go);

	window->pollEvent(e);
	window->clear(sf::Color::Black);

	while (window->isOpen()) 
	{
		while (window->pollEvent(e))
			if (e.type == sf::Event::EventType::Closed)
				window->close();


		game->CheckInput(e);
		game->Update();

		window->clear(sf::Color::Black);
		game->Render(window);
		window->display();
	}

	delete window;
	delete game;
	delete go;
	delete rectangleComponent;
}