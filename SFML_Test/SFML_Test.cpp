#include "pch.h"
#include "Scene.h"
#include "GameScenes.h"
#include "Input.h"
#include "SoundManager.h"
#include "../../Cpp/Clase2/HighScore/ScoreManager.h"

using namespace sf;

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

int main()
{
	sf::Color gray = sf::Color(40, 40, 40);

	sf::View view;


	SoundManager soundManager;

	Scene* game = nullptr;
	GameScenes gameScenes = GameScenes(&game, &view);

	RenderWindow* window = new RenderWindow(VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Game");
	Event e;

	window->pollEvent(e);

	float deltaTime = 0.0f;
	sf::Clock clock;
	window->clear(gray);
	int frameCount = 0;

	Input::SetWindows(window);
	view.setSize(SCREEN_WIDTH, SCREEN_HEIGHT);


	ScoreManager scoreManager = ScoreManager(10);
	


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
		window->setView(view);

		Input::Update();

		game->CheckInput(e);
		game->Update(deltaTime);
		
		window->clear(gray);

		game->Render(window);

		gameScenes.ChangeScene();

		window->setView(window->getDefaultView());

		game->RenderUI(window);

		window->display();

		game->AddDynamicGameObjects();
		game->DestroyAllGameObject();

		game->OnLoopEnd();
	}

	if (game != nullptr) 
	{
		delete game;
	}

	delete window;
}