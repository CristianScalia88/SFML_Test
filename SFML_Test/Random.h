#pragma once
#include <cstdlib>

class Random
{
public:
	static int Range(int minValue, int maxValue);
	static int RandomSign();
	static sf::Vector2f RandomDirection();
};

