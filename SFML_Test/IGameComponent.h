#pragma once
class GameObject;

class IGameComponent {
private:
	GameObject * owner;
public:
	virtual void Start();
	virtual void Update(float deltaTime);
	virtual void Render(sf::RenderWindow*);
	virtual std::string GetClassName();
	virtual GameObject * GetOwner();
	virtual void SetOwner(GameObject * go);
};

