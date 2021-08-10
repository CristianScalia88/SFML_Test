#pragma once
#include "Callbacks.h"
class ScaleData
{
public:
	ScaleData(float _From, float _to, float _time) 
	{
		from = _From;
		to = _to;
		time = _time;
	}
	CallbackBase* cb;
	float from;
	float to;
	float time;

	std::string ToString() {
		return "from" + std::to_string(from) + " to " + std::to_string(to) + " time " + std::to_string(time);
	}
};
