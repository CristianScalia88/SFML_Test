#include "pch.h"
#include "Random.h"
/// <summary>
/// returns a random value (inclusive , inclusive).
/// </summary>
/// <param name="minValue">inclusive</param>
/// <param name="maxValue">inclusive</param>
/// <returns></returns>
int Random::Range(int minValue, int maxValue)
{
    int dif = maxValue - minValue;
    return rand() % (dif + 1) + minValue;
}

int Random::RandomSign()
{
    if (rand() < (32767 / 2))
    {
        return -1;
    }
    else {
        return 1;
    }
}
