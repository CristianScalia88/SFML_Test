#pragma once

#include "score.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class ScoreManager
{
private:
	int maxSamples;
	void RemoveExcess();

public:
	static ScoreManager* instance;
	vector<Score*>* scores;
	ScoreManager(int maxSamples);
	~ScoreManager();
	void AddScore(Score* score);
	void Print();
};

