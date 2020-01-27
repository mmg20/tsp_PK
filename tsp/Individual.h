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
		Individual(int nodeCount); //liczba w�z��w
		vector<int> genome;
		int getFitness();
		void print();
};

