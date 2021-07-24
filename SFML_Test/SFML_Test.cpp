#include "pch.h"
#include "Scene.h"
#include "GameScenes.h"
#include "Input.h"

using namespace sf;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 700;

int main()
{
	sf::Color gray = sf::Color(40, 40, 40);

	Scene* game = nullptr;
	GameScenes gameScenes = GameScenes(&game);

	RenderWindow* window = new RenderWindow(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game");
	Event e;

	window->pollEvent(e);

	float deltaTime = 0.0f;
	sf::Clock clock;
	window->clear(gray);
	int frameCount = 0;

	Input::SetWindows(window);

	while (window->isOpen()) 
	{
		frameCount++;
		deltaTime = clock.restart().asSeconds();
		while (window->pollEvent(e)) {
			if (e.type == sf::Event::EventType::Closed)
				window->close();
			if(e.type == sf::Event::KeyReleased)
			{
				Input::SetState(e.key.code, false);
			}
			if (e.type == sf::Event::MouseButtonReleased) 
			{
				if (e.mouseButton.button == sf::Mouse::Left) 
				{
					Input::SetState(Input::Key::Mouse0, false);
				}
				if (e.mouseButton.button == sf::Mouse::Right)
				{
					Input::SetState(Input::Key::Mouse1, false);
				}
			}
		}

		Input::Update();

		game->CheckInput(e);
		game->Update(deltaTime);
		
		window->clear(gray);

		game->Render(window);
		game->AddDynamicGameObjects();
		game->DestroyAllGameObject();

		gameScenes.ChangeScene();
			
		window->display();
	}

	delete window;
}