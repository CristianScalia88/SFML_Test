#pragma once
class GameObject;

class IGameComponent {
private:
	GameObject * owner;
public:
	virtual void Start();
	virtual void Update(float deltaTime);
	virtual void Render(sf::RenderWindow*);
	virtual std::string GetClassName() = 0;
	virtual GameObject * GetOwner();
	virtual void SetOwner(GameObject* go);
	virtual void Destroy();
	virtual void OnTriggerEnter(GameObject * go);
};

