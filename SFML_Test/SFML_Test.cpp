#include "pch.h"
#include "game.h"
#include "RectangleComponent.h"
#include "File.h"
#include "SpriteSheet.h"
#include "TextureComponent.h"
#include "AnimationComponent.h"
#include "MovementComponent.h"
#include "PlayerInput.h"

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

	Game game = Game();

	sf::Texture texture = Texture();
	if (!texture.loadFromFile(PATH_TEXTURE)) 
	{
		cout << "Texture Load from File Error" << endl;
	}
	sf::Sprite s;
	s.setTexture(texture);
	s.setOrigin(10, 30);

	poke::SpriteSheet spriteSheet = poke::SpriteSheet(&texture, str.c_str());

	GameObject go = GameObject();
	TextureComponent textureComponent = TextureComponent(&texture);
	textureComponent.SetRectangle(spriteSheet.GetSpriteRect(0), spriteSheet.GetPivot(0));
	go.AddComponent(&textureComponent);

	int idleFrameIds[] = { 0, 1, 2, 3, 4, 5 };
	int runFrameIds[] = { 6,7,8,9,10,11,12,13 };
	int walkFrameIds[] = { 14,15,16,17,18,19 };
	int attackFrameIds[] = { 20,21,22 };
	AnimationComponent animationComponent = AnimationComponent(&textureComponent, &spriteSheet, walkFrameIds, 6);
	go.AddComponent(&animationComponent);

	PlayerInput playerInput;
	MovementComponent movementComponent = MovementComponent(&playerInput, 150);
	go.AddComponent(&movementComponent);
	
	go.transform->Translate(Vector2f(40, 80));

	game.AddGameObject(&go);

	window->pollEvent(e);
	window->clear(sf::Color(100,100,100));

	float deltaTime = 0.0f;
	sf::Clock clock;
	while (window->isOpen()) 
	{
		deltaTime = clock.restart().asSeconds();

		while (window->pollEvent(e))
			if (e.type == sf::Event::EventType::Closed)
				window->close();


		game.CheckInput(e);
		game.Update(deltaTime);

		window->clear(sf::Color(100, 100, 100));

		game.Render(window);
		window->display();
	}

	delete window;
}