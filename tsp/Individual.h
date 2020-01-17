#pragma once

#include "Matrix.h"
#include <vector>
#include <string>

using namespace std;

class Individual
{
	private:
		
	public:
		Individual(vector<int> genome);
		friend Individual operator+(const Individual& a, const Individual& b);
		Individual(int nodeCount); //liczba wêz³ów
		vector<int> genome;
		int getFitness();
		void print();
		//int &operator[](int)
};

