#pragma once

#include <vector>

using namespace std;

class Matrix
{
	private:
		vector<vector<int>> distanceMatrix;
	public:
		Matrix(vector<vector<int>> distances);
		int getDistance(int a, int b);
};

