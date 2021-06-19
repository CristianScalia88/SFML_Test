#pragma once
class Collider
{
private:
	sf::RectangleShape* collider;

public:
	Collider();
	~Collider();
	void OnCollider(Collider other);
};

