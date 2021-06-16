#pragma once
#include "Rect.h"
#include "Pivot.h"

struct Sprite
{
public:
	string name;
	Rect* rect;
	Pivot* pivot;
};