#include "pch.h"
#include "VectorUtils.h"

float VectorUtils::Magnitude(const sf::Vector2f& vector)
{
	return sqrt((vector.x * vector.x) + (vector.y * vector.y));
}

sf::Vector2f VectorUtils::Normalize(const sf::Vector2f& source)
{
	float length = sqrt((source.x * source.x) + (source.y * source.y));
	if (length != 0)
		return sf::Vector2f(source.x / length, source.y / length);
	else
		return source;
}

/*float VectorUtils::GetAngle(float ax, float ay, float bx, float by)
{
	return 0.0f;
}

float VectorUtils::GetAngle(float ax, float ay, float bx, float by)
{
	return atan2((by - ay), (bx - ax));
}
*/
