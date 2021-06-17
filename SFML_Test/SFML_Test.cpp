#include "pch.h"
#include "game.h"
#include "RectangleComponent.h"
#include "File.h"
#include "SpriteSheet.h"
#include "TextureComponent.h"

using namespace sf;
const string PATH_JSON = "Assets/filteredSpriteSheet.json";
const string PATH_TEXTURE = "Assets/Animation.png";

int main()
{
	std::ifstream inFile;
	inFile.open(PATH_JSON); //open the input file
	std::stringstream strStream;
	strStream << inFile.rdbuf(); //read the file
	std::string str = strStream.str(); //str holds the content of the file
	inFile.close();
	
	RenderWindow* window = new RenderWindow(VideoMode(800, 600), "Test");
	Event e;

	Game* game = new Game();

	sf::Texture* texture = new Texture();
	if (!texture->loadFromFile(PATH_TEXTURE)) 
	{
		cout << "Texture Load from File Error" << endl;
	}

	poke::SpriteSheet* spriteSheet = new poke::SpriteSheet(texture, str.c_str());

	GameObject* go = new GameObject();
	TextureComponent* textureComponent = new TextureComponent(texture);
	go->AddComponent(textureComponent);

	
	textureComponent->SetRectangle(spriteSheet->GetSpriteRect(0));

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
	delete textureComponent;
	delete texture;
}