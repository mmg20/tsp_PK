#include "PsmMutation.h"
#include "rng.h"
#include "chance.h"
#include <iostream>

using namespace std;

PsmMutation::PsmMutation(double mutationFactor)
	: Mutation(mutationFactor) { }

void PsmMutation::mutator(Individual& individual)
{
	for (int i = 0; i < (int)individual.genome.size(); i++)
	{
		if (this->shouldMutate())
		{
			int pick = rng(0, individual.genome.size() - 1);
			swap(individual.genome[i], individual.genome[pick]);
		}
	}
}

