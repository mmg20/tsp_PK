#pragma once

#include <vector>

using namespace std;

class Individual
{
	private:
		vector<int> genome;
	public:
		Individual();
		Individual(vector<int> genome);
		friend Individual operator+(const Individual& a, const Individual& b);
		vector<int> getGenome();
};

