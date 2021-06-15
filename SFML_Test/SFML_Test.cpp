#include "pch.h"
#include "game.h"
#include "RectangleComponent.h"
#include "File.h"
#include "SpriteSheet.h"

using namespace sf;
const string PATH = "C:/Users/Cristian/source/repos/SFML_Test/filteredSpriteSheet.json";

int main()
{
	std::ifstream inFile;
	inFile.open(PATH); //open the input file
	std::stringstream strStream;
	strStream << inFile.rdbuf(); //read the file
	std::string str = strStream.str(); //str holds the content of the file
	inFile.close();

	SpriteSheet ss(nullptr, str.c_str());

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