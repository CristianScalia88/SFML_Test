#pragma once
#include "Rect.h"
#include "Pivot.h"
namespace poke {
	struct Sprite
	{
	public:
		string name;
		Rect* rect;
		Pivot* pivot;
	};
}