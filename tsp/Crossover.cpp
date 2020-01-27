#include "Crossover.h"
#include "chance.h"

Crossover::Crossover(double crossoverFactor)
{
	this->crossoverFactor = crossoverFactor;
}

bool Crossover::shouldCross()
{
	return chance(this->crossoverFactor);
}

Individual Crossover::cross(Individual individualA, Individual individualB)
{
	if (this->shouldCross())
		return this->crossoverMethod(individualA, individualB);
	else
		return individualA;
}

Individual Crossover::crossoverMethod(Individual, Individual)
{
	
}