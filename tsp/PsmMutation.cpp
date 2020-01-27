#include "PsmMutation.h"
#include "rng.h"
#include "chance.h"
#include <iostream>

using namespace std;

PsmMutation::PsmMutation(double mutationFactor)
	: Mutation(mutationFactor) { }

void PsmMutation::mutator(Individual& individual)
{
	for (int i = 0; i < (int)individual.genome.size(); i++) //petla przez caly genotyp
	{
		if (this->shouldMutate()) //sprawdzamy czy mutowac, dla kazdego elementu genotypu
		{
			int pick = rng(0, individual.genome.size() - 1); // wybieramy losowy gen z przedzialu genotypu
			swap(individual.genome[i], individual.genome[pick]); // zamieniamy miejscami aktualny gen na nowo wylosowany
		}
	}
}

