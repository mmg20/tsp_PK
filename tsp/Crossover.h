#pragma once
#include "Individual.h"

class Crossover
{
public:
	Crossover(double);
	Individual cross(Individual, Individual);
protected:
	double crossoverFactor;
	bool shouldCross();
	virtual Individual crossoverMethod(Individual, Individual);
};

