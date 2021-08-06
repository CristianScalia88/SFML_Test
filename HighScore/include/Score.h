#pragma once
#include <string>

using namespace std;

struct Score {

public:
	int points;
	string name;

	Score(string _name, int _points) {
		points = _points;
		name = _name;
	}
};