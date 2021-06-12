#pragma once
class GameObject;

class IGameComponent {
public:
	GameObject * owner;
	virtual void Start();
	virtual void Update();
	virtual void Render(sf::RenderWindow*);
};

