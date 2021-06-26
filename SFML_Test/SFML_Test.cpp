#include "pch.h"
#include "game.h"
#include "RectangleComponent.h"
#include "File.h"
#include "SpriteSheet.h"
#include "TextureComponent.h"
#include "AnimationComponent.h"
#include "MovementComponent.h"
#include "PlayerInput.h"
#include "ColliderComponent.h"
#include "ColliderManager.h"

using namespace sf;

const string PATH_JSON = "Assets/filteredSpriteSheet.json";
const string PATH_TEXTURE = "Assets/Animation.png";

int main()
{
	ColliderManager colliderManager;

	sf::Texture texture = Texture();
	if (!texture.loadFromFile(PATH_TEXTURE)) 
	{
		cout << "Texture Load from File Error" << endl;
	}

	std::string spriteSheetJson = poke::File::ReadAllText(PATH_JSON); //str holds the content of the file
	poke::SpriteSheet spriteSheet = poke::SpriteSheet(&texture, spriteSheetJson.c_str());

	GameObject go = GameObject();

	TextureComponent textureComponent = TextureComponent(&texture);
	textureComponent.SetRectangle(spriteSheet.GetSpriteRect(0), spriteSheet.GetPivot(0));
	go.AddComponent(&textureComponent);

	int idleFrameIds[] = { 0, 1, 2, 3, 4, 5 };
	int runFrameIds[] = { 6,7,8,9,10,11,12,13 };
	int walkFrameIds[] = { 14,15,16,17,18,19 };
	int attackFrameIds[] = { 20,21,22 };

	AnimationComponent animationComponent = AnimationComponent(&textureComponent, &spriteSheet, walkFrameIds, sizeof(walkFrameIds)/sizeof(int));
	go.AddComponent(&animationComponent);

	PlayerInput playerInput;
	MovementComponent movementComponent = MovementComponent(&playerInput, 500);
	go.AddComponent(&movementComponent);
	
	go.AddComponent(colliderManager.CreateCollider(30,30));

	go.transform->Translate(Vector2f(40, 80));


	GameObject go2 = GameObject();
	go2.AddComponent(colliderManager.CreateCollider(100, 10));
	go2.transform->Translate(Vector2f(100, 400));

	Game game = Game();
	game.AddGameObject(&go);
	game.AddGameObject(&go2);

	RenderWindow* window = new RenderWindow(VideoMode(800, 600), "Test");
	Event e;

	window->pollEvent(e);

	float deltaTime = 0.0f;
	sf::Clock clock;
	sf::Color gray = sf::Color(40, 40, 40);
	window->clear(gray);

	while (window->isOpen()) 
	{
		deltaTime = clock.restart().asSeconds();

		while (window->pollEvent(e))
			if (e.type == sf::Event::EventType::Closed)
				window->close();

		game.CheckInput(e);
		game.Update(deltaTime);
		colliderManager.CheckCollisions(deltaTime);
		window->clear(gray);

		game.Render(window);
		window->display();
	}

	delete window;
}