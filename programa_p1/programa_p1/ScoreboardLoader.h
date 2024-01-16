#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

class ScoreboardLoader
{
private: 
	vector<int> scores;

public:
	void LoadScore(const int& score, string filePath);

	void OrderScore(string filePath);
		
	void InitScore(string filePath);

	int GetAnScore(const int& index);

	int GetSize() { return this->scores.size(); };
};

