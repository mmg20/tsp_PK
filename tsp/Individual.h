#pragma once

#include <vector>

using namespace std;

class Individual
{
	private:
		
	public:
		Individual(vector<int> genome);
		friend Individual operator+(const Individual& a, const Individual& b);
		vector<int> getGenome();
		Individual(int nodeCount); //liczba wêz³ów
		vector<int> genome;
		//int &operator[](int)
};

