#pragma once
class VectorUtils
{
public:
	static float Magnitude(const sf::Vector2f& vector);
	static sf::Vector2f Normalize(const sf::Vector2f& source);
	//static float GetAngle(float ax, float ay, float bx, float by);
};

