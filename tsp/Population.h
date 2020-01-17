#pragma once
#include "Individual.h"
#include "Matrix.h"
#include <vector>

using namespace std;

class Population
{
	private:
		vector<Individual> individuals;
	public:
		Population(int);
		Population(vector<Individual>);
		Individual getBest();
		vector<Individual> getIndividuals();
		int size();
		Individual getByIndex(int);
};

