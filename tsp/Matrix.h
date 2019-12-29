#pragma once

#include <vector>
#include <string>

using namespace std;

class Matrix
{
	private:
		vector<vector<int>> distanceMatrix;
		int size;
	public:
		Matrix(string fileName);
		int getDistance(int a, int b);
		int getSize();
		

};

