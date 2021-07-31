#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "ColliderManager.h"
#include "SpriteSheet.h"
#include "File.h"
#include "RectangleComponent.h"
#include "TextureComponent.h"
#include "AnimationComponent.h"
#include "MovementComponent.h"
#include "PlayerInput.h"
#include "ColliderComponent.h"
#include "Player.h"
#include "EnemyManager.h"

class Gameplay : public Scene
{
private:
	GameObject* playerGo;
	ColliderManager* colliderManager;
public:
	static Gameplay* instance;
	Gameplay(sf::View* view);
	~Gameplay();
	void GoToMainMenu();
};

