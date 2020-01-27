#include "Mutation.h"
#include "chance.h"
#include <iostream>

Mutation::Mutation(double mutationFactor)
{
	this->mutationFactor = mutationFactor;
}

bool Mutation::shouldMutate()
{
	return chance(this->mutationFactor);
}

void Mutation::mutate(Individual& individual)
{
	if (this->shouldMutate())
		this->mutator(individual);
}

void Mutation::mutator(Individual& individual)
{
	Matrix matrix = MatrixProvider::get();
	individual = Individual(matrix.getSize());
}