#pragma once
class CharacterInput
{
public:
	CharacterInput();
	~CharacterInput();
	virtual sf::Vector2f GetDirection() = 0;
	virtual bool Attack() = 0;
};

