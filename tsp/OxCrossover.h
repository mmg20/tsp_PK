#pragma once
#include "Individual.h"
#include "Crossover.h"
#include <vector>

using namespace std;

class OxCrossover : public Crossover
{
public:
	OxCrossover(double);
private:
	Individual crossoverMethod(Individual, Individual);
	bool hasAny(vector<int>, int);
};