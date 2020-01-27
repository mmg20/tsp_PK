#pragma once
#include "Individual.h"

class Crossover
{
public:
	Crossover(double); //dziedziczenie publiczne
	Individual cross(Individual, Individual); //publiczna metoda
protected: //w klasie dziedzicz�cej s� private
	double crossoverFactor;
	bool shouldCross();
	virtual Individual crossoverMethod(Individual, Individual); //metoda zostanie przys�oni�ta w klasie dziedzicz�cej
};

