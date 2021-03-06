#pragma once
#include "Individual.h"

class Crossover
{
public:
	Crossover(double); //dziedziczenie publiczne
	Individual cross(Individual, Individual); //publiczna metoda
protected: //w klasie dziedziczącej są private
	double crossoverFactor;
	bool shouldCross();
	virtual Individual crossoverMethod(Individual, Individual); //metoda zostanie przysłonięta w klasie dziedziczącej
};

